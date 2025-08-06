#include "MainWindow.h"

#include "Windows/FolderWindow.h"
#include "Windows/SettingsWindow.h"
#include "Windows/InitWindow.h"
#include "Windows/AccountsWindow.h"
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
#include <AUI/ASS/Property/BackgroundImage.h>

using namespace declarative;
using namespace ass;

_<AView> MainWindow::CENTRALNYA_HUETA() {
    return Centered::Expanding {
        Label { " asd" },
    };
}

_<AView> MainWindow::NIZHNYA_HUETA() {
    return Centered {
        Vertical::Expanding {
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

              Centered {
                SpacerExpanding(),
                _new<AButton>("+") with_style {
                  MaxSize { 25_dp, 25_dp },
                } let {
                     it->setExpanding(2);
                     connect(it->clicked, me::AddAccountButton);
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
                // let {
                //     it << "#play" << ".btn" << ".btn_default";
                //     connect(it->clicked, me::PlayButton);
                // },
                SpacerExpanding(),
              },
              SpacerExpanding(),
              Vertical {

                SpacerExpanding(),

                Button {
                  Icon { ":img/plus.svg" },
                  Label { "Import version..." },
                }
                    .clicked(this, [this] { _new<InitWindow>(mState)->show(); }),

                Button {
                  Icon { ":img/folder.svg" },
                  Label { "game dir" },
                }
                    .clicked(me::OpenFolder),

                Button {
                  Icon { ":img/settings.svg" },
                  Label { "Settings" },
                }
                    .clicked(me::showLauncherSettings),

                SpacerExpanding(),

              },
            } with_style {
              MinSize { 86_dp }, Expanding {}, BackgroundSolid { 0x999999_rgb },   // 0x272757_rgb
            },
          },
        },
    };
}

// void MainWindow::PlayButton() {
//     auto account = mState.accounts.current;
//     if ( account == nullptr || account->name->empty()) {
//         auto accountWindow = _new<AccountsWindow> (mState, nullptr);
//     }
// }

MainWindow::MainWindow() : AWindow("LauncherMineT", 850_dp, 500_dp) {
    setContents(Vertical::Expanding {
      CENTRALNYA_HUETA(),
      NIZHNYA_HUETA(),
    } with_style {
      BackgroundSolid { 0x232323_rgb },
    });
}

void MainWindow::showLauncherSettings() { _new<SettingsWindow>()->show(); }

void MainWindow::OpenFolder() { _new<FolderWindow>(this)->show(); }

MainWindow& MainWindow::inst() {
    static auto a = aui::ptr::manage(new MainWindow);
    ACleanup::afterEntry([&] { a = nullptr; });
    return *a;
}

void MainWindow::AddAccountButton() {
    _new<AccountsWindow>()->show();
}