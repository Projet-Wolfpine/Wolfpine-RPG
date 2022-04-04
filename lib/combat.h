#ifndef _COMBAT_H
#define _COMBAT_H
#include "structures.h"
#include "spells.h"
#include "inventory.h"
#include "deplacement.h"

perso_t init_player();

void init_monster(monstre_t * monster, char * name, char * sprite, int hp, int dgt, int armor);

void aff_info(perso_t * player, monstre_t * monstre, char * fond, char * sprite);

void tour_joueur(perso_t * player, monstre_t * monstre);

void tour_monstre(perso_t * player, monstre_t * monstre);

perso_t combat(perso_t * player, monstre_t * monstre);

#endif
