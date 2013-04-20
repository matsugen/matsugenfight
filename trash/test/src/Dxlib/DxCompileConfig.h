// ----------------------------------------------------------------------------
//
//		�c�w���C�u�����@�R���p�C���R���t�B�O�w�b�_�t�@�C��
//
//				Ver 3.09 
//
// ----------------------------------------------------------------------------

/*
<<����>>
�@�@���̃w�b�_�t�@�C���� #define �̃R�����g�A�E�g��Ԃ�ύX���Ă��A
  �c�w���C�u�������̂̍ăR���p�C�����s��Ȃ��ƌ��ʂ͂���܂���B
*/

// ���d�C���N���[�h�h�~�p�}�N��
#ifndef __DXCOMPILECONFIG_H__
#define __DXCOMPILECONFIG_H__

// �X�^�e�B�b�N���C�u�������������C�u�����@�\�����p��`�� ---------------------

// �C�����C���A�Z���u�����g�p���Ȃ��\�[�X�R�[�h�ŃR���p�C������ꍇ�͈ȉ��̃R�����g�A�E�g���O���Ă�������
//#define DX_NON_INLINE_ASM

// �c�w���C�u�����̃v���O�������當�������ؔr������ꍇ�̓R�����g���O���Ă�������
// (�o�C�i���G�f�B�^�Ŏ��s�t�@�C�����J���Ă��c�w���C�u�������g�p���Ă��邱�Ƃ��������Ȃ�܂�(�悭���ׂ�Γ��R������܂���)
//  ���݂ɁA�G���[�o�͂���؂���Ȃ��Ȃ�܂��̂ŊǗ��l�̑Ή����Ɏx�����������������܂���)
//#define DX_NON_LITERAL_STRING

// ���ׂĂ̊֐����X���b�h�Z�[�t�ɂ���ꍇ�̓R�����g���O���Ă�������
//#define DX_THREAD_SAFE

// �l�b�g���[�N�֘A�̊֐������X���b�h�Z�[�t�ɂ���ꍇ�̓R�����g���O���ĉ�����
#define DX_THREAD_SAFE_NETWORK_ONLY

// �c�w�A�[�J�C�u������Ȃ����͎��̃R�����g���O���Ă�������
// ( �c�w�A�[�J�C�u�𖳌��ɂ���ƁA�c�w�A�[�J�C�u������Ŏg���Ă���֌W�� DX_NON_MODEL �� DX_NON_FILTER ���L���ɂȂ�܂� )
//#define DX_NON_DXA

// ���[�r�[�@�\������Ȃ����͎��̃R�����g���O���Ă�������
//#define DX_NON_MOVIE

// �s�f�`�摜�̓ǂݍ��݋@�\������Ȃ����͎��̃R�����g���O���Ă�������
//#define DX_NON_TGA

// �i�o�d�f�摜�̓ǂ݂��݋@�\������Ȃ����͎��̃R�����g���O���Ă�������
// ��DxUseCLib.lib ���ăR���p�C������K�v������܂�
//#define DX_NON_JPEGREAD

// �o�m�f�摜�̓ǂ݂��݋@�\������Ȃ����͎��̃R�����g���O���Ă�������
// ��DxUseCLib.lib ���ăR���p�C������K�v������܂�
//#define DX_NON_PNGREAD

// GraphFilter �� GraphBlend ���g�p���Ȃ����͎��̃R�����g���O���ĉ�����
//#define DX_NON_FILTER

// �\�t�g�E�G�A�Q�c�`�悪����Ȃ����͎��̃R�����g���O���Ă�������
//#define DX_NON_2DDRAW

// �W�� WAVE �t�@�C���ȊO�̉����t�@�C�����g�p���Ȃ����͎��̃R�����g���O���Ă�������
//#define DX_NON_ACM

// DirectShow ���g�p���� MP3 �t�@�C���̃f�R�[�h���s��Ȃ��ꍇ�͎��̃R�����g���͂����Ă�������
//#define DX_NON_DSHOW_MP3

// DirectShow ���g�p��������t�@�C���̃f�R�[�h���s��Ȃ��ꍇ�͎��̃R�����g���͂����Ă�������
//#define DX_NON_DSHOW_MOVIE

// �L�[�{�[�h�̊�{�I�ȓ��͋@�\�ȊO�͂���Ȃ����͎��̃R�����g���O���Ă�������
//#define DX_NON_KEYEX

// ��������͋@�\�͂���Ȃ����͎��̃R�����g���O���ĉ�����
//#define DX_NON_INPUTSTRING

// �ʐM�@�\������Ȃ����͎��̃R�����g���O���Ă�������
//#define DX_NON_NETWORK

// �}�X�N�@�\������Ȃ����͎��̃R�����g���O���Ă�������
//#define DX_NON_MASK

// �n���� �u���������� �f�[�^���g�p���Ȃ����͎��̃R�����g���͂����Ă�������
// ��DxUseCLib.lib ���ăR���p�C������K�v������܂�
//#define DX_NON_OGGVORBIS

// �n���� �s���������� �f�[�^���g�p���Ȃ����͎��̃R�����g���͂����Ă�������
// ��DxUseCLib.lib ���ăR���p�C������K�v������܂�
//#define DX_NON_OGGTHEORA

