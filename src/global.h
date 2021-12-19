#include <photon/PtWidget.h>
#include <errno.h>
#include <sys/neutrino.h>
#include <sys/siginfo.h>

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

	int** playerSelect;
	int** enemySelect;
	int** enemyHit;
	int hits;


	int hasServerData;
	char ndString[512];
	pid_t spid;
	int chid;
	int coid;

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

	extern int** playerSelect;
	extern int** enemySelect;
	extern int** enemyHit;
	extern int hits;

	extern int hasServerData;
	extern char ndString[512];
	extern pid_t spid;
	extern int chid;
	extern int coid;

#endif
#endif
