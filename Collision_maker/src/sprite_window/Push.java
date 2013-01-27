package sprite_window;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

public class Push {
	private int x1,x2,y1,y2;
	public Push(){
		x1=x2=y1=y2=0;
	}
	public void setRect(int a1,int a2,int b1,int b2){
		x1=a1;
		x2=a2;
		y1=b1;
		y2=b2;
	}
	public int[] getRect(){
		int[] rect=new int[4];
		rect[0]=x1;
		rect[1]=x2;
		rect[2]=y1;
		rect[3]=y2;
		return rect;
	}
	public void Serializer(String file){
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
			Buf.write(ByteInt.tobyte(x1));
//			System.out.printf("x1=%x\n",x1);
			Buf.write(ByteInt.tobyte(x2));
//			System.out.printf("x2=%x\n",x2);
			Buf.write(ByteInt.tobyte(y1));
//			System.out.printf("y1=%x\n",y1);
			Buf.write(ByteInt.tobyte(y2));
//			System.out.printf("y2=%x\n",y2);
			Buf.flush();
			Buf.close();
		} catch (IOException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}

	}
}
