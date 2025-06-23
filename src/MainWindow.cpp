#include "MainWindow.h"

#include "Windows/FolderWindow.h"
#include "Windows/SettingsWindow.h"
#include "Windows/InitWindow.h"
#include <AUI/Util/UIBuildingHelpers.h>
#include <AUI/View/ALabel.h>
#include <AUI/View/AButton.h>
#include <AUI/Platform/APlatform.h>
#include <AUI/View/ADrawableView.h>
#include <AUI/View/AProgressBar.h>
#include <AUI/ASS/Property/FixedSize.h>
#include <AUI/View/ADropdownList.h>
#include <AUI/Model/AListModel.h>
#include <AUI/View/ATextField.h>
#include <AUI/Util/ACleanup.h>

using namespace declarative;

_<AView> MainWindow::CENTRALNYA_HUETA() {
    return Centered{
        Label {"xd"},
    };
}

_<AView> MainWindow::NIZHNYA_HUETA() {
    return Centered::Expanding {
        Vertical::Expanding {
          SpacerExpanding {},
          Horizontal {
            Horizontal {
              Centered {
                Vertical {
                  Label { "Username:" } with_style {
                    TextColor { AColor::WHITE },
                  },

                  _new<ATextField>() with_style {

                  },
                },
              },
              SpacerExpanding(),
              Vertical {
                SpacerExpanding(),
                _new<AButton>("Play") with_style {
                  MinSize { 128_dp, { 50_dp } },
                  BackgroundSolid { AColor::BLACK },
                  BorderRadius { 12_dp },
                  BoxShadow { 0, 2_dp, 16_dp, AColor::BLUE.transparentize(0.7f) },
                  TextColor { AColor::WHITE },
                },
                SpacerExpanding(),
              },
              SpacerExpanding(),
              Vertical {

                SpacerExpanding(),

                Button {
                  Icon { ":img/plus.svg" },
                  Label { "Import version..." },
                }.clicked(this, [this]{
                    _new<InitWindow>(mState)->show();
                }),

                Button {
                  Icon { ":img/folder.svg" },
                  Label { "game dir" },
                }.clicked(me::OpenFolder),

                Button {
                  Icon { ":img/settings.svg" },
                  Label { "Settings" },
                }.clicked(me::showLauncherSettings),

                SpacerExpanding(),

              },
            } with_style {
              MinSize { 86_dp },
              Expanding {},
              BackgroundSolid { 0x999999_rgb }, //0x272757_rgb
            },
          },
        },
    };
}

MainWindow::MainWindow() : AWindow("LauncherMineT", 850_dp, 500_dp) {
    setContents(Horizontal::Expanding {
      NIZHNYA_HUETA(),
    } with_style {
      BackgroundSolid { 0x232323_rgb },
    });
}

void MainWindow::showLauncherSettings() {
    _new<SettingsWindow>()->show();
}

void MainWindow::OpenFolder() {
    _new<FolderWindow>(this)->show();
}

MainWindow& MainWindow::inst() {
    static auto a = aui::ptr::manage(new MainWindow);
    ACleanup::afterEntry([&] {
        a = nullptr;
    });
    return *a;
}

// MainWindow& MainWindow::inst() {
//     static auto a = aui::ptr::manage(new MainWindow);
//     ACleanup::afterEntry([&] {
//         a = nullptr;
//     });
//     return *a;
// }h