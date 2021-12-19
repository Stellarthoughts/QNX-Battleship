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


int
buttonExitActivate( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{

/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;

	char ndString[512];
	pid_t spid;
	int chid;
	int coid;

	char* localname = "tempInfo.txt";
	FILE *f = fopen(localname,"r");
	if(f)
	{
		fscanf(f, "%s %d %d %d",&ndString,&spid,&chid,&coid);
		ConnectDetach(coid);
		fclose(f);
		remove(localname);
	}

	exit(0);

	return( Pt_CONTINUE );

}
