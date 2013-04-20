dofile"class.lua"
dofile"Image.lua"
dofile"resource.lua"

--[[
試験的に実装。コメント末尾に"**"が付いているものはテスト用に書いたコード
]]
class("Chara",vars_overwrite){--更新時上書きする
};


function Chara:ctor(...)
	local x1,x2,y1,y2=0,0,0,0;--**
	local filename=...;--**
	assert(type(filename)=="string","not filename");--ファイル名が入力されているかどうかを認識**
	local hundle=Dx.FileOpen(filename);--ファイル名からハンドルを取得
	self.attack=collision.Attack(hundle);--判定クラスをハンドルから初期化
	_,x1,x2,y1,y2=self.attack:GetRect(x1,x2,y1,y2);--**
	print(string.format("\nx[%d:%d] y[%d:%d]",x1,x2,y1,y2));--**
	self.hit=collision.Hit(hundle);--判定クラスをハンドルから初期化
	_,x1,x2,y1,y2=self.hit:GetRect(x1,x2,y1,y2);--**
	print(string.format("\nx[%d:%d] y[%d:%d]",x1,x2,y1,y2));--**
	self.push=collision.Push(hundle);--判定クラスをハンドルから初期化
	_,x1,x2,y1,y2=self.push:GetRect(x1,x2,y1,y2);--**
	print(string.format("\nx[%d:%d] y[%d:%d]",x1,x2,y1,y2));--**
	Dx.FileClose(hundle);--取得したハンドルを開放する
	hundle=nil;
	self.walk=ImageLoad("0-0.png",72,192,5);--**
	self.spr=self.walk[0];--**
	self.x=100;--x座標
	self.y=0;--y座標
end

function Chara:Draw()--現在の画像の表示(試験的に静止画)
	Dx.DrawImage(self.x,self.y,self.spr,DIRECTION_LEFT,1);
end

function Chara:DrawHit()--アタリ判定クラスの表示(半透明の緑の矩形)
	local x1,x2,y1,y2=0,0,0,0;
	_,x1,x2,y1,y2=self.hit:GetRect(x1,x2,y1,y2);
	Dx.DrawCollision(0,255,0,self.x+x1,self.x+x2,self.y+y1,self.y+y2);
end
function Chara:DrawAttack()--攻撃判定クラスの表示(半透明の赤の矩形)
	local x1,x2,y1,y2=0,0,0,0;
	_,x1,x2,y1,y2=self.attack:GetRect(x1,x2,y1,y2);
	Dx.DrawCollision(255,0,0,self.x+x1,self.x+x2,self.y+y1,self.y+y2);
end
function Chara:DrawHit()--当たり判定クラスの表示(半透明の青の矩形)
	local x1,x2,y1,y2=0,0,0,0;
	_,x1,x2,y1,y2=self.hit:GetRect(x1,x2,y1,y2);
	Dx.DrawCollision(0,0,255,self.x+x1,self.x+x2,self.y+y1,self.y+y2);
end