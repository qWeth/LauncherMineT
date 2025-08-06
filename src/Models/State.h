#pragma once

#include <AUI/Common/AProperty.h>
#include <AUI/Common/AUuid.h>

#include "Profiles.h"
#include "Accounts.h"

struct State {
    struct Profiles{
        AProperty<AVector<_<GameProfiles>>> list;
        AProperty<_<GameProfiles>> selected;

        void notify() {
            list.notify();
            selected.notify();
        }
    } gprofile;

    struct Account {
        _<Accounts> current = _new<Accounts>();
    } accounts;


    ASet<AUuid> profilesUuidsSnapshot;
};