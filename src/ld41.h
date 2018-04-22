#include <aether/core/application.h>

#include "screens/gameplay.h"
#include "screens/menu.h"
#include "screens/midstage.h"
#include "assets.h"
#include "entity/actions.h"

class LD41 : public aether::core::Application
{
public:
    LD41(int w, int h);

    int ready(int argc, char **argv) override;

    void update(uint64_t delta);

    void dispose();

    GameplayScreen gameplayScreen;
    MenuScreen menuScreen;
    MidstageScreen midstageScreen;

    Assets assets;

    int level = 1;
};

