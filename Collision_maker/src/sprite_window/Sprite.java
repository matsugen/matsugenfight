package sprite_window;

import java.util.ArrayList;

public class Sprite {
	private ArrayList<Attack> Attack_collision;
	private ArrayList<Hit> Hit_collision;
	private ArrayList<Push> Push_collision;
	private State Status;
	public Sprite(){
		Attack_collision=new ArrayList<Attack>();
		Hit_collision=new ArrayList<Hit>();
		Push_collision=new ArrayList<Push>();
		Status=new State();
	}
	public Attack getAttack(int i){//i番目の攻撃判定を取得
		return Attack_collision.get(i);
	}
	public Hit getHit(int i){//i番目の当たり判定を取得
		return Hit_collision.get(i);
	}
	public Push getPush(int i){//i番目の押し出し判定を取得
		return Push_collision.get(i);
	}
	public State getState(){
		return Status;
	}
}
