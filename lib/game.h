/**
 * \file game.c
 * \brief Primitives des fonctions de lancement du jeu
 * \author Thibault.C Killian.R Ilyas.A
 * \version 1.2
 * \date 04 avril 2022
 */

#define Y 16
#define X 30

/**
 * \fn void start()
 * \brief Fonction de lancement du jeu
 */
void start();


void map();
void lecture_fichier_map(char nom_fichier[20],int map_int[Y][X]);
//void sauvegarder_jeu (case_t mat[Y][X],perso_t *perso, char * nom_map);
//void charger_jeu (case_t mat[Y][X], perso_t *perso,char * nom_map);