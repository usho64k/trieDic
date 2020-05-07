#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "trieDic.h"
#include "strCount.h"

unsigned char hand_chsA[80];
unsigned char hand_chsB[80];
unsigned char area_chs[400];

const char dq1_usable_chars[30][2] = 
{"01","0i","0n","ka","ki",
"ko","si","su","ta","to",
"he","ho","ma","mi","mu",
"me","ra","ri","ru","re","ro",
"ga","gi","go","ji","zu","da","do",
"be","bo"};


int main(void)
{
	int i;

	initCnts();

	//手札
	for(i = 0; i < 80; i++){
		hand_chsA[i] = 0x00;		//手札Aの1枚目
		hand_chsB[i] = 0x00;		//手札Bの1枚目
	}

	//山札
	for(i = 0; i < 400; i++)
	{
		area_chs[i] = 0x00;			//山札
	}
	
	

	//以下デバッグ用コード
	triedic_init();

	//回復呪文
	printf("getID[ho0imi]		: %d\r\n",triedic_record("ho0imi#"));
	printf("getID[beho0imi]		: %d\r\n",triedic_record("beho0imi#"));
	printf("getID[behoma]		: %d\r\n",triedic_record("behoma#"));
	printf("getID[behomara01]	: %d\r\n",triedic_record("behomara01#"));
	printf("getID[behomazu0n]	: %d\r\n",triedic_record("behomazu0n#"));

	//攻撃呪文
	printf("getID[mera] 		: %d\r\n",triedic_record("mera#"));
	printf("getID[merami]		: %d\r\n",triedic_record("merami#"));
	printf("getID[gira] 		: %d\r\n",triedic_record("gira#"));
	printf("getID[begirama]		: %d\r\n",triedic_record("begirama#"));
	printf("getID[begirago0n]	: %d\r\n",triedic_record("begirago0n#"));
	printf("getID[doruma]		: %d\r\n",triedic_record("doruma#"));
	printf("getID[dorumado0n]	: %d\r\n",triedic_record("dorumado0n#"));

	//補助呪文
	printf("getID[toherosu]		: %d\r\n",triedic_record("toherosu#"));
	//printf("getID[ru01ra]		: %d\r\n",triedic_record("ru01ra#"));
	//printf("getID[riremito]		: %d\r\n",triedic_record("riremito#"));
	//printf("getID[remi01ra]		: %d\r\n",triedic_record("remi01ra#"));
	printf("getID[doragoramu]	: %d\r\n",triedic_record("doragoramu#"));
	//printf("getID[remira01ma]	: %d\r\n",triedic_record("remira01ma#"));
	printf("getID[sukara]		: %d\r\n",triedic_record("sukara#"));
	printf("getID[mahoto010n]	: %d\r\n",triedic_record("mahoto010n#"));
	printf("getID[mahotora]		: %d\r\n",triedic_record("mahotora#"));
	printf("getID[mahoka0nta]	: %d\r\n",triedic_record("mahoka0nta#"));
	printf("getID[mahota010n]	: %d\r\n",triedic_record("mahota010n#"));

	//妨害呪文
	printf("getID[rariho01]		: %d\r\n",triedic_record("rariho01#"));
	printf("getID[rariho01ma]	: %d\r\n",triedic_record("rariho01ma#"));

	triedic_show();

	setCnts("ho0imi#");
	setCnts("beho0imi#");
	setCnts("behoma#");
	setCnts("behomara01#");
	setCnts("behomazu0n#");

	setCnts("mera#");
	setCnts("merami#");
	setCnts("gira#");
	setCnts("begirama#");
	setCnts("begirago0n#");
	setCnts("doruma#");
	setCnts("dorumado0n#");

	setCnts("toherosu#");
	setCnts("doragoramu#");
	setCnts("sukara#");
	setCnts("mahoto010n#");
	setCnts("mahotora#");
	setCnts("mahoka0nta#");
	setCnts("mahota010n#");

	setCnts("rariho01#");
	setCnts("rariho01ma#");

	printf("\r\n");
	for(i = 0; i < 30; i++)
	{
		printf("%c%c %d,",dq1_usable_chars[i][0],dq1_usable_chars[i][1],getCnts(dq1_usable_chars[i][0],dq1_usable_chars[i][1]));
	}
	printf("\r\n");

}
