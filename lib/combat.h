#ifndef _COMBAT_H
#define _COMBAT_H
#include "structures.h"
#include "spells.h"
#include "inventory.h"
#include "deplacement.h"

/**
 * \file combat.c
 * \brief Prototypes des fonctions de combat.
 * \author Killian.R
 * \version 1.3
 * \date 04 avril 2022
 */

/**
 * \fn perso_t init_player()
 * \brief fonction d'initialisation d'un perso_t
 * \return retourne un pointeur sur le joueur initialisé
 */
perso_t init_player();

/**
 * \fn perso_t free_player(perso_t * player)
 * \brief Libère la mémoire associée à un perso_t
 * \param player adresse du perso_t concerné
 */
void free_player(perso_t * player)

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
void init_monster(monstre_t * monster, char * name, char * sprite, int hp, int dgt, int armor);

/**
 * \fn void aff_info(perso_t * player, monstre_t * monstre, char * fond, char * sprite)
 * \brief fonction d'affichage d'information durant le combat
 * \param player personnage concerné par le combat
 * \param monstre monstre concerné par le combat
 * \param fond texture affichée en background
 * \param sprite texture du monstre à afficher
 */
void aff_info(perso_t * player, monstre_t * monstre, char * fond, char * sprite);

/**
 * \fn void tour_joueur(perso_t * player, monstre_t * monstre)
 * \brief fonction d'attaque du joueur
 * \param player personnage concerné par le combat
 * \param monstre monstre concerné par le combat
 */
void tour_joueur(perso_t * player, monstre_t * monstre);

/**
 * \fn void tour_monstre(perso_t * player, monstre_t * monstre)
 * \brief fonction d'attaque du monstre
 * \param player personnage concerné par le combat
 * \param monstre monstre concerné par le combat
 */
void tour_monstre(perso_t * player, monstre_t * monstre);

/**
 * \fn void combat(perso_t * player, monstre_t * monstre)
 * \brief fonction de lancement du combat au tour par tour
 * \param player adresse du personnage concerné par le combat
 * \param monstre adresse du monstre concerné par le combat
 */
perso_t combat(perso_t * player, monstre_t * monstre);

#endif
