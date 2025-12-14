#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controle_plateau.h"
#include "mvt.h"

void manger (Joueur* J, Piece*** plateau, int x, int y) {
    Piece* P = plateau[x][y] ;
    J -> Points += P -> Point ;
    plateau[x][y] = NULL ;
    free(P) ;
}

void deplacement (Joueur* J, Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin){
    if (plateau[xfin][yfin] != NULL) {
        manger (J, plateau, xfin, yfin) ;
    } plateau[xdebut][ydebut] -> CptMvt += 1 ;
    plateau[xfin][yfin] = plateau[xdebut][ydebut] ;
    plateau[xdebut][ydebut] = NULL ;
}

    //Mouvement Pions
int mvt_pions (Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin) {
    if ((plateau[xdebut][ydebut] -> C == Blanc) && (xfin == xdebut - 1)) {
        if (ydebut != yfin) {
            if ((yfin == ydebut + 1) || (yfin == ydebut - 1)) { //mouv en diago pour manger
                if ((plateau[xfin][yfin] != NULL) && (plateau[xfin][yfin] -> C == Noir)){
                    return (1) ;
                } printf ("Mouvement Illégal\n") ;
                return (0) ;
            } printf ("Mouvement Illégal\n") ;
            return (0) ;
        } if (plateau[xfin][yfin] == NULL) {
            return (1) ;
        } printf ("Mouvement Illégal\n") ;
        return (0) ;
    } if ((plateau[xdebut][ydebut] -> C == Noir) && (xfin == xdebut + 1)) {
        if (ydebut != yfin) {
            if ((yfin == ydebut + 1) || (yfin == ydebut - 1)) {
                if ((plateau[xfin][yfin] != NULL) && (plateau[xfin][yfin] -> C == Blanc)){
                    return (1) ;
                } printf ("Mouvement Illégal\n") ;
                return (0) ;
            } printf ("Mouvement Illégal\n") ;
            return (0) ;
        } if (plateau[xfin][yfin] == NULL) {
            return (1) ;
        } printf ("Mouvement Illégal\n") ;
        return (0) ;
    } if (((plateau[xdebut][ydebut] -> C == Blanc) && (plateau[xdebut][ydebut] -> CptMvt == 0)) && ((xfin == xdebut - 2) && (ydebut == yfin))) {
        if ((plateau[xdebut - 1][ydebut] == NULL) && (plateau[xdebut - 2][ydebut]==NULL)) { //si la case devant le pion est vide
            return (1) ;
        } printf ("Mouvement Illégal\n") ;
        return (0) ;
    } if (((plateau[xdebut][ydebut] -> C == Noir) && (plateau[xdebut][ydebut] -> CptMvt == 0)) && ((xfin == xdebut + 2) && (ydebut == yfin))) {
        if ((plateau[xdebut+1][ydebut] == NULL) && (plateau[xdebut + 2][ydebut]==NULL)) { //la case devant le pion est vide
            return (1) ;
        } printf ("Mouvement Illégal\n") ;
        return (0) ;
    } printf ("Mouvement Illégal\n") ;
    return (0) ;
}

    //Mouvement Cavalier
int mvt_cava (Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin) {
    if ((xfin == xdebut + 2) || (xfin == xdebut - 2)) { 
        if ((yfin == ydebut + 1) || (yfin == ydebut - 1)) {
            return (1) ;
        } printf ("Mouvement Illégal\n") ;
        return (0) ;
    } if ((xfin == xdebut + 1) || (xfin == xdebut - 1)) {
        if ((yfin == ydebut + 2) || (yfin == ydebut - 2)) {
            return (1) ;
        } printf ("Mouvement Illégal\n") ;
        return (0) ;
    } printf ("Mouvement Illégal\n") ;
    return (0) ;
}
    //Mouvement Tour
