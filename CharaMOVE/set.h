#ifndef SET
#define SET
#include"Base.h"
#include"Key.h"

//よく使いそうな

//よく使いそうな変数
//よく使いそうなクラス
class Mainloop{
	private:
		int m_tmptime;			//1ループの処理開始時間
		static const char m_Fps=60;     //Fps
		static Mainloop *m_Instance;	//シングルトンインスタンス
		Mainloop(const Mainloop& r);
		Mainloop& operator=(const Mainloop& r);
		int KeyTime[256];
		bool D_Key[256],U_Key[256];
		Base* state;
		Key* KeyApp;
		Mainloop();
		~Mainloop();                   
	public: 
		bool Seq();		//1ループの処理開始時刻を取得・シーケンス遷移
		bool update();          //描写情報などの更新
		bool print();			//描写
		bool wait();			//1/m_fps秒経過していない間待機させる
		static Mainloop* create();
		static bool destroy();
		bool Debug();
		bool draw();
};

#endif