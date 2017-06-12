#ifndef APP_H
#define APP_H

#include  "Type.h"

#define     TIME_OF_APP    300

/**@public*/
inline void setAppStatus(TStatusApp sts_app);
inline TStatusApp getAppStatus(void);
inline int isRunningApp(void);

#endif

