/*
 * SpriteNode.cpp
 *
 *  Created on: 2013/02/27
 *      Author: matsukuwa
 */


#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL_image.h> // αつきの画像をロードするため
#include "SpriteNode.h"


// テクスチャサイズを求める
// 引数の値以上で、もっとも小さい2のn乗の値を求める
static int GetUpperPowOf2(int n)
{
	int base = 2;
	for (int i=0 ; i<12 ; i++) {
		if ( n <= base ) return base;
		base <<= 1;
	}
	return 256;
}

// SDLサーフェスからOpenGL用のテクスチャを作成するサブルーチン
static GLuint CreateGLTexture(SDL_Surface *surface)
{
	bool alpha = (surface->flags & SDL_SRCALPHA) != 0;
	surface->flags &= ~SDL_SRCALPHA;

	// 2のn乗の32bitサーフェスを作成してそちらにコピー
	SDL_Surface *image = SDL_CreateRGBSurface(SDL_SWSURFACE, GetUpperPowOf2(surface->w), GetUpperPowOf2(surface->h), 32,
#if SDL_BYTEORDER == SDL_LIL_ENDIAN
			0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000
#else
			0xFF000000,0x00FF0000, 0x0000FF00, 0x000000FF
#endif
			);
	if(image == NULL) {
        fprintf(stderr, "CreateRGBSurface failed: %s¥n", SDL_GetError());
        exit(1);
    }

	SDL_BlitSurface(surface, NULL, image, NULL);

	// OpenGLテクスチャ作成
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	SDL_Surface *sf = image;
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sf->w,sf->h,0, GL_RGBA, GL_UNSIGNED_BYTE, sf->pixels);

	SDL_FreeSurface(image);

	return texture;
}

// OpenGLでスプライトを１個描画するサブルーチン
// texture : 描画に使用するOpenGLテクスチャID
// imagew : 元画像幅
// imageh : 元画像高さ
// src  : 画像内の描画元矩形
// dest : 画面上の描画対象矩形
// z    : 描画時のZ座標（Zバッファ用）
static void DrawSprite(GLuint texture, int imagew, int imageh, SpriteRect *src, SpriteRect *dest, int z, SpriteNode::ENUM_OP_TYPE op_type, const GLubyte color[4])
{
	// 左上、左下、右上、右下の各頂点情報セット
	float fz = (float)z;
	float x = floor(dest->x + 0.5f);
	float y = floor(dest->y + 0.5f);
	GLfloat vLT[3] = {x, y, fz};
	GLfloat vLD[3] = {x, (y+dest->h), fz};
	GLfloat vRT[3] = {(x+dest->w), y, fz};
	GLfloat vRD[3] = {(x+dest->w), (y+dest->h), fz};

	// 合成方法をセット
	if (op_type == SpriteNode::OP_ADD) {
		glBlendFunc(GL_SRC_ALPHA, GL_ONE); // 加算合成の場合
	}
	else {
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // 通常合成の場合
	}

	// テクスチャセット
	glBindTexture(GL_TEXTURE_2D, texture);

	// トライアングルストリップ描画開始
	// ここでは、三角形２つで四角形を描画する
	glBegin(GL_TRIANGLE_STRIP);

	// 頂点情報をセット
	float w = (float) imagew;
	float h = (float) imageh;
	float tx = (float) src->x / w;
	float ty = (float) src->y / h;
	float tw = (float) src->w / w;
	float th = (float) src->h / h;

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
	glColor4ubv(color);

	glTexCoord2f(tx, ty);
	glVertex2fv(vLT);
	glTexCoord2f(tx+tw, ty);
	glVertex2fv(vRT);
	glTexCoord2f(tx, ty+th);
	glVertex2fv(vLD);
	glTexCoord2f(tx+tw, ty+th);
	glVertex2fv(vRD);

	glEnd();
}


//
//  class ImageLoaderItem
//

// ImageLoaderの１画像項目を表すクラス
// struct風に使用するため、メンバはpublicとする。

