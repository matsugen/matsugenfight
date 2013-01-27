作るもの Collision_Maker
・Window1(Main Window)
├マウスのクリックアンドドラッグで判定の矩形を作成・削除
├リストボックスで画像→矩形の順に選択し、選択した矩形をハイライト表示。(太線などで囲う)
├ImageLoadボタンでX,Y,Nのパラメータを用いて一つの画像を複数に等分割して取得。
├FileSaveで作成したCollisionデータをセーブ
├FileLoadで過去に作成したデータをロード。
└Collision ReloadボタンでWindow2にある数値に判定を更新
・Window2(Data Window)
├Window1で選択した判定矩形のデータ表示
└データを書き換えWindow1でReloadボタンを押せば編集可
	Window2まではGUI外観が完成済み
・Window3(Play Window)←作成しないかも
├再生ボタンを押して、現在の動作を再生
└ループ・コマ送りなどを可能に。
