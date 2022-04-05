#include "deplacement.h"

/**
 * \file creation_map.c
 * \brief Prototypes des fonctions de création d'une map
 * \author Dimitri.B, Thibault.C
 * \version 1.1
 * \date 04 avril 2022
 */

/**
 * \fn void lecture_fichier_map(char nom_fichier[20],int map_int[Y][X])
 * \brief La fonction prend la matrice avec les entiers afin de remplir un tableau
            de structure contenant les infos de chaque cases (id_bloc et statut colision)
 * \param nom_fichier fichier contenant les informations matricielles relatives à la map
 * \param map_int matrice où les informations sont stockées
 */
void lecture_fichier_map(char nom_fichier[20],int map_int[Y][X]);

/**
 * \fn void mise_struct_map(case_t map_info[Y][X], int map_int[Y][X])
 * \brief Fonction permetant d'associer un id et un statut de collision à toutes les cases de la matrice
 * \param map_info matrice contenant les id et les collisions de chaque bloc
 * \param map_int matrice où les informations sont stockées
 */
void mise_struct_map(case_t map_info[Y][X], int map_int[Y][X]);

/**
 * \fn void afficher_map(char * nom_map,int taille, case_t map_info[Y][X])
 * \brief Affiche en SDL une matrice contenant les informations de chaque bloc
 * \param nom_map nom de la map que l'on veut afficher
 * \param taille taille d'une case en pixel (64px)
 * \param map_info matrice contenant les id et les collisions de chaque bloc
 */
void afficher_map(char * nom_map,int taille, case_t map_info[Y][X]);