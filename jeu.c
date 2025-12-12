#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controle_plateau.h"
#include "mvt.h"

int main(){
    //ajouter ici la recharge de sauvegarde
    Piece*** plateau=ini_plateau();
    printf("les pièces noires sont en haut, les blanches en bas (les couleurs semblent inversées si on est en affichage sombre), les x correspondent aux lignes et les y aux colonnes\n");

    while(!fini(Piece*** plateau)){ //fonction fini pas encore faite, renvoie 1 si un roi a été dévoré
        char yd, yf;
        int xd, xf;
        int xdebut, ydebut, xfin, yfin;

        affiche_plateau(plateau);
        printf("Au tour des blancs\n");
        //debut du décompte pour le joueur blanc
        printf("Entrez les coordonnées de la pièce que vous voulez déplacer, puis celles de la case où vous voulez aller, séparé à chaque fois par un espace\n");
        scanf("%c %d %c %d",&yd, &xd, &yf, &xf);
        xdebut=convert_x(xd);
        ydebut=convert_y(yd);
        xfin=convert_x(xf);
        yfin=convert_y(yf);
        while(!mouvement(plateau, xdebut, ydebut, xfin, yfin)){
            printf("Entrez les coordonnées de la pièce que vous voulez déplacer, puis celles de la case où vous voulez aller, séparé à chaque fois par un espace\n");
            scanf("%c %d %c %d",&yd, &xd, &yf, &xf);
            xdebut=convert_x(xd);
            ydebut=convert_y(yd);
            xfin=convert_x(xf);
            yfin=convert_y(yf);
        }
        //fin du décompte pour le joueur blanc
        affiche_plateau(plateau);
        printf("Au tour des noirs\n");
        //debut du décompte pour le joueur noir
        printf("Entrez les coordonnées de la pièce que vous voulez déplacer, puis celles de la case où vous voulez aller, séparé à chaque fois par un espace\n");
        scanf("%c %d %c %d",&yd, &xd, &yf, &xf);
        xdebut=convert_x(xd);
        ydebut=convert_y(yd);
        xfin=convert_x(xf);
        yfin=convert_y(yf);
        while(!mouvement(plateau, xdebut, ydebut, xfin, yfin)){
            printf("Entrez les coordonnées de la pièce que vous voulez déplacer, puis celles de la case où vous voulez aller, séparé à chaque fois par un espace\n");
            scanf("%c %d %c %d",&yd, &xd, &yf, &xf);
            xdebut=convert_x(xd);
            ydebut=convert_y(yd);
            xfin=convert_x(xf);
            yfin=convert_y(yf);
        }
        //fin du décompte pour le joueur noir
        affiche_plateau(plateau);
    }
}