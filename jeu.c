#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controle_plateau.h"
//#include "mouv.h"

int main(){
    //ajouter ici la recharge de sauvegarde
    Piece*** plateau=ini_plateau();
    printf("les pièces noires sont écrites en haut, les blanches en bas (les couleurs semblent inversées si on est en affichage sombre), les x correspondent aux lignes et les y aux colonnes\n");

    while(!fini(Piece*** plateau)){ //fonction fini pas encore faite, renvoie 1 si un roi a été dévoré
        int xdebut, ydebut, xfin, yfin;
        affiche_plateau(plateau);
        printf("Au tour des blancs\n");
        //debut du décompte pour le joueur blanc
        printf("Entrez le x et y de la pièce que vous voulez déplacer, puis ceux de la case où vous voulez aller, séparé à chaque fois par un espace\n");
        scanf("%d %d %d %d",&xdebut, &ydebut, &xfin, &yfin);
        while(!mouvement(plateau, xdebut, ydebut, xfin, yfin)){
            printf("Entrez le x et y de la pièce que vous voulez déplacer, puis ceux de la case où vous voulez aller, séparé à chaque fois par un espace\n");
            scanf("%d %d %d %d",&xdebut, &ydebut, &xfin, &yfin);
        }
        //fin du décompte pour le joueur blanc
        affiche_plateau(plateau);
        printf("Au tour des noirs\n");
        //debut du décompte pour le joueur noir
        printf("Entrez le x et y de la pièce que vous voulez déplacer, puis ceux de la case où vous voulez aller, séparé à chaque fois par un espace\n");
        scanf("%d %d %d %d",&xdebut, &ydebut, &xfin, &yfin);
        while(!mouvement(plateau, xdebut, ydebut, xfin, yfin)){
            printf("Entrez le x et y de la pièce que vous voulez déplacer, puis ceux de la case où vous voulez aller, séparé à chaque fois par un espace\n");
            scanf("%d %d %d %d",&xdebut, &ydebut, &xfin, &yfin);
        }
        //fin du décompte pour le joueur noir
        affiche_plateau(plateau);
    }
}