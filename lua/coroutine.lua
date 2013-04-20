

--
--  Scheduler
--

class ("Scheduler") {
	__tostring = function()	
		return("class Scheduler")
	end,
}

-- コンストラクタ
function Scheduler:ctor(...)
	self.actors = {}			-- スケジュール対象アクターリスト
	self.added_actors = {}		-- スケジュール中に追加されたアクター
	self.deleted_actors = {}	-- スケジュール中に削除されたアクター
	self.delete_tmp = {}		-- 削除用テンポラリテーブル
end

-- アクター１つをスケジュール処理
function Scheduler:schedule_actor(act)
	local rt = act.current_routine
	if rt ~= nil and rt.co ~= nil then
		if rt.wait_count == 0 then
			-- アクターの状態関数を再開
			local ret = rt:resume(act)
			-- "exit"が返されればアクター削除
            if ret == "exit" then
                self:delete_actor(act)
            elseif ret == false then
                -- エラーの場合
				error("Scheduler:schedule_actor Routine:resume() call error")
            end
		elseif rt.wait_count > 0 then
			-- ウエイト処理
			rt.wait_count = rt.wait_count-1
		end
	end
end

-- 全てのアクターをスケジュール処理
function Scheduler:schedule()

	-- 追加・削除されたアクターをメインに反映
	self:add_actor_sub(self.added_actors)
	self:delete_actor_sub()
	clear_table(self.added_actors)
	--collectgarbage("step")
	--print("Scheduler:schedule() 1")
	
	-- アクターをスケジュール実行
	local count = 0
	for i,act in ipairs(self.actors) do
		if act ~= false and self.deleted_actors[act] == nil then
            --print(string.format("[%2d] : %s : ",i, act.classname), act)
			self:schedule_actor(act)
			count = count + 1
		end
	end
	--print("scheduled actors count:", count)

	-- 処理中に追加されたアクターをさらにスケジュール実行、を繰り返す
	-- （追加処理中に別のアクターが追加されることがある）
	while true do
		local added_tmp = self.added_actors
		self.added_actors = {}
		for act,v in pairs(added_tmp) do
			-- 削除リストに登録されていれば追加中止
			if act.is_dead_actor then
			--if self.deleted_actors[act] ~= nil then
                added_tmp[act] = false
			end
		end
		self:add_actor_sub(added_tmp)
		self:delete_actor_sub()
		
		-- アクターが新たに追加されていなければ終了
		if next(self.added_actors) == nil then
			break
		end
	end
	self:process_deleted_actors()
end

-- 削除されたアクターを（なくなるまで）処理
function Scheduler:process_deleted_actors()
	-- 削除テーブルが空になるまで削除処理を繰り返す
	-- （削除処理中に別のアクターが削除されることがある）
	while true do
		if next(self.deleted_actors) == nil then
			break
		end
		self:delete_actor_sub()
	end
end


-- アクターを追加する
-- 実際には、追加用の予約テーブルに登録しておき、
-- 適切なタイミングでメインのテーブルに追加する
function Scheduler:add_actor(act)
	self.added_actors[act] = true
	--self:add_actor_sub_old(act)
end

-- アクターを削除する
-- 実際には、削除用の予約テーブルに登録しておき、
-- 適切なタイミングでメインのテーブルから削除する
function Scheduler:delete_actor(act)
	act.is_dead_actor = true

	--[[ destroy関数を呼ぶ
	for i,v in ipairs(self.actors) do
		if v == act then
			self.actors[i] = false
		end
	end

	local funcs = act.coroutine_funcs
	if act.on_destroy ~= nil then
		-- この中で他のactorがdeleteされる可能性がある
		act:on_destroy(act.current_routine)
	end
	act:delete_internal()
	
	-- ]]

	self.deleted_actors[act] = true
end

--[[
function Scheduler:add_actor_sub_old(act)
	-- 配列に穴(false)があれば、そこに追加
	for i,v in ipairs(self.actors) do
		if v == false then
			self.actors[i] = act
			return
		end
	end
	-- 末尾に追加
	table.insert(self.actors,act)
end
]]

