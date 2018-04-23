#pragma once

#include <aether/core/iscreen.h>

class LD41;

class MenuScreen : public aether::core::IScreen
{
public:
    MenuScreen(LD41* game);

    void show() final;
    void hide() final;
    void render() final;
    void update(uint64_t delta) final;

private:
    LD41* m_game;
    float m_textPos = 50;

};
