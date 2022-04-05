/**
 * \file affichage_sdl.c
 * \brief Prototypes des fonctions d'affichage du menu et du dialogue.
 * \author thibault.C
 * \version 1.1
 * \date 03/04/2022
 */

/**
 * \fn int afficher_menu(char menu[4][30])
 * \brief fonction d'affichage du menu et de detection du choix de l'utilisateur 
 * \param[in] menu Récupération de la liste format texte du menu pour effectuer l'affichage
 */
int afficher_menu(char menu[4][30]);

/**
 * \fn void affichage_dialogue(char * id_PNJ)
 * \brief fonction d'affichage des dialogue 
 * \param[in] menu Récupération de la liste format texte du menu pour effectuer l'affichage
 */
void affichage_dialogue(char * id_PNJ);