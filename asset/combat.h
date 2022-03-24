#ifndef _STRUCTURES_H
#define _STRUCTURES_H
#include "combat.h"
#include "spells.h"
#include "inventory.h"
#include "deplacement.h"


perso_t init_player(perso_t * player);

void free_player(perso_t player);

void init_monster(monstre_t * monster);

void tour_joueur(perso_t * player, monstre_t * monstre);

void tour_monstre(perso_t * player, monstre_t * monstre);

void combat(monstre_t * monstre, perso_t * player);

#endif
