/* Import (extern) header for application - AppBuilder 2.03  */

#include "abdefine.h"

extern ApWindowLink_t base;
extern ApWidget_t AbWidgets[ 12 ];


#ifdef __cplusplus
extern "C" {
#endif
int buttonReconnectActivate( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int windowStart( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int buttonExitActivate( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int buttonSendActivate( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int windowOpened( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int buttonApplyActivate( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int buttonResetActivate( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int btnReadyActivate( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
#ifdef __cplusplus
}
#endif
