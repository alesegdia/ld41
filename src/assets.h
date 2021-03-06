#pragma once

#include <aether/graphics/texture.h>
#include <aether/graphics/font.h>
#include <aether/audio/stream.h>
#include <aether/audio/sample.h>

class Assets
{
public:
    void load()
    {
        drake_blue.load("media/drake_blue.png");
        drake_green.load("media/drake_green.png");
        drake_red.load("media/drake_red.png");
        drake_gold.load("media/drake_gold.png");
        planet.load("media/planet.png");

        enemy_blue.load("media/enemy_blue.png");
        enemy_green.load("media/enemy_green.png");
        enemy_red.load("media/enemy_red.png");

        bullet_red.load("media/bullet_red.png");
        bullet_green.load("media/bullet_green.png");
        bullet_blue.load("media/bullet_blue.png");

        star_red.load("media/star_red.png");
        star_green.load("media/star_green.png");
        star_blue.load("media/star_blue.png");
        splash.load("media/splash.png");

        font.load("media/perfectdos.ttf", 20);
        fontMid.load("media/perfectdos.ttf", 40);
        fontBig.load("media/perfectdos.ttf", 120);

        theme.load("media/drake_theme.ogg");

        explosion.load("media/explosion.wav");
        shoot.load("media/shoot.wav");
        hurt.load("media/hurt.wav");
        heal.load("media/heal.wav");
        overload.load("media/overload.wav");
        beep.load("media/beep.wav");

    }


    void cleanup()
    {
        drake_blue.destroy();
        drake_green.destroy();
        drake_red.destroy();
        drake_gold.destroy();
        planet.destroy();

        enemy_blue.destroy();
        enemy_green.destroy();
        enemy_red.destroy();

        bullet_blue.destroy();
        bullet_green.destroy();
        bullet_red.destroy();

        star_blue.destroy();
        star_green.destroy();
        star_red.destroy();
        splash.destroy();

        font.destroy();
        fontMid.destroy();
        fontBig.destroy();

        theme.destroy();

        shoot.destroy();
        explosion.destroy();
        hurt.destroy();
        heal.destroy();
        overload.destroy();
        beep.destroy();
    }


    aether::graphics::Texture drake_blue;
    aether::graphics::Texture drake_green;
    aether::graphics::Texture drake_red;
    aether::graphics::Texture drake_gold;
    aether::graphics::Texture planet;

    aether::graphics::Texture enemy_green;
    aether::graphics::Texture enemy_blue;
    aether::graphics::Texture enemy_red;

    aether::graphics::Texture bullet_green;
    aether::graphics::Texture bullet_blue;
    aether::graphics::Texture bullet_red;

    aether::graphics::Texture star_green;
    aether::graphics::Texture star_blue;
    aether::graphics::Texture star_red;

    aether::graphics::Texture splash;

    aether::graphics::Font font;
    aether::graphics::Font fontMid;
    aether::graphics::Font fontBig;

    aether::audio::Stream theme;

    aether::audio::Sample shoot;
    aether::audio::Sample explosion;
    aether::audio::Sample hurt;
    aether::audio::Sample heal;
    aether::audio::Sample overload;
    aether::audio::Sample beep;

};
