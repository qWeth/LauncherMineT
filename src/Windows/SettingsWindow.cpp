//
// Created by mikle on 2025-05-29.
//

#include "SettingsWindow.h"
#include "MainWindow.h"
#include <AUI/Util/UIBuildingHelpers.h>
#include <AUI/View/ATabView.h>
#include <AUI/View/AText.h>
#include <AUI/View/APathChooserView.h>
#include <AUI/Json/AJson.h>
#include <AUI/View/ARadioButton.h>
#include <AUI/View/ANumberPicker.h>
#include <AUI/View/ACheckBox.h>
#include <AUI/Platform/AMessageBox.h>
#include <AUI/Platform/ADesktop.h>
#include <AUI/ASS/ASS.h>
#include <AUI/View/ASpinnerV2.h>
#include <AUI/Platform/APlatform.h>

using namespace ass;

SettingsWindow::SettingsWindow()
        : AWindow("Settings", 500_dp, 400_dp) {
     using namespace declarative;

     _<AView> mView;
     _<ACheckBoxWrapper> fullscreenCheckbox;

     setContents(
        Vertical{
            Label {"asdasd"},
        }
     );
 }
