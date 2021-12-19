
/* abmain.c */

/* buttonApplyActivate.c */
int buttonApplyActivate ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );

/* buttonExitActivate.c */
int buttonExitActivate ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );

/* buttonReconnectActivate.c */
int buttonReconnectActivate ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );

/* buttonResetActivate.c */
int buttonResetActivate ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );

/* buttonRestartActivate.c */
int buttonRestartActivate ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );

/* buttonSendActivate.c */
int buttonSendActivate ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
int sendToServer ( char *message );
void handler ( int signo );

/* global.c */

/* windowOpened.c */
int windowOpened ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
int PlayerButtonPress ( PtWidget_t *widget , void *data , PtCallbackInfo_t *info );
int EnemyButtonPress ( PtWidget_t *widget , void *data , PtCallbackInfo_t *info );

/* windowStart.c */
int windowStart ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
