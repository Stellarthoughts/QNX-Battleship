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

char** split(char* string, int* finalSize, int splitMaxSize);

int buttonReadyActivate( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;

	char* smsg = (char*) malloc(sizeof(char) * 512);
	char rmsg[512];

	if(gameState == 2)
	{
		if(coid == -1)
		{
			PtSetResource(ABW_tbPrompt,Pt_ARG_TEXT_STRING,"Hint: You should connect to server first",0);
		}
		else
		{
			sprintf(smsg,"Ready ");
			int i;
			for(i = 0; i < 5; i++)
			{
				char* add = (char*) malloc(sizeof(char) * 255);
				if(i == 4)
				{
					sprintf(add, "%d%d", playerSelect[i][0], playerSelect[i][1]);
				}
				else
				{
					sprintf(add, "%d%d ", playerSelect[i][0], playerSelect[i][1]);
				}
				strcat(smsg, add);
			}
			printf("%s\n",smsg);

			MsgSend(coid, smsg, strlen(smsg) + 1, rmsg, sizeof(rmsg));
			int size;
			char** spl = split(rmsg,&size,512);
			printf("Server message : %s\n",rmsg);
			if(strcmp(spl[0],"Player") == 0)
			{
				playerNum = atoi(spl[1]);
				char* status = (char*) malloc(sizeof(char) * 50);
				sprintf(status,"Status: Player %d",playerNum);
				gameState = 3;
				PtSetResource(ABW_tbStatus,Pt_ARG_TEXT_STRING,status,0);
				PtSetResource(ABW_tbGameState,Pt_ARG_TEXT_STRING, "Game state: Battle",0);
				PtSetResource(ABW_tbPrompt,Pt_ARG_TEXT_STRING,"Hint: Select the cell on enemy field and hit Attack!",0);
				PtUnrealizeWidget(widget);
			}
			else
			{
				PtSetResource(ABW_tbStatus,Pt_ARG_TEXT_STRING,"Status: Something failed",0);
			}
			return( Pt_CONTINUE );
		}
	}
	else
	{
		PtSetResource(ABW_tbPrompt,Pt_ARG_TEXT_STRING,"Hint: Set up your field first",0);
	}

	return( Pt_CONTINUE );

}

char** split(char* string, int* finalSize, int splitMaxSize)
{
	char *copy = strdup(string);
	char **spl = (char**) malloc(sizeof(char*) * 512);
	int n = 0;
	char *single = strtok_r(copy," ",&string);
	while(single != NULL)
	{
		//realloc(spl,(n+1) * sizeof(char*));
		spl[n] = strdup(single);
		single = strtok_r(NULL," ",&string);
		n++;
	}
	free(single);
	*finalSize = n;
	return spl;
}
