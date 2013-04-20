// -------------------------------------------------------------------------------
// 
// 		�c�w���C�u����		Windows�p�f�[�^�^�C�v��`�w�b�_�t�@�C��
// 
// 				Ver 3.09 
// 
// -------------------------------------------------------------------------------

#ifndef __DXDATATYPEWIN_H__
#define __DXDATATYPEWIN_H__

// �C���N���[�h��-----------------------------------------------------------------
#include "DxCompileConfig.h"
#include <tchar.h>
#include <windows.h>
#include <commctrl.h>

namespace DxLib
{

// �}�N����`�� ------------------------------------------------------------------

// ���ˑ��L�[���[�h�Ȃ�
#define FASTCALL	__fastcall

// DirectX�^
#define DX_DIRECT3DDEVICE9					class D_IDirect3DDevice9
#define DX_DIRECT3DSURFACE9					class D_IDirect3DSurface9

// �c�����������h���������̃o�[�W�����ݒ�
#define DIRECTINPUT_VERSION 0x700

#ifndef DWORD_PTR
#ifdef _WIN64
#define LONG_PTR	ULONGLONG
#else
#define DWORD_PTR	DWORD
#endif
#endif

#ifndef LONG_PTR
#ifdef _WIN64
#define LONG_PTR	__int64
#else
#define LONG_PTR	int
#endif
#endif

// �\���̒�`��-------------------------------------------------------------------

// �e�[�u��-----------------------------------------------------------------------

// �������ϐ��錾��-------------------------------------------------------------

// �֐��v���g�^�C�v�錾-----------------------------------------------------------

}

#endif // __DXDATATYPEWIN_H__
