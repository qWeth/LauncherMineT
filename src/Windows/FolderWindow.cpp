//
// Created by mikle on 2025-05-31.
//

#include "FolderWindow.h"
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

#include <AUI/Util/UIBuildingHelpers.h>

using namespace ass;

FolderWindow::FolderWindow(AWindow *parrent)
        : AWindow(" hui", 600_dp, 500_dp, parrent) {
    using namespace declarative;
    
    setContents(Stacked {
      Label { "pizda" },
    });
}
