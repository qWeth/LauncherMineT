//
// Created by mikle on 2025-05-29.
//

#include <AUI/Util/kAUI.h>
#include "Util.h"

APath Util::launcherDir() {
     auto path = APath::getDefaultPath(APath::APPDATA).file(".minet");
     do_once {
         path.makeDirs();
     };
     return path;
 }