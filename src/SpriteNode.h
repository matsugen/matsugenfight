/*
 * SpriteNode.h
 *
 *  Created on: 2013/02/27
 *      Author: matsukuwa
 */

#ifndef SPRITENODE_H_
#define SPRITENODE_H_


#ifndef _SPRITE_NODE_
#define _SPRITE_NODE_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <GL/gl.h>
#include <GL/glu.h>

#ifndef MAX_PATH
#define MAX_PATH 255
#endif

struct SDL_Surface;

class DrawSystem;

//
//  class ImageLoaderItem
//

// ImageLoaderの１画像項目を表すクラス
// struct風に使用するため、メンバはpublicとする。
// 現状では、SDLサーフェスとOpenGLテクスチャの両方を保持しておく

class ImageLoaderItem
{
public:
	char m_name[MAX_PATH];	// 画像の名前
	SDL_Surface *m_surface;	// SDLサーフェス
	GLuint m_texture;		// OpenGLテクスチャID
	int m_xgridspan;		// サーフェス内のキャラチップ配置間隔(X)
	int m_ygridspan;		// サーフェス内のキャラチップ配置間隔(Y)
	int m_xgridcount;		// サーフェス内のX方向のキャラチップ配置数

public:
	// コンストラクタ
	ImageLoaderItem();

	// デストラクタ
	~ImageLoaderItem();

	// 画像に名前をつける
	void SetName(const char *name);

	// 画像のテクスチャ、サーフェスを削除する
	void Delete();

	// 画像の情報を設定する
	// surface : SDLサーフェスへのポインタ
	// texture : OpenGLテクスチャID
	// xspan  : 画像内のチップ幅
	// yspan  : 画像内のチップ高さ
	// xcount : 画像内のチップのX方向の並び数（チップインデックスから位置を求めるために使用）
	void Set(SDL_Surface *surface, GLuint texture, int xspan, int yspan, int xcount);
};

//
//  class ImageLoader
//

// ロードした画像を管理するクラス
class ImageLoader
{
public:
	enum {
		MAX_SURFACES = 100	// 最大画像数
	};
private:
	ImageLoaderItem m_items[MAX_SURFACES];	// 画像データ
	int m_count;							// m_items内のカウント

public:
	// コンストラクタ
	ImageLoader();

	// デストラクタ
	~ImageLoader();

	// すべての画像を解放
	void Destroy();

	// サーフェスの追加登録
	// name : 画像名（検索用）
	// surface : SDLサーフェス（画像データが入っている状態であること）
	// xgridspan  : 画像内のチップ幅
	// ygridspan  : 画像内のチップ高さ
	// xgridcount : 画像内のチップのX方向の並び数（チップインデックスから位置を求めるために使用）
	// 返り値 : true : 成功　false : 失敗
	bool AddSurface(const char *name, SDL_Surface *surface, int xgridspan = 0, int ygridspan = 0, int xgridcount = 0 );

	// サーフェスの追加登録（ファイル名で登録）
	// name : 画像名（検索用）
	// filename : 画像ファイル名（SDL_imageがロード可能なもの：PNG, GIF, BMP等)
	// xgridspan  : 画像内のチップ幅
	// ygridspan  : 画像内のチップ高さ
	// xgridcount : 画像内のチップのX方向の並び数（チップインデックスから位置を求めるために使用）
	// 返り値 : true : 成功　false : 失敗
	bool AddSurfaceByFileName(const char *name, const char *filename, int xgridspan = 0, int ygridspan = 0, int xgridcount = 0 );

	// 画像アイテムを名前で取得
	ImageLoaderItem *GetItemByName(const char *name);

};

struct SpriteRect
{
	float x,y,w,h;
};


//
// class SpriteNode
//

// スプライトノードクラス
// ・モードにより以下の場合がある
//   - 画像モード     : 画像を表示
//   - テキストモード : テキストを表示
//   - 表示なしモード : 表示なし
// ・各ノードは独自の座標系（原点、拡大率）を持っている
// ・子ノードを持つことができる
// ・親ノードのスケールは子ノードに影響する
// ・子ノードの座標は親ノードのローカル座標系上の値になる

class SpriteNode
{
public:
	enum {
		MAX_TEXT_LEN = 200,	// 最大テキスト文字（バイト）数
	};

	enum ENUM_MODE {
		MODE_IMAGE,		// 画像モード
		MODE_TEXT,		// テキストモード
		MODE_NULL,		// 表示なしモード（子は描画対象になる）
	};

