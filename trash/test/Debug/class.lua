function create_class(classname,super_class,class_vars,on_class_reload)
	assert(type(class_vars)~="nil","nil");
	-- �O���[�o���ɂ��łɃN���X���g���Ă���΂�����g��
	local class=rawget(_G,classname);
	local is_reload=false;
	if class==nil then
		--�N���X�̐V�K�쐬�̏ꍇ
		class=class_vars;
		_G[classname]=class;
	else
		--�N���X�̃����[�h�̏ꍇ
		is_reload=ture;
		if on_class_reload~=nil then
			on_class_reload(class,super_class,class_vars);
		end
	end
	--�p������
	if super_class~=nil then
		class.super=super_class;
		if rawget(super_class,"__index")==super_class then
			setmetatable(class,super_class);
		else
			local mt={__index=super_class};
			setmetatabel(class,mt);
		end
	end

	--�C���X�^���X���쐬����new�֐���ǉ�
	--new �̈����ŃR���X�g���N�^�֐�ctor(...)���Ă�
	class.new=function(self,...)
		local t=create_instance(self,{});
		t:ctor(...);
		return t;
	end
	--�N���X����ݒ�
	class.classname=classname;
	--�C���X�^���X�̃��^�e�[�u���p�Ƃ��Ă̐ݒ�
	class.__index=class;

end
--calss:�N���X����邽�߂̊֐�
function class(classname,on_class_reload)
	return function(class_vars)
		create_class(classname,nil,class_vars,on_class_reload);
	end
end

--subclass:�h���N���X����邽�߂̊֐�
function subclass(classname,super_class,on_class_reload)
	return function(class_vars)
		create_class(classname,super_class,class_vars,on_class_reload);
	end
end

local all_instance={};
local all_instance_mt={__mode="kv"};
setmetatable(all_instance,all_instance_mt);
function get_all_instance()
	return all_instance;
end

--�N���X�̃C���X�^���X�𐶐�
function create_instance(class,target)
	local t=target or {};
	if rawget(class,"__index")==class then
		setmetatable(t,class);
	else
		local mt={__index=class};
		setmetatable(t,mt);
	end
	all_instance[t]=true;

	return t;
end

--



--�N���X�ϐ��ǉ���on_reload
function vars_added(class,super_class,class_vars)
	for k,v in pairs(class_vars) do
		if rawget(class,k)==nil then
			class[k]=v;
		end
	end
end

--�N���X�ϐ��̏㏑����on_reload
function vars_overwrite(class,super_class,class_vars)
	for k,v in pairs(class_vars) do
		class[k]=v;
	end
end


--�Ȃɂ����Ȃ�on_reload
function vars_none(class,super_class,class_vars)
end
