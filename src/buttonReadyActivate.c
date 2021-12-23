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
#include <photon/PtTimer.h>
#include "abimport.h"
#include "proto.h"
#include "global.h"

char** split(char* string, int* finalSize, int splitMaxSize);
int timerCallback ( PtWidget_t *, void *, PtCallbackInfo_t * );

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
				PtSetResource(widget,Pt_ARG_TEXT_STRING,"Give up",0);
				PtSetResource(ABW_tbStatus,Pt_ARG_TEXT_STRING,status,0);
				PtSetResource(ABW_tbGameState,Pt_ARG_TEXT_STRING, "Game state: Battle",0);
				PtSetResource(ABW_tbPrompt,Pt_ARG_TEXT_STRING,"Hint: Select the cell on enemy field and hit Attack!",0);


				PtArg_t  argt[3];
				PtCallback_t timerCallbackStructure[] = {{timerCallback, NULL}};

				PtSetArg( &argt[0], Pt_ARG_TIMER_INITIAL, 100, 0 );
				PtSetArg( &argt[1], Pt_ARG_TIMER_REPEAT, 100, 0 );
				PtSetArg( &argt[2], Pt_CB_TIMER_ACTIVATE, timerCallbackStructure, 0 );
				timer = PtCreateWidget(PtTimer,ABW_base,3,argt);
				PtRealizeWidget(timer);

			}
			else
			{
				PtSetResource(ABW_tbStatus,Pt_ARG_TEXT_STRING,"Status: Something failed",0);
			}
			return( Pt_CONTINUE );
		}
	}
	else if(gameState == 1)
	{
		PtSetResource(ABW_tbPrompt,Pt_ARG_TEXT_STRING,"Hint: Set up your field first",0);
	}
	else if(gameState == 3)
	{
		sprintf(smsg,"Surrender");
		MsgSend(coid, smsg, strlen(smsg) + 1, rmsg, sizeof(rmsg));
	}

	return( Pt_CONTINUE );

}

int timerCallback ( PtWidget_t * widget, void * data, PtCallbackInfo_t * info)
{
	char* smsg = (char*) malloc(sizeof(char) * 512);
	char rmsg[512];
	sprintf(smsg,"Info");
	MsgSend(coid, smsg, strlen(smsg) + 1, rmsg, sizeof(rmsg));
	if(strcmp(rmsg,"NoInfo") == 0)
	{
		return( Pt_CONTINUE );
	}
	else
	{
		int size;
		char** spl = split(rmsg, &size, 512);
		int winCondition = spl[2][0] - '0';
		printf("WIN CONDITION = %d\n",winCondition);
		if(winCondition != 0)
		{
			ResetGame(winCondition);
		}
		else
		{
			int eHit = spl[0][0] - '0';

			int* eCell = (int*) malloc (sizeof(int) * 2); eCell[0] = spl[1][0] - '0'; eCell[1] = spl[1][1] - '0';

			if(eHit == 1)
			{
				//Pg_VGA6
				PtSetResource(ButtonMatPlayer[eCell[0]][eCell[1]],Pt_ARG_FILL_COLOR,Pg_BLACK,0);
				PtSetResource(ABW_tbPrompt,Pt_ARG_TEXT_STRING,"Enemy made his move! Hit!",0);
			}
			else
			{
				//Pg_VGA4
				PtSetResource(ButtonMatPlayer[eCell[0]][eCell[1]],Pt_ARG_FILL_COLOR,Pg_GRAY,0);
				PtSetResource(ABW_tbPrompt,Pt_ARG_TEXT_STRING,"Enemy made his move! Miss!",0);
			}
		}
	}
	return( Pt_CONTINUE );
}
