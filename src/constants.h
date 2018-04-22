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

    static void Level1()
    {
        SHOOT_RATE = 0.3 * 10e6;
        WAVE_RATE = 4 * 10e6;
        MAX_GAUGE = 5;
        INITIAL_STARS = 10;
        PLAYER_X_SPEED = 400;
        PLAYER_Y_SPEED = 200;
        BULLET_SPEED = 1000;
        ENEMY_SPEED = 40;
        ENEMY_HP = 8;
    }

};

