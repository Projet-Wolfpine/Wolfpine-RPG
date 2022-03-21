#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NB_SPELLS 4
#define TAILLE_INV 20

typedef struct spell_s spell_t;
typedef struct case_s case_t;
typedef struct perso_s perso_t;
typedef struct monstre_s monstre_t;
typedef struct objet_s objet_t;
typedef struct inv_s inv_t;

struct objet_s{
  int id;
  int qte;
  char * name;
  char * desc;
  int heal;
  int dgt;
  int armor;
};

struct case_s{
  char *id;//nom de la cellule
  int col;//statut de collision
};

struct perso_s{
  int anc_coord_x;
  int anc_coord_y;
  char *position; //Si jamais le dernier déplacement est gauche on tourne le perso et on modifira cette valeur pour afficher le sprite en consequece en sdl
  int hp;
  int dgt;
  int armor;
  spell_t *spells[NB_SPELLS];
  objet_t *objets[TAILLE_INV];
};

struct monstre_s{//a voir pour remplacer voir suprimer cette structure et utilisé la meme que pour les personages donc la renommer entité
  int hp;
  int dgt;
  int armor;
};

struct spell_s{
	char * name;
	int dgt;
};
