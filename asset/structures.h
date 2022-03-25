#ifndef _INCL_STRUCTURES
#define _INCL_STRUCTURES

typedef struct perso_s perso_t;
typedef struct monstre_s monstre_t;
typedef struct objet_s objet_t;
typedef struct spell_s spell_t;
typedef struct case_s case_t;

/**
 * \file structures.h
 * \brief Structures d'objets.
 * \author Killian.R
 * \version 1.2
 * \date 24 mars 2022
 */

#define NB_SPELLS 4
#define TAILLE_INV 20

/**
 * \struct objet_t structures.h "Objet"
 */
struct objet_s{
  int id;
  int qte;
  char * name;
  char * desc;
  int heal;
  int dgt;
  int armor;
};

/**
 * \struct case_t structures.h "Case d'une matrice"
 */
struct case_s{
  char *id;//nom de la cellule
  int col;//statut de collision
};

/**
 * \struct perso_t structures.h "Personnage"
 */
struct perso_s{
  int anc_coord_x;
  int anc_coord_y;
  char *position; //Si jamais le dernier déplacement est gauche on tourne le perso et on modifira cette valeur pour afficher le sprite en consequece en sdl
  char * name;
  int hp;
  int dgt;
  int armor;
  spell_t *spell[NB_SPELLS];
  objet_t *objets[TAILLE_INV];
};

/**
 * \struct monstre_t structures.h "Monstre"
 */
struct monstre_s{//a voir pour remplacer voir suprimer cette structure et utilisé la meme que pour les personages donc la renommer entité
  int hp;
  int dgt;
  int armor;
};

/**
 * \struct spell_t structures.h "Sort"
 */
struct spell_s{
	char * name;
	int dgt;
};

#endif
