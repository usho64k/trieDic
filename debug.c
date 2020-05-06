#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "trieDic.h"


int main(void)
{
	//以下デバッグ用コード
	triedic_init();
	//回復呪文
	printf("getID[hoimi]		: %d\r\n",triedic_record("hoimi#"));
	printf("getID[behoimi]		: %d\r\n",triedic_record("behoimi#"));
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
}
