#ifndef _INVENTORY_H
#define _INVENTORY_H
#include "structures.h"

/**
 * \file inventory.c
 * \brief Primitives des fonctions d'utilisation et de gestion de l'inventaire.
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
int add_item(perso_t * player, int id, char * name, char * desc, int heal, int dgt, int armor);

/**
 * \fn void del_item(perso_t * player, int id)
 * \brief Fonction de destruction d'un item dans l'inventaire.
 * 
 * \param player Perso_t auquel on souhaite retirer l'item.
 * \param id Numéro affecté à l'item.
 */ 
void del_item(perso_t * player, int id);

/**
 * \fn void use_heal(perso_t * player)
 * \brief Fonction d'utilisation d'une potion stockée dans l'inventaire.
 * 
 * \param player Perso_t auquel on souhaite appliquer la potion.
 */ 
void use_heal(perso_t * player);

/**
 * \fn void aff_inventory(perso_t * player)
 * \brief Fonction d'affichage de l'inventaire.
 * 
 * \param player Perso_t à qui appartient l'inventaire que l'on souhaite afficher.
 */
void aff_inventory(perso_t * player);

#endif

