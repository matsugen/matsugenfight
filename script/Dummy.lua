dofile"class.lua"
dofile"resource.lua"
dofile"Image.lua"
--[[
local cocreate=coroutine.create;
local coresume=coroutine.resume;
local coyield=coroutine.yeild;
]]
Dx.InitImage();
class("Dummy",vars_overwrite){
	LP=ImageLoad("0-1.png",72,192,5),
	walk=ImageLoad("0-0.png",72,192,5),
	speed=1
}
function Dummy:ctor(...)
	self.state=self:wait();
	self.spr=Dummy.walk[0];
	self.dir=...;
	self.Push=0;self.Up=0;self.Down=0;
	self.x=0;self.y=200;
	self.signal="NONE"
end



function PushCheck()
	local signal="NONE";
	return signal;
end

function Dummy:Draw()
	Dx.DrawImage(self.x,self.y,self.spr,self.dir,1);
end

function Dummy:wait()
	local i=0;
	local time=0;
	return function()
		if AND(self.Down,KEY_Q)>0 then
			self.state=self:LightPunch();
		elseif AND(self.Push,KEY_RIGHT)>0 then
			if self.dir==DIRECTION_RIGHT then
				self.state=self:forward();
			else
				self.state=self:back();
			end
		elseif AND(self.Push,KEY_LEFT)>0 then
			if self.dir==DIRECTION_LEFT then
				self.state=self:forward();
			else
				self.state=self:back();
			end
		else
			self:wait();
		end
		self.spr=Dummy.walk[0];
	end
end


function Dummy:forward()
	local time=0;
	local i=0;
	return function()
	--歩行処理
		if self.dir==DIRECTION_RIGHT then
			self.x=self.x+Dummy.speed;
		else
			self.x=self.x-Dummy.speed;
		end
		if time==6 then
			i=i+1;
			i=i%5;
			time=0;
		else
			time=time+1;
		end
	--歩行処理ここまで
	--キー判別処理
		if AND(self.Down,KEY_Q)>0 then
			self.state=self:LightPunch();
		elseif AND(self.Push,KEY_RIGHT)>0 then
			if self.dir==DIRECTION_RIGHT then
				self.state=self:forward();
			else
				self.state=self:back();
			end
		elseif AND(self.Push,KEY_LEFT)>0 then
			if self.dir==DIRECTION_LEFT then
				self.state=self:forward();
			else
				self.state=self:back();
			end
		else
			self.state=self:wait();
		end
	--キー判別処理終了
		self.spr=Dummy.walk[i];
	end
end
function Dummy:back()
	local time=0;
	local i=0;
	return function()
	--歩行処理
		if self.dir==DIRECTION_RIGHT then
			self.x=self.x-Dummy.speed;
		else
			self.x=self.x+Dummy.speed;
		end
		if time==6 then
			i=i+4;
			i=i%5;
			time=0;
		else
			time=time+1;
		end
		--キー入力処理
		if AND(self.Down,KEY_Q)>0 then
			self.state=self:LightPunch();
		elseif AND(self.Push,KEY_RIGHT)>0 then
			if self.dir==DIRECTION_RIGHT then
				self.state=self:forward();
			else
				self.state=self:back();
			end
		elseif AND(self.Push,KEY_LEFT)>0 then
			if self.dir==DIRECTION_LEFT then
				self.state=self:forward();
			else
			end
				self.state=self:back();
		else
			self.state=self:wait();
		end
		self.spr=Dummy.walk[i];
	end
end

--[[function Dummy:reverse()
	return function()
		self.dir=(self.dir+1)%2;
		self.state=self:step();
	end
end]]

--この関数をいじる
--[[バグ内容
	↑を入力してもNONEにならないので、→を押してから↑を押しながら→を離しても歩き続ける
]]
function Dummy:receive(Up,Down,Push)
	local up=Up;local down=Down;local push=Push;
	Dx.String(0,0,0,0,0,string.format("%d,%d,%d",up,down,push));

	Dx.String(0,0,0,0,20,string.format("%s",self.signal));
end

function Dummy:LightPunch()
	local i=0;
	local time=0;
	return function()
		if time==2 then
			i=1;
		elseif time==6 then
			i=2;
		elseif time==10 then
			i=3;
		elseif time==15 then
			i=4;
			self.state=self:wait();
		end
			if time>=6 and time<12 then
				if AND(self.Down,KEY_Q)>0 then
					self.state=self:LightPunch();
				end
			end
			time=time+1;
			self.spr=Dummy.LP[i];
	end
end
function Dummy:receive(Up,Down,Push)
	self.Up=Up;self.Down=Down;self.Push=Push;
	Dx.String(0,0,0,0,0,string.format("%d,%d,%d",self.Up,self.Down,self.Push));
	Dx.String(0,0,0,0,20,string.format("%s",self.signal));
end

