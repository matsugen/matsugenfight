--[[
	キー入力に関するスクリプト
]]

function on_keyevent(key, is_down, is_ctrl, is_alt, is_shift)
	-- キー情報をモニタリング（デバッグ用）	
	--Face(face)にとりあえずキー情報を送信
	All_Key();
	if is_down then
		-- 特殊機能
		-- F1 : キャラ部分リロード
		-- F2 : 全スクリプトリロード
		-- F9 : 実行情報出力
		if key == Key.F1 then
			ReloadLuaFiles("chars")
			return
		end
		if key == Key.F2 then
			ReloadLuaFiles("all")
			return
		end
		if key == Key.F9 then
			print("GC count = ",collectgarbage("count"))
			print("F9 pressed")
			analyze_instances()
			Delay(5000)
			return
		end			
	end
end
--キーの入力状況をキーごとに入手
function KeyState(keynum)
	return GetState(keynum)~=0;
end
--すべてのクラスのキー入力を送信する。なければしない。
function All_Key()
	local instances=get_all_instances();
	for instance,value in pairs(instances) do
		local member=instance.member;
		for i,m in ipairs(member) do
			if m.KeyEvent ~=nil then
				m:KeyEvent();
			end
		end
	end
end