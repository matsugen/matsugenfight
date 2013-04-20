package sprite_window;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

public class Hit {
	private int x1,x2,y1,y2;//くらい判定の矩形
	private int type;//無敵のビット列 対打撃1<<0 対特殊1<<1
	public Hit(){
		x1=x2=y1=y2=0;
		type=0;
	}
	public void setRect(int a1,int a2,int b1,int b2){
		x1=a1;
		x2=a2;
		y1=b1;
		y2=b2;
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
	public int[] getRect(){
		int[] rect=new int[4];
		rect[0]=x1;
		rect[1]=x2;
		rect[2]=y1;
		rect[3]=y2;
		return rect;
	}
	public boolean getType(int index){//チェックボックスのbooleanを取得し,indexの位置に設置
		boolean flg=false;
		if((type|(1<<index))>0){
			flg=true;
		}
		return flg;
	}	public void Serializer(String file){
		File f=new File(file);
		try {
			FileOutputStream fw=new FileOutputStream(f);
			BufferedOutputStream Buf=new BufferedOutputStream(fw);
			Buf.write(ByteInt.tobyte(x1));
//			System.out.printf("x1=%x\n",x1);
			Buf.write(ByteInt.tobyte(x2));
//			System.out.printf("x2=%x\n",x2);
			Buf.write(ByteInt.tobyte(y1));
//			System.out.printf("y1=%x\n",y1);
			Buf.write(ByteInt.tobyte(y2));
//			System.out.printf("y2=%x\n",y2);
			Buf.write(ByteInt.tobyte(type));
//			System.out.printf("type=%x\n",type);
			Buf.flush();
			Buf.close();
		} catch (IOException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}
	}	public void Serializer(File file){
		try {
			FileOutputStream fw=new FileOutputStream(file);
			BufferedOutputStream Buf=new BufferedOutputStream(fw);
			Buf.write(ByteInt.tobyte(x1));
//			System.out.printf("x1=%x\n",x1);
			Buf.write(ByteInt.tobyte(x2));
//			System.out.printf("x2=%x\n",x2);
			Buf.write(ByteInt.tobyte(y1));
//			System.out.printf("y1=%x\n",y1);
			Buf.write(ByteInt.tobyte(y2));
//			System.out.printf("y2=%x\n",y2);
			Buf.write(ByteInt.tobyte(type));
//			System.out.printf("type=%x\n",type);
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
			x1=ByteInt.toint(b);
			Buf.read(b,0,4);
			x2=ByteInt.toint(b);
			Buf.read(b,0,4);
			y1=ByteInt.toint(b);
			Buf.read(b,0,4);
			y2=ByteInt.toint(b);
			Buf.read(b,0,4);
			type=ByteInt.toint(b);
		} catch (IOException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}
	}
}
