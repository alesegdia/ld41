#pragma once

#include <aether/core/iscreen.h>

#include "../entity/stage.h"
#include "../entity/entityfactory.h"
#include "../starsequence.h"
#include "../starfield.h"

class LD41;

class GameplayScreen : public aether::core::IScreen
{
public:
    GameplayScreen(LD41* game);

    void show() final;
    void hide() final;
    void render() final;
    void update(uint64_t delta) final;


private:

    void wave()
    {
        for( int i = 0; i < 4; i++ )
        {
            m_factory.makeRandomElementEnemy(800, 80 + 116 * i);
        }
    }

    LD41* m_game;
    Stage m_stage;
    EntityFactory m_factory;
    GameObject::Ptr m_player = nullptr;
    int m_nextShot = 0;
    int m_nextWave = 0;
    int m_flashBang = 0;
    StarSequence m_sequence;
    Starfield m_starfield;


};
