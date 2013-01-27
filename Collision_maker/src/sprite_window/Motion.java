package sprite_window;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
/*
 * BufferedInputStreamクラスを用いた文字列の取得・バイナリファイルのロード
 * MotionクラスのSerializeとロード・GUIにおける使用方法をまとめておく。
 */
public class Motion {
	private String filename;//読み込む画像の名前
	private int sizex,sizey;//画像分割のサイズ
	private int num;//スプライトの数
	private ArrayList<Sprite> Sprite_set;
	public Motion(){
		filename="";
		sizex=sizey=0;
		num=0;
		Sprite_set=new ArrayList<Sprite>();
	}
	public Motion(File file,int x,int y,int n){//画像読み込みを行う場合のコンストラクタ
		filename=file.getName();
		sizex=x;
		sizey=y;
		num=n;
		Sprite_set=new ArrayList<Sprite>(num);
	}
	public Motion(File file){//バイナリデータから読み取り
		byte[] b=new byte[1024];
		try {
			FileInputStream fw = new FileInputStream(file);
			BufferedInputStream Buf=new BufferedInputStream(fw);
			Buf.read(b,0,4);
			int n=ByteInt.toint(b);//ファイル名の文字数を取得
		} catch (FileNotFoundException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		} catch (IOException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}
	}
	public int getSize(){
		return num;
	}

}
