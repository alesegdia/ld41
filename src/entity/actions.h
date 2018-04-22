#pragma once

#include <assert.h>
#include "gameobject.h"
#include "../assets.h"

#include <vector>

#include <aether/core/input.h>

class EntityFactory;

void player_change_element(GameObject::Ptr go, Element new_element);

void actions_init( Assets* assets, EntityFactory* factory );

void player_step(GameObject::Ptr go, uint64_t delta);

void enemy_step(GameObject::Ptr go, uint64_t delta);

void sys_move(GameObject::Ptr go, uint64_t delta);

std::vector<Element>& get_enemy_dead();

std::vector<Element>& get_enemy_killed();

void inc_gauge();

int get_gauge();

void reset_gauge();
