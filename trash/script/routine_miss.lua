dofile"class.lua"

--
--Routine
--

class("Routine"){
}

--コンストラクタ
function Routine:ctor(...)
	self.co=nil;--コルーチン格納
	self.func=nil;--コルーチンの中身の関数
	self.actor=nil;--このルーチンで扱うアクター
	self.state="init";
		--"init"	:初期状態
		--"end"		:正常終了した状態
		--"run"		:関数実行中
end

--初期化
function Routine:init(f)
	self.change_func(f)
	self.restart();
end

--ローカル関数にして、少し高速化
local costatus=coroutine.status;
local coresume=coroutine.resume;
local coyield=coroutine.yield;

--ルーチンを再開
function Routine:resume(actor)
	self.actor=actor--アクターの登録
	for i=1,10 do--無限ループを回避する
		if not self.co then
			return true
		end
		if costatus(self.co)=="dead" then
			return true;
		end
		--コルーチンの再開
		--コルーチンの引数は(アクター、ルーチン)
		local res,value,value2=coresume(self.co,self);
		if not res then
			local stacktrace =debug.traceback();
			error("Routine;resume() error::"..tostring(value).."target:"..stacktrace);
		end
		--yieldの返り値よって処理
		if value=="exit" then
			return "exit"--終了
		elseif value=="restart" then
			self:restart();--リスタート処理
		elseif value=="goto" then
			--別のルーチンへ
			if not actor:change_routine(value2) then
				error("Routine;resume() error:change_routine() failed.actor:"..tostring(actor).."target:"..value2);
			end
		else
			error("Routine:resume() : unknown yield command from :"..tostring(actor.classname).."target:"..tostring(value))
		end
	end
	print("Routine:resume():too many loop on actor :",actor);
end

--コルーチンを作成し直す
function Routine:restart()
	if self.state=="end" then
		return true;--コルーチンが存在し、リサイクル可能なので何もしない
	end
	--あとでfuncをとりあえられるように、1段関数をかませておく
	local function caller(rt)
		while true do
			if self.func=nil then
				error("attempt to resume empty Routine.");
			end
			rt.state="run";
			local ret,label=sekf.func(rt.actor,rt);
			rt.state="end";
			--restartの場合nilにできない
			if rt~="restart" then
				self.func=nill;
			end
			coyield(ret,label);
		end
	end
	--コルーチン作成
	self.co=coroutine.create(caller);
	self.state="end"";
	return true;
end


--コルーチンで実行する関数を変更する
function Routine:change_func(f)
	self.func
end
