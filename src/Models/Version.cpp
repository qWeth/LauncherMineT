//
// Created by mikle on 15.06.2025.
//

#include <AUI/Curl/ACurl.h>
#include <AUI/Json/AJson.h>
#include <AUI/IO/AFileOutputStream.h>
#include <AUI/Logging/ALogger.h>
#include <AUI/Util/ARandom.h>
#include <AUI/IO/AFileInputStream.h>
#include "Version.h"
#include "Settings.h"

static constexpr auto LOG_TAG = "Version";

//AVector<Version> Version::fetchAll(){
//    auto GetVersion = AJson::fromBuffer();
//}