dofile"class.lua"

--
--Routine
--

class("Routine"){
}

--�R���X�g���N�^
function Routine:ctor(...)
	self.co=nil;--�R���[�`���i�[
	self.func=nil;--�R���[�`���̒��g�̊֐�
	self.actor=nil;--���̃��[�`���ň����A�N�^�[
	self.state="init";
		--"init"	:�������
		--"end"		:����I���������
		--"run"		:�֐����s��
end

--������
function Routine:init(f)
	self.change_func(f)
	self.restart();
end

--���[�J���֐��ɂ��āA����������
local costatus=coroutine.status;
local coresume=coroutine.resume;
local coyield=coroutine.yield;

--���[�`�����ĊJ
function Routine:resume(actor)
	self.actor=actor--�A�N�^�[�̓o�^
	for i=1,10 do--�������[�v���������
		if not self.co then
			return true
		end
		if costatus(self.co)=="dead" then
			return true;
		end
		--�R���[�`���̍ĊJ
		--�R���[�`���̈�����(�A�N�^�[�A���[�`��)
		local res,value,value2=coresume(self.co,self);
		if not res then
			local stacktrace =debug.traceback();
			error("Routine;resume() error::"..tostring(value).."target:"..stacktrace);
		end
		--yield�̕Ԃ�l����ď���
		if value=="exit" then
			return "exit"--�I��
		elseif value=="restart" then
			self:restart();--���X�^�[�g����
		elseif value=="goto" then
			--�ʂ̃��[�`����
			if not actor:change_routine(value2) then
				error("Routine;resume() error:change_routine() failed.actor:"..tostring(actor).."target:"..value2);
			end
		else
			error("Routine:resume() : unknown yield command from :"..tostring(actor.classname).."target:"..tostring(value))
		end
	end
	print("Routine:resume():too many loop on actor :",actor);
end

--�R���[�`�����쐬������
function Routine:restart()
	if self.state=="end" then
		return true;--�R���[�`�������݂��A���T�C�N���\�Ȃ̂ŉ������Ȃ�
	end
	--���Ƃ�func���Ƃ肠������悤�ɁA1�i�֐������܂��Ă���
	local function caller(rt)
		while true do
			if self.func=nil then
				error("attempt to resume empty Routine.");
			end
			rt.state="run";
			local ret,label=sekf.func(rt.actor,rt);
			rt.state="end";
			--restart�̏ꍇnil�ɂł��Ȃ�
			if rt~="restart" then
				self.func=nill;
			end
			coyield(ret,label);
		end
	end
	--�R���[�`���쐬
	self.co=coroutine.create(caller);
	self.state="end"";
	return true;
end


--�R���[�`���Ŏ��s����֐���ύX����
function Routine:change_func(f)
	self.func
end
