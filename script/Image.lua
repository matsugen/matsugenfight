function ImageLoad(filename,x,y,number)
--[[
	filename:�ǂݍ��ރt�@�C���̖��O
	x:�P�ʂ������x��
	y:�P�ʂ������y��
	number:������
]]
	local file=filename;
	local local_x=x or 0;--x�����l�ł���ۏ�
	local local_y=y or 0;--y�����l�ł���ۏ�
	local local_hundle={};--�������ꂽ�摜�n���h�����i�[����e�[�u��
	local tmp_hudle;--�摜�̑S�̂̃n���h�����i�[����ϐ�
	local n=number or 1;--n�����l�ł���ۏ�
	local start_x=0;--�؂�o���摜�̍����x
	local start_y=0;--�����y
	local check_x=0; local check_y=0; --�摜���͂ݏo���Ȃ��悤�ɂ��锻��@
	local i=0;
	tmp_hundle=Dx.LoadImagefile(file);
	while i<n do--[[n�����l�ł��邱�Ƃ��ۏ؂����K�v������]]
		local_hundle[i]=Dx.LoadDivImage(tmp_hundle,start_x,start_y,local_x,local_y);
		start_x=start_x+local_x
		_,check_x,check_y=Dx.GetSize(tmp_hundle,check_x,check_y);
		if check_x<=start_x then
			start_x=0;
			start_y=start_y+local_y;
		end
		i=i+1;
	end
	return local_hundle;
end