#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "spells.h"

/**
 * \file spells.c
 * \brief Fonctions d'utilisation et de gestion des sorts.
 * \author Killian.R
 * \version 1.0
 * \date 21 mars 2022
 */

/**
 * \fn void add_spell (perso_t * player, int num_spell, char * spell_name, int dgt)
 * \brief Fonction d'ajout d'un sort dans le tableau de sorts.
 * 
 * \param player Perso_t auquel on souhaite ajouter le sort.
 * \param num_spell Position à laquelle le sort sera affecté.
 * \param spell_name Nom que l'on souhaite attribuer à ce sort.
 * \param dgt Nombre de dégats infligés par le sort.
 */ 
void add_spell(perso_t * player, int num_spell, char * spell_name, int dgt){
	(player)->spell[num_spell]->name = spell_name;
	(player)->spell[num_spell]->dgt = dgt;
}


/**
 * \fn int spell_existe(perso_t * player, int num_spell)
 * \brief Vérifie si un sort existe ou non. Si il n'existe pas,
 					il ne peut pas être utilisé
 * 
 * \param player Perso_t dans lequel on doit effectuer le recherche de sort.
 * \param num_spell Position à laquelle est situé le sort.
 * \return Résulat de la comparaison entre le nom du sort entré en paramètre et 
 					 la valeur "vide" indiquant un sort non utilisable
 */
int spell_existe(perso_t * player, int num_spell){
  return(strcmp(player->spell[num_spell]->name, "vide"));
}


/**
 * \fn void spell_choice(perso_t * player, int * spell_num)
 * \brief Choix du sort à utiliser lors de l'attaque
 * 
 * \param player Perso_t dans lequel on doit chercher le sort spécifié.
 * \param spell_num Position à laquelle est situé le sort.
 */
void spell_choice(perso_t * player, int * spell_num)
{
  for(int i = 0; i < NB_SPELLS; i++)
  {
    printf("Sort %d : %s   ", i+1, player->spell[i]->name);
  }
  printf("\n");

  scanf("%d",spell_num);

  while(*spell_num < 1 || *spell_num > 4)
  {
    printf("Choisissez un sort valide.\n");
    scanf("%d",spell_num);
  }
  *spell_num -= 1;
}
