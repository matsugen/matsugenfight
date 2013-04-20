print("load/endgame.lua")

function EndGame()
	Back=nil;
	All_End();
end

function All_End()
	local class=get_all_instances();
	for instance,v in pairs(class) do
		local member=instance.member;
		for i,m in ipairs(member) do
			if m~=nil then
				m=nil;
			end
		end
	end
	collectgarbage("collect");
end

