#ifndef _SPELLS_H
#define _SPELLS_H
#include "structures.h"

/**
 * \file spells.c
 * \brief Primitives des fonctions d'utilisation et de gestion des sorts.
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
void add_spell(perso_t * player, int num_spell, char * spell_name, int dgt);

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
int spell_existe(perso_t * player, int num_spell);

/**
 * \fn void spell_choice(perso_t * player, int * spell_num)
 * \brief Choix du sort à utiliser lors de l'attaque
 * 
 * \param player Perso_t dans lequel on doit chercher le sort spécifié.
 * \param spell_num Position à laquelle est situé le sort.
 */
void spell_choice(perso_t * player, int * spell_num);

#endif
