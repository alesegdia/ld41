#pragma once

#include <deque>

#include "entity/gameobject.h"
#include "assets.h"
#include "assert.h"


class StarSequence
{
public:
    StarSequence(Assets& assets)
        : m_assets(assets)
    {

    }

    void reset(int n)
    {
        m_sequence.clear();

        for( int i = 0; i < n; i++ )
        {
            generateBack();
        }
    }

    void generateBack()
    {
        m_sequence.push_back( (Element) (rand()%3) );
    }

    Element top()
    {
        return m_sequence.front();
    }

    void render(float x, float y)
    {
        int i = 0;
        for( auto e : m_sequence )
        {
            aether::graphics::Texture texture;
            switch(e)
            {
            case Element::Water: texture = m_assets.star_blue; break;
            case Element::Plant: texture = m_assets.star_green; break;
            case Element::Fire: texture = m_assets.star_red; break;
            default: assert(false); break;
            }
            texture.draw(x + i * 20, y);
            i++;
        }
    }

    void removeTop()
    {
        m_sequence.pop_front();
    }


private:
    std::deque<Element> m_sequence;
    Assets& m_assets;


};
