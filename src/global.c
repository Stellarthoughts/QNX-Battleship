#define MAIN_FILE
#include "global.h"


PtWidget_t*** ButtonMatPlayer = NULL;
PtWidget_t*** ButtonMatEnemy = NULL;

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
// 2 - battle;
// 3 - game finished;

int*** playerSelect;
int*** enemySelect;


