--[[スクリプトのロード関数]]
dofile"Image.lua"
dofile"Dummy.lua"
dofile"class.lua"
--この関数からスタート
local FIRST_PLAYER=DIRECTION_RIGHT;
local SECOND_PLAYER=DIRECTION_LEFT;
local key=Key();
local P1=Dummy:new(FIRST_PLAYER);
local Attack=Attack_Collision();
local x1,x2,y1,y2=0,0,0,0;
function main()
	type=Attack:GetType();
	Dx.String(200,0,0,200,200,string.format("type:%d",type));
	key:KeyState();
	Push=key:GetPush();
	Down=key:GetDown();
	Up=key:GetUp();
	P1:receive(Up,Down,Push);
	P1:state();
	P1:Draw();
	Dx.DrawCollision(255,0,0,P1.x,P1.y,P1.x+72,P1.y+192);

end
