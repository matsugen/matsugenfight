
--
--  Actor
--

class ("Actor") {
	__tostring = function(self)
		return("class Actor name="..self.name) 
	end,
	--__gc = function(self) -- ユーザーデータじゃないので呼ばれない！！！
	--end,
	all_actors = {},
	id_counter = 1,
}

-- Actorのクラス変数all_actorsを弱参照にする
setmetatable(Actor.all_actors, { __mode = "kv" })

-- （クラス関数）新しいIDを得る
function Actor.get_new_id()
	local next_id = Actor.id_counter
	-- クラス変数id_counterをインクリメント
	Actor.id_counter = Actor.id_counter + 1
	return next_id
end

-- （クラス関数）すべての存在するActorの中からIDで探す
function Actor.get_actor_by_id(id)
	return Actor.all_actors[id]
end

-- コンストラクタ
function Actor:ctor(...)
	self.name = "noname:"..get_classname(self)
	self.spr = nil -- スプライト
	self.current_routine = nil -- ルーチン
	self.params = {} -- アクターの内部パラメータ（ユーザー読み書き用）
	self.cfg = {} -- アクターの初期設定（ユーザーから指定）
    self.timecount = 0 -- アクター開始からのフレーム数
	self.drawsystem = nil -- 登録先の描画システム
	self.is_dead_actor = false -- アクターが死んでいるかどうか
	self.id = self:get_new_id() -- アクターID
	self.state_func_name = nil -- 現在実行中の状態関数
	Actor.all_actors[self.id] = self -- アクターのインスタンスリストに登録

	-- デストラクタ設定
	self.ud = newproxy(true)
	getmetatable(self.ud).__gc = function(s)
		--print("__gc called! self.drawsystem = "..tostring(self.drawsystem))
		self:on_gc()
	end
end

-- アクターを初期化
-- 引数はcfgメンバ変数に設定される（テーブルを指定する）
function Actor:init(cfg)

	self.cfg = cfg or {}
	
	self.routinepool = GS.routinepool
	
	-- state_start関数があればコルーチンを準備
	if self.state_start ~= nil then
		self.current_routine = self.routinepool:get_from_pool() -- Routine:new()
		if self:change_routine("state_start") then
			GS.scheduler:add_actor(self)
		else
			error("change_routine failed.")
		end
	end
	-- 状態関数があろうがなかろうがスケジューラーに登録
	-- →そうしないとActor削除がうまくいかない
	--GS.scheduler:add_actor(self)
end

-- リロード時：特に処理なし
function Actor:on_reload()
end

-- アクターの画像を設定
function Actor:init_image(name, imagename, x, y, z)
	local spr = SpriteNode()
	spr:SetImageName(imagename, GS.imageloader)	
	spr:MoveTo(x or 0,y or 0)
	spr:SetZ(z or 0)
	spr:FetchImage()
	self.name = name
	self.spr = spr
end

-- アクターを文字列表示として設定
-- font : TTFフォントオブジェクト（省略可能）
function Actor:init_text(name, text, fontname, x, y, z)
	local spr = SpriteNode()
	spr:SetText(text)	
	spr:SetFont(fontname);
	spr:MoveTo(x or 0,y or 0)
	spr:SetZ(z or 0)
	self.name = name
	self.spr = spr
end

-- アクターを表示なしとして設定
function Actor:init_null_sprite(x, y, z)
	local spr = SpriteNode()
	spr:MoveTo(x or 0,y or 0)
	spr:SetZ(z or 0)
	self.spr = spr
end

-- 子スプライトを追加
function Actor:add_child(actor)
	if actor.parent ~= nil then
		actor:remove_from_parent()
	end
	if self.spr ~= nil then
		self.spr:AddChild(actor.spr)
	end
	self.child_actors = self.child_actors or {}
	table.insert(self.child_actors, actor)
	actor.parent = self
end

-- 子スプライトを削除
function Actor:remove_child(actor)
	if self.spr ~= nil then
		self.spr:RemoveChild(actor.spr)
	end
	if self.child_actors ~= nil then
	    remove_value_from_array(self.child_actors, actor)
	end
end

-- 親スプライトから切り離す
function Actor:remove_from_parent()
	if self.spr ~= nil then
		self.spr:RemoveFromParent()
	end
	if self.parent ~= nil then
		self.parent:remove_child(self)
		self.parent = nil
	end
end

-- 描画システムに登録
function Actor:add_sprite_to_drawsystem(ds)
    self.drawsystem = ds
    ds:AddNode(self.spr)
end

-- 最終処理
function Actor:on_gc()
    if self.drawsystem ~= nil and self.spr ~= nil then
        self.drawsystem:RemoveNode(self.spr)
    end
    self.spr = nil
    self.drawsystem = nil
	if GS.scheduler ~= nil then
		if self.child_actors ~= nil then
			for i,child in ipairs(self.child_actors) do
				GS.scheduler:delete_actor(child)
			end
		end
	end
	self.child_actors = nil
end

-- アクターの機能を削除
-- GCされる状態に戻す
function Actor:delete_internal(scheduler)
	if self.on_destroy ~= nil then
		self:on_destroy()
	end
    if self.current_routine ~= nil then
        self.routinepool:return_to_pool(self.current_routine)
        self.current_routine = nil
    end
    self:remove_from_parent()
    if self.drawsystem ~= nil and self.spr ~= nil then
        self.drawsystem:RemoveNode(self.spr)
    end
    self.spr = nil
    self.drawsystem = nil
	-- [[
	if self.child_actors ~= nil then
		for i,child in ipairs(self.child_actors) do
			scheduler:delete_actor(child)
		end
	end
	-- ]]
	self.child_actors = nil
end

-- スプライトオブジェクトを返す
function Actor:get_sprite()
	return self.spr
end

-- 現在の状態名（＝状態関数名）を取得
function Actor:get_state_name()
	return self.state_func_name
end

function Actor:change_routine(name)
    --print("change_routine() : ", self.classname, "(",self,") to ", name)
	if self.current_routine == nil then
		print("Actor:change_routine : routine not found :", name)
		return false
	end

	-- クラスの持つメンバ関数から探す
	local f = self[name]
    if f == nil or type(f) ~= "function" then
		print("Actor:change_routine : coroutine func not found :", name)
		return false
    end
	-- ルーチン変更してリスタートする
	self.current_routine:change_func(f)
	self.current_routine:restart()
	self.state_func_name = name
	return true
end

local coyield = coroutine.yield

-- コルーチン内から呼ぶ関数
function Actor:wait(count)
	coyield("wait", count)
    self.timecount = self.timecount + count + 1
end

--[[ コルーチン内から呼ぶ関数
function Actor:goto(label)
	coroutine.yield("goto", label)
end
]]

--[[ コルーチン内から呼ぶ関数
function Actor:exit()
	coroutine.yield("exit", nil)
end
]]