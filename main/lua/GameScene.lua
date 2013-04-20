
subclass("GameScene", Actor) {
}

-- コンストラクタ
function GameScene:ctor(...)
	print("GameScene:ctor() called")
	GameScene.super.ctor(self, ...)
    self.field = nil -- フィールドアクター
	self.scroller = nil -- フィールドをスクロールするスクロールバー
end

function GameScene:init(cfg)
	self:init_null_sprite(0,0,0);--ステージ
	self.spr:SetScale(1.0,1.0);--スケールを等倍に
    GameScene.super.init(self,cfg);
end
