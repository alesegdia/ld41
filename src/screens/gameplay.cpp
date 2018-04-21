#include "gameplay.h"

#include "../ld41.h"

GameplayScreen::GameplayScreen(LD41 *game)
    : m_factory(game->assets, m_stage)
{
    m_game = game;
}

void GameplayScreen::show()
{
    actions_init(&(m_game->assets), &m_factory);
    m_stage.reset();
    m_player = m_factory.makePlayer(10,10);
    m_factory.makeRandomElementEnemy(1000,120);
    m_factory.makeRandomElementEnemy(1000,230);
    m_factory.makeRandomElementEnemy(1000,340);
    m_factory.makeRandomElementEnemy(1000,500);
}

void GameplayScreen::hide()
{

}

void GameplayScreen::render()
{
    aether::graphics::clear(32, 0, 32);
    m_stage.render();
}

void GameplayScreen::update(uint64_t delta)
{
    Element npe = m_stage.getPlayerElement();
    if( m_player->element != npe )
    {
        player_change_element(m_player, npe);
    }

    if( !m_player->isDead() )
    {
        m_stage.update(delta);
    }

    if( aether::core::is_key_down( aether::core::KeyCode::X ) )
    {
        m_factory.makeBullet(
                    m_player->rect.x(),
                    m_player->rect.y(),
                    m_player->element);
    }
}
