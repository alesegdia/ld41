#include "menu.h"

#include "../ld41.h"

#include <stdio.h>


MidstageScreen::MidstageScreen(LD41 *game)
{
    m_game = game;
}

void MidstageScreen::show()
{

}

void MidstageScreen::hide()
{

}

void MidstageScreen::render()
{
    aether::graphics::clear(0, 0, 0);
    if( m_game->level == Constants::MAX_LEVEL )
    {
        m_game->assets.fontMid.print( "GAME OVER", 300, 270, aether::graphics::Color(255,255,255) );
    }
    else
    {
        char buffer[10];
        sprintf(buffer, "STAGE %d", m_game->level);
        m_game->assets.fontMid.print( buffer, 300, 270, aether::graphics::Color(255,255,255) );
        m_game->assets.font.print( "Press X to start", 290, 330, aether::graphics::Color(255,255,255) );
        switch(state)
        {
        case 1: m_game->assets.font.print("You lost", 290, 360, aether::graphics::Color(255, 255, 255) ); break;
        case 2: m_game->assets.font.print("You Won!", 290, 360, aether::graphics::Color(255, 255, 255) ); break;
        }
    }
}

void MidstageScreen::update(uint64_t delta)
{
    if( aether::core::is_key_just_pressed(aether::core::KeyCode::X) )
    {
        m_game->setScreen(&(m_game->gameplayScreen));
    }
}
