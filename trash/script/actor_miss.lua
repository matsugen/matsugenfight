dofile"class.lua"

--
--書籍の"Actor"クラスをほぼ丸写し
--適宜コメントを挿入して内容の理解度を記載しておく。
--
--[[
	Actorのクラス変数・関数の定義ここから
]]
class("Actor"){
	all_actors={};--生成したアクターのインスタンスをテーブルに
				  --保持しておくことでデバッグ時の管理を楽にする
	id_couter=1;--上記のテーブルのキーとするidを変数にしておく
}

--Actorを保持するテーブルall_actorsを弱参照にする。
--これにより、不要となったActorをガベージコレクタの対象とする
setmetatable(Actor.all_actors,{__mode="kv"});

--(クラス関数)新しいIDの取得
function Actor.getid()--クラス変数をいじるため、":"を用いるとややこしい
	local next_id=Actor.id_counter;
	Actor.id_counter=Actor.id_counter+1;
	return next_id;
end

--(クラス関数)IDを用いてアクターの検索を行う
function Actor.search(id)
	return Actor.all_actors[id];
end

--[[
	クラス変数・関数の定義ここまで
]]

--[[
	ここからメンバ関数
]]
--コンストラクタ
function Actor:ctor(...)
	self.name=self.classname;--クラス名の参照を容易に
	self.spr=nil;--アクターのスプライト
	self.routine=nil;--アクターのルーチンインスタンスの格納場所
	self.params={};--アクターの内部パラメータ(ここに現在の座標とかを入れる？)
	self.cfg={};--アクターの初期設定(ここにキャラクターの固定のデータ。例:判定とか発生フレームとか)
	self.id=self:getid();
	self.children={};--ここに子アクターのnew関数を入れる
	self.func=nil;--アクターの現在の動作関数を格納
	Actor.all_actors[self.id]=self--テーブルかアクターのインスタンスを検索できるようにする
end


--アクターの初期化
function Actor:init(cfg,children)
	self.cofunc=Routine:new();--そんなにたくさんのルーチンを扱うつもりはないから、プールはいらんでしょ
	--start関数を現在の処理に設定
	if self.cofunc~=nil then
		self:change_routine("wait")--動作関数startを設定
	end

	--設定を保存
	self.cfg= cfg or {};
	self.children=children or {};
	self.param=self.cfg;
end


--連想配列を用いて、実行関数を変更する関数
function Actor:change_routine(name)
	--コルーチンを持っているかどうか、指定関数があるかどうかをチェック
	if self.routine== nil then--ルーチンがない
		print("Actor:change_routine : routine not found:",name);
		return false
	end
	--クラスの持つメンバ関数から探す
	local f=self[name];
	if f==nil or type(f)~="function" then
		print("Actor:change_routine:coroutine. func not found:",name);
	end
	--ルーチン変更してリスタートする
	self.routine:change_func(f);
	self.routine:restart();
	self.func=name;
	return true;
end

function Actor:schedule()
	local rt=act.routine;--実行するアクターのルーチンをローカル変数へ
	if rt~=nil and rt.co~=nil then
		local ret=rt:resume(self);
		if ret=="exit" then
			return nil;--自分自身が終わってしまったら、アクターを格納してる変数を捨ててやる
		elseif ret==false then
			error("error: Actor:schedule");
		end
		for i,child in ipairs(self.children) do
			childe=child:schedule();
		end
	end
	return self;
end

local coyield=coroutine.yield

function Actor:wait()
	coyeild("wait");
end