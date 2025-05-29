//
// Created by mikle on 2025-05-29.
//

#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H
#include <AUI/Platform/AWindow.h>
#include <AUI/View/AButton.h>
#include <AUI/GL/State.h>


class SettingsWindow : public AWindow{
public:
    SettingsWindow();

private:

    void clearGameDir();

};


#endif //SETTINGSWINDOW_H
