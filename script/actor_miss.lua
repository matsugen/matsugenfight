dofile"class.lua"

--
--���Ђ�"Actor"�N���X���قڊێʂ�
--�K�X�R�����g��}�����ē��e�̗���x���L�ڂ��Ă����B
--
--[[
	Actor�̃N���X�ϐ��E�֐��̒�`��������
]]
class("Actor"){
	all_actors={};--���������A�N�^�[�̃C���X�^���X���e�[�u����
				  --�ێ����Ă������ƂŃf�o�b�O���̊Ǘ����y�ɂ���
	id_couter=1;--��L�̃e�[�u���̃L�[�Ƃ���id��ϐ��ɂ��Ă���
}

--Actor��ێ�����e�[�u��all_actors����Q�Ƃɂ���B
--����ɂ��A�s�v�ƂȂ���Actor���K�x�[�W�R���N�^�̑ΏۂƂ���
setmetatable(Actor.all_actors,{__mode="kv"});

--(�N���X�֐�)�V����ID�̎擾
function Actor.getid()--�N���X�ϐ��������邽�߁A":"��p����Ƃ�₱����
	local next_id=Actor.id_counter;
	Actor.id_counter=Actor.id_counter+1;
	return next_id;
end

--(�N���X�֐�)ID��p���ăA�N�^�[�̌������s��
function Actor.search(id)
	return Actor.all_actors[id];
end

--[[
	�N���X�ϐ��E�֐��̒�`�����܂�
]]

--[[
	�������烁���o�֐�
]]
--�R���X�g���N�^
function Actor:ctor(...)
	self.name=self.classname;--�N���X���̎Q�Ƃ�e�Ղ�
	self.spr=nil;--�A�N�^�[�̃X�v���C�g
	self.routine=nil;--�A�N�^�[�̃��[�`���C���X�^���X�̊i�[�ꏊ
	self.params={};--�A�N�^�[�̓����p�����[�^(�����Ɍ��݂̍��W�Ƃ�������H)
	self.cfg={};--�A�N�^�[�̏����ݒ�(�����ɃL�����N�^�[�̌Œ�̃f�[�^�B��:����Ƃ������t���[���Ƃ�)
	self.id=self:getid();
	self.children={};--�����Ɏq�A�N�^�[��new�֐�������
	self.func=nil;--�A�N�^�[�̌��݂̓���֐����i�[
	Actor.all_actors[self.id]=self--�e�[�u�����A�N�^�[�̃C���X�^���X�������ł���悤�ɂ���
end


--�A�N�^�[�̏�����
function Actor:init(cfg,children)
	self.cofunc=Routine:new();--����Ȃɂ�������̃��[�`������������͂Ȃ�����A�v�[���͂����ł���
	--start�֐������݂̏����ɐݒ�
	if self.cofunc~=nil then
		self:change_routine("wait")--����֐�start��ݒ�
	end

	--�ݒ��ۑ�
	self.cfg= cfg or {};
	self.children=children or {};
	self.param=self.cfg;
end


--�A�z�z���p���āA���s�֐���ύX����֐�
function Actor:change_routine(name)
	--�R���[�`���������Ă��邩�ǂ����A�w��֐������邩�ǂ������`�F�b�N
	if self.routine== nil then--���[�`�����Ȃ�
		print("Actor:change_routine : routine not found:",name);
		return false
	end
	--�N���X�̎������o�֐�����T��
	local f=self[name];
	if f==nil or type(f)~="function" then
		print("Actor:change_routine:coroutine. func not found:",name);
	end
	--���[�`���ύX���ă��X�^�[�g����
	self.routine:change_func(f);
	self.routine:restart();
	self.func=name;
	return true;
end

function Actor:schedule()
	local rt=act.routine;--���s����A�N�^�[�̃��[�`�������[�J���ϐ���
	if rt~=nil and rt.co~=nil then
		local ret=rt:resume(self);
		if ret=="exit" then
			return nil;--�������g���I����Ă��܂�����A�A�N�^�[���i�[���Ă�ϐ����̂ĂĂ��
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