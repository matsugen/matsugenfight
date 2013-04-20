
if rawget(_G, "global") == nil then
  global = function() end
end

--
-- subclass : サブクラスを作るための関数
--
--[[

呼び出し方法：

subclass( 新クラス名, ベースクラス, リロード時の処理関数) {
  -- ここにクラススタティックな変数を定義する
}

例）
subclass("AppleTree", Tree, on_class_reload__added_classvars) {
	type = "apple",
}

function AppleTree:ctor(...)
	AppleTree.super.ctor(...)
end

]]
function class(classname, on_class_reload)
	on_class_reload = on_class_reload
					or on_class_reload__added_classvars
    return function(class_vars)
        create_class(classname, nil, class_vars, on_class_reload)
    end
end


--
-- class : クラスを作るための関数
--
--[[

呼び出し方法：

class( 新クラス名, リロード時の処理関数) {
  -- ここにクラススタティックな変数を定義する
}

リロード時の処理関数が省略された場合は、
on_class_reload__added_classvars
が使用される。
（この関数の動作は、「クラス変数の定義が追加された場合、リロード時にその変数のみ既存のクラスに追加される」という内容）

例）
class("Tree", Tree, on_class_reload__added_classvars) {
}

function Tree:ctor(...)
end

]]
function subclass(classname, super_class, on_class_reload)
	on_class_reload = on_class_reload
					or on_class_reload__added_classvars
    return function(class_vars)
        create_class(classname, super_class, class_vars, on_class_reload)
    end
end


-- クラス実体を取得
-- getmetatable(t).__indexのテーブル（クラス実体）を取得
-- クラスでなければnilを返す
function get_class(t)
	local mt = getmetatable(t)
	if type(mt) == "table" then
		local class = rawget(mt, "__index")
		return class
	end
	return nil
end


-- クラス名を取得
-- getmetatable(t).__indexのテーブル（クラス実体）のclassnameを取得
-- クラスでなければnilを返す
function get_classname(t)
	local class = get_class(t)
	if class ~= nil then
		return rawget(class, "classname")
	end
	return nil
end

-- クラスかどうかを判定
-- クラス名で判定
function is_class_instance(t)
	return get_classname(t) ~= nil
end



-- リロードのために全インスタンスを保持しておくテーブル
-- キーが弱参照なテーブルとして設定
local all_instances = {}
local all_instances_mt = {__mode = "kv"} 
setmetatable(all_instances, all_instances_mt)

function get_all_instances()
	return all_instances
end

-- 実行環境の中にどのクラスのインスタンスが何個あるかを出力する
-- リークチェックなどに便利。
function analyze_instances()
    print("<< analyze_instances >>")
    local classes = {}
    for inst,v in pairs(all_instances) do
        local classname = inst.classname
        if classes[classname] == nil then
            classes[classname] = {}
        end
        local stat = classes[classname]
        stat.num = (stat.num or 0) + 1
    end
    
    for classname,stat in pairs(classes) do
        print("classname:",classname, " count:", stat.num)
    end
end


-- クラスからインスタンスを生成
function create_instance(class, target)
	local t = target or {}
	if rawget(class, "__index") == class then
		setmetatable(t, class)
	else
		local mt = {__index = class}
		setmetatable(t, mt)
	end
	
	-- 全てのインスタンスを記憶しておく
	-- （弱参照のため、ガーベージコレクションを妨げない）
	all_instances[t] = true
	
	return t;
end


-- 派生クラスを作成
-- 前回作ったクラスがある場合はその中身だけ置き換える。
function create_class(classname, super_class, class_vars, on_class_reload)

	assert( type(class_vars) == "table" )

	-- グローバルに既にクラスが存在すればそれを使う
	local class = rawget(_G, classname)
	local is_reload = false
	if class == nil then
		-- クラスの新規作成の場合
		global(classname)
		class = class_vars
		_G[classname] = class
	else
		-- クラスのリロードの場合
		is_reload = true
		if on_class_reload ~= nil then
			on_class_reload(class, super_class, class_vars)
		end
	end

	-- 派生クラスの場合の処理
	if super_class ~= nil then
		class.super = super_class
		
		-- サブクラスに存在しないインデックスは親クラスを参照するよう
		-- メタテーブルを設定
		if rawget(super_class, "__index") == super_class then
			setmetatable(class, super_class)
		else
			local mt = {__index = super_class}
			setmetatable(class, mt)
		end
	end

	-- インスタンスを作成するnew関数追加
	-- newの引数でコンストラクタ関数ctor(...)を呼ぶ
	class.new = function (self, ...)
		local t = create_instance(self, {})
		t:ctor(...)
		return t
	end
	
	-- クラス名設定
	class.classname = classname

	-- インスタンスのメタテーブル用としての設定
	class.__index = class
end



-- クラスリロード時実行関数のデフォルト実装（新規追加のみを追加）
--
-- クラスのクラス変数（スタティックメンバ変数）が追加されていれば
-- 追加分だけを追加する。
-- 既に存在するクラス変数はいじらない。
function on_class_reload__added_classvars(class, super_class, class_vars)
	for k,v in pairs(class_vars) do
		if rawget(class,k) == nil then
			class[k] = v
		end
	end
end

-- クラスリロード時実行関数のデフォルト実装（すべて上書き）
--
-- リロード時にはクラス変数をすべて新しい値で上書きする
function on_class_reload__overwrite(class, super_class, class_vars)
	for k,v in pairs(class_vars) do
		class[k] = v
	end
end


-- クラスリロード時実行関数のデフォルト実装（何もしない！）
--
function on_class_reload__none(class, super_class, class_vars)
end


-- リロード時に呼ばれる関数。
-- すべてのクラスのすべてのインスタンスのon_reload()を（あれば）実行する
function exec_class_reload_funcs()
	for instance,v in pairs(all_instances) do
		if instance.on_reload ~= nil then
			instance:on_reload()
		end
	end
end

