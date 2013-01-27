package sprite_window;

import java.nio.ByteBuffer;

public class ByteInt {
	static int toint(byte[] b){
		return ByteBuffer.wrap(b).asIntBuffer().get();
	}
static byte[] tobyte(int i){
	byte[] b=new byte[4];
	b[3]=(byte)(0x000000ff&(i));
	b[2]=(byte)(0x000000ff&(i>>>8));
	b[1]=(byte)(0x000000ff&(i>>>16));
	b[0]=(byte)(0x000000ff&(i>>>24));
	return b;
	}
}
