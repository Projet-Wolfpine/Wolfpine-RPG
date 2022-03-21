#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structures.h"

void add_spell(perso_t * player, int num_spell, char * spell_name, int dgt);

int spell_existe(perso_t * player, int num_spell);

void spell_choice(perso_t * player, int * spell_num);
