package sprite_window;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

public class State {
	private int axis;//キャラ軸
	private int type;//状態のビット列 投げ無敵1<<0 空中判定1<<1 行動可能1<<2 ガード可能1<<3 ...
	private int vx,vy;//キャラ自体の移動速度・方向
	private int time;//発生フレーム
	public State(){
		axis=type=vx=vy=time=0;
	}
	public void setAxis(int a){
		axis=a;
	}
	public void setType(boolean flg,int index){//チェックボックスのbooleanを取得し,indexの位置に設置
		int bit;
		if(flg){
			bit=1<<index;
		}else{
			bit=0<<index;
		}
		type=type|bit;
	}
	public void setSpeed(int x,int y){
		vx=x;
		vy=y;
	}
	public void setTime(int t){
		time=t;
	}
	public int getAxis(){
		return axis;
	}
	public int[] getSpeed(){
		int[] speed=new int[2];
		speed[0]=vx;
		speed[1]=vy;
		return speed;
	}
	public boolean getType(int index){//チェックボックスのbooleanを取得し,indexの位置に設置
		boolean flg=false;
		if((type|(1<<index))>0){
			flg=true;
		}
		return flg;
	}
	public int getTime(){
		return time;
	}public void Serializer(String file){
		File f=new File(file);
		try {
			FileOutputStream fw=new FileOutputStream(f);
			BufferedOutputStream Buf=new BufferedOutputStream(fw);
			Buf.write(ByteInt.tobyte(axis));
//			System.out.printf("x1=%x\n",x1);
			Buf.write(ByteInt.tobyte(type));
//			System.out.printf("x2=%x\n",x2);
			Buf.write(ByteInt.tobyte(vx));
//			System.out.printf("y1=%x\n",y1);
			Buf.write(ByteInt.tobyte(vy));
//			System.out.printf("y2=%x\n",y2);
			Buf.write(ByteInt.tobyte(time));
//			System.out.printf("y2=%x\n",y2);
			Buf.flush();
			Buf.close();
		} catch (IOException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}

	}
	public void Serializer(File file){
		try {
			FileOutputStream fw=new FileOutputStream(file);
			BufferedOutputStream Buf=new BufferedOutputStream(fw);
			Buf.write(ByteInt.tobyte(axis));
//			System.out.printf("x1=%x\n",x1);
			Buf.write(ByteInt.tobyte(type));
//			System.out.printf("x2=%x\n",x2);
			Buf.write(ByteInt.tobyte(vx));
//			System.out.printf("y1=%x\n",y1);
			Buf.write(ByteInt.tobyte(vy));
//			System.out.printf("y2=%x\n",y2);
			Buf.write(ByteInt.tobyte(time));
//			System.out.printf("y2=%x\n",y2);
			Buf.flush();
			Buf.close();
		} catch (IOException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}

	}
	public void Load(BufferedInputStream Buf){
		byte[] b=new byte[4];
		try {
			Buf.read(b,0,4);
			axis=ByteInt.toint(b);
			Buf.read(b,0,4);
			type=ByteInt.toint(b);
			Buf.read(b,0,4);
			vx=ByteInt.toint(b);
			Buf.read(b,0,4);
			vy=ByteInt.toint(b);
			Buf.read(b,0,4);
			time=ByteInt.toint(b);
		} catch (IOException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}
	}
}
