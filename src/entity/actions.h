#pragma once

#include <assert.h>
#include "gameobject.h"
#include "../assets.h"

#include <aether/core/input.h>

class EntityFactory;

void player_change_element(GameObject::Ptr go, Element new_element);

void actions_init( Assets* assets, EntityFactory* factory );

void player_step(GameObject::Ptr go, uint64_t delta);

void enemy_step(GameObject::Ptr go, uint64_t delta);

void sys_move(GameObject::Ptr go, uint64_t delta);
