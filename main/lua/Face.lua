
class("Face",on_class_reload__overwrite){
	ID=0,
	member={}
};

local mt={__mode="kv"};
setmetatable(Face.member,mt);

function Face.SetID()
	Face.ID=Face.ID+1;
	return Face.ID;
end

function Face:SetMember()
	table.insert(Face.member,self);
end 
function Face:ctor(...)
	self.m_ID=Face.SetID();
	self.player=...;
	self.Sprite={
		Main_Sprite=Sprite("font/VL-PGothic-Regular.ttf","(*´ω｀*)")
	}
	self.Sprite.Main_Sprite:Change_Font("font/VL-PGothic-Regular.ttf",40)
	self.pos={
		x=0,
		y=0
	}
	self.size={
		w=self.Sprite.Main_Sprite:Get_W(),
		h=self.Sprite.Main_Sprite:Get_H()
	}
	self.Sprite.HitBox=Sprite(self.pos.x,self.pos.y,self.size.w,self.size.h);
	self.Sprite.HitBox:Change_Color(255,0,0);
	self.speed={
		x=0,
		y=0
	}
	self:SetMember();
end

function Face:Draw()
	self.pos.x=self.pos.x+self.speed.x;
	self.pos.y=self.pos.y+self.speed.y;
	if (self.pos.x+self.size.w)>640 then
		self.pos.x=640-self.size.w;
	end
	if (self.pos.x)<0 then
		self.pos.x=0;
	end
	if (self.pos.y+self.size.h)>480 then
		self.pos.y=480-self.size.h;
	end
	if (self.pos.y)<0 then
		self.pos.y=0;
	end
	self:Pos(self.pos.x,self.pos.y);
	self.Sprite.Main_Sprite:SetBlit();
	self.Sprite.HitBox:SetBlit();
end

function Face:Pos(x,y)
	for i,v in pairs(self.Sprite) do
		v:Change_Pos(x,y);
	end	
end


function Face:Move()
	self.pos.x=self.pos.x+self.speed.x;
	self.pos.y=self.pos.y+self.speed.y;
end
function Face:KeyEvent()
	if self.player==0 then
		if KeyState(Key.W) then
			self.speed.y=-5;
		end
		if KeyState(Key.S) then
			self.speed.y=5;
		end
		if KeyState(Key.A) then
			self.speed.x=-5;
		end
		if KeyState(Key.D) then
			self.speed.x=5;
		end
		if  (not KeyState(Key.W)) and (not KeyState(Key.S)) and (not KeyState(Key.A)) and (not KeyState(Key.D)) then
			self.speed.x=0;
			self.speed.y=0;
		end
	end
	if self.player==1 then
		if KeyState(Key.UP) then
			self.speed.y=-5;
		end
		if KeyState(Key.DOWN) then
			self.speed.y=5;
		end
		if KeyState(Key.LEFT) then
			self.speed.x=-5;
		end
		if KeyState(Key.RIGHT) then
			self.speed.x=5;
		end
		if  (not KeyState(Key.UP)) and (not KeyState(Key.DOWN)) and (not KeyState(Key.LEFT)) and (not KeyState(Key.RIGHT)) then
			self.speed.x=0;
			self.speed.y=0;
		end
	end
end