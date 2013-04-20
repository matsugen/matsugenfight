#ifndef COMMAND
#define COMMAND

enum Menu {	HADO,//236
		TATSU,//214
		YOGA,//4(1)2(3)6
		R_YOGA,//6(3)2(1)4
		SYORYU,//623
		R_SYORYU,//421
		SINKU,//236236
		R_SINKU,//214214
		JIGOKU,//6(3)2(1)46(3)2(1)4
		R_JIGOKU,//4(1)2(3)64(1)2(3)6
};


int Command(int Key[]);
#endif