-- 指定アクター（複数）を削除するサブルーチン
-- 削除するとき、actor.funcs.destroy関数を呼ぶ
-- 削除されたアクターについては、引数で渡したテーブルからキーが消去される。
function Scheduler:delete_actor_sub()

--[[
	-- 削除されたアクターについては穴(false)に変更する
    local count = 0
	for act,_ in pairs(deleted_actors) do
        local is_deleted = false
		for i,v in ipairs(self.actors) do
			if v == act then
				-- テーブル要素を消す
				self.actors[i] = false
				deleted_actors[act] = nil
                count = count + 1   

	if act.on_destroy ~= nil then
		act:on_destroy(act)
	end
	act:delete_internal()
				
                is_deleted = true
			end
		end
        if not is_deleted then
            print("not deleted : ", act.classname)
        end
	end
    if count > 0 then
        --print("actors deleted count:", count)
    end
--]]

-- [===[
    -- ※削除処理中にさらに削除対象が増えるとテーブルが書き換わり、ループがうまく
    -- 回らないため、先にコピーしておく
	local deleted_actors = self.deleted_actors
    local delete_tmp = self.delete_tmp
	for act,v in pairs(deleted_actors) do
        delete_tmp[act] = v
    end
	clear_table(self.deleted_actors)


	-- 削除されたアクターについては穴(false)に変更する
	local count = 0
	for act,_ in pairs(delete_tmp) do
		local is_deleted = false
		for i,v in ipairs(self.actors) do
			if v == act then
				-- destroy関数を呼ぶ
				--if act.on_destroy ~= nil then
				--	act:on_destroy(act)
				--end
				
				-- キャラを親から切り離す
				act:delete_internal(self)

				-- テーブル要素を消す
				self.actors[i] = false
				--deleted_actors[act] = nil
				count = count + 1
				
				is_deleted = true
			end
		end
		if not is_deleted then
			-- 状態関数のない単なるActorの場合はここにくる
			-- print("not deleted : ", act.classname, tostring(act))
			-- キャラを親から切り離す
			act:delete_internal(self)
		end
	end
	if count > 0 then
		--print("actors deleted count:", count)
	end
	clear_table(self.delete_tmp)
--]===]
end


-- 指定アクター（複数）を追加するサブルーチン
function Scheduler:add_actor_sub(added_actors)
	-- 配列に穴(false)があれば、そこに追加
	local next_act, flag
	for i,v in ipairs(self.actors) do
		if v == false then
            -- flagはtrueならば存在。
			next_act, flag = next(added_actors, next_act)
			if next_act == nil then
				return -- addedテーブルの終端なので終了
			end
            if flag == true and not next_act.is_dead_actor then
                self.actors[i] = next_act
            end
		end
	end
	-- 末尾に追加
	while true do
		next_act, flag = next(added_actors, next_act)
		if next_act == nil then
			return -- addedテーブルの終端なので終了
		end
        if flag == true and not next_act.is_dead_actor then
            table.insert(self.actors, next_act)
        end
	end
end


--[[
function Scheduler:add_actor(act)
	-- 配列に穴(false)があれば、そこに追加
	for i,v in ipairs(self.actors) do
		if v == false then
			self.actors[i] = act
			return
		end
	end
	-- 末尾に追加
	table.insert(self.actors,act)
end
]]


--
--  Routine
--

local dummy_func = function(act, rt) end

class ("Routine") {
	__tostring = function(self)
		return("class Routine name="..self.name)
	end,
}

-- コンストラクタ
function Routine:ctor(...)
	self.wait_count = 0
	self.co = nil
	self.func = nil
    self.actor = nil
	self.state = "init"
		-- "end": 正常終了した状態（関数を取り替えて継続できる）
		-- "run": 関数実行中（関数を取替えられない）
end

-- ルーチンの初期化
function Routine:init(f)
	self:change_func(f)
	self:restart()
end

local costatus = coroutine.status
local coresume = coroutine.resume
local coyield = coroutine.yield

