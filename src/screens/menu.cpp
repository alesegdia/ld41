#include "menu.h"

#include "../ld41.h"


MenuScreen::MenuScreen(LD41 *game)
{
    m_game = game;
}

void MenuScreen::show()
{
    m_textPos = 50;
    m_game->level = 1;
}

void MenuScreen::hide()
{

}

static int blinker = 0;

void MenuScreen::render()
{
    const char* text = "The rise of the elementals, a prophecy spread by word of mouth among people of Lodenia, but unlike most prophecies, this one has come to be true. But fear not, my child, since the ancient dragon knight will arise from the heart of the planet to overcome the evil menace of the machines.";

    aether::graphics::clear(0, 0, 0);
    m_game->assets.splash.draw(0, 0);
    //m_game->assets.fontBig.print( "D.R.A.K.E.", 70, 200, aether::graphics::Color(255,255,255) );

    if( blinker < 3 * 1e6 )
    {
        m_game->assets.font.print( "Press X to start game", 270, 350, aether::graphics::Color(255,255,255) );
    }

    m_game->assets.font.print(text, 400,m_textPos, 600, 20, aether::graphics::Color(255, 255, 255));

}


void MenuScreen::update(uint64_t delta)
{
    m_textPos -= delta / 2e6;
    blinker += delta;
    if( blinker > 6 * 1e6 )
    {
        blinker = 0;
    }

    if( aether::core::is_key_just_pressed(aether::core::KeyCode::X) )
    {
        m_game->setScreen(&(m_game->midstageScreen));
        m_game->assets.beep.play();
    }
}
