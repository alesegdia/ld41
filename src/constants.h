#pragma once

class Constants
{
public:
    static int SHOOT_RATE;
    static int WAVE_RATE;
    static int MAX_GAUGE;
    static int INITIAL_STARS;
    static int PLAYER_X_SPEED;
    static int PLAYER_Y_SPEED;
    static int BULLET_SPEED;
    static int ENEMY_SPEED;
    static int ENEMY_HP;
    static constexpr int MAX_LEVEL = 4;

    static void ConfigLevel(int level)
    {
        switch( level )
        {
        case 1: Constants::Level1(); break;
        case 2: Constants::Level2(); break;
        case 3: Constants::Level3(); break;
        }
    }

    static void Level1()
    {
        SHOOT_RATE = 0.3 * 10e6;
        WAVE_RATE = 4 * 10e6;
        MAX_GAUGE = 5;
        INITIAL_STARS = 3;
        PLAYER_X_SPEED = 400;
        PLAYER_Y_SPEED = 200;
        BULLET_SPEED = 1000;
        ENEMY_SPEED = 40;
        ENEMY_HP = 4;
    }


    static void Level2()
    {
        SHOOT_RATE = 0.3 * 10e6;
        WAVE_RATE = 4 * 10e6;
        MAX_GAUGE = 4;
        INITIAL_STARS = 4;
        PLAYER_X_SPEED = 400;
        PLAYER_Y_SPEED = 200;
        BULLET_SPEED = 1000;
        ENEMY_SPEED = 50;
        ENEMY_HP = 6;
    }

    static void Level3()
    {
        SHOOT_RATE = 0.3 * 10e6;
        WAVE_RATE = 4 * 10e6;
        MAX_GAUGE = 5;
        INITIAL_STARS = 5;
        PLAYER_X_SPEED = 400;
        PLAYER_Y_SPEED = 200;
        BULLET_SPEED = 1000;
        ENEMY_SPEED = 50;
        ENEMY_HP = 8;
    }

};

