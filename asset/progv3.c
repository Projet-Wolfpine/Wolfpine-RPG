#include <stdlib.h>
#include <stdio.h>
#include "string.h"
//Lors du parcours de matrice puisque que les premiers crochet correspondes à la vertical et pas l'horizontal il faudra commencer par mettre les coordonnés Y puis X pour les fonctions
#define Y 11
#define X 31
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

//Fonction de création et d'initialisationn d'une matrice vide (remplie d'etat de collisio à 0)
void init_mat(case_t mat[Y][X]){
  for(int i=0;i<Y;i++){
    for(int j=0; j<X; j++){
      mat[i][j].col = 0;
      mat[i][j].id = "vide";
    }
  }
}

//Fonction de création des bordures de la matrice
void contour_mat(case_t mat[Y][X]){
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
void afficher_mat(case_t mat[Y][X]){
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
int case_libre (case_t mat[Y][X], int coord_y, int coord_x){
  return(mat[coord_y][coord_x].col == 0);//ne pas modifier pour garder le déplacement du personnage possible
}

//Fonction qui permet de placer un objet dans la matrice
void placer_objet(case_t mat[Y][X], int coord_y, int coord_x, char* id, int col){
  if(case_libre(mat,coord_y,coord_x) && strcmp(mat[coord_y][coord_x].id,"vide")){
    mat[coord_y][coord_x].col = col; //ici le chiffre 1 correspond à une collision et 0 correspond à une aucune collision
    mat[coord_y][coord_x].id = id;
  }else{
    //traiter le cas ou ça ne peut pas placer / ou il y'a deja un objet
  }
}

void placer_pers(case_t mat[Y][X], int coord_y, int coord_x, perso_t  *player){
  if(case_libre(mat,coord_y,coord_x)){
    mat[coord_y][coord_x].col=2;
    player->anc_coord_x = coord_x;
    player->anc_coord_y = coord_y;
  }
}

void deplacer_pers(case_t mat[Y][X], int coord_y, int coord_x, perso_t  *player){
  if(case_libre(mat,coord_y,coord_x)){
    mat[player->anc_coord_y][player->anc_coord_x].col = 0;
    placer_pers(mat,coord_y,coord_x,player);
  }
}

void aller_gauche(case_t mat[Y][X], perso_t *player){
  deplacer_pers(mat,player->anc_coord_x-1,player->anc_coord_y,player);
  player->anc_coord_x -= 1;
}

void aller_droite(case_t mat[Y][X], perso_t *player){
  deplacer_pers(mat,player->anc_coord_x,player->anc_coord_y+1,player);
  player->anc_coord_y += 1;
}

void aller_dessus(case_t mat[Y][X], perso_t *player){
  deplacer_pers(mat,player->anc_coord_x,player->anc_coord_y-1,player);
  player->anc_coord_y -= 1;
}

void aller_dessous(case_t mat[Y][X], perso_t *player){
  deplacer_pers(mat,player->anc_coord_x+1,player->anc_coord_y,player);
  player->anc_coord_x += 1;
}

//Nous permet de savoir ce que contient une case
void info_objet(case_t mat[Y][X], int coord_y, int coord_x){
  if(case_libre(mat,coord_y,coord_x) && strcmp(mat[coord_y][coord_x].id,"vide")){//ne marche pas mais est pourtant necessaire pour éviter une erreur de segmentation
    printf("L'emplacement en Y = %d et X = %d ne contient aucun objet\n", coord_y, coord_x);
  }else{
    printf("L'objet stocké en Y = %d et X = %d est : %s\n",coord_y, coord_x, mat[coord_y][coord_x].id);
    printf("Son statut de collision est de : %d\n",mat[coord_y][coord_x].col);
  }
}

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
		player->spells[i]->name = "vide";
		player->spells[i]->dgt = 0;
	}	

  for (int i = 0; i < TAILLE_INV; i++){
    player->objets[i] = malloc(sizeof(objet_t));
    player->objets[i]->id = -1;
    player->objets[i]->qte = 0;
    player->objets[i]->name = "VIDE";
    player->objets[i]->desc = "VIDE";
    player->objets[i]->heal = 0;
    player->objets[i]->dgt = 0;
    player->objets[i]->armor = 0;
  }
  
}

void init_monster(monstre_t * monster){
	monster->hp = 200;
	monster->dgt = 20;
	monster->armor = 5;
}


int add_item(perso_t * player,int place, int id, int qte, char * name, char * desc, int heal, int dgt, int armor){
  player->objets[place]->id = id;
  for(int i = 0; i < TAILLE_INV; i++){
    //player->objets[place]
    if((player->objets[place]->qte > 0)){
      player->objets[i]->qte += qte;
      return(0);
    }
    else{
      player->objets[place]->id = id;
      player->objets[place]->qte = qte;
      player->objets[place]->name = name;
      player->objets[place]->desc = desc;
      player->objets[place]->heal = heal;
      player->objets[place]->dgt = dgt;
      player->objets[place]->armor = armor;
    }
  }
  return(0);
}

