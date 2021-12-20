/* Y o u r   D e s c r i p t i o n                       */
/*                            AppBuilder Photon Code Lib */
/*                                         Version 2.03  */

/* Standard headers */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

/* Local headers */
#include "ablibs.h"
#include "abimport.h"
#include "proto.h"
#include "global.h"
#include <photon/Pg.h>

int PlayerButtonPress (PtWidget_t *widget, void *data, PtCallbackInfo_t *info);
int EnemyButtonPress (PtWidget_t *widget, void *data, PtCallbackInfo_t *info);

int
windowOpened( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{

/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	printf("WindowOpened\n");
	gameState = 0;
	printf("GameState = STARTING\n");
	PtSetResource(ABW_tbGameState, Pt_ARG_TEXT_STRING, "Game state: Starting", 0);

	PhPoint_t pos;
	PhDim_t size;
	PtArg_t  argt[4];
	PtSetArg( &argt[0], Pt_ARG_POS, &pos, 0 );
	PtSetArg( &argt[1], Pt_ARG_DIM, &size, 0 );

	/*PtWidget_t* gridPlayer = ABW_gridPlayer;
	PhPoint_t gridPoint;
	PhDim_t gridDim;
	PtGetResource(gridPlayer,Pt_ARG_POS,&gridPoint,0);
	PtGetResource(gridPlayer,Pt_ARG_DIM,&gridDim,0);*/

	// Init arrays
	playerSelect = (int**) malloc(5 * sizeof(int*));
	enemySelect = (int**) malloc(1 * sizeof(int*));
	enemyHit = (int**) malloc(25 * sizeof(int*));

	int i,j;

	// Player
	PtSetArg( &argt[3], Pt_ARG_FILL_COLOR, Pg_DBLUE, 0 );
	ButtonMatPlayer = (PtWidget_t***) malloc(gridRows * sizeof(PtWidget_t**));
	for(i = 0; i < gridRows; i++)
	{
		ButtonMatPlayer[i] = (PtWidget_t**) malloc(gridRows * sizeof(PtWidget_t**));
		for(j = 0; j < gridCols; j++)
		{
			pos.x = gridPlayerX + j * cellSize + buttonPadding;
			pos.y = gridPlayerY + i * cellSize + buttonPadding;
			size.w = cellSize - 2 * buttonPadding;
			size.h = cellSize - 2 * buttonPadding;

			int* cell = (int*) malloc(sizeof(int) * 2); cell[0] = i; cell[1] = j;
			PtSetArg( &argt[2], Pt_ARG_TEXT_STRING, "", 0 );

			PtWidget_t* wid = PtCreateWidget(PtButton,widget,4,argt);
			PtAddEventHandler(wid,Ph_EV_BUT_PRESS,&PlayerButtonPress,(void*) cell);

			PtRealizeWidget(wid);
			ButtonMatPlayer[i][j] = wid;
		}
	}

	// Enemy
	PtSetArg( &argt[3], Pt_ARG_FILL_COLOR, Pg_VGA4, 0 );
	ButtonMatEnemy = (PtWidget_t***) malloc(gridRows * sizeof(PtWidget_t**));
	for(i = 0; i < gridRows; i++)
	{
		ButtonMatEnemy[i] = (PtWidget_t**) malloc(gridRows * sizeof(PtWidget_t**));
		for(j = 0; j < gridCols; j++)
		{
			pos.x = gridEnemyX + j * cellSize + buttonPadding;
			pos.y = gridEnemyY + i * cellSize + buttonPadding;
			size.w = cellSize - 2 * buttonPadding;
			size.h = cellSize - 2 * buttonPadding;

			int* cell = (int*) malloc(sizeof(int) * 2); cell[0] = i; cell[1] = j;
			PtSetArg( &argt[2], Pt_ARG_TEXT_STRING, "", 0 );

			PtWidget_t* wid = PtCreateWidget(PtButton,widget,4,argt);
			PtAddEventHandler(wid,Ph_EV_BUT_PRESS,&EnemyButtonPress,(void*) cell);

			PtRealizeWidget(wid);
			ButtonMatEnemy[i][j] = wid;
		}
	}

	gameState = 1;
	printf("GameState = PREPARING\n");
	PtSetResource(ABW_tbPrompt, Pt_ARG_TEXT_STRING, "Hint: Fill your field with 5 ships, then hit Apply", 0);
	PtSetResource(ABW_tbGameState, Pt_ARG_TEXT_STRING, "Game state: Preparing", 0);
	return( Pt_CONTINUE );
}


int PlayerButtonPress (PtWidget_t *widget, void *data, PtCallbackInfo_t *info)
{
	int* cell = (int*) data;
	printf("PlayerButtonPress\n");
	if(gameState == 1)
	{
		PtSetResource(ABW_tbPrompt, Pt_ARG_TEXT_STRING, "Hint: Fill your field with 5 ships, then hit Apply", 0);
		int k;

		bool noNeighboor = true;

		for(k = 0; k < 4; k++)
		{
			if(playerSelect[k] != NULL)
			{
				int cellI = cell[0];
				int cellJ = cell[1];
				int mI = playerSelect[k][0];
				int mJ = playerSelect[k][1];

				if(
					(cellI - 1 == mI && cellJ == mJ) || (cellI + 1 == mI && cellJ == mJ) ||
					(cellI == mI && cellJ - 1 == mJ) || (cellI == mI && cellJ + 1 == mJ) ||
					(cellI - 1 == mI && cellJ - 1 == mJ) || (cellI + 1 == mI && cellJ + 1 == mJ) ||
					(cellI - 1 == mI && cellJ + 1 == mJ) || (cellI + 1 == mI && cellJ - 1 == mJ) ||
					(cellI == mI && cellJ == mJ)
				)
				{
					noNeighboor = false;
					break;
				}
			}
		}

		if(noNeighboor)
		{
			if(playerSelect[4] != NULL)
			{
				PtSetResource(ButtonMatPlayer[playerSelect[k][0]][playerSelect[k][1]],Pt_ARG_FILL_COLOR,Pg_DBLUE,0);
			}

			for(k = 4; k > 0; k--){
				playerSelect[k]=playerSelect[k-1];
			}

			playerSelect[0] = cell;
			PtSetResource(ButtonMatPlayer[playerSelect[0][0]][playerSelect[0][1]],Pt_ARG_FILL_COLOR,Pg_CYAN,0);
		}

		int i;
		for(i = 0; i < 5; i++)
		{
			if(playerSelect[i] != NULL)
			{
				printf("%d%d ",playerSelect[i][0],playerSelect[i][1]);
			}
			else
			{
				printf("NULL ");
			}
		}
		printf("\n");
	}
	return( Pt_CONTINUE );
}

int EnemyButtonPress (PtWidget_t *widget, void *data, PtCallbackInfo_t *info)
{
	int* cell = (int*) data;
	printf("EnemyButtonPress\n");
	if(gameState == 3)
	{
		int i = 0;
		while(enemyHit[i] != NULL && i < hits)
		{
			if(enemyHit[i][0] == cell[0] && enemyHit[i][1] == cell[1])
			{
				return( Pt_CONTINUE );
			}
			i++;
		}

		if(enemySelect[0] != NULL)
		{
			PtSetResource(ButtonMatEnemy[enemySelect[0][0]][enemySelect[0][1]],Pt_ARG_FILL_COLOR,Pg_VGA4,0);
		}
		enemySelect[0] = cell;
		PtSetResource(ButtonMatEnemy[enemySelect[0][0]][enemySelect[0][1]],Pt_ARG_FILL_COLOR,Pg_DBLUE,0);
	}
	return( Pt_CONTINUE );
}
