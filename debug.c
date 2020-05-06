#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "trieDic.h"


int main(void)
{
	//以下デバッグ用コード
	triedic_init();
	printf("getID[AIUEO]       : %d\r\n",triedic_record("AIUEO#"));
	printf("getID[kakiikukeko] : %d\r\n",triedic_record("kakiikukeko#"));
	printf("getID[atawana]     : %d\r\n",triedic_record("atawana#"));
	triedic_show();
}
