function create_class(classname,super_class,class_vars,on_class_reload)
	assert(type(class_vars)~="nil","nil");
	-- グローバルにすでにクラスが使われていればそれを使う
	local class=rawget(_G,classname);
	local is_reload=false;
	if class==nil then
		--クラスの新規作成の場合
		class=class_vars;
		_G[classname]=class;
	else
		--クラスのリロードの場合
		is_reload=ture;
		if on_class_reload~=nil then
			on_class_reload(class,super_class,class_vars);
		end
	end
	--継承処理
	if super_class~=nil then
		class.super=super_class;
		if rawget(super_class,"__index")==super_class then
			setmetatable(class,super_class);
		else
			local mt={__index=super_class};
			setmetatabel(class,mt);
		end
	end

	--インスタンスを作成するnew関数を追加
	--new の引数でコンストラクタ関数ctor(...)を呼ぶ
	class.new=function(self,...)
		local t=create_instance(self,{});
		t:ctor(...);
		return t;
	end
	--クラス名を設定
	class.classname=classname;
	--インスタンスのメタテーブル用としての設定
	class.__index=class;

end
--calss:クラスを作るための関数
function class(classname,on_class_reload)
	return function(class_vars)
		create_class(classname,nil,class_vars,on_class_reload);
	end
end

--subclass:派生クラスを作るための関数
function subclass(classname,super_class,on_class_reload)
	return function(class_vars)
		create_class(classname,super_class,class_vars,on_class_reload);
	end
end

local all_instance={};
local all_instance_mt={__mode="kv"};
setmetatable(all_instance,all_instance_mt);
function get_all_instance()
	return all_instance;
end

--クラスのインスタンスを生成
function create_instance(class,target)
	local t=target or {};
	if rawget(class,"__index")==class then
		setmetatable(t,class);
	else
		local mt={__index=class};
		setmetatable(t,mt);
	end
	all_instance[t]=true;

	return t;
end

--



--クラス変数追加のon_reload
function vars_added(class,super_class,class_vars)
	for k,v in pairs(class_vars) do
		if rawget(class,k)==nil then
			class[k]=v;
		end
	end
end

--クラス変数の上書きのon_reload
function vars_overwrite(class,super_class,class_vars)
	for k,v in pairs(class_vars) do
		class[k]=v;
	end
end


--なにもしないon_reload
function vars_none(class,super_class,class_vars)
end
