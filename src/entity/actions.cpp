#include "actions.h"
#include <stdio.h>
#include "entityfactory.h"

static Assets* assets;
static EntityFactory* factory;

void player_change_element(GameObject::Ptr go, Element new_element)
{
    assert(go->faction == Faction::Player);
    assert(go->type == Type::Ship);
    go->element = new_element;
    switch( go->element )
    {
    case Element::Water: go->texture = assets->drake_blue; break;
    case Element::Plant: go->texture = assets->drake_green; break;
    case Element::Fire: go->texture = assets->drake_red; break;
    default: assert(false);
    }
}

void actions_init(Assets *assets_, EntityFactory* factory_)
{
    assets = assets_;
    factory = factory_;
}

void sys_move(GameObject::Ptr go, uint64_t delta)
{
    float delta_float = (double)delta / (double)10e6;
    aether::math::Vec2f distance_to_move = go->input_axis * go->base_speed * delta_float;
    go->rect.move(distance_to_move);
    if( go->rect.x() < -100 || go->rect.x() > 1200 )
    {
        go->dead = true;
    }
}

void sys_move_keyboard(GameObject::Ptr go, uint64_t delta)
{
    aether::math::Vec2f& input = go->input_axis;
    input.set(0, 0);

    if( aether::core::is_key_down(aether::core::KeyCode::Left) )
    {
        input.x(-1);
    }
    else if( aether::core::is_key_down(aether::core::KeyCode::Right) )
    {
        input.x(1);
    }

    if( aether::core::is_key_down(aether::core::KeyCode::Up) )
    {
        input.y(-1);
    }
    else if( aether::core::is_key_down(aether::core::KeyCode::Down) )
    {
        input.y(1);
    }
}

void player_step(GameObject::Ptr go, uint64_t delta)
{
    sys_move_keyboard(go, delta);
    sys_move(go, delta);
}

