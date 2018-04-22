
#include "ld41.h"

LD41::LD41(int w, int h)
    : aether::core::Application(w, h),
      gameplayScreen(this)
{

}

int LD41::ready(int argc, char **argv)
{
    assets.load();
    assets.theme.play();
    setScreen(&gameplayScreen);
    return 0;
}

void LD41::update(uint64_t delta)
{
    if( false == assets.theme.playing() )
    {
        assets.theme.play();

    }
    aether::core::Application::update(delta);
    if( aether::core::is_key_down(aether::core::KeyCode::Escape) )
    {
        close();
    }
}

void LD41::dispose()
{
    assets.cleanup();
}
