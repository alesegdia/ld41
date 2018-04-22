#pragma once

#include <iostream>
#include <vector>

#include <aether/graphics/graphics.h>

#include "gameobject.h"
#include "../explosioncaster.h"

class Stage
{
public:
    ~Stage();

    void update(uint64_t delta);
    void render();
    void add( GameObject::Ptr go );
    void reset();

    void killAll()
    {
        for( auto go : m_gameObjects )
        {
            if( go->type == Type::Ship && go->faction == Faction::Enemy )
            {
                go->dead = true;
                spawn_explosion(go->rect.x(), go->rect.y());
            }
        }
    }

    Element getPlayerElement();


private:
    void handleCollision( GameObject::Ptr a, GameObject::Ptr b );
    bool collide( GameObject::Ptr a, GameObject::Ptr b );

    std::vector<GameObject::Ptr> m_gameObjects;
    Element m_playerElement = Element::Water;


};