	enum ENUM_OP_TYPE {
		OP_NORMAL,		// 通常モード（テクスチャが透明度に応じて重ねあわされる）
		OP_ADD,			// 加算モード（テクスチャを重ねるほど白くなるモード。光の表現など）
	};

private:
	char m_imagename[MAX_PATH];	// 画像名（画像ローダーから検索用）
	ImageLoader *m_loader;		// 画像ローダー
	SDL_Surface *m_image;		// SDLサーフェス（テキストの場合はDrawThis内、画像の場合はFetchImage内でセットされる）
	GLuint m_texture;			// OpenGLテクスチャ（同）
	int m_texsize_w;	// テクスチャ幅
	int m_texsize_h;	// テクスチャ高さ

	ENUM_MODE m_mode;	// 描画モード(ENUM_MODEの値のどれか）

	bool m_show;		// 表示するかどうか（falseの場合、子ノードも表示しない）
	ENUM_OP_TYPE m_op_type;		// 描画時の演算タイプ
	int m_x;			// X座標：画像上のドット単位
	int m_y;			// Y座標：画像上のドット単位
	int m_z;			// Z座標：子ノード間の上下関係の決定に使用
	int m_xcenter;		// 拡大縮小の中心座標(X)
	int m_ycenter;		// 拡大縮小の中心座標(Y)
	float m_xscale;		// 拡大率(X方向)
	float m_yscale;		// 拡大率(Y方向)
	GLubyte m_color[4];	// 色および透明度 R,G,B,A(0〜255)

	int m_xgridspan;	// サーフェス内のキャラチップ配置間隔(X)
	int m_ygridspan;	// サーフェス内のキャラチップ配置間隔(Y)
	int m_xgridcount;	// サーフェス内のX方向のキャラチップ配置数
	int m_gridindex;	// 現在のキャラチップ番号

	int m_xchipspan;	// 1チップx1チップ以上の大きさの画像を使う場合のチップカウント(X方向)
	int m_ychipspan;	// 1チップx1チップ以上の大きさの画像を使う場合のチップカウント(Y方向)

	SpriteNode **m_children;	// 子ノードポインタ配列へのポインタ
	int m_child_count;			// 子ノード数
	int m_child_capacity;		// m_childrenで確保されている配列の要素数
	SpriteNode *m_parent;		// 親ノード

	char m_text[MAX_TEXT_LEN];	// テキスト表示用文字バッファ
	bool m_text_updated;		// テキストの内容が更新されたかどうかのフラグ
	TTF_Font *m_font;			// TrueTypeフォントオブジェクト
	SDL_Color m_textcolor;		// テキストの描画色

public:
	// コンストラクタ
	SpriteNode();
	// デストラクタ
	virtual ~SpriteNode();

	// ノードを削除する
	void Destroy();

	// 使用する画像ローダーをセット
	void SetImageLoader(ImageLoader *loader) {
		m_loader = loader;
	}

	// 画像名を取得
	const char *GetImageName() const {
		return m_imagename;
	}

	// 親ノードを取得
	SpriteNode *GetParent() const {
		return m_parent;
	}

	// 表示・非表示設定
	void Show(bool show) {
		m_show = show;
	}
	// 演算タイプを設定(SpriteNode::OP_NORMAL または SpriteNode::OP_ADD）
	void SetOpType(SpriteNode::ENUM_OP_TYPE op_type) {
		m_op_type = op_type;
	}
	// 指定座標に移動
	void MoveTo(int x, int y) {
		m_x = x;
		m_y = y;
	}
	// 指定した座標分だけ移動する
	void Offset(int x, int y) {
		m_x += x;
		m_y += y;
	}
	// 座標アクセサー関数
	int GetX() const {
		return m_x;
	}
	void SetX(int x) {
		m_x = x;
	}
	int GetY() const {
		return m_y;
	}
	void SetY(int y) {
		m_y = y;
	}
	int GetZ() const {
		return m_z;
	}
	void SetZ(int z) {
		m_z = z;
	}
	// 中心位置をセット（拡大・縮小および配置の基準位置として使用）
	void SetCenter(int x, int y) {
		m_xcenter = x;
		m_ycenter = y;
	}
	// 拡大率をセット
	// x,yそれぞれ設定可能。
	void SetScale(float x, float y) {
		m_xscale = x;
		m_yscale = y;
	}

	// 色をセット
	// （スプライトの色が全体的に変化します）
	void SetColor(float r, float g, float b, float a = 1.0) {
		m_color[0] = (GLubyte) ((r >= 1.0) ? 255 : r * 255);
		m_color[1] = (GLubyte) ((g >= 1.0) ? 255 : g * 255);
		m_color[2] = (GLubyte) ((b >= 1.0) ? 255 : b * 255);
		m_color[3] = (GLubyte) ((a >= 1.0) ? 255 : a * 255);
	}
	// 透明度をセット
	void SetAlpha(float alpha) {
		m_color[3] = (GLubyte) ((alpha >= 1.0) ? 255 : alpha * 255);
	}


