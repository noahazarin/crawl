#ifndef SPL_TRANSLOC_H
#define SPL_TRANSLOC_H

#include "spl-cast.h"

spret_type cast_disjunction(int pow, bool fail);
void disjunction();

spret_type cast_blink(bool fail = false);
spret_type cast_controlled_blink(bool fail = false, bool safe = true);
void uncontrolled_blink(bool override_stasis = false);
spret_type controlled_blink(bool fail, bool safe_cancel = true);
void wizard_blink();

void you_teleport();
void you_teleport_now(bool wizard_tele = false, bool teleportitis = false);
bool you_teleport_to(const coord_def where,
                     bool move_monsters = false);

spret_type cast_portal_projectile(int pow, bool fail);

struct bolt;
spret_type cast_apportation(int pow, bolt& beam, bool fail);
spret_type cast_golubrias_passage(const coord_def& where, bool fail);

spret_type cast_dispersal(int pow, bool fail = false);

int gravitas_range(int pow, int strength = 1);
void attract_actor(const actor* agent, actor* victim, const coord_def pos,
                   int pow, int strength);
bool fatal_attraction(const coord_def& pos, actor *agent, int pow);
spret_type cast_gravitas(int pow, const coord_def& where, bool fail);
#endif
