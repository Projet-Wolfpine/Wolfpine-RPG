#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "../lib/fonction_sdl.h"
#include "../lib/gestion_deplacement_sdl.h"
#include "../lib/menu_principal.h"
#include "../lib/deplacement.h"
#include "../lib/affichage_sdl.h"
#include "../lib/game.h"
#include "../lib/creation_map.h"
#include "../lib/combat.h"
#include "string.h"
#include "time.h"

#define TAILLE_CASE_PXL 64

/*
perso_t joueur;
joueur = init_player();
*/
char * nom_map="map1.txt";


char * info_case(case_t mat[Y][X] , int coord_y, int coord_x){
    return(mat[coord_y][coord_x].id);
}

//Fonction qui permet de sauvegarder diverse informations sur le joueur et son placement pour les inclure dans un fichier txt 
void sauvegarder_jeu (case_t mat[Y][X],perso_t *perso, char * nom_map){
    FILE * sauv;
    sauv=fopen("sauvegarde.txt","w");
    fprintf(sauv,"%s/%d/%d",nom_map,perso->anc_coord_y,perso->anc_coord_x);
    fclose(sauv);
}

/*
void charger_jeu (case_t mat[Y][X], perso_t *perso,char * nom_map){
    FILE * sauv;
    if(sauv=fopen("sauvegarde.txt","r")){
        fscanf(sauv,"%s/%d/%d",nom_map,perso->anc_coord_y,perso->anc_coord_x);
    }else{
        //gerer si aucune sauvegarde n'a été creer
        printf("Aucune sauvegarde de disponible echec du chargement\n");
    }
}
*/
/*char* interaction_pnj(case_t mat[Y][X], perso_t *perso) {
    char *id_pnj;
    if(est_a_cote(mat,perso) == -1){//pnj au dessus
        strcpy(id_pnj,mat[perso->anc_coord_y+1][perso->anc_coord_x].id);
        return(id_pnj);
    }
    if(est_a_cote(mat,perso) == -2){//pnj en dessous
        strcpy(id_pnj,mat[perso->anc_coord_y-1][perso->anc_coord_x].id);
        return(id_pnj);
    }
    if(est_a_cote(mat,perso) == -3){//pnj à droite
        strcpy(id_pnj,mat[perso->anc_coord_y][perso->anc_coord_x+1].id);
        return(id_pnj);
    }
    if(est_a_cote(mat,perso) == -4){//pnj à gauche
        strcpy(id_pnj,mat[perso->anc_coord_y][perso->anc_coord_x-1].id);
        return(id_pnj);
    }
}*/

