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

AVector<Version> Version::fetchAll(){
    auto VersionArray = AJson::fromBuffer(ACurl::Builder("https://launchermeta.mojang.com/mc/game/version_manifest.json").runBlocking().body);
    const auto& jsonVersionArray = VersionArray["version"].asArray();
    AVector<Version> versions;
    versions.reserve(jsonVersionArray.size());
    for (const auto& version : jsonVersionArray) {
        versions.push_back({
            version["id"].asString(),
            version["url"].asString(),
            AEnumerate<VersionType>::byName(version["type"].asString()),
        });
    }
    return versions;
}
GameProfiles Version::import() const {

}