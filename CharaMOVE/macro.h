#ifndef MACRO
#define MACRO

//ÇÊÇ≠égÇ¢ÇªÇ§Ç»É}ÉNÉç
#define SAFE_DELETE(x) {\
	delete(x);\
	(x)=0;\
}

#endif