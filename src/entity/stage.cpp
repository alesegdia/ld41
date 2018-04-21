#include "stage.h"

#include <algorithm>

Stage::~Stage()
{
    for( auto go : m_gameObjects )
    {
        delete go;
    }
}

Element new_player_element = Element::Water;

// mismo color, quitas 1 solo
// color debil, matas del tiron
// color fuerte, +1 bola
void Stage::update(uint64_t delta)
{
    m_playerElement = new_player_element;

    std::vector<GameObject::Ptr> to_remove;

    for( auto goA : m_gameObjects )
    {
        if( ! goA->isDead() )
        {
            for( auto goB : m_gameObjects )
            {
                if( collide(goA, goB) )
                {
                    handleCollision(goA, goB);
                }
            }
        }
        else
        {
            to_remove.push_back(goA);
        }
    }

    for( auto go : to_remove )
    {
        auto& v = m_gameObjects;
        v.erase(std::remove(v.begin(), v.end(), go), v.end());
        delete go;
    }

    for( auto go : m_gameObjects )
    {
        if( go->step != nullptr )
        {
            go->step(go, delta);
        }
    }
}

void Stage::render()
{
    for( auto go : m_gameObjects )
    {
        auto r = go->rect;
        go->texture.draw(r.x(), r.y());
        aether::graphics::Color c(255, 0, 0);
        aether::graphics::draw_rectangle(r.x1(), r.y1(), r.x2(), r.y2(), c);
    }
}

void Stage::add(GameObject::Ptr go)
{
    m_gameObjects.push_back(go);
}

void Stage::reset()
{
    for( auto go : m_gameObjects )
    {
        delete go;
    }
}

Element Stage::getPlayerElement()
{
    return m_playerElement;
}

typedef void (*CollisionCallback)(GameObject::Ptr a, GameObject::Ptr b);


void handle_ship_bullet_collision(GameObject::Ptr ship, GameObject::Ptr bullet)
{
    bullet->dead = true;
    switch(getEffectiveness(bullet->element, ship->element))
    {
    case Effectiveness::Neutral:
        ship->health -= 1;
        break;
    case Effectiveness::Strong:
        ship->dead = true;
        break;
    case Effectiveness::Weak:
        ship->health = 5;
        new_player_element = ship->element;
        break;
    }
}

void handle_ship_ship_collision(GameObject::Ptr ship1, GameObject::Ptr ship2)
{
    fflush(stdout);
    ship1->dead = true;
    ship2->dead = true;
}

void handle_collision(GameObject::Ptr g1, GameObject::Ptr g2, Type t1, Type t2, CollisionCallback cc)
{

    if( g1->type == t1 && g2->type == t2 ) {
        cc(g1, g2);
    } else if( g1->type == t2 && g2->type == t1 ) {
        cc(g2, g1);
    }
}


void Stage::handleCollision(GameObject::Ptr a, GameObject::Ptr b)
{
    // we can suppose they are of different faction
    handle_collision(a, b, Type::Ship, Type::Bullet, &handle_ship_bullet_collision);
    handle_collision(a, b, Type::Ship, Type::Ship, &handle_ship_ship_collision);
}


bool Stage::collide(GameObject::Ptr a, GameObject::Ptr b)
{
    if( a->faction != b->faction )
    {
        if( aether::math::intersect(a->rect, b->rect) )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