// コンストラクタ
ImageLoaderItem::ImageLoaderItem()
	: m_surface(NULL)
	, m_texture(0)
	, m_xgridspan(0), m_ygridspan(0), m_xgridcount(0)
{
	m_name[0] = '¥0';
}

// デストラクタ
ImageLoaderItem::~ImageLoaderItem()
{
	this->Delete();
}

// 画像に名前をつける
void ImageLoaderItem::SetName(const char *name)
{
	strncpy(m_name, name, MAX_PATH-1);
	m_name[MAX_PATH-1] = '¥0';
}

// 画像のテクスチャ、サーフェスを削除する
void ImageLoaderItem::Delete()
{
	if (m_surface) SDL_FreeSurface(m_surface);
	if (m_texture) glDeleteTextures(1, &(m_texture));
	m_surface = NULL;
	m_texture = 0;
}

// 画像の情報を設定する
// surface : SDLサーフェスへのポインタ
// texture : OpenGLテクスチャID
// xspan  : 画像内のチップ幅
// yspan  : 画像内のチップ高さ
// xcount : 画像内のチップのX方向の並び数（チップインデックスから位置を求めるために使用）
void ImageLoaderItem::Set(SDL_Surface *surface, GLuint texture, int xspan, int yspan, int xcount)
{
	m_surface = surface;
	m_texture = texture;
	m_xgridspan = xspan;
	m_ygridspan = yspan;
	m_xgridcount = xcount;
}


//
//  class ImageLoader
//

// ロードした画像を管理するクラス



// コンストラクタ
ImageLoader::ImageLoader()
	: m_count(0)
{
}

// デストラクタ
ImageLoader::~ImageLoader()
{
	Destroy();
}


// サーフェス・テクスチャをすべて解放
void ImageLoader::Destroy()
{
	for ( int i=0 ; i < m_count ; i++ ) {
		m_items[i].Delete();
	}
	m_count = 0;
}

// サーフェスの追加登録
// チップ用のグリッド指定がある場合は指定可能
// name : 画像名（検索用）
// surface : SDLサーフェス（画像データが入っている状態であること）
// xgridspan  : 画像内のチップ幅
// ygridspan  : 画像内のチップ高さ
// xgridcount : 画像内のチップのX方向の並び数（チップインデックスから位置を求めるために使用）
// 返り値 : true : 成功　false : 失敗
bool ImageLoader::AddSurface(const char *name, SDL_Surface *surface, int xgridspan, int ygridspan, int xgridcount)
{
	if (!surface) {
		printf("ImageLoader::AddSurface() surface for %s is NULL.¥n", name);
		return false;
	}
	GLuint texture = CreateGLTexture(surface);

	for ( int i=0 ; i < m_count ; i++ ) {
		ImageLoaderItem &item = m_items[i];
		// 既存のサーフェス内に名前が存在したら上書き
		if (strcmp(item.m_name, name) == 0) {
			item.Delete();
			item.Set(surface, texture, xgridspan, ygridspan, xgridcount);
			return true;
		}
	}
	// サーフェスを新しく追加（余裕があれば）
	if (m_count >= MAX_SURFACES) {
		return false;
	}

	// 新しい要素を追加
	ImageLoaderItem &nextitem = m_items[m_count];
	nextitem.SetName(name);
	nextitem.Set(surface, texture, xgridspan, ygridspan, xgridcount);
	m_count++;

	return true;
}

// サーフェスの追加登録（ファイル名で登録）
// name : 画像名（検索用）
// filename : 画像ファイル名（SDL_imageがロード可能なもの：PNG, GIF, BMP等)
// xgridspan  : 画像内のチップ幅
// ygridspan  : 画像内のチップ高さ
// xgridcount : 画像内のチップのX方向の並び数（チップインデックスから位置を求めるために使用）
// 返り値 : true : 成功　false : 失敗
bool ImageLoader::AddSurfaceByFileName(const char *name, const char *filename, int xgridspan, int ygridspan, int xgridcount )
{
	return AddSurface(name, IMG_Load(filename), xgridspan, ygridspan, xgridcount );
}

