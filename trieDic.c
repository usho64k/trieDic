#include <stdio.h>
#include <string.h>
#include "trieDic.h"

#define TRIEDIC_CHARS	26
#define TRIEDIC_NUMS	10

#define TRIEDIC_ALLCHARS	TRIEDIC_CHARS + TRIEDIC_NUMS + 1

#define MAX_LEN			2048

static int triedic_tree[MAX_LEN][TRIEDIC_ALLCHARS];
static int triedic_len;

typedef enum E_CODE{
	SMALL_CHAR,
	LARGE_CHAR,
	NUMBERS,
	SHARP,
	NO_DEF
}E_CODES;

E_CODES getCode(char c);
static int triedic_get(int arg,char c);
static void triedic_set(int arg,char c);

void triedic_init(void)
{
	memset(triedic_tree,0,TRIEDIC_ALLCHARS *  MAX_LEN);
	triedic_len = 0;
}

E_CODES getCode(char c)
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
			return 1;
		else
			return -1;
	default:
		return 0;
	}
}

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
		triedic_tree[arg][36] = ++triedic_len;
		break;
	default:
		break;
	}
}

void triedic_record(char *str)
{
	int cnt = 0;
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
}

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
