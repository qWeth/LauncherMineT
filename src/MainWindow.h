#pragma once

#include <AUI/Platform/AWindow.h>
#include <Models/State.h>

class MainWindow: public AWindow {
public:

    MainWindow();


    void showLauncherSettings();
    void OpenFolder();
    _<AView> NIZHNYA_HUETA();
    _<AView> CENTRALNYA_HUETA();
    static MainWindow& inst();

private:
    State mState;
};

