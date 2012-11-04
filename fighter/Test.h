#ifndef TEST
#define TEST
#include"macro.h"
#include"Dxlib.h"
#define SIZEX 72.0f						//横幅
#define SIZEY 196.0f                                            //高さ
#define MOVESPEED  5.0f                                         //歩行速度
#define GRAVITY 3.0f                                            //重力加速度
#define FIRSTJUMPY 30.0f                                        //ジャンプ初速Y方向
#define FIRSTJUMPX 4.0f                                         //同上X方向
#define JUMPSTOP 3						//ジャンプ硬直


class Test:public Player{
	private:
		void Walk(char Key[]){
			static int time=0;
			static int number=0;
			if(Control){
				if(Key[KEY_INPUT_LEFT]>=1){
					vx=-MOVESPEED;
					if(time>=10){
						number++;
						time=0;
					}else{
						time++;
					}
					number=number%5;
					Image=img[0][0][number];
				}else if(Key[KEY_INPUT_RIGHT]>=1){
					vx=MOVESPEED;
					if(time>=10){
						number++;
						time=0;
					}else{
						time++;
					}
					number=number%5;
					Image=img[0][0][number];
				}else{
					vx=vy=0;
					Image=img[0][0][0];
					time=number=0;
				}
			}
		}
		void Jump(char Key[]){         
		}
	public:
		int date,i,j;
		int fpH,fpA;
		Test(){
			HP=1000;
			RG=1000;
			PG=0;
			posx=0.0;
			posy=200+SIZEY;
			vx=vy=0.0;
			air=Guard=Counter=false;
			jmp=UnGuard=false;
			Control=true;
			Rmode=false;
			H=new Hit();
			A=new Attack();
			/*当たり判定データの読み込み*/
			if((fpH=FileRead_open("testH"))==0){
				perror("fopen");
				exit(EXIT_FAILURE);
			}
			if((fpA=FileRead_open("testA"))==0){
				perror("fopen");
				exit(EXIT_FAILURE);
			}
			while(FileRead_read(&date,sizeof(int),fpH)!=0&&ProcessMessage()!=-1){
				FileRead_read(&(H->position[0]),sizeof(int),fpH);
				for(i=0;i<date&&ProcessMessage()!=-1;i++){
					FileRead_read(&(H->x[0][i][0]),sizeof(int),fpH);
					FileRead_read(&(H->x[0][i][1]),sizeof(int),fpH);
					FileRead_read(&(H->y[0][i][0]),sizeof(int),fpH);
					FileRead_read(&(H->y[0][i][1]),sizeof(int),fpH);
					FileRead_read(&(H->vsattack[0][i]),sizeof(int),fpH);
					FileRead_read(&(H->vsth[0][i]),sizeof(int),fpH);
					FileRead_read(&(H->vsren[0][i]),sizeof(int),fpH);
				}
			}
			while(FileRead_read(&date,sizeof(int),fpA)!=0&&ProcessMessage()!=-1){
				for(i=0;i<date&&ProcessMessage()!=-1;i++){
					FileRead_read(&(A->x[0][i][0]),sizeof(int),fpA);
					FileRead_read(&(A->x[0][i][1]),sizeof(int),fpA);
					FileRead_read(&(A->y[0][i][0]),sizeof(int),fpA);
					FileRead_read(&(A->y[0][i][1]),sizeof(int),fpA);
					FileRead_read(&(A->attack[0][i]),sizeof(int),fpA);
					FileRead_read(&(A->th[0][i]),sizeof(int),fpA);
					FileRead_read(&(A->ren[0][i]),sizeof(int),fpA);
				}
			}
			FileRead_close(fpH);
			FileRead_close(fpA);
			/*データ読み込み終了*/	
		}
		void Load(){
			if(LoadDivGraph("0-0.png",5,5,1,SIZEX,SIZEY,&img[0][0][0])==-1){
				perror("LoadDivGraph");
				exit(EXIT_FAILURE);
			}
			Image=img[0][0][0];	
		}
		
		void Move(){
			posy+=vy;
			posx+=vx;
			if(posx<=0){
				posx=0;
			}
			if(posy<=0){
				posy=0;
			}
			if(posx>=1208){
				posx=1208;
			}
			if(posy>=524){
				posy=524;
			}
		}
		
		void Print(){
			DrawGraph(posx,posy,Image,true);
		}
		void CONTROL(char Key[]){
				Walk(Key);
				Jump(Key);
		}
		~Test(){
			delete A;
			delete H;
			}
};    

#endif        
