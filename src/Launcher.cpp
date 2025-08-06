//
// Created by mikle on 13.07.25.
//

#include <range/v3/algorithm/find_if.hpp>
#include <AUI/Logging/ALogger.h>
#include <Models/Settings.h>
#include <AUI/Crypt/AHash.h>
#include <AUI/Traits/iterators.h>
#include <AUI/Platform/AWindow.h>
#include <AUI/IO/AFileInputStream.h>
#include <AUI/Curl/ACurl.h>
#include <AUI/Platform/AProcess.h>
#include <AUI/Platform/AProgramModule.h>
#include "Launcher.h"
#include <AUI/Common/AException.h>
#include "Util.h"

#include <AUI/i18n/AI18n.h>
#include <AUI/Traits/strings.h>
#include <AUI/Traits/platform.h>
#include <AUI/IO/AFileOutputStream.h>
#include <numeric>
#include <AUI/Util/kAUI.h>
#include <AUI/Traits/parallel.h>
#include <AUI/Util/AStdOutputRecorder.h>

static constexpr std::string LOG_TAG = "Launcher";
// static constexpr std::string JAVA_VERSIONS_URL = "https://launchermeta.mojang.com/v1/products/java-runtime/2ec0cc96c44e5a76b9c8b7c39df7210883d12871/all.json";

// _<AChildProcess> Launcher::play(const Accounts& account, const GameProfiles& profiles, bool Update) {
//     emit updateStatus("Locating Java");
//
//     ALogger::info(LOG_TAG) << " PLAY BUTTON";
//     ALogger::info(LOG_TAG) << " Accounts: " + account.name;
//     ALogger::info(LOG_TAG) << " Profiles: " + profiles.name;
// }
