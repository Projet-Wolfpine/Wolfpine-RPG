#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <math.h>
#include "../lib/fonction_sdl.h"
#include "../lib/combat.h"
#include "../lib/audio.h"

/**
 * \file combat.c
 * \brief Fonctions de combat.
 * \author Killian.R
 * \version 1.3
 * \date 04 avril 2022
 */
SDL_Color noir = {0, 0, 0};
SDL_Color rouge = {255, 0, 0};
SDL_Color blanc = {255, 255, 255};
char hp_joueur[3];
char hp_monstre[3];
char inf_dgt[2];

/**
 * \fn int __itoa(int num,char *result,int base,int nbrNum)
 * \brief fonction de convertion d'un int en char
 * \param num nombre que l'on souhaite convertir
 * \param result variable dans laquelle on stocke le résultat de la convertion
 * \param base base numérique de la convertion
 * \param nbrNum taille de caractères du résultat
 * \return 0 si tout s'est bien passé
 */
int __itoa(int num,char *result,int base,int nbrNum)
{
	int j=0;
	int i=0;
	int k=0;
	int l=0;
	int temp;
	char res[32];
	char res2[nbrNum+1];
	char cList[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	if(result==NULL || base>16 || base<2)return -1;
	j=num;
	i=31;
	while(i>=0)
		{
		l=pow(base,i);
		temp=(int)j/l;
		res[k++]=cList[temp];
		j-=temp*l;
		i--;
		}
	i=0;
	j=31-(nbrNum-1);
	for(k=j;k<32;k++)res2[i++]=res[k];

	res2[nbrNum]='\0';
	memcpy(result,res2,sizeof(res2));
	return 0;
}

/**
 * \fn perso_t init_player()
 * \brief fonction d'initialisation d'un perso_t
 * \return retourne un pointeur sur le joueur initialisé
 */
perso_t init_player(){
	perso_t * player = malloc(sizeof(perso_t));
	player->name =  malloc(sizeof(char *));
	player->anc_coord_x = 5;
	player->anc_coord_y = 4;
	player->position = "droite"; //Si jamais le dernier déplacement est gauche on tourne le perso et on modifira cette valeur pour afficher le sprite en consequece en sdl
	player->hp = PLAYER_HP;
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
  return *player;
}

/**
 * \fn perso_t free_player(perso_t * player)
 * \brief Libère la mémoire associée à un perso_t
 * \param player adresse du perso_t concerné
 */
void free_player(perso_t * player){
	for (int i = 0; i < NB_SPELLS; i++){
		
		free(player->spell[i]);
		player->spell[i] = NULL;
		
	} 
	for (int j = 0; j < TAILLE_INV; j++){
		
		free(player->objets[j]);
		player->objets[j] = NULL;
		
	} 
	
	free(player->name);
	player->name = NULL;
	
	free(player);
	player = NULL;
	
}

/**
 * \fn void init_monster(monstre_t * monster, char * name, char * sprite, int hp, int dgt, int armor)
 * \brief fonction d'initialisation d'un monstre_t
 * \param monster monstre_t dans lequel va être renvoyé le monstre 
 * \param name nom associé au monstre
 * \param sprite texture d'affichage du monstre
 * \param hp nombre de points de vie du monstre
 * \param dgt nombre de dégats du monstre
 * \param armor nombre de résistance du monstre
 * \return retourne un pointeur sur le joueur initialisé
 */
void init_monster(monstre_t * monster, char * name, char * sprite, int hp, int dgt, int armor){
	monster->name =  malloc(sizeof(char *));
	monster->sprite =  malloc(sizeof(char *));
	strcpy(monster->name,name);
	strcpy(monster->sprite,sprite);
	monster->hp = hp;
	monster->dgt = dgt;
	monster->armor = armor;
}

/**
 * \fn void aff_info(perso_t * player, monstre_t * monstre, char * fond, char * sprite)
 * \brief fonction d'affichage d'information durant le combat
 * \param player personnage concerné par le combat
 * \param monstre monstre concerné par le combat
 * \param fond texture affichée en background
 * \param sprite texture du monstre à afficher
 */
void aff_info(perso_t * player, monstre_t * monstre, char * fond, char * sprite){

	if(!strcmp(fond,"combat.png")){
		drawImage(0, 0, fond, 1920, 1080);
		drawImage(700,200,sprite, 520, 520);
		__itoa(player->hp,hp_joueur,10,3);
		drawText(490,900,hp_joueur,60,40,rouge);
		drawText(720,900,"ATQ",60,40,noir);
		drawText(1020,900,"SORT",60,40,noir);
		drawText(1380,900,"INV",60,40,noir);
		drawText(820,150,monstre->name,60,40,blanc);
		__itoa(monstre->hp,hp_monstre,10,3);
		drawText(1700,85,hp_monstre,60,40,rouge);
		faire_rendu();
	}
	else if(!strcmp(fond,"spells.png")){
		drawImage(0, 0, fond, 1920, 1080);
		drawImage(700,200,sprite, 520, 520);
		drawImage(1580,820,"exit_cross.png", 50, 50);

		//Spells
		if(spell_existe(player,0) != 0){
			drawText(650,900,player->spell[0]->name,60,40,noir);
		}
		if(spell_existe(player,1) != 0){
			drawText(930,900,player->spell[1]->name,60,40,noir);
		}
		if(spell_existe(player,2) != 0){
			drawText(1250,900,player->spell[2]->name,60,40,noir);
		}
		__itoa(player->hp,hp_joueur,10,3);
		drawText(490,900,hp_joueur,60,40,rouge);
		drawText(820,150,monstre->name,60,40,blanc);
		__itoa(monstre->hp,hp_monstre,10,3);
		drawText(1700,85,hp_monstre,60,40,rouge);
		faire_rendu();
	}
	else{
		drawImage(0, 0, "spells.png", 1920, 1080);
		drawImage(700,200,sprite, 520, 520);
		drawImage(1580,820,"exit_cross.png", 50, 50);
		if(!strcmp(player->objets[3]->name,"Potion de soin")){
			drawText(900,900,"Potion de soin",60,40,rouge);
		}
		__itoa(player->hp,hp_joueur,10,3);
		drawText(490,900,hp_joueur,60,40,rouge);
		drawText(820,150,monstre->name,60,40,blanc);
		__itoa(monstre->hp,hp_monstre,10,3);
		drawText(1700,85,hp_monstre,60,40,rouge);
		faire_rendu();
	}
}

/**
 * \fn void tour_joueur(perso_t * player, monstre_t * monstre)
 * \brief fonction d'attaque du joueur
 * \param player personnage concerné par le combat
 * \param monstre monstre concerné par le combat
 */
void tour_joueur(perso_t * player, monstre_t * monstre){
	SDL_Event event;
	int choix = 0; 
	int spell_num = 0;
	int dgt;
	int spell_choose = -1;
	int heal = -1;
	int combat = -1;
	int souris_x=0, souris_y=0;
  
  	if(player->hp > 0){


		SDL_GetMouseState(&souris_x, &souris_y);
		while(combat == -1 && monstre->hp > 0){
			aff_info(player,monstre, "combat.png", monstre->sprite);
			
		 	if (SDL_WaitEvent(&event) != 0) {
				switch(event.type){
				case SDL_MOUSEBUTTONDOWN:
					SDL_GetMouseState(&souris_x, &souris_y);

					if((souris_x >= 720 && souris_x <=1000) && (souris_y >= 900 && souris_y <=960)){
						dgt =  player->dgt - monstre->armor;
						monstre->hp -= dgt;
						if(monstre->hp < 0){
							monstre->hp = 0;
						}

						aff_info(player,monstre, "combat.png", monstre->sprite);
						combat = 0; break;
					}

					if((souris_x >= 1020 && souris_x <=1350) && (souris_y >= 900 && souris_y <=960)){
						aff_info(player,monstre, "spells.png", monstre->sprite);
						
						while(spell_choose == -1){
							if (SDL_WaitEvent(&event) != 0) {
								switch(event.type){
								case SDL_MOUSEBUTTONDOWN:
									SDL_GetMouseState(&souris_x, &souris_y);

									if((souris_x >= 650 && souris_x <=800) && (souris_y >= 900 && souris_y <=950)){
										if(spell_existe(player,0) != 0){
											dgt = player->spell[0]->dgt - monstre->armor;
											monstre->hp -= dgt;
											if(monstre->hp < 0){
												monstre->hp = 0;
											}

											SDL_Init(SDL_INIT_AUDIO);
    	
											initAudio();
											playSound("sounds/thunder.wav", SDL_MIX_MAXVOLUME / 6);
											drawImage(700,200,"thunder.png", 520, 520);
											faire_rendu();
											SDL_Delay(500);
											
											aff_info(player,monstre, "combat.png", monstre->sprite);

											endAudio();
										
											spell_choose = 0;
										}
									}


									if((souris_x >= 930 && souris_x <=1100) && (souris_y >= 900 && souris_y <=950)){
										if(spell_existe(player,1) != 0){
											dgt = player->spell[0]->dgt - monstre->armor;
											monstre->hp -= dgt;
											if(monstre->hp < 0){
												monstre->hp = 0;
											}

											aff_info(player,monstre, "combat.png", monstre->sprite);
											spell_choose = 0;
										}
									}

									if((souris_x >= 1250 && souris_x <=1400) && (souris_y >= 900 && souris_y <=950)){
										if(spell_existe(player,1) != 0){
											dgt = player->spell[0]->dgt - monstre->armor;
											monstre->hp -= dgt;
											if(monstre->hp < 0){
												monstre->hp = 0;
											}

											aff_info(player,monstre, "combat.png", monstre->sprite);
											spell_choose = 0;
										}
									}

									//Cas de sortie
									if((souris_x >= 1580 && souris_x <=1630) && (souris_y >= 820 && souris_y <=870)){
										tour_joueur(player,monstre);
										spell_choose = 0; combat = 0; break;
									}
								}
							}
						}
						combat = 0; break;
					}

					if((souris_x >= 1380 && souris_x <=1640) && (souris_y >= 900 && souris_y <=950)){
						aff_info(player,monstre, "heal.png", monstre->sprite);
						while(heal == -1){
							if (SDL_WaitEvent(&event) != 0) {
								switch(event.type){
								case SDL_MOUSEBUTTONDOWN:
									SDL_GetMouseState(&souris_x, &souris_y);

									if((souris_x >= 900 && souris_x <=1630) && (souris_y >= 900 && souris_y <=950)){
										if(!strcmp(player->objets[3]->name,"Potion de soin")){
											use_heal(player);
											heal = 0;
										}
									}
									

									//Cas de sortie
									if((souris_x >= 1580 && souris_x <=1630) && (souris_y >= 820 && souris_y <=870)){
										tour_joueur(player,monstre);
										heal = 0; combat = 0; break;
									}
									
								}
							}
						}
					}
					combat = 0; break;
					
				}
			}
		}
  	}
}

/**
 * \fn void tour_monstre(perso_t * player, monstre_t * monstre)
 * \brief fonction d'attaque du monstre
 * \param player personnage concerné par le combat
 * \param monstre monstre concerné par le combat
 */
void tour_monstre(perso_t * player, monstre_t * monstre)
{
  	int dgt;
  	int crit;
  
	srand(time(0));
	aff_info(player,monstre, "combat.png", monstre->sprite);
	
  	if(monstre->hp > 0){
  		crit = rand() % 101;
  	if(crit >= 95){
  		dgt = monstre->dgt - player->armor;
  		dgt += 15;
  		player->hp -= dgt;
  	}
  	else{
  		dgt = monstre->dgt - player->armor;
		player->hp -= dgt;
	}
    if(player->hp < 0){
      player->hp = 0;
      printf("%s attaque ! vous prenez %d dégats    ||	HP player : %d  HP monstre : %d\n\n",monstre->name, dgt, player->hp, monstre->hp);
      printf("Oh.. vous avez perdu il me semble.\n");
	}
 	else{
 		printf("%s attaque ! vous prenez %d dégats    ||	HP player : %d  HP monstre : %d\n\n",monstre->name, dgt, player->hp, monstre->hp);
 	}
  }
  else{
	drawText(820,200,"est mort !",60,40,blanc);
  	faire_rendu();
  }

  		
}

/**
 * \fn void combat(perso_t * player, monstre_t * monstre)
 * \brief fonction de lancement du combat au tour par tour
 * \param player adresse du personnage concerné par le combat
 * \param monstre adresse du monstre concerné par le combat
 */
perso_t combat(perso_t * player, monstre_t * monstre){

  while(monstre->hp > 0 && player->hp > 0){
	tour_joueur(player,monstre);
    tour_monstre(player,monstre);
  }
  
  return(*player);
}
