#include "MainWindow.h"
#include <AUI/Util/UIBuildingHelpers.h>
#include <AUI/View/ALabel.h>
#include <AUI/View/AButton.h>
#include <AUI/Platform/APlatform.h>
#include <AUI/View/ADrawableView.h>
#include <AUI/View/AProgressBar.h>
#include <AUI/ASS/Property/FixedSize.h>

using namespace declarative;

static _<AView> NIZHNYA_HUETA() {
    return Centered::Expanding {
        Vertical::Expanding {
          SpacerExpanding {},
          Horizontal {
            Horizontal {
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
            } with_style {
              MinSize { 86_dp },
              Expanding {},
              BackgroundSolid { AColor::GRAY },
            },
          },
        },
    };
}

MainWindow::MainWindow() : AWindow("LauncherMineT", 800_dp, 600_dp) {
    setContents(Horizontal::Expanding {
      NIZHNYA_HUETA(),
    } with_style {
      BackgroundSolid { 0x232323_rgb },
    });
}