-- ルーチンを再開
function Routine:resume(actor)
	self.actor = actor

	for i=0,10 do -- 無限ループしないよう、限界を決めておく
		if not self.co then
			return true
		end
		if costatus(self.co) == "dead" then
			--self:restart()
			return true
		end
		-- コルーチン再開
		-- コルーチンの引数は (アクター,ルーチン) を渡す
		local res, value, value2 = coresume(self.co, self)
		if not res then
			local stacktrace = debug.traceback()
			error("Routine:resume() error: ¥n "..tostring(value).." ¥n"..stacktrace)
		end
		-- yieldの返り値によって処理
		if value == "exit" then
			-- ルーチン終了
			return "exit"
		elseif value == "restart" then
			-- ルーチン再起動：そのまま実行
			self:restart()
		elseif value == "goto" then
			-- 別のルーチンに移動
			--print("goto : actor: "..tostring(actor).." target : "..value2)
			if not actor:change_routine(value2) then
			  error("Routine:resume() error: change_routine() failed. actor: "..tostring(actor).." target : "..value2)
			end
		elseif value == "wait" then
			-- 次回起動までのウエイト設定
			if type(value2) ~= "number" then
			  error("Routine wait(n) error: n is not number. type:"..type(value2).." actor:"..tostring(actor) )
			end
			self.wait_count = value2
			return true
		--elseif value == "end" then
		--	-- 一旦終了
		--	return "exit"
		else
			error("Routine:resume() : unknown yield command from: "..tostring(actor.classname).." return value :"..tostring(value))
		end
	end

	print("Routine:resume() : too many loop on actor :", actor)
	return false
end

-- コルーチンを作成しなおす
function Routine:restart()
	if self.state == "end" then
		-- コルーチンリサイクル可能状態のため、作りなおす必要がない
		return true
	end
	
	-- 後でfuncを取り替えられるように、１段関数をかませておく
	local function caller(rt)
		if rt ~= self then
			error("rt ~= self")
		end
		local ret = "init"
		local label
		while true do
			if self.func == nil then
				error("attemt to resume empty Routine : ret :"..tostring(ret)..","..tostring(label)
						.." actor class:"..tostring(self.actor.classname) )
			end
			self.state = "run"
			ret, label = self.func(self.actor, rt)
			self.state = "end"
			
			-- restartの場合はnilにできない
			if ret ~= "restart" then
				self.func = nil
			end

			--[[
			if ret == "goto" then
				coyield("goto", label)
			elseif ret == "exit" then
				coyield("exit")
			else
				coyield(ret)
			end
			]]
			coyield(ret, label)
		end
	end

	-- コルーチン作成
	self.co = coroutine.create(caller)
	self.state = "end"
	
	return true
end

function Routine:change_func(f)
	self.func = f
end






class ("RoutinePool") {
}

-- コンストラクタ
function RoutinePool:ctor(...)
	self.pool = {}
end

-- 初期化
-- pool_countの数だけルーチンインスタンスを蓄えておく
function RoutinePool:init(pool_count)
    for i=1,pool_count do
        table.insert(self.pool, self:get_new_routine())
    end
end

-- 新しいルーチンを作成して返す。
-- 実行対象にはダミー関数を入れておく。
function RoutinePool:get_new_routine()
    local rt = Routine:new()
    rt:init(dummy_func)
    return rt
end

-- ルーチンをプールに返す
function RoutinePool:return_to_pool(rt)
	rt.actor = nil
    rt:change_func(dummy_func)
	-- コルーチン実行中ならコルーチンを作り直す。
	-- （不要オブジェクト処理のためにも重要）
    rt:restart() 
	-- 穴(false値)を見つけてそこにroutineをセット
    for i,v in ipairs(self.pool) do
        if v == false then
            self.pool[i] = rt
            return
        end
    end
    table.insert(self.pool,rt)
end

-- ルーチンを１つ借りる
function RoutinePool:get_from_pool()
    for i,rt in ipairs(self.pool) do
        if rt ~= false then
            self.pool[i] = false -- 貸した場所には穴(false値)をあけておく
			if rt.func ~= dummy_func then
				error("Maybe already in rental...")
			end
            return rt
        end
    end
    return self:get_new_routine()
end