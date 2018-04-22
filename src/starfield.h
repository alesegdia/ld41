#pragma once

#include <aether/graphics/graphics.h>

#include <vector>

class Star
{
public:
    Star()
    {
        x = rand() % 800;
        y = rand() % 600;
        z = rand() % 3 + 1;
    }


    void update()
    {
        if( x < 0 )
        {
            x = 800;
            y = rand() % 600;
            z = rand() % 3 + 1;
        }

        constexpr int SPEED = 4;
        x -= z * SPEED;
    }

    void draw()
    {
        int tone = 128 + 128 / 3 * z;
        aether::graphics::draw_filled_rectangle(
                    x, y,
                    x + z * 1,
                    y + z * 1,
                    aether::graphics::Color(tone, tone, tone));
    }

private:
    float x, y, z;

};

class Starfield
{
public:
    Starfield(int n)
    {
        while( n-- > 0 )
        {
            m_stars.push_back(Star());
        }
    }

    void update()
    {
        for( auto& s : m_stars )
        {
            s.update();
        }
    }

    void render()
    {
        for( auto s : m_stars )
        {
            s.draw();
        }
    }

private:
    std::vector<Star> m_stars;

};