void aff_inventory(perso_t * player){
  for(int i = 0; i < TAILLE_INV; i++){
   if(player->objets[i]->id > 0){
      printf("%d  : %d  : %s  : %s  : %d  : %d  : %d\n", player->objets[i]->id, player->objets[i]->qte, player->objets[i]->name, player->objets[i]->desc,
      player->objets[i]->heal, player->objets[i]->dgt, player->objets[i]->armor);
    }
  }
}

/*void use_pot(){

}*/

void add_spell(perso_t * player, int num_spell, char * spell_name, int dgt){
	player->spells[num_spell]->name = spell_name;
	player->spells[num_spell]->dgt = dgt;
}

int spell_existe(perso_t * player, int num_spell){
  return(strcmp(player->spells[num_spell]->name, "vide"));
}

void spell_choice(perso_t * player, int * spell_num)
{
  for(int i = 0; i < NB_SPELLS; i++)
  {
    printf("Sort %d : %s   ", i+1, player->spells[i]->name);
  }
  printf("\n");

  scanf("%d",spell_num);

  while(*spell_num < 1 || *spell_num > 4)
  {
    printf("Choisissez un sort valide.\n");
    scanf("%d",spell_num);
  }
  *spell_num -= 1;
}

void tour_joueur(perso_t * player, monstre_t * monstre){
	int choix = 0; 
  int spell_num = 0;
  int dgt;

  if(player->hp > 0){
    while(choix != 1 && choix != 2){
      printf("Choisissez le mode d'attaque (1 : attaque , 2 : sort) : ");
      scanf("%d",&choix);
    }
    
    if(choix == 1)
    {
      dgt =  player->dgt - monstre->armor;
      monstre->hp -= dgt;
       if(monstre->hp < 0){
          monstre->hp = 0;
        }
      printf("Vous infligez %d dégats au monstre	     ||	HP player : %d  HP monstre : %d\n", dgt, player->hp, monstre->hp);
    }
    else if(choix == 2)
    {
      printf("Choisissez quel sort vous souhaitez utiliser.\n");
      spell_choice(player,&spell_num);
      if(spell_existe(player,spell_num) != 0)
      {
              dgt = player->spells[spell_num]->dgt - monstre->armor;
              monstre->hp -= dgt;
              if(monstre->hp < 0){
                monstre->hp = 0;
              }
      }
      else
      {
        while(spell_existe(player,spell_num) == 0)
        {
          spell_num=0;
          printf("Choisissez un sort valide.\n");
          spell_choice(player,&spell_num);
        }
        dgt = player->spells[spell_num]->dgt - monstre->armor;
        monstre->hp -= dgt;
        if(monstre->hp < 0){
          monstre->hp = 0;
        }
      }
      printf("Vous infligez %d dégats magiques au monstre  ||	HP player : %d  HP monstre : %d\n", dgt, player->hp, monstre->hp);
    }
  }
  else{
    printf("Oh.. vous avez perdu il me semble.\n");
  }
}

void tour_monstre(perso_t * player, monstre_t * monstre)
{
  int dgt;

  if(monstre->hp > 0){
    dgt = monstre->dgt - player->armor;
    player->hp -= dgt;
    if(player->hp < 0){
      player->hp = 0;
    }
    printf("Le monstre attaque ! vous prenez %d dégats    ||	HP player : %d  HP monstre : %d\n\n", dgt, player->hp, monstre->hp);
  }
  else{
    printf("Bravo ! Vous avez battu le méchant monstre\n");
  }
}

void combat(monstre_t * monstre, perso_t * player){
  //Affichage spécial du combat

  init_player(player);
  init_monster(monstre);
  add_spell(player,0,"Foudre",77); 
  
  
  while(monstre->hp > 0 && player->hp > 0){//condition de sortie à modifier avec sdl ?
	tour_joueur(player,monstre);
    	tour_monstre(player,monstre);
  }
}

int main(){
  //case_t mat[Y][X];
  perso_t *joueur;
  joueur= malloc(sizeof(perso_t));
  monstre_t *monstre;
  monstre = malloc(sizeof(perso_t));

 init_player(joueur);
 init_monster(monstre);

 add_item(joueur,1, 1, 1, "Epee D", "Vous aussi vous aimez l'épée d ?", 0, 15, 0);
 aff_inventory(joueur);
  add_item(joueur,1, 1, 1, "Epee D", "Vous aussi vous aimez l'épée d ?", 0, 15, 0);
  printf("\n\n\n");
  aff_inventory(joueur);
   add_item(joueur,8, 8, 1, "Test", "Oui", 0, 0, 5);
     printf("\n\n\n");
 aff_inventory(joueur);


 // add_spell(joueur,0,"Foudre",77); 
 // printf("%d\n",spell_existe(joueur,0));
 // printf("%d\n",spell_existe(joueur,1));
 // combat(monstre, joueur);

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
