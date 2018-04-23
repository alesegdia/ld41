#include "explosioncaster.h"
#include <stdint.h>
#include <stdio.h>


static ExplosionCaster caster;


void update_caster(uint64_t delta)
{
    caster.update(delta);
}

void render_caster()
{
    caster.render();
}

void spawn_explosion(float x, float y)
{
    return caster.cast(x, y);
}


void cast_debris(float x, float y)
{
    caster.cast_debris(x, y);
}
