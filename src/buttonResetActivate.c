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
buttonResetActivate( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )

	{

	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;

	int i;
	for(i = 0; i < 5; i++)
	{
		if(playerSelect[i] != NULL)
		{
			PtSetResource(ButtonMatPlayer[playerSelect[i][0]][playerSelect[i][1]],Pt_ARG_FILL_COLOR,Pg_DBLUE,0);
			playerSelect[i] = NULL;
		}
	}

	return( Pt_CONTINUE );

	}

