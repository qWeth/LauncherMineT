//
// Created by mikle on 2025-05-28.
//

#ifndef INITWINDOW_H
#define INITWINDOW_H

#pragma once

#include "Models/State.h"
#include <AUI/Platform/AWindow.h>
#include <AUI/View/ARadioButton.h>
#include <AUI/View/AListView.h>
#include <AUI/View/AButton.h>
#include <AUI/Model/AListModel.h>
#include <AUI/View/ATextField.h>
#include <AUI/Util/ABitField.h>
#include <AUI/Thread/AAsyncHolder.h>




class InitWindow: public AWindow {
public:
    InitWindow(State& state);
private:
    State& mState;
};



#endif //INITWINDOW_H
