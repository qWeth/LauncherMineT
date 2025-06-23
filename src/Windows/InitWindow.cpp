
#include <AUI/View/AListView.h>
#include <AUI/View/ADropdownList.h>
#include <AUI/View/AText.h>
#include <AUI/Curl/ACurl.h>
#include <AUI/Json/AJson.h>
#include <AUI/Model/AModels.h>
#include <AUI/View/ACheckBox.h>
#include "InitWindow.h"
#include "MainWindow.h"
#include "Models/State.h"

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

using namespace declarative;

InitWindow::InitWindow(State& state)
  : AWindow("Import version", 500_dp, 400_dp, &MainWindow::inst(), WindowStyle::MODAL), mState(state) {
    connect(mReleaseTypeGroup.selectionChanged, [&](int d) {
        mVersionTypeValue = (VersionType) d;
        emit invalidateSearch;
    });
    _<AView> MinecraftListRepo = Horizontal::Expanding {
        mMinecraftListRepo =
            _new<AListView>() let {
                it->setCustomStyle({
                  Expanding {},
                  MinSize { 70_dp },
                });
                connect(it->itemDoubleClicked, me::ImportMinecraftRepo);
            },
        Vertical {
          _new<ALabel>("Search:"),
          mSearchTextField =
              _new<ATextField>().connect(&ATextField::textChanging, [&] { emit invalidateSearch; }) let { it->focus(); },
          _new<ALabel>("Filter:"),
          mReleaseTypeGroup.addRadioButton(_new<ARadioButton>("Releases"), int(VersionType::RELEASE)),
          mReleaseTypeGroup.addRadioButton(_new<ARadioButton>("Snapshots"), int(VersionType::SNAPSHOT)),
          mReleaseTypeGroup.addRadioButton(_new<ARadioButton>("Betas"), int(VersionType::OLD_BETA)),
          mReleaseTypeGroup.addRadioButton(_new<ARadioButton>("Alphas"), int(VersionType::OLD_ALPHA)),
        },
    };
}
void InitWindow::ImportMinecraftRepo() {
    setContents(Centered { Horizontal {
      _new<ASpinnerV2>(), Label { "Importing..." },

      Centered {
        Button { Label { "Cancel" } }.clicked(me::close),

      } } });

    for(const auto& row : mMinecraftListRepo->getSelectionModel()){
        Version version = mVersionModel->listItemAt(row.getIndex().getRow());



    }
}