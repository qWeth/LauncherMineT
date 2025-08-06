#include <AUI/Platform/Entry.h>
#include "MainWindow.h"

#if AUI_PLATFORM_LINUX
#endif

AUI_ENTRY {

    _new<MainWindow>()->show();
    return 0;
};