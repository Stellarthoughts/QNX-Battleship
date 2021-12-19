/* Y o u r   D e s c r i p t i o n                       */
/*                            AppBuilder Photon Code Lib */
/*                                         Version 2.03  */

/* Standard headers */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* User headers */
#include <errno.h>
#include <sys/neutrino.h>
#include <sys/siginfo.h>

/* Local headers */
#include "ablibs.h"
#include "abimport.h"
#include "proto.h"
#include "global.h"

int
buttonReconnectActivate( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	/* eliminate 'unreferenced' warnings */
	printf("ReconnectActivate\n");
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;

	FILE* f;

	// Read server data
	char* filename = "serverInfo.txt";
	f = fopen(filename,"r");
	if(!f)
	{
		PtSetResource(ABW_tbStatus,Pt_ARG_TEXT_STRING,"Status: Connection error. Bad server info file",0);
	}
	else
	{
		fscanf(f, "%s %d %d",&ndString,&spid,&chid);
		int nd = netmgr_strtond(&ndString,NULL);
		fclose(f);
		hasServerData = 1;
	}

	if(hasServerData == 0)
	{
		return( Pt_CONTINUE );
	}

	// Connect to channel
	coid = ConnectAttach(0, spid, chid, 0, 0);
	if(coid == -1)
	{

		PtSetResource(ABW_tbStatus,Pt_ARG_TEXT_STRING,"Status: ConnectAttach error",0);
		return( Pt_CONTINUE );
	}
	else
	{
		PtSetResource(ABW_tbStatus,Pt_ARG_TEXT_STRING,"Status: Connected to server",0);
	}

	return( Pt_CONTINUE );
}