void start(){
    char * info;
    int y=10,x=10;//Initialisation de la posiition de départ dans la premiere map
    SDL_RenderClear(renderer);
    int touche=-1;
    int running = 1;//Initialisation pour savoir si le jeu continue de tourner ou non
    int random;
    srand(time(0));
	//Initialisation de la matrice et du joueur
    case_t mat[Y][X];
    perso_t joueur;
    joueur = init_player();
  	init_mat(mat);
    afficher_mat(mat);//verif
    placer_pers(mat,y,x,&joueur);
    afficher_mat(mat);//verification 
	
    afficher_map(nom_map,64,mat);//SDL
    drawImage(TAILLE_CASE_PXL*x , TAILLE_CASE_PXL*y , "perso.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL ); 
    faire_rendu();
    
    while(running == 1){
        touche=touche_detecter();    
        if(touche != 0){
            afficher_map(nom_map,64,mat);
            info=info_case(mat,y,x);
		    if(touche == 1 && dessus(mat,&joueur)){
                //nom_map="map2.txt";
                y--;
		        printf("%d\n",est_a_cote(mat,&joueur));
                info=info_case(mat,y,x);
                afficher_mat(mat);
                drawImage(TAILLE_CASE_PXL*x , TAILLE_CASE_PXL*y , "dessus.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL ); 
                faire_rendu();
		        if(!strcmp(info,"ID_SOLMONSTRE1")){
                	//srand(time(0));
                	random=rand() % 101;
               		if(random > 97){
                		monstre_t monstre;
            			init_monster(&monstre, "Sanik", "sanic.png", 50, 30 ,5);
            			combat(&joueur,&monstre);
                	}
                }

            }
            if(touche == 2 && dessous(mat,&joueur)){
                //nom_map="map3.txt";
                y++;
		        printf("%d\n",est_a_cote(mat,&joueur));
                info=info_case(mat,y,x);
                afficher_mat(mat);

                drawImage(TAILLE_CASE_PXL*x , TAILLE_CASE_PXL*y , "dessous.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
                faire_rendu();
		  
		        if(!strcmp(info,"ID_SOLMONSTRE1")){
                	//srand(time(0));
                	random=rand() % 101;
               		
                	if(random > 97){
                		monstre_t monstre;
            			init_monster(&monstre, "Sanik", "sanic.png", 50, 30 ,5);
          			
            			combat(&joueur,&monstre);
                	}
                }
                
            }
            if(touche == 3 && droite(mat,&joueur)){
                x++;
		        printf("%d\n",est_a_cote(mat,&joueur));
                info=info_case(mat,y,x);
                afficher_mat(mat);
                //afficher_mat(mat);
                drawImage(TAILLE_CASE_PXL*x, TAILLE_CASE_PXL*y , "droite.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
                faire_rendu();
		    
		         if(!strcmp(info,"ID_SOLMONSTRE1")){
                	//srand(time(0));
                	random=rand() % 101;
               		
                	if(random > 97){
                		monstre_t monstre;
            			init_monster(&monstre, "Sanik", "sanic.png", 50, 30 ,5);
          			
            			combat(&joueur,&monstre);
                	}
                }
                
            }
            if(touche == 4 && gauche(mat,&joueur)){
                x--;
		        printf("%d\n",est_a_cote(mat,&joueur));
                info=info_case(mat,y,x);
                afficher_mat(mat);
                //afficher_map(nom_map,64,mat);
                drawImage(TAILLE_CASE_PXL*x , TAILLE_CASE_PXL*y , "gauche.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
                faire_rendu();
		    
		         if(!strcmp(info,"ID_SOLMONSTRE1")){
                	//srand(time(0));
                	random=rand() % 101;
               		
                	if(random > 97){
                		monstre_t monstre;
            			init_monster(&monstre, "Sanik", "sanic.png", 50, 30 ,5);
          			
            			combat(&joueur,&monstre);
                	}
                }
                
            }
            if(touche == 5){
                running=0;
            }
            if(touche == 6 ){
                drawImage(TAILLE_CASE_PXL*x , TAILLE_CASE_PXL*y , "perso.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
                drawImage(1920/4 , 1080/4 , "inventory0.png", 1920/2, 1080/2 );
                faire_rendu();
                touche=touche_detecter();
                while(touche != 6){
                    touche=touche_detecter();
                }
                SDL_RenderClear(renderer);
                afficher_map(nom_map,64,mat);
                drawImage(TAILLE_CASE_PXL*x , TAILLE_CASE_PXL*y , "perso.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
                faire_rendu();
                
            }
		
            printf("\nvaleur de strcmp = %d\n",strcmp(info,"ID_SORTIE1"));
            if((strcmp(info,"ID_SORTIE1"))== 0 && strcmp(nom_map,"map1.txt")==0){
                SDL_RenderClear(renderer);
                nom_map="map2.txt";
                afficher_map(nom_map,64,mat);
                y = 8;
                x = 5;
                placer_pers(mat,y,x,&joueur);
                drawImage(TAILLE_CASE_PXL*x , TAILLE_CASE_PXL*y , "perso.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
                faire_rendu();
            }
        
            if((strcmp(info,"ID_SORTIE2"))==0 && strcmp(nom_map,"map2.txt")==0){
                SDL_RenderClear(renderer);
                nom_map="map1.txt";
                afficher_map(nom_map,64,mat);
                y = 15;
                x = 15;
                placer_pers(mat,y,x,&joueur);
                drawImage(TAILLE_CASE_PXL*x , TAILLE_CASE_PXL*y , "perso.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
                faire_rendu();
            }
            if((strcmp(info,"ID_SORTIE3"))==0 && strcmp(nom_map,"map2.txt")==0){
               SDL_RenderClear(renderer);
               nom_map="map3.txt";
               afficher_map(nom_map,64,mat);
               y = 15;
               x = 15;
               placer_pers(mat,y,x,&joueur);
               drawImage(TAILLE_CASE_PXL*x , TAILLE_CASE_PXL*y , "perso.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
               faire_rendu();
            }
            if((strcmp(info,"ID_SORTIE4"))==0 && strcmp(nom_map,"map3.txt")==0){
              SDL_RenderClear(renderer);
              nom_map="map2.txt";
              afficher_map(nom_map,64,mat);
              y = 0;
              x = 15;
              placer_pers(mat,y,x,&joueur);
              drawImage(TAILLE_CASE_PXL*x , TAILLE_CASE_PXL*y , "perso.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
              faire_rendu();
            }
            if((strcmp(info,"ID_ENTREEGROTTE1"))==0 && strcmp(nom_map,"map3.txt")==0){
             SDL_RenderClear(renderer);
             nom_map="donjon1.txt";
             afficher_map(nom_map,64,mat);
             y = 15;
             x = 16;
             placer_pers(mat,y,x,&joueur);
             drawImage(TAILLE_CASE_PXL*x , TAILLE_CASE_PXL*y , "perso.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
             faire_rendu();
            }
            if((strcmp(info,"ID_SORTIE5"))==0 && strcmp(nom_map,"donjon1.txt")==0){
              SDL_RenderClear(renderer);
              nom_map="map3.txt";
              afficher_map(nom_map,64,mat);
               y = 6;
               x = 15;
                placer_pers(mat,y,x,&joueur);
                drawImage(TAILLE_CASE_PXL*x , TAILLE_CASE_PXL*y , "perso.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
               faire_rendu();
            }
	        if((strcmp(info,"ID_SORTIE6"))==0 && strcmp(nom_map,"donjon1.txt")==0){
                SDL_RenderClear(renderer);
                nom_map="donjon2.txt";
                  afficher_map(nom_map,64,mat);
                  y = 3;
                  x = 0;
                  placer_pers(mat,y,x,&joueur);
                   drawImage(TAILLE_CASE_PXL*x , TAILLE_CASE_PXL*y , "perso.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
                   faire_rendu();
            }
            if((strcmp(info,"ID_SORTIE7"))==0 && strcmp(nom_map,"donjon2.txt")==0){
             SDL_RenderClear(renderer);
             nom_map="donjon1.txt";
              afficher_map(nom_map,64,mat);
              y = 3;
              x = 29;
              placer_pers(mat,y,x,&joueur);
              drawImage(TAILLE_CASE_PXL*x , TAILLE_CASE_PXL*y , "perso.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
              faire_rendu();
            }
	        if((strcmp(info,"ID_SORTIE8"))==0 && strcmp(nom_map,"donjon2.txt")==0){
              SDL_RenderClear(renderer);
              nom_map="donjon3.txt";
             afficher_map(nom_map,64,mat);
              y = 4;
               x = 0;
           placer_pers(mat,y,x,&joueur);
                 drawImage(TAILLE_CASE_PXL*x , TAILLE_CASE_PXL*y , "perso.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
             faire_rendu();
            }
            if((strcmp(info,"ID_SORTIE9"))==0 && strcmp(nom_map,"donjon3.txt")==0){
            SDL_RenderClear(renderer);
            nom_map="donjon2.txt";
            afficher_map(nom_map,64,mat);
            y = 7;
            x = 29;
            placer_pers(mat,y,x,&joueur);
            drawImage(TAILLE_CASE_PXL*x , TAILLE_CASE_PXL*y , "perso.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
            faire_rendu();
            }
            if(touche == 7 && est_a_cote(mat, &joueur)<0){
                affichage_dialogue("PNJ02");
                drawImage(TAILLE_CASE_PXL*x , TAILLE_CASE_PXL*y , "perso.png", TAILLE_CASE_PXL, TAILLE_CASE_PXL );
                faire_rendu();
            }
 	        add_item(&joueur, 0, "Epee d'Erastre", "Ceci est une fraude", 0, 69, 0);
            if(x == 10 && y == 10){
			    monstre_t monstre;
            	init_monster(&monstre, "Wolfy", "wolfy.png", 50, 30 ,5);
                add_spell(&joueur,0,"Foudre",75);
                add_spell(&joueur,1,"Marrée",150);
                add_spell(&joueur,2,"Brasier",150);
                add_item(&joueur, 3, "Potion de soin", "caca", 50, 0, 0);				
            	combat(&joueur,&monstre);
            }
	    }   

    }
    Menu();
}
