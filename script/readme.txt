*_Collision:
	各判定のクラス名。
	"クラス名()"でインスタンス化引数に文字列を用いることでファイル名でパラメータを初期化
	各クラスにはそれぞれの要素を取得するGet関数が存在する
	以下*_Collisionのヘッダファイルのpublic部分を抜粋
	/*collision.h*/
	/*
	 * 攻撃判定クラス
	 */
	class Attack_Collision{
		Attack_Collision();
		Attack_Collision(FILE* file);
		~Attack_Collision();
		int GetRect(int* a1,int* a2,int* b1,int* b2);//判定矩形の取得
		int GetType();//攻撃タイプの取得
		int GetDamage();//ダメージの取得
		int AirHit(int* dx,int* dy,int* p);//空中ヒット時の吹き飛び方向、削減値の取得
		int GroundHit(int* dx,int* dy,int* t,int* p);//地上ヒット時の吹き飛び方向とのけぞり時間。lua側でdy>0のときはのけぞり時間を考えない

	};

	/*
	 * 押し出し判定クラス
	 */
	class Push_Collision{
		Push_Collision();
		Push_Collision(FILE *file);
		~Push_Collision();
		int GetRect(int *a1,int *a2,int *b1,int *b2);//判定矩形の取得
		int GetAxis();//キャラ軸取得
	};
	/*
	 * 食らい判定クラス
	 */
	class Hit_Collision{
		Hit_Collision();
		Hit_Collision(FILE* file);
		~Hit_Collision();
		int GetRect(int *a1,int *a2,int *b1,int *b2);//判定矩形の取得
	};

	/*collision.h*/
	
/*以下雑多な説明*/
	
*_missは失敗作。後学のため残す。
test.luaに主な動作を記述している
現状はすべてのパラメータを0で初期化したAttack_CollisionクラスをAttackにインスタンス化し、typeを取得・表示している
他に、左上に信号(現在は常にNONE)とキー入力を数値化したものを表示し、キーボードの"Q"キーでパンチモーション、方向キーで左右にのみ移動可能
今後は追加した各Collisionクラスを用いて技などのモーションをファイル読み込みだけで実行できるようにする
以後やっていきたいこと
luaの連想配列機能を用いて、読み込んだファイルの拡張子を覗いた部分を技参照のキーとして用いる
こうすることで、おそらく関数を多く使わず、連想配列を走査するだけで技を実行できると思われる。
読み込んだファイルの拡張子を除いた部分を連想配列のキーとするにはどうするか。
また、技の信号を受け取った場合別の動作に移行するにはどうするか。課題は残る。
