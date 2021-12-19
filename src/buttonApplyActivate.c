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
buttonApplyActivate( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )

	{

	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;

	if(gameState == 1)
	{
		int i;
		for(i = 0; i < 5; i++)
		{
			if(playerSelect[i] == NULL)
			{
				PtSetResource(ABW_tbPrompt, Pt_ARG_TEXT_STRING, "Hint: You must place 5 ships before applying", 0);
				return( Pt_CONTINUE );
			}
		}
		PtUnrealizeWidget(ABW_btnReset);
		PtUnrealizeWidget(widget);
		gameState = 2;
		PtSetResource(ABW_tbPrompt, Pt_ARG_TEXT_STRING, "Hint: Connect to server, then hit Ready", 0);
		PtSetResource(ABW_tbGameState, Pt_ARG_TEXT_STRING, "Game state: Field filled", 0);
		printf("GameState = FIELD FILLED\n");
	}


	return( Pt_CONTINUE );

	}