	// 座標変換関数群
	// use_this_scaleがfalseならば、このスプライトのスケールは現在の値ではなく、1.0として計算される。

	// 親の座標系から自分の座標系に変換
	void TranslateParentToThis(float *x, float *y, bool use_this_scale = true);
	// 自分の座標系から親の座標系に変換
	void TranslateThisToParent(float *x, float *y, bool use_this_scale = true);
	// ルート（一番上の親）の座標系から自分の座標系に変換
	void TranslateRootToThis(float *x, float *y, bool use_this_scale = true);
	// 自分の座標系からルート（一番上の親）の座標系に変換
	void TranslateThisToRoot(float *x, float *y, bool use_this_scale = true);

	// 画像チップの格子情報を設定
	void SetChipGrid(int xspan, int yspan, int xcount) {
		m_xgridspan = xspan;
		m_ygridspan = yspan;
		m_xgridcount = xcount;
	}

	// チップ番号をセット
	void SetChipIndex(int index) {
		m_gridindex = index;
	}

	// 画像表示範囲の大きさ設定(2x2, 4x1 のように複数チップに渡る場合）
	// グリッド単位で指定。
	void SetChipSpan(int x_chipspan, int y_chipspan) {
		m_xchipspan = x_chipspan;
		m_ychipspan = y_chipspan;
	}

	/*
	// サーフェスをセットする
	// （サーフェスを「所有」するわけではないので、破棄などは行わない。）
	void SetSurface(SDL_Surface *image) {
		m_image = image;
	}
	SDL_Surface * GetSurface() {
		return m_image;
	}
	*/
	// OpenGLテクスチャIDを取得する
	GLuint GetTexture() {
		return m_texture;
	}

	// 画像名をセット
	// （画像ローダーから検索する時の名前）
	// さらに、現在のモードを画像モードに変更する
	// ついでに画像ローダーをセット可能（NULLならそのまま）
	void SetImageName(const char *name, ImageLoader *loader = NULL);

	// ローダーから画像を取ってくる
	// （SetImageNameでセットした画像名で検索する）
	bool FetchImage();

	// 子ノード関連

	// 子ノード数を取得
	int GetChildCount() const;

	// 子ノードのポインタをインデックス指定で取得
	// （削除等を行った場合、同じインデックスで同じノードが取れるわけではないので注意）
	SpriteNode *GetChildAt(int index);

	// 子ノードを追加
	bool AddChild(SpriteNode *chr);

	// 子ノードを削除
	// （配列の後ろの要素を詰める）
	bool RemoveChild(SpriteNode *chr);

	// 親ノードから切り離す
	bool RemoveFromParent();

	// テキスト関連

	// フォントを設定する
	// 同時に、テキストモードに変更する
	void SetFont(const char *fontname);

	// テキスト表示用文字列をセット
	// 同時に、テキストモードに変更する
	void SetText(const char *text);

	// テキストの色を設定
	void SetTextColor( unsigned int r, unsigned int g, unsigned int b);

	// クイックソート用
	// ノード同士をZ座標で比較する関数
	static int SortFunc(const void *a, const void *b) {
		return (*(SpriteNode **)a)->GetZ() - (*(SpriteNode **)b)->GetZ();
	}

	// 描画(OpenGL)
	void DrawGL(DrawSystem *ds, float xbase, float ybase, float xscale, float yscale, int level);

private:
	// このノードのみを描画するサブルーチン
	void DrawThis(DrawSystem *ds, float xbase, float ybase, float xbasescale, float ybasescale);

	// 子ノード配列のキャパシティを拡張
	void IncreaseChildrenCapacity();

};



// 描画システム
// ノードのポインタを保持して順番に描画するという程度のもの
class DrawSystem
{
public:
	enum {
		MAX_NODES = 3000, // ノード数の上限
	};

private:
	SpriteNode *m_nodes[MAX_NODES];
	int m_node_count;

	int m_screen_w;
	int m_screen_h;

	static SpriteNode *s_nodes_sort[MAX_NODES];

public:
	DrawSystem() : m_node_count(0) {}
	~DrawSystem() {}

	bool AddNode(SpriteNode *chr);

	bool RemoveNode(SpriteNode *chr);

	void SetScreenSize(int w,int h) {
		m_screen_w = w;
		m_screen_h = h;
	}
	void GetScreenSize(int &w, int &h) {
		w = m_screen_w;
		h = m_screen_h;
	}

	// 指定矩形が画面内に一部入るかどうかを返す
	bool IsIntersectScreen(SpriteRect *rect);

	void DrawGL();

};

#endif // _SPRITE_NODE_
#endif /* SPRITENODE_H_ */
