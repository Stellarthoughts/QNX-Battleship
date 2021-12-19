/* Y o u r   D e s c r i p t i o n                       */
/*                            AppBuilder Photon Code Lib */
/*                                         Version 2.03  */

/* Standard headers */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Local headers */
#include "ablibs.h"
#include "abimport.h"
#include "proto.h"
#include "global.h"


int
buttonAttackActivate( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;

	char* smsg = (char*) malloc(sizeof(char) * 512);
	char rmsg[512];

	if(gameState == 3)
	{
		if(enemySelect[0] == NULL)
		{
			PtSetResource(ABW_tbPrompt,Pt_ARG_TEXT_STRING,"Hint: You should select the enemy cell first!",0);
		}
		else
		{
			sprintf(smsg, "%d%d", enemySelect[0][0], enemySelect[0][1]);
			MsgSend(coid, smsg, strlen(smsg) + 1, rmsg, sizeof(rmsg));
			printf("%s\n",rmsg);
			return( Pt_CONTINUE );
		}
	}
	else
	{
		PtSetResource(ABW_tbPrompt,Pt_ARG_TEXT_STRING,"Hint: Hey! You're not in game or it's already finished",0);
	}

	return( Pt_CONTINUE );
}

