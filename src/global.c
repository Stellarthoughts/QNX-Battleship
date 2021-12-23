#define MAIN_FILE
#include "global.h"


PtWidget_t*** ButtonMatPlayer = NULL;
PtWidget_t*** ButtonMatEnemy = NULL;

PtWidget_t* timer = NULL;

int gridRows = 5;
int gridCols = 5;
int buttonPadding = 2;

int gridDimension = 300;
int cellSize = 60;

int gridPlayerX = 50;
int gridPlayerY = 150;

int gridEnemyX = 425;
int gridEnemyY = 150;

int gameState = 0;
// 0 - game has not started;
// 1 - preparing;
// 2 - filled field;
// 3 - battle;

int** playerSelect;
int** enemySelect;
int** enemyHit;
int hits = 0;

int playerNum;

char ndString[512];
pid_t spid;
int chid;
int coid;
int hasServerData = 0;
