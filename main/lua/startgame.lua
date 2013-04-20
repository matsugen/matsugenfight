local GS=GS;
function StartGame()
    GS.routinepool = RoutinePool:new()
    GS.routinepool:init(50)
	GS.scheduler = Scheduler:new()
	-- シーン移行の場合
	if GS.next_scene_class ~= nil then
		if GS.scene ~= nil then
			GS.scheduler:delete_actor(GS.scene)
		end
		GS.scheduler:process_deleted_actors()
		GS.scene = GS.next_scene_class:new()
		GS.scene:init(unpack(GS.next_scene_cfg))
		GS.scene:add_sprite_to_drawsystem(GS.drawsystem)
		GS.next_scene_class = nil
		GS.next_scene_cfg = nil
	end

	if GS.scene == nil then
		return "no scene"
	end
	
	-- スケジューラー処理
	GS.scheduler:schedule()	

	-- シーンごとのスケジューラー後処理
	if GS.scene.post_schedule ~= nil then
		GS.scene:post_schedule()
	end
	
	return "ok"
end


-- シーンを変更
function change_scene(scene_class, ...)
	GS.next_scene_class = scene_class
	GS.next_scene_cfg = {...}
end
