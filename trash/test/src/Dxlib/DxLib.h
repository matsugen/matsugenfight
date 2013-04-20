// -------------------------------------------------------------------------------
// 
// 		�c�w���C�u����		�w�b�_�t�@�C��
// 
// 				Ver 3.09 
// 
// -------------------------------------------------------------------------------

#ifndef __DXLIB
#define __DXLIB

#include "DxCompileConfig.h"
#include "DxDirectX.h"

// �c�w���C�u�����̃o�[�W����
#define DXLIB_VERSION 0x3090
#define DXLIB_VERSION_STR _T( "3.09 " )

// �ݒ� -----------------------------------------------------------------------

// �c�w���C�u�����ɕK�v�� lib �t�@�C�����A�v���W�F�N�g�̃J�����g�t�H���_��
// �R���p�C���̃f�t�H���g LIB �p�X�ɐݒ肹���Ɏg�p�����ꍇ�͈ȉ���
// �R�����g���O���Ă�������
//#define DX_LIB_NOT_DEFAULTPATH

#ifndef __DX_MAKE

// �`��֘A�̊֐�����؎g�p����Ȃ��ꍇ�͈ȉ��̃R�����g���O���ĉ�����
//#define DX_NOTUSE_DRAWFUNCTION

#endif // __DX_MAKE

// ���C�u���������N��`--------------------------------------------------------

#if !defined( __ANDROID )

#ifndef __DX_MAKE
	#ifndef DX_LIB_NOT_DEFAULTPATH
		#ifndef DX_SRC_COMPILE
			#ifdef _MSC_VER
				#ifdef _WIN64
					#ifdef _DEBUG
						#pragma comment( lib, "DxDrawFunc_x64_d.lib"		)		//  �`�敔���̔����o��
						#ifdef UNICODE
							#pragma comment( lib, "DxLibW_x64_d.lib"		)		//  �c�w���C�u�����g�p�w��
							#pragma comment( lib, "DxUseCLibW_x64_d.lib"	)		//  �W���b���C�u�������g�p���镔���� lib �t�@�C���̎g�p�w��
						#else
							#pragma comment( lib, "DxLib_x64_d.lib"			)		//  �c�w���C�u�����g�p�w��
							#pragma comment( lib, "DxUseCLib_x64_d.lib"		)		//  �W���b���C�u�������g�p���镔���� lib �t�@�C���̎g�p�w��
						#endif
					#else
						#pragma comment( lib, "DxDrawFunc_x64.lib"			)		//  �`�敔���̔����o��
						#ifdef UNICODE
							#pragma comment( lib, "DxLibW_x64.lib"			)		//  �c�w���C�u�����g�p�w��
							#pragma comment( lib, "DxUseCLibW_x64.lib"		)		//  �W���b���C�u�������g�p���镔���� lib �t�@�C���̎g�p�w��
						#else
							#pragma comment( lib, "DxLib_x64.lib"			)		//  �c�w���C�u�����g�p�w��
							#pragma comment( lib, "DxUseCLib_x64.lib"		)		//  �W���b���C�u�������g�p���镔���� lib �t�@�C���̎g�p�w��
						#endif
					#endif
				#else
					#ifdef _DEBUG
						#pragma comment( lib, "DxDrawFunc_d.lib"		)		//  �`�敔���̔����o��
						#ifdef UNICODE
							#pragma comment( lib, "DxLibW_d.lib"		)		//  �c�w���C�u�����g�p�w��
							#pragma comment( lib, "DxUseCLibW_d.lib"	)		//  �W���b���C�u�������g�p���镔���� lib �t�@�C���̎g�p�w��
						#else
							#pragma comment( lib, "DxLib_d.lib"			)		//  �c�w���C�u�����g�p�w��
							#pragma comment( lib, "DxUseCLib_d.lib"		)		//  �W���b���C�u�������g�p���镔���� lib �t�@�C���̎g�p�w��
						#endif
					#else
						#pragma comment( lib, "DxDrawFunc.lib"			)		//  �`�敔���̔����o��
						#ifdef UNICODE
							#pragma comment( lib, "DxLibW.lib"			)		//  �c�w���C�u�����g�p�w��
							#pragma comment( lib, "DxUseCLibW.lib"		)		//  �W���b���C�u�������g�p���镔���� lib �t�@�C���̎g�p�w��
						#else
							#pragma comment( lib, "DxLib.lib"			)		//  �c�w���C�u�����g�p�w��
							#pragma comment( lib, "DxUseCLib.lib"		)		//  �W���b���C�u�������g�p���镔���� lib �t�@�C���̎g�p�w��
						#endif
					#endif
				#endif
			#else
				#pragma comment( lib, "DxDrawFunc.lib"		)			//  �`�敔���̔����o��
				#ifdef UNICODE
					#pragma comment( lib, "DxLibW.lib"		)			//  �c�w���C�u�����g�p�w��
					#pragma comment( lib, "DxUseCLibW.lib"	)			//  �W���b���C�u�������g�p���镔���� lib �t�@�C���̎g�p�w��
				#else
					#pragma comment( lib, "DxLib.lib"		)			//  �c�w���C�u�����g�p�w��
					#pragma comment( lib, "DxUseCLib.lib"	)			//  �W���b���C�u�������g�p���镔���� lib �t�@�C���̎g�p�w��
				#endif
			#endif

			#ifdef _DEBUG
				#pragma comment( linker, "/NODEFAULTLIB:libcmt.lib" )
				#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
				#pragma comment( linker, "/NODEFAULTLIB:libcd.lib" )
	//			#pragma comment( linker, "/NODEFAULTLIB:msvcrt.lib" )
	//			#pragma comment( linker, "/NODEFAULTLIB:msvcrtd.lib" )
			#else
				#pragma comment( linker, "/NODEFAULTLIB:libcmtd.lib" )
				#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
				#pragma comment( linker, "/NODEFAULTLIB:libcd.lib" )
	//			#pragma comment( linker, "/NODEFAULTLIB:msvcrt.lib" )
	//			#pragma comment( linker, "/NODEFAULTLIB:msvcrtd.lib" )
			#endif
		#endif
		//#pragma comment( lib, "libcmt.lib"		)				//  C�W���}���`�X���b�h�Ή����C�u����
		#pragma comment( lib, "kernel32.lib"		)			//  Win32�J�[�l�����C�u����
		//#pragma comment( lib, "comctl32.lib"		)			//�@Win32API���C�u����
		#pragma comment( lib, "user32.lib"		)				//  Win32API���C�u����
		#pragma comment( lib, "gdi32.lib"		)				//  Win32API���C�u����
		#pragma comment( lib, "advapi32.lib"		)			//  Win32API���C�u����
		//#pragma comment( lib, "ole32.lib"		)				//  Win32API���C�u����
		#pragma comment( lib, "shell32.lib"		)				//  �}���`���f�B�A���C�u����
		//#pragma comment( lib, "winmm.lib"		)				//  �}���`���f�B�A���C�u����
		#ifndef DX_NON_MOVIE
			//#pragma comment( lib, "Strmiids.lib" )			//�@DirectShow���C�u����
		#endif
		#ifndef DX_NON_NETWORK
			//#pragma comment( lib, "wsock32.lib" )				//  WinSockets���C�u����
		#endif
		#ifndef DX_NON_KEYEX
			//#pragma comment( lib, "imm32.lib" )					// �h�l�d����p���C�u����
		#endif
		#ifndef DX_NON_ACM
			//#pragma comment( lib, "msacm32.lib" )				// �`�b�l����p���C�u���� 
		#endif
		#ifndef DX_NON_BULLET_PHYSICS
			#ifdef _MSC_VER
				#ifdef DX_USE_VC8_BULLET_PHYSICS_LIB
					#ifdef _WIN64
						#ifdef _DEBUG
							#pragma comment( lib, "libbulletcollision_vc8_x64_d.lib" )	// Visual C++ 8.0 �ŃR���p�C������ Bullet Physics ���C�u���� 
							#pragma comment( lib, "libbulletdynamics_vc8_x64_d.lib" )
							#pragma comment( lib, "libbulletmath_vc8_x64_d.lib" )
						#else
							#pragma comment( lib, "libbulletcollision_vc8_x64.lib" )	// Visual C++ 8.0 �ŃR���p�C������ Bullet Physics ���C�u���� 
							#pragma comment( lib, "libbulletdynamics_vc8_x64.lib" )
							#pragma comment( lib, "libbulletmath_vc8_x64.lib" )
						#endif
					#else
						#ifdef _DEBUG
							#pragma comment( lib, "libbulletcollision_vc8_d.lib" )	// Visual C++ 8.0 �ŃR���p�C������ Bullet Physics ���C�u���� 
							#pragma comment( lib, "libbulletdynamics_vc8_d.lib" )
							#pragma comment( lib, "libbulletmath_vc8_d.lib" )
						#else
							#pragma comment( lib, "libbulletcollision_vc8.lib" )	// Visual C++ 8.0 �ŃR���p�C������ Bullet Physics ���C�u���� 
							#pragma comment( lib, "libbulletdynamics_vc8.lib" )
							#pragma comment( lib, "libbulletmath_vc8.lib" )
						#endif
					#endif
				#else
					#ifdef _WIN64
						#ifdef _DEBUG
							#pragma comment( lib, "libbulletcollision_vc8_x64_d.lib" )	// Visual C++ 8.0 �ŃR���p�C������ Bullet Physics ���C�u���� 
							#pragma comment( lib, "libbulletdynamics_vc8_x64_d.lib" )
							#pragma comment( lib, "libbulletmath_vc8_x64_d.lib" )
						#else
							#pragma comment( lib, "libbulletcollision_vc8_x64.lib" )	// Visual C++ 8.0 �ŃR���p�C������ Bullet Physics ���C�u���� 
							#pragma comment( lib, "libbulletdynamics_vc8_x64.lib" )
							#pragma comment( lib, "libbulletmath_vc8_x64.lib" )
						#endif
					#else
						#ifdef _DEBUG
							#pragma comment( lib, "libbulletcollision_vc6_d.lib" )	// Visual C++ 6.0 �ŃR���p�C������ Bullet Physics ���C�u���� 
							#pragma comment( lib, "libbulletdynamics_vc6_d.lib" )
							#pragma comment( lib, "libbulletmath_vc6_d.lib" )
						#else
							#pragma comment( lib, "libbulletcollision_vc6.lib" )	// Visual C++ 6.0 �ŃR���p�C������ Bullet Physics ���C�u���� 
							#pragma comment( lib, "libbulletdynamics_vc6.lib" )
							#pragma comment( lib, "libbulletmath_vc6.lib" )
						#endif
					#endif
				#endif
			#else
				#pragma comment( lib, "libbulletcollision.lib" )	// Bullet Physics ���C�u���� 
				#pragma comment( lib, "libbulletdynamics.lib" )
				#pragma comment( lib, "libbulletmath.lib" )
			#endif
		#endif
		#ifndef DX_NON_PNGREAD
			#ifdef _MSC_VER
				#ifdef _WIN64
					#ifdef _DEBUG
						#pragma comment( lib, "libpng_x64_d.lib" )		// �o�m�f���C�u����
						#pragma comment( lib, "zlib_x64_d.lib" )
					#else
						#pragma comment( lib, "libpng_x64.lib" )		// �o�m�f���C�u����
						#pragma comment( lib, "zlib_x64.lib" )
					#endif
				#else
					#ifdef _DEBUG
						#pragma comment( lib, "libpng_d.lib" )			// �o�m�f���C�u����
						#pragma comment( lib, "zlib_d.lib" )
					#else
						#pragma comment( lib, "libpng.lib" )			// �o�m�f���C�u����
						#pragma comment( lib, "zlib.lib" )
					#endif
				#endif
			#else
				#pragma comment( lib, "libpng.lib" )			// �o�m�f���C�u����
				#pragma comment( lib, "zlib.lib" )
			#endif
		#endif
		#ifndef DX_NON_JPEGREAD
			#ifdef _MSC_VER
				#ifdef _WIN64
					#ifdef _DEBUG
						#pragma comment( lib, "libjpeg_x64_d.lib" )		// �i�o�d�f���C�u����
					#else
						#pragma comment( lib, "libjpeg_x64.lib" )		// �i�o�d�f���C�u����
					#endif
				#else
					#ifdef _DEBUG
						#pragma comment( lib, "libjpeg_d.lib" )			// �i�o�d�f���C�u����
					#else
						#pragma comment( lib, "libjpeg.lib" )			// �i�o�d�f���C�u����
					#endif
				#endif
			#else
				#pragma comment( lib, "libjpeg.lib" )			// �i�o�d�f���C�u����
			#endif
		#endif
		#ifndef DX_NON_OGGVORBIS								// �n�����u�������������C�u����
			#ifdef _MSC_VER
				#ifdef _WIN64
					#ifdef _DEBUG
						#pragma comment( lib, "ogg_static_x64_d.lib" )
						#pragma comment( lib, "vorbis_static_x64_d.lib" )
						#pragma comment( lib, "vorbisfile_static_x64_d.lib" )
					#else
						#pragma comment( lib, "ogg_static_x64.lib" )
						#pragma comment( lib, "vorbis_static_x64.lib" )
						#pragma comment( lib, "vorbisfile_static_x64.lib" )
					#endif
				#else
					#ifdef _DEBUG
						#pragma comment( lib, "ogg_static_d.lib" )
						#pragma comment( lib, "vorbis_static_d.lib" )
						#pragma comment( lib, "vorbisfile_static_d.lib" )
					#else
						#pragma comment( lib, "ogg_static.lib" )
						#pragma comment( lib, "vorbis_static.lib" )
						#pragma comment( lib, "vorbisfile_static.lib" )
					#endif
				#endif
			#else
				#pragma comment( lib, "ogg_static.lib" )
				#pragma comment( lib, "vorbis_static.lib" )
				#pragma comment( lib, "vorbisfile_static.lib" )
			#endif
		#endif
		#ifndef DX_NON_OGGTHEORA								// �n�����s�������������C�u����
			#ifdef _MSC_VER
				#ifdef _WIN64
					#ifdef _DEBUG
						#pragma comment( lib, "ogg_static_x64_d.lib" )
						#pragma comment( lib, "vorbis_static_x64_d.lib" )
						#pragma comment( lib, "vorbisfile_static_x64_d.lib" )

						#pragma comment( lib, "libtheora_static_x64_d.lib" )
					#else
						#pragma comment( lib, "ogg_static_x64.lib" )
						#pragma comment( lib, "vorbis_static_x64.lib" )
						#pragma comment( lib, "vorbisfile_static_x64.lib" )

						#pragma comment( lib, "libtheora_static_x64.lib" )
					#endif
				#else
					#ifdef _DEBUG
						#pragma comment( lib, "ogg_static_d.lib" )
						#pragma comment( lib, "vorbis_static_d.lib" )
						#pragma comment( lib, "vorbisfile_static_d.lib" )

						#pragma comment( lib, "libtheora_static_d.lib" )
					#else
						#pragma comment( lib, "ogg_static.lib" )
						#pragma comment( lib, "vorbis_static.lib" )
						#pragma comment( lib, "vorbisfile_static.lib" )

						#pragma comment( lib, "libtheora_static.lib" )
					#endif
				#endif
			#else
				#pragma comment( lib, "ogg_static.lib" )
				#pragma comment( lib, "vorbis_static.lib" )
				#pragma comment( lib, "vorbisfile_static.lib" )

				#pragma comment( lib, "libtheora_static.lib" )
			#endif
		#endif
	#endif
#endif

#endif // !defined( __ANDROID )

// ��`---------------------------------------------------------------------------

// ��
#define DX_PI										(3.1415926535897932384626433832795 )
#define DX_PI_F										(3.1415926535897932384626433832795f)
#define DX_TWO_PI									(3.1415926535897932384626433832795  * 2.0 )
#define DX_TWO_PI_F									(3.1415926535897932384626433832795f * 2.0f)

#define DX_CHAR										char

#define DX_DEFINE_START

#define MAX_IMAGE_NUM								(32768)				// �����Ɏ��Ă�O���t�B�b�N�n���h���̍ő吔( �n���h���G���[�`�F�b�N�̃}�X�N�Ɏg�p���Ă���̂� 65536 �ȉ��� 2 �ׂ̂���ɂ��ĉ����� )
#define MAX_2DSURFACE_NUM							(32768)				// �Q�c�T�[�t�F�X�f�[�^�̍ő吔( �n���h���G���[�`�F�b�N�̃}�X�N�Ɏg�p���Ă���̂� 65536 �ȉ��� 2 �ׂ̂���ɂ��ĉ����� )
#define MAX_3DSURFACE_NUM							(65536)				// �R�c�T�[�t�F�X�f�[�^�̍ő吔( �n���h���G���[�`�F�b�N�̃}�X�N�Ɏg�p���Ă���̂� 65536 �ȉ��� 2 �ׂ̂���ɂ��ĉ����� )
#define MAX_IMAGE_DIVNUM							(64)				// �摜�����̍ő吔
#define MAX_SURFACE_NUM								(65536)				// �T�[�t�F�X�f�[�^�̍ő吔
#define MAX_SOFTIMAGE_NUM							(8192)				// �����Ɏ��Ă�\�t�g�C���[�W�n���h���̍ő吔( �n���h���G���[�`�F�b�N�̃}�X�N�Ɏg�p���Ă���̂� 65536 �ȉ��� 2 �ׂ̂���ɂ��ĉ����� )

#define MAX_SOUND_NUM								(32768)				// �����Ɏ��Ă�T�E���h�n���h���̍ő吔
#define MAX_SOFTSOUND_NUM							(8192)				// �����Ɏ��Ă�\�t�g�E�G�A�T�E���h�n���h���̍ő吔
#define MAX_MUSIC_NUM								(256)				// �����Ɏ��Ă�~���[�W�b�N�n���h���̍ő吔
#define MAX_MOVIE_NUM								(100)				// �����Ɏ��Ă郀�[�r�[�n���h���̍ő吔
#define MAX_MASK_NUM								(512)				// �����Ɏ��Ă�}�X�N�n���h���̍ő吔
#define MAX_FONT_NUM								(40)				// �����Ɏ��Ă�t�H���g�n���h���̍ő吔
#define MAX_INPUT_NUM								(256)				// �����Ɏ��Ă镶������̓n���h���̍ő吔
#define MAX_SOCKET_NUM								(8192)				// �����Ɏ��Ă�ʐM�n���h���̍ő吔
#define MAX_LIGHT_NUM								(4096)				// �����Ɏ��Ă郉�C�g�n���h���̍ő吔
#define MAX_SHADER_NUM								(4096)				// �����Ɏ��Ă�V�F�[�_�[�n���h���̍ő吔
#define MAX_MODEL_BASE_NUM							(32768)				// �����Ɏ��Ă�R�c���f����{�f�[�^�n���h���̍ő吔
#define MAX_MODEL_NUM								(32768)				// �����Ɏ��Ă�R�c���f���f�[�^�n���h���̍ő吔
#define MAX_VERTEX_BUFFER_NUM						(16384)				// �����Ɏ��Ă钸�_�o�b�t�@�n���h���̍ő吔
#define MAX_INDEX_BUFFER_NUM						(16384)				// �����Ɏ��Ă�C���f�b�N�X�o�b�t�@�̍ő吔
#define MAX_FILE_NUM								(32768)				// �����Ɏ��Ă�t�@�C���n���h���̍ő吔

#define MAX_JOYPAD_NUM								(16)				// �W���C�p�b�h�̍ő吔
#define MAX_EVENTPROCESS_NUM						(5)					// ��x�ɏ�������C�x���g�̍ő吔

#define DEFAULT_SCREEN_SIZE_X						(640)				// �f�t�H���g�̉�ʂ̕�
#define DEFAULT_SCREEN_SIZE_Y						(480)				// �f�t�H���g�̉�ʂ̍���
#define DEFAULT_COLOR_BITDEPTH						(16)				// �f�t�H���g�̐F�r�b�g�[�x

#define DEFAULT_FOV									(60.0F * 3.1415926535897932384626433832795F / 180.0F)	// �f�t�H���g�̎���p
#define DEFAULT_TAN_FOV_HALF						(0.57735026918962576450914878050196F) // tan( FOV * 0.5 )
#define DEFAULT_NEAR								(0.0F)				// NEAR�N���b�v��
#define DEFAULT_FAR									(20000.0F)			// FAR�N���b�v��

#define DEFAULT_FONT_SIZE							(16)				// �t�H���g�̃f�t�H���g�̃T�C�Y
#define DEFAULT_FONT_THINCK							(6)					// �t�H���g�̃f�t�H���g�̑���
#define DEFAULT_FONT_TYPE							( DX_FONTTYPE_NORMAL )	// �t�H���g�̃f�t�H���g�̌`��
#define DEFAULT_FONT_EDGESIZE						(1)					// �t�H���g�̃f�t�H���g�̑���

#define FONT_CACHE_MAXNUM							(2024)				// �t�H���g�L���b�V���Ɋi�[�ł���ő啶����
#define FONT_CACHE_MEMORYSIZE						(0x50000)			// �t�H���g�L���b�V���̍ő�e��
#define FONT_CACHE_MAX_YLENGTH						(0x4000)			// �t�H���g�L���b�V���T�[�t�F�X�̍ő�c��

#define MAX_USERIMAGEREAD_FUNCNUM					(10)				// ���[�U�[���o�^�ł���O���t�B�b�N���[�h�֐��̍ő吔


// �n���h���̓���
#define DX_HANDLEINDEX_MASK							(0x0000ffff)		// �n���h���z��C���f�b�N�X�}�X�N
#define DX_HANDLECHECKBIT_MASK						(0x03ff0000)		// �n���h���C���f�b�N�X�G���[�`�F�b�N�p�}�X�N
#define DX_HANDLECHECKBIT_ADDRESS					(16)				// �n���h���C���f�b�N�X�G���[�`�F�b�N�p�}�X�N�̊J�n�A�h���X
#define DX_HANDLETYPE_MASK							(0x7c000000)		// �n���h���^�C�v�}�X�N
#define DX_HANDLEERROR_MASK							(0x80000000)		// �G���[�`�F�b�N�}�X�N( �O�ł͂Ȃ�������G���[ )
#define DX_HANDLEERROR_OR_TYPE_MASK					(0xf8000000)		// DX_HANDLETYPE_MASK �� DX_HANDLEERROR_MASK ���|�����킹������

// �n���h���^�C�v��`
#define DX_HANDLETYPE_GRAPH							(0x04000000)		// �O���t�B�b�N�n���h��
#define DX_HANDLETYPE_SOFTIMAGE						(0x08000000)		// �\�t�g�E�G�A�ň����C���[�W�n���h��
#define DX_HANDLETYPE_SOUND							(0x0c000000)		// �T�E���h�n���h��
#define DX_HANDLETYPE_SOFTSOUND						(0x10000000)		// �\�t�g�T�E���h�n���h��
#define DX_HANDLETYPE_MUSIC							(0x14000000)		// �~���[�W�b�N�n���h��
#define DX_HANDLETYPE_MOVIE							(0x18000000)		// ���[�r�[�n���h��
#define DX_HANDLETYPE_GMASK							(0x1c000000)		// �}�X�N�n���h��
#define DX_HANDLETYPE_FONT							(0x20000000)		// �t�H���g�n���h��
#define DX_HANDLETYPE_KEYINPUT						(0x24000000)		// ��������̓n���h��
#define DX_HANDLETYPE_NETWORK						(0x28000000)		// �l�b�g���[�N�n���h��
#define DX_HANDLETYPE_LIGHT							(0x2c000000)		// ���C�g
#define DX_HANDLETYPE_SHADER						(0x30000000)		// �V�F�[�_�[�n���h��
#define DX_HANDLETYPE_MODEL_BASE					(0x34000000)		// �R�c���f����{�f�[�^
#define DX_HANDLETYPE_MODEL							(0x38000000)		// �R�c���f��
#define DX_HANDLETYPE_VERTEX_BUFFER					(0x3c000000)		// ���_�o�b�t�@�n���h��
#define DX_HANDLETYPE_INDEX_BUFFER					(0x40000000)		// �C���f�b�N�X�o�b�t�@�n���h��
#define DX_HANDLETYPE_FILE							(0x44000000)		// �t�@�C���n���h��

// �v�h�m�c�n�v�r�̃o�[�W�����}�N��
#define DX_WINDOWSVERSION_31						(0x000)
#define DX_WINDOWSVERSION_95						(0x001)
#define DX_WINDOWSVERSION_98						(0x002)
#define DX_WINDOWSVERSION_ME						(0x003)
#define DX_WINDOWSVERSION_NT31						(0x104)
#define DX_WINDOWSVERSION_NT40						(0x105)
#define DX_WINDOWSVERSION_2000						(0x106)
#define DX_WINDOWSVERSION_XP						(0x107)
#define DX_WINDOWSVERSION_VISTA						(0x108)
#define DX_WINDOWSVERSION_7							(0x109)
#define DX_WINDOWSVERSION_NT_TYPE					(0x100)

// �c�����������w�̃o�[�W�����}�N��
#define DX_DIRECTXVERSION_NON						(0)
#define DX_DIRECTXVERSION_1							(0x10000)
#define DX_DIRECTXVERSION_2							(0x20000)
#define DX_DIRECTXVERSION_3							(0x30000)
#define DX_DIRECTXVERSION_4							(0x40000)
#define DX_DIRECTXVERSION_5							(0x50000)
#define DX_DIRECTXVERSION_6							(0x60000)
#define DX_DIRECTXVERSION_6_1						(0x60100)
#define DX_DIRECTXVERSION_7							(0x70000)
#define DX_DIRECTXVERSION_8							(0x80000)
#define DX_DIRECTXVERSION_8_1						(0x80100)

// �����Z�b�g
#define DX_CHARSET_DEFAULT							(0)				// �f�t�H���g�����Z�b�g
#define DX_CHARSET_SHFTJIS							(1)				// ���{�ꕶ���Z�b�g
#define DX_CHARSET_HANGEUL							(2)				// �؍��ꕶ���Z�b�g
#define DX_CHARSET_BIG5								(3)				// �ɑ̕����Z�b�g
#define DX_CHARSET_GB2312							(4)				// �ȑ̕����Z�b�g

// �l�h�c�h�̍Đ����[�h��`
#define DX_MIDIMODE_MCI								(0)				// �l�b�h�ɂ��Đ�
#define DX_MIDIMODE_DM								(1)				// �c�����������l���������ɂ��Đ�

// �`�惂�[�h��`
#define DX_DRAWMODE_NEAREST							(0)				// �l�A���X�g�l�C�o�[�@�ŕ`��
#define DX_DRAWMODE_BILINEAR						(1)				// �o�C���j�A�@�ŕ`�悷��
#define DX_DRAWMODE_ANISOTROPIC						(2)				// �ٕ����t�B���^�����O�@�ŕ`�悷��
#define DX_DRAWMODE_OTHER							(3)				// ����ȊO

// �t�H���g�̃^�C�v
#define DX_FONTTYPE_NORMAL							(0)				// �m�[�}���t�H���g
#define DX_FONTTYPE_EDGE							(1)				// �G�b�W���t�H���g
#define DX_FONTTYPE_ANTIALIASING					(2)				// �A���`�G�C���A�X�t�H���g
#define DX_FONTTYPE_ANTIALIASING_EDGE				(3)				// �A���`�G�C���A�X���G�b�W�t���t�H���g

// �`��u�����h���[�h��`
#define DX_BLENDMODE_NOBLEND						(0)				// �m�[�u�����h
#define DX_BLENDMODE_ALPHA							(1)				// ���u�����h
#define DX_BLENDMODE_ADD							(2)				// ���Z�u�����h
#define DX_BLENDMODE_SUB							(3)				// ���Z�u�����h
#define DX_BLENDMODE_MUL							(4)				// ��Z�u�����h
   // (���������p)
#define DX_BLENDMODE_SUB2							(5)				// ���������p���Z�u�����h�q�P
//#define DX_BLENDMODE_BLINEALPHA					(7)				// ���E���ڂ���
#define DX_BLENDMODE_XOR							(6)				// XOR�u�����h( �\�t�g�E�G�A�����_�����O���[�h�ł̂ݗL�� )
#define DX_BLENDMODE_DESTCOLOR						(8)				// �J���[�͍X�V����Ȃ�
#define DX_BLENDMODE_INVDESTCOLOR					(9)				// �`���̐F�̔��]�l���|����
#define DX_BLENDMODE_INVSRC							(10)			// �`�挳�̐F�𔽓]����
#define DX_BLENDMODE_MULA							(11)			// �A���t�@�`�����l���l���t����Z�u�����h
#define DX_BLENDMODE_ALPHA_X4						(12)			// ���u�����h�̕`�挳�̋P�x���ő�S�{�ɂł��郂�[�h
#define DX_BLENDMODE_ADD_X4							(13)			// ���Z�u�����h�̕`�挳�̋P�x���ő�S�{�ɂł��郂�[�h
#define DX_BLENDMODE_SRCCOLOR						(14)			// �`�挳�̃J���[�ł��̂܂ܕ`�悳���
#define DX_BLENDMODE_HALF_ADD						(15)			// �����Z�u�����h

// �摜�����^�C�v
#define DX_BLENDGRAPHTYPE_NORMAL					(0)				// �ʏ퍇��
#define DX_BLENDGRAPHTYPE_WIPE						(1)				// ���C�v����
#define DX_BLENDGRAPHTYPE_ALPHA						(2)				// �u�����h�摜�̃��l�ƌ��摜�̃��l���|�����킹��

// �O���t�B�b�N�t�B���^�[�^�C�v
#define DX_GRAPH_FILTER_MONO						(0)				// ���m�g�[���t�B���^
#define DX_GRAPH_FILTER_GAUSS						(1)				// �K�E�X�t�B���^
#define DX_GRAPH_FILTER_DOWN_SCALE					(2)				// �k���t�B���^
#define DX_GRAPH_FILTER_BRIGHT_CLIP					(3)				// ���邳�N���b�v�t�B���^
#define DX_GRAPH_FILTER_HSB							(4)				// �F���E�ʓx�E���x�t�B���^
#define DX_GRAPH_FILTER_INVERT						(5)				// �K���̔��]�t�B���^
#define DX_GRAPH_FILTER_LEVEL						(6)				// ���x���␳�t�B���^
#define DX_GRAPH_FILTER_TWO_COLOR					(7)				// �Q�K�����t�B���^
#define DX_GRAPH_FILTER_GRADIENT_MAP				(8)				// �O���f�[�V�����}�b�v�t�B���^
#define DX_GRAPH_FILTER_PREMUL_ALPHA				(9)				// �ʏ�̃A���t�@�`�����l���t���摜����Z�ς݃A���t�@�摜�ɕϊ�����t�B���^
#define DX_GRAPH_FILTER_NUM							(10)

// �O���t�B�b�N�u�����h�^�C�v
#define DX_GRAPH_BLEND_NORMAL						(0)				// �ʏ�
#define DX_GRAPH_BLEND_RGBA_SELECT_MIX				(1)				// RGBA�̗v�f��I�����č���
#define DX_GRAPH_BLEND_MULTIPLE						(2)				// ��Z
#define DX_GRAPH_BLEND_DIFFERENCE					(3)				// ���Z
#define DX_GRAPH_BLEND_ADD							(4)				// ���Z
#define DX_GRAPH_BLEND_SCREEN						(5)				// �X�N���[��
#define DX_GRAPH_BLEND_OVERLAY						(6)				// �I�[�o�[���C
#define DX_GRAPH_BLEND_DODGE						(7)				// �����Ă�
#define DX_GRAPH_BLEND_BURN							(8)				// �Ă�����
#define DX_GRAPH_BLEND_DARKEN						(9)				// ��r(��)
#define DX_GRAPH_BLEND_LIGHTEN						(10)			// ��r(��)
#define DX_GRAPH_BLEND_SOFTLIGHT					(11)			// �\�t�g���C�g
#define DX_GRAPH_BLEND_HARDLIGHT					(12)			// �n�[�h���C�g
#define DX_GRAPH_BLEND_EXCLUSION					(13)			// ���O
#define DX_GRAPH_BLEND_NORMAL_ALPHACH				(14)			// ���`�����l���t���摜�̒ʏ퍇��
#define DX_GRAPH_BLEND_ADD_ALPHACH					(15)			// ���`�����l���t���摜�̉��Z����
#define DX_GRAPH_BLEND_MULTIPLE_A_ONLY				(16)			// �A���t�@�`�����l���݂̂̏�Z
#define DX_GRAPH_BLEND_NUM							(17)

// DX_GRAPH_BLEND_RGBA_SELECT_MIX �p�̐F�I��p��`
#define DX_RGBA_SELECT_SRC_R						(0)				// ���摜�̐Ԑ���
#define DX_RGBA_SELECT_SRC_G						(1)				// ���摜�̗ΐ���
#define DX_RGBA_SELECT_SRC_B						(2)				// ���摜�̐���
#define DX_RGBA_SELECT_SRC_A						(3)				// ���摜�̃�����
#define DX_RGBA_SELECT_BLEND_R						(4)				// �u�����h�摜�̐Ԑ���
#define DX_RGBA_SELECT_BLEND_G						(5)				// �u�����h�摜�̗ΐ���
#define DX_RGBA_SELECT_BLEND_B						(6)				// �u�����h�摜�̐���
#define DX_RGBA_SELECT_BLEND_A						(7)				// �u�����h�摜�̃�����

// �|���S���J�����O���[�h
#define DX_CULLING_NONE								(0)				// �J�����O�Ȃ�
#define DX_CULLING_LEFT								(1)				// �w�ʂ������ŃJ�����O
#define DX_CULLING_RIGHT							(2)				// �w�ʂ��E���ŃJ�����O

// �N���b�s���O����
#define DX_CAMERACLIP_LEFT							(0x01)			// ��ʍ������ɃN���b�v
#define DX_CAMERACLIP_RIGHT							(0x02)			// ��ʉE�����ɃN���b�v
#define DX_CAMERACLIP_BOTTOM						(0x04)			// ��ʉ������ɃN���b�v
#define DX_CAMERACLIP_TOP							(0x08)			// ��ʏ�����ɃN���b�v
#define DX_CAMERACLIP_BACK							(0x10)			// ��ʌ�����ɃN���b�v
#define DX_CAMERACLIP_FRONT							(0x20)			// ��ʑO�����ɃN���b�v

// MV1���f���̒��_�^�C�v
#define DX_MV1_VERTEX_TYPE_1FRAME					(0)				// �P�t���[���̉e�����󂯂钸�_
#define DX_MV1_VERTEX_TYPE_4FRAME					(1)				// �P�`�S�t���[���̉e�����󂯂钸�_
#define DX_MV1_VERTEX_TYPE_8FRAME					(2)				// �T�`�W�t���[���̉e�����󂯂钸�_
#define DX_MV1_VERTEX_TYPE_FREE_FRAME				(3)				// �X�t���[���ȏ�̉e�����󂯂钸�_
#define DX_MV1_VERTEX_TYPE_NMAP_1FRAME				(4)				// �@���}�b�v�p�̏�񂪊܂܂��P�t���[���̉e�����󂯂钸�_
#define DX_MV1_VERTEX_TYPE_NMAP_4FRAME				(5)				// �@���}�b�v�p�̏�񂪊܂܂��P�`�S�t���[���̉e�����󂯂钸�_
#define DX_MV1_VERTEX_TYPE_NMAP_8FRAME				(6)				// �@���}�b�v�p�̏�񂪊܂܂��T�`�W�t���[���̉e�����󂯂钸�_
#define DX_MV1_VERTEX_TYPE_NMAP_FREE_FRAME			(7)				// �@���}�b�v�p�̏�񂪊܂܂��X�t���[���ȏ�̉e�����󂯂钸�_
#define DX_MV1_VERTEX_TYPE_NUM						(8)				// ���_�^�C�v�̐�

// MV1�t�@�C���̕ۑ��^�C�v
#define MV1_SAVETYPE_MESH							(0x0001)		// ���b�V�����̂ݕۑ�
#define MV1_SAVETYPE_ANIM							(0x0002)		// �A�j���[�V�������̂ݕۑ�
#define MV1_SAVETYPE_NORMAL							( MV1_SAVETYPE_MESH | MV1_SAVETYPE_ANIM )	// �ʏ�ۑ�

// �`����ʎw��p��`
#define DX_SCREEN_FRONT								(0xfffffffc)
#define DX_SCREEN_BACK								(0xfffffffe) 
#define DX_SCREEN_WORK 								(0xfffffffd)
#define DX_SCREEN_TEMPFRONT							(0xfffffffb)

#define DX_NONE_GRAPH								(0xfffffffb)	// �O���t�B�b�N�Ȃ��n���h��

// �O���t�B�b�N���F���̉摜�򉻊ɘa�������[�h
#define DX_SHAVEDMODE_NONE							(0)				// �摜�򉻊ɘa�������s��Ȃ�
#define DX_SHAVEDMODE_DITHER						(1)				// �f�B�U�����O
#define DX_SHAVEDMODE_DIFFUS						(2)				// �덷�g�U

// �摜�̕ۑ��^�C�v
#define DX_IMAGESAVETYPE_BMP						(0)				// bitmap
#define DX_IMAGESAVETYPE_JPEG						(1)				// jpeg
#define DX_IMAGESAVETYPE_PNG						(2)				// Png

// �T�E���h�Đ��`�Ԏw��p��`
#define DX_PLAYTYPE_LOOPBIT							(0x0002)		// ���[�v�Đ��r�b�g
#define DX_PLAYTYPE_BACKBIT							(0x0001)		// �o�b�N�O���E���h�Đ��r�b�g

#define DX_PLAYTYPE_NORMAL							(0)												// �m�[�}���Đ�
#define DX_PLAYTYPE_BACK				  			( DX_PLAYTYPE_BACKBIT )							// �o�b�N�O���E���h�Đ�
#define DX_PLAYTYPE_LOOP							( DX_PLAYTYPE_LOOPBIT | DX_PLAYTYPE_BACKBIT )	// ���[�v�Đ�

// ����Đ��^�C�v��`
#define DX_MOVIEPLAYTYPE_BCANCEL					(0)				// �{�^���L�����Z������
#define DX_MOVIEPLAYTYPE_NORMAL						(1)				// �{�^���L�����Z���Ȃ�

// �T�E���h�̃^�C�v
#define DX_SOUNDTYPE_NORMAL							(0)				// �m�[�}���T�E���h�`��
#define DX_SOUNDTYPE_STREAMSTYLE					(1)				// �X�g���[�����T�E���h�`��

// �X�g���[���T�E���h�Đ��f�[�^�^�C�v�̃}�N��
#define DX_SOUNDDATATYPE_MEMNOPRESS					(0)				// ���k���ꂽ�S�f�[�^�͍Đ����n�܂�O�ɃT�E���h�������ɂ��ׂĉ𓀂���A�i�[�����
#define DX_SOUNDDATATYPE_MEMNOPRESS_PLUS			(1)				// ���k���ꂽ�S�f�[�^�̓V�X�e���������Ɋi�[����A�Đ����Ȃ��璀���𓀂���A�ŏI�I�ɂ��ׂăT�E���h�������Ɋi�[�����(���̌�V�X�e���������ɑ��݂��鈳�k�f�[�^�͔j�������)
#define DX_SOUNDDATATYPE_MEMPRESS					(2)				// ���k���ꂽ�S�f�[�^�̓V�X�e���������Ɋi�[����A�Đ����镔�����������𓀂��Ȃ���T�E���h�������Ɋi�[����(�炵�I���Ɖ𓀂����f�[�^�͔j�������̂ŉ��x���𓀏������s����)
#define DX_SOUNDDATATYPE_FILE						(3)				// ���k���ꂽ�f�[�^�̍Đ����镔�������t�@�C�����璀���ǂݍ��݉𓀂���A�T�E���h�������Ɋi�[�����(�炵�I���Ɖ𓀂����f�[�^�͔j�������̂ŉ��x���𓀏������s����)

// �ǂݍ��ݏ����̃^�C�v
#define DX_READSOUNDFUNCTION_PCM					(0x0001)		// PCM �̓ǂݍ��ݏ���
#define DX_READSOUNDFUNCTION_ACM					(0x0002)		// ACM ���g�p�����ǂݍ��ݏ���
#define DX_READSOUNDFUNCTION_OGG					(0x0004)		// Ogg Vorbis �̓ǂݍ��ݏ���
#define DX_READSOUNDFUNCTION_MP3					(0x0008)		// ACM ���g�p���� MP3 �̓ǂݍ��ݏ���
#define DX_READSOUNDFUNCTION_DSMP3					(0x0010)		// DirectShow ���g�p���� MP3 �̓ǂݍ��ݏ���

// �}�X�N���ߐF���[�h
#define DX_MASKTRANS_WHITE							(0)				// �}�X�N�摜�̔��������𓧉ߐF�Ƃ���
#define DX_MASKTRANS_BLACK							(1)				// �}�X�N�摜�̍��������𓧉ߐF�Ƃ���
#define DX_MASKTRANS_NONE							(2) 			// ���ߐF�Ȃ�

// �y�o�b�t�@�������݃��[�h
#define DX_ZWRITE_MASK								(0)				// �������߂Ȃ��悤�Ƀ}�X�N����
#define DX_ZWRITE_CLEAR								(1)				// �������߂�悤�Ƀ}�X�N���N���A����

// ��r���[�h
#define DX_CMP_NEVER								(1)				// FALSE
#define DX_CMP_LESS									(2)				// Src <  Dest		DrawAlpha <  TestParam
#define DX_CMP_EQUAL								(3)				// Src == Dest		DrawAlpha == TestParam
#define DX_CMP_LESSEQUAL							(4)				// Src <= Dest		DrawAlpha <= TestParam
#define DX_CMP_GREATER								(5)				// Src >  Dest		DrawAlpha >  TestParam
#define DX_CMP_NOTEQUAL								(6)				// Src != Dest		DrawAlpha != TestParam
#define DX_CMP_GREATEREQUAL							(7)				// Src >= Dest		DrawAlpha >= TestParam
#define DX_CMP_ALWAYS								(8)				// TRUE
#define DX_ZCMP_DEFAULT								( DX_CMP_LESSEQUAL )
#define DX_ZCMP_REVERSE								( DX_CMP_GREATEREQUAL )

// �V�F�[�f�B���O���[�h
#define DX_SHADEMODE_FLAT							D_D3DSHADE_FLAT
#define DX_SHADEMODE_GOURAUD						D_D3DSHADE_GOURAUD

// �t�H�O���[�h
#define DX_FOGMODE_NONE								D_D3DFOG_NONE
#define DX_FOGMODE_EXP								D_D3DFOG_EXP
#define DX_FOGMODE_EXP2								D_D3DFOG_EXP2
#define DX_FOGMODE_LINEAR							D_D3DFOG_LINEAR

// �}�e���A���^�C�v
#define DX_MATERIAL_TYPE_NORMAL						(0)				// �W���}�e���A��
#define DX_MATERIAL_TYPE_TOON						(1)				// �g�D�[�������_�����O�p�}�e���A��
#define DX_MATERIAL_TYPE_TOON_2						(2)				// �g�D�[�������_�����O�p�}�e���A��_�^�C�v�Q( MMD�݊� )

// �}�e���A���u�����h�^�C�v
#define DX_MATERIAL_BLENDTYPE_TRANSLUCENT			(0)				// �A���t�@����
#define DX_MATERIAL_BLENDTYPE_ADDITIVE				(1)				// ���Z
#define DX_MATERIAL_BLENDTYPE_MODULATE				(2)				// ��Z

// �e�N�X�`���A�h���X�^�C�v
#define DX_TEXADDRESS_WRAP							D_D3DTADDRESS_WRAP
#define DX_TEXADDRESS_MIRROR						D_D3DTADDRESS_MIRROR
#define DX_TEXADDRESS_CLAMP							D_D3DTADDRESS_CLAMP
#define DX_TEXADDRESS_BORDER						D_D3DTADDRESS_BORDER

// ���_�f�[�^�^�C�v
#define DX_VERTEX_TYPE_NORMAL_3D					(0)				// VERTEX3D�\���̌`��
#define DX_VERTEX_TYPE_SHADER_3D					(1)				// VERTEX3DSHADER�\���̌`��
#define DX_VERTEX_TYPE_NUM							(2)

// �C���f�b�N�X�f�[�^�^�C�v
#define DX_INDEX_TYPE_16BIT							(0)				// 16bit�C���f�b�N�X

// ���f���t�@�C���ǂݍ��ݎ��̕������Z���[�h
#define DX_LOADMODEL_PHYSICS_DISABLE				(1)				// �������Z���g�p���Ȃ�
#define DX_LOADMODEL_PHYSICS_LOADCALC				(0)				// �ǂݍ��ݎ��Ɍv�Z
#define DX_LOADMODEL_PHYSICS_REALTIME				(2)				// ���s���v�Z

// �|���S���`��^�C�v
#define DX_PRIMTYPE_POINTLIST						D_D3DPT_POINTLIST
#define DX_PRIMTYPE_LINELIST						D_D3DPT_LINELIST
#define DX_PRIMTYPE_LINESTRIP						D_D3DPT_LINESTRIP
#define DX_PRIMTYPE_TRIANGLELIST					D_D3DPT_TRIANGLELIST
#define DX_PRIMTYPE_TRIANGLESTRIP					D_D3DPT_TRIANGLESTRIP
#define DX_PRIMTYPE_TRIANGLEFAN						D_D3DPT_TRIANGLEFAN

// ���C�g�^�C�v
#define DX_LIGHTTYPE_D3DLIGHT_POINT					D_D3DLIGHT_POINT
#define DX_LIGHTTYPE_D3DLIGHT_SPOT					D_D3DLIGHT_SPOT
#define DX_LIGHTTYPE_D3DLIGHT_DIRECTIONAL			D_D3DLIGHT_DIRECTIONAL
#define DX_LIGHTTYPE_D3DLIGHT_FORCEDWORD			D_D3DLIGHT_FORCE_DWORD
#define DX_LIGHTTYPE_POINT							D_D3DLIGHT_POINT
#define DX_LIGHTTYPE_SPOT							D_D3DLIGHT_SPOT
#define DX_LIGHTTYPE_DIRECTIONAL					D_D3DLIGHT_DIRECTIONAL

// �O���t�B�b�N�C���[�W�t�H�[�}�b�g�̒�`
#define DX_GRAPHICSIMAGE_FORMAT_3D_RGB16					(0)		// �P�U�r�b�g�J���[�W��
#define DX_GRAPHICSIMAGE_FORMAT_3D_RGB32					(1)		// �R�Q�r�b�g�J���[�W��
#define DX_GRAPHICSIMAGE_FORMAT_3D_ALPHA_RGB16				(2)		// ���`�����l���t���P�U�r�b�g�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_ALPHA_RGB32				(3)		// ���`�����l���t���R�Q�r�b�g�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_ALPHATEST_RGB16			(4)		// ���e�X�g�t���P�U�r�b�g�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_ALPHATEST_RGB32			(5)		// ���e�X�g�t���R�Q�r�b�g�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT1						(6)		// �c�w�s�P
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT2						(7)		// �c�w�s�Q
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT3						(8)		// �c�w�s�R
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT4						(9)		// �c�w�s�S
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT5 					(10)	// �c�w�s�T
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_RGB16			(11)	// �`��\�P�U�r�b�g�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_RGB32			(12)	// �`��\�R�Q�r�b�g�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ALPHA_RGB32	(13)	// �`��\���t���R�Q�r�b�g�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ABGR_I16		(14)	// �`��\ARGB����16�r�b�g�^�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ABGR_F16		(15)	// �`��\ARGB���������_16�r�b�g�^�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ABGR_F32		(16)	// �`��\ARGB���������_32�r�b�g�^�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ONE_I8			(17)	// �`��\�P�`�����l������8�r�b�g�^�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ONE_I16		(18)	// �`��\�P�`�����l������16�r�b�g�^�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ONE_F16		(19)	// �`��\�P�`�����l����������16�r�b�g�^�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ONE_F32		(20)	// �`��\�P�`�����l����������32�r�b�g�^�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_TWO_I8			(21)	// �`��\�Q�`�����l������8�r�b�g�^�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_TWO_I16		(22)	// �`��\�Q�`�����l������16�r�b�g�^�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_TWO_F16		(23)	// �`��\�Q�`�����l����������16�r�b�g�^�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_TWO_F32		(24)	// �`��\�Q�`�����l����������32�r�b�g�^�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_NUM						(25)
#define DX_GRAPHICSIMAGE_FORMAT_2D							(26)	// �W��( DirectDrawSurface �̏ꍇ�͂���̂� )
#define DX_GRAPHICSIMAGE_FORMAT_R5G6B5						(27)	// R5G6B5( MEMIMG �p )
#define DX_GRAPHICSIMAGE_FORMAT_X8A8R5G6B5					(28)	// X8A8R5G6B5( MEMIMG �p )
#define DX_GRAPHICSIMAGE_FORMAT_X8R8G8B8					(29)	// X8R8G8B8( MEMIMG �p )
#define DX_GRAPHICSIMAGE_FORMAT_A8R8G8B8					(30)	// A8R8G8B8( MEMIMG �p )

#define DX_GRAPHICSIMAGE_FORMAT_NUM							(31)	// �O���t�B�b�N�t�H�[�}�b�g�̎�ނ̐�

// ��{�C���[�W�̃s�N�Z���t�H�[�}�b�g
#define DX_BASEIMAGE_FORMAT_NORMAL					(0)			// ���ʂ̉摜
#define DX_BASEIMAGE_FORMAT_DXT1					(1)			// �c�w�s�P
#define DX_BASEIMAGE_FORMAT_DXT2					(2)			// �c�w�s�Q
#define DX_BASEIMAGE_FORMAT_DXT3					(3)			// �c�w�s�R
#define DX_BASEIMAGE_FORMAT_DXT4					(4)			// �c�w�s�S
#define DX_BASEIMAGE_FORMAT_DXT5					(5)			// �c�w�s�T

// �c�[���o�[�̃{�^���̏��
#define TOOLBUTTON_STATE_ENABLE						(0)			// ���͉\�ȏ��
#define TOOLBUTTON_STATE_PRESSED					(1)			// ������Ă�����
#define TOOLBUTTON_STATE_DISABLE					(2)			// ���͕s�\�ȏ��
#define TOOLBUTTON_STATE_PRESSED_DISABLE			(3)			// ������Ă����ԂŁA���͕s�\�ȏ��
#define TOOLBUTTON_STATE_NUM						(4)			// �c�[���o�[�̃{�^���̏�Ԃ̐�

// �c�[���o�[�̃{�^���̃^�C�v
#define TOOLBUTTON_TYPE_NORMAL						(0)			// ���ʂ̃{�^��
#define TOOLBUTTON_TYPE_CHECK						(1)			// �������Ƃɂn�m�^�n�e�e���؂�ւ��{�^��
#define TOOLBUTTON_TYPE_GROUP						(2)			// �ʂ� TOOLBUTTON_TYPE_GROUP �^�C�v�̃{�^�����������Ƃn�e�e�ɂȂ�^�C�v�̃{�^��(�O���[�v�̋�؂�͌��Ԃ�)
#define TOOLBUTTON_TYPE_SEP							(3)			// ����(�{�^���ł͂���܂���)
#define TOOLBUTTON_TYPE_NUM							(4)			// �c�[���o�[�̃{�^���̃^�C�v�̐�

// �e���j���[�̂h�c
#define MENUITEM_IDTOP								(0xabababab)

// ���j���[�ɒǉ�����ۂ̃^�C�v
#define MENUITEM_ADD_CHILD							(0)				// �w��̍��ڂ̎q�Ƃ��Ēǉ�����
#define MENUITEM_ADD_INSERT							(1)				// �w��̍��ڂƎw��̍��ڂ����̍��ڂ̊Ԃɒǉ�����

// ���j���[�̉��ɕt���}�[�N�^�C�v
#define MENUITEM_MARK_NONE							(0)				// �����t������
#define MENUITEM_MARK_CHECK							(1)				// �`�F�b�N�}�[�N
#define MENUITEM_MARK_RADIO							(2)				// ���W�I�{�^��

// �����ϊ��^�C�v��`
#define DX_NUMMODE_10								(0)				// �P�O�i��
#define DX_NUMMODE_16								(1)				// �P�U�i��
#define DX_STRMODE_NOT0								(2)				// �󂫂��O�Ŗ��߂Ȃ�
#define DX_STRMODE_USE0								(3)				// �󂫂��O�Ŗ��߂�

// CheckHitKeyAll �Œ��ׂ���̓^�C�v
#define DX_CHECKINPUT_KEY							(0x0001)		// �L�[���͂𒲂ׂ�
#define DX_CHECKINPUT_PAD							(0x0002)		// �p�b�h���͂𒲂ׂ�
#define DX_CHECKINPUT_MOUSE							(0x0004)		// �}�E�X�{�^�����͂𒲂ׂ�
#define DX_CHECKINPUT_ALL							(DX_CHECKINPUT_KEY | DX_CHECKINPUT_PAD | DX_CHECKINPUT_MOUSE)	// ���ׂĂ̓��͂𒲂ׂ�

// �p�b�h���͎擾�p�����[�^
#define DX_INPUT_KEY_PAD1							(0x1001)		// �L�[���͂ƃp�b�h�P����
#define DX_INPUT_PAD1								(0x0001)		// �p�b�h�P����
#define DX_INPUT_PAD2								(0x0002)		// �p�b�h�Q����
#define DX_INPUT_PAD3								(0x0003)		// �p�b�h�R����
#define DX_INPUT_PAD4								(0x0004)		// �p�b�h�S����
#define DX_INPUT_PAD5								(0x0005)		// �p�b�h�T����
#define DX_INPUT_PAD6								(0x0006)		// �p�b�h�U����
#define DX_INPUT_PAD7								(0x0007)		// �p�b�h�V����
#define DX_INPUT_PAD8								(0x0008)		// �p�b�h�W����
#define DX_INPUT_PAD9								(0x0009)		// �p�b�h�X����
#define DX_INPUT_PAD10								(0x000a)		// �p�b�h�P�O����
#define DX_INPUT_PAD11								(0x000b)		// �p�b�h�P�P����
#define DX_INPUT_PAD12								(0x000c)		// �p�b�h�P�Q����
#define DX_INPUT_PAD13								(0x000d)		// �p�b�h�P�R����
#define DX_INPUT_PAD14								(0x000e)		// �p�b�h�P�S����
#define DX_INPUT_PAD15								(0x000f)		// �p�b�h�P�T����
#define DX_INPUT_PAD16								(0x0010)		// �p�b�h�P�U����
#define DX_INPUT_KEY								(0x1000)		// �L�[����

// ���[�r�[�̃T�[�t�F�X���[�h
#define DX_MOVIESURFACE_NORMAL						(0)
#define DX_MOVIESURFACE_OVERLAY						(1)
#define DX_MOVIESURFACE_FULLCOLOR					(2)

// �p�b�h���͒�`
#define PAD_INPUT_DOWN								(0x00000001)	// ���`�F�b�N�}�X�N
#define PAD_INPUT_LEFT								(0x00000002)	// ���`�F�b�N�}�X�N
#define PAD_INPUT_RIGHT								(0x00000004)	// ���`�F�b�N�}�X�N
#define PAD_INPUT_UP								(0x00000008)	// ���`�F�b�N�}�X�N
#define PAD_INPUT_A									(0x00000010)	// �`�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_B									(0x00000020)	// �a�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_C									(0x00000040)	// �b�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_X									(0x00000080)	// �w�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_Y									(0x00000100)	// �x�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_Z									(0x00000200)	// �y�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_L									(0x00000400)	// �k�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_R									(0x00000800)	// �q�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_START								(0x00001000)	// �r�s�`�q�s�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_M									(0x00002000)	// �l�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_D									(0x00004000)
#define PAD_INPUT_F									(0x00008000)
#define PAD_INPUT_G									(0x00010000)
#define PAD_INPUT_H									(0x00020000)
#define PAD_INPUT_I									(0x00040000)
#define PAD_INPUT_J									(0x00080000)
#define PAD_INPUT_K									(0x00100000)
#define PAD_INPUT_LL								(0x00200000)
#define PAD_INPUT_N									(0x00400000)
#define PAD_INPUT_O									(0x00800000)
#define PAD_INPUT_P									(0x01000000)
#define PAD_INPUT_RR								(0x02000000)
#define PAD_INPUT_S									(0x04000000)
#define PAD_INPUT_T									(0x08000000)
#define PAD_INPUT_U									(0x10000000)
#define PAD_INPUT_V									(0x20000000)
#define PAD_INPUT_W									(0x40000000)
#define PAD_INPUT_XX								(0x80000000)

#define PAD_INPUT_1									(0x00000010)
#define PAD_INPUT_2									(0x00000020)
#define PAD_INPUT_3									(0x00000040)
#define PAD_INPUT_4									(0x00000080)
#define PAD_INPUT_5									(0x00000100)
#define PAD_INPUT_6									(0x00000200)
#define PAD_INPUT_7									(0x00000400)
#define PAD_INPUT_8									(0x00000800)
#define PAD_INPUT_9									(0x00001000)
#define PAD_INPUT_10								(0x00002000)
#define PAD_INPUT_11								(0x00004000)
#define PAD_INPUT_12								(0x00008000)
#define PAD_INPUT_13								(0x00010000)
#define PAD_INPUT_14								(0x00020000)
#define PAD_INPUT_15								(0x00040000)
#define PAD_INPUT_16								(0x00080000)
#define PAD_INPUT_17								(0x00100000)
#define PAD_INPUT_18								(0x00200000)
#define PAD_INPUT_19								(0x00400000)
#define PAD_INPUT_20								(0x00800000)
#define PAD_INPUT_21								(0x01000000)
#define PAD_INPUT_22								(0x02000000)
#define PAD_INPUT_23								(0x04000000)
#define PAD_INPUT_24								(0x08000000)
#define PAD_INPUT_25								(0x10000000)
#define PAD_INPUT_26								(0x20000000)
#define PAD_INPUT_27								(0x40000000)
#define PAD_INPUT_28								(0x80000000)

// �}�E�X���͒�`
#define MOUSE_INPUT_LEFT							(0x0001)			// �}�E�X���{�^��
#define MOUSE_INPUT_RIGHT							(0x0002)			// �}�E�X�E�{�^��
#define MOUSE_INPUT_MIDDLE							(0x0004)			// �}�E�X�����{�^��
#define MOUSE_INPUT_1								(0x0001)			// �}�E�X�P�{�^��
#define MOUSE_INPUT_2								(0x0002)			// �}�E�X�Q�{�^��
#define MOUSE_INPUT_3								(0x0004)			// �}�E�X�R�{�^��
#define MOUSE_INPUT_4								(0x0008)			// �}�E�X�S�{�^��
#define MOUSE_INPUT_5								(0x0010)			// �}�E�X�T�{�^��
#define MOUSE_INPUT_6								(0x0020)			// �}�E�X�U�{�^��
#define MOUSE_INPUT_7								(0x0040)			// �}�E�X�V�{�^��
#define MOUSE_INPUT_8								(0x0080)			// �}�E�X�W�{�^��

// �L�[��`
#define KEY_INPUT_BACK								D_DIK_BACK			// �o�b�N�X�y�[�X�L�[
#define KEY_INPUT_TAB								D_DIK_TAB			// �^�u�L�[
#define KEY_INPUT_RETURN							D_DIK_RETURN		// �G���^�[�L�[

#define KEY_INPUT_LSHIFT							D_DIK_LSHIFT		// ���V�t�g�L�[
#define KEY_INPUT_RSHIFT							D_DIK_RSHIFT		// �E�V�t�g�L�[
#define KEY_INPUT_LCONTROL							D_DIK_LCONTROL		// ���R���g���[���L�[
#define KEY_INPUT_RCONTROL							D_DIK_RCONTROL		// �E�R���g���[���L�[
#define KEY_INPUT_ESCAPE							D_DIK_ESCAPE		// �G�X�P�[�v�L�[
#define KEY_INPUT_SPACE								D_DIK_SPACE			// �X�y�[�X�L�[
#define KEY_INPUT_PGUP								D_DIK_PGUP			// �o�������t�o�L�[
#define KEY_INPUT_PGDN								D_DIK_PGDN			// �o�������c�������L�[
#define KEY_INPUT_END								D_DIK_END			// �G���h�L�[
#define KEY_INPUT_HOME								D_DIK_HOME			// �z�[���L�[
#define KEY_INPUT_LEFT								D_DIK_LEFT			// ���L�[
#define KEY_INPUT_UP								D_DIK_UP			// ��L�[
#define KEY_INPUT_RIGHT								D_DIK_RIGHT			// �E�L�[
#define KEY_INPUT_DOWN								D_DIK_DOWN			// ���L�[
#define KEY_INPUT_INSERT							D_DIK_INSERT		// �C���T�[�g�L�[
#define KEY_INPUT_DELETE							D_DIK_DELETE		// �f���[�g�L�[

#define KEY_INPUT_MINUS								D_DIK_MINUS			// �|�L�[
#define KEY_INPUT_YEN								D_DIK_YEN			// ���L�[
#define KEY_INPUT_PREVTRACK							D_DIK_PREVTRACK		// �O�L�[
#define KEY_INPUT_PERIOD							D_DIK_PERIOD		// �D�L�[
#define KEY_INPUT_SLASH								D_DIK_SLASH			// �^�L�[
#define KEY_INPUT_LALT								D_DIK_LALT			// ���`�k�s�L�[
#define KEY_INPUT_RALT								D_DIK_RALT			// �E�`�k�s�L�[
#define KEY_INPUT_SCROLL							D_DIK_SCROLL		// ScrollLock�L�[
#define KEY_INPUT_SEMICOLON							D_DIK_SEMICOLON		// �G�L�[
#define KEY_INPUT_COLON								D_DIK_COLON			// �F�L�[
#define KEY_INPUT_LBRACKET							D_DIK_LBRACKET		// �m�L�[
#define KEY_INPUT_RBRACKET							D_DIK_RBRACKET		// �n�L�[
#define KEY_INPUT_AT								D_DIK_AT			// ���L�[
#define KEY_INPUT_BACKSLASH							D_DIK_BACKSLASH		// �_�L�[
#define KEY_INPUT_COMMA								D_DIK_COMMA			// �C�L�[
#define KEY_INPUT_KANJI								D_DIK_KANJI			// �����L�[
#define KEY_INPUT_CONVERT							D_DIK_CONVERT		// �ϊ��L�[
#define KEY_INPUT_NOCONVERT							D_DIK_NOCONVERT		// ���ϊ��L�[
#define KEY_INPUT_KANA								D_DIK_KANA			// �J�i�L�[
#define KEY_INPUT_APPS								D_DIK_APPS			// �A�v���P�[�V�������j���[�L�[
#define KEY_INPUT_CAPSLOCK							D_DIK_CAPSLOCK		// CaspLock�L�[
#define KEY_INPUT_SYSRQ								D_DIK_SYSRQ			// PrintScreen�L�[
#define KEY_INPUT_PAUSE								D_DIK_PAUSE			// PauseBreak�L�[
#define KEY_INPUT_LWIN								D_DIK_LWIN			// ���v�����L�[
#define KEY_INPUT_RWIN								D_DIK_RWIN			// �E�v�����L�[

#define KEY_INPUT_NUMLOCK							D_DIK_NUMLOCK		// �e���L�[�O
#define KEY_INPUT_NUMPAD0							D_DIK_NUMPAD0		// �e���L�[�O
#define KEY_INPUT_NUMPAD1							D_DIK_NUMPAD1		// �e���L�[�P
#define KEY_INPUT_NUMPAD2							D_DIK_NUMPAD2		// �e���L�[�Q
#define KEY_INPUT_NUMPAD3							D_DIK_NUMPAD3		// �e���L�[�R
#define KEY_INPUT_NUMPAD4							D_DIK_NUMPAD4		// �e���L�[�S
#define KEY_INPUT_NUMPAD5							D_DIK_NUMPAD5		// �e���L�[�T
#define KEY_INPUT_NUMPAD6							D_DIK_NUMPAD6		// �e���L�[�U
#define KEY_INPUT_NUMPAD7							D_DIK_NUMPAD7		// �e���L�[�V
#define KEY_INPUT_NUMPAD8							D_DIK_NUMPAD8		// �e���L�[�W
#define KEY_INPUT_NUMPAD9							D_DIK_NUMPAD9		// �e���L�[�X
#define KEY_INPUT_MULTIPLY							D_DIK_MULTIPLY		// �e���L�[���L�[
#define KEY_INPUT_ADD								D_DIK_ADD			// �e���L�[�{�L�[
#define KEY_INPUT_SUBTRACT							D_DIK_SUBTRACT		// �e���L�[�|�L�[
#define KEY_INPUT_DECIMAL							D_DIK_DECIMAL		// �e���L�[�D�L�[
#define KEY_INPUT_DIVIDE							D_DIK_DIVIDE		// �e���L�[�^�L�[
#define KEY_INPUT_NUMPADENTER						D_DIK_NUMPADENTER	// �e���L�[�̃G���^�[�L�[

#define KEY_INPUT_F1								D_DIK_F1			// �e�P�L�[
#define KEY_INPUT_F2								D_DIK_F2			// �e�Q�L�[
#define KEY_INPUT_F3								D_DIK_F3			// �e�R�L�[
#define KEY_INPUT_F4								D_DIK_F4			// �e�S�L�[
#define KEY_INPUT_F5								D_DIK_F5			// �e�T�L�[
#define KEY_INPUT_F6								D_DIK_F6			// �e�U�L�[
#define KEY_INPUT_F7								D_DIK_F7			// �e�V�L�[
#define KEY_INPUT_F8								D_DIK_F8			// �e�W�L�[
#define KEY_INPUT_F9								D_DIK_F9			// �e�X�L�[
#define KEY_INPUT_F10								D_DIK_F10			// �e�P�O�L�[
#define KEY_INPUT_F11								D_DIK_F11			// �e�P�P�L�[
#define KEY_INPUT_F12								D_DIK_F12			// �e�P�Q�L�[

#define KEY_INPUT_A									D_DIK_A			// �`�L�[
#define KEY_INPUT_B									D_DIK_B			// �a�L�[
#define KEY_INPUT_C									D_DIK_C			// �b�L�[
#define KEY_INPUT_D									D_DIK_D			// �c�L�[
#define KEY_INPUT_E									D_DIK_E			// �d�L�[
#define KEY_INPUT_F									D_DIK_F			// �e�L�[
#define KEY_INPUT_G									D_DIK_G			// �f�L�[
#define KEY_INPUT_H									D_DIK_H			// �g�L�[
#define KEY_INPUT_I									D_DIK_I			// �h�L�[
#define KEY_INPUT_J									D_DIK_J			// �i�L�[
#define KEY_INPUT_K									D_DIK_K			// �j�L�[
#define KEY_INPUT_L									D_DIK_L			// �k�L�[
#define KEY_INPUT_M									D_DIK_M			// �l�L�[
#define KEY_INPUT_N									D_DIK_N			// �m�L�[
#define KEY_INPUT_O									D_DIK_O			// �n�L�[
#define KEY_INPUT_P									D_DIK_P			// �o�L�[
#define KEY_INPUT_Q									D_DIK_Q			// �p�L�[
#define KEY_INPUT_R									D_DIK_R			// �q�L�[
#define KEY_INPUT_S									D_DIK_S			// �r�L�[
#define KEY_INPUT_T									D_DIK_T			// �s�L�[
#define KEY_INPUT_U									D_DIK_U			// �t�L�[
#define KEY_INPUT_V									D_DIK_V			// �u�L�[
#define KEY_INPUT_W									D_DIK_W			// �v�L�[
#define KEY_INPUT_X									D_DIK_X			// �w�L�[
#define KEY_INPUT_Y									D_DIK_Y			// �x�L�[
#define KEY_INPUT_Z									D_DIK_Z			// �y�L�[

#define KEY_INPUT_0 								D_DIK_0			// �O�L�[
#define KEY_INPUT_1									D_DIK_1			// �P�L�[
#define KEY_INPUT_2									D_DIK_2			// �Q�L�[
#define KEY_INPUT_3									D_DIK_3			// �R�L�[
#define KEY_INPUT_4									D_DIK_4			// �S�L�[
#define KEY_INPUT_5									D_DIK_5			// �T�L�[
#define KEY_INPUT_6									D_DIK_6			// �U�L�[
#define KEY_INPUT_7									D_DIK_7			// �V�L�[
#define KEY_INPUT_8									D_DIK_8			// �W�L�[
#define KEY_INPUT_9									D_DIK_9			// �X�L�[

// �A�X�L�[�R���g���[���L�[�R�[�h
#define CTRL_CODE_BS								(0x08)				// �o�b�N�X�y�[�X
#define CTRL_CODE_TAB								(0x09)				// �^�u
#define CTRL_CODE_CR								(0x0d)				// ���s
#define CTRL_CODE_DEL								(0x10)				// �c�d�k�L�[

#define CTRL_CODE_COPY								(0x03)				// �R�s�[
#define CTRL_CODE_PASTE								(0x16)				// �y�[�X�g
#define CTRL_CODE_CUT								(0x18)				// �J�b�g
#define CTRL_CODE_ALL								(0x01)				// �S�đI��

#define CTRL_CODE_LEFT								(0x1d)				// ���L�[
#define CTRL_CODE_RIGHT								(0x1c)				// ���L�[
#define CTRL_CODE_UP								(0x1e)				// ���L�[
#define CTRL_CODE_DOWN								(0x1f)				// ���L�[

#define CTRL_CODE_HOME								(0x1a)				// �g�n�l�d�{�^��
#define CTRL_CODE_END								(0x19)				// �d�m�c�{�^��
#define CTRL_CODE_PAGE_UP							(0x17)				// �o�`�f�d �t�o
#define CTRL_CODE_PAGE_DOWN							(0x15)				// �o�`�f�d �c�n�v�m

#define CTRL_CODE_ESC								(0x1b)				// �d�r�b�L�[
#define CTRL_CODE_CMP								(0x20)				// ����R�[�h�~���l

// SetGraphMode �߂�l��`
#define DX_CHANGESCREEN_OK							(0)					// ��ʕύX�͐�������
#define DX_CHANGESCREEN_RETURN						(-1)				// ��ʂ̕ύX�͎��s���A���̉�ʃ��[�h�ɖ߂��ꂽ
#define DX_CHANGESCREEN_DEFAULT						(-2)				// ��ʂ̕ύX�͎��s���f�t�H���g�̉�ʃ��[�h�ɕύX���ꂽ
#define DX_CHANGESCREEN_REFRESHNORMAL				(-3)				// ��ʂ̕ύX�͐����������A���t���b�V�����[�g�̕ύX�͎��s����

// �X�g���[���f�[�^�ǂݍ��ݏ����R�[�h�ȗ����֘A
#define STTELL( st )								((st)->ReadShred.Tell( (st)->DataPoint ))
#define STSEEK( st, pos, type )						((st)->ReadShred.Seek( (st)->DataPoint, (pos), (type) ))
#define STREAD( buf, length, num, st )				((st)->ReadShred.Read( (buf), (length), (num), (st)->DataPoint ))
#define STWRITE( buf, length, num, st )				((st)->ReadShred.Write( (buf), (length), (num), (st)->DataPoint ))
#define STEOF( st )									((st)->ReadShred.Eof( (st)->DataPoint ))
#define STCLOSE( st )								((st)->ReadShred.Close( (st)->DataPoint ))

// �X�g���[���f�[�^����̃V�[�N�^�C�v��`
#define STREAM_SEEKTYPE_SET							(SEEK_SET)
#define STREAM_SEEKTYPE_END							(SEEK_END)
#define STREAM_SEEKTYPE_CUR							(SEEK_CUR)

// �O���t�B�b�N���[�h���̃C���[�W�^�C�v
#define LOADIMAGE_TYPE_FILE							(0)				// �C���[�W�̓t�@�C���ł���
#define LOADIMAGE_TYPE_MEM							(1)				// �C���[�W�̓������ł���
#define LOADIMAGE_TYPE_NONE							(-1)			// �C���[�W�͖���

// DrawPreparation �֐��ɓn���t���O
#define DRAWPREP_TRANS								(0x0001)
#define DRAWPREP_VECTORINT							(0x0002)
#define DRAWPREP_GOURAUDSHADE						(0x0008)
#define DRAWPREP_PERSPECTIVE						(0x0010)
#define DRAWPREP_DIFFUSERGB							(0x0020)
#define DRAWPREP_DIFFUSEALPHA						(0x0040)
#define DRAWPREP_FOG								(0x0080)
#define DRAWPREP_NOBLENDSETTING						(0x0100)
#define DRAWPREP_LIGHTING							(0x0200)
#define DRAWPREP_SPECULAR							(0x0400)
#define DRAWPREP_3D									(0x0800)
#define DRAWPREP_TEXADDRESS							(0x1000)
#define DRAWPREP_NOTSHADERRESET						(0x2000)
#define DRAWPREP_CULLING							(0x4000)


#ifndef DX_NON_NETWORK

// HTTP �G���[
#define HTTP_ERR_SERVER								(0)				// �T�[�o�[�G���[
#define HTTP_ERR_NOTFOUND							(1)				// �t�@�C����������Ȃ�����
#define HTTP_ERR_MEMORY								(2)				// �������m�ۂ̎��s
#define HTTP_ERR_LOST								(3)				// �r���Őؒf���ꂽ
#define HTTP_ERR_NONE								(-1)			// �G���[�͕񍐂���Ă��Ȃ�

// HTTP �����̌���
#define HTTP_RES_COMPLETE							(0)				// ��������
#define HTTP_RES_STOP								(1)				// �������~
#define HTTP_RES_ERROR								(2)				// �G���[�I��
#define HTTP_RES_NOW								(-1)			// ���ݐi�s��

#endif // DX_NON_NETWORK

#define DX_DEFINE_END

// �f�[�^�^��`-------------------------------------------------------------------

namespace DxLib
{

#define DX_STRUCT_START

// �h�l�d���͕�����̕`��ɕK�v�ȏ��̓��̕��ߏ��
typedef struct tagIMEINPUTCLAUSEDATA
{
	int						Position ;				// ���o�C�g�ڂ���
	int						Length ;				// ���o�C�g��
} IMEINPUTCLAUSEDATA, *LPIMEINPUTCLAUSEDATA ;

// �h�l�d���͕�����̕`��ɕK�v�ȏ��
typedef struct tagIMEINPUTDATA
{
	const TCHAR *				InputString ;			// ���͒��̕�����

	int							CursorPosition ;		// �J�[�\���̓��͕����񒆂̈ʒu(�o�C�g�P��)

	const IMEINPUTCLAUSEDATA *	ClauseData ;			// ���ߏ��
	int							ClauseNum ;				// ���ߏ��̐�
	int							SelectClause ;			// �I�𒆂̕���( -1 �̏ꍇ�͂ǂ̕��߂ɂ������Ă��Ȃ�( �����ɃJ�[�\�������� ) )

	int							CandidateNum ;			// �ϊ����̐�( 0�̏ꍇ�͕ϊ����ł͂Ȃ� )
	const TCHAR **				CandidateList ;			// �ϊ���╶���񃊃X�g( ��F���Ԗڂ̌���`�悷��ꍇ  DrawString( 0, 0, data.CandidateList[ n ], GetColor(255,255,255) ); )
	int							SelectCandidate ;		// �I�𒆂̕ϊ����

	int							ConvertFlag ;			// �����ϊ������ǂ���( TRUE:�ϊ���  FALSE:�ϊ����ł͂Ȃ�( �����P�ʂŃJ�[�\�����ړ��ł����� ) )
} IMEINPUTDATA, *LPIMEINPUTDATA ;

// �^�C���f�[�^�^
typedef struct tagDATEDATA
{
	int						Year ;							// �N
	int						Mon ;							// ��
	int						Day ;							// ��
	int						Hour ;							// ����
	int						Min ;							// ��
	int						Sec ;							// �b
} DATEDATA, *LPDATEDATA ;

// ��ʃ��[�h���f�[�^�^
typedef struct tagDISPLAYMODEDATA
{
	int						Width ;				// �����𑜓x
	int						Height ;			// �����𑜓x
	int						ColorBitDepth ;		// �F�r�b�g�[�x
	int						RefreshRate ;		// ���t���b�V�����[�g( -1 �̏ꍇ�͋K��l )
} DISPLAYMODEDATA, *LPDISPLAYMODEDATA ;

// �t�@�C�����\����
typedef struct tagFILEINFO
{
	TCHAR					Name[260] ;			 // �I�u�W�F�N�g��
	int						DirFlag ;			// �f�B���N�g�����ǂ���( TRUE:�f�B���N�g��  FALSE:�t�@�C�� )
	LONGLONG				Size ;				// �T�C�Y
	DATEDATA				CreationTime ;		// �쐬����
	DATEDATA				LastWriteTime ;		// �ŏI�X�V����
} FILEINFO, *LPFILEINFO ;

#ifndef DX_NOTUSE_DRAWFUNCTION

// �s��\����
typedef struct tagMATRIX
{
	float					m[4][4] ;
} MATRIX, *LPMATRIX ;

// �x�N�g���f�[�^�^
typedef struct tagVECTOR
{
	float					x, y, z ;
} VECTOR, *LPVECTOR, XYZ, *LPXYZ ;

// FLOAT2�f�[�^�^
typedef struct tagFLOAT2
{
	float					u, v ;
} UV ;

// float �^�̃J���[�l
typedef struct tagCOLOR_F
{
	float					r, g, b, a ;
} COLOR_F, *LPCOLOR_F ;

// unsigned char �^�̃J���[�l
typedef struct tagCOLOR_U8
{
	BYTE					b, g, r, a ;
} COLOR_U8 ;

// FLOAT4�f�[�^�^
typedef struct tagFLOAT4
{
	float					x, y, z, w ;
} FLOAT4, *LPFLOAT4 ;

// INT4�f�[�^�^
typedef struct tagINT4
{
	int						x, y, z, w ;
} INT4 ;

// �Q�c�`��p���_�\����(�e�N�X�`������)
typedef struct tagVERTEX_NOTEX_2D
{
	VECTOR					pos ;
	float					rhw ;
	int						color ;
} VERTEX_NOTEX_2D, *LPVERTEX_NOTEX_2D ; 

// ��ɂQ�c�`��Ɏg�p���钸�_�f�[�^�^
typedef struct tagVERTEX_2D
{
	VECTOR					pos ;
	float					rhw ;
	int						color ;
	float					u, v ;
} VERTEX_2D, *LPVERTEX_2D ; 

// �Q�c�`��Ɏg�p���钸�_�f�[�^�^(DrawPrimitive2D�p)
typedef struct tagVERTEX2D
{
	VECTOR					pos ;
	float					rhw ;
	COLOR_U8				dif ;
	float					u, v ;
} VERTEX2D, *LPVERTEX2D ; 

// �Q�c�`��Ɏg�p���钸�_�f�[�^�^(DrawPrimitive2DToShader�p)
typedef struct tagVERTEX2DSHADER
{
	VECTOR					pos ;
	float					rhw ;
	COLOR_U8				dif ;
	COLOR_U8				spc ;
	float					u, v ;
	float					su, sv ;
} VERTEX2DSHADER, *LPVERTEX2DSHADER ; 

// �Q�c�`��Ɏg�p���钸�_�f�[�^�^(���J�p)
typedef struct tagVERTEX
{
	float					x, y ;
	float					u, v ;
	unsigned char			b, g, r, a ;
} VERTEX ;

// �R�c�`��Ɏg�p���钸�_�f�[�^�^( �e�N�X�`���Ȃ� )( ���o�[�W�����̂��� )
typedef struct tagVERTEX_NOTEX_3D
{
	VECTOR					pos ;
	unsigned char			b, g, r, a ;
} VERTEX_NOTEX_3D, *LPVERTEX_NOTEX_3D ;

// �R�c�`��Ɏg�p���钸�_�f�[�^�^( ���o�[�W�����̂��� )
typedef struct tagVERTEX_3D
{
	VECTOR					pos ;
	unsigned char			b, g, r, a ;
	float					u, v ;
} VERTEX_3D, *LPVERTEX_3D ;

// �R�c�`��Ɏg�p���钸�_�f�[�^�^
typedef struct tagVERTEX3D
{
	VECTOR					pos ;						// ���W
	VECTOR					norm ;						// �@��
	COLOR_U8				dif ;						// �f�B�t���[�Y�J���[
	COLOR_U8				spc ;						// �X�y�L�����J���[
	float					u, v ;						// �e�N�X�`�����W
	float					su, sv ;					// �⏕�e�N�X�`�����W
} VERTEX3D, *LPVERTEX3D ;

// �R�c�`��Ɏg�p���钸�_�f�[�^�^( DrawPrimitive3DToShader�p )
// ���Ӂc�����o�ϐ��ɒǉ������邩������܂���̂ŁA�錾���̏�����( VERTEX3DSHADER Vertex = { 0.0f, 0.0f, ... �Ƃ����悤�Ȃ��� )�͂��Ȃ������ǂ��ł�
typedef struct tagVERTEX3DSHADER
{
	VECTOR					pos ;						// ���W
	FLOAT4					spos ;						// �⏕���W
	VECTOR					norm ;						// �@��
	VECTOR					tan ;						// �ڐ�
	VECTOR					binorm ;					// �]�@��
	COLOR_U8				dif ;						// �f�B�t���[�Y�J���[
	COLOR_U8				spc ;						// �X�y�L�����J���[
	float					u, v ;						// �e�N�X�`�����W
	float					su, sv ;					// �⏕�e�N�X�`�����W
} VERTEX3DSHADER, *LPVERTEX3DSHADER ;

// ���C�g�p�����[�^
typedef struct tagLIGHTPARAM
{
	int						LightType ;					// ���C�g�̃^�C�v( DX_LIGHTTYPE_D3DLIGHT_POINT �� )
	COLOR_F					Diffuse ;					// �f�B�t���[�Y�J���[
	COLOR_F					Specular ;					// �X�y�L�����J���[
	COLOR_F					Ambient ;					// �A���r�G���g�F
	VECTOR					Position ;					// �ʒu
	VECTOR					Direction ;					// ����
	float					Range ;						// �L������
	float					Falloff ;					// �t�H�[���I�t 1.0f �ɂ��Ă����̂��D�܂���
	float					Attenuation0 ;				// �����ɂ�錸���W���O
	float					Attenuation1 ;				// �����ɂ�錸���W���P
	float					Attenuation2 ;				// �����ɂ�錸���W���Q
	float					Theta ;						// �X�|�b�g���C�g�̓����R�[���̏Ɩ��p�x( ���W�A�� )
	float					Phi ;						// �X�|�b�g���C�g�̊O���R�[���̏Ɩ��p�x
} LIGHTPARAM ;

// �}�e���A���p�����[�^
typedef struct tagMATERIALPARAM
{
	COLOR_F					Diffuse ;					// �f�B�t���[�Y�J���[
	COLOR_F					Ambient ;					// �A���r�G���g�J���[
	COLOR_F					Specular ;					// �X�y�L�����J���[
	COLOR_F					Emissive ;					// �G�~�b�V�u�J���[
	float					Power ;						// �X�y�L�����n�C���C�g�̑N���x
} MATERIALPARAM ;

// ���C���q�b�g�`�F�b�N���ʊi�[�p�\����
typedef struct tagHITRESULT_LINE
{
	int						HitFlag ;					// �����������ǂ���( 1:��������  0:������Ȃ����� )
	VECTOR					Position ;					// �����������W
} HITRESULT_LINE ;

// �R���W�������ʑ���p�|���S��
typedef struct tagMV1_COLL_RESULT_POLY
{
	int						HitFlag ;							// ( MV1CollCheck_Line �ł̂ݗL�� )�q�b�g�t���O( 1:�q�b�g����  0:�q�b�g���Ȃ����� )
	VECTOR					HitPosition ;						// ( MV1CollCheck_Line �ł̂ݗL�� )�q�b�g���W

	int						FrameIndex ;						// ���������|���S�����܂܂��t���[���̔ԍ�
	int						PolygonIndex ;						// ���������|���S���̔ԍ�
	int						MaterialIndex ;						// ���������|���S�����g�p���Ă���}�e���A���̔ԍ�
	VECTOR					Position[ 3 ] ;						// ���������|���S�����`������O�_�̍��W
	VECTOR					Normal ;							// ���������|���S���̖@��
} MV1_COLL_RESULT_POLY ;

// �R���W�������ʑ���p�|���S���z��
typedef struct tagMV1_COLL_RESULT_POLY_DIM
{
	int						HitNum ;							// �q�b�g�����|���S���̐�
	MV1_COLL_RESULT_POLY *	Dim ;								// �q�b�g�����|���S���̔z��( HitNum�����݂��� )
} MV1_COLL_RESULT_POLY_DIM ;

// �Q�Ɨp���_�\����
typedef struct tagMV1_REF_VERTEX
{
	VECTOR					Position ;							// �ʒu
	VECTOR					Normal ;							// �@��
	UV						TexCoord[ 2 ] ;						// �e�N�X�`�����W
	COLOR_U8				DiffuseColor ;						// �f�B�t���[�Y�J���[
	COLOR_U8				SpecularColor ;						// �X�y�L�����J���[
} MV1_REF_VERTEX ;

// �Q�Ɨp�|���S���\����
typedef struct tagMV1_REF_POLYGON
{
	unsigned short			FrameIndex ;						// ���̃|���S���������Ă���t���[��
	unsigned short			MaterialIndex ;						// �g�p���Ă���}�e���A��
	int						VIndexTarget ;						// VIndex ���w���C���f�b�N�X�̎Q�Ɛ�( 1:�t���[��  0:���f���S�� )
	int						VIndex[ 3 ] ;						// �R�p�`�|���S���𐬂��Q�ƒ��_�̃C���f�b�N�X
	VECTOR					MinPosition ;						// �|���S���𐬂����_���W�̍ŏ��l
	VECTOR					MaxPosition ;						// �|���S���𐬂����_���W�̍ő�l
} MV1_REF_POLYGON ;

// �Q�Ɨp�|���S���f�[�^�\����
typedef struct tagMV1_REF_POLYGONLIST
{
	int						PolygonNum ;						// �Q�Ɨp�|���S���̐�
	int						VertexNum ;							// ���_�̐�
	VECTOR					MinPosition ;						// ���_���W�̍ŏ��l
	VECTOR					MaxPosition ;						// ���_���W�̍ő�l
	MV1_REF_POLYGON	*		Polygons ;							// �Q�Ɨp�|���S���z��
	MV1_REF_VERTEX *		Vertexs ;							// �Q�Ɨp���_�z��
} MV1_REF_POLYGONLIST ;

#endif // DX_NOTUSE_DRAWFUNCTION






// �X�g���[���f�[�^����p�֐��|�C���^�\���̃^�C�v�Q
typedef struct tagSTREAMDATASHREDTYPE2
{
	DWORD_PTR				(*Open		)( const TCHAR *Path, int UseCacheFlag, int BlockReadFlag, int UseASyncReadFlag ) ;
	int						(*Close		)( DWORD_PTR Handle ) ;
	long					(*Tell		)( DWORD_PTR Handle ) ;
	int						(*Seek		)( DWORD_PTR Handle, long SeekPoint, int SeekType ) ;
	size_t					(*Read		)( void *Buffer, size_t BlockSize, size_t DataNum, DWORD_PTR Handle ) ;
	int						(*Eof		)( DWORD_PTR Handle ) ;
	int						(*IdleCheck	)( DWORD_PTR Handle ) ;
	int						(*ChDir		)( const TCHAR *Path ) ;
	int						(*GetDir	)( TCHAR *Buffer ) ;
	DWORD_PTR				(*FindFirst	)( const TCHAR *FilePath, FILEINFO *Buffer ) ;		// �߂�l: -1=�G���[  -1�ȊO=FindHandle
	int						(*FindNext	)( DWORD_PTR FindHandle, FILEINFO *Buffer ) ;			// �߂�l: -1=�G���[  0=����
	int						(*FindClose	)( DWORD_PTR FindHandle ) ;							// �߂�l: -1=�G���[  0=����
} STREAMDATASHREDTYPE2 ;

// �X�g���[���f�[�^����p�֐��|�C���^�\����
typedef struct tagSTREAMDATASHRED
{
	long					(*Tell		)( void *StreamDataPoint ) ;
	int						(*Seek		)( void *StreamDataPoint, long SeekPoint, int SeekType ) ;
	size_t					(*Read		)( void *Buffer, size_t BlockSize, size_t DataNum, void *StreamDataPoint ) ;
//	size_t					(*Write		)( void *Buffer, size_t BlockSize, size_t DataNum, void *StreamDataPoint ) ;
	int						(*Eof		)( void *StreamDataPoint ) ;
	int						(*IdleCheck	)( void *StreamDataPoint ) ;
	int						(*Close		)( void *StreamDataPoint ) ;
} STREAMDATASHRED, *LPSTREAMDATASHRED ;

// �X�g���[���f�[�^����p�f�[�^�\����
typedef struct tagSTREAMDATA
{
	STREAMDATASHRED			ReadShred ;
	void					*DataPoint ;
} STREAMDATA ;




#ifndef DX_NOTUSE_DRAWFUNCTION

// �p���b�g���\����
typedef struct tagCOLORPALETTEDATA
{
	unsigned char			Blue ;
	unsigned char			Green ;
	unsigned char			Red ;
	unsigned char			Alpha ;
} COLORPALETTEDATA ;

// �J���[�\�����\����
typedef struct tagCOLORDATA
{
	unsigned char			Format ;										// �t�H�[�}�b�g( DX_BASEIMAGE_FORMAT_NORMAL �� )

	unsigned char			ChannelNum ;									// �`�����l����
	unsigned char			ChannelBitDepth ;								// �P�`�����l���ӂ�̃r�b�g�[�x
	unsigned char			FloatTypeFlag ;									// ���������_�^���ǂ���( TRUE:���������_�^  FALSE:�����^ )
	unsigned char			PixelByte ;										// �P�s�N�Z��������̃o�C�g��

	// �ȉ��� ChannelNum ���� ChannelBitDepth �� 0 �̎��̂ݗL��
	unsigned char			ColorBitDepth ;									// �r�b�g�[�x
	unsigned char			NoneLoc, NoneWidth ;							// �g���Ă��Ȃ��r�b�g�̃A�h���X�ƕ�
	unsigned char			RedWidth, GreenWidth, BlueWidth, AlphaWidth ;	// �e�F�̃r�b�g��
	unsigned char			RedLoc	, GreenLoc  , BlueLoc  , AlphaLoc   ;	// �e�F�̔z�u����Ă���r�b�g�A�h���X
	unsigned int			RedMask , GreenMask , BlueMask , AlphaMask  ;	// �e�F�̃r�b�g�}�X�N
	unsigned int			NoneMask ;										// �g���Ă��Ȃ��r�b�g�̃}�X�N
	COLORPALETTEDATA		Palette[ 256 ] ;								// �p���b�g( ColorBitDepth ���W�ȉ��̏ꍇ�̂ݗL�� )
} COLORDATA, *LPCOLORDATA ;

// ��{�C���[�W�f�[�^�\����
typedef struct tagBASEIMAGE
{
	COLORDATA				ColorData ;							// �F���
	int						Width, Height, Pitch ;				// ���A�����A�s�b�`
	void					*GraphData ;						// �O���t�B�b�N�C���[�W
	int						MipMapCount ;						// �~�b�v�}�b�v�̐�
} BASEIMAGE, GRAPHIMAGE, *LPGRAPHIMAGE ;

// ���C���f�[�^�^
typedef struct tagLINEDATA
{
	int						x1, y1, x2, y2 ;					// ���W
	int						color ;								// �F
	int						pal ;								// �p�����[�^
} LINEDATA, *LPLINEDATA ;

// ���W�f�[�^�^
typedef struct tagPOINTDATA
{
	int						x, y ;								// ���W
	int						color ;								// �F
	int						pal ;								// �p�����[�^
} POINTDATA, *LPPOINTDATA ;

// �C���[�W�t�H�[�}�b�g�f�[�^
typedef struct tagIMAGEFORMATDESC
{
	unsigned char			TextureFlag ;					// �e�N�X�`�����A�t���O( TRUE:�e�N�X�`��  FALSE:�W���T�[�t�F�X )
	unsigned char			AlphaChFlag ;					// ���`�����l���͂��邩�A�t���O	( TRUE:����  FALSE:�Ȃ� )
	unsigned char			DrawValidFlag ;					// �`��\���A�t���O( TRUE:�\  FALSE:�s�\ )
	unsigned char			SystemMemFlag ;					// �V�X�e����������ɑ��݂��Ă��邩�A�t���O( TRUE:�V�X�e����������  FALSE:�u�q�`�l�� )( �W���T�[�t�F�X�̎��̂ݗL�� )
	unsigned char			UseManagedTextureFlag ;			// �}�l�[�W�h�e�N�X�`�����g�p���邩�A�t���O

	unsigned char			BaseFormat ;					// ��{�t�H�[�}�b�g( DX_BASEIMAGE_FORMAT_NORMAL �� )
	unsigned char			MipMapCount ;					// �~�b�v�}�b�v�̐�
	unsigned char			AlphaTestFlag ;					// ���e�X�g�`�����l���͂��邩�A�t���O( TRUE:����  FALSE:�Ȃ� )( �e�N�X�`���̏ꍇ�̂ݗL�� )
	unsigned char			FloatTypeFlag ;					// ���������_�^���ǂ���
	unsigned char			ColorBitDepth ;					// �F�[�x( �e�N�X�`���̏ꍇ�̂ݗL�� )
	unsigned char			ChannelNum ;					// �`�����l���̐�
	unsigned char			ChannelBitDepth ;				// �P�`�����l���ӂ�̃r�b�g�[�x( �e�N�X�`���̏ꍇ�̂ݗL���A0 �̏ꍇ�� ColorBitDepth ���g�p����� )
	unsigned char			BlendGraphFlag ;				// �u�����h�p�摜���A�t���O
	unsigned char			UsePaletteFlag ;				// �p���b�g���g�p���Ă��邩�A�t���O( SystemMemFlag �� TRUE �̏ꍇ�̂ݗL�� )

	unsigned char			MSSamples ;						// �}���`�T���v�����O��( �`��Ώۂ̏ꍇ�g�p )
	unsigned char			MSQuality ;						// �}���`�T���v�����O�N�I���e�B( �`��Ώۂ̏ꍇ�g�p )
} IMAGEFORMATDESC ;

#endif // DX_NOTUSE_DRAWFUNCTION

// DirectInput �̃W���C�p�b�h���͏��
typedef struct tagDINPUT_JOYSTATE
{
	int						X ;								// �X�e�B�b�N�̂w���p�����[�^( -1000�`1000 )
	int						Y ;								// �X�e�B�b�N�̂x���p�����[�^( -1000�`1000 )
	int						Z ;								// �X�e�B�b�N�̂y���p�����[�^( -1000�`1000 )
	int						Rx ;							// �X�e�B�b�N�̂w����]�p�����[�^( -1000�`1000 )
	int						Ry ;							// �X�e�B�b�N�̂x����]�p�����[�^( -1000�`1000 )
	int						Rz ;							// �X�e�B�b�N�̂y����]�p�����[�^( -1000�`1000 )
	int						Slider[ 2 ] ;					// �X���C�_�[���
	unsigned int			POV[ 4 ] ;						// �n�b�g�X�C�b�`�S��( -1:���͂Ȃ� 0:�� 4500:�E�� 9000:�E 13500:�E�� 18000:�� 22500:���� 27000:�� 31500:���� )
	unsigned char			Buttons[ 32 ] ;					// �{�^���R�Q��( �����ꂽ�{�^���� 128 �ɂȂ� )
} DINPUT_JOYSTATE ;







// WinSockets�g�p���̃A�h���X�w��p�\����
typedef struct tagIPDATA
{
	unsigned char			d1, d2, d3, d4 ;				// �A�h���X�l
} IPDATA, *LPIPDATA ;

typedef struct tagIPDATA_IPv6
{
	union
	{
		unsigned char			Byte[ 16 ] ;
		unsigned short			Word[ 8 ] ;
	} ;
} IPDATA_IPv6 ;

#define DX_STRUCT_END

}

// �֐��v���g�^�C�v�錾------------------------------------------------------------------

namespace DxLib
{

#define DX_FUNCTION_START

// DxSystem.cpp�֐��v���g�^�C�v�錾

// �������I���n�֐�
extern	int			DxLib_Init( void ) ;													// ���C�u�������������s��
extern	int			DxLib_End( void ) ;														// ���C�u�����g�p�̌�n�����s��

extern	int			DxLib_GlobalStructInitialize( void ) ;									// ���C�u�����̓����Ŏg�p���Ă���\���̂��[�����������āADxLib_Init �̑O�ɍs�����ݒ�𖳌�������( DxLib_Init �̑O�ł̂ݗL�� )
extern	int			DxLib_IsInit( void ) ;													// ���C�u����������������Ă��邩�ǂ������擾����( �߂�l: TRUE=����������Ă���  FALSE=����Ă��Ȃ� )

// ���b�Z�[�W�����֐�
extern	int			ProcessMessage( void ) ;												// �E�C���h�E�Y�̃��b�Z�[�W���[�v�ɑ��鏈�����s��

// �E�G�C�g�n�֐�
extern	int			WaitTimer( int WaitTime ) ;												// �w��̎��Ԃ����������Ƃ߂�
#ifndef DX_NON_INPUT
extern	int			WaitKey( void ) ;														// �L�[�̓��͑҂����s��
#endif // DX_NON_INPUT

// �J�E���^�y�ю����擾�n�֐�
extern	int			GetNowCount(				int UseRDTSCFlag = FALSE ) ;				// �~���b�P�ʂ̐��x�����J�E���^�̌��ݒl�𓾂�
extern	LONGLONG	GetNowHiPerformanceCount(	int UseRDTSCFlag = FALSE ) ;				// GetNowCount�̍����x�o�[�W����
extern	int			GetDateTime(				DATEDATA *DateBuf ) ;						// ���ݎ������擾���� 

// �����擾
extern	int			GetRand( int RandMax ) ;												// �������擾����( RandMax : �Ԃ��ė���l�̍ő�l )
extern	int			SRand(	 int Seed ) ;													// �����̏����l��ݒ肷��








// DxLog.cpp�֐��v���g�^�C�v�錾

#ifndef DX_NON_LOG
// �G���[�����֐�
extern	int			ErrorLogAdd(		 const TCHAR *ErrorStr ) ;							// ���O�t�@�C��( Log.txt ) �ɕ�������o�͂���
extern 	int			ErrorLogFmtAdd(		 const TCHAR *FormatString , ... ) ;				// �����t���� ���O�t�@�C��( Log.txt ) �ɕ�������o�͂���( ������ printf �Ɠ��� )
extern	int			ErrorLogTabAdd(		 void ) ;											// ���O�t�@�C��( Log.txt ) �ɏo�͂��镶����̑O�ɕt����^�u�̐�������₷
extern	int			ErrorLogTabSub(		 void ) ;											// ���O�t�@�C��( Log.txt ) �ɏo�͂��镶����̑O�ɕt����^�u�̐�������炷
extern	int			SetUseTimeStampFlag( int UseFlag ) ;									// ���O�t�@�C��( Log.txt ) �ɏo�͂��镶����̑O�ɋN�����Ă���̎��Ԃ�t���邩�ǂ�����ݒ肷��( TRUE:�t����( �f�t�H���g)  FALSE:�t���Ȃ� )
extern 	int			AppLogAdd(			 const TCHAR *String , ... ) ;						// ErrorLogFmtAdd �Ɠ����@�\

#ifndef DX_NON_PRINTF_DX

// ���O�o�͋@�\�֐�
extern	int			SetLogDrawOutFlag(	 int DrawFlag ) ;									// printfDx �̌��ʂ���ʂɏo�͂��邩�ǂ�����ݒ肷��ATRUE:�o�͂��s��  FALSE:�o�͂��s��Ȃ�( printfDx �����s����Ɠ����� SetLogDrawOutFlag( TRUE ) ; ���Ă΂�܂� )
extern 	int			GetLogDrawFlag(		 void ) ;											// printfDx �̌��ʂ���ʂɏo�͂��邩�ǂ����̐ݒ���擾����( �߂�l  TRUE:�o�͂��s��  FALSE:�o�͂��s��Ȃ� )
extern	int			SetLogFontSize(		 int Size ) ;										// printfDx �̌��ʂ���ʂɏo�͂���ۂɎg�p����t�H���g�̃T�C�Y��ݒ肷��

// �ȈՉ�ʏo�͊֐�
extern 	int			printfDx(			 const TCHAR *FormatString , ... ) ;				// printf �Ɠ��������ŉ�ʂɕ������\�����邽�߂̊֐�
extern	int			clsDx(				 void ) ;											// printfDx �̌��ʂ����Z�b�g���邽�߂̊֐�
#endif // DX_NON_PRINTF_DX

#endif // DX_NON_LOG












#ifndef DX_NON_ASYNCLOAD

// DxASyncLoad.cpp�֐��v���g�^�C�v�錾

// �񓯊��ǂݍ��݊֌W
extern	int			SetUseASyncLoadFlag(		int Flag ) ;								// �ǂݍ��ݏ����n�̊֐��Ŕ񓯊��ǂݍ��݂��s�����ǂ�����ݒ肷��( �񓯊��ǂݍ��݂ɑΉ����Ă���֐��̂ݗL�� )( TRUE:�񓯊��ǂݍ��݂��s��  FALSE:�񓯊��ǂݍ��݂��s��Ȃ�( �f�t�H���g ) )
extern	int			CheckHandleASyncLoad(		int Handle ) ;								// �n���h���̔񓯊��ǂݍ��݂��������Ă��邩�ǂ������擾����( TRUE:�܂��������Ă��Ȃ�  FALSE:�������Ă���  -1:�G���[ )
extern	int			GetHandleASyncLoadResult(	int Handle ) ;								// �n���h���̔񓯊��ǂݍ��ݏ����̖߂�l���擾����( �񓯊��ǂݍ��ݒ��̏ꍇ�͈�O�̔񓯊��ǂݍ��ݏ����̖߂�l���Ԃ��Ă��܂� )
extern	int			GetASyncLoadNum(			void ) ;									// �񓯊��ǂݍ��ݒ��̏����̐����擾����

#endif // DX_NON_ASYNCLOAD










// DxWindow.cpp�֐��v���g�^�C�v�錾

#ifdef __WINDOWS__

// �֗��֐�
extern	int			GetResourceInfo(		const TCHAR *ResourceName , const TCHAR *ResourceType , void **DataPointerP , int *DataSizeP ) ;		// �w��̖��O�A�^�C�v�̃��\�[�X�̃A�h���X�ƃT�C�Y���擾����( �߂�l  -1:���s  0:���� )
extern	TCHAR*		GetResourceIDString(	int ResourceID ) ;																						// ���\�[�X�h�c�l���烊�\�[�X�����擾����

// �E�C���h�E�֌W���擾�֐�
extern	int			GetWindowCRect(					RECT *RectBuf ) ;										// ���C���E�C���h�E�̃N���C�A���g�̈���擾����
extern	int			GetWindowActiveFlag(			void ) ;												// ���C���E�C���h�E���A�N�e�B�u���ǂ������擾����( �߂�l  TRUE:�A�N�e�B�u  FALSE:��A�N�e�B�u )
extern	int			GetActiveFlag(					void ) ;												// GetWindowActiveFlag �̕ʖ��֐�
extern	HWND		GetMainWindowHandle(			void ) ;												// ���C���E�C���h�E�̃E�C���h�E�n���h�����擾����
extern	int			GetWindowModeFlag(				void ) ;												// �E�C���h�E���[�h�ŋN�����Ă��邩�ǂ������擾����( �߂�l  TRUE:�E�C���h�E���[�h  FALSE:�t���X�N���[�����[�h )
extern	int			GetDefaultState(				int *SizeX , int *SizeY , int *ColorBitDepth ) ;		// �N�����̃f�X�N�g�b�v�̉�ʏ����擾����( SizeX:�f�X�N�g�b�v�̉��𑜓x���i�[����ϐ��̃|�C���^  SizeY:�c�𑜓x���i�[����ϐ��̃|�C���^  ColorBitDepth:��ʃJ���[�r�b�g�����i�[����ϐ��̃|�C���^ )
extern	int			GetNoActiveState(				int ResetFlag = TRUE ) ;								// ���C���E�C���h�E����A�N�e�B�u�ɂȂ�A�������ꎞ��~���Ă������ǂ������擾����(���� ResetFlag=TRUE:��Ԃ����Z�b�g FALSE:��Ԃ����Z�b�g���Ȃ�    �߂�l: 0=�ꎞ��~�͂��Ă��Ȃ�  1=�ꎞ��~���Ă��� )
extern	int			GetMouseDispFlag(				void ) ;												// �}�E�X�|�C���^��\�����邩�ǂ����̐ݒ���擾����( �߂�l  TRUE:�\������  FALSE:�\�����Ȃ� )
extern	int			GetAlwaysRunFlag(				void ) ;												// ���C���E�C���h�E����A�N�e�B�u�ɂȂ��Ă����������s�������邩�ǂ����̐ݒ���擾����( TRUE:���s����  FALSE:��~���� )
extern	int			_GetSystemInfo(					int *DxLibVer , int *DirectXVer , int *WindowsVer ) ;	// �c�w���C�u������ DirectX �̃o�[�W������ Windows �̃o�[�W�����ԍ����擾����
extern	int			GetPcInfo(						TCHAR *OSString , TCHAR *DirectXString , TCHAR *CPUString , int *CPUSpeed /* �P��MHz */ , double *FreeMemorySize /* �P��MByte */ , double *TotalMemorySize , TCHAR *VideoDriverFileName , TCHAR *VideoDriverString , double *FreeVideoMemorySize /* �P��MByte */ , double *TotalVideoMemorySize ) ;	// �o�b�̏����擾����
extern	int			GetUseMMXFlag(					void ) ;												// �l�l�w���g���邩�ǂ����̏��𓾂�
extern	int			GetUseSSEFlag(					void ) ;												// �r�r�d���g���邩�ǂ����̏��𓾂�
extern	int			GetUseSSE2Flag(					void ) ;												// �r�r�d�Q���g���邩�ǂ����̏��𓾂�
extern	int			GetWindowCloseFlag(				void ) ;												// �E�C���h�E����悤�Ƃ��Ă��邩�̏��𓾂�
extern	HINSTANCE	GetTaskInstance(				void ) ;												// �\�t�g�̃C���X�^���X���擾����
extern	int			GetUseWindowRgnFlag(			void ) ;												// ���[�W�������g���Ă��邩�ǂ������擾����
extern	int			GetWindowSizeChangeEnableFlag(	int *FitScreen = NULL ) ;								// �E�C���h�E�̃T�C�Y��ύX�ł���ݒ�ɂȂ��Ă��邩�ǂ������擾����( �߂�l  TRUE:�ύX�ł���悤�ɂȂ��Ă���  FALSE:�ύX�ł��Ȃ��悤�ɂȂ��Ă��� )
extern	double		GetWindowSizeExtendRate(		double *ExRateX = NULL , double *ExRateY = NULL ) ;		// �`���ʂ̃T�C�Y�ɑ΂���E�C���h�E�T�C�Y�̔䗦���擾����( �߂�l�� ExRateX �ɑ�������l�Ɠ����ł� )
extern	int			GetWindowSize(					int *Width, int *Height ) ;								// ���C���E�C���h�E�̃N���C�A���g�̈�̃T�C�Y���擾����
extern	int			GetWindowPosition(				int *x, int *y ) ;										// ���C���E�C���h�E�̃f�X�N�g�b�v��̍���[���W���擾����( �g���܂߂� )
extern	int			GetWindowUserCloseFlag(			int StateResetFlag = FALSE ) ;							// ���C���E�C���h�E�̕���{�^���������ꂽ���ǂ������擾����
extern	int			GetNotDrawFlag(					void ) ;												// �c�w���C�u�����̕`��@�\���g�����ǂ����̐ݒ���擾����
extern	int			GetPaintMessageFlag(			void ) ;												// WM_PAINT ���b�Z�[�W���������ǂ������擾����(�߂�l  TRUE:WM_PAINT���b�Z�[�W������(��x�擾����ƈȌ�A�Ă� WM_PAINT���b�Z�[�W������܂� FALSE ���Ԃ��Ă���悤�ɂȂ�)  FALSE:WM_PAINT ���b�Z�[�W�͗��Ă��Ȃ�)
extern	int			GetValidHiPerformanceCounter(	void ) ;												// �p�t�H�[�}���X�J�E���^���L�����ǂ������擾����(�߂�l  TRUE:�L��  FALSE:����)

// �ݒ�n�֐�
extern	int			ChangeWindowMode(						int Flag ) ;																		// �E�C���h�E���[�h��ύX����
extern	int			SetUseCharSet(							int CharSet /* = DX_CHARSET_SHFTJIS �� */ ) ;										// �c�w���C�u�����̕����񏈗��őO��Ƃ��镶����Z�b�g��ݒ肷��
extern	int			LoadPauseGraph(							const TCHAR *FileName ) ;															// �A�N�e�B�u�E�C���h�E�����̃\�t�g�Ɉڂ��Ă���ۂɕ\������摜���t�@�C������ǂݍ���( FileName �� NULL ��n�����Ƃŉ���)
extern	int			LoadPauseGraphFromMem(					void *MemImage , int MemImageSize ) ;												// �A�N�e�B�u�E�C���h�E�����̃\�t�g�Ɉڂ��Ă���ۂɕ\������摜������������ǂݍ���( MemImage:�t�@�C���C���[�W�̐擪�A�h���X,NULL �ɂ��邱�ƂŐݒ����  MemImageSize:�t�@�C���C���[�W�̃T�C�Y( �P��:Byte ) )
extern	int			SetActiveStateChangeCallBackFunction(	int (* CallBackFunction )( int ActiveState , void *UserData ) , void *UserData ) ;	// ���C���E�C���h�E�̃A�N�e�B�u��Ԃɕω����������Ƃ��ɌĂ΂��R�[���o�b�N�֐���ݒ肷��( CallBackFunction:�Ă΂��R�[���o�b�N�֐��ANULL ��n���Ɛݒ����  UserData:CallBackFunction �̑�Q�����ɓn�����l )
extern	int			SetWindowText(							const TCHAR *WindowText ) ;															// ���C���E�C���h�E�̃E�C���h�E�e�L�X�g��ύX����
extern	int			SetMainWindowText(						const TCHAR *WindowText ) ;															// SetWindowText �̕ʖ��֐�
extern	int			SetMainWindowClassName(					const TCHAR *ClassName ) ;															// ���C���E�C���h�E�̃N���X����ݒ肷��( DxLib_Init �̑O�ł̂ݎg�p�\ )
#ifndef DX_NON_LOG
extern	int			SetOutApplicationLogValidFlag(			int Flag ) ;																		// ���O�t�@�C��( Log.txt ) ���쐬���邩�ǂ�����ݒ肷��( TRUE:�쐬����( �f�t�H���g )  FALSE:�쐬���Ȃ� )�ADxLib_Init �̑O�ł̂ݎg�p�\
extern	int			SetApplicationLogSaveDirectory(			const TCHAR *DirectoryPath ) ;														// ���O�t�@�C��( Log.txt ) ��ۑ�����f�B���N�g���p�X��ݒ肷��
extern	int			SetUseDateNameLogFile(					int Flag ) ;																		// ���O�t�@�C�����ɓ��t�����邩�ǂ������Z�b�g����( TRUE:�t����  FALSE:�t���Ȃ�( �f�t�H���g ) )
#endif // DX_NON_LOG
extern	int			SetAlwaysRunFlag(						int Flag ) ;																		// ���C���E�C���h�E����A�N�e�B�u��Ԃł����������s���邩�ǂ�����ݒ肷��( TRUE:���s����  FALSE:��~����( �f�t�H���g ) )
extern	int			SetWindowIconID(						int ID ) ;																			// ���C���E�C���h�E�Ŏg�p����A�C�R���̂h�c���Z�b�g����
extern	int			SetWindowIconHandle(					HICON Icon ) ;																		// ���C���E�C���h�E�Ŏg�p����A�C�R���̃n���h�����Z�b�g����
extern	int			SetUseASyncChangeWindowModeFunction(	int Flag , void (* CallBackFunction )( void * ) , void *Data ) ;					// �ő剻�{�^����ALT+ENTER�L�[�ɂ��񓯊��ȃE�C���h�E���[�h�̕ύX�̋@�\�̐ݒ���s��( Flag:�񓯊��E�C���h�E���[�h�ύX��L���ɂ��邩�ǂ����̃t���O( TRUE:�L���ɂ���  FALSE:�����ɂ���( �f�t�H���g ) )   CallBackFunction:�񓯊��E�C���h�E���[�h�ύX���s��ꂽ�ꍇ�ɌĂ΂��R�[���o�b�N�֐��̃A�h���X   Data:CallBackFunction �̈����ɓn����� void �^�̃|�C���^ )
extern	int			SetWindowStyleMode(						int Mode ) ;																		// ���C���E�C���h�E�̃X�^�C����ύX����
extern	int			SetWindowSizeChangeEnableFlag(			int Flag, int FitScreen = TRUE ) ;													// ���C���E�C���h�E�̒[��͂�ŃE�C���h�E�̃T�C�Y��ύX�ł���悤�ɂ��邩�ǂ����̐ݒ���s��( Flag:�ύX���\�ɂ��邩�ǂ���( TRUE:�\�ɂ���  FALSE:�s�\�ɂ���( �f�t�H���g ) )  FitScreen:�E�C���h�E�̃N���C�A���g�̈�ɉ�ʂ��t�B�b�g������(�g�傳����)���ǂ���  TRUE:�t�B�b�g������  FALSE:�t�B�b�g�����Ȃ� )
extern	int			SetWindowSizeExtendRate(				double ExRateX, double ExRateY = -1.0 ) ;											// �`���ʂ̃T�C�Y�ɑ΂��郁�C���E�C���h�E�T�C�Y�̔䗦��ݒ肷��( ExRateY ���}�C�i�X�̏ꍇ�� ExRateX �̒l�� ExRateY �ɂ��g�p����܂� )
extern	int			SetWindowSize(							int Width, int Height ) ;															// ���C���E�C���h�E�̃N���C�A���g�̈�̃T�C�Y��ݒ肷��
extern	int			SetWindowPosition(						int x, int y ) ;																	// ���C���E�C���h�E�̈ʒu��ݒ肷��( �g���܂߂�������W )
extern	int			SetSysCommandOffFlag(					int Flag , const TCHAR *HookDllPath = NULL ) ;										// �^�X�N�X�C�b�`��L���ɂ��邩�ǂ�����ݒ肷��
extern	int			SetHookWinProc(							WNDPROC WinProc ) ;																	// ���C���E�C���h�E�ւ̃��b�Z�[�W���t�b�N����E�C���h�E�v���[�W����o�^����
extern	int			SetUseHookWinProcReturnValue(			int UseFlag ) ;																		// SetHookWinProc �Őݒ肵���E�C���h�E�v���[�W���̖߂�l���g�p���邩�ǂ�����ݒ肷��ASetHookWinProc �Őݒ肵���E�C���h�E�v���[�W���̒��ł̂ݎg�p�\( UseFlag TRUE:�߂�l���g�p���āA�c�w���C�u�����̃E�C���h�E�v���[�W���̏����͍s��Ȃ�  FALSE:�߂�l�͎g�p�����A�E�C���h�E�v���[�W������o����A�c�w���C�u�����̃E�C���h�E�v���[�W���̏������s�� )
extern	int			SetDoubleStartValidFlag(				int Flag ) ;																		// �c�w���C�u�������g�p�����\�t�g�̓�d�N�����\�ɂ��邩�ǂ����̐ݒ���s��( TRUE:�\�ɂ���  FALSE:�s�\�ɂ���( �f�t�H���g ) )
extern	int			AddMessageTakeOverWindow(				HWND Window ) ;																		// ���b�Z�[�W�������c�w���C�u�����Ɍ����肵�Ă��炤�E�C���h�E��ǉ�����
extern	int			SubMessageTakeOverWindow(				HWND Window ) ;																		// ���b�Z�[�W�������c�w���C�u�����Ɍ����肵�Ă��炤�E�C���h�E�����炷

extern	int			SetWindowInitPosition(					int x , int y ) ;																	// ���C���E�C���h�E�̏����ʒu��ݒ肷��
extern	int			SetNotWinFlag(							int Flag ) ;																		// �c�w���C�u�����̃E�C���h�E�֘A�̋@�\���g�p���Ȃ����ǂ�����ݒ肷��( TRUE:�g�p���Ȃ�  FALSE:�g�p����( �f�t�H���g ) )
extern	int			SetNotDrawFlag(							int Flag ) ;																		// �c�w���C�u�����̕`��@�\���g�����ǂ�����ݒ肷��( TRUE:�g�p���Ȃ�  FALSE:�g�p����( �f�t�H���g ) )
extern	int			SetNotSoundFlag(						int Flag ) ;																		// �c�w���C�u�����̃T�E���h�@�\���g�����ǂ�����ݒ肷��( TRUE:�g�p���Ȃ�  FALSE:�g�p����( �f�t�H���g ) )
extern	int			SetNotInputFlag(						int Flag ) ;																		// �c�w���C�u�����̓��͏�Ԃ̎擾�@�\���g�����ǂ�����ݒ肷��( TRUE:�g�p���Ȃ�  FALSE:�g�p����( �f�t�H���g ) )
extern	int			SetDialogBoxHandle(						HWND WindowHandle ) ;																// �c�w���C�u�����Ń��b�Z�[�W�������s���_�C�A���O�{�b�N�X��o�^����
extern	int			SetWindowVisibleFlag(					int Flag ) ;																		// ���C���E�C���h�E��\�����邩�ǂ�����ݒ肷��( TRUE:�\������  FALSE:�\�����Ȃ� )
extern	int			SetWindowMinimizeFlag(					int Flag ) ;																		// ���C���E�C���h�E���ŏ������邩�ǂ�����ݒ肷��( TRUE:�ŏ�������  FALSE:�ŏ��������� )
extern	int			SetWindowUserCloseEnableFlag(			int Flag ) ;																		// ���C���E�C���h�E�́~�{�^�������������ɂc�w���C�u�����������I�ɃE�C���h�E����邩�ǂ�����ݒ肷��( TRUE:�����I�ɕ���( �f�t�H���g )  FALSE:���Ȃ� )
extern	int			SetDxLibEndPostQuitMessageFlag(			int Flag ) ;																		// �c�w���C�u�����I������ PostQuitMessage ���ĂԂ��ǂ�����ݒ肷��( TRUE:PostQuitMessage ���Ă�( �f�t�H���g )  FALSE:�Ă΂Ȃ� )
extern	int			SetUserWindow(							HWND WindowHandle ) ;																// �c�w���C�u�����Ŏg�p����E�C���h�E�̃n���h�����Z�b�g����( DxLib_Init �����s����ȑO�ł̂ݗL�� )
extern	int			SetUserChildWindow(						HWND WindowHandle ) ;																// �c�w���C�u�����Ŏg�p����\���p�̎q�E�C���h�E�̃n���h�����Z�b�g����( DxLib_Init �����s����ȑO�ł̂ݗL�� )
extern	int			SetUserWindowMessageProcessDXLibFlag(	int Flag ) ;																		// SetUseWindow �Őݒ肵���E�C���h�E�̃��b�Z�[�W���[�v�������c�w���C�u�����ōs�����ǂ�����ݒ肷��( TRUE:�c�w���C�u�����ōs��( �f�t�H���g )  FALSE:�c�w���C�u�����ł͍s��Ȃ� )
extern	int			SetBackgroundColor(						int Red, int Green, int Blue ) ;													// ���C���E�C���h�E�̔w�i�F��ݒ肷��( Red,Green,Blue:���ꂼ�� �O�`�Q�T�T )
extern	int			SetUseFPUPreserveFlag(					int Flag ) ;																		// FPU�̐��x�𗎂Ƃ��Ȃ��ݒ���g�p���邩�ǂ�����ݒ肷��ADxLib_Init ���Ăяo���O�̂ݗL��( TRUE:�g�p����(���x�������Ȃ�)  FALSE:�g�p���Ȃ�(���x�𗎂Ƃ�(�f�t�H���g) )
extern	int			SetValidMousePointerWindowOutClientAreaMoveFlag( int Flag ) ;																// �}�E�X�|�C���^���E�C���h�E�̃N���C�A���g�G���A�̊O�ɂ����邩�ǂ�����ݒ肷��( TRUE:������( �f�t�H���g�ݒ� )  FALSE:�����Ȃ� )
extern	int			SetUseBackBufferTransColorFlag(			int Flag ) ;																		// �o�b�N�o�b�t�@�̓��ߐF�̕����𓧉߂����邩�ǂ�����ݒ肷��( TRUE:���߂�����  FALSE:���߂����Ȃ�( �f�t�H���g ) )
extern	int			SetResourceModule(						HMODULE ResourceModule ) ;															// ���\�[�X��ǂݍ��ލۂɎg�p���郂�W���[����ݒ肷��( NULL ���w�肷��Ə�����Ԃɖ߂�܂��A�f�t�H���g�ł� NULL )

// �N���b�v�{�[�h�֌W
extern	int			GetClipboardText(			TCHAR *DestBuffer ) ;															// �N���b�v�{�[�h�Ɋi�[����Ă���e�L�X�g�f�[�^��ǂݏo��( DestBuffer:��������i�[����o�b�t�@�̐擪�A�h���X   �߂�l  -1:�N���b�v�{�[�h�Ƀe�L�X�g�f�[�^������  -1�ȊO:�N���b�v�{�[�h�Ɋi�[����Ă��镶����f�[�^�̃T�C�Y( �P��:byte ) ) 
extern	int			SetClipboardText(			const TCHAR *Text ) ;															// �N���b�v�{�[�h�Ƀe�L�X�g�f�[�^���i�[����

// �h���b�O���h���b�v���ꂽ�t�@�C���֌W
extern	int			SetDragFileValidFlag(		int Flag ) ;																	// �t�@�C���̃��C���E�C���h�E�ւ̃h���b�O���h���b�v�@�\��L���ɂ��邩�ǂ����̃t���O���Z�b�g����
extern	int			DragFileInfoClear(			void ) ;																		// ���C���E�C���h�E�փh���b�O���h���b�v���ꂽ�t�@�C���̏������Z�b�g����
extern	int			GetDragFilePath(			TCHAR *FilePathBuffer ) ;														// ���C���E�C���h�E�փh���b�O���h���b�v���ꂽ�t�@�C�������擾����( FilePathBuffer:�t�@�C�������i�[����o�b�t�@�̐擪�A�h���X�@�@�߂�l�@-1:�擾�ł��Ȃ�����  0:�擾�ł��� )
extern	int			GetDragFileNum(				void ) ;																		// ���C���E�C���h�E�փh���b�O���h���b�v���ꂽ�t�@�C���̐����擾����

// �E�C���h�E�`��̈�ݒ�n�֐�
extern	HRGN		CreateRgnFromGraph(			int Width , int Height , void *MaskData , int Pitch , int Byte ) ;				// �C�ӂ̉摜�C���[�W����RGN�n���h�����쐬����( Width:���h�b�g��  Height:�c�h�b�g��  MaskData:�h�b�g���z��̐擪�A�h���X  Pitch:�P���C���������byte�T�C�Y  Byte:�P�h�b�g�ӂ��byte�T�C�Y( �Ή����Ă���̂� 1�`4 )�A�h�b�g�̐��l��0������ȊO���Ŕ��� )
extern	HRGN		CreateRgnFromBaseImage(		BASEIMAGE *BaseImage, int TransColorR, int TransColorG, int TransColorB ) ;		// �C�ӂ̊�{�C���[�W�f�[�^�Ɠ��ߐF����RGN�n���h�����쐬����( BaseImage:��{�C���[�W�f�[�^�̃A�h���X  TransColorR,TransColorG,TransColorB:���ߐF( ���ꂼ��O�`�Q�T�T )
extern	int			SetWindowRgnGraph(			const TCHAR *FileName ) ;														// �C�ӂ̉摜�t�@�C������q�f�m���Z�b�g����
extern	int			UpdateTransColorWindowRgn(	void ) ;																		// �`���̉�ʂ̓��ߐF�̕����𓧉߂�����q�f�m���Z�b�g����( �g�p����铧�ߐF�͊֐� SetTransColor �Őݒ肵���F )

// �c�[���o�[�֌W
extern	int			SetupToolBar(				const TCHAR *BitmapName , int DivNum , int ResourceID = -1 ) ;															// �c�[���o�[�̏����ABitmapName �� NULL, ResourceID �� -1 ��n���ƃc�[���o�[������( BitmapName:�c�[���o�[�̃{�^���Ɏg�p����摜�t�@�C���p�X�AResourceID �� -1 �ȊO��n���ꍇ�� NULL �ɂ���  DivNum:�{�^���摜���̃{�^���̐�  ResourceID:�c�[���o�[�̃{�^���Ɏg�p����r�b�g�}�b�v���\�[�X�̂h�c�ABitmapName �� NULL ��n���Ƃ��̈������g�p����� )
extern	int			AddToolBarButton(			int Type /* TOOLBUTTON_TYPE_NORMAL �� */ , int State /* TOOLBUTTON_STATE_ENABLE �� */ , int ImageIndex, int ID ) ;		// �c�[���o�[�Ƀ{�^����ǉ�����( Type:�{�^���^�C�v( TOOLBUTTON_TYPE_NORMAL ��( ����� #define �̒�`���Q�Ƃ��Ă������� ) )  State:�������( TOOLBUTTON_STATE_ENABLE ��( ����� #define �̒�`���Q�Ƃ��Ă������� ) )  ImageIndex:�g�p����{�^���̉摜�ԍ�  ID:�{�^���Ɋ��蓖�Ă鎯�ʔԍ�  )
extern	int			AddToolBarSep(				void ) ;																												// �c�[���o�[�Ɍ��Ԃ�ǉ�����
extern	int			GetToolBarButtonState(		int ID ) ;																												// �c�[���o�[�̃{�^���̏�Ԃ��擾����( ID:AddToolBarButton�Őݒ肵���{�^���̎��ʔԍ��@�@�߂�l�@TRUE:������Ă��� or �����ꂽ  FALSE:������Ă��Ȃ� )
extern	int			SetToolBarButtonState(		int ID , int State /* TOOLBUTTON_STATE_ENABLE �� */ ) ;																	// �c�[���o�[�̃{�^���̏�Ԃ�ݒ肷��( ID:AddToolBarButton�Őݒ肵���{�^���̎��ʔԍ��@State:�ݒ肷����( TOOLBUTTON_STATE_ENABLE ��( ����� #define �̒�`���Q�Ƃ��Ă������� ) )
extern	int			DeleteAllToolBarButton(		void ) ;																												// �c�[���o�[�̃{�^����S�č폜����

// ���j���[�֌W
extern	int			SetUseMenuFlag(				int Flag ) ;																						// ���j���[��L���ɂ��邩�ǂ�����ݒ肷��( TRUE:�g�p����  FALSE:�g�p���Ȃ� )
extern	int			SetUseKeyAccelFlag(			int Flag ) ;																						// �L�[�{�[�h�A�N�Z�����[�^�[���g�p���邩�ǂ�����ݒ肷��( TRUE:�g�p����  FALSE:�g�p���Ȃ� )

extern	int			AddKeyAccel(				const TCHAR *ItemName , int ItemID , int KeyCode , int CtrlFlag , int AltFlag , int ShiftFlag ) ;	// �V���[�g�J�b�g�L�[��ǉ�����( ItemName:�V���[�g�J�b�g�L�[�����蓖�Ă郁�j���[�̃A�C�e����( AddMenuItem �� NewItemName �ɓn�������O )�AItemID ���g�p����ꍇ�� NULL ��n��  ItemID:���j���[���ڂ̎��ʔԍ�( AddMenuItem �̈��� NewItemID �Ŏw�肵������ )�AItemName ���g�p����ꍇ�� -1 ��n��  KeyCode:�V���[�g�J�b�g�L�[�̃L�[( KEY_INPUT_L �� )  CtrlFlag:������CTRL�L�[�������K�v������悤�ɂ��邩�ǂ���( TRUE:�����K�v������  FALSE:�����Ȃ��Ă��ǂ� )  AltFlag:������ALT�L�[�������K�v������悤�ɂ��邩�ǂ���( TRUE:�����K�v������  FALSE:�����Ȃ��Ă��ǂ� )  ShiftFlag:������SHIFT�L�[�������K�v������悤�ɂ��邩�ǂ���( TRUE:�����K�v������  FALSE:�����Ȃ��Ă��ǂ� )
extern	int			AddKeyAccel_Name(			const TCHAR *ItemName , int KeyCode , int CtrlFlag , int AltFlag , int ShiftFlag ) ;				// �V���[�g�J�b�g�L�[��ǉ�����( �e�����̉���� AddKeyAccel �Ɠ����AItemID �������Ȃ������� )
extern	int			AddKeyAccel_ID(				int ItemID, int KeyCode, int CtrlFlag, int AltFlag, int ShiftFlag ) ;								// �V���[�g�J�b�g�L�[��ǉ�����( �e�����̉���� AddKeyAccel �Ɠ����AItemName �������Ȃ������� )
extern	int			ClearKeyAccel(				void ) ;																							// �V���[�g�J�b�g�L�[�̏������Z�b�g����

extern	int			AddMenuItem(				int AddType /* MENUITEM_ADD_CHILD�� */ , const TCHAR *ItemName, int ItemID, int SeparatorFlag, const TCHAR *NewItemName = NULL , int NewItemID = -1 ) ;	// ���j���[�ɍ��ڂ�ǉ�����( AddType:���ڃ^�C�v( MENUITEM_ADD_CHILD ��( ����� #define �̒�`���Q�Ƃ��Ă������� ) )    ItemName:AddType �� MENUITEM_ADD_CHILD�̏ꍇ�͐e�ƂȂ鍀�ڂ̖��O�AMENUITEM_ADD_INSERT�̏ꍇ�͑}���ʒu�ƂȂ鍀�ڂ̖��O�ANULL ���w�肷��� ItemID ���g�p�����   ItemID:ItemName �̑���Ɏ��ʔԍ��Ŏw�肷����́AAddType���̈Ⴂ�� ItemName �̉���̒ʂ�A-1���w�肷��� ItemName ���g�p�����@�@SeparatorFlag:��؂����ǉ����邩�ǂ���( TRUE:��؂����ǉ��A���̏ꍇ NewItemName �� NewItemID �͖��������  FALSE:�ǉ�����̂͋�؂���ł͂Ȃ� )�@�@NewItemName:�V�������ڂ̖��O  NewItemID:�V�������ڂ̎��ʔԍ��A-1���w�肷��Ɠ����œK���Ȕԍ������蓖�Ă��� )
extern	int			DeleteMenuItem(				const TCHAR *ItemName, int ItemID ) ;																// ���j���[����I�����ڂ��폜����( ItemName:�폜���鍀�ڂ̖��O( AddMenuItem �� NewItemName �ɓn�������O )�ANULL ���w�肷��� ItemID ���g�p�����  ItemID:�폜���鍀�ڂ̎��ʔԍ�( AddMenuItem �� NewItemID �ɓn�����ԍ� )�A-1 ���w�肷��� ItemName ���g�p����� )
extern	int			CheckMenuItemSelect(		const TCHAR *ItemName, int ItemID ) ;																// ���j���[���I�����ꂽ���ǂ������擾����( �߂�l�@ 0:�I������Ă��Ȃ�  1:�I�����ꂽ   ItemName �� ItemID �ɂ��Ă͊֐� DeleteMenuItem �̒��߂��Q�Ƃ��Ă������� )
extern	int			SetMenuItemEnable(			const TCHAR *ItemName, int ItemID, int EnableFlag ) ;												// ���j���[�̍��ڂ�I���o���邩�ǂ�����ݒ肷��( EnableFlag:���ڂ��I���ł��邩�ǂ���( TRUE:�I���ł���   FALSE:�I���ł��Ȃ� )   ItemName �� ItemID �ɂ��Ă͊֐� DeleteMenuItem �̒��߂��Q�Ƃ��Ă������� )
extern	int			SetMenuItemMark(			const TCHAR *ItemName, int ItemID, int Mark ) ;														// ���j���[�̍��ڂɃ`�F�b�N�}�[�N�⃉�W�I�{�^����\�����邩�ǂ�����ݒ肷��( Mark:�ݒ肷��}�[�N( MENUITEM_MARK_NONE ��( ����� #define �̒�`���Q�Ƃ��Ă������� )    ItemName �� ItemID �ɂ��Ă͊֐� DeleteMenuItem �̒��߂��Q�Ƃ��Ă������� ) )
extern	int			CheckMenuItemSelectAll(		void ) ;																							// ���j���[�̍��ڂ��ǂꂩ�I�����ꂽ���ǂ������擾����( �߂�l  TRUE:�ǂꂩ�I�����ꂽ  FALSE:�I������Ă��Ȃ� )

extern	int			AddMenuItem_Name(			const TCHAR *ParentItemName, const TCHAR *NewItemName ) ;											// ���j���[�ɑI�����ڂ�ǉ�����( ParentItemName:�e�ƂȂ鍀�ڂ̖��O�A�e�������X�g�̖��[�ɐV�������ڂ�ǉ����܂�  NewItemName:�V�������ڂ̖��O )
extern	int			AddMenuLine_Name(			const TCHAR *ParentItemName ) ;																		// ���j���[�̃��X�g�ɋ�؂����ǉ�����( ParentItemName:��؂����t���鍀�ڃ��X�g�̐e�̖��O�A���X�g�̖��[�ɋ�؂����ǉ����܂� )
extern	int			InsertMenuItem_Name(		const TCHAR *ItemName, const TCHAR *NewItemName ) ;													// �w��̍��ڂƁA�w��̍��ڂ̈��̍��ڂƂ̊ԂɐV�������ڂ�ǉ�����
extern	int			InsertMenuLine_Name(		const TCHAR *ItemName ) ;																			// �w��̍��ڂƁA�w��̍��ڂ̈��̍��ڂƂ̊Ԃɋ�؂����ǉ�����
extern	int			DeleteMenuItem_Name(		const TCHAR *ItemName ) ;																			// ���j���[����I�����ڂ��폜����
extern	int			CheckMenuItemSelect_Name(	const TCHAR *ItemName ) ;																			// ���j���[���I�����ꂽ���ǂ������擾����( �߂�l�@0:�I������Ă��Ȃ�  1:�I�����ꂽ )
extern	int			SetMenuItemEnable_Name(		const TCHAR *ItemName, int EnableFlag ) ;															// ���j���[�̍��ڂ�I���o���邩�ǂ�����ݒ肷��( EnableFlag�@1:�I���ł���  0:�I���ł��Ȃ� )
extern	int			SetMenuItemMark_Name(		const TCHAR *ItemName, int Mark ) ;																	// ���j���[�̍��ڂɃ`�F�b�N�}�[�N�⃉�W�I�{�^����\�����邩�ǂ�����ݒ肷��( Mark:�ݒ肷��}�[�N( MENUITEM_MARK_NONE �� ) )

extern	int			AddMenuItem_ID(				int ParentItemID, const TCHAR *NewItemName, int NewItemID = -1 ) ;									// ���j���[�ɑI�����ڂ�ǉ�����
extern	int			AddMenuLine_ID(				int ParentItemID ) ;																				// ���j���[�̃��X�g�ɋ�؂����ǉ�����
extern	int			InsertMenuItem_ID(			int ItemID, int NewItemID ) ;																		// �w��̍��ڂƁA�w��̍��ڂ̈��̍��ڂƂ̊ԂɐV�������ڂ�ǉ�����
extern	int			InsertMenuLine_ID(			int ItemID, int NewItemID ) ;																		// �w��̍��ڂƁA�w��̍��ڂ̈��̍��ڂƂ̊Ԃɋ�؂����ǉ�����
extern	int			DeleteMenuItem_ID(			int ItemID ) ;																						// ���j���[����I�����ڂ��폜����
extern	int			CheckMenuItemSelect_ID(		int ItemID ) ;																						// ���j���[���I�����ꂽ���ǂ������擾����( �߂�l�@�@0:�I������Ă��Ȃ�  1:�I�����ꂽ )
extern	int			SetMenuItemEnable_ID(		int ItemID, int EnableFlag ) ;																		// ���j���[�̍��ڂ�I���o���邩�ǂ�����ݒ肷��( EnableFlag�@1:�I���ł���  0:�I���ł��Ȃ� )
extern	int			SetMenuItemMark_ID(			int ItemID, int Mark ) ;																			// ���j���[�̍��ڂɃ`�F�b�N�}�[�N�⃉�W�I�{�^����\�����邩�ǂ�����ݒ肷��( Mark:�ݒ肷��}�[�N( MENUITEM_MARK_NONE �� ) )

extern	int			DeleteMenuItemAll(			void ) ;																							// ���j���[�̑S�Ă̑I�����ڂ��폜����
extern	int			ClearMenuItemSelect(		void ) ;																							// ���j���[���I�����ꂽ���ǂ����̏������Z�b�g
extern	int			GetMenuItemID(				const TCHAR *ItemName ) ;																			// ���j���[�̍��ږ����獀�ڎ��ʔԍ����擾����
extern	int			GetMenuItemName(			int ItemID, TCHAR *NameBuffer ) ;																	// ���j���[�̍��ڎ��ʔԍ����獀�ږ����擾����
extern	int 		LoadMenuResource(			int MenuResourceID ) ;																				// ���j���[�����\�[�X����ǂݍ���
extern	int			SetMenuItemSelectCallBackFunction(		void (* CallBackFunction )( const TCHAR *ItemName, int ItemID ) ) ;						// ���j���[�̑I�����ڂ��I�����ꂽ�Ƃ��ɌĂ΂��R�[���o�b�N�֐���ݒ肷��( CallBackFunction:���ڂ��I�����ꂽ�Ƃ��ɌĂ΂��R�[���o�b�N�֐��A�����ɍ��ږ��ƍ��ڂ̎��ʔԍ���n����ČĂ΂�� )

extern	int			SetWindowMenu(				int MenuID, int (* MenuProc )( WORD ID ) ) ;														// (�Â��֐�)�E�C���h�E�Ƀ��j���[��ݒ肷��
extern	int			SetDisplayMenuFlag(			int Flag ) ;																						// ���j���[��\�����邩�ǂ������Z�b�g����
extern	int			GetDisplayMenuFlag(			void ) ;																							// ���j���[��\�����Ă��邩�ǂ������擾����
extern	int			GetUseMenuFlag(				void ) ;																							// ���j���[���g�p���Ă��邩�ǂ����𓾂�
extern	int			SetAutoMenuDisplayFlag(		int Flag ) ;																						// �t���X�N���[�����Ƀ��j���[�������ŕ\���������\���ɂ����肷�邩�ǂ����̃t���O���Z�b�g����

#endif // __WINDOWS__

// �}�E�X�֌W�֐�
extern	int			SetMouseDispFlag(		int DispFlag ) ;												// �}�E�X�|�C���^�̕\����Ԃ�ݒ肷��( DispFlag:�}�E�X�|�C���^��\�����邩�ǂ���( TRUE:�\������  FALSE:�\�����Ȃ� )
extern	int			GetMousePoint(			int *XBuf, int *YBuf ) ;										// �}�E�X�|�C���^�̈ʒu���擾����
extern	int			SetMousePoint(			int PointX, int PointY ) ;										// �}�E�X�|�C���^�̈ʒu��ݒ肷��
#ifndef DX_NON_INPUT
extern	int			GetMouseInput(			void ) ;														// �}�E�X�̃{�^���̉�����Ԃ��擾����
extern	int			GetMouseWheelRotVol(	int CounterReset = TRUE ) ;										// �����}�E�X�z�C�[���̉�]�ʂ��擾����
extern	int			GetMouseHWheelRotVol(	int CounterReset = TRUE ) ;										// �����}�E�X�z�C�[���̉�]�ʂ��擾����
extern	int			GetMouseInputLog(		int *Button, int *ClickX, int *ClickY, int LogDelete = TRUE ) ;	// �}�E�X�̃N���b�N������擾����( Button:�N���b�N���ꂽ�{�^��( MOUSE_INPUT_LEFT �� )���i�[����ϐ��̃A�h���X  ClickX:�N���b�N���ꂽ���̂w���W���i�[����ϐ��̃A�h���X  ClickY:�N���b�N���ꂽ���̂x���W���i�[����ϐ��̃A�h���X   LogDelete:�擾�����N���b�N����������O����폜���邩�ǂ���( TRUE:�폜����  FALSE:�폜���Ȃ��A�܂莟�ɂ��̊֐����Ă΂ꂽ�Ƃ��ɓ����l���擾���邱�ƂɂȂ� )�@�@�߂�l  0:�N���b�N���擾�ł����@-1:�N���b�N��񂪖��������A�܂�O��̌Ăяo��( �܂��͋N��������ŏ��̌Ăяo�� )�̊ԂɈ�x���}�E�X�̃{�^�����N���b�N����Ȃ����� )
#endif // DX_NON_INPUT














// DxMemory.cpp�֐��v���g�^�C�v�錾

// �������m�یn�֐�
extern	void*		DxAlloc(						size_t AllocSize , const char *File = NULL , int Line = -1 ) ;					// �w��̃T�C�Y�̃��������m�ۂ���( AllocSize:�m�ۂ��郁�����̃T�C�Y( �P��:byte )  File:DxAlloc���Ă񂾃\�[�X�t�@�C����( �f�o�b�O�p )  Line:DxAlloc���Ă񂾃\�[�X�t�@�C�����̍s�ԍ�( �f�o�b�O�p )�@�@�߂�l  NULL:�������̊m�ێ��s   NULL�ȊO:�m�ۂ����������̈�̐擪�A�h���X )
extern	void*		DxCalloc(						size_t AllocSize , const char *File = NULL , int Line = -1 ) ;					// �w��̃T�C�Y�̃��������m�ۂ��āA�O�Ŗ��߂�A��������ɂO�Ŗ��߂�ȊO�� DxAlloc �Ɠ���͓���
extern	void*		DxRealloc(						void *Memory , size_t AllocSize , const char *File = NULL , int Line = -1 ) ;	// �������̍Ċm�ۂ��s��( Memory:�Ċm�ۂ��s���������̈�̐擪�A�h���X( DxAlloc �̖߂�l )  AllocSize:�V�����m�ۃT�C�Y�@File��Line �̐����� DxAlloc �̒��߂̒ʂ� �@�߂�l NULL:�������̍Ċm�ێ��s�@NULL�ȊO:�Ċm�ۂ����V�����������̈�̐擪�A�h���X�@)
extern	void		DxFree(							void *Memory ) ;																// ���������������( Memory:������郁�����̈�̐擪�A�h���X( DxAlloc �̖߂�l ) )
extern	size_t		DxSetAllocSizeTrap(				size_t Size ) ;																	// �񋓑Ώۂɂ��郁�����̊m�ۗe�ʂ��Z�b�g����
extern	int			DxSetAllocPrintFlag(			int Flag ) ;																	// �c�w���C�u�������Ń������m�ۂ��s���鎞�ɏ����o�͂��邩�ǂ������Z�b�g����
extern	size_t		DxGetAllocSize(					void ) ;																		// DxAlloc �� DxCalloc �Ŋm�ۂ��Ă��郁�����T�C�Y���擾����
extern	int			DxGetAllocNum(					void ) ;																		// DxAlloc �� DxCalloc �Ŋm�ۂ��Ă��郁�����̐����擾����
extern	void		DxDumpAlloc(					void ) ;																		// DxAlloc �� DxCalloc �Ŋm�ۂ��Ă��郁������񋓂���
extern	int			DxErrorCheckAlloc(				void ) ;																		// �m�ۂ�����������񂪔j�󂳂�Ă��Ȃ������ׂ�( -1:�j�󂠂�  0:�Ȃ� )
extern	int			DxSetAllocSizeOutFlag(			int Flag ) ;																	// ���������m�ہA������s����x�Ɋm�ۂ��Ă��郁�����̗e�ʂ��o�͂��邩�ǂ����̃t���O���Z�b�g����
extern	int			DxSetAllocMemoryErrorCheckFlag(	int Flag ) ;																	// �������̊m�ہA������s����x�Ɋm�ۂ��Ă��郁�����m�ۏ�񂪔j�����Ă��Ȃ������ׂ邩�ǂ����̃t���O���Z�b�g����
















// DxNetwork.cpp�֐��v���g�^�C�v�錾

#ifndef DX_NON_NETWORK

// �ʐM�֌W
extern	int			ProcessNetMessage(				int RunReleaseProcess = FALSE ) ;														// �ʐM���b�Z�[�W�̏���������֐�

extern	int			GetHostIPbyName(				const TCHAR *HostName, IPDATA      *IPDataBuf ) ;										// �c�m�r�T�[�o�[���g���ăz�X�g������h�o�A�h���X���擾����( IPv4�� )
extern	int			GetHostIPbyName_IPv6(			const TCHAR *HostName, IPDATA_IPv6 *IPDataBuf ) ;										// �c�m�r�T�[�o�[���g���ăz�X�g������h�o�A�h���X���擾����( IPv6�� )
extern 	int			ConnectNetWork(					IPDATA      IPData, int Port = -1 ) ;													// ���}�V���ɐڑ�����( IPv4�� )
extern	int			ConnectNetWork_IPv6(			IPDATA_IPv6 IPData, int Port = -1 ) ;													// ���}�V���ɐڑ�����( IPv6�� )
extern 	int			ConnectNetWork_ASync(			IPDATA      IPData, int Port = -1 ) ;													// ���}�V���ɐڑ�����( IPv4�� )�A�񓯊���
extern	int			ConnectNetWork_IPv6_ASync(		IPDATA_IPv6 IPData, int Port = -1 ) ;													// ���}�V���ɐڑ�����( IPv6�� )�A�񓯊���
extern 	int			PreparationListenNetWork(		int Port = -1 ) ;																		// �ڑ����󂯂����Ԃɂ���( IPv4�� )
extern 	int			PreparationListenNetWork_IPv6(	int Port = -1 ) ;																		// �ڑ����󂯂����Ԃɂ���( IPv6�� )
extern 	int			StopListenNetWork(				void ) ;																				// �ڑ����󂯂���Ԃ̉���
extern 	int			CloseNetWork(					int NetHandle ) ;																		// �ڑ����I������

extern 	int			GetNetWorkAcceptState(			int NetHandle ) ;																		// �ڑ���Ԃ��擾����
extern 	int			GetNetWorkDataLength(			int NetHandle ) ;																		// ��M�f�[�^�̗ʂ𓾂�
extern	int			GetNetWorkSendDataLength(		int NetHandle ) ;																		// �����M�̃f�[�^�̗ʂ𓾂� 
extern 	int			GetNewAcceptNetWork(			void ) ;																				// �V���ɐڑ������ʐM����𓾂�
extern 	int			GetLostNetWork(					void ) ;																				// �ڑ���ؒf���ꂽ�ʐM����𓾂�
extern 	int			GetNetWorkIP(					int NetHandle, IPDATA      *IpBuf ) ;													// �ڑ���̂h�o�𓾂�( IPv4�� )
extern 	int			GetNetWorkIP_IPv6(				int NetHandle, IPDATA_IPv6 *IpBuf ) ;													// �ڑ���̂h�o�𓾂�( IPv6�� )
extern	int			GetMyIPAddress(					IPDATA *IpBuf ) ;																		// �����̂h�o�𓾂�
extern	int			SetConnectTimeOutWait(			int Time ) ;																			// �ڑ��̃^�C���A�E�g�܂ł̎��Ԃ�ݒ肷��
extern	int			SetUseDXNetWorkProtocol(		int Flag ) ;																			// �c�w���C�u�����̒ʐM�`�Ԃ��g�����ǂ������Z�b�g����
extern	int			GetUseDXNetWorkProtocol(		void ) ; 																				// �c�w���C�u�����̒ʐM�`�Ԃ��g�����ǂ������擾����
extern	int			SetUseDXProtocol(				int Flag ) ;																			// SetUseDXNetWorkProtocol �̕ʖ�
extern	int			GetUseDXProtocol(				void ) ; 																				// GetUseDXNetWorkProtocol �̕ʖ�
extern	int			SetNetWorkCloseAfterLostFlag(	int Flag ) ;																			// �ڑ����ؒf���ꂽ����ɐڑ��n���h����������邩�ǂ����̃t���O���Z�b�g����
extern	int			GetNetWorkCloseAfterLostFlag(	void ) ;																				// �ڑ����ؒf���ꂽ����ɐڑ��n���h����������邩�ǂ����̃t���O���擾����
//extern	int			SetProxySetting( int UseFlag, const char *Address, int Port ) ;														// �g�s�s�o�ʐM�Ŏg�p����v���L�V�ݒ���s��
//extern	int			GetProxySetting( int *UseFlagBuffer, char *AddressBuffer, int *PortBuffer ) ;										// �g�s�s�o�ʐM�Ŏg�p����v���L�V�ݒ���擾����
//extern	int			SetIEProxySetting( void ) ;																							// �h�d�̃v���L�V�ݒ��K������

extern 	int			NetWorkRecv(			int NetHandle, void *Buffer, int Length ) ;														// ��M�����f�[�^��ǂݍ���
extern	int			NetWorkRecvToPeek(		int NetHandle, void *Buffer, int Length ) ;														// ��M�����f�[�^��ǂݍ��ށA�ǂݍ��񂾃f�[�^�̓o�b�t�@����폜����Ȃ�
extern	int			NetWorkRecvBufferClear(	int NetHandle ) ;																				// ��M�����f�[�^���N���A����
extern 	int			NetWorkSend(			int NetHandle, void *Buffer, int Length ) ;														// �f�[�^�𑗐M����

extern	int			MakeUDPSocket(			int RecvPort = -1 ) ;																			// UDP���g�p�����ʐM���s���\�P�b�g�n���h�����쐬����( RecvPort �� -1 �ɂ���Ƒ��M��p�̃\�P�b�g�n���h���ɂȂ�܂� )
extern	int			MakeUDPSocket_IPv6(		int RecvPort = -1 ) ;																			// UDP���g�p�����ʐM���s���\�P�b�g�n���h�����쐬����( RecvPort �� -1 �ɂ���Ƒ��M��p�̃\�P�b�g�n���h���ɂȂ�܂� )( IPv6�� )
extern	int			DeleteUDPSocket(		int NetUDPHandle ) ;																			// UDP���g�p�����ʐM���s���\�P�b�g�n���h�����폜����
extern	int			NetWorkSendUDP(			int NetUDPHandle, IPDATA       SendIP, int SendPort,  void *Buffer, int Length ) ;				// UDP���g�p�����ʐM�Ŏw��̂h�o�Ƀf�[�^�𑗐M����ALength �͍ő�65507�ASendPort �� -1 �ɂ���� MakeUDPSocket �� RecvPort �œn�����|�[�g���g�p����܂�( �߂�l  0�ȏ�;���M�ł����f�[�^�T�C�Y  -1:�G���[  -2:���M�f�[�^���傫������  -3:���M�������ł��Ă��Ȃ�  )
extern	int			NetWorkSendUDP_IPv6(	int NetUDPHandle, IPDATA_IPv6  SendIP, int SendPort,  void *Buffer, int Length ) ;				// UDP���g�p�����ʐM�Ŏw��̂h�o�Ƀf�[�^�𑗐M����ALength �͍ő�65507�ASendPort �� -1 �ɂ���� MakeUDPSocket �� RecvPort �œn�����|�[�g���g�p����܂�( �߂�l  0�ȏ�;���M�ł����f�[�^�T�C�Y  -1:�G���[  -2:���M�f�[�^���傫������  -3:���M�������ł��Ă��Ȃ�  )( IPv6�� )
extern	int			NetWorkRecvUDP(			int NetUDPHandle, IPDATA      *RecvIP, int *RecvPort, void *Buffer, int Length, int Peek ) ;	// UDP���g�p�����ʐM�Ńf�[�^����M����APeek �� TRUE ��n���Ǝ�M�ɐ������Ă��f�[�^����M�L���[����폜���܂���( �߂�l  0�ȏ�:��M�����f�[�^�̃T�C�Y  -1:�G���[  -2:�o�b�t�@�̃T�C�Y������Ȃ�  -3:��M�f�[�^���Ȃ� )
extern	int			NetWorkRecvUDP_IPv6(	int NetUDPHandle, IPDATA_IPv6 *RecvIP, int *RecvPort, void *Buffer, int Length, int Peek ) ;	// UDP���g�p�����ʐM�Ńf�[�^����M����APeek �� TRUE ��n���Ǝ�M�ɐ������Ă��f�[�^����M�L���[����폜���܂���( �߂�l  0�ȏ�:��M�����f�[�^�̃T�C�Y  -1:�G���[  -2:�o�b�t�@�̃T�C�Y������Ȃ�  -3:��M�f�[�^���Ȃ� )( IPv6�� )
//extern int		CheckNetWorkSendUDP(	int NetUDPHandle ) ;																			// UDP���g�p�����ʐM�Ńf�[�^�����M�ł����Ԃ��ǂ����𒲂ׂ�( �߂�l  -1:�G���[  TRUE:���M�\  FALSE:���M�s�\ )
extern	int			CheckNetWorkRecvUDP(	int NetUDPHandle ) ;																			// UDP���g�p�����ʐM�ŐV���Ȏ�M�f�[�^�����݂��邩�ǂ����𒲂ׂ�( �߂�l  -1:�G���[  TRUE:��M�f�[�^����  FALSE:��M�f�[�^�Ȃ� )

/*	�g�p�s��
extern	int			HTTP_FileDownload(			const char *FileURL, const char *SavePath = NULL , void **SaveBufferP = NULL , int *FileSize = NULL , char **ParamList = NULL ) ;						// HTTP ���g�p���ăl�b�g���[�N��̃t�@�C�����_�E�����[�h����
extern	int			HTTP_GetFileSize(			const char *FileURL ) ;																		// HTTP ���g�p���ăl�b�g���[�N��̃t�@�C���̃T�C�Y�𓾂�

extern	int			HTTP_StartFileDownload(		const char *FileURL, const char *SavePath, void **SaveBufferP = NULL , char **ParamList = NULL ) ;	// HTTP ���g�p�����l�b�g���[�N��̃t�@�C�����_�E�����[�h���鏈�����J�n����
extern	int			HTTP_StartGetFileSize(		const char *FileURL ) ;																		// HTTP ���g�p�����l�b�g���[�N��̃t�@�C���̃T�C�Y�𓾂鏈�����J�n����
extern	int			HTTP_Close(					int HttpHandle ) ;																			// HTTP �̏������I�����A�n���h�����������
extern	int			HTTP_CloseAll(				void ) ;																					// �S�Ẵn���h���ɑ΂��� HTTP_Close ���s��
extern	int			HTTP_GetState(				int HttpHandle ) ;																			// HTTP �����̌��݂̏�Ԃ𓾂�( NET_RES_COMPLETE �� )
extern	int			HTTP_GetError(				int HttpHandle ) ;																			// HTTP �����ŃG���[�����������ꍇ�A�G���[�̓��e�𓾂�( HTTP_ERR_NONE �� )
extern	int			HTTP_GetDownloadFileSize(	int HttpHandle ) ;																			// HTTP �����őΏۂƂȂ��Ă���t�@�C���̃T�C�Y�𓾂�( �߂�l: -1 = �G���[�E�Ⴕ���͂܂��t�@�C���̃T�C�Y���擾���Ă��Ȃ�  0�ȏ� = �t�@�C���̃T�C�Y )
extern	int			HTTP_GetDownloadedFileSize( int HttpHandle ) ;																			// HTTP �����Ŋ��Ƀ_�E�����[�h�����t�@�C���̃T�C�Y���擾����

extern	int			fgetsForNetHandle(			int NetHandle, char *strbuffer ) ;															// fgets �̃l�b�g���[�N�n���h����( -1:�擾�ł��� 0:�擾�ł��� )
extern	int			URLAnalys(					const char *URL, char *HostBuf = NULL , char *PathBuf = NULL , char *FileNameBuf = NULL , int *PortBuf = NULL ) ;	// �t�q�k����͂���
extern	int			URLConvert(					char *URL, int ParamConvert = TRUE , int NonConvert = FALSE ) ;								// HTTP �ɓn���Ȃ��L�����g��ꂽ�������n����悤�ȕ�����ɕϊ�����( �߂�l: -1 = �G���[  0�ȏ� = �ϊ���̕�����̃T�C�Y )
extern	int			URLParamAnalysis(			char **ParamList, char **ParamStringP ) ;													// HTTP �p�p�����[�^���X�g�����̃p�����[�^��������쐬����( �߂�l:  -1 = �G���[  0�ȏ� = �p�����[�^�̕�����̒��� )
*/

#endif // DX_NON_NETWORK
















// DxInputString.cpp�֐��v���g�^�C�v�錾

#ifndef DX_NON_INPUTSTRING

// �����R�[�h�o�b�t�@����֌W
extern	int			StockInputChar(		TCHAR CharCode ) ;								// �����R�[�h�o�b�t�@�ɕ����R�[�h���X�g�b�N����
extern	int			ClearInputCharBuf(	void ) ;										// �����R�[�h�o�b�t�@���N���A����
extern	TCHAR		GetInputChar(		int DeleteFlag ) ;								// �����R�[�h�o�b�t�@�ɗ��܂����f�[�^���當���R�[�h����擾����
extern	TCHAR		GetInputCharWait(	int DeleteFlag ) ;								// �����R�[�h�o�b�t�@�ɗ��܂����f�[�^���當���R�[�h����擾����A�o�b�t�@�ɂȂɂ������R�[�h���Ȃ��ꍇ�͕����R�[�h���o�b�t�@�Ɉꕶ�������܂�܂ő҂�

extern	int			GetOneChar(			TCHAR *CharBuffer, int DeleteFlag ) ;			// �����R�[�h�o�b�t�@�ɗ��܂����f�[�^����P�������擾����
extern	int			GetOneCharWait(		TCHAR *CharBuffer, int DeleteFlag ) ;			// �����R�[�h�o�b�t�@�ɗ��܂����f�[�^����P�������擾����A�o�b�t�@�ɉ��������R�[�h���Ȃ��ꍇ�͕����R�[�h���o�b�t�@�Ɉꕶ�������܂�܂ő҂�
extern	int			GetCtrlCodeCmp(		TCHAR Char ) ;									// �w��̕����R�[�h���A�X�L�[�R���g���[���R�[�h�����ׂ�

#endif // DX_NON_INPUTSTRING

#ifndef DX_NON_KEYEX

extern	int			DrawIMEInputString(				int x, int y, int SelectStringNum ) ;	// ��ʏ�ɓ��͒��̕������`�悷��
extern	int			SetUseIMEFlag(					int UseFlag ) ;							// �h�l�d���g�p���邩�ǂ�����ݒ肷��
extern	int			SetInputStringMaxLengthIMESync(	int Flag ) ;							// �h�l�d�œ��͂ł���ő啶������ MakeKeyInput �̐ݒ�ɍ��킹�邩�ǂ������Z�b�g����( TRUE:���킹��  FALSE:���킹�Ȃ�(�f�t�H���g) )
extern	int			SetIMEInputStringMaxLength(		int Length ) ;							// �h�l�d�ň�x�ɓ��͂ł���ő啶������ݒ肷��( 0:�����Ȃ�  1�ȏ�:�w��̕������Ő��� )

#endif // DX_NON_KEYEX

extern	int			GetStringPoint(				const TCHAR *String, int Point ) ;			// �S�p�����A���p�������藐��钆����w��̕������ł̔��p�������𓾂�
extern	int			GetStringPoint2(			const TCHAR *String, int Point ) ;			// �S�p�����A���p�������藐��钆����w��̕������ł̑S�p�������𓾂�

#ifndef DX_NON_FONT
extern	int			DrawObtainsString(			int x, int y, int AddY, const TCHAR *String, int StrColor, int StrEdgeColor = 0 , int FontHandle = -1 , int SelectBackColor = -1 , int SelectStrColor = 0 , int SelectStrEdgeColor = -1 , int SelectStart = -1 , int SelectEnd = -1 ) ;		// �`��\�̈�Ɏ��܂�悤�ɉ��s���Ȃ��當�����`��
#endif // DX_NON_FONT
extern	int			DrawObtainsBox(				int x1, int y1, int x2, int y2, int AddY, int Color, int FillFlag ) ;																																										// �`��\�̈�Ɏ��܂�悤�ɕ␳�������Ȃ����`��`��

#ifndef DX_NON_KEYEX

extern	int			InputStringToCustom(		int x, int y, int BufLength, TCHAR *StrBuffer, int CancelValidFlag, int SingleCharOnlyFlag, int NumCharOnlyFlag, int DoubleCharOnlyFlag = FALSE ) ;		// ������̓��͎擾

extern	int			KeyInputString(				int x, int y, int CharMaxLength, TCHAR *StrBuffer, int CancelValidFlag ) ;														// ������̓��͎擾
extern	int			KeyInputSingleCharString(	int x, int y, int CharMaxLength, TCHAR *StrBuffer, int CancelValidFlag ) ;														// ���p������݂̂̓��͎擾
extern	int			KeyInputNumber(				int x, int y, int MaxNum, int MinNum, int CancelValidFlag ) ;																	// ���l�̓��͎擾

extern	int			GetIMEInputModeStr(			TCHAR *GetBuffer ) ;																											// IME�̓��̓��[�h��������擾����
extern	IMEINPUTDATA* GetIMEInputData(			void ) ;																														// IME�œ��͒��̕�����̏����擾����
#if defined( DX_GCC_COMPILE ) || defined( __ANDROID )
extern	int			SetKeyInputStringColor(		ULONGLONG NmlStr, ULONGLONG NmlCur, ULONGLONG IMEStr, ULONGLONG IMECur, ULONGLONG IMELine, ULONGLONG IMESelectStr, ULONGLONG IMEModeStr , ULONGLONG NmlStrE = 0 , ULONGLONG IMESelectStrE = 0 , ULONGLONG IMEModeStrE = 0 , ULONGLONG IMESelectWinE = 0xffffffffffffffffULL ,	ULONGLONG IMESelectWinF = 0xffffffffffffffffULL , ULONGLONG SelectStrBackColor = 0xffffffffffffffffULL , ULONGLONG SelectStrColor = 0xffffffffffffffffULL , ULONGLONG SelectStrEdgeColor = 0xffffffffffffffffULL ) ;	// InputString�֐��g�p���̕����̊e�F��ύX����
#else // defined( DX_GCC_COMPILE ) || defined( __ANDROID )
extern	int			SetKeyInputStringColor(		ULONGLONG NmlStr, ULONGLONG NmlCur, ULONGLONG IMEStr, ULONGLONG IMECur, ULONGLONG IMELine, ULONGLONG IMESelectStr, ULONGLONG IMEModeStr , ULONGLONG NmlStrE = 0 , ULONGLONG IMESelectStrE = 0 , ULONGLONG IMEModeStrE = 0 , ULONGLONG IMESelectWinE = 0xffffffffffffffff ,	ULONGLONG IMESelectWinF = 0xffffffffffffffff , ULONGLONG SelectStrBackColor = 0xffffffffffffffff , ULONGLONG SelectStrColor = 0xffffffffffffffff , ULONGLONG SelectStrEdgeColor = 0xffffffffffffffff ) ;	// InputString�֐��g�p���̕����̊e�F��ύX����
#endif // defined( DX_GCC_COMPILE ) || defined( __ANDROID )
extern	int			SetKeyInputStringFont(		int FontHandle ) ;																												// �L�[���͕�����`��֘A�Ŏg�p����t�H���g�̃n���h����ύX����(-1�Ńf�t�H���g�̃t�H���g�n���h��)
extern	int			DrawKeyInputModeString(		int x, int y ) ;																												// ���̓��[�h�������`�悷��

extern	int			InitKeyInput(				void ) ;																														// �L�[���̓f�[�^������
extern	int			MakeKeyInput(				int MaxStrLength, int CancelValidFlag, int SingleCharOnlyFlag, int NumCharOnlyFlag, int DoubleCharOnlyFlag = FALSE ) ;			// �V�����L�[���̓n���h���̍쐬
extern	int			DeleteKeyInput(				int InputHandle ) ;																												// �L�[���̓n���h���̍폜
extern	int			SetActiveKeyInput(			int InputHandle ) ;																												// �w��̃L�[���̓n���h�����A�N�e�B�u�ɂ���( -1 ���w�肷��ƃA�N�e�B�u�ȃL�[���̓n���h����������ԂɂȂ�܂� )
extern	int			GetActiveKeyInput(			void ) ;																														// ���݃A�N�e�B�u�ɂȂ��Ă���L�[���̓n���h�����擾����
extern	int			CheckKeyInput(				int InputHandle ) ;																												// �L�[���̓n���h���̓��͂��I�����Ă��邩�擾����
extern	int			ReStartKeyInput(			int InputHandle ) ;																												// ���͂����������L�[���̓n���h�����ēx�ҏW��Ԃɖ߂�
extern	int			ProcessActKeyInput(			void ) ;																														// �L�[���̓n���h�������֐�
extern	int			DrawKeyInputString(			int x, int y, int InputHandle ) ;																								// �L�[���̓n���h���̓��͒����̕`��

extern	int			SetKeyInputSelectArea(		int  SelectStart, int  SelectEnd, int InputHandle ) ;																			// �L�[���̓n���h���̎w��̗̈��I����Ԃɂ���( SelectStart �� SelectEnd �� -1 ���w�肷��ƑI����Ԃ���������܂� )
extern	int			GetKeyInputSelectArea(		int *SelectStart, int *SelectEnd, int InputHandle ) ;																			// �L�[���̓n���h���̑I��̈���擾����
extern	int			SetKeyInputDrawStartPos(	int DrawStartPos, int InputHandle ) ;																							// �L�[���̓n���h���̕`��J�n�����ʒu��ݒ肷��
extern	int			GetKeyInputDrawStartPos(	int InputHandle ) ;																												// �L�[���̓n���h���̕`��J�n�����ʒu���擾����
extern	int			SetKeyInputCursorBrinkTime(	int Time ) ;																													// �L�[���̓n���h���̃L�[���͎��̃J�[�\���̓_�ł��鑁�����Z�b�g����
extern	int			SetKeyInputCursorBrinkFlag(	int Flag ) ;																													// �L�[���̓n���h���̃L�[���͎��̃J�[�\����_�ł����邩�ǂ������Z�b�g����
extern	int			SetKeyInputString(			const TCHAR *String, int InputHandle ) ;																						// �L�[���̓n���h���Ɏw��̕�������Z�b�g����
extern	int			SetKeyInputNumber(			int   Number,        int InputHandle ) ;																						// �L�[���̓n���h���Ɏw��̐��l�𕶎��ɒu�������ăZ�b�g����
extern	int			SetKeyInputNumberToFloat(	float Number,        int InputHandle ) ;																						// �L�[���̓n���h���Ɏw��̕��������_�l�𕶎��ɒu�������ăZ�b�g����
extern	int			GetKeyInputString(			TCHAR *StrBuffer,    int InputHandle ) ;																						// �L�[���̓n���h���̓��͒��̕�������擾����
extern	int			GetKeyInputNumber(			int InputHandle ) ;																												// �L�[���̓n���h���̓��͒��̕�����𐮐��l�Ƃ��Ď擾����
extern	float		GetKeyInputNumberToFloat(	int InputHandle ) ;																												// �L�[���̓n���h���̓��͒��̕�����𕂓������_�l�Ƃ��Ď擾����
extern	int			SetKeyInputCursorPosition(	int Position,        int InputHandle ) ;																						// �L�[���̓n���h���̌��݂̃J�[�\���ʒu��ݒ肷��
extern	int			GetKeyInputCursorPosition(	int InputHandle ) ;																												// �L�[���̓n���h���̌��݂̃J�[�\���ʒu���擾����

#endif // DX_NON_KEYEX











// DxFile.cpp�֐��v���g�^�C�v�錾

// �t�@�C���A�N�Z�X�֐�
extern	int			FileRead_open(				const TCHAR *FilePath , int ASync = FALSE ) ;					// �t�@�C�����J��
extern	int			FileRead_size(				const TCHAR *FilePath ) ;										// �t�@�C���̃T�C�Y���擾����
extern	int			FileRead_close(				int FileHandle ) ;												// �t�@�C�������
extern	int			FileRead_tell(				int FileHandle ) ;												// �t�@�C���|�C���^�̓ǂݍ��݈ʒu���擾����
extern	int			FileRead_seek(				int FileHandle , int Offset , int Origin ) ;					// �t�@�C���|�C���^�̓ǂݍ��݈ʒu��ύX����
extern	int			FileRead_read(				void *Buffer , int ReadSize , int FileHandle ) ;				// �t�@�C������f�[�^��ǂݍ���
extern	int			FileRead_idle_chk(			int FileHandle ) ;												// �t�@�C���ǂݍ��݂��������Ă��邩�ǂ������擾����
extern	int			FileRead_eof(				int FileHandle ) ;												// �t�@�C���̓ǂݍ��݈ʒu���I�[�ɒB���Ă��邩�ǂ������擾����
extern	int			FileRead_gets(				TCHAR *Buffer , int BufferSize , int FileHandle ) ;				// �t�@�C�����當�����ǂݏo��
extern	TCHAR		FileRead_getc(				int FileHandle ) ;												// �t�@�C������ꕶ���ǂݏo��
extern	int			FileRead_scanf(				int FileHandle , const TCHAR *Format , ... ) ;					// �t�@�C�����珑�������ꂽ�f�[�^��ǂݏo��

extern	DWORD_PTR	FileRead_createInfo(		const TCHAR *ObjectPath ) ;										// �t�@�C�����n���h�����쐬����( �߂�l  -1:�G���[  -1�ȊO:�t�@�C�����n���h�� )
extern	int			FileRead_getInfoNum(		DWORD_PTR FileInfoHandle ) ;									// �t�@�C�����n���h�����̃t�@�C���̐����擾����
extern	int			FileRead_getInfo(			int Index , FILEINFO *Buffer , DWORD_PTR FileInfoHandle ) ;		// �t�@�C�����n���h�����̃t�@�C���̏����擾����
extern	int			FileRead_deleteInfo(		DWORD_PTR FileInfoHandle ) ;									// �t�@�C�����n���h�����폜����

extern	DWORD_PTR	FileRead_findFirst(			const TCHAR *FilePath, FILEINFO *Buffer ) ;						// �w��̃t�@�C�����̓t�H���_�̏����擾���A�t�@�C�������n���h�����쐬����( �߂�l: -1=�G���[  -1�ȊO=�t�@�C�������n���h�� )
extern	int			FileRead_findNext(			DWORD_PTR FindHandle, FILEINFO *Buffer ) ;						// �����̍��v���鎟�̃t�@�C���̏����擾����( �߂�l: -1=�G���[  0=���� )
extern	int			FileRead_findClose(			DWORD_PTR FindHandle ) ;										// �t�@�C�������n���h�������( �߂�l: -1=�G���[  0=���� )

// �ݒ�֌W�֐�
extern	int			GetStreamFunctionDefault(	void ) ;														// �c�w���C�u�����ŃX�g���[���f�[�^�A�N�Z�X�Ɏg�p����֐����f�t�H���g�̂��̂����ׂ�( TRUE:�f�t�H���g�̂���  FALSE:�f�t�H���g�ł͂Ȃ� )
extern	int			ChangeStreamFunction(		STREAMDATASHREDTYPE2 *StreamThread ) ;							// �c�w���C�u�����ŃX�g���[���f�[�^�A�N�Z�X�Ɏg�p����֐���ύX����












// DxInput.cpp�֐��v���g�^�C�v�錾

#ifndef DX_NON_INPUT

// ���͏�Ԏ擾�֐�
extern	int			CheckHitKey(							int KeyCode ) ;															// �L�[�{�[�h�̉�����Ԃ��擾����
extern	int			CheckHitKeyAll(							int CheckType = DX_CHECKINPUT_ALL ) ;									// �ǂꂩ��ł��L�[��������Ă��邩�ǂ������擾( ������Ă�����߂�l�� 0 �ȊO�ɂȂ� )
extern	int			GetHitKeyStateAll(						DX_CHAR *KeyStateBuf ) ;												// ���ׂẴL�[�̉�����Ԃ��擾����( KeyStateBuf:char�^256���̔z��̐擪�A�h���X )
extern	int			SetKeyExclusiveCooperativeLevelFlag(	int Flag ) ;															// DirectInput �̃L�[�{�[�h�̋������x����r�����x���ɂ��邩�ǂ�����ݒ肷��( TRUE:�r�����x���ɂ���  FALSE:�W�����x���ɂ���( �f�t�H���g ) )�ADxLib_Init �̌Ăяo���O�ł̂ݎ��s�\
extern	int			GetJoypadNum(							void ) ;																// �W���C�p�b�h���ڑ�����Ă��鐔���擾����
extern	int			GetJoypadInputState(					int InputType ) ;														// �W���C�p�b�h�̓��͏�Ԃ��擾����
extern	int			GetJoypadAnalogInput(					int *XBuf, int *YBuf, int InputType ) ;									// �W���C�p�b�h�̃A�i���O�I�ȃX�e�B�b�N���͏��𓾂�
extern	int			GetJoypadAnalogInputRight(				int *XBuf, int *YBuf, int InputType ) ;									// ( �g�p�񐄏� )�W���C�p�b�h�̃A�i���O�I�ȃX�e�B�b�N���͏��𓾂�(�E�X�e�B�b�N�p)
extern	int			GetJoypadDirectInputState(				int InputType, DINPUT_JOYSTATE *DInputState ) ;							// DirectInput ���瓾����W���C�p�b�h�̐��̃f�[�^���擾����( DX_INPUT_KEY �� DX_INPUT_KEY_PAD1 �ȂǁA�L�[�{�[�h�����ރ^�C�v�� InputType �ɓn���ƃG���[ )
extern	int			KeyboradBufferProcess(					void ) ;																// �L�[�{�[�h�̃o�b�t�@����f�[�^���擾���鏈��
extern	int			GetJoypadGUID(							int PadIndex, GUID *GuidBuffer ) ;										// �W���C�p�b�h�̂f�tI�c�𓾂�
extern	int			ConvertKeyCodeToVirtualKey(				int KeyCode ) ;															// �c�w���C�u�����̃L�[�R�[�h( KEY_INPUT_A �Ȃ� )�ɑΉ����� Windows �̉��z�L�[�R�[�h( VK_LEFT �Ȃ� ) ���擾����( KeyCode:�ϊ��������c�w���C�u�����̃L�[�R�[�h�@�߂�l�FWindows�̉��z�L�[�R�[�h )
extern	int			SetJoypadInputToKeyInput(				int InputType, int PadInput, int KeyInput1, int KeyInput2 = -1 , int KeyInput3 = -1 , int KeyInput4 = -1  ) ; // �W���C�p�b�h�̓��͂ɑΉ������L�[�{�[�h�̓��͂�ݒ肷��( InputType:�ݒ��ύX����p�b�h�̎��ʎq( DX_INPUT_PAD1�� )�@�@PadInput:�ݒ��ύX����p�b�h�{�^���̎��ʎq( PAD_INPUT_1 �� )�@�@KeyInput1:PadInput �������������Ƃɂ���L�[�R�[�h( KEY_INPUT_A �Ȃ� )���̂P�@�@KeyInput2:���̂Q�A-1�Őݒ�Ȃ��@�@KeyInput3:���̂R�A-1�Őݒ�Ȃ��@�@KeyInput4:���̂S�A-1�Őݒ�Ȃ� )
extern	int			SetJoypadDeadZone(						int InputType, double Zone ) ;											// �W���C�p�b�h�̖����]�[���̐ݒ���s��( InputType:�ݒ��ύX����p�b�h�̎��ʎq( DX_INPUT_PAD1�� )   Zone:�V���������]�[��( 0.0 �` 1.0 )�A�f�t�H���g�l�� 0.35 )
extern	int			StartJoypadVibration(					int InputType, int Power, int Time ) ;									// �W���C�p�b�h�̐U�����J�n����
extern	int			StopJoypadVibration(					int InputType ) ;														// �W���C�p�b�h�̐U�����~����
extern	int			GetJoypadPOVState(						int InputType, int POVNumber ) ;										// �W���C�p�b�h�̂o�n�u���͂̏�Ԃ𓾂�( �߂�l�@�w���POV�f�[�^�̊p�x�A�P�ʂ͊p�x�̂P�O�O�{( 90�x�Ȃ� 9000 ) ���S�ʒu�ɂ���ꍇ�� -1 ���Ԃ� )
extern	int			GetJoypadName(							int InputType, TCHAR *InstanceNameBuffer, TCHAR *ProductNameBuffer ) ;	// �W���C�p�b�h�̃f�o�C�X�o�^���Ɛ��i�o�^�����擾����
extern	int			ReSetupJoypad(							void ) ;																// �W���C�p�b�h�̍ăZ�b�g�A�b�v���s��( �V���ɐڑ����ꂽ�W���C�p�b�h���������猟�o����� )

extern	int			SetKeyboardNotDirectInputFlag(			int Flag ) ;															// �L�[�{�[�h�̓��͏����� DirectInput ���g��Ȃ����ǂ�����ݒ肷��( TRUE:DirectInput ���g�킸�AWindows�W���@�\���g�p����@�@FALSE:DirectInput ���g�p���� )
extern	int			SetUseDirectInputFlag(					int Flag ) ;															// ���͏����� DirectInput ���g�p���邩�ǂ�����ݒ肷��( TRUE:DirectInput ���g�p����@�@FALSE:DirectInput ���g�킸�AWindows�W���@�\���g�p���� )
extern	int			SetUseJoypadVibrationFlag(				int Flag ) ;															// �W���C�p�b�h�̐U���@�\���g�p���邩�ǂ�����ݒ肷��( TRUE:�g�p����@�@FALSE:�g�p���Ȃ� )

#endif // DX_NON_INPUT







#ifndef DX_NOTUSE_DRAWFUNCTION

// �摜�����n�֐��v���g�^�C�v�錾

// �O���t�B�b�N�n���h���쐬�֌W�֐�
extern	int			MakeGraph(						int SizeX, int SizeY, int NotUse3DFlag = FALSE ) ;							// �w��T�C�Y�̃O���t�B�b�N�n���h�����쐬����
extern	int			MakeScreen(						int SizeX, int SizeY, int UseAlphaChannel = FALSE ) ;						// SetDrawScreen �ŕ`��Ώۂɂł���O���t�B�b�N�n���h�����쐬����
extern	int			DerivationGraph(				int SrcX, int SrcY, int Width, int Height, int SrcGraphHandle ) ;			// �w��̃O���t�B�b�N�n���h���̎w�蕔�������𔲂��o���ĐV���ȃO���t�B�b�N�n���h�����쐬����
extern	int			DeleteGraph(					int GrHandle, int LogOutFlag = FALSE ) ;									// �O���t�B�b�N�n���h�����폜����
extern	int			DeleteSharingGraph(				int GrHandle ) ;															// �w��̃O���t�B�b�N�n���h���ƁA�����O���t�B�b�N�n���h������h�����Ă���O���t�B�b�N�n���h��( DerivationGraph �Ŕh�������n���h���ALoadDivGraph �ǂݍ���ō쐬���ꂽ�����̃n���h�� )����x�ɍ폜����
extern	int			GetGraphNum(					void ) ;																	// �L���ȃO���t�B�b�N�n���h���̐����擾����
extern	int			FillGraph(						int GrHandle, int Red, int Green, int Blue, int Alpha = 255 ) ;				// �O���t�B�b�N�n���h�����w��̐F�œh��Ԃ�
extern	int			SetGraphLostFlag(				int GrHandle, int *LostFlag ) ;												// �w��̃O���t�B�b�N�n���h�����폜���ꂽ�ۂ� 1 �ɂ���ϐ��̃A�h���X��ݒ肷��
extern	int			InitGraph(						int LogOutFlag = FALSE ) ;													// ���ׂẴO���t�B�b�N�n���h�����폜����
extern	int			ReloadFileGraphAll(				void ) ;																	// �t�@�C������摜��ǂݍ��񂾑S�ẴO���t�B�b�N�n���h���ɂ��āA�ēx�t�@�C������摜��ǂݍ���

// �O���t�B�b�N�n���h���ւ̉摜�]���֐�
extern	int			BltBmpToGraph(					COLORDATA *BmpColorData, HBITMAP RgbBmp, HBITMAP AlphaBmp, int CopyPointX, int CopyPointY,                                                                                 int GrHandle ) ;						// �a�l�o�̓��e���O���t�B�b�N�n���h���ɓ]��
extern	int			BltBmpToDivGraph(				COLORDATA *BmpColorData, HBITMAP RgbBmp, HBITMAP AlphaBmp, int AllNum, int XNum, int YNum, int Width, int Height,                                                          int *GrHandle, int ReverseFlag ) ;	// �a�l�o�̓��e�𕪊��쐬�����O���t�B�b�N�n���h�������ɓ]��
extern	int			BltBmpOrGraphImageToGraph(		COLORDATA *BmpColorData, HBITMAP RgbBmp, HBITMAP AlphaBmp, int BmpFlag, BASEIMAGE *RgbImage, BASEIMAGE *AlphaImage, int CopyPointX, int CopyPointY,                        int GrHandle ) ;						// �a�l�o �� BASEIMAGE ���O���t�B�b�N�n���h���ɓ]��
extern	int			BltBmpOrGraphImageToGraph2(		COLORDATA *BmpColorData, HBITMAP RgbBmp, HBITMAP AlphaBmp, int BmpFlag, BASEIMAGE *RgbImage, BASEIMAGE *AlphaImage, RECT *SrcRect, int DestX, int DestY,                   int GrHandle ) ;						// �a�l�o �� BASEIMAGE �̎w��̗̈���O���t�B�b�N�n���h���ɓ]��
extern	int			BltBmpOrGraphImageToDivGraph(	COLORDATA *BmpColorData, HBITMAP RgbBmp, HBITMAP AlphaBmp, int BmpFlag, BASEIMAGE *RgbImage, BASEIMAGE *AlphaImage, int AllNum, int XNum, int YNum, int Width, int Height, int *GrHandle, int ReverseFlag ) ;	// �a�l�o �� BASEIMAGE �𕪊��쐬�����O���t�B�b�N�n���h�������ɓ]��

// �摜����O���t�B�b�N�n���h�����쐬����֐�
extern	int			LoadBmpToGraph(					const TCHAR *FileName, int TextureFlag, int ReverseFlag, int SurfaceMode = DX_MOVIESURFACE_NORMAL ) ;								// �摜�t�@�C������O���t�B�b�N�n���h�����쐬����
extern	int			LoadGraph(						const TCHAR *FileName, int NotUse3DFlag = FALSE ) ;																					// �摜�t�@�C������O���t�B�b�N�n���h�����쐬����
extern	int			LoadReverseGraph(				const TCHAR *FileName, int NotUse3DFlag = FALSE ) ;																					// �摜�t�@�C���𔽓]�������̂ŃO���t�B�b�N�n���h�����쐬����
extern	int			LoadDivGraph(					const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf, int NotUse3DFlag = FALSE ) ;			// �摜�t�@�C���𕪊����ăO���t�B�b�N�n���h�����쐬����
extern	int			LoadDivBmpToGraph(				const TCHAR *FileName, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, int TextureFlag, int ReverseFlag ) ;	// �摜�t�@�C���𕪊����ăO���t�B�b�N�n���h�����쐬����
extern	int			LoadReverseDivGraph(			const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf, int NotUse3DFlag = FALSE ) ;			// �摜�t�@�C���𔽓]�������̂𕪊����ăO���t�B�b�N�n���h�����쐬����
extern	int			LoadBlendGraph(					const TCHAR *FileName ) ;																											// �摜�t�@�C������u�����h�p�O���t�B�b�N�n���h�����쐬����
#ifdef __WINDOWS__
extern	int			LoadGraphToResource(			int ResourceID ) ;																													// �摜���\�[�X����O���t�B�b�N�n���h�����쐬����
extern	int			LoadDivGraphToResource(			int ResourceID, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf ) ;											// �摜���\�[�X�𕪊����ăO���t�B�b�N�n���h�����쐬����
extern	int			LoadGraphToResource(			const TCHAR *ResourceName, const TCHAR *ResourceType ) ;																			// �摜���\�[�X����O���t�B�b�N�n���h�����쐬����
extern	int			LoadDivGraphToResource(			const TCHAR *ResourceName, const TCHAR *ResourceType, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf ) ;		// �摜���\�[�X�𕪊����ăO���t�B�b�N�n���h�����쐬����
#endif // __WINDOWS__

extern	int			CreateGraphFromMem(				void *RGBFileImage, int RGBFileImageSize,               void *AlphaFileImage = NULL , int AlphaFileImageSize = 0 ,      int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// ��������̉摜�C���[�W����O���t�B�b�N�n���h�����쐬����
extern	int			ReCreateGraphFromMem(           void *RGBFileImage, int RGBFileImageSize, int GrHandle, void *AlphaFileImage = NULL , int AlphaFileImageSize = 0 ,      int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// ��������̉摜�C���[�W��������̃O���t�B�b�N�n���h���Ƀf�[�^��]������
extern	int			CreateDivGraphFromMem(          void *RGBFileImage, int RGBFileImageSize, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf,         int TextureFlag = TRUE , int ReverseFlag = FALSE , void *AlphaFileImage = NULL , int AlphaFileImageSize = 0 ) ;		// ��������̉摜�C���[�W���番���O���t�B�b�N�n���h�����쐬����
extern	int			ReCreateDivGraphFromMem(        void *RGBFileImage, int RGBFileImageSize, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf,         int TextureFlag = TRUE , int ReverseFlag = FALSE , void *AlphaFileImage = NULL , int AlphaFileImageSize = 0 ) ;		// ��������̉摜�C���[�W��������̕����O���t�B�b�N�n���h���Ƀf�[�^��]������
extern	int			CreateGraphFromBmp(             BITMAPINFO *RGBBmpInfo, void *RGBBmpImage,               BITMAPINFO *AlphaBmpInfo = NULL , void *AlphaBmpImage = NULL , int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// �r�b�g�}�b�v�f�[�^����O���t�B�b�N�n���h�����쐬����
extern	int			ReCreateGraphFromBmp(           BITMAPINFO *RGBBmpInfo, void *RGBBmpImage, int GrHandle, BITMAPINFO *AlphaBmpInfo = NULL , void *AlphaBmpImage = NULL , int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// �r�b�g�}�b�v�f�[�^��������̃O���t�B�b�N�n���h���Ƀf�[�^��]������
extern	int			CreateDivGraphFromBmp(          BITMAPINFO *RGBBmpInfo, void *RGBBmpImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf,        int TextureFlag = TRUE , int ReverseFlag = FALSE , BITMAPINFO *AlphaBmpInfo = NULL , void *AlphaBmpImage = NULL ) ;	// �r�b�g�}�b�v�f�[�^���番���O���t�B�b�N�n���h�����쐬����
extern	int			ReCreateDivGraphFromBmp(        BITMAPINFO *RGBBmpInfo, void *RGBBmpImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf,        int TextureFlag = TRUE , int ReverseFlag = FALSE , BITMAPINFO *AlphaBmpInfo = NULL , void *AlphaBmpImage = NULL ) ;	// �r�b�g�}�b�v�f�[�^��������̕����O���t�B�b�N�n���h���Ƀf�[�^��]������
extern	int			CreateDXGraph(					BASEIMAGE *RgbImage, BASEIMAGE *AlphaImage,																				int TextureFlag ) ;																									// ��{�C���[�W�f�[�^����T�C�Y������o���A����ɍ������O���t�B�b�N�n���h�����쐬����
extern	int			CreateGraphFromGraphImage(      BASEIMAGE *RGBImage,                                                                                                    int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// ��{�C���[�W�f�[�^����O���t�B�b�N�n���h�����쐬����
extern	int			CreateGraphFromGraphImage(      BASEIMAGE *RGBImage, BASEIMAGE *AlphaImage,                                                                             int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// ��{�C���[�W�f�[�^����O���t�B�b�N�n���h�����쐬����
extern	int			ReCreateGraphFromGraphImage(    BASEIMAGE *RGBImage,                        int GrHandle,                                                               int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// ��{�C���[�W�f�[�^��������̃O���t�B�b�N�n���h���Ƀf�[�^��]������
extern	int			ReCreateGraphFromGraphImage(    BASEIMAGE *RGBImage, BASEIMAGE *AlphaImage, int GrHandle,                                                               int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// ��{�C���[�W�f�[�^��������̃O���t�B�b�N�n���h���Ƀf�[�^��]������
extern	int			CreateDivGraphFromGraphImage(   BASEIMAGE *RGBImage,                        int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf,       int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// ��{�C���[�W�f�[�^���番���O���t�B�b�N�n���h�����쐬����
extern	int			CreateDivGraphFromGraphImage(   BASEIMAGE *RGBImage, BASEIMAGE *AlphaImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf,       int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// ��{�C���[�W�f�[�^���番���O���t�B�b�N�n���h�����쐬����
extern	int			ReCreateDivGraphFromGraphImage( BASEIMAGE *RGBImage,                        int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf,       int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// ��{�C���[�W�f�[�^��������̕����O���t�B�b�N�n���h���Ƀf�[�^��]������
extern	int			ReCreateDivGraphFromGraphImage( BASEIMAGE *RGBImage, BASEIMAGE *AlphaImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf,       int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// ��{�C���[�W�f�[�^��������̕����O���t�B�b�N�n���h���Ƀf�[�^��]������
extern	int			CreateGraph(                    int Width, int Height, int Pitch, void *RGBImage, void *AlphaImage = NULL , int GrHandle = -1 ) ;																																			// ��������̃r�b�g�}�b�v�C���[�W����O���t�B�b�N�n���h�����쐬����
extern	int			CreateDivGraph(                 int Width, int Height, int Pitch, void *RGBImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, void *AlphaImage = NULL ) ;																							// ��������̃r�b�g�}�b�v�C���[�W���番���O���t�B�b�N�n���h�����쐬����
extern	int			ReCreateGraph(                  int Width, int Height, int Pitch, void *RGBImage, int GrHandle, void *AlphaImage = NULL ) ;																																					// ��������̃r�b�g�}�b�v�C���[�W����O���t�B�b�N�n���h�����č쐬����
#ifndef DX_NON_SOFTIMAGE
extern	int			CreateBlendGraphFromSoftImage(  int SIHandle ) ;																													// �\�t�g�E�G�A�ň����C���[�W����u�����h�p�摜�O���t�B�b�N�n���h�����쐬����( -1:�G���[  -1�ȊO:�u�����h�p�O���t�B�b�N�n���h�� )
extern	int			CreateGraphFromSoftImage(       int SIHandle ) ;																													// �\�t�g�E�G�A�ň����C���[�W����O���t�B�b�N�n���h�����쐬����( -1:�G���[  -1�ȊO:�O���t�B�b�N�n���h�� )
extern	int			CreateGraphFromRectSoftImage(   int SIHandle, int x, int y, int SizeX, int SizeY ) ;																				// �\�t�g�E�G�A�ň����C���[�W�̎w��̗̈���g���ăO���t�B�b�N�n���h�����쐬����( -1:�G���[  -1�ȊO:�O���t�B�b�N�n���h�� )
extern	int			ReCreateGraphFromSoftImage(     int SIHandle, int GrHandle ) ;																										// �\�t�g�E�G�A�ň����C���[�W��������̃O���t�B�b�N�n���h���ɉ摜�f�[�^��]������
extern	int			ReCreateGraphFromRectSoftImage( int SIHandle, int x, int y, int SizeX, int SizeY, int GrHandle ) ;																	// �\�t�g�E�G�A�ň����C���[�W��������̃O���t�B�b�N�n���h���ɉ摜�f�[�^��]������
extern	int			CreateDivGraphFromSoftImage(    int SIHandle, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf ) ;												// �\�t�g�E�G�A�ň����C���[�W���番���O���t�B�b�N�n���h�����쐬����
#endif // DX_NON_SOFTIMAGE
extern	int			CreateGraphFromBaseImage(       BASEIMAGE *BaseImage ) ;																											// ��{�C���[�W�f�[�^����O���t�B�b�N�n���h�����쐬����
extern	int			CreateGraphFromRectBaseImage(   BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY ) ;																		// ��{�C���[�W�f�[�^�̎w��̗̈���g���ăO���t�B�b�N�n���h�����쐬����
extern	int			ReCreateGraphFromBaseImage(     BASEIMAGE *BaseImage,                                     int GrHandle ) ;															// ��{�C���[�W�f�[�^��������̃O���t�B�b�N�n���h���ɉ摜�f�[�^��]������
extern	int			ReCreateGraphFromRectBaseImage( BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY, int GrHandle ) ;															// ��{�C���[�W�f�[�^�̎w��̗̈���g���Ċ����̃O���t�B�b�N�n���h���ɉ摜�f�[�^��]������
extern	int			CreateDivGraphFromBaseImage(    BASEIMAGE *BaseImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf ) ;										// ��{�C���[�W�f�[�^���番���O���t�B�b�N�n���h�����쐬����
extern	int			ReloadGraph(					const TCHAR *FileName, int GrHandle, int ReverseFlag = FALSE ) ;																	// �摜�t�@�C������O���t�B�b�N�n���h���։摜�f�[�^��]������
extern	int			ReloadDivGraph(					const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf, int ReverseFlag = FALSE ) ;			// �摜�t�@�C������O���t�B�b�N�n���h�������։摜�f�[�^�𕪊��]������
extern	int			ReloadReverseGraph(				const TCHAR *FileName, int GrHandle ) ;																								// ReloadGraph �̉摜���]�����ǉ���
extern	int			ReloadReverseDivGraph(			const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf ) ;										// ReloadDivGraph �̉摜���]�����ǉ���

// �O���t�B�b�N�n���h���쐬���ݒ�W�֐�
extern	int			SetGraphColorBitDepth(						int ColorBitDepth ) ;							// SetCreateGraphColorBitDepth �̋�����
extern 	int			GetGraphColorBitDepth(						void ) ;										// GetCreateGraphColorBitDepth �̋�����
extern	int			SetCreateGraphColorBitDepth(				int BitDepth ) ;								// �쐬����O���t�B�b�N�n���h���̐F�[�x��ݒ肷��
extern	int			GetCreateGraphColorBitDepth(				void ) ;										// �쐬����O���t�B�b�N�n���h���̐F�[�x���擾����
extern	int			SetCreateGraphChannelBitDepth(				int BitDepth ) ;								// �쐬����O���t�B�b�N�n���h���̂P�`�����l���ӂ�̃r�b�g�[�x��ݒ肷��
extern	int			GetCreateGraphChannelBitDepth(				void ) ;										// �쐬����O���t�B�b�N�n���h���̂P�`�����l���ӂ�̃r�b�g�[�x���擾����
extern	int			SetDrawValidGraphCreateFlag(				int Flag ) ;									// SetDrawScreen �Ɉ����Ƃ��ēn����( �`��ΏۂƂ��Ďg�p�ł��� )�O���t�B�b�N�n���h�����쐬���邩�ǂ�����ݒ肷��( TRUE:�`��\�O���t�B�b�N�n���h�����쐬����  FLASE:�ʏ�̃O���t�B�b�N�n���h�����쐬����( �f�t�H���g ) )
extern	int			GetDrawValidGraphCreateFlag(				void ) ;										// SetDrawScreen �Ɉ����Ƃ��ēn����( �`��ΏۂƂ��Ďg�p�ł��� )�O���t�B�b�N�n���h�����쐬���邩�ǂ�����ݒ���擾����
extern	int			SetDrawValidFlagOf3DGraph(					int Flag ) ;									// SetDrawValidGraphCreateFlag �̋�����
extern	int			SetLeftUpColorIsTransColorFlag(				int Flag ) ;									// �摜�t�@�C������O���t�B�b�N�n���h�����쐬����ۂɉ摜����̐F�𓧉ߐF�Ƃ��Ĉ������ǂ�����ݒ肷��( TRUE:���ߐF�Ƃ��Ĉ��� �@FALSE:���ߐF�Ƃ��Ĉ���Ȃ�( �f�t�H���g ) )
extern	int			SetUseBlendGraphCreateFlag(					int Flag ) ;									// �u�����h�����p�摜���쐬���邩�ǂ���( �v�͉摜�̐Ԑ������������Ƃ��Ĉ������ǂ��� )�̐ݒ���s��( TRUE:�u�����h�摜�Ƃ��ēǂݍ���  FALSE:�ʏ�摜�Ƃ��ēǂݍ���( �f�t�H���g ) )
extern	int			GetUseBlendGraphCreateFlag(					void ) ;										// �u�����h�����p�摜���쐬���邩�ǂ���( �v�͉摜�̐Ԑ������������Ƃ��Ĉ������ǂ��� )�̐ݒ���擾����
extern	int			SetUseAlphaTestGraphCreateFlag(				int Flag ) ;									// �A���t�@�e�X�g���g�p����O���t�B�b�N�n���h�����쐬���邩�ǂ�����ݒ肷��( TRUE:�A���t�@�e�X�g���g�p����( �f�t�H���g )  FALSE:�A���t�@�e�X�g���g�p���Ȃ� )
extern	int			GetUseAlphaTestGraphCreateFlag(				void ) ;										// �A���t�@�e�X�g���g�p����O���t�B�b�N�n���h�����쐬���邩�ǂ������擾����
extern	int			SetUseAlphaTestFlag(						int Flag ) ;									// SetUseAlphaTestGraphCreateFlag �̋�����
extern	int			GetUseAlphaTestFlag(						void ) ;										// GetUseAlphaTestGraphCreateFlag �̋�����
extern	int			SetUseNoBlendModeParam(						int Flag ) ;									// SetDrawBlendMode �֐��̑������� DX_BLENDMODE_NOBLEND ���������ۂɁA�f�t�H���g�ł͑������͓����łQ�T�T���w�肵�����ƂɂȂ邪�A���̎����Q�T�T�������Ȃ����ǂ�����ݒ肷��( TRUE:���Ȃ�(�������̒l���g�p�����)   FALSE:����(�������̒l�͖�������� 255 ����Ɏg�p�����)(�f�t�H���g) )���`�����l���t���摜�ɑ΂��ĕ`����s���ꍇ�݈̂Ӗ�������֐�
extern	int			SetDrawValidAlphaChannelGraphCreateFlag(	int Flag ) ;									// SetDrawScreen �̈����Ƃ��ēn����( �`��ΏۂƂ��Ďg�p�ł��� )���`�����l���t���O���t�B�b�N�n���h�����쐬���邩�ǂ�����ݒ肷��( SetDrawValidGraphCreateFlag �֐��ŕ`��ΏۂƂ��Ďg�p�ł���O���t�B�b�N�n���h�����쐬����悤�ɐݒ肳��Ă��Ȃ��ƌ��ʂ���܂��� )( TRUE:���`�����l���t��   FALSE:���`�����l���Ȃ�( �f�t�H���g ) )
extern	int			GetDrawValidAlphaChannelGraphCreateFlag(	void ) ;										// SetDrawScreen �̈����Ƃ��ēn����( �`��ΏۂƂ��Ďg�p�ł��� )���`�����l���t���O���t�B�b�N�n���h�����쐬���邩�ǂ������擾����
extern	int			SetDrawValidFloatTypeGraphCreateFlag(		int Flag ) ;									// SetDrawScreen �̈����Ƃ��ēn����( �`��ΏۂƂ��Ďg�p�ł��� )�s�N�Z���t�H�[�}�b�g�����������_�^�̃O���t�B�b�N�n���h�����쐬���邩�ǂ�����ݒ肷��( SetDrawValidGraphCreateFlag �֐��ŕ`��ΏۂƂ��Ďg�p�ł���O���t�B�b�N�n���h�����쐬����悤�ɐݒ肳��Ă��Ȃ��ƌ��ʂ���܂��� )�A�O���t�B�b�N�X�f�o�C�X�����������_�^�̃s�N�Z���t�H�[�}�b�g�ɑΉ����Ă��Ȃ��ꍇ�̓O���t�B�b�N�n���h���̍쐬�Ɏ��s����( TRUE:���������_�^�@�@FALSE:�����^( �f�t�H���g ) )
extern	int			GetDrawValidFloatTypeGraphCreateFlag(		void ) ;										// SetDrawScreen �̈����Ƃ��ēn����( �`��ΏۂƂ��Ďg�p�ł��� )�s�N�Z���t�H�[�}�b�g�����������_�^�̃O���t�B�b�N�n���h�����쐬���邩�ǂ������擾����
extern	int			SetDrawValidGraphCreateZBufferFlag(			int Flag ) ;									// SetDrawScreen �̈����Ƃ��ēn����( �`��ΏۂƂ��Ďg�p�ł��� )�O���t�B�b�N�n���h�����쐬����ۂɐ�p�̂y�o�b�t�@���쐬���邩�ǂ�����ݒ肷��( TRUE:��p�̂y�o�b�t�@���쐬����( �f�t�H���g )  FALSE:��p�̂y�o�b�t�@�͍쐬���Ȃ� )
extern	int			GetDrawValidGraphCreateZBufferFlag(			void ) ;										// SetDrawScreen �̈����Ƃ��ēn����( �`��ΏۂƂ��Ďg�p�ł��� )�O���t�B�b�N�n���h�����쐬����ۂɐ�p�̂y�o�b�t�@���쐬���邩�ǂ������擾����
extern	int			SetCreateDrawValidGraphChannelNum(			int ChannelNum ) ;								// SetDrawScreen �̈����Ƃ��ēn����( �`��ΏۂƂ��Ďg�p�ł��� )�O���t�B�b�N�n���h���ɓK�p����F�̃`�����l������ݒ肷��( ChannelNum:�`�����l����( �w��\�Ȓl�� 1, 2, 4 �̉��ꂩ( SetDrawValidGraphCreateFlag �֐��ŕ`��ΏۂƂ��Ďg�p�ł���O���t�B�b�N�n���h�����쐬����悤�ɐݒ肳��Ă��Ȃ��ƌ��ʂ���܂��� )
extern	int			GetCreateDrawValidGraphChannelNum(			void ) ;										// SetDrawScreen �̈����Ƃ��ēn����( �`��ΏۂƂ��Ďg�p�ł��� )�O���t�B�b�N�n���h���ɓK�p����F�̃`�����l�������擾����
extern	int			SetDrawValidMultiSample(					int Samples, int Quality ) ;					// SetDrawScreen �̈����Ƃ��ēn����( �`��ΏۂƂ��Ďg�p�ł��� )�O���t�B�b�N�n���h���ɓK�p����}���`�T���v�����O( �A���`�G�C���A�V���O )�ݒ���s��( Samples:�}���`�T���v�������Ɏg�p����h�b�g��( �����قǏd���Ȃ�܂� )  Quality:�}���`�T���v�������̕i�� )
extern	int			GetMultiSampleQuality(						int Samples ) ;									// �w��̃}���`�T���v�����Ŏg�p�ł���ő�N�I���e�B�l���擾����( �߂�l���}�C�i�X�̏ꍇ�͈����̃T���v�������g�p�ł��Ȃ����Ƃ������܂� )
extern	int			SetUseTransColor(							int Flag ) ;									// ���ߐF�@�\���g�p���邩�ǂ�����ݒ肷��( TRUE:�g�p����( �f�t�H���g )  FALSE:�g�p���Ȃ� )
extern	int			SetUseTransColorGraphCreateFlag(			int Flag ) ;									// ���ߐF�@�\���g�p���邱�Ƃ�O��Ƃ����摜�f�[�^�̓ǂݍ��ݏ������s�����ǂ�����ݒ肷��( TRUE �ɂ���� SetDrawMode( DX_DRAWMODE_BILINEAR ); ��������Ԃ� DrawGraphF ���̕��������_�^���W���󂯎��֐��ŏ����_�ȉ��̒l���w�肵���ꍇ�ɔ�������`�挋�ʂ̕s���R���ɘa������ʂ�����܂� ( �f�t�H���g�� FALSE ) )
extern 	int			SetUseGraphAlphaChannel(					int Flag ) ;									// SetUseAlphaChannelGraphCreateFlag �̋�����
extern 	int			GetUseGraphAlphaChannel(					void ) ;										// GetUseAlphaChannelGraphCreateFlag �̋�����
extern 	int			SetUseAlphaChannelGraphCreateFlag(			int Flag ) ;									// ���`�����l���t���O���t�B�b�N�n���h�����쐬���邩�ǂ�����ݒ肷��( TRUE:���`�����l���t��   FALSE:���`�����l������ )
extern 	int			GetUseAlphaChannelGraphCreateFlag(			void ) ;										// ���`�����l���t���O���t�B�b�N�n���h�����쐬���邩�ǂ������擾����( TRUE:���`�����l���t��   FALSE:���`�����l������ )
extern	int			SetUseNotManageTextureFlag(					int Flag ) ;									// Direct3D �̊Ǘ��e�N�X�`���@�\���g�p����O���t�B�b�N�n���h�����쐬���邩�ǂ�����ݒ肷��( TRUE:�Ǘ��@�\���g�p����( �f�t�H���g )  FALSE:�Ǘ��@�\���g�p���Ȃ� )�A�Ǘ��@�\���g�p����ƃO���t�B�b�N�X�f�o�C�X�̂u�q�`�l�e�ʈȏ�̉摜���������Ƃ��ł������ɃV�X�e���������̎g�p�ʂ������܂�
extern	int			GetUseNotManageTextureFlag(					void ) ;										// Direct3D �̊Ǘ��e�N�X�`���@�\���g�p����O���t�B�b�N�n���h�����쐬���邩�ǂ������擾����
extern	int			SetTransColor(								int Red, int Green, int Blue ) ;				// �쐬����O���t�B�b�N�n���h���ɓK�p���铧�ߐF��ݒ肷��( Red,Green,Blue:���ߐF�����̂R���F�ŕ\��������( �e�F�O�`�Q�T�T ) )
extern	int			GetTransColor(								int *Red, int *Green, int *Blue ) ;				// �쐬����O���t�B�b�N�n���h���ɓK�p���铧�ߐF���擾����
extern	int			SetUseDivGraphFlag(							int Flag ) ;									// �Q�̂���ł͂Ȃ��T�C�Y�̉摜�𕡐��̃e�N�X�`�����g�p���Ău�q�`�l�̖��ʂ��Ȃ����ǂ�����ݒ肷��( TRUE:�����̃e�N�X�`�����g�p����   FALSE:�Ȃ�ׂ��ꖇ�̃e�N�X�`���ōς܂�( �f�t�H���g ) )�A�����̃e�N�X�`�����g�p����ꍇ�͂u�q�`�l�e�ʂ̐ߖ񂪂ł������ɑ��x�̒ቺ��o�C���j�A�t�B���^�����O�`�掞�Ƀe�N�X�`���ƃe�N�X�`���̋��ڂ��ǂ�����Ƃ킩�铙�̕��Q������܂�
extern	int			SetUseMaxTextureSize(						int Size ) ;									// �g�p����e�N�X�`���[�̍ő�T�C�Y��ݒ肷��( �f�t�H���g�ł̓O���t�B�b�N�X�f�o�C�X���Ή����Ă���ő�e�N�X�`���[�T�C�Y�A������ 0 ��n���ƃf�t�H���g�ݒ�ɂȂ�܂� )
extern	int			SetUseGraphBaseDataBackup(					int Flag ) ;									// �O���t�B�b�N�n���h�����쐬����ۂɎg�p�����摜�f�[�^�̃o�b�N�A�b�v������ Direct3DDevice �̃f�o�C�X���X�g���Ɏg�p���邩�ǂ�����ݒ肷��( TRUE:�o�b�N�A�b�v������( �f�t�H���g )  FALSE:�o�b�N�A�b�v�����Ȃ� )�A�o�b�N�A�b�v�����Ȃ��ƃ������̐ߖ�ɂȂ�܂����A���A�Ɋ|���鎞�Ԃ������Ȃ�A��������̃t�@�C���C���[�W����O���t�B�b�N�n���h�����쐬�����ꍇ�͎������A���ł��Ȃ��Ȃǂ̕��Q������܂�
extern	int			GetUseGraphBaseDataBackup(					void ) ;										// �O���t�B�b�N�n���h�����쐬����ۂɎg�p�����摜�f�[�^�̃o�b�N�A�b�v������ Direct3DDevice �̃f�o�C�X���X�g���Ɏg�p���邩�ǂ������擾����
extern	int			SetUseSystemMemGraphCreateFlag(				int Flag ) ;									// ( ���݌��ʂȂ� )�O���t�B�b�N�n���h�������摜�f�[�^���V�X�e����������ɍ쐬���邩�ǂ�����ݒ肷��( TRUE:�V�X�e����������ɍ쐬  FALSE:�u�q�`�l��ɍ쐬( �f�t�H���g ) )
extern	int			GetUseSystemMemGraphCreateFlag(				void ) ;										// ( ���݌��ʂȂ� )�O���t�B�b�N�n���h�������摜�f�[�^���V�X�e����������ɍ쐬���邩�ǂ������擾����

// �摜���֌W�֐�
extern	DWORD*		GetFullColorImage(				int GrHandle ) ;																		// �w��̃O���t�B�b�N�n���h���̂`�q�f�a�W�C���[�W���擾����( ���ݓ���t�@�C�����O���t�B�b�N�n���h���œǂݍ��񂾏ꍇ�̂ݎg�p�\ )

extern	int			GraphLock(						int GrHandle, int *PitchBuf, void **DataPointBuf, COLORDATA **ColorDataPP = NULL ) ;	// �O���t�B�b�N�������̈�̃��b�N
extern	int			GraphUnLock(					int GrHandle ) ;																		// �O���t�B�b�N�������̈�̃��b�N����

extern	int			SetUseGraphZBuffer(				int GrHandle, int UseFlag ) ;															// �O���t�B�b�N�n���h����p�̂y�o�b�t�@�������ǂ�����ݒ肷��( GrHandle:�ΏۂƂȂ�O���t�B�b�N�n���h��( �`��ΏۂƂ��Ďg�p�\�ȃO���t�B�b�N�n���h���̂ݗL�� )  UseFlag:��p�̂y�o�b�t�@�������ǂ���( TRUE:����( �f�t�H���g )  FALSE:�����Ȃ� ) )
extern	int			CopyGraphZBufferImage(			int DestGrHandle, int SrcGrHandle ) ;													// �O���t�B�b�N�n���h���̂y�o�b�t�@�̏�Ԃ�ʂ̃O���t�B�b�N�n���h���̂y�o�b�t�@�ɃR�s�[����( DestGrHandle �� SrcGrHandle ���y�o�b�t�@�������Ă���`��Ώۂɂł���O���t�B�b�N�n���h���ŁA�T�C�Y�������ł���A���}���`�T���v�����O( �A���`�G�C���A�X )�ݒ肪�������Ƃ����� )

extern	int			GetGraphSize(					int GrHandle, int *SizeXBuf, int *SizeYBuf ) ;											// �O���t�B�b�N�n���h�������摜�̃T�C�Y�𓾂�
extern	int			GetGraphTextureSize(			int GrHandle, int *SizeXBuf, int *SizeYBuf ) ;											// �O���t�B�b�N�n���h��������ڂ̃e�N�X�`���̃T�C�Y�𓾂�
extern	int			GetGraphMipmapCount(			int GrHandle ) ;																		// �O���t�B�b�N�n���h�������e�N�X�`���̃~�b�v�}�b�v���x�������擾����

extern	COLORDATA*	GetTexColorData(				int AlphaCh, int AlphaTest, int ColorBitDepth, int DrawValid = FALSE ) ;				// �J���[�f�[�^�𓾂�
extern	COLORDATA*	GetTexColorData(				IMAGEFORMATDESC *Format ) ;																// �t�H�[�}�b�g�Ɋ�Â����J���[�f�[�^�𓾂�
extern	COLORDATA*	GetTexColorData(				int FormatIndex ) ;																		// �w��̃t�H�[�}�b�g�C���f�b�N�X�̃J���[�f�[�^�𓾂�
extern	int			GetMaxGraphTextureSize(			int *SizeX, int *SizeY ) ;																// �O���t�B�b�N�X�f�o�C�X���Ή����Ă���ő�e�N�X�`���T�C�Y���擾����
extern	int			GetValidRestoreShredPoint(		void ) ;																				// �O���t�B�b�N�n���h���̉摜�𕜌�����֐����o�^����Ă��邩�ǂ������擾����( TRUE:�o�^����Ă���  FALSE:�o�^����Ă��Ȃ� )
extern	int			GetCreateGraphColorData(		COLORDATA *ColorData, IMAGEFORMATDESC *Format ) ;										// ���ꂩ��V���ɃO���t�B�b�N���쐬����ꍇ�Ɏg�p����J���[�����擾����

// �摜�p���b�g����֌W�֐�( �\�t�g�E�G�A�摜�̂ݎg�p�\ )
extern	int			GetGraphPalette(				int GrHandle, int ColorIndex, int *Red, int *Green, int *Blue ) ;						// �O���t�B�b�N�n���h���̃p���b�g���擾����( �\�t�g�E�G�A�����_�����O���[�h�ŁA���p���b�g�摜�̏ꍇ�̂ݎg�p�\ )
extern  int			GetGraphOriginalPalette(		int GrHandle, int ColorIndex, int *Red, int *Green, int *Blue ) ;						// �O���t�B�b�N�n���h���� SetGraphPalette �ŕύX����O�̃p���b�g���擾����( �\�t�g�E�G�A�����_�����O���[�h�ŁA���p���b�g�摜�̏ꍇ�̂ݎg�p�\ )
extern	int			SetGraphPalette(				int GrHandle, int ColorIndex, int Color ) ;												// �O���t�B�b�N�n���h���̃p���b�g��ύX����( �\�t�g�E�G�A�����_�����O���[�h�ŁA���p���b�g�摜�̏ꍇ�̂ݎg�p�\ )
extern	int			ResetGraphPalette(				int GrHandle ) ;																		// SetGraphPalette �ŕύX�����p���b�g��S�Č��ɖ߂�( �\�t�g�E�G�A�����_�����O���[�h�ŁA���p���b�g�摜�̏ꍇ�̂ݎg�p�\ )

// �}�`�`��֐�
extern	int			DrawLine(       int x1, int y1, int x2, int y2,                                 int Color, int Thickness = 1 ) ;		// ����`�悷��
extern	int			DrawBox(        int x1, int y1, int x2, int y2,                                 int Color, int FillFlag ) ;				// �l�p�`�̕`�悷��
extern	int			DrawFillBox(    int x1, int y1, int x2, int y2,                                 int Color ) ;							// ���g��h��Ԃ��l�p�`��`�悷��
extern	int			DrawLineBox(    int x1, int y1, int x2, int y2,                                 int Color ) ;							// �g�����̎l�p�`�̕`�� ����
extern	int			DrawCircle(     int x, int y, int r,                                            int Color, int FillFlag = TRUE ) ;		// �~��`�悷��
extern	int			DrawOval(       int x, int y, int rx, int ry,                                   int Color, int FillFlag ) ;				// �ȉ~��`�悷��
extern	int			DrawTriangle(   int x1, int y1, int x2, int y2, int x3, int y3,                 int Color, int FillFlag ) ;				// �O�p�`��`�悷��
extern	int			DrawQuadrangle( int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int Color, int FillFlag ) ;				// �l�p�`��`�悷��
extern 	int			DrawPixel(      int x, int y,                                                   int Color ) ;							// �_��`�悷��

extern	int			Paint(			int x, int y, int FillColor, int BoundaryColor = -1 ) ;													// �w��_���狫�E�F������Ƃ���܂œh��Ԃ�(���E�F�� -1 �ɂ���Ǝw��_�̐F�̗̈��h��Ԃ�)

extern 	int			DrawPixelSet(   POINTDATA *PointData, int Num ) ;																		// �_�̏W����`�悷��
extern	int			DrawLineSet(    LINEDATA *LineData,   int Num ) ;																		// ���̏W����`�悷��

extern	int			DrawPixel3D(    VECTOR Pos,                                                            int Color ) ;					// �R�c�̓_��`�悷��
extern	int			DrawLine3D(     VECTOR Pos1, VECTOR Pos2,                                              int Color ) ;					// �R�c�̐�����`�悷��
extern	int			DrawTriangle3D( VECTOR Pos1, VECTOR Pos2, VECTOR Pos3,                                 int Color, int FillFlag ) ;		// �R�c�̎O�p�`��`�悷��
extern	int			DrawCube3D(     VECTOR Pos1, VECTOR Pos2,                             int DifColor, int SpcColor, int FillFlag ) ;		// �R�c�̗����̂�`�悷��
extern	int			DrawSphere3D(   VECTOR CenterPos,                float r, int DivNum, int DifColor, int SpcColor, int FillFlag ) ;		// �R�c�̋��̂�`�悷��
extern	int			DrawCapsule3D(  VECTOR Pos1, VECTOR Pos2,        float r, int DivNum, int DifColor, int SpcColor, int FillFlag ) ;		// �R�c�̃J�v�Z����`�悷��
extern	int			DrawCone3D(     VECTOR TopPos, VECTOR BottomPos, float r, int DivNum, int DifColor, int SpcColor, int FillFlag ) ;		// �R�c�̉~����`�悷��

// �摜�`��֐�
extern	int			LoadGraphScreen(          int x, int y, const TCHAR *GraphName, int TransFlag ) ;										// �摜�t�@�C����ǂ݂���ŉ�ʂɕ`�悷��

extern	int			DrawGraph(                int x, int y,                                                                 int GrHandle, int TransFlag ) ;										// �摜�̓��{�`��
extern	int			DrawExtendGraph(          int x1, int y1, int x2, int y2,                                               int GrHandle, int TransFlag ) ;										// �摜�̊g��`��
extern	int			DrawRotaGraph(            int x, int y,                 double ExRate,                    double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) ;				// �摜�̉�]�`��
extern	int			DrawRotaGraph2(           int x, int y, int cx, int cy, double ExtRate,                   double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) ;				// �摜�̉�]�`��Q( ��]���S�w��t�� )
extern	int			DrawRotaGraph3(           int x, int y, int cx, int cy, double ExtRateX, double ExtRateY, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE ) ; 				// �摜�̉�]�`��R( ��]���S�w��t���{�c���g�嗦�ʎw��� )
extern	int			DrawModiGraph(            int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4,               int GrHandle, int TransFlag ) ;										// �摜�̎��R�ό`�`��
extern	int			DrawTurnGraph(            int x, int y,                                                                 int GrHandle, int TransFlag ) ;										// �摜�̍��E���]�`��

extern	int			DrawGraphF(               float xf, float yf,                                                                       int GrHandle, int TransFlag ) ;							// �摜�̕`��( ���W�w�肪 float �� )
extern	int			DrawExtendGraphF(         float x1f, float y1f, float x2f, float y2,                                                int GrHandle, int TransFlag ) ;							// �摜�̊g��`��( ���W�w�肪 float �� )
extern	int			DrawRotaGraphF(           float xf, float yf,                       double ExRate,                    double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) ;	// �摜�̉�]�`��( ���W�w�肪 float �� )
extern	int			DrawRotaGraph2F(          float xf, float yf, float cxf, float cyf, double ExtRate,                   double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) ;	// �摜�̉�]�`��Q( ��]���S�w��t�� )( ���W�w�肪 float �� )
extern	int			DrawRotaGraph3F(          float xf, float yf, float cxf, float cyf, double ExtRateX, double ExtRateY, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE ) ; 	// �摜�̉�]�`��R( ��]���S�w��t���{�c���g�嗦�ʎw��� )( ���W�w�肪 float �� )
extern	int			DrawModiGraphF(           float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4,           int GrHandle, int TransFlag ) ;							// �摜�̎��R�ό`�`��( ���W�w�肪 float �� )
extern	int			DrawTurnGraphF(           float xf, float yf,                                                                       int GrHandle, int TransFlag ) ;							// �摜�̍��E���]�`��( ���W�w�肪 float �� )

extern	int			DrawChipMap(              int Sx, int Sy, int XNum, int YNum, int *MapData, int ChipTypeNum, int MapDataPitch, int *ChipGrHandle, int TransFlag ) ;																											// �`�b�v�摜���g�����Q�c�}�b�v�`��
extern	int			DrawChipMap(              int MapWidth, int MapHeight,        int *MapData, int ChipTypeNum,                   int *ChipGrHandle, int TransFlag, int MapDrawPointX, int MapDrawPointY, int MapDrawWidth, int MapDrawHeight, int ScreenX, int ScreenY ) ;	// �`�b�v�摜���g�����Q�c�}�b�v�`��
extern	int			DrawTile(                 int x1, int y1, int x2, int y2, int Tx, int Ty, double ExtRate, double Angle, int GrHandle, int TransFlag ) ;																														// �摜���w��̈�Ƀ^�C����ɕ`�悷��

extern	int			DrawRectGraph(            int DestX,  int DestY,                          int SrcX, int SrcY, int    Width, int    Height,                         int GraphHandle, int TransFlag, int TurnFlag ) ;				// �摜�̎w���`�����݂̂𓙔{�`��
extern	int			DrawRectExtendGraph(      int DestX1, int DestY1, int DestX2, int DestY2, int SrcX, int SrcY, int SrcWidth, int SrcHeight,                         int GraphHandle, int TransFlag ) ;							// �摜�̎w���`�����݂̂��g��`��
extern	int			DrawRectRotaGraph(        int x, int y, int SrcX, int SrcY, int Width, int Height, double ExtRate, double Angle,                                   int GraphHandle, int TransFlag, int TurnFlag ) ;				// �摜�̎w���`�����݂̂���]�`��
extern	int			DrawRectRotaGraph2(       int x, int y, int SrcX, int SrcY, int Width, int Height, int cx, int cy, double ExtRate,  double Angle,                  int GraphHandle, int TransFlag, int TurnFlag ) ;				// �摜�̎w���`�����݂̂���]�`��Q( ��]���S�w��t�� )
extern	int			DrawRectRotaGraph3(       int x, int y, int SrcX, int SrcY, int Width, int Height, int cx, int cy, double ExtRateX, double ExtRateY, double Angle, int GraphHandle, int TransFlag, int TurnFlag ) ;				// �摜�̎w���`�����݂̂���]�`��R( ��]���S�w��t���{�c���g�嗦�ʎw��� )

extern	int			DrawRectGraphF(           float DestX,  float DestY,                              int SrcX, int SrcY, int    Width, int    Height,                           int GraphHandle, int TransFlag, int TurnFlag ) ;	// �摜�̎w���`�����݂̂𓙔{�`��( ���W�w�肪 float �� )
extern	int			DrawRectExtendGraphF(     float DestX1, float DestY1, float DestX2, float DestY2, int SrcX, int SrcY, int SrcWidth, int SrcHeight,                           int GraphHandle, int TransFlag ) ;					// �摜�̎w���`�����݂̂��g��`��( ���W�w�肪 float �� )
extern	int			DrawRectRotaGraphF(       float x, float y, int SrcX, int SrcY, int Width, int Height,                       double ExtRate,                   double Angle, int GraphHandle, int TransFlag, int TurnFlag ) ;	// �摜�̎w���`�����݂̂���]�`��( ���W�w�肪 float �� )
extern	int			DrawRectRotaGraph2F(      float x, float y, int SrcX, int SrcY, int Width, int Height, float cxf, float cyf, double ExtRate,                   double Angle, int GraphHandle, int TransFlag, int TurnFlag ) ;	// �摜�̎w���`�����݂̂���]�`��Q( ��]���S�w��t�� )( ���W�w�肪 float �� )
extern	int			DrawRectRotaGraph3F(      float x, float y, int SrcX, int SrcY, int Width, int Height, float cxf, float cyf, double ExtRateX, double ExtRateY, double Angle, int GraphHandle, int TransFlag, int TurnFlag ) ;	// �摜�̎w���`�����݂̂���]�`��R( ��]���S�w��t���{�c���g�嗦�ʎw��� )( ���W�w�肪 float �� )

extern	int			DrawBlendGraph(           int x, int y, int GrHandle, int TransFlag,                 int BlendGraph, int BorderParam, int BorderRange ) ;									// �u�����h�摜�ƍ������ĉ摜�𓙔{�`�悷��
extern	int			DrawBlendGraphPos(        int x, int y, int GrHandle, int TransFlag, int bx, int by, int BlendGraph, int BorderParam, int BorderRange ) ;									// �u�����h�摜�ƍ������ĉ摜�𓙔{�`�悷��( �u�����h�摜�̋N�_���W���w�肷������t�� )

extern	int			DrawCircleGauge(          int CenterX, int CenterY, double Percent, int GrHandle ) ;																						// �~�O���t�I�ȕ`����s��( GrHandle �̉摜�̏㉺���E�̒[�͓��ߐF�ɂ��Ă����K�v������܂� )

extern	int			DrawGraphToZBuffer(       int X, int Y,                                                                 int GrHandle, int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;							// �y�o�b�t�@�ɑ΂��ĉ摜�̓��{�`��
extern	int			DrawTurnGraphToZBuffer(   int x, int y,                                                                 int GrHandle, int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;							// �y�o�b�t�@�ɑ΂��ĉ摜�̍��E���]�`��
extern	int			DrawExtendGraphToZBuffer( int x1, int y1, int x2, int y2,                                               int GrHandle, int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;							// �y�o�b�t�@�ɑ΂��ĉ摜�̊g��`��
extern	int			DrawRotaGraphToZBuffer(   int x, int y, double ExRate, double Angle,                                    int GrHandle, int WriteZMode /* DX_ZWRITE_MASK �� */ , int TurnFlag = FALSE ) ;		// �y�o�b�t�@�ɑ΂��ĉ摜�̉�]�`��
extern	int			DrawRotaGraph2ToZBuffer(  int x, int y, int cx, int cy, double ExtRate,                   double Angle, int GrHandle, int WriteZMode /* DX_ZWRITE_MASK �� */ , int TurnFlag = FALSE ) ;		// �y�o�b�t�@�ɑ΂��ĉ摜�̉�]�`��Q( ��]���S�w��t�� )
extern	int			DrawRotaGraph3ToZBuffer(  int x, int y, int cx, int cy, double ExtRateX, double ExtRateY, double Angle, int GrHandle, int WriteZMode /* DX_ZWRITE_MASK �� */ , int TurnFlag = FALSE ) ; 	// �y�o�b�t�@�ɑ΂��ĉ摜�̉�]�`��R( ��]���S�w��t���{�c���g�嗦�ʎw��� )
extern	int			DrawModiGraphToZBuffer(   int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4,               int GrHandle, int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;							// �y�o�b�t�@�ɑ΂��ĉ摜�̎��R�ό`�`��
extern	int			DrawBoxToZBuffer(         int x1, int y1, int x2, int y2,                                               int FillFlag, int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;							// �y�o�b�t�@�ɑ΂��ċ�`�̕`��
extern	int			DrawCircleToZBuffer(      int x, int y, int r,                                                          int FillFlag, int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;							// �y�o�b�t�@�ɑ΂��ĉ~�̕`��

extern	int			DrawPolygon(                             VERTEX    *Vertex, int PolygonNum,                                                                                              int GrHandle, int TransFlag, int UVScaling = FALSE ) ;		// �Q�c�|���S����`�悷��( Vertex:�O�p�`���`�����钸�_�z��̐擪�A�h���X( ���_�̐��̓|���S���̐��~�R )  PolygonNum:�`�悷��|���S���̐�  GrHandle:�g�p����O���t�B�b�N�n���h��  TransFlag:���ߐF�������s�����ǂ���( TRUE:�s��  FALSE:�s��Ȃ� )  UVScaling:��{FALSE��OK )
extern	int			DrawPolygon2D(                           VERTEX2D  *Vertex, int PolygonNum,                                                                                              int GrHandle, int TransFlag ) ;							// �Q�c�|���S����`�悷��
extern	int			DrawPolygon3D(                           VERTEX3D  *Vertex, int PolygonNum,                                                                                              int GrHandle, int TransFlag ) ;							// �R�c�|���S����`�悷��
extern	int			DrawPolygonIndexed2D(                    VERTEX2D  *Vertex, int VertexNum, unsigned short *Indices, int PolygonNum,                                                      int GrHandle, int TransFlag ) ;							// �Q�c�|���S����`�悷��( ���_�C���f�b�N�X���g�p )
extern	int			DrawPolygonIndexed3D(                    VERTEX3D  *Vertex, int VertexNum, unsigned short *Indices, int PolygonNum,                                                      int GrHandle, int TransFlag ) ;							// �R�c�|���S����`�悷��( ���_�C���f�b�N�X���g�p )
extern	int			DrawPolygonIndexed3DBase(                VERTEX_3D *Vertex, int VertexNum, unsigned short *Indices, int IndexNum,   int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST �� */, int GrHandle, int TransFlag ) ;							// �R�c�|���S����`�悷��( ���_�C���f�b�N�X���g�p )( ���o�[�W�����p )
extern	int			DrawPolygon3DBase(                       VERTEX_3D *Vertex, int VertexNum,                                          int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST �� */, int GrHandle, int TransFlag ) ;							// �R�c�|���S����`�悷��( ���o�[�W�����p )
extern	int			DrawPolygon3D(                           VERTEX_3D *Vertex, int PolygonNum,                                                                                              int GrHandle, int TransFlag ) ;							// �R�c�|���S����`�悷��( ���o�[�W�����p )

extern	int			DrawPolygonBase(                         VERTEX    *Vertex, int VertexNum,                                          int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST �� */, int GrHandle, int TransFlag, int UVScaling = FALSE ) ;		// �Q�c�v���~�e�B�u��`�悷��
extern	int			DrawPrimitive2D(                         VERTEX2D  *Vertex, int VertexNum,                                          int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST �� */, int GrHandle, int TransFlag ) ;							// �Q�c�v���~�e�B�u��`�悷��
extern	int			DrawPrimitive3D(                         VERTEX3D  *Vertex, int VertexNum,                                          int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST �� */, int GrHandle, int TransFlag ) ;							// �R�c�v���~�e�B�u��`�悷��
extern	int			DrawPrimitiveIndexed2D(                  VERTEX2D  *Vertex, int VertexNum, unsigned short *Indices, int IndexNum,   int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST �� */, int GrHandle, int TransFlag ) ;							// �Q�c�v���~�e�B�u��`�悷��(���_�C���f�b�N�X�g�p)
extern	int			DrawPrimitiveIndexed3D(                  VERTEX3D  *Vertex, int VertexNum, unsigned short *Indices, int IndexNum,   int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST �� */, int GrHandle, int TransFlag ) ;							// �R�c�v���~�e�B�u��`�悷��(���_�C���f�b�N�X�g�p)

extern	int			DrawPolygon3D_UseVertexBuffer(           int VertexBufHandle,                                                                                                                                                               int GrHandle, int TransFlag ) ;		// ���_�o�b�t�@���g�p���ĂR�c�|���S����`�悷��
extern	int			DrawPrimitive3D_UseVertexBuffer(         int VertexBufHandle,                     int PrimitiveType  /* DX_PRIMTYPE_TRIANGLELIST �� */,                                                                                     int GrHandle, int TransFlag ) ;		// ���_�o�b�t�@���g�p���ĂR�c�v���~�e�B�u��`�悷��
extern	int			DrawPrimitive3D_UseVertexBuffer2(        int VertexBufHandle,                     int PrimitiveType  /* DX_PRIMTYPE_TRIANGLELIST �� */,                 int StartVertex, int UseVertexNum,                                  int GrHandle, int TransFlag ) ;		// ���_�o�b�t�@���g�p���ĂR�c�v���~�e�B�u��`�悷��
extern	int			DrawPolygonIndexed3D_UseVertexBuffer(    int VertexBufHandle, int IndexBufHandle,                                                                                                                                           int GrHandle, int TransFlag ) ;		// ���_�o�b�t�@�ƃC���f�b�N�X�o�b�t�@���g�p���ĂR�c�|���S����`�悷��
extern	int			DrawPrimitiveIndexed3D_UseVertexBuffer(  int VertexBufHandle, int IndexBufHandle, int PrimitiveType  /* DX_PRIMTYPE_TRIANGLELIST �� */,                                                                                     int GrHandle, int TransFlag ) ;		// ���_�o�b�t�@�ƃC���f�b�N�X�o�b�t�@���g�p���ĂR�c�v���~�e�B�u��`�悷��
extern	int			DrawPrimitiveIndexed3D_UseVertexBuffer2( int VertexBufHandle, int IndexBufHandle, int PrimitiveType  /* DX_PRIMTYPE_TRIANGLELIST �� */, int BaseVertex, int StartVertex, int UseVertexNum, int StartIndex, int UseIndexNum, int GrHandle, int TransFlag ) ;		// ���_�o�b�t�@�ƃC���f�b�N�X�o�b�t�@���g�p���ĂR�c�v���~�e�B�u��`�悷��

extern	int			DrawGraph3D(                             float x, float y, float z,                                                                     int GrHandle, int TransFlag ) ;								// �摜�̂R�c�`��
extern	int			DrawExtendGraph3D(                       float x, float y, float z, double ExRateX, double ExRateY,                                     int GrHandle, int TransFlag ) ;								// �摜�̊g��R�c�`��
extern	int			DrawRotaGraph3D(                         float x, float y, float z, double ExRate, double Angle,                                        int GrHandle, int TransFlag, int TurnFlag = FALSE ) ;		// �摜�̉�]�R�c�`��
extern	int			DrawRota2Graph3D(                        float x, float y, float z, float cx, float cy, double ExtRateX, double ExtRateY, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE ) ;		// �摜�̉�]�R�c�`��(��]���S�w��^)
extern	int			DrawModiBillboard3D(                     VECTOR Pos, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4,    int GrHandle, int TransFlag ) ;								// �摜�̎��R�ό`�R�c�`��
extern	int			DrawBillboard3D(                         VECTOR Pos, float cx, float cy, float Size, float Angle,                                       int GrHandle, int TransFlag, int TurnFlag = FALSE ) ;		// �R�c��ԏ�ɉ摜��`��


// �`��ݒ�֌W�֐�
extern	int			SetDrawMode(						int DrawMode ) ;												// �`�惂�[�h��ݒ肷��
extern	int			GetDrawMode(						void ) ;														// �`�惂�[�h���擾����
extern	int			SetDrawBlendMode(					int BlendMode, int BlendParam ) ;								// �`��u�����h���[�h��ݒ肷��
extern	int			GetDrawBlendMode(					int *BlendMode, int *BlendParam ) ;								// �`��u�����h���[�h���擾����
extern	int			SetDrawAlphaTest(					int TestMode, int TestParam ) ;									// �`�掞�̃A���t�@�e�X�g�̐ݒ���s��( TestMode:�e�X�g���[�h( DX_CMP_GREATER�� -1�Ńf�t�H���g����ɖ߂� )  TestParam:�`��A���t�@�l�Ƃ̔�r�Ɏg�p����l( 0�`255 ) )
extern	int			SetBlendGraph(						int BlendGraph, int BorderParam, int BorderRange ) ;			// ( SetBlendGraphParam �� BlendType = DX_BLENDGRAPHTYPE_WIPE �̏������s�����֐� )�`�揈�����ɕ`�悷��摜�ƃu�����h���郿�`�����l���t���摜���Z�b�g����( BlendGraph �� -1 �Ńu�����h�@�\�𖳌� )
extern	int			SetBlendGraphParam(					int BlendGraph, int BlendType, ... ) ;							// �`�揈�����ɕ`�悷��摜�ƃu�����h����摜�̃u�����h�ݒ���s���ABlendGraph �� -1 �ɂ���ΐݒ�������A���̏ꍇ BlendType �Ƃ��̌��̃p�����[�^�͖��������
//		int			SetBlendGraphParam(					int BlendGraph, int BlendType = DX_BLENDGRAPHTYPE_NORMAL, int Ratio = ( 0( �u�����h���O�� )�`255( �u�����h���P�O�O�� ) ) ) ;
//		int			SetBlendGraphParam(					int BlendGraph, int BlendType = DX_BLENDGRAPHTYPE_WIPE, int BorderParam, int BorderRange ) ;
//		int			SetBlendGraphParam(					int BlendGraph, int BlendType = DX_BLENDGRAPHTYPE_ALPHA ) ;
extern	int			SetBlendGraphPosition(				int x, int y ) ;												// �u�����h�摜�̋N�_���W���Z�b�g����
extern	int			SetDrawBright(						int RedBright, int GreenBright, int BlueBright ) ;				// �`��P�x��ݒ肷��
extern	int			GetDrawBright(						int *Red, int *Green, int *Blue ) ;								// �`��P�x���擾����
extern	int			SetIgnoreDrawGraphColor(			int EnableFlag ) ;												// �`�悷��摜�̂q�f�a�����𖳎����邩�ǂ������w�肷��( EnableFlag:���̋@�\���g�����ǂ���( TRUE:�g��  FALSE:�g��Ȃ�( �f�t�H���g ) ) )
extern	int			SetMaxAnisotropy(					int MaxAnisotropy ) ;											// �ő�ٕ����l��ݒ肷��

extern	int			SetUseZBufferFlag(					int Flag ) ;													// �y�o�b�t�@���g�p���邩�ǂ�����ݒ肷��( �Q�c�ƂR�c�`��ɉe�� )( TRUE:�y�o�b�t�@���g�p����  FALSE:�y�o�b�t�@���g�p���Ȃ�( �f�t�H���g ) )
extern	int			SetWriteZBufferFlag(				int Flag ) ;													// �y�o�b�t�@�ɏ������݂��s�����ǂ�����ݒ肷��( �Q�c�ƂR�c�`��ɉe�� )( TRUE:�������݂��s��  FALSE:�������݂��s��Ȃ�( �f�t�H���g ) )
extern	int			SetZBufferCmpType(					int CmpType /* DX_CMP_NEVER �� */ ) ;							// �y�o�b�t�@�̂y�l�Ə������ނy�l�Ƃ̔�r���[�h��ݒ肷��( �Q�c�ƂR�c�`��ɉe�� )( CmpType:DX_CMP_NEVER��( �f�t�H���g:DX_CMP_LESSEQUAL ) )
extern	int			SetZBias(							int Bias ) ;													// �������ނy�l�̃o�C�A�X��ݒ肷��( �Q�c�ƂR�c�`��ɉe�� )( Bias:�o�C�A�X�l( �f�t�H���g:0 ) )
extern	int			SetUseZBuffer3D(					int Flag ) ;													// �y�o�b�t�@���g�p���邩�ǂ�����ݒ肷��( �R�c�`��݂̂ɉe�� )( TRUE:�y�o�b�t�@���g�p����  FALSE:�y�o�b�t�@���g�p���Ȃ�( �f�t�H���g ) )
extern	int			SetWriteZBuffer3D(					int Flag ) ;													// �y�o�b�t�@�ɏ������݂��s�����ǂ�����ݒ肷��( �R�c�`��݂̂ɉe�� )( TRUE:�������݂��s��  FALSE:�������݂��s��Ȃ�( �f�t�H���g ) )
extern	int			SetZBufferCmpType3D(				int CmpType /* DX_CMP_NEVER �� */ ) ;							// �y�o�b�t�@�̂y�l�Ə������ނy�l�Ƃ̔�r���[�h��ݒ肷��( �R�c�`��݂̂ɉe�� )( CmpType:DX_CMP_NEVER��( �f�t�H���g:DX_CMP_LESSEQUAL ) )
extern	int			SetZBias3D(							int Bias ) ;													// �������ނy�l�̃o�C�A�X��ݒ肷��( �R�c�`��݂̂ɉe�� )( Bias:�o�C�A�X�l( �f�t�H���g:0 ) )
extern	int			SetDrawZ(							float Z ) ;														// �Q�c�`��ły�o�b�t�@�ɏ������ނy�l��ݒ肷��( Z:�������ނy�l( �f�t�H���g:0.2f ) )

extern	int			SetDrawArea(						int x1, int y1, int x2, int y2 ) ;								// �`��\�̈�̐ݒ肷��
extern	int			GetDrawArea(						RECT *Rect ) ;													// �`��\�̈���擾����
extern	int			SetDrawAreaFull(					void ) ;														// �`��\�̈��`��Ώۉ�ʑS�̂ɂ���
extern	int			SetDraw3DScale(						float Scale ) ;													// �R�c�`��̊g�嗦��ݒ肷��

extern	int			SetRestoreShredPoint(				void (* ShredPoint )( void ) ) ;								// SetRestoreGraphCallback �̋���
extern	int			SetRestoreGraphCallback(			void (* Callback )( void ) ) ;									// �O���t�B�b�N�n���h�������֐���o�^����
extern	int			RunRestoreShred(					void ) ;														// �O���t�B�b�N�����֐������s����
extern	int			SetGraphicsDeviceRestoreCallbackFunction( void (* Callback )( void *Data ), void *CallbackData ) ;	// �O���t�B�b�N�X�f�o�C�X�����X�g���畜�A�����ۂɌĂ΂��R�[���o�b�N�֐���ݒ肷��
extern	int			SetGraphicsDeviceLostCallbackFunction(    void (* Callback )( void *Data ), void *CallbackData ) ;	// �O���t�B�b�N�X�f�o�C�X�����X�g���畜�A����O�ɌĂ΂��R�[���o�b�N�֐���ݒ肷��

extern	int			SetTransformToWorld(				MATRIX *Matrix ) ;												// ���[�J�����W���烏�[���h���W�ɕϊ����邽�߂̍s���ݒ肷��
extern	int			GetTransformToWorldMatrix(			MATRIX *MatBuf ) ;												// ���[�J�����W���烏�[���h���W�ɕϊ����邽�߂̍s����擾����
extern	int			SetTransformToView(					MATRIX *Matrix ) ;												// ���[���h���W����r���[���W�ɕϊ����邽�߂̍s���ݒ肷��
extern	int			GetTransformToViewMatrix(			MATRIX *MatBuf ) ;												// ���[���h���W����r���[���W�ɕϊ����邽�߂̍s����擾����
extern	int			SetTransformToProjection(			MATRIX *Matrix ) ;												// �r���[���W����v���W�F�N�V�������W�ɕϊ����邽�߂̍s���ݒ肷��
extern	int			GetTransformToProjectionMatrix(		MATRIX *MatBuf ) ;												// �r���[���W����v���W�F�N�V�������W�ɕϊ����邽�߂̍s����擾����
extern	int			SetTransformToViewport(				MATRIX *Matrix ) ;												// �r���[�|�[�g�s���ݒ肷��
extern	int			GetTransformToViewportMatrix(		MATRIX *MatBuf ) ;												// �r���[�|�[�g�s����擾����
extern	int			GetTransformToAPIViewportMatrix(	MATRIX *MatBuf ) ;												// Direct3D�Ŏ����K�p�����r���[�|�[�g�s����擾����
extern	int			SetDefTransformMatrix(				void ) ;														// �f�t�H���g�̕ϊ��s���ݒ肷��
extern	int			GetTransformPosition(				VECTOR *LocalPos, float *x, float *y ) ;						// ���[�J�����W����X�N���[�����W���擾����
extern	float		GetBillboardPixelSize(				VECTOR WorldPos, float WorldSize ) ;							// ���[���h��ԏ�̃r���{�[�h�̃T�C�Y����X�N���[���ɓ��e�����ꍇ�̃s�N�Z���P�ʂ̃T�C�Y���擾����
extern	VECTOR		ConvWorldPosToViewPos(				VECTOR WorldPos ) ;												// ���[���h���W���r���[���W�ɕϊ�����
extern	VECTOR		ConvWorldPosToScreenPos(			VECTOR WorldPos ) ;												// ���[���h���W���X�N���[�����W�ɕϊ�����
extern	FLOAT4		ConvWorldPosToScreenPosPlusW(		VECTOR WorldPos ) ;												// ���[���h���W���X�N���[�����W�ɕϊ�����A�Ō�̂w�x�y���W���v�Ŋ���O�̒l�𓾂�
extern	VECTOR		ConvScreenPosToWorldPos(			VECTOR ScreenPos ) ;											// �X�N���[�����W�����[���h���W�ɕϊ�����
extern	VECTOR		ConvScreenPosToWorldPos_ZLinear(	VECTOR ScreenPos ) ;											// �X�N���[�����W�����[���h���W�ɕϊ�����( Z���W�����` )

extern	int			SetUseCullingFlag(					int Flag ) ;													// SetUseBackCulling �̋�����
extern	int			SetUseBackCulling(					int Flag /* DX_CULLING_LEFT �� */ ) ;							// �|���S���J�����O���[�h��ݒ肷��

extern	int			SetTextureAddressMode(				int Mode /* DX_TEXADDRESS_WRAP �� */ , int Stage = -1 ) ;		// �e�N�X�`���A�h���X���[�h��ݒ肷��
extern	int			SetTextureAddressModeUV(			int ModeU, int ModeV, int Stage = -1 ) ;						// �e�N�X�`���A�h���X���[�h��ݒ肷��( U �� V ��ʁX�ɐݒ肷�� )
extern	int			SetTextureAddressTransform(			float TransU, float TransV, float ScaleU, float ScaleV, float RotCenterU, float RotCenterV, float Rotate ) ;	// �e�N�X�`�����W�ϊ��p�����[�^��ݒ肷��
extern	int			SetTextureAddressTransformMatrix(	MATRIX Matrix ) ;												// �e�N�X�`�����W�ϊ��s���ݒ肷��
extern	int			ResetTextureAddressTransform(		void ) ;														// �e�N�X�`�����W�ϊ��ݒ�����Z�b�g����

extern	int			SetFogEnable(						int Flag ) ;													// �t�H�O��L���ɂ��邩�ǂ�����ݒ肷��( TRUE:�L��  FALSE:���� )
extern	int			SetFogMode(							int Mode /* DX_FOGMODE_NONE �� */ ) ;							// �t�H�O���[�h��ݒ肷��
extern	int			SetFogColor(						int r, int g, int b ) ;											// �t�H�O�J���[��ݒ肷��
extern	int			SetFogStartEnd(						float start, float end ) ;										// �t�H�O���n�܂鋗���ƏI�����鋗����ݒ肷��( 0.0f �` 1.0f )
extern	int			SetFogDensity(						float density ) ;												// �t�H�O�̖��x��ݒ肷��( 0.0f �` 1.0f )


// ��ʊ֌W�֐�
extern	int				GetPixel(									int x, int y ) ;																// �w����W�̐F���擾����
extern	int				GetDrawScreenGraph(							                             int x1, int y1, int x2, int y2,                       int GrHandle, int UseClientFlag = TRUE ) ;	// �`���̉�ʂ���w��̈�̉摜�����O���t�B�b�N�n���h���ɓ]������
extern	int				BltDrawValidGraph(							int TargetDrawValidGrHandle, int x1, int y1, int x2, int y2, int DestX, int DestY, int DestGrHandle ) ;							// SetDrawScreen �ŕ`��Ώۂɂł���O���t�B�b�N�n���h������w��̈�̉摜����ʂ̃O���t�B�b�N�n���h���ɓ]������
extern	int				ScreenFlip(									void ) ;																		// ����ʂƕ\��ʂ̓��e����������
extern 	int				ScreenCopy(									void ) ;																		// ����ʂ̓��e��\��ʂɓ]������
extern	int				WaitVSync(									int SyncNum ) ;																	// ���������M����҂�
extern	int				ClearDrawScreen(					        RECT *ClearRect = NULL ) ;														// ��ʂ��N���A����
extern	int				ClearDrawScreenZBuffer(						RECT *ClearRect = NULL ) ;														// ��ʂ̂y�o�b�t�@���N���A����
extern	int				ClsDrawScreen(								void ) ;																		// ClearDrawScreen�̋�����
extern	int				SetDrawScreen(								int DrawScreen ) ;																// �`����ʂ�ݒ肷��( MakeScreen �ō쐬�����O���t�B�b�N�n���h�����n�����Ƃ��ł��܂� )
extern	int				GetDrawScreen(								void ) ;																		// �`����ʂ��擾����
extern	int				GetActiveGraph(								void ) ;																		// GetDrawScreen �̋�����
extern	int				SetDrawZBuffer(								int DrawScreen ) ;																// �`���y�o�b�t�@�̃Z�b�g( DrawScreen �t���̂y�o�b�t�@��`���y�o�b�t�@�ɂ���ADrawScreen �� -1 �ɂ���ƃf�t�H���g�̕`���y�o�b�t�@�ɖ߂� )
#ifdef __WINDOWS__
extern	int				BltBackScreenToWindow(						HWND Window, int ClientX, int ClientY ) ;										// ����ʂ̓��e���w��̃E�C���h�E�ɓ]������
extern	int				BltRectBackScreenToWindow(					HWND Window, RECT BackScreenRect, RECT WindowClientRect ) ;						// ����ʂ̎w��̗̈���E�C���h�E�̃N���C�A���g�̈�̎w��̗̈�ɓ]������
#endif // __WINDOWS__
extern	int				SetGraphMode(								int ScreenSizeX, int ScreenSizeY, int ColorBitDepth, int RefreshRate = 60 ) ;	// ��ʃ��[�h��ݒ肷��
extern	int				SetEmulation320x240(						int Flag ) ;																	// �U�S�O���S�W�O�̉�ʂłR�Q�O���Q�S�O�̉�ʉ𑜓x�ɂ��邩�ǂ�����ݒ肷��A�U�S�O���S�W�O�ȊO�̉𑜓x�ł͖���( TRUE:�L��  FALSE:���� )
extern	int				SetZBufferSize(								int ZBufferSizeX, int ZBufferSizeY ) ;											// ��ʗp�̂y�o�b�t�@�̃T�C�Y��ݒ肷��
extern	int				SetWaitVSyncFlag(							int Flag ) ;																	// ScreenFlip ���s���ɂu�r�x�m�b�҂������邩�ǂ�����ݒ肷��
extern	int				GetWaitVSyncFlag(							void ) ;																		// ScreenFlip ���s���ɂu�r�x�m�b�҂������邩�ǂ������擾����
extern	int				SetFullSceneAntiAliasingMode(				int Samples, int Quality ) ;													// ��ʂ̃t���X�N���[���A���`�G�C���A�X���[�h�̐ݒ���s��( DxLib_Init �̑O�ł̂ݎg�p�\ )
extern	int				SetGraphDisplayArea(						int x1, int y1, int x2, int y2 ) ;												// ScreenFlip ���ɕ\��ʑS�̂ɓ]�����闠��ʂ̗̈��ݒ肷��( DxLib_Init �̑O�ł̂ݎg�p�\ )
extern	int				SetChangeScreenModeGraphicsSystemResetFlag(	int Flag ) ;																	// ��ʃ��[�h�ύX��( �ƃE�C���h�E���[�h�ύX�� )�ɃO���t�B�b�N�X�V�X�e���̐ݒ��O���t�B�b�N�n���h�������Z�b�g���邩�ǂ�����ݒ肷��( TRUE:���Z�b�g����( �f�t�H���g )  FALSE:���Z�b�g���Ȃ� )
extern	int				GetScreenState(								int *SizeX, int *SizeY, int *ColorBitDepth ) ;									// ���݂̉�ʂ̉𑜓x�ƃJ���[�r�b�g���𓾂� 
extern	int				GetDrawScreenSize(							int *XBuf, int *YBuf ) ;														// �`���̃T�C�Y���擾����
extern	int				GetScreenBitDepth(							void ) ;																		// ��ʂ̃J���[�r�b�g�����擾����
extern	int				GetColorBitDepth(							void ) ;																		// GetScreenBitDepth �̋�����
extern	int				GetChangeDisplayFlag(						void ) ;																		// ��ʃ��[�h���ύX����Ă��邩�ǂ������擾����
extern	int				GetVideoMemorySize(							int *AllSize, int *FreeSize ) ;													// ( ���ݐ���ɓ��삵�܂��� )�r�f�I�������̗e�ʂ𓾂�
extern	int				GetRefreshRate(								void ) ;																		// ���݂̉�ʂ̃��t���b�V�����[�g���擾����
extern	int				GetDisplayModeNum(							void ) ;																		// �ύX�\�ȃf�B�X�v���C���[�h�̐����擾����
extern	DISPLAYMODEDATA	GetDisplayMode(								int ModeIndex ) ;																// �ύX�\�ȃf�B�X�v���C���[�h�̏����擾����( ModeIndex �� 0 �` GetDisplayModeNum �̖߂�l-1 )
extern	COLORDATA*		GetDispColorData(							void ) ;																		// �f�B�X�v���C�̃J���[�f�[�^�A�h���X���擾����
extern	int				GetMultiDrawScreenNum(						void ) ;																		// �����ɕ`����s�����Ƃ��ł����ʂ̐����擾����
extern	int				SetDisplayRefreshRate(						int RefreshRate ) ;																// ( ���݌��ʂȂ� )�t���X�N���[�����̉�ʂ̃��t���b�V�����[�g��ύX����

// ���̑��ݒ�֌W�֐�
extern	int			SetUseNormalDrawShader(						int Flag ) ;									// �ʏ�`��Ƀv���O���}�u���V�F�[�_�[���g�p���邩�ǂ�����ݒ肷��( TRUE:�g�p����( �f�t�H���g )  FALSE:�g�p���Ȃ� )
extern	int			SetUseSoftwareRenderModeFlag(				int Flag ) ;									// �\�t�g�E�G�A�����_�����O���[�h���g�p���邩�ǂ�����ݒ肷��( TRUE:�g�p����  FALSE:�g�p���Ȃ�( �f�t�H���g ) )( DxLib_Init �̑O�ɌĂԕK�v������܂� )
extern	int			SetNotUse3DFlag(							int Flag ) ;									// ( �����ʂ�SetUseSoftwareRenderModeFlag ���g�p���ĉ����� )�R�c�@�\���g��Ȃ����ǂ�����ݒ肷��
extern	int			SetUse3DFlag(								int Flag ) ;									// ( �����ʂ�SetUseSoftwareRenderModeFlag ���g�p���ĉ����� )�R�c�@�\���g�����ǂ�����ݒ肷��
extern	int			GetUse3DFlag(								void ) ;										// �`��ɂR�c�@�\���g�����ǂ������擾����
extern	int			SetScreenMemToVramFlag(						int Flag ) ;									// ( �����ʂ�SetUseSoftwareRenderModeFlag ���g�p���ĉ����� )��ʂ̃s�N�Z���f�[�^���u�q�`�l�ɒu�����ǂ�����ݒ肷��
extern	int			GetScreenMemToSystemMemFlag(				void ) ;										// ��ʂ̃s�N�Z���f�[�^���V�X�e����������ɑ��݂��邩���擾����

extern	int			SetWindowDrawRect(							RECT *DrawRect ) ;								// �ʏ�g�p���Ȃ�
extern	int			RestoreGraphSystem(							void ) ;										// �c�w���C�u�����̃O���t�B�b�N�X�����֘A�̕��A�������s��
extern	int			SetAeroDisableFlag(							int Flag ) ;									// Vista,7 �� Windows Aero �𖳌��ɂ��邩�ǂ�����ݒ肷��( TRUE:�����ɂ���( �f�t�H���g )  FALSE:�L���ɂ��� )( DxLib_Init �̑O�ɌĂԕK�v������܂� )
extern	int			SetUseDirect3D9Ex(							int Flag ) ;									// Vista�ȍ~�̊��� Direct3D9Ex ���g�p���邩�ǂ�����ݒ肷��( TRUE:�g�p����( �f�t�H���g )  FALSE:�g�p���Ȃ� )( DxLib_Init �̑O�ɌĂԕK�v������܂� )
extern	int			SetUseHardwareVertexProcessing(				int Flag ) ;									// �n�[�h�E�G�A�̒��_���Z�����@�\���g�p���邩�ǂ�����ݒ肷��( TRUE:�g�p����( �f�t�H���g )  FALSE:�g�p���Ȃ� )( DxLib_Init �̑O�ɌĂԕK�v������܂� )
extern	int			SetMultiThreadFlag(							int Flag ) ;									// DirectDraw �� Direct3D �̋������x�����}���`�X���b�h�Ή��ɂ��邩�ǂ������Z�b�g����( TRUE:�}���`�X���b�h�Ή��ɂ���  FALSE:�}���`�X���b�h�Ή��ɂ��Ȃ�( �f�t�H���g ) )
extern	int			SetUseDirectDrawDeviceIndex(				int Index ) ;									// �g�p���� DirectDraw �f�o�C�X�̃C���f�b�N�X��ݒ肷��
extern	int			SetUseOldDrawModiGraphCodeFlag(				int Flag ) ;									// �Â��o�[�W������ DrawModiGraph �֐��̃R�[�h���g�p���邩�ǂ�����ݒ肷��
extern	int			SetUseVramFlag(								int Flag ) ;									// ( ���݌��ʂȂ� )�u�q�`�l���g�p���邩�̃t���O���Z�b�g����
extern	int			GetUseVramFlag(								void ) ;										// ( ���݌��ʂȂ� )�Q�c�O���t�B�b�N�T�[�t�F�X�쐬���ɃV�X�e���������[���g�p���邩�̃t���O�擾
extern	int			SetBasicBlendFlag(							int Flag ) ;									// ( ���݌��ʂȂ� )�ȗ����u�����h�������s�����ۂ��̃t���O���Z�b�g����
extern	int			SetUseBasicGraphDraw3DDeviceMethodFlag(		int Flag ) ;									// ( ���݌��ʂȂ� )�P���}�`�̕`��ɂR�c�f�o�C�X�̋@�\���g�p���邩�ǂ�����ݒ肷��
#ifdef __WINDOWS__
extern	int			SetUseDirectDrawFlag(						int Flag ) ;									// ( �����ʂ�SetUseSoftwareRenderModeFlag ���g�p���ĉ����� )DirectDraw���g�p���邩�ǂ�����ݒ肷��
extern	int			SetUseGDIFlag(								int Flag ) ;									// GDI�`����g�p���邩�ǂ�����ݒ肷��
extern	int			GetUseGDIFlag(								void ) ;										// GDI�`����g�p���邩�ǂ������擾����
extern	int			SetDDrawUseGuid(							GUID *Guid ) ;									// DirectDraw���g�p����GUID��ݒ肷��
extern	void*		GetUseDDrawObj(								void ) ;										// ���ݎg�p���Ă���DirectDraw�I�u�W�F�N�g�̃A�h���X���擾����( �߂�l�� IDirectDraw7 * �ɃL���X�g���ĉ����� )
extern	GUID*		GetDirectDrawDeviceGUID(					int Number ) ;									// �L���� DirectDraw �f�o�C�X�� GUID ���擾����
extern	int			GetDirectDrawDeviceDescription(				int Number, char *StringBuffer ) ;				// �L���� DirectDraw �f�o�C�X�̖��O���擾����
extern	int			GetDirectDrawDeviceNum(						void ) ;										// �L���� DirectDraw �f�o�C�X�̐����擾����
extern	DX_DIRECT3DDEVICE9* GetUseDirect3DDevice9(				void ) ;										// �g�p����Direct3DDevice9�I�u�W�F�N�g���擾����
extern	DX_DIRECT3DSURFACE9* GetUseDirect3D9BackBufferSurface(	void ) ;										// �g�p���̃o�b�N�o�b�t�@��Direct3DSurface9�I�u�W�F�N�g���擾����
#endif // __WINDOWS__
extern	int			RefreshDxLibDirect3DSetting(				void ) ;										// �c�w���C�u�������s����Direct3D�̐ݒ���ēx�s��( ����p�r )
extern	int			RenderVertex(								void ) ;										// ���_�o�b�t�@�ɗ��܂������_�f�[�^��`�悷��( ����p�r )

#ifndef DX_NON_SAVEFUNCTION

// �`����ʕۑ��֐�
// Jpeg_Quality         = 0:��掿�`100:���掿
// Png_CompressionLevel = 0:�����k�`  9:�ō����k
extern	int			SaveDrawScreen(       int x1, int y1, int x2, int y2, const TCHAR *FileName, int SaveType = DX_IMAGESAVETYPE_BMP , int Jpeg_Quality = 80 , int Jpeg_Sample2x1 = TRUE , int Png_CompressionLevel = -1 ) ;		// ���ݕ`��ΏۂɂȂ��Ă����ʂ��t�@�C���ŕۑ�����
extern	int			SaveDrawScreenToBMP(  int x1, int y1, int x2, int y2, const TCHAR *FileName ) ;																																	// ���ݕ`��ΏۂɂȂ��Ă����ʂ��a�l�o�`���ŕۑ�����
extern	int			SaveDrawScreenToJPEG( int x1, int y1, int x2, int y2, const TCHAR *FileName, int Quality = 80 , int Sample2x1 = TRUE ) ;																						// ���ݕ`��ΏۂɂȂ��Ă����ʂ��i�o�d�f�`���ŕۑ����� Quality = �掿�A�l���傫���قǒሳ�k���掿,0�`100 
extern	int			SaveDrawScreenToPNG(  int x1, int y1, int x2, int y2, const TCHAR *FileName, int CompressionLevel = -1 ) ;																										// ���ݕ`��ΏۂɂȂ��Ă����ʂ��o�m�f�`���ŕۑ����� CompressionLevel = ���k���A�l���傫���قǍ����k�������ׁA�O�͖����k,0�`9

#endif // DX_NON_SAVEFUNCTION

// ���_�o�b�t�@�֌W�֐�
extern	int			CreateVertexBuffer(		int VertexNum, int VertexType /* DX_VERTEX_TYPE_NORMAL_3D �� */ ) ;						// ���_�o�b�t�@���쐬����( -1:�G���[  0�ȏ�:���_�o�b�t�@�n���h�� )
extern	int			DeleteVertexBuffer(		int VertexBufHandle ) ;																	// ���_�o�b�t�@���폜����
extern	int			InitVertexBuffer(		void ) ;																				// ���ׂĂ̒��_�o�b�t�@���폜����
extern	int			SetVertexBufferData(	int SetIndex, void *VertexData, int VertexNum, int VertexBufHandle ) ;					// ���_�o�b�t�@�ɒ��_�f�[�^��]������
extern	int			CreateIndexBuffer(		int IndexNum, int IndexType /* DX_INDEX_TYPE_16BIT �� */  ) ;							// �C���f�b�N�X�o�b�t�@���쐬����( -1:�G���[�@0�ȏ�F�C���f�b�N�X�o�b�t�@�n���h�� )
extern	int			DeleteIndexBuffer(		int IndexBufHandle ) ;																	// �C���f�b�N�X�o�b�t�@���폜����
extern	int			InitIndexBuffer(		void ) ;																				// ���ׂẴC���f�b�N�X�o�b�t�@���폜����
extern	int			SetIndexBufferData(		int SetIndex, void *IndexData, int IndexNum, int IndexBufHandle ) ;						// �C���f�b�N�X�o�b�t�@�ɃC���f�b�N�X�f�[�^��]������

// �V�F�[�_�[�֌W�֐�
extern	int			GetValidShaderVersion(		void ) ;												// �g�p�ł���V�F�[�_�[�̃o�[�W�������擾����( 0=�g���Ȃ�  200=�V�F�[�_�[���f���Q�D�O���g�p�\  300=�V�F�[�_�[���f���R�D�O���g�p�\ )

extern	int			LoadVertexShader(			const TCHAR *FileName ) ;								// ���_�V�F�[�_�[�o�C�i�����t�@�C������ǂݍ��ݒ��_�V�F�[�_�[�n���h�����쐬����( �߂�l -1:�G���[  -1�ȊO:�V�F�[�_�[�n���h�� )
extern	int			LoadPixelShader(			const TCHAR *FileName ) ;								// �s�N�Z���V�F�[�_�[�o�C�i�����t�@�C������ǂݍ��݃s�N�Z���V�F�[�_�[�n���h�����쐬����( �߂�l -1:�G���[  -1�ȊO:�V�F�[�_�[�n���h�� )
extern	int			LoadVertexShaderFromMem(	void *ImageAddress, int ImageSize ) ;					// �������ɓǂݍ��܂ꂽ���_�V�F�[�_�[�o�C�i�����璸�_�V�F�[�_�[�n���h�����쐬����( �߂�l -1:�G���[  -1�ȊO:�V�F�[�_�[�n���h�� )
extern	int			LoadPixelShaderFromMem(		void *ImageAddress, int ImageSize ) ;					// �������ɓǂݍ��܂ꂽ�s�N�Z���V�F�[�_�[�o�C�i������s�N�Z���V�F�[�_�[�n���h�����쐬����( �߂�l -1:�G���[  -1�ȊO:�V�F�[�_�[�n���h�� )
extern	int			DeleteShader(				int ShaderHandle ) ;									// �V�F�[�_�[�n���h���̍폜( ���_�V�F�[�_�[�E�s�N�Z���V�F�[�_�[���� )
extern	int			InitShader(					void ) ;												// �V�F�[�_�[�n���h����S�č폜����( ���_�V�F�[�_�[�n���h���E�s�N�Z���V�F�[�_�[�n���h���ǂ�������ׂč폜 )

extern	int			GetConstIndexToShader(           const TCHAR *ConstantName, int ShaderHandle ) ;	// �w��̖��O�����萔���g�p����V�F�[�_�[�萔�̔ԍ����擾����
extern	int			GetConstCountToShader(           const TCHAR *ConstantName, int ShaderHandle ) ;	// �w��̖��O�����萔���g�p����V�F�[�_�[�萔�̐����擾����
extern	const FLOAT4 *GetConstDefaultParamFToShader( const TCHAR *ConstantName, int ShaderHandle ) ;	// �w��̖��O�������������_���萔�̃f�t�H���g�p�����[�^���i�[����Ă��郁�����A�h���X���擾����
extern	int			SetVSConstSF(         int ConstantIndex, float  Param ) ;							// ���_�V�F�[�_�[�� float �^�萔��ݒ肷��
extern	int			SetVSConstF(          int ConstantIndex, FLOAT4 Param ) ;							// ���_�V�F�[�_�[�� float �^�萔��ݒ肷��
extern	int			SetVSConstFMtx(       int ConstantIndex, MATRIX Param ) ;							// ���_�V�F�[�_�[�� float �^�萔�ɍs���ݒ肷��
extern	int			SetVSConstFMtxT(      int ConstantIndex, MATRIX Param ) ;							// ���_�V�F�[�_�[�� float �^�萔�ɓ]�u�����s���ݒ肷��
extern	int			SetVSConstSI(         int ConstantIndex, int    Param ) ;							// ���_�V�F�[�_�[�� int   �^�萔��ݒ肷��
extern	int			SetVSConstI(          int ConstantIndex, INT4   Param ) ;							// ���_�V�F�[�_�[�� int   �^�萔��ݒ肷��
extern	int			SetVSConstB(          int ConstantIndex, BOOL   Param ) ;							// ���_�V�F�[�_�[�� BOOL  �^�萔��ݒ肷��
extern	int			SetVSConstSFArray(    int ConstantIndex, float  *ParamArray, int ParamNum ) ;		// ���_�V�F�[�_�[�� float �^�萔��ݒ肷��( �z����g���ĘA�ԃC���f�b�N�X�Ɉ�x�ɐݒ� )
extern	int			SetVSConstFArray(     int ConstantIndex, FLOAT4 *ParamArray, int ParamNum ) ;		// ���_�V�F�[�_�[�� float �^�萔��ݒ肷��( �z����g���ĘA�ԃC���f�b�N�X�Ɉ�x�ɐݒ� )
extern	int			SetVSConstFMtxArray(  int ConstantIndex, MATRIX *ParamArray, int ParamNum ) ;		// ���_�V�F�[�_�[�� float �^�萔�ɍs���ݒ肷��( �z����g���ĘA�ԃC���f�b�N�X�Ɉ�x�ɐݒ� )
extern	int			SetVSConstFMtxTArray( int ConstantIndex, MATRIX *ParamArray, int ParamNum ) ;		// ���_�V�F�[�_�[�� float �^�萔�ɓ]�u�����s���ݒ肷��( �z����g���ĘA�ԃC���f�b�N�X�Ɉ�x�ɐݒ� )
extern	int			SetVSConstSIArray(    int ConstantIndex, int    *ParamArray, int ParamNum ) ;		// ���_�V�F�[�_�[�� int   �^�萔��ݒ肷��( �z����g���ĘA�ԃC���f�b�N�X�Ɉ�x�ɐݒ� )
extern	int			SetVSConstIArray(     int ConstantIndex, INT4   *ParamArray, int ParamNum ) ;		// ���_�V�F�[�_�[�� int   �^�萔��ݒ肷��( �z����g���ĘA�ԃC���f�b�N�X�Ɉ�x�ɐݒ� )
extern	int			SetVSConstBArray(     int ConstantIndex, BOOL   *ParamArray, int ParamNum ) ;		// ���_�V�F�[�_�[�� BOOL  �^�萔��ݒ肷��( �z����g���ĘA�ԃC���f�b�N�X�Ɉ�x�ɐݒ� )
extern	int			ResetVSConstF(        int ConstantIndex, int ParamNum ) ;							// ���_�V�F�[�_�[�� float �^�萔�̐ݒ�����Z�b�g����
extern	int			ResetVSConstI(        int ConstantIndex, int ParamNum ) ;							// ���_�V�F�[�_�[�� int   �^�萔�̐ݒ�����Z�b�g����
extern	int			ResetVSConstB(        int ConstantIndex, int ParamNum ) ;							// ���_�V�F�[�_�[�� BOOL  �^�萔�̐ݒ�����Z�b�g����

extern	int			SetPSConstSF(         int ConstantIndex, float  Param ) ;							// �s�N�Z���V�F�[�_�[�� float �^�萔��ݒ肷��
extern	int			SetPSConstF(          int ConstantIndex, FLOAT4 Param ) ;							// �s�N�Z���V�F�[�_�[�� float �^�萔��ݒ肷��
extern	int			SetPSConstFMtx(       int ConstantIndex, MATRIX Param ) ;							// �s�N�Z���V�F�[�_�[�� float �^�萔�ɍs���ݒ肷��
extern	int			SetPSConstFMtxT(      int ConstantIndex, MATRIX Param ) ;							// �s�N�Z���V�F�[�_�[�� float �^�萔�ɓ]�u�����s���ݒ肷��
extern	int			SetPSConstSI(         int ConstantIndex, int    Param ) ;							// �s�N�Z���V�F�[�_�[�� int   �^�萔��ݒ肷��
extern	int			SetPSConstI(          int ConstantIndex, INT4   Param ) ;							// �s�N�Z���V�F�[�_�[�� int   �^�萔��ݒ肷��
extern	int			SetPSConstB(          int ConstantIndex, BOOL   Param ) ;							// �s�N�Z���V�F�[�_�[�� BOOL  �^�萔��ݒ肷��
extern	int			SetPSConstSFArray(    int ConstantIndex, float  *ParamArray, int ParamNum ) ;		// �s�N�Z���V�F�[�_�[�� float �^�萔��ݒ肷��( �z����g���ĘA�ԃC���f�b�N�X�Ɉ�x�ɐݒ� )
extern	int			SetPSConstFArray(     int ConstantIndex, FLOAT4 *ParamArray, int ParamNum ) ;		// �s�N�Z���V�F�[�_�[�� float �^�萔��ݒ肷��( �z����g���ĘA�ԃC���f�b�N�X�Ɉ�x�ɐݒ� )
extern	int			SetPSConstFMtxArray(  int ConstantIndex, MATRIX *ParamArray, int ParamNum ) ;		// �s�N�Z���V�F�[�_�[�� float �^�萔�ɍs���ݒ肷��( �z����g���ĘA�ԃC���f�b�N�X�Ɉ�x�ɐݒ� )
extern	int			SetPSConstFMtxTArray( int ConstantIndex, MATRIX *ParamArray, int ParamNum ) ;		// �s�N�Z���V�F�[�_�[�� float �^�萔�ɓ]�u�����s���ݒ肷��( �z����g���ĘA�ԃC���f�b�N�X�Ɉ�x�ɐݒ� )
extern	int			SetPSConstSIArray(    int ConstantIndex, int    *ParamArray, int ParamNum ) ;		// �s�N�Z���V�F�[�_�[�� int   �^�萔��ݒ肷��( �z����g���ĘA�ԃC���f�b�N�X�Ɉ�x�ɐݒ� )
extern	int			SetPSConstIArray(     int ConstantIndex, INT4   *ParamArray, int ParamNum ) ;		// �s�N�Z���V�F�[�_�[�� int   �^�萔��ݒ肷��( �z����g���ĘA�ԃC���f�b�N�X�Ɉ�x�ɐݒ� )
extern	int			SetPSConstBArray(     int ConstantIndex, BOOL   *ParamArray, int ParamNum ) ;		// �s�N�Z���V�F�[�_�[�� BOOL  �^�萔��ݒ肷��( �z����g���ĘA�ԃC���f�b�N�X�Ɉ�x�ɐݒ� )
extern	int			ResetPSConstF(        int ConstantIndex, int ParamNum ) ;							// �s�N�Z���V�F�[�_�[�� float �^�萔�̐ݒ�����Z�b�g����
extern	int			ResetPSConstI(        int ConstantIndex, int ParamNum ) ;							// �s�N�Z���V�F�[�_�[�� int   �^�萔�̐ݒ�����Z�b�g����
extern	int			ResetPSConstB(        int ConstantIndex, int ParamNum ) ;							// �s�N�Z���V�F�[�_�[�� BOOL  �^�萔�̐ݒ�����Z�b�g����

extern	int			SetRenderTargetToShader( int TargetIndex, int DrawScreen ) ;						// �V�F�[�_�[���g�p�����`��ł̕`����ݒ肷��
extern	int			SetUseTextureToShader(   int StageIndex, int GraphHandle ) ;						// �V�F�[�_�[���g�p�����`��Ŏg�p����O���t�B�b�N�n���h����ݒ肷��
extern	int			SetUseVertexShader(      int ShaderHandle ) ;										// �V�F�[�_�[���g�p�����`��Ɏg�p���钸�_�V�F�[�_�[��ݒ肷��( -1��n���Ɖ��� )
extern	int			SetUsePixelShader(       int ShaderHandle ) ;										// �V�F�[�_�[���g�p�����`��Ɏg�p����s�N�Z���V�F�[�_�[��ݒ肷��( -1��n���Ɖ��� )

extern	int			CalcPolygonBinormalAndTangentsToShader(        VERTEX3DSHADER *Vertex, int PolygonNum ) ;												// �|���S���̒��_�̐ڐ��Ə]�@�����t�u���W����v�Z���ăZ�b�g����
extern	int			CalcPolygonIndexedBinormalAndTangentsToShader( VERTEX3DSHADER *Vertex, int VertexNum, unsigned short *Indices, int PolygonNum ) ;		// �|���S���̒��_�̐ڐ��Ə]�@�����t�u���W����v�Z���ăZ�b�g����( ���_�C���f�b�N�X���g�p���� )

extern	int			DrawPolygon2DToShader(          VERTEX2DSHADER *Vertex, int PolygonNum ) ;																												// �V�F�[�_�[���g���ĂQ�c�|���S����`�悷��
extern	int			DrawPolygon3DToShader(          VERTEX3DSHADER *Vertex, int PolygonNum ) ;																												// �V�F�[�_�[���g���ĂR�c�|���S����`�悷��
extern	int			DrawPolygonIndexed2DToShader(   VERTEX2DSHADER *Vertex, int VertexNum, unsigned short *Indices, int PolygonNum ) ;																		// �V�F�[�_�[���g���ĂQ�c�|���S����`�悷��( ���_�C���f�b�N�X���g�p���� )
extern	int			DrawPolygonIndexed3DToShader(   VERTEX3DSHADER *Vertex, int VertexNum, unsigned short *Indices, int PolygonNum ) ;																		// �V�F�[�_�[���g���ĂR�c�|���S����`�悷��( ���_�C���f�b�N�X���g�p���� )
extern	int			DrawPrimitive2DToShader(        VERTEX2DSHADER *Vertex, int VertexNum,                                        int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST �� */ ) ;					// �V�F�[�_�[���g���ĂQ�c�v���~�e�B�u��`�悷��
extern	int			DrawPrimitive3DToShader(        VERTEX3DSHADER *Vertex, int VertexNum,                                        int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST �� */ ) ;					// �V�F�[�_�[���g���ĂR�c�v���~�e�B�u��`�悷��
extern	int			DrawPrimitiveIndexed2DToShader( VERTEX2DSHADER *Vertex, int VertexNum, unsigned short *Indices, int IndexNum, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST �� */ ) ;					// �V�F�[�_�[���g���ĂQ�c�v���~�e�B�u��`�悷��( ���_�C���f�b�N�X���g�p���� )
extern	int			DrawPrimitiveIndexed3DToShader( VERTEX3DSHADER *Vertex, int VertexNum, unsigned short *Indices, int IndexNum, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST �� */ ) ;					// �V�F�[�_�[���g���ĂR�c�v���~�e�B�u��`�悷��( ���_�C���f�b�N�X���g�p���� )
extern	int			DrawPolygon3DToShader_UseVertexBuffer(           int VertexBufHandle ) ;																												// �V�F�[�_�[���g���ĂR�c�|���S����`�悷��( ���_�o�b�t�@�g�p�� )
extern	int			DrawPolygonIndexed3DToShader_UseVertexBuffer(    int VertexBufHandle, int IndexBufHandle ) ;																							// �V�F�[�_�[���g���ĂR�c�|���S����`�悷��( ���_�o�b�t�@�ƃC���f�b�N�X�o�b�t�@�g�p�� )
extern	int			DrawPrimitive3DToShader_UseVertexBuffer(         int VertexBufHandle,                     int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST �� */ ) ;										// �V�F�[�_�[���g���ĂR�c�v���~�e�B�u��`�悷��( ���_�o�b�t�@�g�p�� )
extern	int			DrawPrimitive3DToShader_UseVertexBuffer2(        int VertexBufHandle,                     int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST �� */, int StartVertex, int UseVertexNum ) ;	// �V�F�[�_�[���g���ĂR�c�v���~�e�B�u��`�悷��( ���_�o�b�t�@�g�p�� )
extern	int			DrawPrimitiveIndexed3DToShader_UseVertexBuffer(  int VertexBufHandle, int IndexBufHandle, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST �� */ ) ;										// �V�F�[�_�[���g���ĂR�c�v���~�e�B�u��`�悷��( ���_�o�b�t�@�ƃC���f�b�N�X�o�b�t�@�g�p�� )
extern	int			DrawPrimitiveIndexed3DToShader_UseVertexBuffer2( int VertexBufHandle, int IndexBufHandle, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST �� */, int BaseVertex, int StartVertex, int UseVertexNum, int StartIndex, int UseIndexNum ) ;	// �V�F�[�_�[���g���ĂR�c�v���~�e�B�u��`�悷��( ���_�o�b�t�@�ƃC���f�b�N�X�o�b�t�@�g�p�� )

// �t�B���^�[�֌W�֐�
#ifndef DX_NON_FILTER
extern	int			GraphFilter(         int    GrHandle,                                                                                                               int FilterType /* DX_GRAPH_FILTER_GAUSS �� */ , ... ) ;		// �摜�Ƀt�B���^�[�������s��
extern	int			GraphFilterBlt(      int SrcGrHandle, int DestGrHandle,                                                                                             int FilterType /* DX_GRAPH_FILTER_GAUSS �� */ , ... ) ;		// �摜�̃t�B���^�[�t���]�����s��
extern	int			GraphFilterRectBlt(  int SrcGrHandle, int DestGrHandle, int SrcX1, int SrcY1, int SrcX2, int SrcY2, int DestX,  int DestY,                          int FilterType /* DX_GRAPH_FILTER_GAUSS �� */ , ... ) ;		// �摜�̃t�B���^�[�t���]�����s��( ��`�w�� )
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_MONO, int Cb = �F��( -255 �` 255 ), int Cr = �ԐF��( -255 �` 255 ) ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_GAUSS, int PixelWidth = �g�p�s�N�Z����( 8 , 16 , 32 �̉��ꂩ ), int Param = �ڂ����p�����[�^( 100 �Ŗ�1�s�N�Z�����̕� ) ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_DOWN_SCALE, int DivNum = ���̃T�C�Y�̉����̂P���A�Ƃ����l( 2 , 4 , 8 �̉��ꂩ ) ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_BRIGHT_CLIP, int CmpType = �N���b�v�^�C�v( DX_CMP_LESS:CmpParam�ȉ����N���b�v  ����  DX_CMP_GREATER:CmpParam�ȏ���N���b�v ), int CmpParam = �N���b�v�p�����[�^( 0 �` 255 ), int ClipFillFlag = �N���b�v�����s�N�Z����h��Ԃ����ǂ���( TRUE:�h��Ԃ�  FALSE:�h��Ԃ��Ȃ� ), int ClipFillColor = �N���b�v�����s�N�Z���ɓh��F�l( GetColor �Ŏ擾���� )( ClipFillFlag �� FALSE �̏ꍇ�͎g�p���Ȃ� ), int ClipFillAlpha = �N���b�v�����s�N�Z���ɓh�郿�l( 0 �` 255 )( ClipFillFlag �� FALSE �̏ꍇ�͎g�p���Ȃ� ) ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_HSB, int HueType = Hue �̈Ӗ�( 0:���Βl  1:��Βl ), int Hue = �F���p�����[�^( HueType �� 0 �̏ꍇ = �s�N�Z���̐F���ɑ΂��鑊�Βl( -180 �` 180 )   HueType �� 1 �̏ꍇ = �F���̐�Βl( 0 �` 360 ) ), int Saturation = �ʓx( -255 �` ), int Bright = �P�x( -255 �` 255 ) ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_INVERT ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_LEVEL, int Min = �ϊ����̉����l( 0 �` 255 ), int Max = �ϊ����̏���l( 0 �` 255 ), int Gamma = �K���}�l( 100 �ŃK���}�␳�����A0 �Ƃ���ȉ��̒l�͕s�� ), int AfterMin = �ϊ���̍Œ�l( 0 �` 255 ), int AfterMax = �ϊ���̍ő�l( 0 �` 255 ) ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_TWO_COLOR, int Threshold = 臒l( 0 �` 255 ), int LowColor = 臒l���l���Ⴉ�����s�N�Z���̕ϊ���̐F�l( GetColor �Ŏ擾���� ), int LowAlpha = 臒l���l���Ⴉ�����s�N�Z���̕ϊ���̃��l( 0 �` 255 ), int HighColor = 臒l���l�����������s�N�Z���̕ϊ���̐F�l( GetColor �Ŏ擾���� ), int HighAlpha = 臒l���l�����������s�N�Z���̕ϊ���̃��l( 0 �` 255 ) ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_GRADIENT_MAP, int MapGrHandle = �O���f�[�V�����}�b�v�̃O���t�B�b�N�n���h��( ���摜�̋P�x����O���f�[�V�����}�b�v�摜�� x ���W���Z�o���܂��̂ŏc����1dot�ł��n�j ), int Reverse = �O���f�[�V�����}�b�v���E���]�t���O( TRUE : �O���f�[�V�����}�b�v�����E���]���Ďg��  FALSE : ���E���]���Ȃ� ) ) ;

extern	int			GraphBlend(         int    GrHandle, int BlendGrHandle,                                                                                                                                         int BlendRatio /* �u�����h���ʂ̉e���x( 0:�O��  255:�P�O�O�� ) */ , int BlendType /* DX_GRAPH_BLEND_ADD �� */ , ... ) ;	// ��̉摜���u�����h����
extern	int			GraphBlendBlt(      int SrcGrHandle, int BlendGrHandle, int DestGrHandle,                                                                                                                       int BlendRatio /* �u�����h���ʂ̉e���x( 0:�O��  255:�P�O�O�� ) */ , int BlendType /* DX_GRAPH_BLEND_ADD �� */ , ... ) ;	// ��̉摜���u�����h���Č��ʂ��w��̉摜�ɏo�͂���
extern	int			GraphBlendRectBlt(  int SrcGrHandle, int BlendGrHandle, int DestGrHandle, int SrcX1, int SrcY1, int SrcX2, int SrcY2, int BlendX,  int BlendY,                            int DestX, int DestY, int BlendRatio /* �u�����h���ʂ̉e���x( 0:�O��  255:�P�O�O�� ) */ , int BlendType /* DX_GRAPH_BLEND_ADD �� */ , ... ) ;	// ��̉摜���u�����h���Č��ʂ��w��̉摜�ɏo�͂���( ��`�w�� )
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_NORMAL ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_RGBA_SELECT_MIX, int SelectR = ( �o�͂̐ԕ��ƂȂ鐬�� DX_RGBA_SELECT_SRC_R �� ), int SelectG = ( �o�̗͂ΐ����ƂȂ鐬�� DX_RGBA_SELECT_SRC_R �� ), int SelectB = ( �o�͂̐����ƂȂ鐬�� DX_RGBA_SELECT_SRC_R �� ), int SelectA = ( �o�͂̃������ƂȂ鐬�� DX_RGBA_SELECT_SRC_R �� ) ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_MULTIPLE ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_DIFFERENCE ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_ADD ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_SCREEN ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_OVERLAY ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_DODGE ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_BURN ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_DARKEN ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_LIGHTEN ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_SOFTLIGHT ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_HARDLIGHT ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_EXCLUSION ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_HUE ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_SATURATION ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_COLOR ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_BRIGHT ) ;
#endif // DX_NON_FILTER

#ifndef DX_NON_MOVIE
// ���[�r�[�O���t�B�b�N�֌W�֐�
extern	int			PlayMovie(						const TCHAR *FileName, int ExRate, int PlayType ) ;						// ����t�@�C���̍Đ�
extern	int			OpenMovieToGraph(				const TCHAR *FileName, int FullColor = TRUE ) ;							// ����t�@�C�����J��
extern 	int			PlayMovieToGraph(				int GraphHandle, int PlayType = DX_PLAYTYPE_BACK , int SysPlay = 0 ) ;	// ����t�@�C�����g�p����O���t�B�b�N�n���h���̓���t�@�C���̍Đ����J�n����
extern 	int			PauseMovieToGraph(				int GraphHandle, int SysPause = 0 ) ;									// ����t�@�C�����g�p����O���t�B�b�N�n���h���̓���t�@�C���̍Đ����~����
extern	int			AddMovieFrameToGraph(			int GraphHandle, unsigned int FrameNum ) ;								// ����t�@�C���̍Đ��t���[����i�߂�A�߂����Ƃ͏o���Ȃ�( ����t�@�C������~��ԂŁA���� Ogg Theora �̂ݗL�� )
extern	int			SeekMovieToGraph(				int GraphHandle, int Time ) ;											// ����t�@�C���̍Đ��ʒu��ݒ肷��(�~���b�P��)
extern 	int			GetMovieStateToGraph(			int GraphHandle ) ;														// ����t�@�C���̍Đ���Ԃ𓾂�
extern	int			SetMovieVolumeToGraph(			int Volume, int GraphHandle ) ;											// ����t�@�C���̉��ʂ�ݒ肷��(0�`10000)
extern	int			ChangeMovieVolumeToGraph(		int Volume, int GraphHandle ) ;											// ����t�@�C���̉��ʂ�ݒ肷��(0�`255)
extern	BASEIMAGE*	GetMovieBaseImageToGraph(		int GraphHandle ) ;														// ����t�@�C���̊�{�C���[�W�f�[�^���擾����
extern	int			GetMovieTotalFrameToGraph(		int GraphHandle ) ;														// ����t�@�C���̑��t���[�����𓾂�( Ogg Theora �ł̂ݗL�� )
extern	int			TellMovieToGraph(				int GraphHandle ) ;														// ����t�@�C���̍Đ��ʒu���擾����(�~���b�P��)
extern	int			TellMovieToGraphToFrame(		int GraphHandle ) ;														// ����t�@�C���̍Đ��ʒu���擾����(�t���[���P��)
extern	int			SeekMovieToGraphToFrame(		int GraphHandle, int Frame ) ;											// ����t�@�C���̍Đ��ʒu��ݒ肷��(�t���[���P��)
extern	LONGLONG	GetOneFrameTimeMovieToGraph(	int GraphHandle ) ;														// ����t�@�C���̂P�t���[��������̎��Ԃ��擾����
extern	int			GetLastUpdateTimeMovieToGraph(	int GraphHandle ) ;														// ����t�@�C���̃C���[�W���Ō�ɍX�V�������Ԃ𓾂�(�~���b�P��)
extern	int			SetMovieRightImageAlphaFlag(	int Flag ) ;															// ����t�@�C���f���̉E�����̐Ԑ����������Ƃ��Ĉ������ǂ������Z�b�g����( TRUE:�����Ƃ��Ĉ���  FALSE:�����Ƃ��Ĉ���Ȃ�( �f�t�H���g ) )
#endif // DX_NON_MOVIE

// �J�����֌W�֐�
extern	int			SetCameraNearFar(					float Near, float Far ) ;											// �J������ Near�N���b�v�ʂ� Far�N���b�v�ʂ̋�����ݒ肷��
extern	int			SetCameraPositionAndTarget_UpVecY(  VECTOR Position, VECTOR Target ) ;									// �J�����̎��_�A�����_�A�A�b�v�x�N�g����ݒ肷��( �A�b�v�x�N�g���͂x���������瓱���o�� )
extern	int			SetCameraPositionAndTargetAndUpVec( VECTOR Position, VECTOR Target, VECTOR Up ) ;						// �J�����̎��_�A�����_�A�A�b�v�x�N�g����ݒ肷��
extern	int			SetCameraPositionAndAngle(			VECTOR Position, float VRotate, float HRotate, float TRotate ) ;	// �J�����̎��_�A�����_�A�A�b�v�x�N�g����ݒ肷��( �����_�ƃA�b�v�x�N�g���͐�����]�p�x�A������]�p�x�A�P���]�p�x���瓱���o�� )
extern	int			SetCameraViewMatrix(				MATRIX ViewMatrix ) ;												// �r���[�s��𒼐ڐݒ肷��
extern	int			SetCameraScreenCenter(				float x, float y ) ;												// ��ʏ�ɂ�����J���������Ă���f���̒��S�̍��W��ݒ肷��

extern	int			SetupCamera_Perspective(			float Fov ) ;														// ���ߖ@�J�������Z�b�g�A�b�v����
extern	int			SetupCamera_Ortho(					float Size ) ;														// ���ˉe�J�������Z�b�g�A�b�v����
extern	int			SetupCamera_ProjectionMatrix(		MATRIX ProjectionMatrix ) ;											// �ˉe�s��𒼐ڐݒ肷��
extern	int			SetCameraDotAspect(					float DotAspect ) ;													// �J�����̃h�b�g�A�X�y�N�g���ݒ肷��

extern	int			CheckCameraViewClip(				VECTOR CheckPos ) ;													// �w��̍��W���J�����̎��E�ɓ����Ă��邩�ǂ����𔻒肷��( �߂�l TRUE:���E�ɓ����Ă��Ȃ�  FALSE:���E�ɓ����Ă��� )
extern	int			CheckCameraViewClip_Dir(			VECTOR CheckPos ) ;													// �w��̍��W���J�����̎��E�ɓ����Ă��邩�ǂ����𔻒肷��A�߂�l�ŊO��Ă���������m�邱�Ƃ��ł���( �߂�l 0:���E�ɓ����Ă���  0�ȊO:���E�ɓ����Ă��Ȃ�( DX_CAMERACLIP_LEFT �� DX_CAMERACLIP_RIGHT �� or ���Z�ō������ꂽ���́Aand ���Z�ŕ������m�F�ł��� ) )
extern	int			CheckCameraViewClip_Box(			VECTOR BoxPos1, VECTOR BoxPos2 ) ;									// ��̍��W�ŕ\�����{�b�N�X���J�����̎��E�ɓ����Ă��邩�ǂ����𔻒肷��( �߂�l TRUE:���E�ɓ����Ă��Ȃ�  FALSE:���E�ɓ����Ă��� )

extern	float		GetCameraNear(						void ) ;															// �J������ Near �N���b�v�ʂ̋������擾����
extern	float		GetCameraFar(						void ) ;															// �J������ Far �N���b�v�ʂ̋������擾����

extern	VECTOR		GetCameraPosition(					void ) ;															// �J�����̈ʒu���擾����
extern	VECTOR		GetCameraTarget(					void ) ;															// �J�����̒����_���擾����
extern	VECTOR		GetCameraUpVector(					void ) ;															// �J�����̎����ɐ����ȏ�����̃x�N�g�����擾����
extern	float		GetCameraAngleHRotate(				void ) ;															// �J�����̐��������̌������擾����
extern	float		GetCameraAngleVRotate(				void ) ;															// �J�����̐��������̌������擾����
extern	float		GetCameraAngleTRotate(				void ) ;															// �J�����̌����̔P��p�x���擾����

extern	MATRIX		GetCameraViewMatrix(				void ) ;															// �r���[�s����擾����
extern	MATRIX		GetCameraBillboardMatrix(			void ) ;															// �r���{�[�h�s����擾����
extern	float		GetCameraFov(						void ) ;															// �J�����̎���p���擾����
extern	float		GetCameraSize(						void ) ;															// �J�����̎���T�C�Y���擾����
extern	MATRIX		GetCameraProjectionMatrix(			void ) ;															// �ˉe�s����擾����
extern	float		GetCameraDotAspect(					void ) ;															// �J�����̃h�b�g�A�X�y�N�g��𓾂�
extern	MATRIX		GetCameraViewportMatrix(			void ) ;															// �r���[�|�[�g�s����擾����
extern	MATRIX		GetCameraAPIViewportMatrix(			void ) ;															// Direct3D�Ŏ����K�p�����r���[�|�[�g�s����擾����

// ���C�g�֌W�֐�
extern	int			SetUseLighting(				int Flag ) ;																// ���C�e�B���O���g�p���邩�ǂ�����ݒ肷��
extern	int			SetMaterialUseVertDifColor( int UseFlag ) ;																// �R�c�`��̃��C�e�B���O�v�Z�Œ��_�J���[�̃f�B�t���[�Y�J���[���g�p���邩�ǂ�����ݒ肷��
extern	int			SetMaterialUseVertSpcColor( int UseFlag ) ;																// �R�c�`��̃��C�e�B���O�v�Z�Œ��_�J���[�̃X�y�L�����J���[���g�p���邩�ǂ�����ݒ肷��
extern	int			SetMaterialParam(			MATERIALPARAM Material ) ;													// �R�c�`��̃��C�e�B���O�v�Z�Ŏg�p����}�e���A���p�����[�^��ݒ肷��
extern	int			SetUseSpecular(				int UseFlag ) ;																// �R�c�`��ɃX�y�L�������g�p���邩�ǂ�����ݒ肷��
extern	int			SetGlobalAmbientLight(		COLOR_F Color ) ;															// �O���[�o���A���r�G���g���C�g�J���[��ݒ肷��

extern	int			ChangeLightTypeDir(			VECTOR Direction ) ;														// �f�t�H���g���C�g�̃^�C�v���f�B���N�V���i�����C�g�ɂ���
extern	int			ChangeLightTypeSpot(		VECTOR Position, VECTOR Direction, float OutAngle, float InAngle, float Range, float Atten0, float Atten1, float Atten2 ) ;	// �f�t�H���g���C�g�̃^�C�v���X�|�b�g���C�g�ɂ���
extern	int			ChangeLightTypePoint(		VECTOR Position, float Range, float Atten0, float Atten1, float Atten2 ) ;	// �f�t�H���g���C�g�̃^�C�v���|�C���g���C�g�ɂ���
extern	int			GetLightType(				void ) ;																	// �f�t�H���g���C�g�̃^�C�v���擾����( �߂�l�� DX_LIGHTTYPE_DIRECTIONAL �� )
extern	int			SetLightEnable(				int EnableFlag ) ;															// �f�t�H���g���C�g���g�p���邩�ǂ�����ݒ肷��
extern	int			GetLightEnable(				void ) ;																	// �f�t�H���g���C�g���g�p���邩�ǂ������擾����( �߂�l�@TRUE:�L��  FALSE:���� )
extern	int			SetLightDifColor(			COLOR_F Color ) ;															// �f�t�H���g���C�g�̃f�B�t���[�Y�J���[��ݒ肷��
extern	COLOR_F		GetLightDifColor(			void ) ;																	// �f�t�H���g���C�g�̃f�B�t���[�Y�J���[���擾����
extern	int			SetLightSpcColor(			COLOR_F Color ) ;															// �f�t�H���g���C�g�̃X�y�L�����J���[��ݒ肷��
extern	COLOR_F		GetLightSpcColor(			void ) ;																	// �f�t�H���g���C�g�̃X�y�L�����J���[���擾����
extern	int			SetLightAmbColor(			COLOR_F Color ) ;															// �f�t�H���g���C�g�̃A���r�G���g�J���[��ݒ肷��
extern	COLOR_F		GetLightAmbColor(			void ) ;																	// �f�t�H���g���C�g�̃A���r�G���g�J���[���擾����
extern	int			SetLightDirection(			VECTOR Direction ) ;														// �f�t�H���g���C�g�̕�����ݒ肷��
extern	VECTOR		GetLightDirection(			void ) ;																	// �f�t�H���g���C�g�̕������擾����
extern	int			SetLightPosition(			VECTOR Position ) ;															// �f�t�H���g���C�g�̈ʒu��ݒ肷��
extern	VECTOR		GetLightPosition(			void ) ;																	// �f�t�H���g���C�g�̈ʒu���擾����
extern	int			SetLightRangeAtten(			float Range, float Atten0, float Atten1, float Atten2 ) ;					// �f�t�H���g���C�g�̋��������p�����[�^��ݒ肷��( �L�������A���������W���O�A�P�A�Q )
extern	int			GetLightRangeAtten(			float *Range, float *Atten0, float *Atten1, float *Atten2 )	;				// �f�t�H���g���C�g�̋��������p�����[�^���擾����( �L�������A���������W���O�A�P�A�Q )
extern	int			SetLightAngle(				float OutAngle, float InAngle ) ;											// �f�t�H���g���C�g�̃X�|�b�g���C�g�̃p�����[�^��ݒ肷��( �O���R�[���p�x�A�����R�[���p�x )
extern	int			GetLightAngle(				float *OutAngle, float *InAngle ) ;											// �f�t�H���g���C�g�̃X�|�b�g���C�g�̃p�����[�^���擾����( �O���R�[���p�x�A�����R�[���p�x )

extern	int			CreateDirLightHandle(       VECTOR Direction ) ;														// �f�B���N�V���i�����C�g�n���h�����쐬����
extern	int			CreateSpotLightHandle(      VECTOR Position, VECTOR Direction, float OutAngle, float InAngle, float Range, float Atten0, float Atten1, float Atten2 ) ;	// �X�|�b�g���C�g�n���h�����쐬����
extern	int			CreatePointLightHandle(     VECTOR Position, float Range, float Atten0, float Atten1, float Atten2 ) ;	// �|�C���g���C�g�n���h�����쐬����
extern	int			DeleteLightHandle(          int LHandle ) ;																// ���C�g�n���h�����폜����
extern	int			DeleteLightHandleAll(       void ) ;																	// ���C�g�n���h����S�č폜����
extern	int			SetLightTypeHandle(         int LHandle, int LightType ) ;												// ���C�g�n���h���̃��C�g�̃^�C�v��ύX����( DX_LIGHTTYPE_DIRECTIONAL �� )
extern	int			SetLightEnableHandle(       int LHandle, int EnableFlag ) ;												// ���C�g�n���h���̃��C�g���ʂ̗L���A������ݒ肷��( TRUE:�L��  FALSE:���� )
extern	int			SetLightDifColorHandle(     int LHandle, COLOR_F Color ) ;												// ���C�g�n���h���̃��C�g�̃f�B�t���[�Y�J���[��ݒ肷��
extern	int			SetLightSpcColorHandle(     int LHandle, COLOR_F Color ) ;												// ���C�g�n���h���̃��C�g�̃X�y�L�����J���[��ݒ肷��
extern	int			SetLightAmbColorHandle(     int LHandle, COLOR_F Color ) ;												// ���C�g�n���h���̃��C�g�̃A���r�G���g�J���[��ݒ肷��
extern	int			SetLightDirectionHandle(    int LHandle, VECTOR Direction ) ;											// ���C�g�n���h���̃��C�g�̕�����ݒ肷��
extern	int			SetLightPositionHandle(     int LHandle, VECTOR Position ) ;											// ���C�g�n���h���̃��C�g�̈ʒu��ݒ肷��
extern	int			SetLightRangeAttenHandle(   int LHandle, float Range, float Atten0, float Atten1, float Atten2 ) ;		// ���C�g�n���h���̃��C�g�̋��������p�����[�^��ݒ肷��( �L�������A���������W���O�A�P�A�Q )
extern	int			SetLightAngleHandle(        int LHandle, float OutAngle, float InAngle ) ;								// ���C�g�n���h���̃��C�g�̃X�|�b�g���C�g�̃p�����[�^��ݒ肷��( �O���R�[���p�x�A�����R�[���p�x )
extern	int			GetLightTypeHandle(         int LHandle ) ;																// ���C�g�n���h���̃��C�g�̃^�C�v���擾����( �߂�l�� DX_LIGHTTYPE_DIRECTIONAL �� )
extern	int			GetLightEnableHandle(       int LHandle ) ;																// ���C�g�n���h���̃��C�g���ʂ̗L���A�������擾����( TRUE:�L��  FALSE:���� )
extern	COLOR_F		GetLightDifColorHandle(     int LHandle ) ;																// ���C�g�n���h���̃��C�g�̃f�B�t���[�Y�J���[���擾����
extern	COLOR_F		GetLightSpcColorHandle(     int LHandle ) ;																// ���C�g�n���h���̃��C�g�̃X�y�L�����J���[���擾����
extern	COLOR_F		GetLightAmbColorHandle(     int LHandle ) ;																// ���C�g�n���h���̃��C�g�̃A���r�G���g�J���[���擾����
extern	VECTOR		GetLightDirectionHandle(    int LHandle ) ;																// ���C�g�n���h���̃��C�g�̕������擾����
extern	VECTOR		GetLightPositionHandle(     int LHandle ) ;																// ���C�g�n���h���̃��C�g�̈ʒu���擾����
extern	int			GetLightRangeAttenHandle(   int LHandle, float *Range, float *Atten0, float *Atten1, float *Atten2 ) ;	// ���C�g�n���h���̃��C�g�̋��������p�����[�^���擾����( �L�������A���������W���O�A�P�A�Q )
extern	int			GetLightAngleHandle(        int LHandle, float *OutAngle, float *InAngle ) ;							// ���C�g�n���h���̃��C�g�̃X�|�b�g���C�g�̃p�����[�^���擾����( �O���R�[���p�x�A�����R�[���p�x )

extern	int			GetEnableLightHandleNum(	void ) ;																	// �L���ɂȂ��Ă��郉�C�g�n���h���̐����擾����
extern	int			GetEnableLightHandle(		int Index ) ;																// �L���ɂȂ��Ă��郉�C�g�n���h�����擾����

// �F���擾�p�֐�
extern	int			GetTexFormatIndex(			IMAGEFORMATDESC *Format ) ;																									// �e�N�X�`���t�H�[�}�b�g�̃C���f�b�N�X�𓾂�
extern	int			ColorKaiseki(				void *PixelData, COLORDATA* ColorData ) ;																					// �F�r�b�g�����
#ifdef __WINDOWS__
extern	int			CreatePixelFormat(			D_DDPIXELFORMAT *PixelFormatBuf, int ColorBitDepth, DWORD RedMask, DWORD GreenMask, DWORD BlueMask, DWORD AlphaMask ) ;		// DDPIXELFORMAT�f�[�^���쐬����
#endif // __WINDOWS__








// DxMask.cpp �֐��v���g�^�C�v�錾

#ifndef DX_NON_MASK

// �}�X�N�֌W 
extern	int			CreateMaskScreen(				void ) ;																						// �}�X�N�X�N���[�����쐬����
extern	int			DeleteMaskScreen(				void ) ;																						// �}�X�N�X�N���[�����폜����
extern	int			DrawMaskToDirectData(			int x, int y, int Width, int Height, void *MaskData , int TransMode ) ;							// �}�X�N�X�N���[���Ƀ�������̃r�b�g�}�b�v�f�[�^��]������( MaskData �� 1byte �� 1dot �\���P���C�������� Width byte �̃f�[�^�z��̐擪�A�h���X )
extern	int			DrawFillMaskToDirectData(		int x1, int y1, int x2, int y2,  int Width, int Height, void *MaskData ) ;						// �}�X�N�X�N���[���Ƀ�������̃r�b�g�}�b�v�f�[�^�Ŏw���`����h��Ԃ��悤�ɓ]������

extern	int			SetUseMaskScreenFlag(			int ValidFlag ) ;																				// �}�X�N�X�N���[�����g�p���邩�ǂ�����ݒ肷��( ValidFlag:�g�p���邩�ǂ���( TRUE:�g�p����  FALSE:�g�p���Ȃ�( �f�t�H���g ) )
extern	int			GetUseMaskScreenFlag(			void ) ;																						// �}�X�N�X�N���[�����g�p���邩�ǂ������擾����
extern	int			FillMaskScreen(					int Flag ) ;																					// �}�X�N�X�N���[�����w��̐F�œh��Ԃ�

extern	int			InitMask(						void ) ;																						// �}�X�N�n���h�������ׂč폜����
extern	int			MakeMask(						int Width, int Height ) ;																		// �}�X�N�n���h�����쐬����
extern	int			GetMaskSize(					int *WidthBuf, int *HeightBuf, int MaskHandle ) ;												// �}�X�N�n���h�������}�X�N�C���[�W�̃T�C�Y���擾����
extern	int			SetDataToMask(					int Width, int Height, void *MaskData, int MaskHandle ) ;										// �}�X�N�n���h���Ƀr�b�g�}�b�v�C���[�W��]������
extern	int			DeleteMask(						int MaskHandle ) ;																				// �}�X�N�n���h�����폜����
extern	int			BmpBltToMask(					HBITMAP Bmp, int BmpPointX, int BmpPointY, int MaskHandle ) ;									// �}�X�N�n���h���ɂa�l�o�f�[�^��]������
extern	int			LoadMask(						const TCHAR *FileName ) ;																		// �摜�t�@�C����ǂݍ��݃}�X�N�n���h�����쐬����
extern	int			LoadDivMask(					const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf ) ;	// �摜�t�@�C���𕪊��ǂݍ��݂��ă}�X�N�n���h�����쐬����
extern	int			DrawMask(						int x, int y, int MaskHandle, int TransMode ) ;													// �}�X�N�X�N���[���Ƀ}�X�N�n���h���̎��}�X�N�C���[�W����������
#ifndef DX_NON_FONT
extern	int			DrawFormatStringMask(			int x, int y, int Flag,                 const TCHAR *FormatString, ... ) ;						// �����w�肠��̕�������}�X�N�X�N���[���ɕ`�悷��
extern	int			DrawFormatStringMaskToHandle(	int x, int y, int Flag, int FontHandle, const TCHAR *FormatString, ... ) ;						// �����w�肠��̕�������}�X�N�X�N���[���ɕ`�悷��( �t�H���g�n���h���w��� )( SetFontCacheToTextureFlag( FALSE ) ; �ɂ��č쐬�����t�H���g�n���h���̂ݎg�p�\ )
extern	int			DrawStringMask(					int x, int y, int Flag,                 const TCHAR *String ) ;									// ��������}�X�N�X�N���[���ɕ`�悷��
extern	int			DrawStringMaskToHandle(			int x, int y, int Flag, int FontHandle, const TCHAR *String ) ;									// ��������}�X�N�X�N���[���ɕ`�悷��( �t�H���g�n���h���w��� )( SetFontCacheToTextureFlag( FALSE ) ; �ɂ��č쐬�����t�H���g�n���h���̂ݎg�p�\ )
#endif // DX_NON_FONT
extern	int			DrawFillMask(					int x1, int y1, int x2, int y2, int MaskHandle ) ;												// �}�X�N�n���h�������}�X�N�C���[�W���}�X�N�X�N���[�������ς��ɕ`�悷��( �^�C����ɕ��ׂ� )
extern	int			SetMaskReverseEffectFlag(		int ReverseFlag ) ;																				// �}�X�N�C���[�W���̐��l�ɑ΂�����ʂ��t�]������( ���o�[�W�����Ƃ̌݊����ׂ̈̋@�\ )

extern 	int			GetMaskScreenData(				int x1, int y1, int x2, int y2, int MaskHandle ) ;												// �}�X�N�X�N���[���̎w���`�������}�X�N�n���h���ɓ]������
extern	int			GetMaskUseFlag(					void ) ;																						// �}�X�N�X�N���[�����g�p����ݒ�ɂȂ��Ă��邩�ǂ������擾����

#endif // DX_NON_MASK
















// DxFont.cpp �֐��v���g�^�C�v�錾

#ifndef DX_NON_FONT

// �t�H���g�A������`��֌W�֐�
extern	int			EnumFontName(                           TCHAR *NameBuffer, int NameBufferNum, int JapanOnlyFlag = TRUE ) ;								// �g�p�\�ȃt�H���g�̖��O��񋓂���( NameBuffer �� 64�o�C�g��؂�Ŗ��O���i�[����܂� )
extern	int			EnumFontNameEx(                         TCHAR *NameBuffer, int NameBufferNum, int CharSet = -1 /* DX_CHARSET_DEFAULT �� */ ) ;			// �g�p�\�ȃt�H���g�̖��O��񋓂���( NameBuffer �� 64�o�C�g��؂�Ŗ��O���i�[����܂� )( �����Z�b�g�w��� )
extern	int			EnumFontNameEx2(						TCHAR *NameBuffer, int NameBufferNum, TCHAR *EnumFontName, int CharSet = -1 /* DX_CHARSET_DEFAULT �� */ ) ;	// �w��̃t�H���g���̃t�H���g��񋓂���
extern	int			InitFontToHandle(                       void ) ;																						// �S�Ẵt�H���g�n���h�����폜����

extern	int			CreateFontToHandle(                     const TCHAR *FontName, int Size, int Thick, int FontType = -1 , int CharSet = -1 , int EdgeSize = -1 , int Italic = FALSE , int Handle = -1 ) ;		// �t�H���g�n���h�����쐬����
extern	int			SetFontSpaceToHandle(                   int Point, int FontHandle ) ;																	// �t�H���g�n���h���̎��Ԃ�ύX����
extern	int			DeleteFontToHandle(                     int FontHandle ) ;																				// �t�H���g�n���h�����폜����
extern	int			SetFontLostFlag(                        int FontHandle, int *LostFlag ) ;																// �t�H���g�n���h�����폜�����ۂ� TRUE ��������ϐ��̃A�h���X��ݒ肷��

extern	int			ChangeFont(                             const TCHAR *FontName, int CharSet = -1 /* DX_CHARSET_SHFTJIS �� */ ) ;							// �f�t�H���g�t�H���g�n���h���Ŏg�p����t�H���g��ύX
extern	int			ChangeFontType(                         int FontType ) ;																				// �f�t�H���g�t�H���g�n���h���̃t�H���g�^�C�v�̕ύX
extern	int			SetFontSize(                            int FontSize ) ;																				// �f�t�H���g�t�H���g�n���h���̃T�C�Y��ݒ肷��
extern	int			GetFontSize(                            void ) ;																						// �f�t�H���g�t�H���g�n���h���̃T�C�Y���擾����
extern	int			SetFontThickness(                       int ThickPal ) ;																				// �f�t�H���g�t�H���g�n���h���̑�����ݒ肷��
extern	int			SetFontSpace(                           int Point ) ;																					// �f�t�H���g�t�H���g�n���h���̎��Ԃ�ύX����
extern	int			SetDefaultFontState(                    const TCHAR *FontName, int Size, int Thick ) ;													// �f�t�H���g�t�H���g�n���h���̐ݒ��ύX����
extern	int			GetDefaultFontHandle(                   void ) ;																						// �f�t�H���g�t�H���g�n���h�����擾����
extern	int			GetFontMaxWidth(                        void ) ;																						// �f�t�H���g�t�H���g�n���h���̕����̍ő啝���擾����
extern	int			GetDrawStringWidth(                     const TCHAR *String, int StrLen, int VerticalFlag = FALSE ) ;									// �f�t�H���g�t�H���g�n���h�����g�p����������̕`�敝���擾����
extern	int			GetDrawFormatStringWidth(               const TCHAR *FormatString, ... ) ;																// �f�t�H���g�t�H���g�n���h�����g�p���������t��������̕`�敝���擾����
extern	int			GetDrawExtendStringWidth(               double ExRateX, const TCHAR *String, int StrLen, int VerticalFlag = FALSE ) ;					// �f�t�H���g�t�H���g�n���h�����g�p����������̕`�敝���擾����( �g�嗦�t�� )
extern	int			GetDrawExtendFormatStringWidth(         double ExRateX, const TCHAR *FormatString, ... ) ;												// �f�t�H���g�t�H���g�n���h�����g�p���������t��������̕`�敝���擾����( �g�嗦�t�� )

extern	int			GetFontMaxWidthToHandle(                int FontHandle ) ;																				// �t�H���g�n���h���̕����̍ő啝���擾����
extern	int			GetFontSizeToHandle(                    int FontHandle ) ;																				// �t�H���g�n���h���̃T�C�Y���擾����
extern	int			GetFontCharInfo(                        int FontHandle, const TCHAR *Char, int *DrawX, int *DrawY, int *NextCharX, int *SizeX, int *SizeY ) ;	// �t�H���g�n���h���̎w��̕����̕`������擾����
extern	int			GetDrawStringWidthToHandle(             const TCHAR *String, int StrLen, int FontHandle, int VerticalFlag = FALSE ) ;					// �t�H���g�n���h�����g�p����������̕`�敝���擾����
extern	int			GetDrawFormatStringWidthToHandle(       int FontHandle, const TCHAR *FormatString, ... ) ;												// �t�H���g�n���h�����g�p���������t��������̕`�敝���擾����
extern	int			GetDrawExtendStringWidthToHandle(       double ExRateX, const TCHAR *String, int StrLen, int FontHandle, int VerticalFlag = FALSE ) ;	// �t�H���g�n���h�����g�p����������̕`�敝���擾����
extern	int			GetDrawExtendFormatStringWidthToHandle( double ExRateX, int FontHandle, const TCHAR *FormatString, ... ) ;								// �t�H���g�n���h�����g�p���������t��������̕`�敝���擾����
extern	int			GetFontStateToHandle(                   TCHAR *FontName, int *Size, int *Thick, int FontHandle) ;										// �t�H���g�n���h���̏����擾����
extern	int			CheckFontCacheToTextureFlag(            int FontHandle ) ;																				// �t�H���g�n���h�����e�N�X�`���L���b�V�����g�p���Ă��邩�ǂ������擾����
extern	int			CheckFontChacheToTextureFlag(           int FontHandle ) ;																				// CheckFontCacheToTextureFlag �̌뎚��
extern	int			CheckFontHandleValid(                   int FontHandle ) ;																				// �t�H���g�n���h�����L�����ǂ������擾����

extern	int			SetFontCacheToTextureFlag(              int Flag ) ;																					// �t�H���g�̃L���b�V���Ƀe�N�X�`�����g�p���邩�ǂ�����ݒ肷��( TRUE:�e�N�X�`�����g�p����( �f�t�H���g )  FALSE:�e�N�X�`���͎g�p���Ȃ� )
extern	int			GetFontCacheToTextureFlag(              void ) ;																						// �t�H���g�̃L���b�V���Ƀe�N�X�`�����g�p���邩�ǂ�����ݒ肷��
extern	int			SetFontChacheToTextureFlag(             int Flag ) ;																					// SetFontCacheToTextureFlag �̌뎚��
extern	int			GetFontChacheToTextureFlag(             void ) ;																						// GetFontCacheToTextureFlag �̌뎚��
extern	int			SetFontCacheCharNum(                    int CharNum ) ;																					// �t�H���g�L���b�V���ŃL���b�V���ł��镶������ݒ肷��
extern	int			GetFontCacheCharNum(                    void ) ;																						// �t�H���g�L���b�V���ŃL���b�V���ł��镶�������擾����( �߂�l  0:�f�t�H���g  1�ȏ�:�w�蕶���� )

// FontCacheStringDraw �̑���� DrawString ���g���Ă�������
extern	int			FontCacheStringDrawToHandle(            int x, int y, const TCHAR *StrData, int Color, int EdgeColor, BASEIMAGE *DestImage, RECT *ClipRect /* NULL �� */ , int FontHandle, int VerticalFlag = FALSE , SIZE *DrawSizeP = NULL ) ;
extern	int			FontBaseImageBlt(                       int x, int y, const TCHAR *StrData, BASEIMAGE *DestImage, BASEIMAGE *DestEdgeImage,                 int VerticalFlag = FALSE ) ;	// ��{�C���[�W�ɕ������`�悷��( �f�t�H���g�t�H���g�n���h�����g�p���� )
extern	int			FontBaseImageBltToHandle(               int x, int y, const TCHAR *StrData, BASEIMAGE *DestImage, BASEIMAGE *DestEdgeImage, int FontHandle, int VerticalFlag = FALSE ) ;	// ��{�C���[�W�ɕ������`�悷��

extern	int			MultiByteCharCheck(                     const char *Buf, int CharSet /* DX_CHARSET_SHFTJIS */ ) ;										// �Q�o�C�g���������ׂ�( TRUE:�Q�o�C�g����  FALSE:�P�o�C�g���� )

// ������`��֐�
extern	int			DrawString(                             int x, int y, const TCHAR *String, int Color,                 int EdgeColor = 0 ) ;																				// �f�t�H���g�t�H���g�n���h�����g�p���ĕ������`�悷��
extern	int			DrawVString(                            int x, int y, const TCHAR *String, int Color,                 int EdgeColor = 0 ) ;																				// �f�t�H���g�t�H���g�n���h�����g�p���ĕ������`�悷��( �c���� )
extern	int			DrawFormatString(                       int x, int y, int Color,                 const TCHAR *FormatString, ... ) ;																						// �f�t�H���g�t�H���g�n���h�����g�p���ď����w�蕶�����`�悷��
extern	int			DrawFormatVString(                      int x, int y, int Color,                 const TCHAR *FormatString, ... ) ;																						// �f�t�H���g�t�H���g�n���h�����g�p���ď����w�蕶�����`�悷��( �c���� )
extern	int			DrawExtendString(                       int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int Color,                 int EdgeColor = 0 ) ;												// �f�t�H���g�t�H���g�n���h�����g�p���ĕ�����̊g��`��
extern	int			DrawExtendVString(                      int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int Color,                 int EdgeColor = 0 ) ;												// �f�t�H���g�t�H���g�n���h�����g�p���ĕ�����̊g��`��( �c���� )
extern	int			DrawExtendFormatString(                 int x, int y, double ExRateX, double ExRateY, int Color,                 const TCHAR *FormatString, ... ) ;														// �f�t�H���g�t�H���g�n���h�����g�p���ď����w�蕶������g��`�悷��
extern	int			DrawExtendFormatVString(                int x, int y, double ExRateX, double ExRateY, int Color,                 const TCHAR *FormatString, ... ) ;														// �f�t�H���g�t�H���g�n���h�����g�p���ď����w�蕶������g��`�悷��( �c���� )

extern	int			DrawNumberToI(                          int x, int y,                          int    Num, int RisesNum, int Color, int EdgeColor = 0 ) ;																// �f�t�H���g�t�H���g�n���h�����g�p���Đ����^�̐��l��`�悷��
extern	int			DrawNumberToF(                          int x, int y,                          double Num, int Length,   int Color, int EdgeColor = 0 ) ;																// �f�t�H���g�t�H���g�n���h�����g�p���ĕ��������_�^�̐��l��`�悷��
extern	int			DrawNumberPlusToI(                      int x, int y, const TCHAR *NoteString, int    Num, int RisesNum, int Color, int EdgeColor = 0 ) ;																// �f�t�H���g�t�H���g�n���h�����g�p���Đ����^�̐��l�Ƃ��̐����̕��������x�ɕ`�悷��
extern 	int			DrawNumberPlusToF(                      int x, int y, const TCHAR *NoteString, double Num, int Length,   int Color, int EdgeColor = 0 ) ;																// �f�t�H���g�t�H���g�n���h�����g�p���ĕ��������_�^�̐��l�Ƃ��̐����̕��������x�ɕ`�悷��

extern	int			DrawStringToZBuffer(                    int x, int y, const TCHAR *String,                                                 int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;									// �f�t�H���g�t�H���g�n���h�����g�p���Ăy�o�b�t�@�ɑ΂��ĕ������`�悷��
extern	int			DrawVStringToZBuffer(                   int x, int y, const TCHAR *String,                                                 int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;									// �f�t�H���g�t�H���g�n���h�����g�p���Ăy�o�b�t�@�ɑ΂��ĕ������`�悷��( �c���� )
extern	int			DrawFormatStringToZBuffer(              int x, int y,                                                                      int WriteZMode /* DX_ZWRITE_MASK �� */, const TCHAR *FormatString, ... ) ;	// �f�t�H���g�t�H���g�n���h�����g�p���Ăy�o�b�t�@�ɑ΂��ď����w�蕶�����`�悷��
extern	int			DrawFormatVStringToZBuffer(             int x, int y,                                                                      int WriteZMode /* DX_ZWRITE_MASK �� */, const TCHAR *FormatString, ... ) ;	// �f�t�H���g�t�H���g�n���h�����g�p���Ăy�o�b�t�@�ɑ΂��ď����w�蕶�����`�悷��( �c���� )
extern	int			DrawExtendStringToZBuffer(              int x, int y, double ExRateX, double ExRateY, const TCHAR *String,                 int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;									// �f�t�H���g�t�H���g�n���h�����g�p���Ăy�o�b�t�@�ɑ΂��ĕ�������g��`�悷��
extern	int			DrawExtendVStringToZBuffer(             int x, int y, double ExRateX, double ExRateY, const TCHAR *String,                 int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;									// �f�t�H���g�t�H���g�n���h�����g�p���Ăy�o�b�t�@�ɑ΂��ĕ�������g��`�悷��( �c���� )
extern	int			DrawExtendFormatStringToZBuffer(        int x, int y, double ExRateX, double ExRateY,                                      int WriteZMode /* DX_ZWRITE_MASK �� */, const TCHAR *FormatString, ... ) ;	// �f�t�H���g�t�H���g�n���h�����g�p���Ăy�o�b�t�@�ɑ΂��ď����w�蕶������g��`�悷��
extern	int			DrawExtendFormatVStringToZBuffer(       int x, int y, double ExRateX, double ExRateY,                                      int WriteZMode /* DX_ZWRITE_MASK �� */, const TCHAR *FormatString, ... ) ;	// �f�t�H���g�t�H���g�n���h�����g�p���Ăy�o�b�t�@�ɑ΂��ď����w�蕶������g��`�悷��( �c���� )


extern	int			DrawStringToHandle(                     int x, int y, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 , int VerticalFlag = FALSE ) ;													// �t�H���g�n���h�����g�p���ĕ������`�悷��
extern	int			DrawVStringToHandle(                    int x, int y, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 ) ;																				// �t�H���g�n���h�����g�p���ĕ������`�悷��( �c���� )
extern	int			DrawFormatStringToHandle(               int x, int y, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;																						// �t�H���g�n���h�����g�p���ď����w�蕶�����`�悷��
extern	int			DrawFormatVStringToHandle(              int x, int y, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;																						// �t�H���g�n���h�����g�p���ď����w�蕶�����`�悷��( �c���� )
extern	int			DrawExtendStringToHandle(               int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 , int VerticalFlag = FALSE ) ;					// �t�H���g�n���h�����g�p���ĕ�������g��`�悷��
extern	int			DrawExtendVStringToHandle(              int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 ) ;												// �t�H���g�n���h�����g�p���ĕ�������g��`�悷��( �c���� )
extern	int			DrawExtendFormatStringToHandle(         int x, int y, double ExRateX, double ExRateY, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;														// �t�H���g�n���h�����g�p���ď����w�蕶������g��`�悷��
extern	int			DrawExtendFormatVStringToHandle(        int x, int y, double ExRateX, double ExRateY, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;														// �t�H���g�n���h�����g�p���ď����w�蕶������g��`�悷��( �c���� )

extern	int			DrawNumberToIToHandle(                  int x, int y,                          int    Num, int RisesNum, int Color, int FontHandle, int EdgeColor = 0 ) ;												// �t�H���g�n���h�����g�p���Đ����^�̐��l��`�悷��
extern	int			DrawNumberToFToHandle(                  int x, int y,                          double Num, int Length,   int Color, int FontHandle, int EdgeColor = 0 ) ;												// �t�H���g�n���h�����g�p���ĕ��������_�^�̐��l��`�悷��
extern	int			DrawNumberPlusToIToHandle(              int x, int y, const TCHAR *NoteString, int    Num, int RisesNum, int Color, int FontHandle, int EdgeColor = 0 ) ;												// �t�H���g�n���h�����g�p���Đ����^�̐��l�Ƃ��̐����̕��������x�ɕ`�悷��
extern	int			DrawNumberPlusToFToHandle(              int x, int y, const TCHAR *NoteString, double Num, int Length,   int Color, int FontHandle, int EdgeColor = 0 ) ;												// �t�H���g�n���h�����g�p���ĕ��������_�^�̐��l�Ƃ��̐����̕��������x�ɕ`�悷��

extern	int			DrawStringToHandleToZBuffer(            int x, int y, const TCHAR *String, int FontHandle,                                 int WriteZMode /* DX_ZWRITE_MASK �� */ , int VerticalFlag = FALSE ) ;		// �t�H���g�n���h�����g�p���Ăy�o�b�t�@�ɑ΂��ĕ������`�悷��
extern	int			DrawVStringToHandleToZBuffer(           int x, int y, const TCHAR *String, int FontHandle,                                 int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;									// �t�H���g�n���h�����g�p���Ăy�o�b�t�@�ɑ΂��ĕ������`�悷��( �c���� )
extern	int			DrawFormatStringToHandleToZBuffer(      int x, int y, int FontHandle,                                                      int WriteZMode /* DX_ZWRITE_MASK �� */, const TCHAR *FormatString, ... ) ;	// �t�H���g�n���h�����g�p���Ăy�o�b�t�@�ɑ΂��ď����w�蕶�����`�悷��
extern	int			DrawFormatVStringToHandleToZBuffer(     int x, int y, int FontHandle,                                                      int WriteZMode /* DX_ZWRITE_MASK �� */, const TCHAR *FormatString, ... ) ;	// �t�H���g�n���h�����g�p���Ăy�o�b�t�@�ɑ΂��ď����w�蕶�����`�悷��( �c���� )
extern	int			DrawExtendStringToHandleToZBuffer(      int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int FontHandle, int WriteZMode /* DX_ZWRITE_MASK �� */ , int VerticalFlag = FALSE ) ;		// �t�H���g�n���h�����g�p���Ăy�o�b�t�@�ɑ΂��ĕ�������g��`�悷��
extern	int			DrawExtendVStringToHandleToZBuffer(     int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int FontHandle, int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;									// �t�H���g�n���h�����g�p���Ăy�o�b�t�@�ɑ΂��ĕ�������g��`�悷��( �c���� )
extern	int			DrawExtendFormatStringToHandleToZBuffer(  int x, int y, double ExRateX, double ExRateY, int FontHandle,                    int WriteZMode /* DX_ZWRITE_MASK �� */, const TCHAR *FormatString, ... ) ;	// �t�H���g�n���h�����g�p���Ăy�o�b�t�@�ɑ΂��ď����w�蕶������g��`�悷��
extern	int			DrawExtendFormatVStringToHandleToZBuffer( int x, int y, double ExRateX, double ExRateY, int FontHandle,                    int WriteZMode /* DX_ZWRITE_MASK �� */, const TCHAR *FormatString, ... ) ;	// �t�H���g�n���h�����g�p���Ăy�o�b�t�@�ɑ΂��ď����w�蕶������g��`�悷��( �c���� )

#endif // DX_NON_FONT








// DxMath.cpp �֐��v���g�^�C�v�錾

// ���Z���C�u����
extern	int			CreateIdentityMatrix(         MATRIX *Out ) ;															// �P�ʍs����쐬����
extern	int			CreateLookAtMatrix(           MATRIX *Out, VECTOR *Eye, VECTOR *At, VECTOR *Up ) ;						// �r���[�s����쐬����
extern	int			CreateLookAtMatrix2(          MATRIX *Out, VECTOR *Eye, double XZAngle, double Oira ) ;					// �r���[�s����쐬����(��������]�l�Ŏw��)
extern	int			CreateLookAtMatrixRH(         MATRIX *Out, VECTOR *Eye, VECTOR *At, VECTOR *Up ) ;						// �r���[�s����쐬����(�E����W�n�p)
extern	int			CreateMultiplyMatrix(         MATRIX *Out, MATRIX *In1, MATRIX *In2 ) ;									// �s��̐ς����߂�
extern	int			CreatePerspectiveFovMatrix(   MATRIX *Out, float fov, float zn, float zf, float aspect = -1.0f ) ;		// �ˉe�s����쐬����
extern	int			CreatePerspectiveFovMatrixRH( MATRIX *Out, float fov, float zn, float zf, float aspect = -1.0f ) ;		// �ˉe�s����쐬����(�E����W�n�p)
extern	int			CreateOrthoMatrix(            MATRIX *Out, float size, float zn, float zf, float aspect = -1.0f ) ;		// ���ˉe�s����쐬����
extern	int			CreateOrthoMatrixRH(          MATRIX *Out, float size, float zn, float zf, float aspect = -1.0f ) ;		// ���ˉe�s����쐬����(�E����W�n�p)
extern	int			CreateScalingMatrix(          MATRIX *Out, float sx, float sy, float sz ) ;								// �X�P�[�����O�s����쐬����
extern	int			CreateRotationXMatrix(        MATRIX *Out, float Angle ) ;												// �w���𒆐S�Ƃ�����]�s����쐬����
extern	int			CreateRotationYMatrix(        MATRIX *Out, float Angle ) ;												// �x���𒆐S�Ƃ�����]�s����쐬����
extern	int			CreateRotationZMatrix(        MATRIX *Out, float Angle ) ;												// �y���𒆐S�Ƃ�����]�s����쐬����
extern	int			CreateTranslationMatrix(      MATRIX *Out, float x, float y, float z ) ;								// ���s�ړ��s����쐬����
extern	int			CreateTransposeMatrix(        MATRIX *Out, MATRIX *In ) ;												// �]�u�s����쐬����
extern	int			CreateInverseMatrix(          MATRIX *Out, MATRIX *In ) ;												// �t�s����쐬����
extern	int			CreateViewportMatrix(         MATRIX *Out, float CenterX, float CenterY, float Width, float Height ) ;	// �r���[�|�[�g�s����쐬����
extern	int			CreateRotationXYZMatrix(      MATRIX *Out, float XRot, float YRot, float ZRot ) ;						// �w����]���x����]���y����]�����������s����쐬����
extern	int			CreateRotationXZYMatrix(      MATRIX *Out, float XRot, float YRot, float ZRot ) ;						// �w����]���y����]���x����]�����������s����쐬����
extern	int			CreateRotationYXZMatrix(      MATRIX *Out, float XRot, float YRot, float ZRot ) ;						// �x����]���w����]���y����]�����������s����쐬����
extern	int			CreateRotationYZXMatrix(      MATRIX *Out, float XRot, float YRot, float ZRot ) ;						// �x����]���y����]���w����]�����������s����쐬����
extern	int			CreateRotationZXYMatrix(      MATRIX *Out, float XRot, float YRot, float ZRot ) ;						// �y����]���w����]���x����]�����������s����쐬����
extern	int			CreateRotationZYXMatrix(      MATRIX *Out, float XRot, float YRot, float ZRot ) ;						// �y����]���x����]���w����]�����������s����쐬����
extern	int			GetMatrixXYZRotation(         MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;			// �s�񂩂�w�x�y����]�̒l���擾����( �߂�l�@-1:�W���o�����b�N����  0:���� )
extern	int			GetMatrixXZYRotation(         MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;			// �s�񂩂�w�y�x����]�̒l���擾����( �߂�l�@-1:�W���o�����b�N����  0:���� )
extern	int			GetMatrixYXZRotation(         MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;			// �s�񂩂�x�w�y����]�̒l���擾����( �߂�l�@-1:�W���o�����b�N����  0:���� )
extern	int			GetMatrixYZXRotation(         MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;			// �s�񂩂�x�y�w����]�̒l���擾����( �߂�l�@-1:�W���o�����b�N����  0:���� )
extern	int			GetMatrixZXYRotation(         MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;			// �s�񂩂�y�w�x����]�̒l���擾����( �߂�l�@-1:�W���o�����b�N����  0:���� )
extern	int			GetMatrixZYXRotation(         MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;			// �s�񂩂�y�x�w����]�̒l���擾����( �߂�l�@-1:�W���o�����b�N����  0:���� )
extern	int			VectorNormalize(              VECTOR *Out, VECTOR *In ) ;												// �x�N�g���𐳋K������
extern	int			VectorScale(                  VECTOR *Out, VECTOR *In, float Scale ) ;									// �x�N�g�����X�J���[�{����
extern	int			VectorMultiply(               VECTOR *Out, VECTOR *In1, VECTOR *In2 ) ;									// �x�N�g���̊|���Z������
extern	int			VectorSub(                    VECTOR *Out, VECTOR *In1, VECTOR *In2 ) ;									// Out = In1 - In2 �̃x�N�g���v�Z������ 
extern	int			VectorAdd(                    VECTOR *Out, VECTOR *In1, VECTOR *In2 ) ;									// Out = In1 + In2 �̃x�N�g���v�Z������ 
extern	int			VectorOuterProduct(           VECTOR *Out, VECTOR *In1, VECTOR *In2 ) ;									// In1��In2�̊O�ς��v�Z����
extern	float		VectorInnerProduct(           VECTOR *In1, VECTOR *In2 ) ;												// In1��In2�̓��ς��v�Z����
extern	int			VectorRotationX(              VECTOR *Out, VECTOR *In, double Angle ) ;									// �x�N�g���̂w�������ɂ�����]���s��
extern	int			VectorRotationY(              VECTOR *Out, VECTOR *In, double Angle ) ;									// �x�N�g���̂x�������ɂ�����]���s��
extern	int			VectorRotationZ(              VECTOR *Out, VECTOR *In, double Angle ) ;									// �x�N�g���̂y�������ɂ�����]���s��
extern	int			VectorTransform(              VECTOR *Out, VECTOR *InVec, MATRIX *InMatrix ) ;							// �x�N�g���s���4x4�����s�����Z����( w �� 1 �Ɖ��� )
extern	int			VectorTransform4(             VECTOR *Out, float *V4Out, VECTOR *InVec, float *V4In, MATRIX *InMatrix ) ; // �x�N�g���s���4x4�����s�����Z����( w �̗v�f��n�� )

extern	void		TriangleBarycenter(           VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3, VECTOR Position, float *u, float *v, float *w ) ;	// �w��̍��W����O�p�`�̏d�S�����߂�

extern	float		Segment_Segment_MinLength(         VECTOR SegmentAPos1, VECTOR SegmentAPos2, VECTOR SegmentBPos1, VECTOR SegmentBPos2 ) ;						// ��̐����̍ŋߓ_�Ԃ̋����𓾂�
extern	float		Segment_Segment_MinLength_Square(  VECTOR SegmentAPos1, VECTOR SegmentAPos2, VECTOR SegmentBPos1, VECTOR SegmentBPos2 ) ;						// ��̐����̍ŋߓ_�Ԃ̋����̓��𓾂�
extern	float		Segment_Triangle_MinLength(        VECTOR SegmentPos1, VECTOR SegmentPos2, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;	// �����ƎO�p�`�̍ŋߓ_�Ԃ̋����𓾂� 
extern	float		Segment_Triangle_MinLength_Square( VECTOR SegmentPos1, VECTOR SegmentPos2, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;	// �����ƎO�p�`�̍ŋߓ_�Ԃ̋����̓��𓾂� 
extern	float		Segment_Point_MinLength(           VECTOR SegmentPos1, VECTOR SegmentPos2, VECTOR PointPos ) ;													// �����Ɠ_�̈�ԋ߂������𓾂�
extern	float		Segment_Point_MinLength_Square(    VECTOR SegmentPos1, VECTOR SegmentPos2, VECTOR PointPos ) ;													// �����Ɠ_�̈�ԋ߂������̓��𓾂�
extern	float		Triangle_Point_MinLength(          VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3, VECTOR PointPos ) ;							// �O�p�`�Ɠ_�̈�ԋ߂������𓾂�
extern	float		Triangle_Point_MinLength_Square(   VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3, VECTOR PointPos ) ;							// �O�p�`�Ɠ_�̈�ԋ߂������̓��𓾂�
extern	VECTOR		Plane_Point_MinLength_Position(    VECTOR PlanePos, VECTOR PlaneNormal, VECTOR PointPos ) ;														// �_�Ɉ�ԋ߂����ʏ�̍��W�𓾂�
extern	float		Plane_Point_MinLength(             VECTOR PlanePos, VECTOR PlaneNormal, VECTOR PointPos ) ;														// ���ʂƓ_�̈�ԋ߂������𓾂�

extern	HITRESULT_LINE HitCheck_Line_Triangle(         VECTOR LinePos1, VECTOR LinePos2, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;										// �O�p�`�Ɛ��̓����蔻��
extern	int			HitCheck_Triangle_Triangle(        VECTOR Triangle1Pos1, VECTOR Triangle1Pos2, VECTOR Triangle1Pos3, VECTOR Triangle2Pos1, VECTOR Triangle2Pos2, VECTOR Triangle2Pos3 ) ;	// �O�p�`�ƎO�p�`�̓����蔻��( TRUE:�������Ă���  FALSE:�������Ă��Ȃ� )
extern	int			HitCheck_Line_Sphere(              VECTOR LinePos1, VECTOR LinePos2, VECTOR SphereCenterPos, float SphereR ) ;																// ���Ƌ��̓����蔻��( TRUE:�������Ă���  FALSE:�������Ă��Ȃ� )
extern	int			HitCheck_Sphere_Sphere(            VECTOR Sphere1CenterPos, float Sphere1R, VECTOR Sphere2CenterPos, float Sphere2R ) ;														// ���Ƌ��̓����蔻��( TRUE:�������Ă���  FALSE:�������Ă��Ȃ� )
extern	int			HitCheck_Sphere_Triangle(          VECTOR SphereCenterPos, float SphereR, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;									// ���ƎO�p�`�̓����蔻��( TRUE:�������Ă���  FALSE:�������Ă��Ȃ� )
extern	int			HitCheck_Capsule_Capsule(          VECTOR Cap1Pos1, VECTOR Cap1Pos2, float Cap1R, VECTOR Cap2Pos1, VECTOR Cap2Pos2, float Cap2R ) ;											// �J�v�Z�����m�̓����蔻��( TRUE:�������Ă���  FALSE:�������Ă��Ȃ� )
extern	int			HitCheck_Capsule_Triangle(         VECTOR CapPos1, VECTOR CapPos2, float CapR, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;							// �J�v�Z���ƎO�p�`�̓����蔻��( TRUE:�������Ă���  FALSE:�������Ă��Ȃ� )

// ���̑�
extern	int			RectClipping( RECT *MotoRect, RECT *ClippuRect ) ;							// ��`�̃N���b�s���O
extern	int			RectAdjust(   RECT *Rect ) ;												// ��`�� left �� right ���l���傫���ꍇ�Ȃǂ̌���␳����
extern	int			GetRectSize(  RECT *Rect, int *Width, int *Height ) ;						// ��`�̕��ƍ��������߂�

// �\�L�ȗ���
extern	MATRIX		MGetIdent(     void ) ;														// �P�ʍs����擾����
extern	MATRIX		MMult(         MATRIX In1, MATRIX In2 ) ;									// �s��̏�Z���s��
extern	MATRIX		MScale(        MATRIX InM, float Scale ) ;									// �s��̃X�P�[�����O���s��
extern	MATRIX		MAdd(          MATRIX In1, MATRIX In2 ) ;									// �s��̑����Z���s��
extern	MATRIX		MGetScale(     VECTOR Scale ) ;												// �g��s����擾����
extern	MATRIX		MGetRotX(      float XAxisRotate ) ;										// �w����]�s����擾����
extern	MATRIX		MGetRotY(      float YAxisRotate ) ;										// �x����]�s����擾����
extern	MATRIX		MGetRotZ(      float ZAxisRotate ) ;										// �y����]�s����擾����
extern	MATRIX		MGetRotAxis(   VECTOR RotateAxis, float Rotate ) ;							// �w�莲�Ŏw��p�x��]����s����擾����
extern	MATRIX		MGetRotVec2(   VECTOR In1, VECTOR In2 ) ;									// In1 �̌������� In2 �̌����֕ϊ������]�s����擾����( In2 �� In1 ���^�t�̃x�N�g���̏ꍇ�͉�]���͕s�� )
extern	MATRIX		MGetTranslate( VECTOR Trans ) ;												// ���s�ړ��s����擾����
extern	MATRIX		MGetAxis1(     VECTOR XAxis, VECTOR YAxis, VECTOR ZAxis, VECTOR Pos ) ;		// �w��̂R�����[�J���̃x�N�g������{����̃x�N�g���ɕϊ�����s����擾����( x' = XAxis.x * x + YAixs.x * y + ZAxis.z * z + Pos.x   y' = XAxis.y * x + YAixs.y * y + ZAxis.y * z + Pos.y      z' = XAxis.z * x + YAixs.z * y + ZAxis.z * z + Pos.z )
extern	MATRIX		MGetAxis2(     VECTOR XAxis, VECTOR YAxis, VECTOR ZAxis, VECTOR Pos ) ;		// ��{����̃x�N�g�����w��̂R����ɓ��e�����x�N�g���ɕϊ�����s����擾����( x' = XAxis.x * ( x - Pos.x ) + XAxis.y * ( x - Pos.x ) + XAxis.z * ( x - Pos.x )    y' = YAxis.x * ( x - Pos.x ) + YAxis.y * ( x - Pos.x ) + YAxis.z * ( x - Pos.x )    z' = ZAxis.x * ( x - Pos.x ) + ZAxis.y * ( x - Pos.x ) + ZAxis.z * ( x - Pos.x ) )
extern	MATRIX		MTranspose(    MATRIX InM ) ;												// �]�u�s����擾����
extern	MATRIX		MInverse(      MATRIX InM ) ;												// �t�s����擾����
extern  VECTOR		MGetSize(      MATRIX InM ) ;												// �g��s��̂w���A�x���A�y���̊g�嗦���擾����

// �x�N�g���l�̐���
__inline VECTOR VGet( float x, float y, float z )
{
	VECTOR Result;
	Result.x = x ;
	Result.y = y ;
	Result.z = z ;
	return Result ;
}

// �S�v�f�x�N�g���l�̐���
__inline FLOAT4 F4Get( float x, float y, float z, float w )
{
	FLOAT4 Result;
	Result.x = x ;
	Result.y = y ;
	Result.z = z ;
	Result.w = w ;
	return Result ;
}

// �x�N�g���̉��Z
__inline VECTOR		VAdd( const VECTOR &In1, const VECTOR &In2 )
{
	VECTOR Result ;
	Result.x = In1.x + In2.x ;
	Result.y = In1.y + In2.y ;
	Result.z = In1.z + In2.z ;
	return Result ;
}

// �x�N�g���̌��Z
__inline VECTOR		VSub( const VECTOR &In1, const VECTOR &In2 )
{
	VECTOR Result ;
	Result.x = In1.x - In2.x ;
	Result.y = In1.y - In2.y ;
	Result.z = In1.z - In2.z ;
	return Result ;
}

// �S�v�f�x�N�g���̉��Z
__inline FLOAT4		F4Add( const FLOAT4 &In1, const FLOAT4 &In2 )
{
	FLOAT4 Result ;
	Result.x = In1.x + In2.x ;
	Result.y = In1.y + In2.y ;
	Result.z = In1.z + In2.z ;
	Result.w = In1.w + In2.w ;
	return Result ;
}

// �S�v�f�x�N�g���̌��Z
__inline FLOAT4		F4Sub( const FLOAT4 &In1, const FLOAT4 &In2 )
{
	FLOAT4 Result ;
	Result.x = In1.x - In2.x ;
	Result.y = In1.y - In2.y ;
	Result.z = In1.z - In2.z ;
	Result.w = In1.w - In2.w ;
	return Result ;
}

// �x�N�g���̓���
__inline float		VDot( const VECTOR &In1, const VECTOR &In2 )
{
	return In1.x * In2.x + In1.y * In2.y + In1.z * In2.z ;
}

// �x�N�g���̊O��
__inline VECTOR		VCross( const VECTOR &In1, const VECTOR &In2 )
{
	VECTOR Result ;
	Result.x = In1.y * In2.z - In1.z * In2.y ;
	Result.y = In1.z * In2.x - In1.x * In2.z ;
	Result.z = In1.x * In2.y - In1.y * In2.x ;
	return Result ;
}

// �x�N�g���̃X�P�[�����O
__inline VECTOR		VScale( const VECTOR &In, float Scale )
{
	VECTOR Result ;
	Result.x = In.x * Scale ;
	Result.y = In.y * Scale ;
	Result.z = In.z * Scale ;
	return Result ;
}

// �S�v�f�x�N�g���̃X�P�[�����O
__inline FLOAT4		F4Scale( const FLOAT4 &In, float Scale )
{
	FLOAT4 Result ;
	Result.x = In.x * Scale ;
	Result.y = In.y * Scale ;
	Result.z = In.z * Scale ;
	Result.w = In.w * Scale ;
	return Result ;
}

// �x�N�g���̐��K��
extern VECTOR		VNorm( VECTOR In ) ;

// �x�N�g���̃T�C�Y
extern float		VSize( VECTOR In ) ;

// �x�N�g���̃T�C�Y�̂Q��
__inline float		VSquareSize( const VECTOR &In )
{
	return In.x * In.x + In.y * In.y + In.z * In.z ;
}

// �s����g�������W�ϊ�
__inline VECTOR		VTransform( const VECTOR &InV, const MATRIX &InM )
{
	VECTOR Result ;
	Result.x = InV.x * InM.m[0][0] + InV.y * InM.m[1][0] + InV.z * InM.m[2][0] + InM.m[3][0] ;
	Result.y = InV.x * InM.m[0][1] + InV.y * InM.m[1][1] + InV.z * InM.m[2][1] + InM.m[3][1] ;
	Result.z = InV.x * InM.m[0][2] + InV.y * InM.m[1][2] + InV.z * InM.m[2][2] + InM.m[3][2] ;
	return Result ;
}

// �s����g�������W�ϊ�( �X�P�[�����O�{��]�����̂� )
__inline VECTOR		VTransformSR( const VECTOR &InV, const MATRIX &InM )
{
	VECTOR Result ;
	Result.x = InV.x * InM.m[0][0] + InV.y * InM.m[1][0] + InV.z * InM.m[2][0] ;
	Result.y = InV.x * InM.m[0][1] + InV.y * InM.m[1][1] + InV.z * InM.m[2][1] ;
	Result.z = InV.x * InM.m[0][2] + InV.y * InM.m[1][2] + InV.z * InM.m[2][2] ;
	return Result ;
}

// ��̃x�N�g���������p�̃R�T�C���l�𓾂�
extern	float		VCos( VECTOR In1, VECTOR In2 ) ;

// ��̃x�N�g���������p�̊p�x�𓾂�( �P�ʁF���W�A�� )
extern	float		VRad( VECTOR In1, VECTOR In2 ) ;








// DxBaseImage.cpp �֐��v���g�^�C�v�錾

// ��{�C���[�W�f�[�^�̃��[�h�{�c�h�a�֌W
extern	int			CreateGraphImageOrDIBGraph(    const TCHAR *FileName, void *DataImage, int DataImageSize, int DataImageType /* LOADIMAGE_TYPE_FILE �� */ , int BmpFlag, int ReverseFlag, BASEIMAGE *Image, BITMAPINFO **BmpInfo, void **GraphData ) ;				// �摜�t�@�C���Ⴕ���̓�������ɓW�J���ꂽ�摜�t�@�C���C���[�W��ǂݍ��݁A��{�C���[�W�f�[�^�Ⴕ���͂a�l�o�f�[�^���\�z����
extern	int			CreateGraphImageType2(         STREAMDATA *Src, BASEIMAGE *Dest ) ;																																													// �摜�f�[�^����\�z�����X�g���[���ǂݍ��ݗp�f�[�^���g�p���Ċ�{�C���[�W�f�[�^���\�z����
extern	int			CreateBmpInfo(                 BITMAPINFO *BmpInfo, int Width, int Height, int Pitch, void *SrcGrData, void **DestGrData ) ;																														// 24bit�J���[�`���̃r�b�g�}�b�v�f�[�^����a�l�o�f�[�^���\�z����
extern	DWORD		GetGraphImageFullColorCode(    BASEIMAGE *GraphImage, int x, int y ) ;																																												// ��{�C���[�W�f�[�^�̎w����W�̃t���J���[�R�[�h���擾����
extern	int			CreateGraphImage_plus_Alpha(   const TCHAR *FileName, void *RgbImage, int RgbImageSize, int RgbImageType, void *AlphaImage, int AlphaImageSize, int AlphaImageType, BASEIMAGE *RgbGraphImage, BASEIMAGE *AlphaGraphImage, int ReverseFlag ) ;		// �摜�t�@�C���Ⴕ���̓�������ɓW�J���ꂽ�摜�t�@�C���C���[�W��ǂݍ��݁A��{�C���[�W�f�[�^���\�z����
extern	int			ReverseGraphImage(             BASEIMAGE *GraphImage ) ;																																															// ��{�C���[�W�f�[�^�����E���]����
#ifdef __WINDOWS__
extern	HBITMAP		CreateDIBGraph(                const TCHAR *FileName,                                                                                                                            int ReverseFlag,          COLORDATA *SrcColor) ;					// �摜�t�@�C������c�h�a�f�[�^���쐬����
extern	HBITMAP		CreateDIBGraphToMem(           BITMAPINFO *BmpInfo, void *GraphData,                                                                                                             int ReverseFlag,          COLORDATA *SrcColor ) ;					// �a�l�o�f�[�^����c�h�a�f�[�^�N���쐬����
extern	int			CreateDIBGraph_plus_Alpha(     const TCHAR *FileName, HBITMAP *RGBBmp, HBITMAP *AlphaBmp,                                                                                        int ReverseFlag = FALSE , COLORDATA *SrcColor = NULL ) ;			// �摜�t�@�C������c�h�a�f�[�^�ƃ}�X�N�p�c�h�a�f�[�^���쐬����
extern	HBITMAP		CreateDIBGraphVer2(            const TCHAR *FileName, void *MemImage, int MemImageSize,                                       int ImageType,                                     int ReverseFlag,          COLORDATA *SrcColor ) ;					// �摜�t�@�C���Ⴕ���̓�������ɓW�J���ꂽ�摜�t�@�C���C���[�W����c�h�a�f�[�^���쐬����
extern	int			CreateDIBGraphVer2_plus_Alpha( const TCHAR *FileName, void *MemImage, int MemImageSize, void *AlphaImage, int AlphaImageSize, int ImageType, HBITMAP *RGBBmp, HBITMAP *AlphaBmp, int ReverseFlag,          COLORDATA *SrcColor ) ;					// �摜�t�@�C���Ⴕ���̓�������ɓW�J���ꂽ�摜�t�@�C���C���[�W����c�h�a�f�[�^�ƃ}�X�N�p�c�h�a�f�[�^���쐬����
extern	int			ConvBitmapToGraphImage(        BITMAPINFO *BmpInfo, void *GraphData, BASEIMAGE *GraphImage, int CopyFlag ) ;																																		// �a�l�o�f�[�^�����{�C���[�W�f�[�^���\�z����( Ret 0:����I��  1:�R�s�[���s����  -1:�G���[ )
extern	int			ConvGraphImageToBitmap(        BASEIMAGE *GraphImage, BITMAPINFO *BmpInfo, void **GraphData, int CopyFlag, int FullColorConv = TRUE ) ;																												// ��{�C���[�W�f�[�^���a�l�o�f�[�^�ɕϊ�����GraphImage �� �a�l�o �ɕϊ�����(�A���t�@�f�[�^�͂����Ă����������)( �߂�l�@0:����I��  1:�R�s�[���s����  -1:�G���[ )
#endif // __WINDOWS__

//extern int		AddUserGraphLoadFunction( int ( *UserLoadFunc )( FILE *fp, BITMAPINFO **BmpInfo, void **GraphData ) ) ;																					// ���[�U�[��`�̉摜�f�[�^�ǂݍ��݊֐���o�^����
//extern int		AddUserGraphLoadFunction2( int ( *UserLoadFunc )( void *Image, int ImageSize, int ImageType, BITMAPINFO **BmpInfo, void **GraphData ) ) ;												// ���[�U�[��`�̉摜�f�[�^�ǂݍ��݊֐���o�^����
//extern int		AddUserGraphLoadFunction3( int ( *UserLoadFunc )( void *DataImage, int DataImageSize, int DataImageType, int BmpFlag, BASEIMAGE *Image, BITMAPINFO **BmpInfo, void **GraphData ) ) ;	// ���[�U�[��`�̉摜�f�[�^�ǂݍ��݊֐�Ver3��o�^����
extern	int			AddUserGraphLoadFunction4( int (* UserLoadFunc )( STREAMDATA *Src, BASEIMAGE *Image ) ) ; 																								// ���[�U�[��`�̉摜�f�[�^�ǂݍ��݊֐�Ver4��o�^����
//extern int		SubUserGraphLoadFunction( int ( *UserLoadFunc )( FILE *fp, BITMAPINFO **BmpInfo, void **GraphData ) ) ;																					// ���[�U�[��`�̉摜�f�[�^�ǂݍ��݊֐���o�^���疕������
//extern int		SubUserGraphLoadFunction2( int ( *UserLoadFunc )( void *Image, int ImageSize, int ImageType, BITMAPINFO **BmpInfo, void **GraphData ) ) ;												// ���[�U�[��`�̉摜�f�[�^�ǂݍ��݊֐���o�^���疕������
//extern int		SubUserGraphLoadFunction3( int ( *UserLoadFunc )( void *DataImage, int DataImageSize, int DataImageType, int BmpFlag, BASEIMAGE *Image, BITMAPINFO **BmpInfo, void **GraphData ) ) ;	// ���[�U�[��`�̉摜�f�[�^�ǂݍ��݊֐�Ver3��o�^���疕������
extern	int			SubUserGraphLoadFunction4( int (* UserLoadFunc )( STREAMDATA *Src, BASEIMAGE *Image ) ) ; 																								// ���[�U�[��`�̉摜�f�[�^�ǂݍ��݊֐�Ver4��o�^���疕������

extern	int			SetUseFastLoadFlag(            int Flag ) ;														// �����ǂݍ��݃��[�`�����g�p���邩�ǂ�����ݒ肷��( TRUE:�g�p����( �f�t�H���g )  FALSE:�g�p���Ȃ� )
extern	int			SetGraphDataShavedMode(        int ShavedMode /* DX_SHAVEDMODE_NONE �� */ ) ;					// �摜���F���̉摜�򉻊ɘa�������[�h��ݒ肷��( �f�t�H���g�ł͊ɘa���������� DX_SHAVEDMODE_NONE )
extern	int			GetGraphDataShavedMode(        void ) ;															// �摜���F���̉摜�򉻊ɘa�������[�h���擾����

// ��{�C���[�W�f�[�^�\���̊֌W
extern	int			CreateBaseImage(               const TCHAR *FileName, void *FileImage, int FileImageSize, int DataType /*=LOADIMAGE_TYPE_FILE*/ , BASEIMAGE *BaseImage,  int ReverseFlag ) ;			// �摜�t�@�C���Ⴕ���̓�������ɓW�J���ꂽ�摜�t�@�C���C���[�W�����{�C���[�W�f�[�^���\�z����
extern	int			CreateGraphImage(              const TCHAR *FileName, void *DataImage, int DataImageSize, int DataImageType,                      BASEIMAGE *GraphImage, int ReverseFlag ) ;			// CreateBaseImage �̋�����
extern	int			CreateBaseImageToFile(         const TCHAR *FileName,                                                                             BASEIMAGE *BaseImage,  int ReverseFlag = FALSE ) ;	// �摜�t�@�C�������{�C���[�W�f�[�^���\�z����
extern	int			CreateBaseImageToMem(                                 void *FileImage, int FileImageSize,                                         BASEIMAGE *BaseImage,  int ReverseFlag = FALSE ) ;	// ��������ɓW�J���ꂽ�摜�t�@�C���C���[�W�����{�C���[�W�f�[�^���\�z����
extern	int			CreateARGB8ColorBaseImage(     int SizeX, int SizeY,                       BASEIMAGE *BaseImage ) ;																						// �`�q�f�a�W�J���[�̊�{�C���[�W�f�[�^���쐬����
extern	int			CreateXRGB8ColorBaseImage(     int SizeX, int SizeY,                       BASEIMAGE *BaseImage ) ;																						// �w�q�f�a�W�J���[�̊�{�C���[�W�f�[�^���쐬����
extern	int			CreateRGB8ColorBaseImage(      int SizeX, int SizeY,                       BASEIMAGE *BaseImage ) ;																						// �q�f�a�W�J���[�̊�{�C���[�W�f�[�^���쐬����
extern	int			CreateARGB4ColorBaseImage(     int SizeX, int SizeY,                       BASEIMAGE *BaseImage ) ;																						// �`�q�f�a�S�J���[�̊�{�C���[�W�f�[�^���쐬����
extern	int			CreatePAL8ColorBaseImage(      int SizeX, int SizeY,                       BASEIMAGE *BaseImage ) ;																						// �p���b�g�W�r�b�g�J���[�̊�{�C���[�W�f�[�^���쐬����
extern	int			CreateColorDataBaseImage(      int SizeX, int SizeY, COLORDATA *ColorData, BASEIMAGE *BaseImage ) ;																						// �w��̃J���[�t�H�[�}�b�g�̊�{�C���[�W�f�[�^���쐬����
extern	int			GetBaseImageGraphDataSize(     BASEIMAGE *BaseImage ) ;																																	// ��{�C���[�W�f�[�^�̃C���[�W�T�C�Y���擾����( �P�ʁFbyte )

extern	int			ReleaseBaseImage(              BASEIMAGE *BaseImage ) ;																																	// ��{�C���[�W�f�[�^�̌�n�����s��
extern	int			ReleaseGraphImage(             BASEIMAGE *GraphImage ) ;																																// ReleaseBaseImage �̋�����

extern	int			ConvertNormalFormatBaseImage(  BASEIMAGE *BaseImage ) ;																																	// DX_BASEIMAGE_FORMAT_NORMAL �ȊO�̌`���̃C���[�W�� DX_BASEIMAGE_FORMAT_NORMAL �`���̃C���[�W�ɕϊ�����

extern	int			GetDrawScreenBaseImage(        int x1, int y1, int x2, int y2, BASEIMAGE *BaseImage ) ;																									// �`��Ώۂ̉�ʂ���w��̈����{�C���[�W�f�[�^�ɓ]������
#ifdef __WINDOWS__
extern	int			UpdateLayerdWindowForBaseImage(                   BASEIMAGE *BaseImage ) ;																												// ��{�C���[�W�f�[�^���g�p���� UpdateLayerdWindow ���s��
extern	int			UpdateLayerdWindowForPremultipliedAlphaBaseImage( BASEIMAGE *BaseImage ) ;																												// ��Z�ς݃A���t�@�̊�{�C���[�W�f�[�^���g�p���� UpdateLayerdWindow ���s��
#endif // __WINDOWS__
extern	int			FillBaseImage(                 BASEIMAGE *BaseImage, int r, int g, int b, int a ) ;																										// ��{�C���[�W�f�[�^���w��̐F�œh��Ԃ�
extern	int			ClearRectBaseImage(            BASEIMAGE *BaseImage, int x, int y, int w, int h ) ;																										// ��{�C���[�W�f�[�^�̎w��̗̈���O�N���A����
extern	int			GetPaletteBaseImage(           BASEIMAGE *BaseImage, int PaletteNo, int *r, int *g, int *b, int *a ) ;																					// ��{�C���[�W�f�[�^�̃p���b�g���擾����
extern	int			SetPaletteBaseImage(           BASEIMAGE *BaseImage, int PaletteNo, int  r, int  g, int  b, int  a ) ;																					// ��{�C���[�W�f�[�^�̃p���b�g���Z�b�g����
extern	int			SetPixelPalCodeBaseImage(      BASEIMAGE *BaseImage, int x, int y, int palNo ) ;																										// ��{�C���[�W�f�[�^�̎w��̍��W�̐F�R�[�h��ύX����(�p���b�g�摜�p)
extern	int			GetPixelPalCodeBaseImage(      BASEIMAGE *BaseImage, int x, int y ) ;																													// ��{�C���[�W�f�[�^�̎w��̍��W�̐F�R�[�h���擾����(�p���b�g�摜�p)
extern	int			SetPixelBaseImage(             BASEIMAGE *BaseImage, int x, int y, int  r, int  g, int  b, int  a ) ;																					// ��{�C���[�W�f�[�^�̎w��̍��W�̐F��ύX����(�e�F�v�f�͂O�`�Q�T�T)
extern	int			GetPixelBaseImage(             BASEIMAGE *BaseImage, int x, int y, int *r, int *g, int *b, int *a ) ;																					// ��{�C���[�W�f�[�^�̎w��̍��W�̐F���擾����(�e�F�v�f�͂O�`�Q�T�T)
extern	int			DrawLineBaseImage(             BASEIMAGE *BaseImage, int x1, int y1, int x2, int y2, int r, int g, int b, int a ) ;																		// ��{�C���[�W�f�[�^�̎w��̍��W�ɐ���`�悷��(�e�F�v�f�͂O�`�Q�T�T)
extern	int			BltBaseImage(                  int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int DestX, int DestY, BASEIMAGE *SrcBaseImage, BASEIMAGE *DestBaseImage ) ;								// ��{�C���[�W�f�[�^��ʂ̊�{�C���[�W�f�[�^�ɓ]������
extern	int			BltBaseImage(                                                                  int DestX, int DestY, BASEIMAGE *SrcBaseImage, BASEIMAGE *DestBaseImage ) ;								// ��{�C���[�W�f�[�^��ʂ̊�{�C���[�W�f�[�^�ɓ]������
extern	int			BltBaseImageWithTransColor(    int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int DestX, int DestY, BASEIMAGE *SrcBaseImage, BASEIMAGE *DestBaseImage, int Tr, int Tg, int Tb, int Ta ) ;	// ��{�C���[�W�f�[�^��ʂ̊�{�C���[�W�f�[�^�ɓ��ߐF�����t���œ]������
extern	int			BltBaseImageWithAlphaBlend(    int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int DestX, int DestY, BASEIMAGE *SrcBaseImage, BASEIMAGE *DestBaseImage, int Opacity = 255 ) ;			// ��{�C���[�W�f�[�^��ʂ̊�{�C���[�W�f�[�^�ɃA���t�@�l�̃u�����h���l��������œ]������( Opacity �͓����x : 0( ���S���� ) �` 255( ���S�s���� ) )( �o�͐悪 ARGB8 �`���ȊO�̏ꍇ�̓G���[�ɂȂ�܂� )
extern	int			ReverseBaseImageH(             BASEIMAGE *BaseImage ) ;																																	// ��{�C���[�W�f�[�^�����E���]����
extern	int			ReverseBaseImageV(             BASEIMAGE *BaseImage ) ;																																	// ��{�C���[�W�f�[�^���㉺���]����
extern	int			ReverseBaseImage(              BASEIMAGE *BaseImage ) ;																																	// ��{�C���[�W�f�[�^���㉺���E���]����
extern	int			CheckPixelAlphaBaseImage(      BASEIMAGE *BaseImage ) ;																																	// ��{�C���[�W�f�[�^�Ɋ܂܂��s�N�Z���̃A���t�@�l���`�F�b�N����( �߂�l   -1:�G���[  0:�摜�ɃA���t�@����������  1:�摜�ɃA���t�@����������A���ׂčő�(255)�l  2:�摜�ɃA���t�@����������A���݂���A���t�@�l�͍ŏ�(0)�ƍő�(255)�������͍ŏ�(0)�̂݁@3:�摜�ɃA���t�@����������A�ŏ��ƍő�ȊO�̒��Ԃ̒l������ )  

#ifndef DX_NON_SAVEFUNCTION

extern	int			SaveBaseImageToBmp(            const TCHAR *FilePath, BASEIMAGE *BaseImage ) ;																											// ��{�C���[�W�f�[�^���a�l�o�摜�Ƃ��ĕۑ�����
#ifndef DX_NON_PNGREAD
extern	int			SaveBaseImageToPng(            const TCHAR *FilePath, BASEIMAGE *BaseImage, int CompressionLevel ) ;																					// ��{�C���[�W�f�[�^���o�m�f�摜�Ƃ��ĕۑ�����
#endif // DX_NON_PNGREAD
#ifndef DX_NON_JPEGREAD
extern	int			SaveBaseImageToJpeg(           const TCHAR *FilePath, BASEIMAGE *BaseImage, int Quality, int Sample2x1 ) ;																				// ��{�C���[�W�f�[�^���i�o�d�f�摜�Ƃ��ĕۑ�����
#endif // DX_NON_JPEGREAD

#endif // DX_NON_SAVEFUNCTION

// ��{�C���[�W�`��
extern	int			DrawBaseImage(					int x, int y, BASEIMAGE *BaseImage ) ;																													// ��{�C���[�W�f�[�^��`�悷��

// �J���[�}�b�`���O���Ȃ���C���[�W�f�[�^�ԓ]�����s�� Ver2
extern int			GraphColorMatchBltVer2( void *DestGraphData, int DestPitch,  COLORDATA *DestColorData,
											void *SrcGraphData,  int SrcPitch,   COLORDATA *SrcColorData,
											void *AlphaMask,     int AlphaPitch, COLORDATA *AlphaColorData,
											POINT DestPoint, RECT *SrcRect, int ReverseFlag,
											int TransColorAlphaTestFlag, unsigned int TransColor,
											int ImageShavedMode, int AlphaOnlyFlag = FALSE ,
											int RedIsAlphaFlag = FALSE , int TransColorNoMoveFlag = FALSE ,
											int Pal8ColorMatch = FALSE ) ;


// �F���擾�֌W
extern	COLOR_F		GetColorF(              float Red, float Green, float Blue, float Alpha ) ;										// ���������_�^�̃J���[�l���쐬����
extern	COLOR_U8	GetColorU8(             int Red, int Green, int Blue, int Alpha ) ;												// �����Ȃ������W�r�b�g�̃J���[�l���쐬����
extern	DWORD		GetColor(               int Red, int Green, int Blue ) ;														// �R���F�̒l���猻�݂̉�ʃ��[�h�ɑΉ������J���[�l�𓾂�
extern	int			GetColor2(              int Color, int *Red, int *Green, int *Blue ) ;											// ��ʃ��[�h�ɑΉ������J���[�l����X�̂R���F�̒l�𔲂��o��
extern	int			GetColor3(              COLORDATA *ColorData, int Red, int Green, int Blue, int Alpha = 255 ) ;					// �R���F�̒l����w��̃s�N�Z���t�H�[�}�b�g�ɑΉ������J���[�l�𓾂�
extern	int			GetColor4(              COLORDATA *DestColorData, COLORDATA* SrcColorData, int SrcColor ) ;						// �w��̃J���[�t�H�[�}�b�g�̃J���[�l��ʂ̃J���[�t�H�[�}�b�g�̃J���[�l�ɕϊ�����
extern	int			GetColor5(              COLORDATA *ColorData, int Color, int *Red, int *Green, int *Blue, int *Alpha = NULL ) ;	// �w��̃J���[�t�H�[�}�b�g�̃J���[�l���R���F�̒l�ɕϊ�����
extern	int			CreatePaletteColorData( COLORDATA *ColorDataBuf ) ;																// �p���b�g�J���[�̃J���[�t�H�[�}�b�g���\�z����
extern	int			CreateXRGB8ColorData(   COLORDATA *ColorDataBuf ) ;																// �w�q�f�a�W�J���[�̃J���[�t�H�[�}�b�g���\�z����
extern	int			CreateARGB8ColorData(   COLORDATA *ColorDataBuf ) ;																// �`�q�f�a�W�J���[�̃J���[�t�H�[�}�b�g���\�z����
extern	int			CreateARGB4ColorData(   COLORDATA *ColorDataBuf ) ;																// �`�q�f�a�S�J���[�̃J���[�t�H�[�}�b�g���\�z����
extern	int			CreateFullColorData(    COLORDATA *ColorDataBuf ) ;																// �Q�S�r�b�g�J���[�̃J���[�t�H�[�}�b�g���\�z����
extern	int			CreateGrayColorData(    COLORDATA *ColorDataBuf ) ;																// �O���[�X�P�[���̃J���[�t�H�[�}�b�g���\�z����
extern	int			CreatePal8ColorData(    COLORDATA *ColorDataBuf ) ;																// �p���b�g�Q�T�U�F�̃J���[�t�H�[�}�b�g���\�z����
extern	int			CreateColorData(        COLORDATA *ColorDataBuf, int ColorBitDepth,
									        DWORD RedMask, DWORD GreenMask, DWORD BlueMask, DWORD AlphaMask,
									        int ChannelNum = 0, int ChannelBitDepth = 0, int FloatTypeFlag = FALSE ) ;				// �J���[�t�H�[�}�b�g���쐬����
extern	void		SetColorDataNoneMask(   COLORDATA *ColorData ) ;																// NoneMask �ȊO�̗v�f�𖄂߂� COLORDATA �\���̂̏������� NoneMask ���Z�b�g����
extern	int			CmpColorData(           COLORDATA *ColorData1, COLORDATA *ColorData2 ) ;										// ��̃J���[�t�H�[�}�b�g�����������ǂ������ׂ�( �߂�l�@TRUE:������  FALSE:�������Ȃ� )

#endif // DX_NOTUSE_DRAWFUNCTION













// DxSoftImage.cpp�֐��v���g�^�C�v�錾
#ifndef DX_NON_SOFTIMAGE
extern	int			InitSoftImage(                   void ) ;																			// �\�t�g�E�G�A�C���[�W�n���h����S�č폜����
extern	int			LoadSoftImage(                   const TCHAR *FileName ) ;															// �摜�t�@�C����ǂݍ��݃\�t�g�E�G�A�C���[�W�n���h�����쐬����( -1:�G���[  -1�ȊO:�C���[�W�n���h�� )
extern	int			LoadSoftImageToMem(              void *FileImage, int FileImageSize ) ;												// ��������ɓW�J���ꂽ�摜�t�@�C���C���[�W����\�t�g�E�G�A�C���[�W�n���h�����쐬����( -1:�G���[  -1�ȊO:�C���[�W�n���h�� )
extern	int			MakeSoftImage(                   int SizeX, int SizeY ) ;															// �\�t�g�E�G�A�C���[�W�n���h���̍쐬( -1:�G���[  -1�ȊO:�C���[�W�n���h�� )
extern	int			MakeARGB8ColorSoftImage(         int SizeX, int SizeY ) ;															// �\�t�g�E�G�A�C���[�W�n���h���̍쐬( RGBA8 �J���[ )
extern	int			MakeXRGB8ColorSoftImage(         int SizeX, int SizeY ) ;															// �\�t�g�E�G�A�C���[�W�n���h���̍쐬( XRGB8 �J���[ )
extern	int			MakeARGB4ColorSoftImage(         int SizeX, int SizeY ) ;															// �\�t�g�E�G�A�C���[�W�n���h���̍쐬( ARGB4 �J���[ )
extern	int			MakeRGB8ColorSoftImage(          int SizeX, int SizeY ) ;															// �\�t�g�E�G�A�C���[�W�n���h���̍쐬( RGB8 �J���[ )
extern	int			MakePAL8ColorSoftImage(          int SizeX, int SizeY ) ;															// �\�t�g�E�G�A�C���[�W�n���h���̍쐬( �p���b�g�Q�T�U�F �J���[ )

extern	int			DeleteSoftImage(                 int SIHandle ) ;																	// �\�t�g�E�G�A�C���[�W�n���h���̍폜����

extern	int			GetSoftImageSize(                int SIHandle, int *Width, int *Height ) ;											// �\�t�g�E�G�A�C���[�W�n���h���̃T�C�Y���擾����
extern	int			CheckPaletteSoftImage(           int SIHandle ) ;																	// �\�t�g�E�G�A�C���[�W�n���h�����p���b�g�摜���ǂ������擾����( TRUE:�p���b�g�摜  FALSE:�p���b�g�摜����Ȃ� )
extern	int			CheckAlphaSoftImage(             int SIHandle ) ;																	// �\�t�g�E�G�A�C���[�W�n���h���̃t�H�[�}�b�g�Ƀ��v�f�����邩�ǂ������擾����( TRUE:����  FALSE:�Ȃ� )
extern	int			CheckPixelAlphaSoftImage(        int SIHandle ) ;																	// �\�t�g�E�G�A�C���[�W�n���h���Ɋ܂܂��s�N�Z���̃��l���`�F�b�N����( �߂�l   -1:�G���[  0:�摜�Ƀ�����������  1:�摜�Ƀ�����������A���ׂčő�(255)�l  2:�摜�Ƀ�����������A���݂��郿�l�͍ŏ�(0)�ƍő�(255)�������͍ŏ�(0)�̂݁@3:�摜�Ƀ�����������A�ŏ��ƍő�ȊO�̒��Ԃ̒l������ )  

extern	int			GetDrawScreenSoftImage(          int x1, int y1, int x2, int y2, int SIHandle ) ;									// �`��Ώۂ̉�ʂ���w��̈���\�t�g�E�G�A�C���[�W�n���h���ɓ]������
#ifdef __WINDOWS__
extern	int			UpdateLayerdWindowForSoftImage(                   int SIHandle ) ;													// �\�t�g�E�G�A�C���[�W�n���h�����g�p���� UpdateLayerdWindow ���s��( �C���[�W�̓E�C���h�E�̃N���C�A���g�̈�Ɠ����T�C�Y�ł���K�v������܂� )
extern	int			UpdateLayerdWindowForPremultipliedAlphaSoftImage( int SIHandle ) ;													// ��Z�ς݃A���t�@�̃\�t�g�E�G�A�C���[�W�n���h�����g�p���� UpdateLayerdWindow ���s��( �C���[�W�̓E�C���h�E�̃N���C�A���g�̈�Ɠ����T�C�Y�ł���K�v������܂� )
#endif // __WINDOWS__
extern	int			FillSoftImage(                   int SIHandle, int r, int g, int b, int a ) ;										// �\�t�g�E�G�A�C���[�W�n���h�����w��F�œh��Ԃ�(�e�F�v�f�͂O�`�Q�T�T)
extern	int			ClearRectSoftImage(              int SIHandle, int x, int y, int w, int h ) ;										// �\�t�g�E�G�A�C���[�W�n���h���̎w��̗̈���O�N���A����
extern	int			GetPaletteSoftImage(             int SIHandle, int PaletteNo, int *r, int *g, int *b, int *a ) ;					// �\�t�g�E�G�A�C���[�W�n���h���̃p���b�g���擾����(�e�F�v�f�͂O�`�Q�T�T)
extern	int			SetPaletteSoftImage(             int SIHandle, int PaletteNo, int  r, int  g, int  b, int  a ) ;					// �\�t�g�E�G�A�C���[�W�n���h���̃p���b�g��ݒ肷��(�e�F�v�f�͂O�`�Q�T�T)
extern	int			DrawPixelPalCodeSoftImage(       int SIHandle, int x, int y, int palNo ) ;											// �\�t�g�E�G�A�C���[�W�n���h���̎w����W�Ƀh�b�g��`�悷��(�p���b�g�摜�p�A�L���l�͂O�`�Q�T�T)
extern	int			GetPixelPalCodeSoftImage(        int SIHandle, int x, int y ) ;														// �\�t�g�E�G�A�C���[�W�n���h���̎w����W�̐F�R�[�h���擾����(�p���b�g�摜�p�A�߂�l�͂O�`�Q�T�T)
extern	void		*GetImageAddressSoftImage(       int SIHandle ) ;																	// �\�t�g�E�G�A�C���[�W�n���h���̉摜���i�[����Ă��郁�����̈�̐擪�A�h���X���擾����
extern	int			DrawPixelSoftImage(              int SIHandle, int x, int y, int  r, int  g, int  b, int  a ) ;						// �\�t�g�E�G�A�C���[�W�n���h���̎w����W�Ƀh�b�g��`�悷��(�e�F�v�f�͂O�`�Q�T�T)
extern	void		DrawPixelSoftImage_Unsafe_XRGB8( int SIHandle, int x, int y, int  r, int  g, int  b ) ;								// �\�t�g�E�G�A�C���[�W�n���h���̎w����W�Ƀh�b�g��`�悷��(�e�F�v�f�͂O�`�Q�T�T)�A�G���[�`�F�b�N�����Ȃ�����ɍ����ł����A�͈͊O�̍��W�� ARGB8 �ȊO�̃t�H�[�}�b�g�̃\�t�g�n���h����n���ƕs���ȃ������A�N�Z�X�ŋ����I�����܂�
extern	void		DrawPixelSoftImage_Unsafe_ARGB8( int SIHandle, int x, int y, int  r, int  g, int  b, int  a ) ;						// �\�t�g�E�G�A�C���[�W�n���h���̎w����W�Ƀh�b�g��`�悷��(�e�F�v�f�͂O�`�Q�T�T)�A�G���[�`�F�b�N�����Ȃ�����ɍ����ł����A�͈͊O�̍��W�� XRGB8 �ȊO�̃t�H�[�}�b�g�̃\�t�g�n���h����n���ƕs���ȃ������A�N�Z�X�ŋ����I�����܂�
extern	int			GetPixelSoftImage(               int SIHandle, int x, int y, int *r, int *g, int *b, int *a ) ;						// �\�t�g�E�G�A�C���[�W�n���h���̎w����W�̐F���擾����(�e�F�v�f�͂O�`�Q�T�T)
extern	void		GetPixelSoftImage_Unsafe_XRGB8(  int SIHandle, int x, int y, int *r, int *g, int *b ) ;								// �\�t�g�E�G�A�C���[�W�n���h���̎w����W�̐F���擾����(�e�F�v�f�͂O�`�Q�T�T)�A�G���[�`�F�b�N�����Ȃ�����ɍ����ł����A�͈͊O�̍��W�� XRGB8 �ȊO�̃t�H�[�}�b�g�̃\�t�g�n���h����n���ƕs���ȃ������A�N�Z�X�ŋ����I�����܂�
extern	void		GetPixelSoftImage_Unsafe_ARGB8(  int SIHandle, int x, int y, int *r, int *g, int *b, int *a ) ;						// �\�t�g�E�G�A�C���[�W�n���h���̎w����W�̐F���擾����(�e�F�v�f�͂O�`�Q�T�T)�A�G���[�`�F�b�N�����Ȃ�����ɍ����ł����A�͈͊O�̍��W�� ARGB8 �ȊO�̃t�H�[�}�b�g�̃\�t�g�n���h����n���ƕs���ȃ������A�N�Z�X�ŋ����I�����܂�
extern	int			DrawLineSoftImage(               int SIHandle, int x1, int y1, int x2, int y2, int r, int g, int b, int a ) ;		// �\�t�g�E�G�A�C���[�W�n���h���̎w����W�ɐ���`�悷��(�e�F�v�f�͂O�`�Q�T�T)
extern	int			BltSoftImage(                    int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int SrcSIHandle, int DestX, int DestY, int DestSIHandle ) ;									// �\�t�g�E�G�A�C���[�W�n���h����ʂ̃\�t�g�E�G�A�C���[�W�n���h���ɓ]������
extern	int			BltSoftImageWithTransColor(      int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int SrcSIHandle, int DestX, int DestY, int DestSIHandle, int Tr, int Tg, int Tb, int Ta ) ;	// �\�t�g�E�G�A�C���[�W�n���h����ʂ̃\�t�g�E�G�A�C���[�W�n���h���ɓ��ߐF�����t���œ]������
extern	int			BltSoftImageWithAlphaBlend(      int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int SrcSIHandle, int DestX, int DestY, int DestSIHandle, int Opacity = 255 ) ;					// �\�t�g�E�G�A�C���[�W�n���h����ʂ̃\�t�g�E�G�A�C���[�W�n���h���ɃA���t�@�l�̃u�����h���l��������œ]������( Opacity �͓����x : 0( ���S���� ) �` 255( ���S�s���� ) )( �o�͐悪 ARGB8 �`���ȊO�̏ꍇ�̓G���[�ɂȂ�܂� )
extern	int			ReverseSoftImageH(               int SIHandle ) ;																	// �\�t�g�E�G�A�C���[�W�n���h�������E���]����
extern	int			ReverseSoftImageV(               int SIHandle ) ;																	// �\�t�g�E�G�A�C���[�W�n���h�����㉺���]����
extern	int			ReverseSoftImage(                int SIHandle ) ;																	// �\�t�g�E�G�A�C���[�W�n���h�����㉺���E���]����

#ifndef DX_NON_FONT
extern	int			BltStringSoftImage(              int x, int y, const TCHAR *StrData, int DestSIHandle, int DestEdgeSIHandle = -1 ,                                        int VerticalFlag = FALSE ) ;		// �\�t�g�E�G�A�C���[�W�n���h���ɕ������`�悷��( �f�t�H���g�t�H���g�n���h�����g�p���� )
extern	int			BltStringSoftImageToHandle(      int x, int y, const TCHAR *StrData, int DestSIHandle, int DestEdgeSIHandle /* �����K�v�Ȃ��ꍇ�� -1 */ , int FontHandle, int VerticalFlag = FALSE ) ;		// �\�t�g�E�G�A�C���[�W�n���h���ɕ������`�悷��( �t�H���g�n���h���g�p�� )
#endif // DX_NON_FONT

extern	int			DrawSoftImage(                   int x, int y, int SIHandle ) ;														// �\�t�g�E�G�A�C���[�W�n���h������ʂɕ`�悷��

#ifndef DX_NON_SAVEFUNCTION

extern	int			SaveSoftImageToBmp(              const TCHAR *FilePath, int SIHandle ) ;											// �\�t�g�E�G�A�C���[�W�n���h�����a�l�o�摜�t�@�C���Ƃ��ĕۑ�����
#ifndef DX_NON_PNGREAD
extern	int			SaveSoftImageToPng(              const TCHAR *FilePath, int SIHandle, int CompressionLevel ) ;						// �\�t�g�E�G�A�C���[�W�n���h�����o�m�f�摜�t�@�C���Ƃ��ĕۑ����� CompressionLevel = ���k���A�l���傫���قǍ����k�������ׁA�O�͖����k,0�`9
#endif // DX_NON_PNGREAD
#ifndef DX_NON_JPEGREAD
extern	int			SaveSoftImageToJpeg(             const TCHAR *FilePath, int SIHandle, int Quality, int Sample2x1 ) ;				// �\�t�g�E�G�A�C���[�W�n���h�����i�o�d�f�摜�t�@�C���Ƃ��ĕۑ����� Quality = �掿�A�l���傫���قǒሳ�k���掿,0�`100 
#endif // DX_NON_JPEGREAD

#endif // DX_NON_SAVEFUNCTION

#endif // DX_NON_SOFTIMAGE


















#ifndef DX_NON_SOUND

// DxSound.cpp�֐��v���g�^�C�v�錾

// �T�E���h�f�[�^�Ǘ��n�֐�
extern	int			InitSoundMem(                        int LogOutFlag = FALSE ) ;																	// �S�ẴT�E���h�n���h�����폜����

extern	int			AddSoundData(                        int Handle = -1 ) ;																										// �T�E���h�n���h�����쐬����
extern	int			AddStreamSoundMem(                   STREAMDATA *Stream, int LoopNum,  int SoundHandle, int StreamDataType, int *CanStreamCloseFlag, int UnionHandle = -1 ) ;	// �X�g���[���Đ��^�C�v�̃T�E���h�n���h���ɃX�g���[���f�[�^���Đ��Ώۂɒǉ�����
extern	int			AddStreamSoundMemToMem(              void *FileImage, int FileImageSize, int LoopNum,  int SoundHandle, int StreamDataType, int UnionHandle = -1 ) ;			// �X�g���[���Đ��^�C�v�̃T�E���h�n���h���Ƀ�������ɓW�J�����T�E���h�t�@�C���C���[�W���Đ��Ώۂɒǉ�����
extern	int			AddStreamSoundMemToFile(             const TCHAR *WaveFile, int LoopNum,  int SoundHandle, int StreamDataType, int UnionHandle = -1 ) ;							// �X�g���[���Đ��^�C�v�̃T�E���h�n���h���ɃT�E���h�t�@�C�����Đ��Ώۂɒǉ�����
extern	int			SetupStreamSoundMem(                 int SoundHandle ) ;																		// �X�g���[���Đ��^�C�v�̃T�E���h�n���h���̍Đ�����������
extern	int			PlayStreamSoundMem(                  int SoundHandle, int PlayType = DX_PLAYTYPE_LOOP , int TopPositionFlag = TRUE ) ;			// �X�g���[���Đ��^�C�v�̃T�E���h�n���h���̍Đ����J�n����
extern	int			CheckStreamSoundMem(                 int SoundHandle ) ;																		// �X�g���[���Đ��^�C�v�̃T�E���h�n���h���̍Đ���Ԃ��擾����
extern	int			StopStreamSoundMem(                  int SoundHandle ) ;																		// �X�g���[���Đ��^�C�v�̃T�E���h�n���h���̍Đ����~����
extern	int			SetStreamSoundCurrentPosition(       int Byte, int SoundHandle ) ;																// �T�E���h�n���h���̍Đ��ʒu���o�C�g�P�ʂŕύX����(�Đ����~�܂��Ă��鎞�̂ݗL��)
extern	int			GetStreamSoundCurrentPosition(       int SoundHandle ) ;																		// �T�E���h�n���h���̍Đ��ʒu���o�C�g�P�ʂŎ擾����
extern	int			SetStreamSoundCurrentTime(           int Time, int SoundHandle ) ;																// �T�E���h�n���h���̍Đ��ʒu���~���b�P�ʂŐݒ肷��(���k�`���̏ꍇ�͐������ݒ肳��Ȃ��ꍇ������)
extern	int			GetStreamSoundCurrentTime(           int SoundHandle ) ;																		// �T�E���h�n���h���̍Đ��ʒu���~���b�P�ʂŎ擾����(���k�`���̏ꍇ�͐������l���Ԃ��Ă��Ȃ��ꍇ������)
extern	int			ProcessStreamSoundMem(               int SoundHandle ) ;																		// �X�g���[���Đ��^�C�v�̃T�E���h�n���h���̎����I�ȏ������s���֐�( �����Ŏ����I�ɌĂ΂�܂� )
extern	int			ProcessStreamSoundMemAll(            void ) ;																					// �L���ȃX�g���[���Đ��^�C�v�̃T�E���h�n���h���ɑ΂��� ProcessStreamSoundMem �����s����( �����Ŏ����I�ɌĂ΂�܂� )


extern	int			LoadSoundMem2(                       const TCHAR *FileName1, const TCHAR *FileName2 ) ;											// �O�t���ƃ��[�v���ɕ����ꂽ�T�E���h�t�@�C����ǂݍ��݃T�E���h�n���h�����쐬����
extern	int			LoadBGM(                             const TCHAR *FileName ) ;																	// ��ɂa�f�l��ǂݍ��݃T�E���h�n���h�����쐬����̂ɓK�����֐�

extern	int			LoadSoundMemBase(                    const TCHAR *FileName, int BufferNum,      int UnionHandle = -1 ) ;						// �T�E���h�t�@�C������T�E���h�n���h�����쐬����
extern	int			LoadSoundMem(                        const TCHAR *FileName, int BufferNum = 3 , int UnionHandle = -1 ) ;						// LoadSoundMemBase �̕ʖ��֐�
extern	int			LoadSoundMemToBufNumSitei(           const TCHAR *FileName, int BufferNum ) ;													// LoadSoundMem ���g�p���ĉ�����
extern	int			LoadSoundMemByResource(              const TCHAR *ResourceName, const TCHAR *ResourceType, int BufferNum = 1 ) ;				// �T�E���h���\�[�X����T�E���h�n���h�����쐬����
extern	int			DuplicateSoundMem(                   int SrcSoundHandle, int BufferNum = 3 ) ;													// �����T�E���h�f�[�^���g�p����T�E���h�n���h�����쐬����( DX_SOUNDDATATYPE_MEMNOPRESS �^�C�v�̃T�E���h�n���h���̂݉\ )

extern	int			LoadSoundMemByMemImageBase(          void *FileImage, int FileImageSize, int BufferNum, int UnionHandle = -1 ) ;				// ��������ɓW�J���ꂽ�T�E���h�t�@�C���C���[�W����T�E���h�n���h�����쐬����
extern	int			LoadSoundMemByMemImage(              void *FileImage, int FileImageSize,                int UnionHandle = -1 ) ;				// ��������ɓW�J���ꂽ�T�E���h�t�@�C���C���[�W����T�E���h�n���h�����쐬����( �o�b�t�@���w�薳�� )
extern	int			LoadSoundMemByMemImage2(             void *WaveImage, int WaveImageSize, WAVEFORMATEX *WaveFormat, int WaveHeaderSize ) ;		// ��������ɓW�J���ꂽ�o�b�l�f�[�^����T�E���h�n���h�����쐬����
extern	int			LoadSoundMemByMemImageToBufNumSitei( void *FileImage, int FileImageSize, int BufferNum ) ;										// LoadSoundMemByMemImageBase ���g�p���ĉ�����
extern	int			LoadSoundMem2ByMemImage(             void *FileImage1, int FileImageSize1, void *FileImage2, int FileImageSize2 ) ;				// �O�t���ƃ��[�v���ɕ����ꂽ��̃�������ɓW�J���ꂽ�T�E���h�t�@�C���C���[�W����T�E���h�n���h�����쐬����
extern	int			LoadSoundMemFromSoftSound(           int SoftSoundHandle, int BufferNum = 3 ) ;													// �\�t�g�E�G�A�T�E���h�n���h�������T�E���h�f�[�^����T�E���h�n���h�����쐬����

extern	int			DeleteSoundMem(                      int SoundHandle, int LogOutFlag = FALSE ) ;												// �T�E���h�n���h�����폜����

extern	int			PlaySoundMem(                        int SoundHandle, int PlayType, int TopPositionFlag = TRUE ) ;								// �T�E���h�n���h�����Đ�����
extern	int			StopSoundMem(                                                     int SoundHandle ) ;											// �T�E���h�n���h���̍Đ����~����
extern	int			CheckSoundMem(                                                    int SoundHandle ) ;											// �T�E���h�n���h�����Đ������ǂ������擾����
extern	int			SetPanSoundMem(                      int PanPal,                  int SoundHandle ) ;											// �T�E���h�n���h���̃p����ݒ肷��
extern	int			GetPanSoundMem(                                                   int SoundHandle ) ;											// �T�E���h�n���h���̃p�����擾����
extern	int			SetVolumeSoundMem(                   int VolumePal,               int SoundHandle ) ;											// �T�E���h�n���h���̃{�����[����ݒ肷��( 100����1�f�V�x���P�� )
extern	int			ChangeVolumeSoundMem(                int VolumePal,               int SoundHandle ) ;											// �T�E���h�n���h���̃{�����[����ݒ肷��( �p�[�Z���g�w�� )
extern	int			GetVolumeSoundMem(                                                int SoundHandle ) ;											// �T�E���h�n���h���̃{�����[�����擾����
extern	int			SetFrequencySoundMem(                int FrequencyPal,            int SoundHandle ) ;											// �T�E���h�n���h���̍Đ����g����ݒ肷��
extern	int			GetFrequencySoundMem(                                             int SoundHandle ) ;											// �T�E���h�n���h���̍Đ����g�����擾����
extern	int			ResetFrequencySoundMem(                                           int SoundHandle ) ;											// �T�E���h�n���h���̍Đ����g����ǂݍ��ݒ���̏�Ԃɖ߂�

extern	int			SetNextPlayPanSoundMem(              int PanPal,                  int SoundHandle ) ;											// �T�E���h�n���h���̎��̍Đ��ɂ̂ݎg�p����p����ݒ肷��
extern	int			SetNextPlayVolumeSoundMem(           int VolumePal,               int SoundHandle ) ;											// �T�E���h�n���h���̎��̍Đ��ɂ̂ݎg�p����{�����[����ݒ肷��( 100����1�f�V�x���P�� )
extern	int			ChangeNextPlayVolumeSoundMem(        int VolumePal,               int SoundHandle ) ;											// �T�E���h�n���h���̎��̍Đ��ɂ̂ݎg�p����{�����[����ݒ肷��( �p�[�Z���g�w�� )
extern	int			SetNextPlayFrequencySoundMem(        int FrequencyPal,            int SoundHandle ) ;											// �T�E���h�n���h���̎��̍Đ��ɂ̂ݎg�p����Đ����g����ݒ肷��

extern	int			SetCurrentPositionSoundMem(          int SamplePosition,          int SoundHandle ) ;											// �T�E���h�n���h���̍Đ��ʒu���T���v���P�ʂŐݒ肷��(�Đ����~�܂��Ă��鎞�̂ݗL��)
extern	int			GetCurrentPositionSoundMem(                                       int SoundHandle ) ;											// �T�E���h�n���h���̍Đ��ʒu���T���v���P�ʂŎ擾����
extern	int			SetSoundCurrentPosition(             int Byte,                    int SoundHandle ) ;											// �T�E���h�n���h���̍Đ��ʒu���o�C�g�P�ʂŐݒ肷��(�Đ����~�܂��Ă��鎞�̂ݗL��)
extern	int			GetSoundCurrentPosition(                                          int SoundHandle ) ;											// �T�E���h�n���h���̍Đ��ʒu���o�C�g�P�ʂŎ擾����
extern	int			SetSoundCurrentTime(                 int Time,                    int SoundHandle ) ;											// �T�E���h�n���h���̍Đ��ʒu���~���b�P�ʂŐݒ肷��(���k�`���̏ꍇ�͐������ݒ肳��Ȃ��ꍇ������)
extern	int			GetSoundCurrentTime(                                              int SoundHandle ) ;											// �T�E���h�n���h���̍Đ��ʒu���~���b�P�ʂŎ擾����(���k�`���̏ꍇ�͐������l���Ԃ��Ă��Ȃ��ꍇ������)
extern	int			GetSoundTotalSample(                                              int SoundHandle ) ;											// �T�E���h�n���h���̉��̑����Ԃ��T���v���P�ʂŎ擾����
extern	int			GetSoundTotalTime(                                                int SoundHandle ) ;											// �T�E���h�n���h���̉��̑����Ԃ��~���b�P�ʂŎ擾����

extern	int			SetLoopPosSoundMem(                  int LoopTime,                int SoundHandle ) ;											// SetLoopTimePosSoundMem �̕ʖ��֐�
extern	int			SetLoopTimePosSoundMem(              int LoopTime,                int SoundHandle ) ;											// �T�E���h�n���h���Ƀ��[�v�ʒu��ݒ肷��(�~���b�P��)
extern	int			SetLoopSamplePosSoundMem(            int LoopSamplePosition,      int SoundHandle ) ;											// �T�E���h�n���h���Ƀ��[�v�ʒu��ݒ肷��(�T���v���P��)

extern	int			SetLoopStartTimePosSoundMem(         int LoopStartTime,           int SoundHandle ) ;											// �T�E���h�n���h���Ƀ��[�v�J�n�ʒu��ݒ肷��(�~���b�P��)
extern	int			SetLoopStartSamplePosSoundMem(       int LoopStartSamplePosition, int SoundHandle ) ;											// �T�E���h�n���h���Ƀ��[�v�J�n�ʒu��ݒ肷��(�T���v���P��)

// �ݒ�֌W�֐�
extern	int			SetCreateSoundDataType(              int SoundDataType ) ;																		// �쐬����T�E���h�n���h���̍Đ��^�C�v��ݒ肷��( DX_SOUNDDATATYPE_MEMNOPRESS �� )
extern	int			GetCreateSoundDataType(              void ) ;																					// �쐬����T�E���h�n���h���̍Đ��^�C�v���擾����( DX_SOUNDDATATYPE_MEMNOPRESS �� )
extern	int			SetDisableReadSoundFunctionMask(     int Mask ) ;																				// �g�p���Ȃ��T�E���h�f�[�^�ǂݍ��ݏ����̃}�X�N��ݒ肷��( DX_READSOUNDFUNCTION_PCM �� )
extern	int			GetDisableReadSoundFunctionMask(     void ) ;																					// �g�p���Ȃ��T�E���h�f�[�^�ǂݍ��ݏ����̃}�X�N���擾����( DX_READSOUNDFUNCTION_PCM �� )
extern	int			SetEnableSoundCaptureFlag(           int Flag ) ;																				// �T�E���h�L���v�`����O��Ƃ�����������邩�ǂ�����ݒ肷��
extern	int			SetUseSoftwareMixingSoundFlag(       int Flag ) ;																				// �T�E���h�̏������\�t�g�E�G�A�ōs�����ǂ�����ݒ肷��( TRUE:�\�t�g�E�G�A  FALSE:�n�[�h�E�G�A( �f�t�H���g ) )

// ���擾�n�֐�
extern	void*		GetDSoundObj(                        void ) ;	/* �߂�l�� IDirectSound * �ɃL���X�g���ĉ����� */								// �c�w���C�u�������g�p���Ă��� DirectSound �I�u�W�F�N�g���擾����

#ifndef DX_NON_BEEP
// BEEP���Đ��p����
extern	int			SetBeepFrequency(					int Freq ) ;																				// �r�[�v�����g���ݒ�֐�
extern	int			PlayBeep(							void ) ;																					// �r�[�v�����Đ�����
extern	int			StopBeep(							void ) ;																					// �r�[�v�����~�߂�
#endif // DX_NON_BEEP

// ���b�p�[�֐�
extern	int			PlaySoundFile(						const TCHAR *FileName, int PlayType ) ;														// �T�E���h�t�@�C�����Đ�����
extern	int			PlaySound(							const TCHAR *FileName, int PlayType ) ;														// PlaySoundFile �̋�����
extern	int			CheckSoundFile(						void ) ;																					// �T�E���h�t�@�C���̍Đ������ǂ������擾����
extern	int			CheckSound(							void ) ;																					// CheckSoundFile �̋�����
extern	int			StopSoundFile(						void ) ;																					// �T�E���h�t�@�C���̍Đ����~����
extern	int			StopSound(							void ) ;																					// StopSoundFile �̋�����
extern	int			SetVolumeSoundFile(					int VolumePal ) ;																			// �T�E���h�t�@�C���̉��ʂ�ݒ肷��
extern	int			SetVolumeSound(						int VolumePal ) ;																			// SetVolumeSound �̋�����

// �\�t�g�E�G�A����T�E���h�n�֐�
extern	int			InitSoftSound(						void ) ;																					// �\�t�g�E�G�A�ň����g�`�f�[�^�n���h�������ׂč폜����
extern	int			LoadSoftSound(						const TCHAR *FileName ) ;																	// �\�t�g�E�G�A�ň����g�`�f�[�^�n���h�����T�E���h�t�@�C������쐬����
extern	int			LoadSoftSoundFromMemImage(			const void *FileImage, int FileImageSize ) ;												// �\�t�g�E�G�A�ň����g�`�f�[�^�n���h������������ɓW�J���ꂽ�T�E���h�t�@�C���C���[�W����쐬����
extern	int			MakeSoftSound(						int UseFormat_SoftSoundHandle, int SampleNum ) ;											// �\�t�g�E�G�A�ň�����̔g�`�f�[�^�n���h�����쐬����( �t�H�[�}�b�g�͈����̃\�t�g�E�G�A�T�E���h�n���h���Ɠ������̂ɂ��� )
extern	int			MakeSoftSound2Ch16Bit44KHz(			int SampleNum ) ;																			// �\�t�g�E�G�A�ň�����̔g�`�f�[�^�n���h�����쐬����( �`�����l����:2 �ʎq���r�b�g��:16bit �T���v�����O���g��:44KHz )
extern	int			MakeSoftSound2Ch16Bit22KHz(			int SampleNum ) ;																			// �\�t�g�E�G�A�ň�����̔g�`�f�[�^�n���h�����쐬����( �`�����l����:2 �ʎq���r�b�g��:16bit �T���v�����O���g��:22KHz )
extern	int			MakeSoftSound2Ch8Bit44KHz(			int SampleNum ) ;																			// �\�t�g�E�G�A�ň�����̔g�`�f�[�^�n���h�����쐬����( �`�����l����:2 �ʎq���r�b�g��: 8bit �T���v�����O���g��:44KHz )
extern	int			MakeSoftSound2Ch8Bit22KHz(			int SampleNum ) ;																			// �\�t�g�E�G�A�ň�����̔g�`�f�[�^�n���h�����쐬����( �`�����l����:2 �ʎq���r�b�g��: 8bit �T���v�����O���g��:22KHz )
extern	int			MakeSoftSound1Ch16Bit44KHz(			int SampleNum ) ;																			// �\�t�g�E�G�A�ň�����̔g�`�f�[�^�n���h�����쐬����( �`�����l����:1 �ʎq���r�b�g��:16bit �T���v�����O���g��:44KHz )
extern	int			MakeSoftSound1Ch16Bit22KHz(			int SampleNum ) ;																			// �\�t�g�E�G�A�ň�����̔g�`�f�[�^�n���h�����쐬����( �`�����l����:1 �ʎq���r�b�g��:16bit �T���v�����O���g��:22KHz )
extern	int			MakeSoftSound1Ch8Bit44KHz(			int SampleNum ) ;																			// �\�t�g�E�G�A�ň�����̔g�`�f�[�^�n���h�����쐬����( �`�����l����:1 �ʎq���r�b�g��: 8bit �T���v�����O���g��:44KHz )
extern	int			MakeSoftSound1Ch8Bit22KHz(			int SampleNum ) ;																			// �\�t�g�E�G�A�ň�����̔g�`�f�[�^�n���h�����쐬����( �`�����l����:1 �ʎq���r�b�g��: 8bit �T���v�����O���g��:22KHz )
extern	int			MakeSoftSoundCustom(				int ChannelNum, int BitsPerSample, int SamplesPerSec, int SampleNum );						// �\�t�g�E�G�A�ň�����̔g�`�f�[�^�n���h�����쐬����
extern	int			DeleteSoftSound(					int SoftSoundHandle ) ;																		// �\�t�g�E�G�A�ň����g�`�f�[�^�n���h�����폜����
#ifndef DX_NON_SAVEFUNCTION
extern	int			SaveSoftSound(						int SoftSoundHandle, const TCHAR *FileName ) ;												// �\�t�g�E�G�A�ň����g�`�f�[�^�n���h����WAVE�t�@�C��(PCM)�`���ŕۑ�����
#endif // DX_NON_SAVEFUNCTION
extern	int			GetSoftSoundSampleNum(				int SoftSoundHandle ) ;																		// �\�t�g�E�G�A�ň����g�`�f�[�^�n���h���̃T���v�������擾����
extern	int			GetSoftSoundFormat(					int SoftSoundHandle, int *Channels, int *BitsPerSample, int *SamplesPerSec ) ;				// �\�t�g�E�G�A�ň����g�`�f�[�^�n���h���̃t�H�[�}�b�g���擾����
extern	int			ReadSoftSoundData(					int SoftSoundHandle, int SamplePosition, int *Channel1, int *Channel2 ) ;					// �\�t�g�E�G�A�ň����g�`�f�[�^�n���h���̃T���v����ǂݎ��
extern	int			WriteSoftSoundData(					int SoftSoundHandle, int SamplePosition, int Channel1, int Channel2 ) ;						// �\�t�g�E�G�A�ň����g�`�f�[�^�n���h���̃T���v������������
extern	void		*GetSoftSoundDataImage(				int SoftSoundHandle ) ;																		// �\�t�g�E�G�A�ň����g�`�f�[�^�n���h���̔g�`�C���[�W���i�[����Ă��郁�����A�h���X���擾����

extern	int			InitSoftSoundPlayer(				void ) ;																					// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�n���h�������ׂĉ������
extern	int			MakeSoftSoundPlayer(				int UseFormat_SoftSoundHandle ) ;															// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�n���h�����쐬����( �t�H�[�}�b�g�͈����̃\�t�g�E�G�A�T�E���h�n���h���Ɠ������̂ɂ��� )
extern	int			MakeSoftSoundPlayer2Ch16Bit44KHz(	void ) ;																					// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�n���h�����쐬����( �`�����l����:2 �ʎq���r�b�g��:16bit �T���v�����O���g��:44KHz )
extern	int			MakeSoftSoundPlayer2Ch16Bit22KHz(	void ) ;																					// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�n���h�����쐬����( �`�����l����:2 �ʎq���r�b�g��:16bit �T���v�����O���g��:22KHz )
extern	int			MakeSoftSoundPlayer2Ch8Bit44KHz(	void ) ;																					// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�n���h�����쐬����( �`�����l����:2 �ʎq���r�b�g��: 8bit �T���v�����O���g��:44KHz )
extern	int			MakeSoftSoundPlayer2Ch8Bit22KHz(	void ) ;																					// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�n���h�����쐬����( �`�����l����:2 �ʎq���r�b�g��: 8bit �T���v�����O���g��:22KHz )
extern	int			MakeSoftSoundPlayer1Ch16Bit44KHz(	void ) ;																					// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�n���h�����쐬����( �`�����l����:1 �ʎq���r�b�g��:16bit �T���v�����O���g��:44KHz )
extern	int			MakeSoftSoundPlayer1Ch16Bit22KHz(	void ) ;																					// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�n���h�����쐬����( �`�����l����:1 �ʎq���r�b�g��:16bit �T���v�����O���g��:22KHz )
extern	int			MakeSoftSoundPlayer1Ch8Bit44KHz(	void ) ;																					// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�n���h�����쐬����( �`�����l����:1 �ʎq���r�b�g��: 8bit �T���v�����O���g��:44KHz )
extern	int			MakeSoftSoundPlayer1Ch8Bit22KHz(	void ) ;																					// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�n���h�����쐬����( �`�����l����:1 �ʎq���r�b�g��: 8bit �T���v�����O���g��:22KHz )
extern	int			MakeSoftSoundPlayerCustom(			int ChannelNum, int BitsPerSample, int SamplesPerSec ) ;									// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�n���h�����쐬����
extern	int			DeleteSoftSoundPlayer(				int SSoundPlayerHandle ) ;																	// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�n���h�����폜����
extern	int			AddDataSoftSoundPlayer(				int SSoundPlayerHandle, int SoftSoundHandle, int AddSamplePosition, int AddSampleNum ) ;	// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�n���h���ɔg�`�f�[�^��ǉ�����( �t�H�[�}�b�g�������ł͂Ȃ��ꍇ�̓G���[ )
extern	int			AddDirectDataSoftSoundPlayer(		int SSoundPlayerHandle, void *SoundData, int AddSampleNum ) ;								// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�n���h���Ƀv���C���[���Ή������t�H�[�}�b�g�̐��g�`�f�[�^��ǉ�����
extern	int			AddOneDataSoftSoundPlayer(			int SSoundPlayerHandle, int Channel1, int Channel2 ) ;										// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�n���h���ɔg�`�f�[�^����ǉ�����
extern	int			GetSoftSoundPlayerFormat(			int SSoundPlayerHandle, int *Channels, int *BitsPerSample, int *SamplesPerSec ) ;			// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�n���h���������f�[�^�t�H�[�}�b�g���擾����
extern	int			StartSoftSoundPlayer(				int SSoundPlayerHandle ) ;																	// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�n���h���̍Đ��������J�n����
extern	int			CheckStartSoftSoundPlayer(			int SSoundPlayerHandle ) ;																	// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�n���h���̍Đ��������J�n����Ă��邩�擾����( TRUE:�J�n���Ă���  FALSE:��~���Ă��� )
extern	int			StopSoftSoundPlayer(				int SSoundPlayerHandle ) ;																	// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�n���h���̍Đ��������~����
extern	int			ResetSoftSoundPlayer(				int SSoundPlayerHandle ) ;																	// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�n���h���̏�Ԃ�������Ԃɖ߂�( �ǉ����ꂽ�g�`�f�[�^�͍폜����A�Đ���Ԃ������ꍇ�͒�~���� )
extern	int			GetStockDataLengthSoftSoundPlayer(	int SSoundPlayerHandle ) ;																	// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�n���h���ɒǉ������g�`�f�[�^�ł܂��Đ��p�T�E���h�o�b�t�@�ɓ]������Ă��Ȃ��g�`�f�[�^�̃T���v�������擾����
extern	int			CheckSoftSoundPlayerNoneData(		int SSoundPlayerHandle ) ;																	// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�n���h���ɍĐ��p�T�E���h�o�b�t�@�ɓ]�����Ă��Ȃ��g�`�f�[�^�������A�Đ��p�T�E���h�o�b�t�@�ɂ������f�[�^�ȊO�������ǂ������擾����( TRUE:�����f�[�^�ȊO����  FALSE:�L���f�[�^������ )




// �l�h�c�h����֐�
extern	int			DeleteMusicMem(						int MusicHandle ) ;																			// �l�h�c�h�n���h�����폜����
extern	int			LoadMusicMem(						const TCHAR *FileName ) ;																	// �l�h�c�h�t�@�C����ǂݍ��݂l�h�c�h�n���h�����쐬����
extern	int			LoadMusicMemByMemImage(				void *FileImage, int FileImageSize ) ;														// ��������ɓW�J���ꂽ�l�h�c�h�t�@�C���C���[�W����l�h�c�h�n���h�����쐬����
extern	int			LoadMusicMemByResource(				const TCHAR *ResourceName, const TCHAR *ResourceType ) ;									// ���\�[�X��̂l�h�c�h�t�@�C������l�h�c�h�n���h�����쐬����
extern	int			PlayMusicMem(						int MusicHandle, int PlayType ) ;															// �l�h�c�h�n���h���̉��t���J�n����
extern	int			StopMusicMem(						int MusicHandle ) ;																			// �l�h�c�h�n���h���̉��t���~����
extern	int			CheckMusicMem(						int MusicHandle ) ;																			// �l�h�c�h�n���h�������t�����ǂ������擾����( TRUE:���t��  FALSE:��~�� )
extern	int			SetVolumeMusicMem(					int Volume, int MusicHandle ) ;																// �l�h�c�h�n���h���̍Đ����ʂ��Z�b�g����
extern	int			GetMusicMemPosition(				int MusicHandle ) ;																			// �l�h�c�h�n���h���̌��݂̍Đ��ʒu���擾����
extern	int			InitMusicMem(						void ) ;																					// �l�h�c�h�n���h�������ׂč폜����
extern	int			ProcessMusicMem(					void ) ;																					// �l�h�c�h�n���h���̎����I����( �����ŌĂ΂�܂� )

extern	int			PlayMusic(							const TCHAR *FileName, int PlayType ) ;														// �l�h�c�h�t�@�C�������t����
extern	int			PlayMusicByMemImage(				void *FileImage, int FileImageSize, int PlayType ) ;										// ��������ɓW�J����Ă���l�h�c�h�t�@�C�������t����
extern	int			PlayMusicByResource(				const TCHAR *ResourceName, const TCHAR *ResourceType, int PlayType ) ;						// ���\�[�X����l�h�c�h�t�@�C����ǂݍ���ŉ��t����
extern	int			SetVolumeMusic(						int Volume ) ;																				// �l�h�c�h�̍Đ����ʂ��Z�b�g����
extern	int			StopMusic(							void ) ;																					// �l�h�c�h�t�@�C���̉��t��~
extern	int			CheckMusic(							void ) ;																					// �l�h�c�h�t�@�C�������t�����ۂ������擾����
extern	int			GetMusicPosition(					void ) ;																					// �l�h�c�h�̌��݂̍Đ��ʒu���擾����

extern	int			SelectMidiMode(						int Mode ) ;																				// �l�h�c�h�̍Đ��`����ݒ肷��

#endif // DX_NON_SOUND










// DxArchive_.cpp �֐� �v���g�^�C�v�錾
extern	int			SetUseDXArchiveFlag(	int Flag ) ;													// �c�w�A�[�J�C�u�t�@�C���̓ǂݍ��݋@�\���g�����ǂ�����ݒ肷��( FALSE:�g�p���Ȃ�  TRUE:�g�p���� )
extern	int			SetDXArchivePriority(	int Priority = 0 ) ;											// �����̂c�w�A�[�J�C�u�t�@�C���ƃt�H���_�����݂����ꍇ�A�ǂ����D�悳���邩��ݒ肷��( 1:�t�H���_��D��@ 0:�c�w�A�[�J�C�u�t�@�C����D��( �f�t�H���g ) )
extern	int			SetDXArchiveExtension(	const TCHAR *Extension = NULL ) ;								// ��������c�w�A�[�J�C�u�t�@�C���̊g���q��ݒ肷��( Extension:�g���q�������� )
extern	int			SetDXArchiveKeyString(	const TCHAR *KeyString = NULL ) ;								// �c�w�A�[�J�C�u�t�@�C���̌��������ݒ肷��( KeyString:�������� )

extern	int			DXArchivePreLoad(		const TCHAR *FilePath , int ASync = FALSE ) ;					// �w��̂c�w�`�t�@�C�����ۂ��ƃ������ɓǂݍ���( �߂�l  -1:�G���[  0:���� )
extern	int			DXArchiveCheckIdle(		const TCHAR *FilePath ) ;										// �w��̂c�w�`�t�@�C���̎��O�ǂݍ��݂������������ǂ������擾����( �߂�l  TRUE:�������� FALSE:�܂� )
extern	int			DXArchiveRelease(		const TCHAR *FilePath ) ;										// �w��̂c�w�`�t�@�C��������������������
extern	int			DXArchiveCheckFile(		const TCHAR *FilePath, const TCHAR *TargetFilePath ) ;			// �c�w�`�t�@�C���̒��Ɏw��̃t�@�C�������݂��邩�ǂ����𒲂ׂ�ATargetFilePath �͂c�w�`�t�@�C�����J�����g�t�H���_�Ƃ����ꍇ�̃p�X( �߂�l:  -1=�G���[  0:����  1:���� )





















// DxModel.cpp �֐� �v���g�^�C�v�錾

#ifndef DX_NON_MODEL

// ���f���̓ǂݍ��݁E�����֌W
extern	int			MV1LoadModel(						const TCHAR *FileName ) ;											// ���f���̓ǂݍ���( -1:�G���[  0�ȏ�:���f���n���h�� )
extern	int			MV1LoadModelFromMem(				void *FileImage, int FileSize, int (* FileReadFunc )( const TCHAR *FilePath, void **FileImageAddr, int *FileSize, void *FileReadFuncData ), int (* FileReleaseFunc )( void *MemoryAddr, void *FileReadFuncData ), void *FileReadFuncData = NULL ) ;	// ��������̃��f���t�@�C���C���[�W�ƓƎ��̓ǂݍ��݃��[�`�����g�p���ă��f����ǂݍ���
extern	int			MV1DuplicateModel(					int SrcMHandle ) ;													// �w��̃��f���Ɠ������f����{�f�[�^���g�p���ă��f�����쐬����( -1:�G���[  0�ȏ�:���f���n���h�� )
extern	int			MV1CreateCloneModel(				int SrcMHandle ) ;													// �w��̃��f�������f����{�f�[�^���܂ߕ�������( MV1DuplicateModel �̓��f����{�f�[�^�͋��L���܂����A������͕������̃��f���Ƃ͈�؋��L�f�[�^�̖������f���n���h�����쐬���܂� )( -1:�G���[  0�ȏ�:���f���n���h�� )

extern	int			MV1DeleteModel(						int MHandle ) ;														// ���f�����폜����
extern	int			MV1InitModel(						void ) ;															// ���ׂẴ��f�����폜����

extern	int			MV1SetLoadModelReMakeNormal(		int Flag ) ;														// ���f����ǂݍ��ލۂɖ@���̍Čv�Z���s�����ǂ�����ݒ肷��( TRUE:�s��  FALSE:�s��Ȃ� )
extern	int			MV1SetLoadModelReMakeNormalSmoothingAngle( float SmoothingAngle = 1.562069f ) ;							// ���f����ǂݍ��ލۂɍs���@��̍Čv�Z�Ŏg�p����X���[�W���O�p�x��ݒ肷��( �P�ʂ̓��W�A�� )
extern	int			MV1SetLoadModelPositionOptimize(	int Flag ) ;														// ���f����ǂݍ��ލۂɍ��W�f�[�^�̍œK�����s�����ǂ�����ݒ肷��( TRUE:�s��  FALSE:�s��Ȃ� )
extern	int			MV1SetLoadModelUsePhysicsMode(		int PhysicsMode /* DX_LOADMODEL_PHYSICS_LOADCALC �� */ ) ;			// �ǂݍ��ރ��f���̕������Z���[�h��ݒ肷��
extern	int			MV1SetLoadModelPhysicsWorldGravity( float Gravity ) ;													// �ǂݍ��ރ��f���̕������Z�ɓK�p����d�̓p�����[�^��ݒ肷��
extern	int			MV1SetLoadCalcPhysicsWorldGravity(	int GravityNo, VECTOR Gravity ) ;									// �ǂݍ��ރ��f���̕������Z���[�h�����O�v�Z( DX_LOADMODEL_PHYSICS_LOADCALC )�������ꍇ�ɓK�p�����d�͂̐ݒ������
extern	int			MV1SetLoadModelAnimFilePath(		const TCHAR *FileName ) ;											// �ǂݍ��ރ��f���ɓK�p����A�j���[�V�����t�@�C���̃p�X��ݒ肷��ANULL��n���Ɛݒ胊�Z�b�g( ���݂� PMD,PMX �݂̂Ɍ��ʂ��� )

// ���f���ۑ��֌W
extern	int			MV1SaveModelToMV1File( int MHandle, const TCHAR *FileName, int SaveType = MV1_SAVETYPE_NORMAL , int AnimMHandle = -1 , int AnimNameCheck = TRUE , int Normal8BitFlag = 1 , int Position16BitFlag = 1 , int Weight8BitFlag = 0 , int Anim16BitFlag = 1 ) ;		// �w��̃p�X�Ƀ��f����ۑ�����( �߂�l  0:����  -1:�������s��  -2:�g���Ă��Ȃ��A�j���[�V������������ )
#ifndef DX_NON_SAVEFUNCTION
extern	int			MV1SaveModelToXFile(   int MHandle, const TCHAR *FileName, int SaveType = MV1_SAVETYPE_NORMAL , int AnimMHandle = -1 , int AnimNameCheck = TRUE ) ;	// �w��̃p�X�Ƀ��f�����w�t�@�C���`���ŕۑ�����( �߂�l  0:����  -1:�������s��  -2:�g���Ă��Ȃ��A�j���[�V������������ )
#endif // DX_NON_SAVEFUNCTION

// ���f���`��֌W
extern	int			MV1DrawModel(						int MHandle ) ;														// ���f����`�悷��
extern	int			MV1DrawFrame(						int MHandle, int FrameIndex ) ;										// ���f���̎w��̃t���[����`�悷��
extern	int			MV1DrawMesh(						int MHandle, int MeshIndex ) ;										// ���f���̎w��̃��b�V����`�悷��
extern	int			MV1DrawTriangleList(				int MHandle, int TriangleListIndex ) ;								// ���f���̎w��̃g���C�A���O�����X�g��`�悷��
extern	int			MV1DrawModelDebug(					int MHandle, int Color, int IsNormalLine, float NormalLineLength, int IsPolyLine, int IsCollisionBox ) ;	// ���f���̃f�o�b�O�`��

// �`��ݒ�֌W
extern	int			MV1SetUseOrigShader(				int UseFlag ) ;														// ���f���̕`��� SetUseVertexShader, SetUsePixelShader �Ŏw�肵���V�F�[�_�[���g�p���邩�ǂ�����ݒ肷��( TRUE:�g�p����  FALSE:�g�p���Ȃ�( �f�t�H���g ) )

// ���f����{����֌W
extern	MATRIX		MV1GetLocalWorldMatrix(				int MHandle ) ;														// ���f���̃��[�J�����W���烏�[���h���W�ɕϊ�����s��𓾂�
extern	int			MV1SetPosition(						int MHandle, VECTOR Position ) ;									// ���f���̍��W���Z�b�g
extern	VECTOR		MV1GetPosition(						int MHandle ) ;														// ���f���̍��W���擾
extern	int			MV1SetScale(						int MHandle, VECTOR Scale ) ;										// ���f���̊g��l���Z�b�g
extern	VECTOR		MV1GetScale(						int MHandle ) ;														// ���f���̊g��l���擾
extern	int			MV1SetRotationXYZ(					int MHandle, VECTOR Rotate ) ;										// ���f���̉�]�l���Z�b�g( X����]��Y����]��Z����]���� )
extern	VECTOR		MV1GetRotationXYZ(					int MHandle ) ;														// ���f���̉�]�l���擾( X����]��Y����]��Z����]���� )
extern	int			MV1SetRotationZYAxis(				int MHandle, VECTOR ZAxisDirection, VECTOR YAxisDirection, float ZAxisTwistRotate ) ;	// ���f���̂y���Ƃx���̌������Z�b�g����
extern	int			MV1SetRotationMatrix(				int MHandle, MATRIX Matrix ) ;										// ���f���̉�]�p�s����Z�b�g����
extern	MATRIX		MV1GetRotationMatrix(				int MHandle ) ;														// ���f���̉�]�p�s����擾����
extern	int			MV1SetMatrix(						int MHandle, MATRIX Matrix ) ;										// ���f���̕ό`�p�s����Z�b�g����
extern	MATRIX		MV1GetMatrix(						int MHandle ) ;														// ���f���̕ό`�p�s����擾����
extern	int			MV1SetVisible(						int MHandle, int VisibleFlag ) ;									// ���f���̕\���A��\����Ԃ�ύX����( TRUE:�\��  FALSE:��\�� )
extern	int			MV1GetVisible(						int MHandle ) ;														// ���f���̕\���A��\����Ԃ��擾����( TRUE:�\��  FALSE:��\�� )
extern	int			MV1SetDifColorScale(				int MHandle, COLOR_F Scale ) ;										// ���f���̃f�B�t���[�Y�J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetDifColorScale(				int MHandle ) ;														// ���f���̃f�B�t���[�Y�J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	int			MV1SetSpcColorScale(				int MHandle, COLOR_F Scale ) ;										// ���f���̃X�y�L�����J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetSpcColorScale(				int MHandle ) ;														// ���f���̃X�y�L�����J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	int			MV1SetEmiColorScale(				int MHandle, COLOR_F Scale ) ;										// ���f���̃G�~�b�V�u�J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetEmiColorScale(				int MHandle ) ;														// ���f���̃G�~�b�V�u�J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	int			MV1SetAmbColorScale(				int MHandle, COLOR_F Scale ) ;										// ���f���̃A���r�G���g�J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetAmbColorScale(				int MHandle ) ;														// ���f���̃A���r�G���g�J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	int			MV1GetSemiTransState(				int MHandle ) ;														// ���f���ɔ������v�f�����邩�ǂ������擾����( �߂�l TRUE:����  FALSE:�Ȃ� )
extern	int			MV1SetOpacityRate(					int MHandle, float Rate ) ;											// ���f���̕s�����x��ݒ肷��( �s���� 1.0f �` ���� 0.0f )
extern	float		MV1GetOpacityRate(					int MHandle ) ;														// ���f���̕s�����x���擾����( �s���� 1.0f �` ���� 0.0f )
extern	int			MV1SetUseZBuffer(					int MHandle, int Flag ) ;											// ���f����`�悷��ۂɂy�o�b�t�@���g�p���邩�ǂ�����ݒ肷��
extern	int			MV1SetWriteZBuffer(					int MHandle, int Flag ) ;											// ���f����`�悷��ۂɂy�o�b�t�@�ɏ������݂��s�����ǂ�����ݒ肷��
extern	int			MV1SetZBufferCmpType(				int MHandle, int CmpType /* DX_CMP_NEVER �� */ ) ;					// ���f���̕`�掞�̂y�l�̔�r���[�h��ݒ肷��
extern	int			MV1SetZBias(						int MHandle, int Bias ) ;											// ���f���̕`�掞�̏������ނy�l�̃o�C�A�X��ݒ肷��
extern	int			MV1SetUseVertDifColor(				int MHandle, int UseFlag ) ;										// ���f���̊܂܂�郁�b�V���̒��_�f�B�t���[�Y�J���[���}�e���A���̃f�B�t���[�Y�J���[�̑���Ɏg�p���邩�ǂ�����ݒ肷��( TRUE:�}�e���A���J���[�̑���Ɏg�p����  FALSE:�}�e���A���J���[���g�p���� )
extern	int			MV1SetUseVertSpcColor(				int MHandle, int UseFlag ) ;										// ���f���Ɋ܂܂�郁�b�V���̒��_�X�y�L�����J���[���}�e���A���̃X�y�L�����J���[�̑���Ɏg�p���邩�ǂ�����ݒ肷��( TRUE:�}�e���A���J���[�̑���Ɏg�p����  FALSE:�}�e���A���J���[���g�p���� )
extern	int			MV1SetSampleFilterMode(				int MHandle, int FilterMode ) ;										// ���f���̃e�N�X�`���̃T���v���t�B���^�[���[�h��ύX����( FilterMode �� DX_DRAWMODE_NEAREST �� )
extern	int			MV1SetMaxAnisotropy(				int MHandle, int MaxAnisotropy ) ;									// ���f���ٕ̈����t�B���^�����O�̍ő原����ݒ肷��
extern	int			MV1SetWireFrameDrawFlag(			int MHandle, int Flag ) ;											// ���f�������C���[�t���[���ŕ`�悷�邩�ǂ�����ݒ肷��
extern	int			MV1RefreshVertColorFromMaterial(	int MHandle ) ;														// ���f���̒��_�J���[�����ݐݒ肳��Ă���}�e���A���̃J���[�ɂ���
extern	int			MV1PhysicsCalculation(				int MHandle, float MillisecondTime ) ;								// ���f���̕������Z���w�莞�ԕ��o�߂����Ɖ��肵�Čv�Z����( MillisecondTime �Ŏw�肷�鎞�Ԃ̒P�ʂ̓~���b )
extern	int			MV1PhysicsResetState(				int MHandle ) ;														// ���f���̕������Z�̏�Ԃ����Z�b�g����( �ʒu�����[�v�����Ƃ��p )

// �A�j���[�V�����֌W
extern	int			MV1AttachAnim(						int MHandle, int AnimIndex, int AnimSrcMHandle = -1 , int NameCheck = TRUE ) ;		// �A�j���[�V�������A�^�b�`����( �߂�l  -1:�G���[  0�ȏ�:�A�^�b�`�C���f�b�N�X )
extern	int			MV1DetachAnim(						int MHandle, int AttachIndex ) ;													// �A�j���[�V�������f�^�b�`����
extern	int			MV1SetAttachAnimTime(				int MHandle, int AttachIndex, float Time ) ;										// �A�^�b�`���Ă���A�j���[�V�����̍Đ����Ԃ�ݒ肷��
extern	float		MV1GetAttachAnimTime(				int MHandle, int AttachIndex ) ;													// �A�^�b�`���Ă���A�j���[�V�����̍Đ����Ԃ��擾����
extern	float		MV1GetAttachAnimTotalTime(			int MHandle, int AttachIndex ) ;													// �A�^�b�`���Ă���A�j���[�V�����̑����Ԃ𓾂�
extern	int			MV1SetAttachAnimBlendRate(			int MHandle, int AttachIndex, float Rate = 1.0f ) ;									// �A�^�b�`���Ă���A�j���[�V�����̃u�����h����ݒ肷��
extern	float		MV1GetAttachAnimBlendRate(			int MHandle, int AttachIndex ) ;													// �A�^�b�`���Ă���A�j���[�V�����̃u�����h�����擾����
extern	int			MV1SetAttachAnimBlendRateToFrame(	int MHandle, int AttachIndex, int FrameIndex, float Rate, int SetChild = TRUE ) ;	// �A�^�b�`���Ă���A�j���[�V�����̃u�����h����ݒ肷��( �t���[���P�� )
extern	float		MV1GetAttachAnimBlendRateToFrame(	int MHandle, int AttachIndex, int FrameIndex ) ;									// �A�^�b�`���Ă���A�j���[�V�����̃u�����h����ݒ肷��( �t���[���P�� )
extern	int			MV1GetAttachAnim(					int MHandle, int AttachIndex ) ;													// �A�^�b�`���Ă���A�j���[�V�����̃A�j���[�V�����C���f�b�N�X���擾����

extern	int			MV1GetAnimNum(						int MHandle ) ;																		// �A�j���[�V�����̐����擾����
extern	const TCHAR *MV1GetAnimName(					int MHandle, int AnimIndex ) ;														// �w��ԍ��̃A�j���[�V���������擾����( NULL:�G���[ )
extern	int			MV1SetAnimName(						int MHandle, int AnimIndex, const TCHAR *AnimName ) ;								// �w��ԍ��̃A�j���[�V��������ύX����
extern	int			MV1GetAnimIndex(					int MHandle, const TCHAR *AnimName ) ;												// �w�薼�̃A�j���[�V�����ԍ����擾����( -1:�G���[ )
extern	float		MV1GetAnimTotalTime(				int MHandle, int AnimIndex ) ;														// �w��ԍ��̃A�j���[�V�����̑����Ԃ𓾂�
extern	int			MV1GetAnimTargetFrameNum(			int MHandle, int AnimIndex ) ;														// �w��̃A�j���[�V�������^�[�Q�b�g�Ƃ���t���[���̐����擾����
extern	const TCHAR *MV1GetAnimTargetFrameName(			int MHandle, int AnimIndex, int AnimFrameIndex ) ;									// �w��̃A�j���[�V�������^�[�Q�b�g�Ƃ���t���[���̖��O���擾����
extern	int			MV1GetAnimTargetFrame(				int MHandle, int AnimIndex, int AnimFrameIndex ) ;									// �w��̃A�j���[�V�������^�[�Q�b�g�Ƃ���t���[���̔ԍ����擾����
extern	int			MV1GetAnimTargetFrameKeySetNum(		int MHandle, int AnimIndex, int AnimFrameIndex ) ;									// �w��̃A�j���[�V�������^�[�Q�b�g�Ƃ���t���[���p�̃A�j���[�V�����L�[�Z�b�g�̐����擾����
extern	int			MV1GetAnimTargetFrameKeySet(		int MHandle, int AnimIndex, int AnimFrameIndex, int Index ) ;						// �w��̃A�j���[�V�������^�[�Q�b�g�Ƃ���t���[���p�̃A�j���[�V�����L�[�Z�b�g�L�[�Z�b�g�C���f�b�N�X���擾����

extern	int			MV1GetAnimKeySetNum(				int MHandle ) ;																		// ���f���Ɋ܂܂��A�j���[�V�����L�[�Z�b�g�̑����𓾂�
extern	int			MV1GetAnimKeySetType(				int MHandle, int AnimKeySetIndex ) ;												// �w��̃A�j���[�V�����L�[�Z�b�g�̃^�C�v���擾����( MV1_ANIMKEY_TYPE_QUATERNION �� )
extern	int			MV1GetAnimKeySetDataType(			int MHandle, int AnimKeySetIndex ) ;												// �w��̃A�j���[�V�����L�[�Z�b�g�̃f�[�^�^�C�v���擾����( MV1_ANIMKEY_DATATYPE_ROTATE �� )
extern	int			MV1GetAnimKeySetTimeType(			int MHandle, int AnimKeySetIndex ) ;												// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[�̎��ԃf�[�^�^�C�v���擾����( MV1_ANIMKEY_TIME_TYPE_ONE �� )
extern	int			MV1GetAnimKeySetDataNum(			int MHandle, int AnimKeySetIndex ) ;												// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[�̐����擾����
extern	float		MV1GetAnimKeyDataTime(				int MHandle, int AnimKeySetIndex, int Index ) ;										// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[�̎��Ԃ��擾����
extern	FLOAT4		MV1GetAnimKeyDataToQuaternion(		int MHandle, int AnimKeySetIndex, int Index ) ;										// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[���擾����A�L�[�^�C�v�� MV1_ANIMKEY_TYPE_QUATERNION �ł͖��������ꍇ�͎��s����
extern	FLOAT4		MV1GetAnimKeyDataToQuaternionFromTime( int MHandle, int AnimKeySetIndex, float Time ) ;									// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[���擾����A�L�[�^�C�v�� MV1_ANIMKEY_TYPE_QUATERNION �ł͖��������ꍇ�͎��s����( ���Ԏw��� )
extern	VECTOR		MV1GetAnimKeyDataToVector(			int MHandle, int AnimKeySetIndex, int Index ) ;										// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[���擾����A�L�[�^�C�v�� MV1_ANIMKEY_TYPE_VECTOR �ł͖��������ꍇ�͎��s����
extern	VECTOR		MV1GetAnimKeyDataToVectorFromTime(	int MHandle, int AnimKeySetIndex, float Time ) ;									// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[���擾����A�L�[�^�C�v�� MV1_ANIMKEY_TYPE_VECTOR �ł͖��������ꍇ�͎��s����( ���Ԏw��� )
extern	MATRIX		MV1GetAnimKeyDataToMatrix(			int MHandle, int AnimKeySetIndex, int Index ) ;										// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[���擾����A�L�[�^�C�v�� MV1_ANIMKEY_TYPE_MATRIX4X4C �� MV1_ANIMKEY_TYPE_MATRIX3X3 �ł͖��������ꍇ�͎��s����
extern	MATRIX		MV1GetAnimKeyDataToMatrixFromTime(	int MHandle, int AnimKeySetIndex, float Time ) ;									// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[���擾����A�L�[�^�C�v�� MV1_ANIMKEY_TYPE_MATRIX4X4C �� MV1_ANIMKEY_TYPE_MATRIX3X3 �ł͖��������ꍇ�͎��s����( ���Ԏw��� )
extern	float		MV1GetAnimKeyDataToFlat(			int MHandle, int AnimKeySetIndex, int Index ) ;										// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[���擾����A�L�[�^�C�v�� MV1_ANIMKEY_TYPE_FLAT �ł͖��������ꍇ�͎��s����
extern	float		MV1GetAnimKeyDataToFlatFromTime(	int MHandle, int AnimKeySetIndex, float Time ) ;									// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[���擾����A�L�[�^�C�v�� MV1_ANIMKEY_TYPE_FLAT �ł͖��������ꍇ�͎��s����( ���Ԏw��� )
extern	float		MV1GetAnimKeyDataToLinear(			int MHandle, int AnimKeySetIndex, int Index ) ;										// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[���擾����A�L�[�^�C�v�� MV1_ANIMKEY_TYPE_LINEAR �ł͖��������ꍇ�͎��s����
extern	float		MV1GetAnimKeyDataToLinearFromTime(	int MHandle, int AnimKeySetIndex, float Time ) ;									// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[���擾����A�L�[�^�C�v�� MV1_ANIMKEY_TYPE_LINEAR �ł͖��������ꍇ�͎��s����( ���Ԏw��� )

// �}�e���A���֌W
extern	int			MV1GetMaterialNum(					int MHandle ) ;												// ���f���Ŏg�p���Ă���}�e���A���̐����擾����
extern	const TCHAR *MV1GetMaterialName(				int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���̖��O���擾����
extern	int			MV1SetMaterialType(					int MHandle, int MaterialIndex, int Type ) ;				// �w��̃}�e���A���̃^�C�v��ύX����( Type : DX_MATERIAL_TYPE_NORMAL �Ȃ� )
extern	int			MV1GetMaterialType(					int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���̃^�C�v���擾����( �߂�l : DX_MATERIAL_TYPE_NORMAL �Ȃ� )
extern	int			MV1SetMaterialDifColor(				int MHandle, int MaterialIndex, COLOR_F Color ) ;			// �w��̃}�e���A���̃f�B�t���[�Y�J���[��ݒ肷��
extern	COLOR_F		MV1GetMaterialDifColor( 			int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���̃f�B�t���[�Y�J���[���擾����
extern	int			MV1SetMaterialSpcColor( 			int MHandle, int MaterialIndex, COLOR_F Color ) ;			// �w��̃}�e���A���̃X�y�L�����J���[��ݒ肷��
extern	COLOR_F		MV1GetMaterialSpcColor( 			int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���̃X�y�L�����J���[���擾����
extern	int			MV1SetMaterialEmiColor( 			int MHandle, int MaterialIndex, COLOR_F Color ) ;			// �w��̃}�e���A���̃G�~�b�V�u�J���[��ݒ肷��
extern	COLOR_F		MV1GetMaterialEmiColor( 			int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���̃G�~�b�V�u�J���[���擾����
extern	int			MV1SetMaterialAmbColor( 			int MHandle, int MaterialIndex, COLOR_F Color ) ;			// �w��̃}�e���A���̃A���r�G���g�J���[��ݒ肷��
extern	COLOR_F		MV1GetMaterialAmbColor( 			int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���̃A���r�G���g�J���[���擾����
extern	int			MV1SetMaterialSpcPower( 			int MHandle, int MaterialIndex, float Power ) ;				// �w��̃}�e���A���̃X�y�L�����̋�����ݒ肷��
extern	float		MV1GetMaterialSpcPower( 			int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���̃X�y�L�����̋������擾����
extern	int			MV1SetMaterialDifMapTexture(		int MHandle, int MaterialIndex, int TexIndex ) ;			// �w��̃}�e���A���Ńf�B�t���[�Y�}�b�v�Ƃ��Ďg�p����e�N�X�`�����w�肷��
extern	int			MV1GetMaterialDifMapTexture(		int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���Ńf�B�t���[�Y�}�b�v�Ƃ��Ďg�p����Ă���e�N�X�`���̃C���f�b�N�X���擾����
extern	int			MV1SetMaterialSpcMapTexture(		int MHandle, int MaterialIndex, int TexIndex ) ;			// �w��̃}�e���A���ŃX�y�L�����}�b�v�Ƃ��Ďg�p����e�N�X�`�����w�肷��
extern	int			MV1GetMaterialSpcMapTexture(		int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���ŃX�y�L�����}�b�v�Ƃ��Ďg�p����Ă���e�N�X�`���̃C���f�b�N�X���擾����
extern	int			MV1GetMaterialNormalMapTexture(		int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���Ŗ@���}�b�v�Ƃ��Ďg�p����Ă���e�N�X�`���̃C���f�b�N�X���擾����
extern	int			MV1SetMaterialDifGradTexture(		int MHandle, int MaterialIndex, int TexIndex ) ;			// �w��̃}�e���A���Ńg�D�[�������_�����O�̃f�B�t���[�Y�O���f�[�V�����}�b�v�Ƃ��Ďg�p����e�N�X�`����ݒ肷��
extern	int			MV1GetMaterialDifGradTexture(		int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���Ńg�D�[�������_�����O�̃f�B�t���[�Y�O���f�[�V�����}�b�v�Ƃ��Ďg�p����e�N�X�`�����擾����
extern	int			MV1SetMaterialSpcGradTexture(		int MHandle, int MaterialIndex, int TexIndex ) ;			// �w��̃}�e���A���Ńg�D�[�������_�����O�̃X�y�L�����O���f�[�V�����}�b�v�Ƃ��Ďg�p����e�N�X�`����ݒ肷��
extern	int			MV1GetMaterialSpcGradTexture(		int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���Ńg�D�[�������_�����O�̃X�y�L�����O���f�[�V�����}�b�v�Ƃ��Ďg�p����e�N�X�`�����擾����
extern	int			MV1SetMaterialDifGradBlendType(		int MHandle, int MaterialIndex, int BlendType ) ;			// �w��̃}�e���A���̃g�D�[�������_�����O�Ŏg�p����f�B�t���[�Y�O���f�[�V�����}�b�v�ƃf�B�t���[�Y�J���[�̍������@��ݒ肷��( DX_MATERIAL_BLENDTYPE_ADDITIVE �Ȃ� )
extern	int			MV1GetMaterialDifGradBlendType(		int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���̃g�D�[�������_�����O�Ŏg�p����f�B�t���[�Y�O���f�[�V�����}�b�v�ƃf�B�t���[�Y�J���[�̍������@���擾����( DX_MATERIAL_BLENDTYPE_ADDITIVE �Ȃ� )
extern	int			MV1SetMaterialSpcGradBlendType(		int MHandle, int MaterialIndex, int BlendType ) ;			// �w��̃}�e���A���̃g�D�[�������_�����O�Ŏg�p����X�y�L�����O���f�[�V�����}�b�v�ƃX�y�L�����J���[�̍������@��ݒ肷��( DX_MATERIAL_BLENDTYPE_ADDITIVE �Ȃ� )
extern	int			MV1GetMaterialSpcGradBlendType(		int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���̃g�D�[�������_�����O�Ŏg�p����X�y�L�����O���f�[�V�����}�b�v�ƃX�y�L�����J���[�̍������@���擾����( DX_MATERIAL_BLENDTYPE_ADDITIVE �Ȃ� )
extern	int			MV1SetMaterialOutLineWidth(			int MHandle, int MaterialIndex, float Width ) ;				// �w��̃}�e���A���̃g�D�[�������_�����O�Ŏg�p����֊s���̑�����ݒ肷��
extern	float		MV1GetMaterialOutLineWidth(			int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���̃g�D�[�������_�����O�Ŏg�p����֊s���̑������擾����
extern	int			MV1SetMaterialOutLineDotWidth(		int MHandle, int MaterialIndex, float Width ) ;				// �w��̃}�e���A���̃g�D�[�������_�����O�Ŏg�p����֊s���̃h�b�g�P�ʂ̑�����ݒ肷��
extern	float		MV1GetMaterialOutLineDotWidth(		int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���̃g�D�[�������_�����O�Ŏg�p����֊s���̃h�b�g�P�ʂ̑������擾����
extern	int			MV1SetMaterialOutLineColor(			int MHandle, int MaterialIndex, COLOR_F Color ) ;			// �w��̃}�e���A���̃g�D�[�������_�����O�Ŏg�p����֊s���̐F��ݒ肷��
extern	COLOR_F		MV1GetMaterialOutLineColor(			int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���̃g�D�[�������_�����O�Ŏg�p����֊s���̐F���擾����
extern	int			MV1SetMaterialDrawBlendMode(		int MHandle, int MaterialIndex, int BlendMode ) ;			// �w��̃}�e���A���̕`��u�����h���[�h��ݒ肷��( DX_BLENDMODE_ALPHA �� )
extern	int			MV1GetMaterialDrawBlendMode(		int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���̕`��u�����h���[�h���擾����( DX_BLENDMODE_ALPHA �� )
extern	int			MV1SetMaterialDrawBlendParam(		int MHandle, int MaterialIndex, int BlendParam ) ;			// �w��̃}�e���A���̕`��u�����h�p�����[�^��ݒ肷��
extern	int			MV1GetMaterialDrawBlendParam(		int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���̕`��u�����h�p�����[�^��ݒ肷��

// �e�N�X�`���֌W
extern	int			MV1GetTextureNum(					int MHandle ) ;													// �e�N�X�`���̐����擾
extern	const TCHAR *MV1GetTextureName(					int MHandle, int TexIndex ) ;									// �e�N�X�`���̖��O���擾
extern	int			MV1SetTextureColorFilePath(			int MHandle, int TexIndex, const TCHAR *FilePath ) ;			// �J���[�e�N�X�`���̃t�@�C���p�X��ύX����
extern	const TCHAR *MV1GetTextureColorFilePath(		int MHandle, int TexIndex ) ;									// �J���[�e�N�X�`���̃t�@�C���p�X���擾
extern	int			MV1SetTextureAlphaFilePath(			int MHandle, int TexIndex, const TCHAR *FilePath ) ;			// �A���t�@�e�N�X�`���̃t�@�C���p�X��ύX����
extern	const TCHAR *MV1GetTextureAlphaFilePath(		int MHandle, int TexIndex ) ;									// �A���t�@�e�N�X�`���̃t�@�C���p�X���擾
extern	int			MV1SetTextureGraphHandle(			int MHandle, int TexIndex, int GrHandle, int SemiTransFlag ) ;	// �e�N�X�`���Ŏg�p����O���t�B�b�N�n���h����ύX����( GrHandle �� -1 �ɂ���Ɖ��� )
extern	int			MV1GetTextureGraphHandle(			int MHandle, int TexIndex ) ;									// �e�N�X�`���̃O���t�B�b�N�n���h�����擾����
extern	int			MV1SetTextureAddressMode(			int MHandle, int TexIndex, int AddrUMode, int AddrVMode ) ;		// �e�N�X�`���̃A�h���X���[�h��ݒ肷��( AddUMode �̒l�� DX_TEXADDRESS_WRAP �� )
extern	int			MV1GetTextureAddressModeU(			int MHandle, int TexIndex ) ;									// �e�N�X�`���̂t�l�̃A�h���X���[�h���擾����( �߂�l:DX_TEXADDRESS_WRAP �� )
extern	int			MV1GetTextureAddressModeV(			int MHandle, int TexIndex ) ;									// �e�N�X�`���̂u�l�̃A�h���X���[�h���擾����( �߂�l:DX_TEXADDRESS_WRAP �� )
extern	int			MV1GetTextureWidth(					int MHandle, int TexIndex ) ;									// �e�N�X�`���̕����擾����
extern	int			MV1GetTextureHeight(				int MHandle, int TexIndex ) ;									// �e�N�X�`���̍������擾����
extern	int			MV1GetTextureSemiTransState(		int MHandle, int TexIndex ) ;									// �e�N�X�`���ɔ������v�f�����邩�ǂ������擾����( �߂�l  TRUE:����  FALSE:�Ȃ� )
extern	int			MV1SetTextureBumpImageFlag(			int MHandle, int TexIndex, int Flag ) ;							// �e�N�X�`���Ŏg�p���Ă���摜���o���v�}�b�v���ǂ�����ݒ肷��
extern	int			MV1GetTextureBumpImageFlag(			int MHandle, int TexIndex ) ;									// �e�N�X�`�����o���v�}�b�v���ǂ������擾����( �߂�l  TRUE:�o���v�}�b�v  FALSE:�Ⴄ )
extern	int			MV1SetTextureBumpImageNextPixelLength( int MHandle, int TexIndex, float Length ) ;					// �o���v�}�b�v�摜�̏ꍇ�ׂ̗̃s�N�Z���Ƃ̋�����ݒ肷��
extern	float		MV1GetTextureBumpImageNextPixelLength( int MHandle, int TexIndex ) ;								// �o���v�}�b�v�摜�̏ꍇ�ׂ̗̃s�N�Z���Ƃ̋������擾����
extern	int			MV1SetTextureSampleFilterMode(		int MHandle, int TexIndex, int FilterMode ) ;					// �e�N�X�`���̃t�B���^�����O���[�h��ݒ肷��
extern	int			MV1GetTextureSampleFilterMode(		int MHandle, int TexIndex ) ;									// �e�N�X�`���̃t�B���^�����O���[�h���擾����( �߂�l  DX_DRAWMODE_BILINEAR�� )
extern	int			MV1LoadTexture(						const TCHAR *FilePath ) ;										// �R�c���f���ɓ\��t����̂Ɍ������摜�̓ǂݍ��ݕ����ŉ摜��ǂݍ���( �߂�l  -1:�G���[  0�ȏ�:�O���t�B�b�N�n���h�� )

// �t���[���֌W
extern	int			MV1GetFrameNum(						int MHandle ) ;															// �t���[���̐����擾����
extern	int			MV1SearchFrame(						int MHandle, const TCHAR *FrameName ) ;									// �t���[���̖��O���烂�f�����̃t���[���̃t���[���C���f�b�N�X���擾����( ���������ꍇ�͖߂�l��-1 )
extern	int			MV1SearchFrameChild(				int MHandle, int FrameIndex = -1 , const TCHAR *ChildName = NULL ) ;	// �t���[���̖��O����w��̃t���[���̎q�t���[���̃t���[���C���f�b�N�X���擾����( ���O�w��� )( FrameIndex �� -1 �ɂ���Ɛe�������Ȃ��t���[���� ChildIndex �Ŏw�肷�� )( ���������ꍇ�͖߂�l��-1 )
extern	const TCHAR *MV1GetFrameName(					int MHandle, int FrameIndex ) ;											// �w��̃t���[���̖��O���擾����( �G���[�̏ꍇ�͖߂�l�� NULL )
extern	int			MV1GetFrameParent(					int MHandle, int FrameIndex ) ;											// �w��̃t���[���̐e�t���[���̃C���f�b�N�X�𓾂�( �e�����Ȃ��ꍇ�� -2 ���Ԃ� )
extern	int			MV1GetFrameChildNum(				int MHandle, int FrameIndex = -1 ) ;									// �w��̃t���[���̎q�t���[���̐����擾����( FrameIndex �� -1 �ɂ���Ɛe�������Ȃ��t���[���̐����Ԃ��Ă��� )
extern	int			MV1GetFrameChild(					int MHandle, int FrameIndex = -1 , int ChildIndex = 0 ) ;				// �w��̃t���[���̎q�t���[���̃t���[���C���f�b�N�X���擾����( �ԍ��w��� )( FrameIndex �� -1 �ɂ���Ɛe�������Ȃ��t���[���� ChildIndex �Ŏw�肷�� )( �G���[�̏ꍇ�͖߂�l��-1 )
extern	VECTOR		MV1GetFramePosition(				int MHandle, int FrameIndex ) ;											// �w��̃t���[���̍��W���擾����
extern	MATRIX		MV1GetFrameBaseLocalMatrix(			int MHandle, int FrameIndex ) ;											// �w��̃t���[���̏�����Ԃł̍��W�ϊ��s����擾����
extern	MATRIX		MV1GetFrameLocalMatrix(				int MHandle, int FrameIndex ) ;											// �w��̃t���[���̍��W�ϊ��s����擾����
extern	MATRIX		MV1GetFrameLocalWorldMatrix(		int MHandle, int FrameIndex ) ;											// �w��̃t���[���̃��[�J�����W���烏�[���h���W�ɕϊ�����s��𓾂�
extern	int			MV1SetFrameUserLocalMatrix(			int MHandle, int FrameIndex, MATRIX Matrix ) ;							// �w��̃t���[���̍��W�ϊ��s���ݒ肷��
extern	int			MV1ResetFrameUserLocalMatrix(		int MHandle, int FrameIndex ) ;											// �w��̃t���[���̍��W�ϊ��s����f�t�H���g�ɖ߂�
extern	VECTOR		MV1GetFrameMaxVertexLocalPosition(	int MHandle, int FrameIndex ) ;											// �w��̃t���[���������b�V�����_�̃��[�J�����W�ł̍ő�l�𓾂�
extern	VECTOR		MV1GetFrameMinVertexLocalPosition(	int MHandle, int FrameIndex ) ;											// �w��̃t���[���������b�V�����_�̃��[�J�����W�ł̍ŏ��l�𓾂�
extern	VECTOR		MV1GetFrameAvgVertexLocalPosition(	int MHandle, int FrameIndex ) ;											// �w��̃t���[���������b�V�����_�̃��[�J�����W�ł̕��ϒl�𓾂�
extern	int			MV1GetFrameTriangleNum(				int MHandle, int FrameIndex ) ;											// �w��̃t���[���Ɋ܂܂��|���S���̐����擾����
extern	int			MV1GetFrameMeshNum(					int MHandle, int FrameIndex ) ;											// �w��̃t���[���������b�V���̐����擾����
extern	int			MV1GetFrameMesh(					int MHandle, int FrameIndex, int Index ) ;								// �w��̃t���[���������b�V���̃��b�V���C���f�b�N�X���擾����
extern	int			MV1SetFrameVisible(					int MHandle, int FrameIndex, int VisibleFlag ) ;						// �w��̃t���[���̕\���A��\����Ԃ�ύX����( TRUE:�\��  FALSE:��\�� )
extern	int			MV1GetFrameVisible(					int MHandle, int FrameIndex ) ;											// �w��̃t���[���̕\���A��\����Ԃ��擾����( TRUE:�\��  FALSE:��\�� )
extern	int			MV1SetFrameDifColorScale(			int MHandle, int FrameIndex, COLOR_F Scale ) ;							// �w��̃t���[���̃f�B�t���[�Y�J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	int			MV1SetFrameSpcColorScale(			int MHandle, int FrameIndex, COLOR_F Scale ) ;							// �w��̃t���[���̃X�y�L�����J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	int			MV1SetFrameEmiColorScale(			int MHandle, int FrameIndex, COLOR_F Scale ) ;							// �w��̃t���[���̃G�~�b�V�u�J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	int			MV1SetFrameAmbColorScale(			int MHandle, int FrameIndex, COLOR_F Scale ) ;							// �w��̃t���[���̃A���r�G���g�J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetFrameDifColorScale(			int MHandle, int FrameIndex ) ;											// �w��̃t���[���̃f�B�t���[�Y�J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetFrameSpcColorScale(			int MHandle, int FrameIndex ) ;											// �w��̃t���[���̃X�y�L�����J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetFrameEmiColorScale(			int MHandle, int FrameIndex ) ;											// �w��̃t���[���̃G�~�b�V�u�J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetFrameAmbColorScale(			int MHandle, int FrameIndex ) ;											// �w��̃t���[���̃A���r�G���g�J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	int			MV1GetFrameSemiTransState(			int MHandle, int FrameIndex ) ;											// �w��̃t���[���ɔ������v�f�����邩�ǂ������擾����( �߂�l TRUE:����  FALSE:�Ȃ� )
extern	int			MV1SetFrameOpacityRate(				int MHandle, int FrameIndex, float Rate ) ;								// �w��̃t���[���̕s�����x��ݒ肷��( �s���� 1.0f �` ���� 0.0f )
extern	float		MV1GetFrameOpacityRate(				int MHandle, int FrameIndex ) ;											// �w��̃t���[���̕s�����x���擾����( �s���� 1.0f �` ���� 0.0f )
extern	int			MV1SetFrameBaseVisible(				int MHandle, int FrameIndex, int VisibleFlag ) ;						// �w��̃t���[���̏����\����Ԃ�ݒ肷��( TRUE:�\��  FALSE:��\�� )
extern	int			MV1GetFrameBaseVisible(				int MHandle, int FrameIndex ) ;											// �w��̃t���[���̏����\����Ԃ��擾����( TRUE:�\��  FALSE:��\�� )
extern	int			MV1SetFrameTextureAddressTransform( int MHandle, int FrameIndex, float TransU, float TransV, float ScaleU, float ScaleV, float RotCenterU, float RotCenterV, float Rotate ) ;	// �w��̃t���[���̃e�N�X�`�����W�ϊ��p�����[�^��ݒ肷��
extern	int			MV1SetFrameTextureAddressTransformMatrix( int MHandle, int FrameIndex, MATRIX Matrix ) ;					// �w��̃t���[���̃e�N�X�`�����W�ϊ��s����Z�b�g����
extern	int			MV1ResetFrameTextureAddressTransform( int MHandle, int FrameIndex ) ;										// �w��̃t���[���̃e�N�X�`�����W�ϊ��p�����[�^�����Z�b�g����

// ���b�V���֌W
extern	int			MV1GetMeshNum(						int MHandle ) ;															// ���f���Ɋ܂܂�郁�b�V���̐����擾����
extern	int			MV1GetMeshMaterial(					int MHandle, int MeshIndex ) ;											// �w�胁�b�V�����g�p���Ă���}�e���A���̃C���f�b�N�X���擾����
extern	int			MV1GetMeshTriangleNum(				int MHandle, int MeshIndex ) ;											// �w�胁�b�V���Ɋ܂܂��O�p�`�|���S���̐����擾����
extern	int			MV1SetMeshVisible(					int MHandle, int MeshIndex, int VisibleFlag ) ;							// �w�胁�b�V���̕\���A��\����Ԃ�ύX����( TRUE:�\��  FALSE:��\�� )
extern	int			MV1GetMeshVisible(					int MHandle, int MeshIndex ) ;											// �w�胁�b�V���̕\���A��\����Ԃ��擾����( TRUE:�\��  FALSE:��\�� )
extern	int			MV1SetMeshDifColorScale(			int MHandle, int MeshIndex, COLOR_F Scale ) ;							// �w��̃��b�V���̃f�B�t���[�Y�J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	int			MV1SetMeshSpcColorScale( 			int MHandle, int MeshIndex, COLOR_F Scale ) ;							// �w��̃��b�V���̃X�y�L�����J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	int			MV1SetMeshEmiColorScale( 			int MHandle, int MeshIndex, COLOR_F Scale ) ;							// �w��̃��b�V���̃G�~�b�V�u�J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	int			MV1SetMeshAmbColorScale( 			int MHandle, int MeshIndex, COLOR_F Scale ) ;							// �w��̃��b�V���̃A���r�G���g�J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetMeshDifColorScale( 			int MHandle, int MeshIndex ) ;											// �w��̃��b�V���̃f�B�t���[�Y�J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetMeshSpcColorScale( 			int MHandle, int MeshIndex ) ;											// �w��̃��b�V���̃X�y�L�����J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetMeshEmiColorScale( 			int MHandle, int MeshIndex ) ;											// �w��̃��b�V���̃G�~�b�V�u�J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetMeshAmbColorScale( 			int MHandle, int MeshIndex ) ;											// �w��̃��b�V���̃A���r�G���g�J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	int			MV1SetMeshOpacityRate( 				int MHandle, int MeshIndex, float Rate ) ;								// �w��̃��b�V���̕s�����x��ݒ肷��( �s���� 1.0f �` ���� 0.0f )
extern	float		MV1GetMeshOpacityRate( 				int MHandle, int MeshIndex ) ;											// �w��̃��b�V���̕s�����x���擾����( �s���� 1.0f �` ���� 0.0f )
extern	int			MV1SetMeshDrawBlendMode( 			int MHandle, int MeshIndex, int BlendMode ) ;							// �w��̃��b�V���̕`��u�����h���[�h��ݒ肷��( DX_BLENDMODE_ALPHA �� )
extern	int			MV1SetMeshDrawBlendParam( 			int MHandle, int MeshIndex, int BlendParam ) ;							// �w��̃��b�V���̕`��u�����h�p�����[�^��ݒ肷��
extern	int			MV1GetMeshDrawBlendMode( 			int MHandle, int MeshIndex ) ;											// �w��̃��b�V���̕`��u�����h���[�h���擾����( DX_BLENDMODE_ALPHA �� )
extern	int			MV1GetMeshDrawBlendParam( 			int MHandle, int MeshIndex ) ;											// �w��̃��b�V���̕`��u�����h�p�����[�^��ݒ肷��
extern	int			MV1SetMeshBaseVisible( 				int MHandle, int MeshIndex, int VisibleFlag ) ;							// �w��̃��b�V���̏����\����Ԃ�ݒ肷��( TRUE:�\��  FALSE:��\�� )
extern	int			MV1GetMeshBaseVisible( 				int MHandle, int MeshIndex ) ;											// �w��̃��b�V���̏����\����Ԃ��擾����( TRUE:�\��  FALSE:��\�� )
extern	int			MV1SetMeshBackCulling( 				int MHandle, int MeshIndex, int CullingFlag ) ;							// �w��̃��b�V���̃o�b�N�J�����O���s�����ǂ�����ݒ肷��( DX_CULLING_LEFT �� )
extern	int			MV1GetMeshBackCulling( 				int MHandle, int MeshIndex ) ;											// �w��̃��b�V���̃o�b�N�J�����O���s�����ǂ������擾����( DX_CULLING_LEFT �� )
extern	VECTOR		MV1GetMeshMaxPosition( 				int MHandle, int MeshIndex ) ;											// �w��̃��b�V���Ɋ܂܂��|���S���̍ő働�[�J�����W���擾����
extern	VECTOR		MV1GetMeshMinPosition( 				int MHandle, int MeshIndex ) ;											// �w��̃��b�V���Ɋ܂܂��|���S���̍ŏ����[�J�����W���擾����
extern	int			MV1GetMeshTListNum( 				int MHandle, int MeshIndex ) ;											// �w��̃��b�V���Ɋ܂܂��g���C�A���O�����X�g�̐����擾����
extern	int			MV1GetMeshTList( 					int MHandle, int MeshIndex, int Index ) ;								// �w��̃��b�V���Ɋ܂܂��g���C�A���O�����X�g�̃C���f�b�N�X���擾����
extern	int			MV1GetMeshSemiTransState( 			int MHandle, int MeshIndex ) ;											// �w��̃��b�V���ɔ������v�f�����邩�ǂ������擾����( �߂�l TRUE:����  FALSE:�Ȃ� )
extern	int			MV1SetMeshUseVertDifColor( 			int MHandle, int MeshIndex, int UseFlag ) ;								// �w��̃��b�V���̒��_�f�B�t���[�Y�J���[���}�e���A���̃f�B�t���[�Y�J���[�̑���Ɏg�p���邩�ǂ�����ݒ肷��( TRUE:�}�e���A���J���[�̑���Ɏg�p����  FALSE:�}�e���A���J���[���g�p���� )
extern	int			MV1SetMeshUseVertSpcColor( 			int MHandle, int MeshIndex, int UseFlag ) ;								// �w��̃��b�V���̒��_�X�y�L�����J���[���}�e���A���̃X�y�L�����J���[�̑���Ɏg�p���邩�ǂ�����ݒ肷��( TRUE:�}�e���A���J���[�̑���Ɏg�p����  FALSE:�}�e���A���J���[���g�p���� )
extern	int			MV1GetMeshUseVertDifColor( 			int MHandle, int MeshIndex ) ;											// �w��̃��b�V���̒��_�f�B�t���[�Y�J���[���}�e���A���̃f�B�t���[�Y�J���[�̑���Ɏg�p���邩�ǂ����̐ݒ���擾����( �߂�l  TRUE:�}�e���A���J���[�̑���Ɏg�p����  FALSE:�}�e���A���J���[���g�p���� )
extern	int			MV1GetMeshUseVertSpcColor( 			int MHandle, int MeshIndex ) ;											// �w��̃��b�V���̒��_�X�y�L�����J���[���}�e���A���̃X�y�L�����J���[�̑���Ɏg�p���邩�ǂ����̐ݒ���擾����( �߂�l  TRUE:�}�e���A���J���[�̑���Ɏg�p����  FALSE:�}�e���A���J���[���g�p���� )

// �g���C�A���O�����X�g�֌W
extern	int			MV1GetTriangleListNum(				int MHandle ) ;															// ���f���Ɋ܂܂��g���C�A���O�����X�g�̐����擾����
extern	int			MV1GetTriangleListVertexType(		int MHandle, int TListIndex ) ;											// �w��̃g���C�A���O�����X�g�̒��_�f�[�^�^�C�v���擾����( DX_MV1_VERTEX_TYPE_1FRAME �� )
extern	int			MV1GetTriangleListPolygonNum(		int MHandle, int TListIndex ) ;											// �w��̃g���C�A���O�����X�g�Ɋ܂܂��|���S���̐����擾����
extern	int			MV1GetTriangleListVertexNum(		int MHandle, int TListIndex ) ;											// �w��̃g���C�A���O�����X�g�Ɋ܂܂�钸�_�f�[�^�̐����擾����

// �R���W�����֌W
extern	int							MV1SetupCollInfo(				int MHandle, int FrameIndex = -1 , int XDivNum = 32 , int YDivNum = 8 , int ZDivNum = 32 ) ;	// �R���W���������\�z����
extern	int							MV1TerminateCollInfo(			int MHandle, int FrameIndex = -1 ) ;															// �R���W�������̌�n��
extern	int							MV1RefreshCollInfo(				int MHandle, int FrameIndex = -1 ) ;															// �R���W���������X�V����
extern	MV1_COLL_RESULT_POLY		MV1CollCheck_Line(				int MHandle, int FrameIndex, VECTOR PosStart, VECTOR PosEnd ) ;									// ���ƃ��f���̓����蔻��
extern	MV1_COLL_RESULT_POLY_DIM	MV1CollCheck_LineDim(			int MHandle, int FrameIndex, VECTOR PosStart, VECTOR PosEnd ) ;									// ���ƃ��f���̓����蔻��( �߂�l�� MV1_COLL_RESULT_POLY_DIM )
extern	MV1_COLL_RESULT_POLY_DIM	MV1CollCheck_Sphere(			int MHandle, int FrameIndex, VECTOR CenterPos, float r ) ;										// ���ƃ��f���̓����蔻��
extern	MV1_COLL_RESULT_POLY_DIM	MV1CollCheck_Capsule(			int MHandle, int FrameIndex, VECTOR Pos1, VECTOR Pos2, float r ) ;								// �J�v�Z���ƃ��f���̓����蔻��
extern	MV1_COLL_RESULT_POLY		MV1CollCheck_GetResultPoly(		MV1_COLL_RESULT_POLY_DIM ResultPolyDim, int PolyNo ) ;											// �R���W�������ʃ|���S���z�񂩂�w��ԍ��̃|���S�������擾����
extern	int							MV1CollResultPolyDimTerminate(	MV1_COLL_RESULT_POLY_DIM ResultPolyDim ) ;														// �R���W�������ʃ|���S���z��̌�n��������

// �Q�Ɨp���b�V���֌W
extern	int					MV1SetupReferenceMesh(		int MHandle, int FrameIndex, int IsTransform ) ;						// �Q�Ɨp���b�V���̃Z�b�g�A�b�v
extern	int					MV1TerminateReferenceMesh(	int MHandle, int FrameIndex, int IsTransform ) ;						// �Q�Ɨp���b�V���̌�n��
extern	int					MV1RefreshReferenceMesh(	int MHandle, int FrameIndex, int IsTransform ) ;						// �Q�Ɨp���b�V���̍X�V
extern	MV1_REF_POLYGONLIST	MV1GetReferenceMesh(		int MHandle, int FrameIndex, int IsTransform ) ;						// �Q�Ɨp���b�V�����擾����

#endif // DX_NON_MODEL

#define DX_FUNCTION_END

}

// �l�[���X�y�[�X DxLib ���g�p���� ------------------------------------------------------
using namespace DxLib ;

// �c�w���C�u���������ł̂ݎg�p����w�b�_�t�@�C���̃C���N���[�h -------------------------

#ifdef __DX_MAKE
//	#include "DxStatic.h"
#endif

#endif


