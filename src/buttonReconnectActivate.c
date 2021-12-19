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


int
buttonReconnectActivate( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	/* eliminate 'unreferenced' warnings */
	printf("ReconnectActivate\n");
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;

	char ndString[512];
	pid_t spid;
	int chid;
	int coid;

	FILE* f;

	// Read local data
	char* localname = "tempInfo.txt";
	f = fopen(localname,"r");
	if(f)
	{
		fscanf(f, "%s %d %d %d",&ndString,&spid,&chid,&coid);
		ConnectDetach(coid);
		fclose(f);
		remove(localname);
	}

	// Read server data
	char* filename = "/prog/lab8/serverInfo.txt";
	f = fopen(filename,"r");
	if(!f)
	{
		PtSetResource(ABW_tbStatus,Pt_ARG_TEXT_STRING,"Status: Connection error.\nBad server info file",0);
		return( Pt_CONTINUE );
	}
	fscanf(f, "%s %d %d",&ndString,&spid,&chid);
	int nd = netmgr_strtond(&ndString,NULL);
	fclose(f);

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

	// connected message
	char* formatted = (char*) calloc (sizeof(char),100);
	sprintf(formatted,"Connected!\nND: %s\nSPID: %d\nCHID: %d\nCOID: %d",ndString,spid,chid,coid);
	//PtSetResource(ABW_tbOutput,Pt_ARG_TEXT_STRING,formatted,0);
	free(formatted);

	// Saving data about channel
	f = fopen(localname,"w");
	if(!f)
	{
		PtSetResource(ABW_tbStatus,Pt_ARG_TEXT_STRING,"Status: Error\nCan't save server data",0);
		return( Pt_CONTINUE );
	}
	else
	{
		fprintf(f,"%s\n%d\n%d\n%d",ndString,spid,chid,coid);
	}
	fclose(f);

	return( Pt_CONTINUE );

}
