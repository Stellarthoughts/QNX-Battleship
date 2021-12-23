#include "globalFunctions.h"

void ResetGame(int winCondition)
{
	gameState = 1;
	PtUnrealizeWidget(timer);

	if(winCondition == playerNum)
	{
		PtSetResource(ABW_tbPrompt,Pt_ARG_TEXT_STRING,"You won!",0);
	}
	else
	{
		PtSetResource(ABW_tbPrompt,Pt_ARG_TEXT_STRING,"You lost!",0);
	}
	PtSetResource(ABW_tbGameState,Pt_ARG_TEXT_STRING, "Game state: Preparing",0);
	PtSetResource(ABW_btnReady,Pt_ARG_TEXT_STRING,"Ready",0);
	PtRealizeWidget(ABW_btnReset);
	PtRealizeWidget(ABW_btnApply);

	int i,j;
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			PtSetResource(ButtonMatEnemy[i][j],Pt_ARG_FILL_COLOR,Pg_VGA4,0);
			PtSetResource(ButtonMatPlayer[i][j],Pt_ARG_FILL_COLOR,Pg_DBLUE,0);
		}
	}

	PtSetResource(ABW_tbGameState, Pt_ARG_TEXT_STRING, "Game state: Starting", 0);

	for(i = 0; i < 5; i++ ) playerSelect[i] = NULL;
	enemySelect[0] = NULL;
	for(i = 0; i < 25 ; i++ ) enemyHit[i] = NULL;
	hits = 0;


}
