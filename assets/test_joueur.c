#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "combat.h"

void main(){
	perso_t player;
	player=init_player();
	case_t mat[Y][X];
	init_mat(mat);
	
	monstre_t monstre;
	init_monster(&monstre, "Wolfy", 150, 25, 5);
  	printf("Init monster OK\n");

	
	combat(&player, &monstre);
	
	printf("HP : %d\n", player.hp);
	
	add_spell(&player,0,"Foudre",77); 
  	printf("Add spell OK\n");
	
	monstre_t monstre2;
	init_monster(&monstre2, "Le mechant", 250, 1000, 10);
	combat(&player, &monstre2);

}
