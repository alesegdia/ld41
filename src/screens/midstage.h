#pragma once

#include <aether/core/iscreen.h>

class LD41;

class MidstageScreen : public aether::core::IScreen
{
public:
    MidstageScreen(LD41* game);

    void show() final;
    void hide() final;
    void render() final;
    void update(uint64_t delta) final;

    int state = 0;

private:
    LD41* m_game;

};
