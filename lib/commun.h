#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAILLE_STR 50
#define ERR_RAND -110    
#define ERR_DEB_MEMOIRE -100
#define ERR_LISTE_IND_ELEM  -200
#define END_OF_GAME 666 

typedef char* string;
typedef int err_t ;

int position_x;
int position_y;

int etat_jeu;

int entier_aleatoire(int min, int max);
void clear_screen(void);

typedef enum booleen_s { FAUX , VRAI } booleen_t ;
