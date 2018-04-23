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
        m_game->assets.fontBig.print( "GAME OVER", 100, 100, aether::graphics::Color(255,255,255) );
        m_game->assets.fontMid.print("Congratulations!", 210, 250, aether::graphics::Color(255, 255, 255));
        m_game->assets.font.print("You earned a golden dragon!!!11eleven :D", 168, 330, aether::graphics::Color(255, 255, 255));
        m_game->assets.drake_gold.draw(350,400);
        m_game->assets.font.print("Graphics by TheMiwes#006", 260, 480, aether::graphics::Color(255,255,255));
        m_game->assets.font.print("Dev by alesegdia", 305, 505, aether::graphics::Color(255,255,255));

    }
    else
    {
        char buffer[10];
        sprintf(buffer, "STAGE %d", m_game->level);
        m_game->assets.fontMid.print( buffer, 300, 270, aether::graphics::Color(255,255,255) );
        m_game->assets.font.print( "Press X to start", 290, 330, aether::graphics::Color(255,255,255) );
        switch(state)
        {
        case 1: m_game->assets.font.print("You lost", 335, 360, aether::graphics::Color(255, 255, 255) ); break;
        case 2: m_game->assets.font.print("You Won!", 335, 360, aether::graphics::Color(255, 255, 255) ); break;
        }
        m_game->assets.font.print("Kill enemies of the correct color to complete the star sequence", 50, 400, aether::graphics::Color(255, 255, 255) );
        m_game->assets.font.print("Killing an enemy of the wrong color adds a star to the sequence", 50, 440, aether::graphics::Color(255, 255, 255) );
        m_game->assets.font.print("   Enemy reaching left of screen adds a star to the sequence", 50, 480, aether::graphics::Color(255, 255, 255) );

        m_game->assets.font.print("Shoot same element to deal damage", 200, 100, aether::graphics::Color(255, 255, 255) );
        m_game->assets.font.print("Shoot strong element enemy to instakill", 165, 140, aether::graphics::Color(255, 255, 255) );
        m_game->assets.font.print("Shoot weak enemy to heal the enemy and change your element", 70, 180, aether::graphics::Color(255, 255, 255) );

    }
}

void MidstageScreen::update(uint64_t delta)
{
    if( aether::core::is_key_just_pressed(aether::core::KeyCode::X) )
    {
        if( m_game->level == Constants::MAX_LEVEL )
        {
            m_game->setScreen(&(m_game->menuScreen));
        }
        else
        {
            m_game->setScreen(&(m_game->gameplayScreen));
        }
        m_game->assets.beep.play();
    }
}
