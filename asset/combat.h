#ifndef _COMBAT_H
#define _COMBAT_H
#include "structures.h"
#include "spells.h"
#include "inventory.h"
#include "deplacement.h"
//#include "dungeon.h"



perso_t init_player();

void init_monster(monstre_t * monster, char * name, int hp, int dgt, int armor);

void tour_joueur(perso_t * player, monstre_t * monstre);

void tour_monstre(perso_t * player, monstre_t * monstre);

perso_t combat(perso_t * player, monstre_t * monstre);

#endif
