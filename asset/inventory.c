#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "inventory.h"

int add_item(perso_t * player, int id, char * name, char * desc, int heal, int dgt, int armor){
	if(player->objets[id]->id != -1){
		return(-1);
	}		 

   player->objets[id]->id = id;
   player->objets[id]->name = name;
   player->objets[id]->desc = desc;
   player->objets[id]->heal = heal;
   player->objets[id]->dgt = dgt;
   player->objets[id]->armor = armor;
   
   if(! strcmp(player->objets[id]->name,"Potion de soin")){
   	player->hp += heal;
   	player->dgt += dgt;
   	player->armor += armor;
   }
   
  return(0);
}

void del_item(perso_t * player, int id){
	player->objets[id]->id = -1;
    player->objets[id]->name = "VIDE";
    player->objets[id]->desc = "VIDE";
    player->objets[id]->heal = 0;
    player->objets[id]->dgt = 0;
    player->objets[id]->armor = 0;
}

void use_heal(perso_t * player){
	int i;
	int id = 0;
	for(i=0; i < TAILLE_INV; i++){
		if(!strcmp(player->objets[i]->name,"Potion de soin")){
			id = i;
		}
	}
	printf("%d	!\n",id);
	player->hp += player->objets[id]->heal;
	del_item(player, player->objets[id]->id);
}

void aff_inventory(perso_t * player){
  for(int i = 0; i < TAILLE_INV; i++){
   if(player->objets[i]->id > 0){
      printf("%d  : %s  : %s  : %d  : %d : %d\n", player->objets[i]->id, player->objets[i]->name, player->objets[i]->desc, 
      player->objets[i]->heal, player->objets[i]->dgt, player->objets[i]->armor);
    }
  }
}

