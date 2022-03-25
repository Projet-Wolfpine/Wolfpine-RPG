#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "inventory.h"


/**
 * \file inventory.c
 * \brief Fonctions d'utilisation et de gestion de l'inventaire.
 * \author Killian.R
 * \version 1.0
 * \date 23 mars 2022
 */
 
 
/**
 * \fn void add_item (perso_t * player, int id, char * name, char * desc, int heal, int dgt, int armor)
 * \brief Fonction d'ajout d'un item dans l'inventaire.
 * 
 * \param player Perso_t auquel on souhaite ajouter l'item.
 * \param id Numéro affecté à l'item.
 * \param name Nom que l'on souhaite attribuer à cet item.
 * \param desc Courte description de l'item.
 * \param heal Nombre de HP donnés par l'item.
 * \param dgt Nombre de dégats de l'item.
 * \param armor Nombre d'armure ajoutée par l'item.
 * \return On retourne 0 si l'ajout s'est bien passé, -1 si on possède déjà un item comportant cet id.
 */ 
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
   
   if(strcmp(player->objets[id]->name,"Potion de soin")){
   	player->hp += heal;
   	player->dgt += dgt;
   	player->armor += armor;
   }

   
  return(0);
}

/**
 * \fn void del_item(perso_t * player, int id)
 * \brief Fonction de destruction d'un item dans l'inventaire.
 * 
 * \param player Perso_t auquel on souhaite retirer l'item.
 * \param id Numéro affecté à l'item.
 */ 
void del_item(perso_t * player, int id){
	player->objets[id]->id = -1;
    player->objets[id]->name = "VIDE";
    player->objets[id]->desc = "VIDE";
    player->objets[id]->heal = 0;
    player->objets[id]->dgt = 0;
    player->objets[id]->armor = 0;
}

/**
 * \fn void use_heal(perso_t * player)
 * \brief Fonction d'utilisation d'une potion stockée dans l'inventaire.
 * 
 * \param player Perso_t auquel on souhaite appliquer la potion.
 */ 
void use_heal(perso_t * player){
	int i;
	int id = 0;
	
	printf("Hp : %d\n",player->hp);
	
	for(i=0; i < TAILLE_INV; i++){
		if(!strcmp(player->objets[i]->name,"Potion de soin")){
			id = i;
		}
	}
	
	if(player->hp + player->objets[id]->heal > PLAYER_HP){
		player->hp += player->objets[id]->heal;
		player->hp -= player->hp - PLAYER_HP;
	}
	else{
		player->hp += player->objets[id]->heal;
	}
	del_item(player, player->objets[id]->id);
	printf("Hp : %d\n",player->hp);
}

/**
 * \fn void aff_inventory(perso_t * player)
 * \brief Fonction d'affichage de l'inventaire.
 * 
 * \param player Perso_t à qui appartient l'inventaire que l'on souhaite afficher.
 */ 
void aff_inventory(perso_t * player){
  for(int i = 0; i < TAILLE_INV; i++){
   if(player->objets[i]->id > 0){
      printf("%d  : %s  : %s  : %d  : %d : %d\n", player->objets[i]->id, player->objets[i]->name, player->objets[i]->desc, 
      player->objets[i]->heal, player->objets[i]->dgt, player->objets[i]->armor);
    }
  }
}

