#include "strCount.h"

unsigned int cnt_all[36][36];
char getPtr(char c);

void initCnts(void)
{
	int i,j;
	for(i = 0; i < 36; i++)
	{
		for(j = 0; j < 36; j++)
		{
			cnt_all[i][j] = 0;
		}
	}
}

char getPtr(char c)
{
	if((c >= 0x30) && (c <= 0x39))
	{
		return (c - 0x30 + 26);
	}
	else if((c >= 0x41) && (c <= 0x5A))
	{
		return (c - 0x41);
	}
	else if((c >= 0x61) && (c <= 0x7A))
	{
		return (c - 0x61);
	}
	else
	{
		return 0;
	}

}

void setCnts(char *str)
{
	char c1;
	char c2;
	while(((c1 = *str) != '#') && ((c2 = *(str + 1)) != '#'))
	{
		cnt_all[getPtr(c1)][getPtr(c2)]++;
		str+=2;
	}
}

int getCnts(char c1,char c2)
{
	return cnt_all[getPtr(c1)][getPtr(c2)];
}
