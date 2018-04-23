#pragma once

#include <vector>

#include <aether/graphics/graphics.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


struct Explosion
{
    Explosion(float xx, float yy)
    {
        x = xx;
        y = yy;
    }
    float x, y;
    int numExplosions = 10;
    int nextExplosion = 0;
    int update( uint64_t d )
    {
        nextExplosion -= d;
        if( nextExplosion <= 0 )
        {
            nextExplosion = 0.001 * 10e6;
            numExplosions--;
            int s = 5 + rand() % 30;
            return s;
        }
        return 0;
    }
};

struct Debris
{
    int size = 10;
    float x, y;
    int speed = 30;
    Debris(int s, float xx, float yy)
    {
        size = s;
        x = xx;
        y = yy;
        speed = 10 + rand() % 30;
    };

    void update()
    {
        x -= speed;
    }

    void render()
    {
        aether::graphics::draw_filled_circle(x, y, size, aether::graphics::Color(255, 255, 255));
    }
};

class ExplosionCaster
{
public:
    void cast(float x, float y)
    {
        m_explosions.push_back(Explosion(x, y));
    }

    void update(uint64_t d)
    {
        bool clear = true;
        for( auto& e : m_explosions )
        {
            int ret = e.update(d);
            if( ret != 0 )
            {
                m_debris.push_back(Debris(ret, e.x + rand() % 80, e.y + rand() % 80));
            }
            if( e.numExplosions > 0 )
            {
                clear = false;
            }
        }

        if( clear )
        {
            m_explosions.clear();
        }

        for( auto it = m_debris.begin(); it != m_debris.end(); )
        {
            (*it).update();
            if( (*it).x < 0 )
            {
                it = m_debris.erase(it);
            }
            else
            {
                it++;
            }
        }

    }

    void render()
    {
        for( auto e : m_debris )
        {
            e.render();
        }
    }

    void cast_debris(float x, float y)
    {
        m_debris.push_back(Debris(
                               5 + rand()%10,
                               x, y));
    }

private:
    std::vector<Explosion> m_explosions;
    std::vector<Debris> m_debris;

};

void update_caster(uint64_t delta);

void render_caster();

void spawn_explosion(float x, float y);

void cast_debris(float x, float y);


