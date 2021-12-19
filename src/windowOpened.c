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
windowOpened( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{

/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	printf("windowOpened\n");

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
	playerSelect = (int***) malloc(5 * sizeof(int**));
	enemySelect = (int***) malloc(1 * sizeof(int**));;

	int i,j;

	// Player
	ButtonMatPlayer = (PtWidget_t***) malloc(gridRows * sizeof(PtWidget_t**));
	for(i = 0; i < gridRows; i++)
	{
		ButtonMatPlayer[i] = (PtWidget_t**) malloc(gridRows * sizeof(PtWidget_t**));
		for(j = 0; j < gridCols; j++)
		{
			pos.x = gridPlayerX + i * cellSize + buttonPadding;
			pos.y = gridPlayerY + j * cellSize + buttonPadding;
			size.w = cellSize - 2 * buttonPadding;
			size.h = cellSize - 2 * buttonPadding;

			int cell[2]; cell[0] = i; cell[1] = j;
			PtSetArg( &argt[2], Pt_ARG_TEXT_STRING, "", 0 );
			PtSetArg( &argt[3],Pt_ARG_USER_DATA, (void*)&cell ,0);
			PtWidget_t* wid = PtCreateWidget(PtButton,widget,4,argt);
			PtRealizeWidget(wid);
			ButtonMatPlayer[i][j] = wid;
		}
	}

	// Enemy
	ButtonMatEnemy = (PtWidget_t***) malloc(gridRows * sizeof(PtWidget_t**));
	for(i = 0; i < gridRows; i++)
	{
		ButtonMatEnemy[i] = (PtWidget_t**) malloc(gridRows * sizeof(PtWidget_t**));
		for(j = 0; j < gridCols; j++)
		{
			pos.x = gridEnemyX + i * cellSize + buttonPadding;
			pos.y = gridEnemyY + j * cellSize + buttonPadding;
			size.w = cellSize - 2 * buttonPadding;
			size.h = cellSize - 2 * buttonPadding;

			PtSetArg( &argt[2], Pt_ARG_TEXT_STRING, "", 0 );
			PtWidget_t* wid = PtCreateWidget(PtButton,widget,3,argt);
			PtRealizeWidget(wid);
			ButtonMatEnemy[i][j] = wid;
		}
	}

	return( Pt_CONTINUE );

}

