#pragma once
#include <AUI/Platform/AWindow.h>

#include "Models/State.h"

class AccountsWindow : public AWindow{
public:
    // AccountsWindow(State& state, _<Accounts> user);
    AccountsWindow();
signals:
    emits<> positiveAction;
    emits<> deleteUser;

private:
    // State& mState;
    Accounts mAccounts;
};