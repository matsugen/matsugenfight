#ifndef MACRO
#define MACRO

//�悭�g�������ȃ}�N��
#define SAFE_DELETE(x) {\
	delete(x);\
	(x)=0;\
}

#endif