#pragma once

#include <assert.h>

#include "../constants.h"
#include "../assets.h"
#include "gameobject.h"
#include "stage.h"
#include "actions.h"

class EntityFactory
{
public:
    EntityFactory(Assets& assets, Stage& stage)
        : m_assets(assets),
          m_stage(stage)
    {

    }

    GameObject::Ptr makeRandomElementEnemy(float x, float y)
    {
        int element = rand() % ((int)Element::NumElements);
        aether::graphics::Texture tex;
        switch((Element)element)
        {
        case Element::Fire: tex = m_assets.enemy_red; break;
        case Element::Plant: tex = m_assets.enemy_green; break;
        case Element::Water: tex = m_assets.enemy_blue; break;
        default: assert(false); break;
        }
        GameObject::Ptr go = makeGameObject(
            Faction::Enemy, (Element)element, Type::Ship,
            tex, x, y
        );
        go->base_speed.x(Constants::ENEMY_SPEED);
        go->input_axis.x(-1);
        go->step = &sys_move;
        go->health = Constants::ENEMY_HP;
        return go;
    }

    GameObject::Ptr makeBullet(float x, float y, Element e)
    {
        aether::graphics::Texture tex;
        switch(e)
        {
        case Element::Fire: tex = m_assets.bullet_red; break;
        case Element::Plant: tex = m_assets.bullet_green; break;
        case Element::Water: tex = m_assets.bullet_blue; break;
        default: assert(false); break;
        }
        GameObject::Ptr go = makeGameObject(
            Faction::Player, e, Type::Bullet,
            tex, x, y, Constants::BULLET_SPEED, 0, 1, 0
        );
        go->step = &sys_move;
        return go;
    }

    GameObject::Ptr makePlayer(float x, float y)
    {
        GameObject::Ptr go = makeGameObject(
            Faction::Player, Element::Plant, Type::Ship,
            m_assets.drake_green, x, y, Constants::PLAYER_X_SPEED, Constants::PLAYER_Y_SPEED
        );
        go->step = &player_step;
        return go;
    }

    GameObject::Ptr makeGameObject (
            Faction faction,
            Element element,
            Type type,
            aether::graphics::Texture texture,
            float x, float y,
            float sx = 0, float sy = 0,
            int ix = 0, int iy = 0
    )
    {
        aether::math::Rectf rect(x, y, texture.width(), texture.height());
        GameObject::Ptr go = new GameObject;
        go->faction = faction;
        go->element = element;
        go->type = type;
        go->texture = texture;
        go->rect = rect;
        go->base_speed.set(sx, sy);
        go->input_axis.set(ix, iy);
        m_stage.add(go);
        return go;
    }

private:
    Assets& m_assets;
    Stage& m_stage;

};
