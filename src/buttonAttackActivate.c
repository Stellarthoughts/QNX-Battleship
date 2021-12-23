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

#include "globalFunctions.h"

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
			PtSetResource(ButtonMatEnemy[enemySelect[0][0]][enemySelect[0][1]],Pt_ARG_FILL_COLOR,Pg_VGA4,0);
			sprintf(smsg, "%d%d", enemySelect[0][0], enemySelect[0][1]);
			MsgSend(coid, smsg, strlen(smsg) + 1, rmsg, sizeof(rmsg));
			if(strcmp(rmsg,"Turn") == 0)
			{
				PtSetResource(ABW_tbPrompt,Pt_ARG_TEXT_STRING,"Not your turn!",0);
				return( Pt_CONTINUE );
			}

			enemySelect[0] = NULL;
			printf("%s\n",rmsg);
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
				int pHit = spl[0][0] - '0';

				int* pCell = (int*) malloc (sizeof(int) * 2); pCell[0] = spl[1][0] - '0'; pCell[1] = spl[1][1] - '0';

				enemyHit[hits] = pCell;
				hits++;

				if(pHit == 1)
				{
					//Pg_CYAN
					PtSetResource(ButtonMatEnemy[pCell[0]][pCell[1]],Pt_ARG_FILL_COLOR,Pg_BLACK,0);
					PtSetResource(ABW_tbPrompt,Pt_ARG_TEXT_STRING,"Hit!",0);
				}
				else
				{
					//Pg_DBLUE
					PtSetResource(ButtonMatEnemy[pCell[0]][pCell[1]],Pt_ARG_FILL_COLOR,Pg_GRAY,0);
					PtSetResource(ABW_tbPrompt,Pt_ARG_TEXT_STRING,"Miss!",0);
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