// 画像アイテムを名前で取得
ImageLoaderItem *ImageLoader::GetItemByName(const char *name)
{
	for ( int i=0 ; i < m_count ; i++ ) {
		ImageLoaderItem &item = m_items[i];
		if (strcmp(item.m_name, name) == 0) return &item;
	}
	return NULL;
}


//
//  SpriteNode クラス
//

//SpriteNode *SpriteNode::s_children_sort[SpriteNode::MAX_CHILDREN+1]; // 子ノードソート用

// コンストラクタ
SpriteNode::SpriteNode()
	: m_mode(MODE_NULL)
	, m_loader(NULL), m_image(NULL), m_texture(0)
	, m_texsize_w(1), m_texsize_h(1)
	, m_x(0), m_y(0), m_z(0), m_show(true), m_op_type(OP_NORMAL)
	, m_xcenter(0), m_ycenter(0), m_xscale(1.0), m_yscale(1.0)
	, m_xgridspan(0), m_ygridspan(0), m_xgridcount(0), m_gridindex(0)
	, m_xchipspan(1), m_ychipspan(1)
	, m_child_count(0), m_child_capacity(0), m_parent(NULL)
	, m_text_updated(false), m_font(NULL)
{
	m_imagename[0] = '¥0';
	SDL_Color textcolor = { 0xff, 0xff, 0xff, 0 };
	m_textcolor = textcolor;


	m_color[0] = 255; // RED
	m_color[1] = 255; // GREEN
	m_color[2] = 255; // BLUE
	m_color[3] = 255; // ALPHA
}

// デストラクタ
SpriteNode::~SpriteNode()
{
	Destroy();
}

// ノードを削除する
void SpriteNode::Destroy()
{
	if (m_mode == MODE_TEXT) {
		// テキストの場合の処理
		if (m_image) SDL_FreeSurface(m_image);
		if (m_texture) glDeleteTextures(1, &m_texture);
		m_image = NULL;
		m_texture = 0;
	}

	// 親から自分を切り離す
	if (m_parent) m_parent->RemoveChild(this);

	// 子を親から切り離す
	for (int i=0 ; i<m_child_count ; i++) {
		SpriteNode *node = m_children[i];
		if (node->m_parent == this) node->m_parent = NULL;
	}
	if (m_child_capacity > 0) {
		delete [] m_children;
		m_children = NULL;
		m_child_capacity = 0;
	}
	m_child_count = 0;
}

// 親の座標系から自分の座標系に変換
void SpriteNode::TranslateParentToThis(float *x, float *y, bool use_this_scale)
{
	float xscale = use_this_scale ? m_xscale : 1.0f;
	float yscale = use_this_scale ? m_yscale : 1.0f;
	*x = (*x - (float)m_x) / xscale;
	*y = (*y - (float)m_y) / yscale;
}

// 自分の座標系から親の座標系に変換
void SpriteNode::TranslateThisToParent(float *x, float *y, bool use_this_scale)
{
	float xscale = use_this_scale ? m_xscale : 1.0f;
	float yscale = use_this_scale ? m_yscale : 1.0f;
	*x = *x * xscale + (float)m_x;
	*y = *y * yscale + (float)m_y;
}

// ルート（一番上の親）の座標系から自分の座標系に変換
void SpriteNode::TranslateRootToThis(float *x, float *y, bool use_this_scale)
{
	if (m_parent) {
		m_parent->TranslateRootToThis(x, y, true);
	}
	TranslateParentToThis(x, y, use_this_scale);
}

// 自分の座標系からルート（一番上の親）の座標系に変換
void SpriteNode::TranslateThisToRoot(float *x, float *y, bool use_this_scale)
{
	TranslateThisToParent(x, y, use_this_scale);
	if (m_parent) {
		m_parent->TranslateThisToRoot(x, y, true);
	}
}


