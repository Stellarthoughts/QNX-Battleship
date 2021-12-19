/* Define header for application - AppBuilder 2.03  */

/* 'base' Window link */
extern const int ABN_base;
#define ABW_base                             AbGetABW( ABN_base )
extern const int ABN_btnExit;
#define ABW_btnExit                          AbGetABW( ABN_btnExit )
extern const int ABN_btnReconnect;
#define ABW_btnReconnect                     AbGetABW( ABN_btnReconnect )
extern const int ABN_tbStatus;
#define ABW_tbStatus                         AbGetABW( ABN_tbStatus )
extern const int ABN_gridPlayer;
#define ABW_gridPlayer                       AbGetABW( ABN_gridPlayer )
extern const int ABN_gridEnemy;
#define ABW_gridEnemy                        AbGetABW( ABN_gridEnemy )
extern const int ABN_btnReset;
#define ABW_btnReset                         AbGetABW( ABN_btnReset )
extern const int ABN_btnApply;
#define ABW_btnApply                         AbGetABW( ABN_btnApply )
extern const int ABN_btnSend;
#define ABW_btnSend                          AbGetABW( ABN_btnSend )
extern const int ABN_tbPrompt;
#define ABW_tbPrompt                         AbGetABW( ABN_tbPrompt )
extern const int ABN_tbGameState;
#define ABW_tbGameState                      AbGetABW( ABN_tbGameState )

#define AbGetABW( n ) ( AbWidgets[ n ].wgt )

#define AB_OPTIONS "s:x:y:h:w:S:"
