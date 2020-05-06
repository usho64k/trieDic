#include <stdio.h>
#include <string.h>
#include "trieDic.h"

#define TRIEDIC_CHARS	26
#define TRIEDIC_NUMS	10

#define TRIEDIC_ALLCHARS	TRIEDIC_CHARS + TRIEDIC_NUMS + 1

#define MAX_LEN			2048

static int triedic_tree[MAX_LEN][TRIEDIC_ALLCHARS];
static int triedic_len;

static int triedic_id_max;

//文字タイプ
typedef enum E_CODE{
	SMALL_CHAR,		//アルファベット小文字
	LARGE_CHAR,		//アルファベット大文字
	NUMBERS,		//数字
	SHARP,			//シャープ(終了記号)
	NO_DEF			//未定義(その他)
}E_CODES;

static E_CODES getCode(char c);					//文字種取得
static int triedic_get(int arg,char c);			//文字列一致 1文字分
static void triedic_set(int arg,char c);		//文字列設定 1文字分

//trie木の初期化
void triedic_init(void)
{
	memset(triedic_tree,0,TRIEDIC_ALLCHARS *  MAX_LEN);
	triedic_len = 0;
	triedic_id_max = 1;
}

//文字種の取得
static E_CODES getCode(char c)
{
	if(c >= 0x61 && c <= 0x7A)
		return SMALL_CHAR;
	else if(c >= 0x41 && c <= 0x5A)
		return LARGE_CHAR;
	else if(c >= 0x30 && c <= 0x39)
		return NUMBERS;
	else if(c == '#')
		return SHARP;
	else
		return NO_DEF;	
}

//トライ木へのreadアクセス
//arg：検索したい順列番号
//c：検索したい文字列からピックアップした1文字
//文字cが木構造中の経路に存在する場合は、木構造ポインタ番号を返し、なければ-1を返す
static int triedic_get(int arg,char c)
{
	switch(getCode(c))
	{
	case SMALL_CHAR:
		if(triedic_tree[arg][c - 0x61] != 0)
			return triedic_tree[arg][c - 0x61];
		else
			return -1;
	case LARGE_CHAR:
		if(triedic_tree[arg][c - 0x41] != 0)
			return triedic_tree[arg][c - 0x41];
		else
			return -1;
	case NUMBERS:
		if(triedic_tree[arg][c - 0x30] != 0)
			return triedic_tree[arg][c - 0x30 + 26];
		else
			return -1;
	case SHARP:
		if(triedic_tree[arg][36] != 0)
			return triedic_tree[arg][36];
		else
			return -1;
	default:
		return 0;
	}
}

//トライ木へのwriteアクセス
//arg：追加したい列番号
//c：追加する文字
//文字cをarg番目の配列の次のポインタを設定し、新たな文字を追加する
//追加することが確定してからコールすること
static void triedic_set(int arg,char c)
{
	switch(getCode(c))
	{
	case SMALL_CHAR:
		triedic_tree[arg][c - 0x61] = ++triedic_len;
		break;
	case LARGE_CHAR:
		triedic_tree[arg][c - 0x41] = ++triedic_len;
		break;
	case NUMBERS:
		triedic_tree[arg][c - 0x30] = ++triedic_len;
		break;
	case SHARP:
		triedic_tree[arg][36] = triedic_id_max++;
		++triedic_len;
		break;
	default:
		break;
	}
}

//トライ木へのwriteアクセス
//文字列の登録
int triedic_record(char *str)
{
	int cnt = 0;
	//#は終了記号
	while(*str != '#')
	{
		if(triedic_get(cnt,*str) >= 0)
		{
			cnt = triedic_get(cnt,*str);
		}
		else
		{
			triedic_set(cnt,*str);
			cnt = triedic_len;
		}
		str++;
	}
	if(triedic_get(cnt,*str) != 1)
		triedic_set(cnt,'#');

	return triedic_id_max - 1;	//登録するとid_maxが1増加するので、直前の値を返す
}

//トライ木へのreadアクセス
//文字列の検索
//登録IDを返す
int triedic_search(char *str)
{
	int cnt = 0;
	int ret = 0;
	while(*str != '#')
	{
		if(triedic_get(cnt,*str) >= 0)
		{
			cnt = triedic_get(cnt,*str);
		}
		else
		{
			ret = -1;
		}
	}
	if(triedic_get(cnt,*str) == -1)
		ret = -1;
	return ret;
}

void triedic_show(void)
{
	int i,j;
	printf("   :  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  #\n");
	for(i = 0; i < 50; i++)
	{
		printf(" %2d:",i);
		for(j = 0; j < TRIEDIC_ALLCHARS; j++)
		{
			printf(" %2d",triedic_tree[i][j]);
		}
		printf("\n");
	}
}