// 画像ファイル名をセット
// （画像ローダーから検索する時の名前）
// さらに、現在のモードを画像モードに変更する
// ついでに画像ローダーをセット可能（NULLならそのまま）
void SpriteNode::SetImageName(const char *name, ImageLoader *loader)
{
	strncpy(m_imagename, name, MAX_PATH-1);
	m_imagename[MAX_PATH-1] = '¥0';
	if (loader) m_loader = loader;
	m_mode = MODE_IMAGE;
}

// 画像ファイル名を元にローダーから画像を取ってくる
// （SetImageNameでセットした画像名で検索する）
bool SpriteNode::FetchImage()
{
	for (int i=0 ; i<m_child_count ; i++) {
		m_children[i]->FetchImage();
	}
	if (strcmp(m_imagename,"") == 0) return true;
	//SetSurface(m_loader->GetSurfaceByName(m_imagename));
	//m_texture = m_loader->GetTextureByName(m_imagename);
	ImageLoaderItem *item = m_loader->GetItemByName(m_imagename);
	if (!item) return false;
	m_image = item->m_surface;
	m_texture = item->m_texture;
	m_texsize_w = GetUpperPowOf2(m_image->w);
	m_texsize_h = GetUpperPowOf2(m_image->h);
	SetChipGrid(item->m_xgridspan, item->m_ygridspan, item->m_xgridcount);
	return true;
}


// 子ノード関連

// 子ノード数を取得
int SpriteNode::GetChildCount() const
{
	return m_child_count;
}

// 子ノードのポインタをインデックス指定で取得
// （削除等を行った場合、同じインデックスで同じノードが取れるわけではないので注意）
SpriteNode * SpriteNode::GetChildAt(int index)
{
	if (index < 0 || index >= m_child_count) return NULL;
	return m_children[index];
}

// 子ノード配列のキャパシティを拡張
void SpriteNode::IncreaseChildrenCapacity()
{
	// children容量拡張
	int new_child_capacity = (m_child_capacity == 0) ? 8 : m_child_capacity * 4;
	SpriteNode **new_children = new SpriteNode*[new_child_capacity];
	if (m_child_capacity > 0) {
		memcpy(new_children, m_children, sizeof(SpriteNode *) * m_child_count);
		delete [] m_children;
	}
	m_children = new_children;
	m_child_capacity = new_child_capacity;
}


// 子ノードを追加
bool SpriteNode::AddChild(SpriteNode *node)
{
	if (!node) return false;
	if (m_child_count >= m_child_capacity) {
		IncreaseChildrenCapacity();
	}
	m_children[m_child_count] = node;
	m_child_count++;
	node->m_parent = this;
	return true;
}

// 子ノードを削除
// （配列の後ろの要素を詰める）
bool SpriteNode::RemoveChild(SpriteNode *node)
{
	bool found = false;
	for (int i=0 ; i<m_child_count ; i++) {
		if (!found && (m_children[i] == node)) {
			found = true;
		}
		// 発見済みならば後ろの要素を詰める
		if (found && (i != m_child_count-1)) {
			m_children[i] = m_children[i+1];
		}
	}
	if (found) {
		m_child_count--;
	}
	node->m_parent = NULL;
	return found;
}

// 親ノードから切り離す
bool SpriteNode::RemoveFromParent()
{
	if (!m_parent) return false;
	return m_parent->RemoveChild(this);
}


// テキストモード関連

// フォントを設定する
// 同時に、テキストモードに変更する
void SpriteNode::SetFont(const char* fontname)
{
	m_mode = MODE_TEXT;
	m_font = TTF_OpenFont(fontname,16);
}

// テキスト表示用文字列をセット
// 同時に、テキストモードに変更する
void SpriteNode::SetText(const char *text)
{
	m_mode = MODE_TEXT;
	if (strncmp(m_text, text, MAX_TEXT_LEN) == 0) {
		return;
	}
	strncpy(m_text, text, MAX_TEXT_LEN-1);
	m_text[MAX_TEXT_LEN-1] = '¥0';
	m_text_updated = true;
}

