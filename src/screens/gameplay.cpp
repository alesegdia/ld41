#include "gameplay.h"

#include "../ld41.h"

#include "../explosioncaster.h"
#include "../constants.h"

GameplayScreen::GameplayScreen(LD41 *game)
    : m_factory(game->assets, m_stage),
      m_sequence(game->assets),
      m_starfield(100)
{
    m_game = game;
}

void GameplayScreen::show()
{
    Constants::Level1();
    actions_init(&(m_game->assets), &m_factory);
    m_stage.reset();
    m_player = m_factory.makePlayer(10,10);
    m_sequence.reset(Constants::INITIAL_STARS);
    stage_set_assets(&(m_game->assets));
}

void GameplayScreen::hide()
{

}

void GameplayScreen::render()
{
    aether::graphics::clear(32, 0, 32);
    m_starfield.render();
    m_stage.render();

    aether::graphics::draw_filled_rectangle(0, 0, 800, 60, aether::graphics::Color(0, 0, 0));
    aether::graphics::draw_filled_rectangle(0, 600 - 60, 800, 600, aether::graphics::Color(0, 0, 0));

    m_game->assets.font.print("NEXT", 15, 20, aether::graphics::Color(255, 255, 255));
    m_sequence.render(70,10);
    aether::graphics::Color c;
    if( get_gauge() == Constants::MAX_GAUGE )
    {
        c.r = rand() % 255;
        c.g = rand() % 255;
        c.b = rand() % 255;
        m_game->assets.font.print("PRESS X TO OVERLOAD!!", 550, 550, aether::graphics::Color(255, 255, 255));
    }
    else
    {
        c.r = 0; c.g = 255; c.b = 255;
        m_game->assets.font.print("DEFEND THE PLANET!!", 550, 550, aether::graphics::Color(255, 255, 255));
    }

    aether::graphics::draw_filled_rectangle(0, 580, (get_gauge()) * 800 / Constants::MAX_GAUGE, 600, c);

    if( m_flashBang > 0 )
    {
        if( int(m_flashBang / 10e3) % 2 ) aether::graphics::clear(255, 255, 255);
    }

    m_game->assets.font.print("Strength:", 10, 550, aether::graphics::Color(255, 255, 255));
    m_game->assets.font.print("Weakness:", 200, 550, aether::graphics::Color(255, 255, 255));

    aether::graphics::Color wc, sc;
    std::string wt, st;

    switch ( m_player->element )
    {
    case Element::Water:
        wt = "Plant"; wc.g = 255;
        st = "Fire"; sc.r = 255;
        break;
    case Element::Fire:
        wt = "Water"; wc.b = 255;
        st = "Plant"; sc.g = 255;
        break;
    case Element::Plant:
        wt = "Fire"; wc.r = 255;
        st = "Water"; sc.b = 255;
        break;
    }

    m_game->assets.font.print(st.c_str(), 120, 550, sc);
    m_game->assets.font.print(wt.c_str(), 310, 550, wc);

    render_caster();

}

void GameplayScreen::update(uint64_t delta)
{

    m_starfield.update();

    if( m_flashBang > 0 )
    {
        m_flashBang -= delta;
    }

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
        if( m_nextShot <= 0 )
        {
            m_factory.makeBullet(
                        m_player->rect.x() + 60,
                        m_player->rect.y() + 5,
                        m_player->element);
            m_nextShot = Constants::SHOOT_RATE;
            m_game->assets.shoot.play(1);
        }
    }

    if( m_nextWave <= 0 )
    {
        wave();
        m_nextWave = Constants::WAVE_RATE;
    }

    if( m_nextShot > 0 ) m_nextShot -= delta;
    if( m_nextWave > 0 ) m_nextWave -= delta;

    for( auto e : get_enemy_dead() )
    {
        m_sequence.generateBack();
    }

    get_enemy_dead().clear();

    for( auto e : get_enemy_killed() )
    {
        if( e == m_sequence.top() )
        {
            m_sequence.removeTop();
        }
        else
        {
            m_sequence.generateBack();
        }
    }

    if( get_enemy_killed().size() > 0 )
    {
        m_game->assets.explosion.play(1);
    }

    get_enemy_killed().clear();

    if( get_gauge() == Constants::MAX_GAUGE && aether::core::is_key_down(aether::core::KeyCode::Z) )
    {
        reset_gauge();
        m_stage.killAll();
        m_flashBang = 10e6;
    }

    update_caster(delta);

}
