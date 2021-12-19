
/* abmain.c */

/* btnRestartActivate.c */
int btnRestartActivate ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );

/* buttonEnemyActivate.c */

/* buttonExitActivate.c */
int buttonExitActivate ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );

/* buttonPlayerActivate.c */

/* buttonReconnectActivate.c */
int buttonReconnectActivate ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );

/* buttonRestartActivate.c */
int buttonRestartActivate ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );

/* buttonSendActivate.c */
int buttonSendActivate ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
int sendToServer ( char *message );
void handler ( int signo );

/* windowOpened.c */
int windowOpened ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );

/* windowStart.c */
int windowStart ( PtWidget_t *widget , ApInfo_t *apinfo , PtCallbackInfo_t *cbinfo );
