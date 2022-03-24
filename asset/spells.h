#ifndef _STRUCTURES_H
#define _STRUCTURES_H
#include "combat.h"
#include "spells.h"
#include "inventory.h"
#include "deplacement.h"


void add_spell(perso_t * player, int num_spell, char * spell_name, int dgt);

int spell_existe(perso_t * player, int num_spell);

void spell_choice(perso_t * player, int * spell_num);

#endif
