#ifndef _DEPLACEMENT_H
#define _DEPLACEMENT_H
#include "structures.h"
#include "game.h"

/**
 * \file deplacement.c
 * \brief Prototypes des fonctions de déplacement d'un personnage dans une matrice.
 * \author Ilyas.A
 * \version 1.2
 * \date 04 avril 2022
 */

/**
 * \fn void init_mat(case_t mat[Y][X])
 * \brief Fonction de création et d'initialisationn d'une matrice vide (remplie d'etat de collision à 0)
 * \param mat matrice de case_t dans laquelle on stocke les informations initialisées
 */
void init_mat(case_t mat[Y][X]);

/**
 * \fn void contour_mat(case_t mat[Y][X])
 * \brief Fonction de création des bordures de la matrice
 * \param mat matrice de case_t dans laquelle on stocke les informations initialisées
 */
void contour_mat(case_t mat[Y][X]);

/**
 * \fn void afficher_mat(case_t mat[Y][X])
 * \brief Fonction d'affichage de la matrice
 * \param mat matrice de case_t que l'on souhaite afficher
 */
void afficher_mat(case_t mat[Y][X]);

/**
 * \fn int case_libre (case_t mat[Y][X], int coord_y, int coord_x)
 * \brief Vérifie si la case sur laquelle on se déplace est libre (id collision)
 * \param mat matrice de case_t sur laquelle on se déplace
 * \param coord_y coordonée en y que l'on souhaite tester
 * \param coor_x coordonée en x que l'on souhaite tester
 * \return renvoie 1 si la case est libre, 0 sinon
 */
int case_libre (case_t mat[Y][X], int coord_y, int coord_x);

/**
 * \fn void placer_pers(case_t mat[Y][X], int coord_y, int coord_x, perso_t  *player)
 * \brief Place le personnage si la case est libre
 * \param mat matrice de case_t sur laquelle on souhaite placer le personnage
 * \param coord_y coordonée en y où l'on place le personnage
 * \param coor_x coordonée en x où l'on place le personnage
 */
void placer_pers(case_t mat[Y][X], int coord_y, int coord_x, perso_t  *player);

/**
 * \fn int deplacer_pers(case_t mat[Y][X], int coord_y, int coord_x, perso_t  *player)
 * \brief Déplace le personnage sur la case souhaitée
 * \param mat matrice de case_t sur laquelle on souhaite déplacer le personnage
 * \param coord_y coordonée en y où l'on place le personnage
 * \param coor_x coordonée en x où l'on place le personnage
 * \param player personnage que l'on souhaite déplacer
 */
int deplacer_pers(case_t mat[Y][X], int coord_y, int coord_x, perso_t  *player);

/**
 * \fn int gauche(case_t mat[Y][X], perso_t *player)
 * \brief Fonction de déplacement matriciel vers la gauche
 * \param mat matrice de case_t sur laquelle on souhaite déplacer le personnage
 * \param player personnage que l'on souhaite déplacer
 */
int gauche(case_t mat[Y][X], perso_t *player);

/**
 * \fn int droite(case_t mat[Y][X], perso_t *player)
 * \brief Fonction de déplacement matriciel vers la droite
 * \param mat matrice de case_t sur laquelle on souhaite déplacer le personnage
 * \param player personnage que l'on souhaite déplacer
 */
int droite(case_t mat[Y][X], perso_t *player);

/**
 * \fn int dessus(case_t mat[Y][X], perso_t *player)
 * \brief Fonction de déplacement matriciel vers le haut
 * \param mat matrice de case_t sur laquelle on souhaite déplacer le personnage
 * \param player personnage que l'on souhaite déplacer
 */
int dessus(case_t mat[Y][X], perso_t *player);

/**
 * \fn int dessous(case_t mat[Y][X], perso_t *player)
 * \brief Fonction de déplacement matriciel vers le bas
 * \param mat matrice de case_t sur laquelle on souhaite déplacer le personnage
 * \param player personnage que l'on souhaite déplacer
 */
int dessous(case_t mat[Y][X], perso_t *player);

/**
 * \fn int est_a_cote(case_t mat[Y][X], perso_t *perso)
 * \brief Fonction pour savoir si on est proche ou non d'un PNJ
 * \param mat matrice de case_t dans laquelle on souhaite effectuer le test
 * \param perso personnage sur qui on souhaite effectuer le test
 * \return -1 si bas, -2 si haut, -3 si droite, -4 si gauche, 0 si pas de PNJ
 */
int est_a_cote(case_t mat[Y][X], perso_t *perso);

#endif
