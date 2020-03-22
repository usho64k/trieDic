#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "trieDic.h"


int main(void)
{
	//以下デバッグ用コード
	triedic_init();
	triedic_record("AIUEO#");
	triedic_record("kakiikukeko#");
	triedic_record("atawana#");
	triedic_show();
}
