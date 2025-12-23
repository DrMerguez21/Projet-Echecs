#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controle_plateau.h"
#include "mvt.h"
#include "fini.h"
#include "save.h"
#include "partie.h"

int tour_joueur(Piece*** plateau, Joueur* joueur, Joueur* opposant){
    char yd, yf;
    int xd, xf;
    int xdebut, ydebut, xfin, yfin;
    time_t start, end;
    int tps;
    int xroi, yroi;
    int mouv_spe=0;

    if(joueur->C==Blanc) printf("Au tour des Bleus\n");
    else{ printf("Au tour des Rouges\n");}
    time(&start); //debut du décompte pour le joueur blanc
    do{
        printf("Entrez les coordonnées de la pièce que vous voulez déplacer, puis celles de la case où vous voulez aller, séparées par un espace\n");
        scanf(" %c %d %c %d",&yd, &xd, &yf, &xf);
        if((yd=='z')&&(xd==9)&&(yf=='z')&&(xf==9)){
            char nom_fichier[50];
            printf("Entrez le nom dans lequel vous voulez faire la sauvegarde\n");
            scanf("%49s", nom_fichier);
            if(joueur->C==Blanc) save(nom_fichier, plateau, joueur, opposant, Blanc);
            else{save(nom_fichier, plateau, opposant, joueur, Noir);}
            return 1;
        }
        xdebut=convert_x(xd);
        ydebut=convert_y(yd);
        xfin=convert_x(xf);
        yfin=convert_y(yf);
        mouv_spe=mouvement(1,plateau, xdebut, ydebut, xfin, yfin, joueur->C);
    }while(mouv_spe==0);
    if(mouv_spe==2){ //petit roque
        deplacement(joueur, plateau, xdebut, 7, xdebut, 5); //deplacement de la tour de droite    
    }
    if (mouv_spe==3){ //grand roque
        deplacement(joueur, plateau, xdebut, 0, xdebut, 3); //deplacement de la tour de gauche
    }
    deplacement (joueur, plateau, xdebut, ydebut, xfin, yfin) ;
    promotion(plateau, xfin, yfin, opposant);
    time(&end) ;//fin du décompte pour le joueur blanc
    tps = end - start;
    joueur -> temps -= tps ;
    trouver_roi(plateau, opposant->C, &xroi, &yroi); 
    check(1,plateau, xroi, yroi); // on vérif si le mouvement du joueur à mis le roi opposé en echec
    affiche_temps(joueur);
    affiche_point(opposant);
    affiche_plateau(plateau);
    return 0;
}

void partie(Piece*** plateau, Joueur* J1, Joueur* J2, int noir_commence){ // noir_commence=1 si c'est au noir de commencer
    printf("les pièces noires sont en haut représentée en rouge, les blanches en bas en bleu, les x correspondent aux lignes et les y aux colonnes\n");
    printf("Si vous voulez sauvegarder, entrez z9 z9 à la place des coordonnées de votre mouvement\n");
    affiche_plateau(plateau);
    do{
        int sauvegarde;
        if(!noir_commence){
        sauvegarde=tour_joueur(plateau, J1, J2);
        if (sauvegarde) return;
        if (fini(plateau,J1, J2)) return ;
        }

        sauvegarde=tour_joueur(plateau, J2, J1);
        if (sauvegarde) return;

        noir_commence=0;
    } while(!fini(plateau, J1, J2));
}

