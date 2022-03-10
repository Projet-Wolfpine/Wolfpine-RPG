#include <stdlib.h>
#include <stdio.h>
#include "string.h"
//Lors du parcours de matrice puisque que les premiers crochet correspondes à la vertical et pas l'horizontal il faudra commencer par mettre les coordonnés Y puis X pour les fonctions
#define Y 11
#define X 31
#define NB_SPELLS 4

typedef struct spell_s spell_t;
typedef struct objet_s objet_t;
typedef struct perso_s perso_t;
typedef struct monstre_s monstre_t;


struct objet_s{
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


/*
//Fonction de création et d'initialisationn d'une matrice vide (remplie d'etat de collisio à 0)
void init_mat(objet_t mat[Y][X]){
  for(int i=0;i<Y;i++){
    for(int j=0; j<X; j++){
      mat[i][j].col = 0;
      mat[i][j].id = "vide";
    }
  }
}

//Fonction de création des bordures de la matrice
void contour_mat(objet_t mat[Y][X]){
  for(int j = 0; j<X; j++){
      mat[0][j].col = 1;
      mat[Y-1][j].col = 1;
  }
  for(int i = 0; i<Y; i++){
      mat[i][0].col = 1;
      mat[i][X-1].col = 1;
  }
}

//Fonction d'affichage de la matrice
void afficher_mat(objet_t mat[Y][X]){
  for(int i=0;i<Y;i++){
    for(int j=0; j<X; j++){
      if(mat[i][j].col== 2){//personnage
        printf("P");
      }
      if(mat[i][j].col== 1)//collision
        printf("C");
      if(mat[i][j].col== 0 && strcmp(mat[i][j].id,"vide"))//case traversable
        printf("T");
      if(mat[i][j].col== 0)//case vide
        printf(" ");
    }
    printf("\n");
  }
}

//Renvoi vrai si la case est libre
int case_libre (objet_t mat[Y][X], int coord_y, int coord_x){
  return(mat[coord_y][coord_x].col == 0);//ne pas modifier pour garder le déplacement du personnage possible
}

//Fonction qui permet de placer un objet dans la matrice
void placer_objet(objet_t mat[Y][X], int coord_y, int coord_x, char* id, int col){
  if(case_libre(mat,coord_y,coord_x) && strcmp(mat[coord_y][coord_x].id,"vide")){
    mat[coord_y][coord_x].col = col; //ici le chiffre 1 correspond à une collision et 0 correspond à une aucune collision
    mat[coord_y][coord_x].id = id;
  }else{
    //traiter le cas ou ça ne peut pas placer / ou il y'a deja un objet
  }
}

void placer_pers(objet_t mat[Y][X], int coord_y, int coord_x, perso_t  *player){
  if(case_libre(mat,coord_y,coord_x)){
    mat[coord_y][coord_x].col=2;
    player->anc_coord_x = coord_x;
    player->anc_coord_y = coord_y;
  }
}

void deplacer_pers(objet_t mat[Y][X], int coord_y, int coord_x, perso_t  *player){
  if(case_libre(mat,coord_y,coord_x)){
    mat[player->anc_coord_y][player->anc_coord_x].col = 0;
    placer_pers(mat,coord_y,coord_x,player);
  }
}

void aller_gauche(objet_t mat[Y][X], perso_t *player){
  deplacer_pers(mat,player->anc_coord_x-1,player->anc_coord_y,player);
  player->anc_coord_x -= 1;
}

void aller_droite(objet_t mat[Y][X], perso_t *player){
  deplacer_pers(mat,player->anc_coord_x,player->anc_coord_y+1,player);
  player->anc_coord_y += 1;
}

void aller_dessus(objet_t mat[Y][X], perso_t *player){
  deplacer_pers(mat,player->anc_coord_x,player->anc_coord_y-1,player);
  player->anc_coord_y -= 1;
}

void aller_dessous(objet_t mat[Y][X], perso_t *player){
  deplacer_pers(mat,player->anc_coord_x+1,player->anc_coord_y,player);
  player->anc_coord_x += 1;
}

//Nous permet de savoir ce que contient une case
void info_objet(objet_t mat[Y][X], int coord_y, int coord_x){
  if(case_libre(mat,coord_y,coord_x) && strcmp(mat[coord_y][coord_x].id,"vide")){//ne marche pas mais est pourtant necessaire pour éviter une erreur de segmentation
    printf("L'emplacement en Y = %d et X = %d ne contient aucun objet\n", coord_y, coord_x);
  }else{
    printf("L'objet stocké en Y = %d et X = %d est : %s\n",coord_y, coord_x, mat[coord_y][coord_x].id);
    printf("Son statut de collision est de : %d\n",mat[coord_y][coord_x].col);
  }
}

*/

//Creation du systeme de combat

//Fais en sorte que le joueur puisse choisir son nom (struct) connard
void init_player(perso_t * player){
	player->anc_coord_x = 5;
	player->anc_coord_y = 4;
	player->position = "droite"; //Si jamais le dernier déplacement est gauche on tourne le perso et on modifira cette valeur pour afficher le sprite en consequece en sdl
	player->hp = 600;
	player->dgt = 50;
	player->armor = 15;
	
	for(int i = 0; i < NB_SPELLS; i++)
	{	
		player->spells[i] = malloc(sizeof(spell_t));
		player->spells[i]->dgt = 0;
		player->spells[i]->name = "vide";
		player->spells[i]->dgt = 0;
	}	
}

void init_monster(monstre_t * monster){
	monster->hp = 200;
	monster->dgt = 20;
	monster->armor = 5;
}

void add_spell(perso_t * player, int num_spell, char * spell_name, int dgt){
	player->spells[num_spell]->name = spell_name;
	player->spells[num_spell]->dgt = dgt;
	printf("Nom du sort : %s	||	Dégats du sort : %d\n",player->spells[num_spell]->name, player->spells[num_spell]->dgt);

}

void tour_joueur(perso_t * player, monstre_t * monstre){
	int choix = 0;
	
	printf("Choisissez le mode d'attaque\n");

	while(choix != 1 || choix != 2){
		printf("1 : attaque	||	2 : sort AAAs\n");
		scanf("%d",&choix);
	}
	
	if(choix == 1)
	{
		monstre->hp -= player->dgt - monstre->armor;
		printf("Vous infligez %d dégats au monstre	||	HP player : %d  HP monstre : %d", player->dgt-monstre->armor, player->hp, monstre->hp);
	}
}

void combat(monstre_t * monstre, perso_t * player){
  //Affichage spécial du combat
  printf("test1\n");
  init_player(player);
  printf("test2\n");
  init_monster(monstre);
  printf("Deg monstre : %d\n",monstre->dgt);
  add_spell(player,1,"Foudre",60); 
  
  while(monstre->hp != 0 || player->hp != 0){//condition de sortie à modifier avec sdl ?
	tour_joueur(player,monstre);
  }

}

int main(){
  //objet_t mat[Y][X];
  perso_t *joueur;
  joueur= malloc(sizeof(perso_t));
  monstre_t *monstre;
  monstre = malloc(sizeof(perso_t));
  combat(monstre, joueur);

  //init_mat(mat);
  //contour_mat(mat);

  //placer_objet(mat,1,3,"palmier",1);
 // placer_objet(mat,2,5,"route",0);
 // afficher_mat(mat);
  //placer_pers(mat,3,3,player);

 // afficher_mat(mat);
  //info_objet(mat,1,3);
  //info_objet(mat,2,2);

  //info_objet(mat,2,5);
 // info_objet(mat,3,3);
  
  
  
  
  
  

  //aller_droite(mat,player);
  //afficher_mat(mat);
}

