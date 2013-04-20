dofile"class.lua"
dofile"Image.lua"
dofile"resource.lua"

--[[
�����I�Ɏ����B�R�����g������"**"���t���Ă�����̂̓e�X�g�p�ɏ������R�[�h
]]
class("Chara",vars_overwrite){--�X�V���㏑������
};


function Chara:ctor(...)
	local x1,x2,y1,y2=0,0,0,0;--**
	local filename=...;--**
	assert(type(filename)=="string","not filename");--�t�@�C���������͂���Ă��邩�ǂ�����F��**
	local hundle=Dx.FileOpen(filename);--�t�@�C��������n���h�����擾
	self.attack=collision.Attack(hundle);--����N���X���n���h�����珉����
	_,x1,x2,y1,y2=self.attack:GetRect(x1,x2,y1,y2);--**
	print(string.format("\nx[%d:%d] y[%d:%d]",x1,x2,y1,y2));--**
	self.hit=collision.Hit(hundle);--����N���X���n���h�����珉����
	_,x1,x2,y1,y2=self.hit:GetRect(x1,x2,y1,y2);--**
	print(string.format("\nx[%d:%d] y[%d:%d]",x1,x2,y1,y2));--**
	self.push=collision.Push(hundle);--����N���X���n���h�����珉����
	_,x1,x2,y1,y2=self.push:GetRect(x1,x2,y1,y2);--**
	print(string.format("\nx[%d:%d] y[%d:%d]",x1,x2,y1,y2));--**
	Dx.FileClose(hundle);--�擾�����n���h�����J������
	hundle=nil;
	self.walk=ImageLoad("0-0.png",72,192,5);--**
	self.spr=self.walk[0];--**
	self.x=100;--x���W
	self.y=0;--y���W
end

function Chara:Draw()--���݂̉摜�̕\��(�����I�ɐÎ~��)
	Dx.DrawImage(self.x,self.y,self.spr,DIRECTION_LEFT,1);
end

function Chara:DrawHit()--�A�^������N���X�̕\��(�������̗΂̋�`)
	local x1,x2,y1,y2=0,0,0,0;
	_,x1,x2,y1,y2=self.hit:GetRect(x1,x2,y1,y2);
	Dx.DrawCollision(0,255,0,self.x+x1,self.x+x2,self.y+y1,self.y+y2);
end
function Chara:DrawAttack()--�U������N���X�̕\��(�������̐Ԃ̋�`)
	local x1,x2,y1,y2=0,0,0,0;
	_,x1,x2,y1,y2=self.attack:GetRect(x1,x2,y1,y2);
	Dx.DrawCollision(255,0,0,self.x+x1,self.x+x2,self.y+y1,self.y+y2);
end
function Chara:DrawHit()--�����蔻��N���X�̕\��(�������̐̋�`)
	local x1,x2,y1,y2=0,0,0,0;
	_,x1,x2,y1,y2=self.hit:GetRect(x1,x2,y1,y2);
	Dx.DrawCollision(0,0,255,self.x+x1,self.x+x2,self.y+y1,self.y+y2);
end