#pragma once

#include <iostream>
#include <vector>

#include <aether/graphics/graphics.h>

#include "../constants.h"
#include "gameobject.h"
#include "../explosioncaster.h"
#include "../assets.h"

class Stage
{
public:
    ~Stage();

    void update(uint64_t delta);
    void render();
    void add( GameObject::Ptr go );
    void reset();

    void killAll();

    Element getPlayerElement();


private:
    void handleCollision( GameObject::Ptr a, GameObject::Ptr b );
    bool collide( GameObject::Ptr a, GameObject::Ptr b );

    std::vector<GameObject::Ptr> m_gameObjects;
    Element m_playerElement = Element::Water;


};

void stage_set_assets(Assets* a);
