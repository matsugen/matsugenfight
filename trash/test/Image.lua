function ImageLoad(filename,x,y,number)
--[[
	filename:読み込むファイルの名前
	x:単位あたりのx幅
	y:単位あたりのy幅
	number:分割数
]]
	local file=filename;
	local local_x=x or 0;--xが数値である保障
	local local_y=y or 0;--yが数値である保障
	local local_hundle={};--分割された画像ハンドルを格納するテーブル
	local tmp_hudle;--画像の全体のハンドルを格納する変数
	local n=number or 1;--nが数値である保障
	local start_x=0;--切り出す画像の左上のx
	local start_y=0;--同上のy
	local check_x=0; local check_y=0; --画像をはみ出さないようにする判定機
	local i=0;
	tmp_hundle=Dx.LoadImagefile(file);
	while i<n do--[[nが数値であることが保証される必要がある]]
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