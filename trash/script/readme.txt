*_Collision:
	�e����̃N���X���B
	"�N���X��()"�ŃC���X�^���X�������ɕ������p���邱�ƂŃt�@�C�����Ńp�����[�^��������
	�e�N���X�ɂ͂��ꂼ��̗v�f���擾����Get�֐������݂���
	�ȉ�*_Collision�̃w�b�_�t�@�C����public�����𔲐�
	/*collision.h*/
	/*
	 * �U������N���X
	 */
	class Attack_Collision{
		Attack_Collision();
		Attack_Collision(FILE* file);
		~Attack_Collision();
		int GetRect(int* a1,int* a2,int* b1,int* b2);//�����`�̎擾
		int GetType();//�U���^�C�v�̎擾
		int GetDamage();//�_���[�W�̎擾
		int AirHit(int* dx,int* dy,int* p);//�󒆃q�b�g���̐�����ѕ����A�팸�l�̎擾
		int GroundHit(int* dx,int* dy,int* t,int* p);//�n��q�b�g���̐�����ѕ����Ƃ̂����莞�ԁBlua����dy>0�̂Ƃ��͂̂����莞�Ԃ��l���Ȃ�

	};

	/*
	 * �����o������N���X
	 */
	class Push_Collision{
		Push_Collision();
		Push_Collision(FILE *file);
		~Push_Collision();
		int GetRect(int *a1,int *a2,int *b1,int *b2);//�����`�̎擾
		int GetAxis();//�L�������擾
	};
	/*
	 * �H�炢����N���X
	 */
	class Hit_Collision{
		Hit_Collision();
		Hit_Collision(FILE* file);
		~Hit_Collision();
		int GetRect(int *a1,int *a2,int *b1,int *b2);//�����`�̎擾
	};

	/*collision.h*/
	
/*�ȉ��G���Ȑ���*/
	
*_miss�͎��s��B��w�̂��ߎc���B
test.lua�Ɏ�ȓ�����L�q���Ă���
����͂��ׂẴp�����[�^��0�ŏ���������Attack_Collision�N���X��Attack�ɃC���X�^���X�����Atype���擾�E�\�����Ă���
���ɁA����ɐM��(���݂͏��NONE)�ƃL�[���͂𐔒l���������̂�\�����A�L�[�{�[�h��"Q"�L�[�Ńp���`���[�V�����A�����L�[�ō��E�ɂ݈̂ړ��\�B�܂��A�����I�ɐԂ��������̋�`��\�����Ă���B�f�o�b�O�p
����͒ǉ������eCollision�N���X��p���ċZ�Ȃǂ̃��[�V�������t�@�C���ǂݍ��݂����Ŏ��s�ł���悤�ɂ���
�Ȍ����Ă�����������
lua�̘A�z�z��@�\��p���āA�ǂݍ��񂾃t�@�C���̊g���q��`�����������Z�Q�Ƃ̃L�[�Ƃ��ėp����
�������邱�ƂŁA�����炭�֐��𑽂��g�킸�A�A�z�z��𑖍����邾���ŋZ�����s�ł���Ǝv����B
�ǂݍ��񂾃t�@�C���̊g���q��������������A�z�z��̃L�[�Ƃ���ɂ͂ǂ����邩�B
�܂��A�Z�̐M�����󂯎�����ꍇ�ʂ̓���Ɉڍs����ɂ͂ǂ����邩�B�ۑ�͎c��B

2013/1/14
	-"chara"�t�H���_��ǉ��B�ȍ~���̃t�H���_�ɃL�����N�^�[�̃N���X������B
	-*_Collision�N���X��Hit,Push,Attack�ƃN���X����ύX�B����ɔ����Alua���ň����Ƃ���collision�e�[�u���̗̈���̃N���X�Ƃ��Ĉ����Ă���(�g�p����collision.Push()�ȂǂƂ��ăC���X�^���X������)
	-���W(200,0)�ɓ����Ȃ��_�l�Ԃ�\���Bchara/chara.lua�ɂ���"Chara"�N���X��p���Ĕ���ƃX�v���C�g��\�����Ă���B�\����	����Attack�݂̂ŁA�o�C�i���t�@�C��"test"��ǂݍ��ނ��Ƃō��W�Ȃǂ��擾���Ă���B
	����̉ۑ�
		-�o�C�i���t�@�C���𒼐ڂ�����͖̂ʓ|�Ȃ̂ŁAGUI�c�[�����쐬����K�v������B