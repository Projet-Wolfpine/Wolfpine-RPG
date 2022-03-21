#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structures.h"

void init_player(perso_t * player);

void init_monster(monstre_t * monster);

void tour_joueur(perso_t * player, monstre_t * monstre);

void tour_monstre(perso_t * player, monstre_t * monstre);

void combat(monstre_t * monstre, perso_t * player);