// ����������� Mersenne Twister ���g�p����Ȃ��ꍇ�͈ȉ��̃R�����g���O���ĉ�����
// ��DxUseCLib.lib ���ăR���p�C������K�v������܂�
//#define DX_NON_MERSENNE_TWISTER

// �c�w���C�u�������̊m�ۃ������̃_���v�@�\��L���ɂ���ꍇ�͎��̃R�����g���O���Ă�������
#define DX_USE_DXLIB_MEM_DUMP

// ���f���f�[�^�������@�\���g�p���Ȃ����͎��̃R�����g���O���Ă�������
//#define DX_NON_MODEL

// Bullet Physics �������N���Ȃ��ꍇ�͎��̃R�����g���O���Ă�������
// ��DxUseCLib.lib ���ăR���p�C������K�v������܂�
//#define DX_NON_BULLET_PHYSICS

// �e�a�w�t�@�C����ǂݍ��ދ@�\���g�p������͎��̃R�����g���O���Ă�������( �g�p�ɂ� FBX SDK �̃Z�b�g�A�b�v���K�v�ł� )
//#define DX_LOAD_FBX_MODEL

// �r�[�v���@�\������Ȃ����͎��̃R�����g���O���Ă�������
#define DX_NON_BEEP

// �^�X�N�X�C�b�`���n�e�e�ɂ���@�\������Ȃ����͎��̃R�����g���O���Ă�������
// ( �^�X�N�X�C�b�`�n�e�e�@�\�͎g�p�s�ł� )
//#define DX_NON_STOPTASKSWITCH

// ���O�o�͂��s��Ȃ��ꍇ�͎��̃R�����g���O���ĉ�����
//#define DX_NON_LOG

// printfDx �𖳌��ɂ���ꍇ�͎��̃R�����g���O���ĉ�����
//#define DX_NON_PRINTF_DX

// �񓯊��ǂݍ��݂𖳌��ɂ���ꍇ�͎��̃R�����g���O���ĉ�����
//#define DX_NON_ASYNCLOAD

// �t�@�C���ۑ��@�\�𖳌��ɂ���ꍇ�͎��̃R�����g���O���ĉ�����
//#define DX_NON_SAVEFUNCTION

// �\�t�g�E�F�A�ň����C���[�W�𖳌��ɂ���ꍇ�͎��̃R�����g���O���ĉ�����
//#define DX_NON_SOFTIMAGE

// �t�H���g�`��@�\�𖳌��ɂ���ꍇ�͎��̃R�����g���O���ĉ�����
//#define DX_NON_FONT

// �T�E���h�Đ��@�\( �\�t�g�E�G�A�T�E���h�AMIDI�܂� )�𖳌��ɂ���ꍇ�͎��̃R�����g���O���ĉ�����
//#define DX_NON_SOUND

// ���͋@�\�𖳌��ɂ���ꍇ�͎��̃R�����g���O���ĉ�����
//#define DX_NON_INPUT

// �y�ʃo�[�W�����̂c�w���C�u�����𐶐�����ꍇ�͎��̃R�����g���O���Ă�������
//#define DX_LIB_LITEVER

#ifdef DX_LIB_LITEVER
#define DX_NON_ACM
#define DX_NON_2DDRAW
#define DX_NON_MOVIE
#define DX_NON_KEYEX
#define DX_NON_NETWORK
#define DX_NON_MASK
#define DX_NON_JPEGREAD
#define DX_NON_PNGREAD
#define DX_NON_BEEP
#define DX_NON_OGGVORBIS
#define DX_NON_MODEL
#endif

#ifdef DX_NON_INPUTSTRING
	#ifndef DX_NON_KEYEX
		#define DX_NON_KEYEX
	#endif
#endif

#ifdef DX_NON_MOVIE
	#ifndef DX_NON_OGGTHEORA
		#define DX_NON_OGGTHEORA
	#endif
#endif


#ifdef DX_NON_DXA
	#ifndef DX_NON_MODEL
		#define DX_NON_MODEL
	#endif
	#ifndef DX_NON_FILTER
		#define DX_NON_FILTER
	#endif
#endif

#ifdef DX_NON_INPUT
	#ifndef DX_NON_KEYEX
		#define DX_NON_KEYEX
	#endif
#endif

#ifdef DX_NON_FONT
	#ifndef DX_NON_PRINTF_DX
		#define DX_NON_PRINTF_DX
	#endif
	#ifndef DX_NON_KEYEX
		#define DX_NON_KEYEX
	#endif
#endif

#ifdef DX_NON_OGGVORBIS
	#ifndef DX_NON_OGGTHEORA
		#define DX_NON_OGGTHEORA
	#endif
#endif

#ifdef _WIN64
	#ifndef DX_NON_INLINE_ASM
		#define DX_NON_INLINE_ASM
	#endif
#endif

#if !defined( __ANDROID )
#define __WINDOWS__
#endif

#ifdef __ANDROID
#ifndef DX_NON_ACM
#define DX_NON_ACM
#undef DX_THREAD_SAFE
#undef DX_THREAD_SAFE_NETWORK_ONLY
#endif
#endif

#include "DxDataType.h"

#endif // __DXCOMPILECONFIG_H__
