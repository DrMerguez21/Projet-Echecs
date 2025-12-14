#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controle_plateau.h"
#include "mvt.h"
#include "fini.h"

int main(){
    //ajouter ici la recharge de sauvegarde
    Piece*** plateau=ini_plateau();
    Joueur* J1 = init_joueur (Blanc) ;
    Joueur* J2 = init_joueur (Noir) ;
    printf("les pièces noires sont en haut, les blanches en bas (les couleurs semblent inversées si on est en affichage sombre), les x correspondent aux lignes et les y aux colonnes\n");
    affiche_plateau(plateau);
    while(fini(J1, J2)==0){
        char yd, yf;
        int xd, xf;
        int xdebut, ydebut, xfin, yfin;
        double p ;
        clock_t start, end ;

        printf("Au tour des blancs\n");
        start = clock () ;
        //debut du décompte pour le joueur blanc
        printf("Entrez les coordonnées de la pièce que vous voulez déplacer, puis celles de la case où vous voulez aller, séparé à chaque fois par un espace\n");
        scanf(" %c %d %c %d",&yd, &xd, &yf, &xf);
        xdebut=convert_x(xd);
        ydebut=convert_y(yd);
        xfin=convert_x(xf);
        yfin=convert_y(yf);
        while(!mouvement(plateau, xdebut, ydebut, xfin, yfin)){
            printf("Entrez les coordonnées de la pièce que vous voulez déplacer, puis celles de la case où vous voulez aller, séparé à chaque fois par un espace\n");
            scanf(" %c %d %c %d",&yd, &xd, &yf, &xf);
            xdebut=convert_x(xd);
            ydebut=convert_y(yd);
            xfin=convert_x(xf);
            yfin=convert_y(yf);
        } deplacement (J1, plateau, xdebut, ydebut, xfin, yfin) ;
        //fin du décompte pour le joueur blanc
        end = clock () ;
        p = (double) (end - start) / CLOCKS_PER_SEC ;
        J1 -> temps -= p ;
        printf ("Il vous reste %d secondes\n", J1 -> temps) ;
        affiche_plateau(plateau);
        if (fini(J1, J2) != 0) break ;

        printf("Au tour des noirs\n");
        start = clock () ;
        //debut du décompte pour le joueur noir
        printf("Entrez les coordonnées de la pièce que vous voulez déplacer, puis celles de la case où vous voulez aller, séparé à chaque fois par un espace\n");
        scanf(" %c %d %c %d",&yd, &xd, &yf, &xf);
        xdebut=convert_x(xd);
        ydebut=convert_y(yd);
        xfin=convert_x(xf);
        yfin=convert_y(yf);
        while(!mouvement(plateau, xdebut, ydebut, xfin, yfin)){
            printf("Entrez les coordonnées de la pièce que vous voulez déplacer, puis celles de la case où vous voulez aller, séparé à chaque fois par un espace\n");
            scanf(" %c %d %c %d",&yd, &xd, &yf, &xf);
            xdebut=convert_x(xd);
            ydebut=convert_y(yd);
            xfin=convert_x(xf);
            yfin=convert_y(yf);
        } deplacement (J2, plateau, xdebut, ydebut, xfin, yfin) ;
        //fin du décompte pour le joueur noir
        end = clock () ;
        p = (double) (end - start) / CLOCKS_PER_SEC ;
        J2 -> temps -= p ;
        printf ("Il vous reste %d secondes\n", J2 -> temps) ;
        affiche_plateau(plateau);
    }

    if (fini(J1, J2) == 1) printf ("Le Joueur 1 a gagné\n") ;
    if (fini(J1, J2) == 2) printf ("Le Joueur 2 a gagné\n") ;
}