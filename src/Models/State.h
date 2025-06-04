#pragma once

#include <AUI/Common/AProperty.h>
#include <AUI/Common/AUuid.h>

struct State {
    /*
    struct Profiles {

        void notify() {
            list.notify();
            selected.notify();
        }
    } profile;

    struct Accounts {
        //        AProperty<AVector<_<Account>>> list;
        //        AProperty<_<Account>> selected;
        _<Account> current = _new<Account>();
    } accounts;

    */


    ASet<AUuid> profilesUuidsSnapshot;
};