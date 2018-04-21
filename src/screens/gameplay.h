#pragma once


#include <aether/core/iscreen.h>
#include "../entity/stage.h"
#include "../entity/entityfactory.h"

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
    LD41* m_game;
    Stage m_stage;
    EntityFactory m_factory;
    GameObject::Ptr m_player = nullptr;


};
