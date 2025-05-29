
#include <AUI/View/AListView.h>
#include <AUI/View/ADropdownList.h>
#include <AUI/View/AText.h>
#include <AUI/Curl/ACurl.h>
#include <AUI/Json/AJson.h>
#include <AUI/Model/AModels.h>
#include <AUI/View/ACheckBox.h>
#include "InitWindow.h"
#include "MainWindow.h"

#include <AUI/Util/UIBuildingHelpers.h>
#include <AUI/Util/ARandom.h>
#include <AUI/IO/AFileInputStream.h>
#include <AUI/Platform/AMessageBox.h>
#include <AUI/View/ATextField.h>
#include <AUI/IO/AFileOutputStream.h>
#include <AUI/View/ADrawableView.h>
#include <AUI/Platform/ADesktop.h>
#include <AUI/View/AGroupBox.h>
#include <AUI/View/AVDividerView.h>
#include <AUI/View/ASpinnerV2.h>
#include <AUI/View/AProgressBar.h>

// using namespace declarative;
//
// InitWindow::InitWindow(state)
//     : AWindow("Import version", 500_dp, 400_dp, &MainWindow::inst(), WindowStyle::MODAL  ),mState(state) {
//
//
// }