// テキストの色を設定
void SpriteNode::SetTextColor( unsigned int r, unsigned int g, unsigned int b)
{
	SDL_Color color = {r,g,b,0};
	if ( m_textcolor.r != r
		|| m_textcolor.g != g
		|| m_textcolor.b != b ) {
		return;
	}
	m_textcolor = color;
	m_text_updated = true;
}


// 描画ルーチン

// このノード自体を描画
// xbase,ybase				: 描画に使用する座標系の原点座標
// xbasescale,ybasescale	: 描画に使用する座標系の拡大率
void SpriteNode::DrawThis(DrawSystem *ds, float xbase, float ybase, float xbasescale, float ybasescale)
{
	if (m_mode == MODE_NULL) return;

	if (m_mode == MODE_TEXT) {
		if (m_text_updated) {
			m_text_updated = false;

			wchar_t wtext[200];
#ifdef _WIN32
			// ここはWindows専用
			size_t res = mbstowcs(wtext, m_text, strlen(m_text));
			wtext[res] = 0;
#else
			// とりあえずエンコーディング変換せずそのままコピー（日本語不可）
			int len = strlen(m_text);
			int i=0;
			for (i=0 ; i<len ; i++) {
				wtext[i] = (wchar_t) m_text[i];
			}
			wtext[i] = 0;
#endif
			if (m_image) {
				SDL_FreeSurface(m_image);
				glDeleteTextures(1, &m_texture);
			}
			m_image = TTF_RenderUNICODE_Blended(m_font, (Uint16 *) &wtext[0], m_textcolor);
			m_texture = CreateGLTexture(m_image);
			m_texsize_w = GetUpperPowOf2(m_image->w);
			m_texsize_h = GetUpperPowOf2(m_image->h);
		}
	}

	if (m_texture == 0) return;

	int srcw = m_texsize_w;
	int srch = m_texsize_h;

	// 画像ソースサイズを求める
	if (m_xgridcount > 0) {
		srcw = m_xgridspan;
		srch = m_ygridspan;
	}

	// 転送先の座標は拡大率を考慮して指定する
	SpriteRect destrect = {
		(float)xbase + (float)m_x * xbasescale + ( - (float)m_xcenter * m_xscale * xbasescale),
		(float)ybase + (float)m_y * ybasescale + ( - (float)m_ycenter * m_yscale * ybasescale),
		(float)srcw * m_xscale * xbasescale,
		(float)srch * m_yscale * ybasescale
	};

	SpriteRect srcrect;
	if (m_xgridcount > 0) {
		// 転送元はm_gridindexからチップの位置を求める
		SpriteRect rect = {
			(float) ((m_gridindex % m_xgridcount) * m_xgridspan),
			(float) ((m_gridindex / m_xgridcount) * m_ygridspan),
			(float) srcw,
			(float) srch
		};
		srcrect = rect;

		// 1x1チップ以上の場合の対処
		if (m_xchipspan > 0) {
			destrect.w *= m_xchipspan;
			srcrect.w *= m_xchipspan;
		}
		if (m_ychipspan > 0) {
			destrect.h *= m_ychipspan;
			srcrect.h *= m_ychipspan;
		}
	}
	else {
		// チップのグリッド設定がなければ画像をそのまま使用
		SpriteRect rect = {
			0,0,(float)srcw, (float)srch
		};
		srcrect = rect;
	}

	if (ds->IsIntersectScreen(&destrect)) {
		// 画像を描画する(OpenGL)
		DrawSprite(m_texture, m_texsize_w, m_texsize_h, &srcrect, &destrect, 0, m_op_type, m_color);
	}
}


#define MAX_NESTING_LEVEL 20
#define MAX_CHILDREN_PER_LEVEL 512

// ソート用バッファ（ネスト階層ごとに分ける必要がある）
static SpriteNode * (s_sortbuf[MAX_NESTING_LEVEL])[MAX_CHILDREN_PER_LEVEL];

