/**
 *
 */
package sprite_window;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

/**
 * @author matsugen
 *
 */
public class Attack {
	private int x1,x2;//luaに導入しやすいよう配列を使わない。
	private int y1,y2;
	private int g_vx,g_vy,a_vx,a_vy;//ヒット時の吹き飛び方向と速度g_は地上ヒット,a_は空中ヒット
	private int type;//攻撃の種類をビット演算でおこなう。打撃1<<0 特殊1<<1 投げ1<<2 ロック1<<3 屈ガード不能1<<4 立ちガード不能1<<5 ダウン1<<6 強制ダウン1<<7
	private int damage;//ダメージ
	private int point;//削減値。この数値で追撃可能かどうかを判定
	private int time;//のけぞり時間
	public Attack(){
		x1=x2=y1=y2=0;
		g_vx=g_vy=a_vx=a_vy=0;
		type=damage=point=time=0;
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
	public void setSpeed(int g_x,int g_y,int a_x,int a_y){
		g_vx=g_x;
		g_vy=g_y;
		a_vx=a_x;
		a_vy=a_y;
	}
	public void setDamage(int d){
		damage=d;
	}
	public void setPoint(int p){
		point=p;
	}
	public void setTime(int t){
		time=t;
	}
	public int[] getRect(){
		int[] rect=new int[4];
		rect[0]=x1;
		rect[1]=x2;
		rect[2]=y1;
		rect[3]=y2;
		return rect;
	}
	public int[] getSpeed(){
		int[] speed=new int[4];
		speed[0]=g_vx;
		speed[1]=g_vy;
		speed[2]=a_vx;
		speed[3]=a_vy;
		return speed;
	}
	public boolean getType(int index){//チェックボックスのbooleanを取得し,indexの位置に設置
		boolean flg=false;
		if((type|(1<<index))>0){
			flg=true;
		}
		return flg;
	}
	public int getDamage(){
		return damage;
	}
	public int getPoint(){
		return point;
	}
	public int getTime(){
		return time;
	}
	public void Serializer(String file){
		File f=new File("test");
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
			Buf.write(ByteInt.tobyte(g_vx));
//			System.out.printf("g_vx=%x\n",g_vx);
			Buf.write(ByteInt.tobyte(g_vy));
//			System.out.printf("g_vy=%x\n",g_vy);
			Buf.write(ByteInt.tobyte(a_vx));
//			System.out.printf("a_vy=%x\n",a_vy);
			Buf.write(ByteInt.tobyte(a_vy));
//			System.out.printf("a_vy=%x\n",a_vy);
			Buf.write(ByteInt.tobyte(type));
//			System.out.printf("type=%x\n",type);
			Buf.write(ByteInt.tobyte(damage));
//			System.out.printf("damage=%x\n",damage);
			Buf.write(ByteInt.tobyte(point));
//			System.out.printf("point=%x\n",point);
			Buf.write(ByteInt.tobyte(time));
//			System.out.printf("time=%x\n",time);
			Buf.flush();
			Buf.close();
		} catch (IOException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}

	}
}
