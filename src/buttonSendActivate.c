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


/* Standard headers */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* User headers */
#include <sys/neutrino.h>
#include <Ap.h>
#include <Pt.h>
#include <Ph.h>
#include <time.h>
#include <errno.h>
#include <signal.h>

/* Local headers */
#include "ablibs.h"
#include "abimport.h"
#include "proto.h"

char rmsg[512];
int coid;

struct itimerspec timerFirst;
struct itimerspec timerSecond;
timer_t timeridFirst;
timer_t timeridSecond;

int sendToServer(char* message);

int
buttonSendActivate( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	//printf("%d",3);
	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;

	// Read info
	/*FILE* f;
	char ndString[512];
	pid_t spid;
	int chid;

	char* localname = "tempInfo.txt";
	f = fopen(localname,"r");
	if(!f)
	{
		PtSetResource(ABW_tbOutput,Pt_ARG_TEXT_STRING,"Error. Cannot read local info file.\nReconnect.",0);
		return( Pt_CONTINUE );
	}
	else
	{
		fscanf(f, "%s%d%d%d",&ndString,&spid,&chid,&coid);
		fclose(f);
	}

	// Setup timers
	timerFirst.it_value.tv_sec = 3;
	timerFirst.it_value.tv_nsec = 0;
	timerFirst.it_interval.tv_sec = 3;
	timerFirst.it_interval.tv_nsec = 0;

	timerSecond.it_value.tv_sec = 4;
	timerSecond.it_value.tv_nsec = 440000000;
	timerSecond.it_interval.tv_sec = 4;
	timerSecond.it_interval.tv_nsec = 440000000;

	// Input
	char* smsg;
	PtGetResource(ABW_tbInput,Pt_ARG_TEXT_STRING,&smsg,0);
	if(strlen(smsg) == 0) return( Pt_CONTINUE );

	// Command
	if(strcmp(smsg,"signal") == 0)
	{
		sigset_t setFirst;
		sigset_t setSecond;

		sigemptyset(&setFirst);
		sigaddset(&setFirst,SIGUSR1);
		sigemptyset(&setSecond);
		sigaddset(&setSecond,SIGUSR2);

		extern void handler();

		struct sigaction actFirst;
		struct sigaction actSecond;

		actFirst.sa_flags = 0;
		actFirst.sa_mask = setFirst;
		actFirst.sa_handler = &handler;

		actSecond.sa_flags = 0;
		actSecond.sa_mask = setSecond;
		actSecond.sa_handler = &handler;

		sigaction(SIGUSR1, &actFirst, NULL);
		sigaction(SIGUSR2, &actSecond, NULL);

		struct sigevent eventFirst;
		SIGEV_SIGNAL_INIT(&eventFirst,SIGUSR1);

		struct sigevent eventSecond;
		SIGEV_SIGNAL_INIT(&eventSecond,SIGUSR2);

		if(timer_create(CLOCK_REALTIME,&eventFirst,&timeridFirst) == -1)
		{
			printf("%s: cannot create timer 1 (%d)\n","TM",errno);
		}

		if(timer_create(CLOCK_REALTIME,&eventSecond,&timeridSecond) == -1)
		{
			printf("%s: cannot create timer 2 (%d)\n","TM",errno);
		}

		timer_settime(timeridFirst,0,&timerFirst,NULL);
		timer_settime(timeridSecond,0,&timerSecond,NULL);
	}
	else if(strcmp(smsg,"stop_signal") == 0)
	{
		timer_delete(timeridFirst);
		timer_delete(timeridSecond);
	}

	// send message
	int sended = sendToServer(smsg);

	if(strlen(rmsg) > 0 && sended == 0)
	{
		PtSetResource(ABW_tbOutput,Pt_ARG_TEXT_STRING,rmsg,0);
	}*/

	return( Pt_CONTINUE );
}

int sendToServer(char* message)
{
	/*PtSetResource(ABW_tbStatus,Pt_ARG_TEXT_STRING,"Status: Waiting for an answer...",0);

	if(MsgSend(coid,message,strlen(message)+1,rmsg,sizeof(rmsg)) == -1)
	{
		PtSetResource(ABW_tbOutput,Pt_ARG_TEXT_STRING,"Error. Could not send message",0);
		PtSetResource(ABW_tbStatus,Pt_ARG_TEXT_STRING,"Status: Connection error",0);
		return -1;
	}
	else
	{
		PtSetResource(ABW_tbStatus,Pt_ARG_TEXT_STRING,"Status: Connected to server",0);
	}
	return 0;*/
}

void handler(int signo)
{
	char* message = (char*) calloc(sizeof(char),512);
	sprintf(message,"Timer has fired. Signo - %d",signo);
	sendToServer(message);
	free(message);
}
