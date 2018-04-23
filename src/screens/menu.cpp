#include "menu.h"

#include "../ld41.h"


MenuScreen::MenuScreen(LD41 *game)
{
    m_game = game;
}

void MenuScreen::show()
{

}

void MenuScreen::hide()
{

}

static int blinker = 0;

void MenuScreen::render()
{
    aether::graphics::clear(0, 0, 0);
    m_game->assets.fontBig.print( "D.R.A.K.E.", 70, 200, aether::graphics::Color(255,255,255) );

    if( blinker < 3 * 1e6 )
    {
        m_game->assets.font.print( "Press X to start game", 270, 350, aether::graphics::Color(255,255,255) );
    }

}

void MenuScreen::update(uint64_t delta)
{
    blinker += delta;
    if( blinker > 6 * 1e6 )
    {
        blinker = 0;
    }

    if( aether::core::is_key_down(aether::core::KeyCode::X) )
    {
        m_game->setScreen(&(m_game->midstageScreen));
        m_game->assets.beep.play();
    }
}
