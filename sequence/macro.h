#ifndef MACRO
#define MACRO

//よく使いそうなマクロ
#define SAFE_DELETE(x) {\
	delete(x);\
	(x)=0;\
}

#endif