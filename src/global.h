#include <photon/PtWidget.h>

#ifndef SHAREFILE_INCLUDED
#define SHAREFILE_INCLUDED
#ifdef  MAIN_FILE

	PtWidget_t*** ButtonMatPlayer;
	PtWidget_t*** ButtonMatEnemy;

	int gridRows;
	int gridCols;
	int buttonPadding;

	int gridDimension;
	int cellSize;

	int gridPlayerX;
	int gridPlayerY;

	int gridEnemyX ;
	int gridEnemyY;

	int gameState;
	// 0 - game has not started;
	// 1 - preparing;
	// 2 - battle;
	// 3 - game finished;

	int*** playerSelect;
	int*** enemySelect;

#else

	extern PtWidget_t*** ButtonMatPlayer;
	extern PtWidget_t*** ButtonMatEnemy;

	extern int gridRows;
	extern int gridCols;
	extern int buttonPadding;

	extern int gridDimension;
	extern int cellSize;

	extern int gridPlayerX;
	extern int gridPlayerY;

	extern int gridEnemyX ;
	extern int gridEnemyY;

	extern int gameState;
	// 0 - game has not started;
	// 1 - preparing;
	// 2 - battle;
	// 3 - game finished;

	extern int*** playerSelect;
	extern int*** enemySelect;

#endif
#endif
