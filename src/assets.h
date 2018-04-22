#pragma once

#include <aether/graphics/texture.h>

class Assets
{
public:
    void load()
    {
        drake_blue.load("media/drake_blue.png");
        drake_green.load("media/drake_green.png");
        drake_red.load("media/drake_red.png");

        enemy_blue.load("media/enemy_blue.png");
        enemy_green.load("media/enemy_green.png");
        enemy_red.load("media/enemy_red.png");

        bullet_red.load("media/bullet_red.png");
        bullet_green.load("media/bullet_green.png");
        bullet_blue.load("media/bullet_blue.png");
    }

    void cleanup()
    {
        drake_blue.destroy();
        drake_green.destroy();
        drake_red.destroy();

        enemy_blue.destroy();
        enemy_green.destroy();
        enemy_red.destroy();

        bullet_blue.destroy();
        bullet_green.destroy();
        bullet_red.destroy();
    }

    aether::graphics::Texture drake_blue;
    aether::graphics::Texture drake_green;
    aether::graphics::Texture drake_red;

    aether::graphics::Texture enemy_green;
    aether::graphics::Texture enemy_blue;
    aether::graphics::Texture enemy_red;

    aether::graphics::Texture bullet_green;
    aether::graphics::Texture bullet_blue;
    aether::graphics::Texture bullet_red;

};