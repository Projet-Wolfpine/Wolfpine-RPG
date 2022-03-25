#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "combat.h"

void main(){
	perso_t player;
	player=init_player();
	player.hp -= 5;
	printf("Hp : %d\n",player.hp);
	add_item(&player, 1, "Potion de soin", "Vous donne 15 hp", 15, 0, 0);
	aff_inventory(&player);
	use_heal(&player);
	aff_inventory(&player);
	
}
