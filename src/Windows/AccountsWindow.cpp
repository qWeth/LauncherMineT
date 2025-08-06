//
// Created by mikle on 7/8/25.
//

#include "AccountsWindow.h"

#include <AUI/ASS/ASS.h>
#include <AUI/Util/UIBuildingHelpers.h>
#include <AUI/View/ACheckBox.h>
#include <AUI/View/AButton.h>
#include <AUI/Platform/AMessageBox.h>
#include <AUI/Traits/strings.h>
#include <AUI/Util/ARandom.h>
#include <AUI/View/AScrollArea.h>
#include <AUI/View/AScrollArea.h>
#include <AUI/View/ATextField.h>
#include <AUI/View/AGroupBox.h>
// AccountsWindow::AccountsWindow(State& state, _<Accounts> user) :
//     AWindow("Account manager", 300, 200, dynamic_cast<AWindow*>(AWindow::current()), WindowStyle::MODAL),
//     mState(state) {

AccountsWindow::AccountsWindow() : AWindow("Account manager", 300_dp, 200_dp) {
    using namespace declarative;

    setContents(Stacked { Horizontal::Expanding {
      Vertical::Expanding {
        AScrollArea::Builder().withContents(Vertical::Expanding{Vertical{

           Label { " name " },
            Label { " description " },
        } with_style{
            BackgroundSolid{
                AColor::GRAY
            }
        }
            }
        ).build(),
      },
      Vertical::Expanding {
          Vertical{
              _new<ATextField>() with_style {

              },
              _new<AButton>("Add") with_style{
                  BackgroundSolid { AColor::BLUE },
              }
          }
      },

    }});
}