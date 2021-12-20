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
			return( Pt_CONTINUE );
		}
		else
		{
			sprintf(smsg, "%d%d", enemySelect[0][0], enemySelect[0][1]);
			MsgSend(coid, smsg, strlen(smsg) + 1, rmsg, sizeof(rmsg));
			enemySelect[0] = NULL;
			printf("%s\n",rmsg);
			int size;
			char** spl = split(rmsg, &size, 512);
			int winCondition = spl[4][0] - '0';
			printf("WIN CONDITION = %d\n",winCondition);
			if(winCondition != 0)
			{
				gameState = 1;
				if(winCondition == playerNum)
				{
					PtSetResource(ABW_tbPrompt,Pt_ARG_TEXT_STRING,"You won!",0);
				}
				else
				{
					PtSetResource(ABW_tbPrompt,Pt_ARG_TEXT_STRING,"You lost!",0);
				}
				PtSetResource(ABW_tbGameState,Pt_ARG_TEXT_STRING, "Game state: Preparing",0);
				PtRealizeWidget(ABW_btnReady);
				PtRealizeWidget(ABW_btnReset);
				PtRealizeWidget(ABW_btnApply);
			}
			else
			{
				int pHit = spl[0][0] - '0';
				int eHit = spl[2][0] - '0';

				int* pCell = (int*) malloc (sizeof(int) * 2); pCell[0] = spl[1][0] - '0'; pCell[1] = spl[1][1] - '0';
				int* eCell = (int*) malloc (sizeof(int) * 2); eCell[0] = spl[3][0] - '0'; eCell[1] = spl[3][1] - '0';
				//printf("%d %d %d %d\n",pCell[0],pCell[1],eCell[0],eCell[1]);

				enemyHit[hits] = pCell;
				hits++;

				if(pHit == 1)
				{
					PtSetResource(ButtonMatEnemy[pCell[0]][pCell[1]],Pt_ARG_FILL_COLOR,Pg_CYAN,0);
				}
				else
				{
					PtSetResource(ButtonMatEnemy[pCell[0]][pCell[1]],Pt_ARG_FILL_COLOR,Pg_DBLUE,0);
				}
				if(eHit == 1)
				{
					PtSetResource(ButtonMatPlayer[eCell[0]][eCell[1]],Pt_ARG_FILL_COLOR,Pg_VGA6,0);
				}
				else
				{
					PtSetResource(ButtonMatPlayer[eCell[0]][eCell[1]],Pt_ARG_FILL_COLOR,Pg_VGA4,0);
				}
			}

			return( Pt_CONTINUE );
		}
	}
	else
	{
		PtSetResource(ABW_tbPrompt,Pt_ARG_TEXT_STRING,"Hint: Hey! You're not in game or it's already finished",0);
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
