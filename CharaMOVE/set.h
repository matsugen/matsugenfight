#ifndef SET
#define SET
#include"Base.h"
#include"Key.h"

//�悭�g��������

//�悭�g�������ȕϐ�
//�悭�g�������ȃN���X
class Mainloop{
	private:
		int m_tmptime;			//1���[�v�̏����J�n����
		static const char m_Fps=60;     //Fps
		static Mainloop *m_Instance;	//�V���O���g���C���X�^���X
		Mainloop(const Mainloop& r);
		Mainloop& operator=(const Mainloop& r);
		int KeyTime[256];
		bool D_Key[256],U_Key[256];
		Base* state;
		Key* KeyApp;
		Mainloop();
		~Mainloop();                   
	public: 
		bool Seq();		//1���[�v�̏����J�n�������擾�E�V�[�P���X�J��
		bool update();          //�`�ʏ��Ȃǂ̍X�V
		bool print();			//�`��
		bool wait();			//1/m_fps�b�o�߂��Ă��Ȃ��ԑҋ@������
		static Mainloop* create();
		static bool destroy();
		bool Debug();
		bool draw();
};

#endif