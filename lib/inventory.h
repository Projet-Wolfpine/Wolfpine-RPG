#ifndef _INVENTORY_H
#define _INVENTORY_H
#include "structures.h"

int add_item(perso_t * player, int id, char * name, char * desc, int heal, int dgt, int armor);

void del_item(perso_t * player, int id);

void use_heal(perso_t * player);

void aff_inventory(perso_t * player);

#endif

