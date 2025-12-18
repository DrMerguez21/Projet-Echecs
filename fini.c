#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controle_plateau.h"
#include "mvt.h"
#include "fini.h"

int fini (Joueur* J1, Joueur* J2) {
    if (J1 -> Points >= 99) {
        printf("Le joueur 1 a gagné\n");
        return (1) ;
    }
    if (J2 -> Points >= 99) {
        printf("Le joueur 2 a gagné\n");
        return (1) ;
    }
    if(J1 ->temps <= 0){
        printf("Le joueur 1 a perdu au temps\n");
        return (1);
    }
    if(J2 -> temps <=0){
        printf("Le joueur 2 a perdu au temps\n");
        return (1);
    }
    return (0) ;
}

int check (Piece*** plateau, int xroi, int yroi) {
    int echec = 0 ;
    for (int i = 0 ; i < 8 ; i++) {
        for (int j = 0 ; j < 8 ; j++) {
            if ((plateau[i][j] != NULL) && (plateau[i][j] -> C != plateau[xroi][yroi] -> C)) {
                if (mouvement(0,plateau, i, j, xroi, yroi) == 1) {
                    echec = 1 ;
                    printf ("Echec de la pièce en %d %d", i, j) ;
                }
            }
        }
    } return echec ;
}