// OpenGLでこのノードおよび子ノードを描画
void SpriteNode::DrawGL(DrawSystem *ds, float xbase, float ybase, float xscale, float yscale, int level)
{
	if (!m_show) return;
	if (level >= MAX_NESTING_LEVEL) return;
	if (m_child_count == 0) {
		DrawThis(ds, xbase, ybase, xscale, yscale );
	}
	else {
		// 子ノードも含めてZの順番にソートして描画する
		// （子ノードとの前後関係を表現）
		SpriteNode *(*sortbuf)[MAX_CHILDREN_PER_LEVEL] = &s_sortbuf[level];
		//SpriteNode *sortbufx[MAX_CHILDREN_PER_LEVEL];
		//SpriteNode *(*sortbuf)[MAX_CHILDREN_PER_LEVEL] = &sortbufx;
		static SpriteNode mynode; // 自分(Z=0)を表すプレースホルダとして使用
		mynode.SetZ(0);
		memcpy((*sortbuf), m_children, m_child_count * sizeof(SpriteNode*));
		// 自分を表す要素を追加
		(*sortbuf)[m_child_count] = &mynode;
		qsort((*sortbuf), m_child_count+1, sizeof(SpriteNode*), SpriteNode::SortFunc);

		// ソート結果の順番に描画
		for (int i=0 ; i<m_child_count+1 ; i++) {
			SpriteNode *node = (*sortbuf)[i];
			if (node == &mynode) {
				// このノードを描画
				this->DrawThis(ds, xbase, ybase, xscale, yscale);
			}
			else {
				// 子ノードを描画
				node->DrawGL(ds, xbase + m_x * xscale, ybase + m_y * xscale, xscale * m_xscale, yscale * m_yscale, level+1);
			}
		}
	}
}



//
//  DrawSystem
//

SpriteNode *DrawSystem::s_nodes_sort[DrawSystem::MAX_NODES];

// ノードを追加する
bool DrawSystem::AddNode(SpriteNode *node)
{
	if (!node) return false;
	//node->SetImageLoader(m_loader);
	if (!node->FetchImage()) {
		printf("SpriteNode::FetchImage() failed for:");
		printf(node->GetImageName());
	}
	if (m_node_count >= MAX_NODES-1) return false;
	m_nodes[m_node_count] = node;
	m_node_count++;
	return true;
}

// ノードを削除する
bool DrawSystem::RemoveNode(SpriteNode *node)
{
	bool found = false;
	for (int i=0 ; i<m_node_count ; i++) {
		if (!found && (m_nodes[i] == node)) {
			found = true;
		}
		// 発見済みならば後ろの要素を詰める
		if (found && (i != m_node_count-1)) {
			m_nodes[i] = m_nodes[i+1];
		}
	}
	if (found) {
		m_node_count--;
	}
	return found;
}

// すべて描画する
void DrawSystem::DrawGL()
{
	// Z座標でソートする。
	// 実装の簡単さからクイックソートを使用。
	memcpy( s_nodes_sort, m_nodes, sizeof(SpriteNode*) * m_node_count);
	qsort(s_nodes_sort, m_node_count, sizeof(SpriteNode*), SpriteNode::SortFunc);
	for (int i=0 ; i<m_node_count ; i++) {
		s_nodes_sort[i]->DrawGL(this, 0,0,1.0f, 1.0f, 0);
	}
}

// 指定矩形が画面内に一部入るかどうかを返す
bool DrawSystem::IsIntersectScreen(SpriteRect *rect)
{
	float x1,x2,y1,y2;
	// x1 は矩形の左端、 x2は右端 とする ( x1 <= x2 となる)
	if (rect->w >= 0) {
		x1 = rect->x;
		x2 = rect->x+rect->w;
	}
	else {
		x2 = rect->x;
		x1 = rect->x+rect->w;
	}
	// y1矩形の上端、 y2は下端 とする ( y1 <= y2 となる)
	if (rect->h >= 0) {
		y1 = rect->y;
		y2 = rect->y+rect->h;
	}
	else {
		y2 = rect->y;
		y1 = rect->y+rect->h;
	}
	return ! (x2 < 0 || x1 >= m_screen_w || y2 < 0 || y1 >=m_screen_h);
}
