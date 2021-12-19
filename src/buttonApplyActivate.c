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
				return( Pt_CONTINUE );
			}
		}
		PtUnrealizeWidget(ABW_btnReset);
		PtUnrealizeWidget(widget);
		gameState = 2;
		printf("GameState = FIELD FILLED\n");
	}


	return( Pt_CONTINUE );

	}

