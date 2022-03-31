#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<time.h>
#include "combat.h"

/**
 * \file combat.c
 * \brief Fonctions de combat.
 * \author Killian.R
 * \version 1.1
 * \date 24 mars 2022
 */
SDL_Color noir = {0, 0, 0};
char hp_joueur[3];
char hp_monstre[3];
char inf_dgt[2];

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
	//printf("res2=%s \n",res2);
	memcpy(result,res2,sizeof(res2));
	return 0;
}

//Faire en sorte que le joueur puisse choisir son nom (struct)
perso_t init_player(){
	perso_t * player = malloc(sizeof(perso_t));
	player->name =  malloc(sizeof(char *));
	
	//printf("Bonjour.. euh.. quel est ton nom déjà ?\n");
	//scanf("%s",player->name);
	
	//printf("Ah oui.. %s.. ça me reviens.\n", player->name);
	
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

void init_monster(monstre_t * monster, char * name, int hp, int dgt, int armor){
	monster->name =  malloc(sizeof(char *));
	strcpy(monster->name,name);
	monster->hp = hp;
	monster->dgt = dgt;
	monster->armor = armor;
}

void tour_joueur(perso_t * player, monstre_t * monstre){
	int choix = 0; 
	int spell_num = 0;
	int dgt;
  
  	if(player->hp > 0){
		SDL_Event event;
		int combat = -1;
		int souris_x=0, souris_y=0;
		int spell_choose = 0;
		bool exit = FALSE;

		SDL_GetMouseState(&souris_x, &souris_y);
		while(combat == -1 && monstre->hp > 0){
			drawImage(0, 0, "combat.png", 1920, 1080);
			drawImage(700,200,"wolfy.png", 520, 520);
			__itoa(player->hp,hp_joueur,10,3);
			drawText(480,920,hp_joueur,30,30,noir);
			drawText(850,150,monstre->name,40,40,noir);
			__itoa(monstre->hp,hp_monstre,10,3);
			drawText(1700,80,hp_monstre,30,30,noir);
			faire_rendu();
			
		 	if (SDL_WaitEvent(&event) != 0) {
				switch(event.type){
				case SDL_MOUSEBUTTONDOWN:
					SDL_GetMouseState(&souris_x, &souris_y);

					if((souris_x >= 700 && souris_x <=825) && (souris_y >= 900 && souris_y <=950)){
						dgt =  player->dgt - monstre->armor;
						monstre->hp -= dgt;
						if(monstre->hp < 0){
							monstre->hp = 0;
						}
						/*__itoa(dgt,inf_dgt,10,2);
						drawText(800,500,inf_dgt,25,25,noir);
						faire_rendu();*/
						combat = 0; break;
					}

					if((souris_x >= 1000 && souris_x <=1300) && (souris_y >= 900 && souris_y <=950)){
						//while(spell_choose != TRUE){
							drawImage(0, 0, "spells.png", 1920, 1080);
							drawImage(700,200,"wolfy.png", 520, 520);
							__itoa(player->hp,hp_joueur,10,3);
							drawText(480,920,hp_joueur,30,30,noir);
							drawText(850,150,monstre->name,40,40,noir);
							__itoa(monstre->hp,hp_monstre,10,3);
							drawText(1700,80,hp_monstre,30,30,noir);
								
							//Spells
							drawText(650,920,player->spell[0]->name,30,30,noir);
							drawText(900,920,player->spell[1]->name,30,30,noir);
							drawText(1100,920,player->spell[2]->name,30,30,noir);
							drawText(1300,920,player->spell[3]->name,30,30,noir);	
							faire_rendu();
							
						

						while(spell_choose != 1){
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
											spell_choose = 1;
										}
										else{
											tour_joueur(player, monstre);
											//combat = 0; break;
										}
									}


									if((souris_x >= 900 && souris_x <=1050) && (souris_y >= 900 && souris_y <=950)){
										if(spell_existe(player,1) != 0){
											dgt = player->spell[0]->dgt - monstre->armor;
											monstre->hp -= dgt;
											if(monstre->hp < 0){
												monstre->hp = 0;
											}
											spell_choose = 1;
										}
										else{
											tour_joueur(player, monstre);
											//combat = 0; break;
										}
									}
								}
							}
							

							
							//SDL_Delay(5000);
						}

						combat = 0; break;
						
						
						/*drawImage(700,200,"wolfy.png", 520, 520);
						__itoa(player->hp,hp_joueur,10,3);
						drawText(480,920,hp_joueur,30,30,noir);
						drawText(850,150,monstre->name,40,40,noir);
						__itoa(monstre->hp,hp_monstre,10,3);
						drawText(1700,80,hp_monstre,30,30,noir);
						faire_rendu();*/
			
					}
				}
			}
		}

	/*
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
      printf("Vous infligez %d dégats magiques à %s  ||	HP player : %d  HP monstre : %d\n", dgt, monstre->name, player->hp, monstre->hp);
    }*/
  }
}

void tour_monstre(perso_t * player, monstre_t * monstre)
{
  	int dgt;
  	int crit;
  
	srand(time(0));
	drawImage(0, 0, "combat.png", 1920, 1080);
	drawImage(700,200,"wolfy.png", 520, 520);
	__itoa(player->hp,hp_joueur,10,3);
	drawText(480,920,hp_joueur,30,30,noir);
	drawText(850,150,monstre->name,40,40,noir);
	__itoa(monstre->hp,hp_monstre,10,3);
	drawText(1700,80,hp_monstre,30,30,noir);
	faire_rendu();
	
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
		  
  	 	/*__itoa(player->hp,hp_joueur,10,3);
  	  	__itoa(dgt,inf_dgt,10,3);
  		drawText(700,350,inf_dgt,25,25,noir);
  		faire_rendu();
  		drawText(1200,350,"hp.",25,25,noir);
  		faire_rendu();
  		drawText(1300,900,hp_joueur,25,25,noir);
  		faire_rendu();
  		SDL_Delay(2000);*/
  		

	}
    if(player->hp < 0){
      player->hp = 0;
      printf("%s attaque ! vous prenez %d dégats    ||	HP player : %d  HP monstre : %d\n\n",monstre->name, dgt, player->hp, monstre->hp);
      printf("Oh.. vous avez perdu il me semble.\n");
	}
 	else{
 			/*__itoa(player->hp,hp_joueur,10,3);
  		drawText(500,900,hp_joueur,25,25,noir);*/

  		
 		printf("%s attaque ! vous prenez %d dégats    ||	HP player : %d  HP monstre : %d\n\n",monstre->name, dgt, player->hp, monstre->hp);
 	}
  }
  else{
	
	
  	drawText(625,700,monstre->name,40,40,noir);
	drawText(900,700,"est mort !",40,40,noir);
  	faire_rendu();
  }

  		
}

perso_t combat(perso_t * player, monstre_t * monstre){
  //Affichage spécial du combat
  while(monstre->hp > 0 && player->hp > 0){//condition de sortie à modifier avec sdl ?
	tour_joueur(player,monstre);
    	tour_monstre(player,monstre);
  }
  
  return(*player);
}
