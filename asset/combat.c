#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "combat.h"

/**
 * \file combat.c
 * \brief Fonctions de combat.
 * \author Killian.R
 * \version 1.1
 * \date 24 mars 2022
 */
 
//Faire en sorte que le joueur puisse choisir son nom (struct)
void init_player(perso_t * player){

	player = malloc(sizeof(perso_t));
	player->name =  malloc(sizeof(char *));
	
	printf("Bonjour.. euh.. quel est ton nom déjà ?\n");
	scanf("%s",player->name);
	
	printf("Ah oui.. %s.. ça me reviens.\n", player->name);
	
	player->anc_coord_x = 5;
	player->anc_coord_y = 4;
	player->position = "droite"; //Si jamais le dernier déplacement est gauche on tourne le perso et on modifira cette valeur pour afficher le sprite en consequece en sdl
	player->hp = 600;
	player->dgt = 50;
	player->armor = 15;
	
	for(int i = 0; i < NB_SPELLS; i++)
	{	
		player->spell[i] = malloc(sizeof(spell_t));
		player->spell[i]->name = "vide";
		player->spell[i]->dgt = 0;
	}	

  for (int i = 0; i < TAILLE_INV; i++){
    player->objets[i] = malloc(sizeof(objet_t));
    player->objets[i]->id = -1;
    player->objets[i]->name = "VIDE";
    player->objets[i]->desc = "VIDE";
    player->objets[i]->heal = 0;
    player->objets[i]->dgt = 0;
    player->objets[i]->armor = 0;
  }
}

void init_monster(monstre_t * monster){
	monster->hp = 200;
	monster->dgt = 20;
	monster->armor = 5;
}

void tour_joueur(perso_t * player, monstre_t * monstre){
	int choix = 0; 
  int spell_num = 0;
  int dgt;

  if(player->hp > 0){
    while(choix != 1 && choix != 2){
      printf("Choisissez le mode d'attaque (1 : attaque , 2 : sort) : ");
      scanf("%d",&choix);
    }
    
    if(choix == 1)
    {
      dgt =  player->dgt - monstre->armor;
      monstre->hp -= dgt;
       if(monstre->hp < 0){
          monstre->hp = 0;
        }
      printf("Vous infligez %d dégats au monstre	     ||	HP player : %d  HP monstre : %d\n", dgt, player->hp, monstre->hp);
    }
    else if(choix == 2)
    {
      printf("Choisissez quel sort vous souhaitez utiliser.\n");
      spell_choice(player,&spell_num);
      if(spell_existe(player,spell_num) != 0)
      {
              dgt = player->spell[spell_num]->dgt - monstre->armor;
              monstre->hp -= dgt;
              if(monstre->hp < 0){
                monstre->hp = 0;
              }
      }
      else
      {
        while(spell_existe(player,spell_num) == 0)
        {
          spell_num=0;
          printf("Choisissez un sort valide.\n");
          spell_choice(player,&spell_num);
        }
        dgt = player->spell[spell_num]->dgt - monstre->armor;
        monstre->hp -= dgt;
        if(monstre->hp < 0){
          monstre->hp = 0;
        }
      }
      printf("Vous infligez %d dégats magiques au monstre  ||	HP player : %d  HP monstre : %d\n", dgt, player->hp, monstre->hp);
    }
  }
  else{
    printf("Oh.. vous avez perdu il me semble.\n");
  }
}

void tour_monstre(perso_t * player, monstre_t * monstre)
{
  int dgt;

  if(monstre->hp > 0){
    dgt = monstre->dgt - player->armor;
    player->hp -= dgt;
    if(player->hp < 0){
      player->hp = 0;
    }
    printf("Le monstre attaque ! vous prenez %d dégats    ||	HP player : %d  HP monstre : %d\n\n", dgt, player->hp, monstre->hp);
  }
  else{
    printf("Bravo ! Vous avez battu le méchant monstre\n");
  }
}

void combat(monstre_t * monstre, perso_t * player){
  //Affichage spécial du combat

  init_player(player);
  init_monster(monstre);
  add_spell(player,0,"Foudre",77); 
  
  
  while(monstre->hp > 0 && player->hp > 0){//condition de sortie à modifier avec sdl ?
	tour_joueur(player,monstre);
    	tour_monstre(player,monstre);
  }
}

