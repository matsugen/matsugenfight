dofile"class.lua"
dofile"Image.lua"
dofile"resource.lua"


class("Chara",vars_overwrite){
};


function Chara:ctor(...)
	local x1,x2,y1,y2=0,0,0,0;
	local filename=...;
	assert(type(filename)=="string","not filename");
	local hundle=Dx.FileOpen(filename);
	self.attack=collision.Attack(hundle);
	_,x1,x2,y1,y2=self.attack:GetRect(x1,x2,y1,y2)
	print(string.format("\nx[%d:%d] y[%d:%d]",x1,x2,y1,y2));
	self.hit=collision.Hit(hundle);
	_,x1,x2,y1,y2=self.hit:GetRect(x1,x2,y1,y2)
	print(string.format("\nx[%d:%d] y[%d:%d]",x1,x2,y1,y2));
	self.push=collision.Push(hundle);
	_,x1,x2,y1,y2=self.push:GetRect(x1,x2,y1,y2)
	print(string.format("\nx[%d:%d] y[%d:%d]",x1,x2,y1,y2));
	Dx.FileClose(hundle);
	self.walk=ImageLoad("0-0.png",72,192,5);
	self.spr=self.walk[0];
	self.x=100;
	self.y=0;
end

function Chara:Draw()
	Dx.DrawImage(self.x,self.y,self.spr,DIRECTION_LEFT,1);
end

function Chara:DrawHit()
	local x1,x2,y1,y2=0,0,0,0;
	_,x1,x2,y1,y2=self.hit:GetRect(x1,x2,y1,y2);
	Dx.DrawCollision(0,255,0,self.x+x1,self.x+x2,self.y+y1,self.y+y2);
end
function Chara:DrawAttack()
	local x1,x2,y1,y2=0,0,0,0;
	_,x1,x2,y1,y2=self.attack:GetRect(x1,x2,y1,y2);
	Dx.DrawCollision(255,0,0,self.x+x1,self.x+x2,self.y+y1,self.y+y2);
end
function Chara:DrawHit()
	local x1,x2,y1,y2=0,0,0,0;
	_,x1,x2,y1,y2=self.hit:GetRect(x1,x2,y1,y2);
	Dx.DrawCollision(0,0,255,self.x+x1,self.x+x2,self.y+y1,self.y+y2);
end