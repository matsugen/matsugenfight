
print("gameinit.lua");

collectgarbage("setpause", 105)
collectgarbage("setstepmul", 1000)
collectgarbage("collect")


global "GS"

GS = {
	scheduler = nil,                      -- スケジューラー
	imageloader = GetImageLoader(), -- 画像ローダー
	drawsystem = GetDrawSystem(),   -- 描画システム
	scene = nil,            -- 現在のシーン（アクター）
}
