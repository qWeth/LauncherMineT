//
// Created by mikle on 13.07.25.
//
#pragma once

#include <Models/Profiles.h>
#include <Models/Accounts.h>
#include <AUI/Platform/AProcess.h>

class Launcher : public AObject{
public:
    _<AChildProcess> play(const Accounts& account, const GameProfiles& profiles, bool Update = false);

    void InstallJava(const AString& version);
private:
    struct toDownload {
        AString localpath;
        AString url;
        // std::uint64_t;
        AString hash;
    };

signals:
    emits<AString> updateStatus;


};