int mvt_tour (Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin) {
    int compteur = 0 ;
    if (xdebut == xfin) {
        if (ydebut < yfin) {
            if (yfin - ydebut >= 2) {
                for (int i = ydebut + 1 ; i < yfin ; i++) { //vérif que les cases sont toutes vides entre la tour et la case où elle veut aller
                    if (plateau[xdebut][i] != NULL) compteur += 1 ;
                }
            } 
        } else {
            if (ydebut - yfin >= 2) {
                for (int i = ydebut - 1 ; i > yfin ; i--) {
                    if (plateau[xdebut][i] != NULL) compteur += 1 ;
                }
            }
        }
    } else if (ydebut == yfin) {
        if (xdebut < xfin) {
            if (xfin - xdebut >= 2) {
                for (int i = xdebut + 1 ; i < xfin ; i++) {
                    if (plateau[i][ydebut] != NULL) compteur += 1 ;
                }
            } 
        } else {
            if (xdebut - xfin >= 2) {
                for (int i = xdebut - 1 ; i > xfin ; i--) {
                    if (plateau[i][ydebut] != NULL) compteur += 1 ;
                }
            }
        }
    } else {
        printf ("Mouvement Illégal\n") ;
        return (0) ;
    } if (compteur == 0) {
        return (1) ;
    } printf ("Une pièce bloque le chemin\n") ;
    return (0) ;
}

    //Mouvement Fou
int mvt_fou (Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin) {
    int compteur = 0 ;
    if (xdebut - xfin == ydebut - yfin) {
        if (xdebut < xfin) {
            if (xfin - xdebut >= 2) {
                for (int i = 1 ; i < xfin - xdebut ; i++) {
                    if (plateau[xdebut + i][ydebut + i] != NULL) compteur += 1 ;
                }
            }
        } else {
            if (xdebut - xfin >= 2) {
                for (int i = 1 ; i < xdebut - xfin ; i++) {
                    if (plateau[xdebut - i][ydebut - i] != NULL) compteur += 1 ;
                    
                }
            }
        }
    } else if (xdebut - xfin == -1 * (ydebut - yfin)) {
        if (xdebut < xfin) {
            if (xfin - xdebut >= 2) {
                for (int i = 1 ; i < xfin - xdebut ; i++) {
                    if (plateau[xdebut + i][ydebut - i] != NULL) compteur += 1 ;
                }
            }
        } else {
            if (xdebut - xfin >= 2) {
                for (int i = 1 ; i < xdebut - xfin ; i++) {
                    if (plateau[xdebut - i][ydebut + i] != NULL) compteur += 1 ;
                }
            }
        }
    } else {
        printf ("Mouvement Illégal\n") ;
        return (0); ;
    } if (compteur == 0) {
        return (1) ;
    } printf ("Une pièce bloque le chemin\n") ;
    return (0) ;
}
    //mouv de la reine
int mvt_reine (Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin) {
    if((xdebut == xfin) || (ydebut == yfin) ) return mvt_tour (plateau, xdebut, ydebut, xfin, yfin);
    if(abs(xfin - xdebut) == abs(yfin - ydebut) ) return mvt_fou (plateau, xdebut, ydebut, xfin, yfin) ;
    printf ("Mouvement Illégal\n") ;
    return (0) ;  
}
    //mouv du roi 
int mvt_roi (Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin) {
    if ((xdebut - xfin <= 1) || (xdebut - xfin >= -1)) {
        if ((ydebut - yfin <= 1) || (ydebut - yfin >= -1)) {
            return (1) ;
        } //Faire le Roque autour de là
    } printf ("Mouvement Illégal\n") ;
    return (0) ;
}

int mouvement (Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin) {
    if ((xdebut == xfin) && (ydebut == yfin)) {
        printf ("Aucun Déplacement effectué\n") ;
        return (0) ;
    } if (plateau[xdebut][ydebut] == NULL) {
        printf ("Aucune Pièce Sélectionnée\n") ;
        return (0) ;
    } if ((plateau[xfin][yfin] != NULL) && (plateau[xfin][yfin] -> C == plateau[xdebut][ydebut] -> C)) {
        printf ("Case de fin est une pièce appartenant déjà au joueur\n") ;
        return (0) ;
    } if (plateau[xdebut][ydebut] -> name == Pion) return mvt_pions(plateau, xdebut, ydebut, xfin, yfin) ;
    if (plateau[xdebut][ydebut] -> name == Cavalier) return mvt_cava(plateau, xdebut, ydebut, xfin, yfin) ;
    if (plateau[xdebut][ydebut] -> name == Tour) return mvt_tour(plateau, xdebut, ydebut, xfin, yfin) ;
    if (plateau[xdebut][ydebut] -> name == Fou) return mvt_fou(plateau, xdebut, ydebut, xfin, yfin) ;
    if (plateau[xdebut][ydebut] -> name == Reine) return mvt_reine(plateau, xdebut, ydebut, xfin, yfin) ;
    else {
        return mvt_roi(plateau, xdebut, ydebut, xfin, yfin) ;
    }
}
