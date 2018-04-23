#pragma once

#include <stdint.h>
#include <aether/graphics/texture.h>
#include <aether/math/vec.h>
#include <deque>

enum class Faction : uint8_t
{
    Player, Enemy
};

enum class Element : uint8_t
{
    Fire = 0,
    Water,
    Plant,
    NumElements
};

enum class Type : uint8_t
{
    Bullet, Ship
};

enum class Effectiveness : uint8_t
{
    Strong, Weak, Neutral
};

Effectiveness getEffectiveness( Element e1, Element e2 );

class GameObject;

typedef void (*Step)(GameObject*, uint64_t delta);

class GameObject
{
public:
    typedef GameObject* Ptr;

    bool isDead()
    {
        return dead || this->health <= 0;
    }

    Step step = nullptr;
    Faction faction;
    Element element;
    Type type;
    aether::graphics::Texture texture;
    bool dead = false;
    int health = 1;
    aether::math::Rectf rect;
    aether::math::Vec2f actual_speed = aether::math::Vec2f(0, 0);
    aether::math::Vec2f base_speed = aether::math::Vec2f(1, 1);
    aether::math::Vec2f input_axis = aether::math::Vec2f(0, 0);
    std::deque<aether::math::Vec2f> pos_buffer;
};
