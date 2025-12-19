#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controle_plateau.h"
#include "mvt.h"
#include "fini.h"

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
int mvt_pions (int affiche_erreur, Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin) {
    if ((plateau[xdebut][ydebut] -> C == Blanc) && (xfin == xdebut - 1)) {
        if (ydebut != yfin) {
            if ((yfin == ydebut + 1) || (yfin == ydebut - 1)) { //mouv en diago pour manger
                if ((plateau[xfin][yfin] != NULL) && (plateau[xfin][yfin] -> C == Noir)){
                    return (1) ;
                } if (affiche_erreur) printf ("Mouvement Illégal\n") ;
                return (0) ;
            } if(affiche_erreur) printf ("Mouvement Illégal\n") ;
            return (0) ;
        } if (plateau[xfin][yfin] == NULL) {
            return (1) ;
        } if(affiche_erreur) printf ("Mouvement Illégal\n") ;
        return (0) ;
    } if ((plateau[xdebut][ydebut] -> C == Noir) && (xfin == xdebut + 1)) {
        if (ydebut != yfin) {
            if ((yfin == ydebut + 1) || (yfin == ydebut - 1)) {
                if ((plateau[xfin][yfin] != NULL) && (plateau[xfin][yfin] -> C == Blanc)){
                    return (1) ;
                } if(affiche_erreur) printf ("Mouvement Illégal\n") ;
                return (0) ;
            } if(affiche_erreur) printf ("Mouvement Illégal\n") ;
            return (0) ;
        } if (plateau[xfin][yfin] == NULL) {
            return (1) ;
        } if(affiche_erreur) printf ("Mouvement Illégal\n") ;
        return (0) ;
    } if (((plateau[xdebut][ydebut] -> C == Blanc) && (plateau[xdebut][ydebut] -> CptMvt == 0)) && ((xfin == xdebut - 2) && (ydebut == yfin))) {
        if ((plateau[xdebut - 1][ydebut] == NULL) && (plateau[xdebut - 2][ydebut]==NULL)) { //si la case devant le pion est vide
            return (1) ;
        } if(affiche_erreur) printf ("Mouvement Illégal\n") ;
        return (0) ;
    } if (((plateau[xdebut][ydebut] -> C == Noir) && (plateau[xdebut][ydebut] -> CptMvt == 0)) && ((xfin == xdebut + 2) && (ydebut == yfin))) {
        if ((plateau[xdebut+1][ydebut] == NULL) && (plateau[xdebut + 2][ydebut]==NULL)) { //la case devant le pion est vide
            return (1) ;
        } if(affiche_erreur) printf ("Mouvement Illégal\n") ;
        return (0) ;
    } if(affiche_erreur) printf ("Mouvement Illégal\n") ;
    return (0) ;
}

    //Mouvement Cavalier
int mvt_cava (int affiche_erreur, Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin) {
    if ((xfin == xdebut + 2) || (xfin == xdebut - 2)) { 
        if ((yfin == ydebut + 1) || (yfin == ydebut - 1)) {
            return (1) ;
        } if(affiche_erreur) printf ("Mouvement Illégal\n") ;
        return (0) ;
    } if ((xfin == xdebut + 1) || (xfin == xdebut - 1)) {
        if ((yfin == ydebut + 2) || (yfin == ydebut - 2)) {
            return (1) ;
        } if(affiche_erreur) printf ("Mouvement Illégal\n") ;
        return (0) ;
    } if(affiche_erreur) printf ("Mouvement Illégal\n") ;
    return (0) ;
}
    //Mouvement Tour
int mvt_tour (int affiche_erreur, Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin) {
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
        if(affiche_erreur) printf ("Mouvement Illégal\n") ;
        return (0) ;
    } if (compteur == 0) {
        return (1) ;
    } if(affiche_erreur) printf ("Une pièce bloque le chemin\n") ;
    return (0) ;
}

    //Mouvement Fou
int mvt_fou (int affiche_erreur, Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin) {
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
        if(affiche_erreur) printf ("Mouvement Illégal\n") ;
        return (0); ;
    } if (compteur == 0) {
        return (1) ;
    } if(affiche_erreur) printf ("Une pièce bloque le chemin\n") ;
    return (0) ;
}
    //mouv de la reine
int mvt_reine (int affiche_erreur, Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin) {
    if((xdebut == xfin) || (ydebut == yfin) ) return mvt_tour (affiche_erreur, plateau, xdebut, ydebut, xfin, yfin);
    if(abs(xfin - xdebut) == abs(yfin - ydebut) ) return mvt_fou (affiche_erreur, plateau, xdebut, ydebut, xfin, yfin) ;
    if(affiche_erreur) printf ("Mouvement Illégal\n") ;
    return (0) ;  
}

int petit_roque(int affiche_erreur, Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin){
    if((plateau[xdebut][7]==NULL)||(plateau[xdebut][7]->name!=Tour)) return 0;
    if((plateau[xdebut][ydebut]->CptMvt!=0)||(plateau[xdebut][7]->CptMvt!=0)) return 0; //roque impossible si le roi  ou la tour a déjà bougé
    if(check(plateau,xdebut, ydebut))return 0; // si le roi est en échec ou que les cases sur lesquelles il va se déplacer sont attaqué, le roque est impossible
    return mvt_tour(affiche_erreur, plateau,xdebut, 7, xdebut, 5); //si le mouvement de la tour est impossible, car il y a des pièces sur le chemin, le roque ne l'est pas non plus   
}

int grand_roque(int affiche_erreur, Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin){
    if((plateau[xdebut][0]==NULL) || (plateau[xdebut][0]->name!=Tour)) return 0;
    if((plateau[xdebut][ydebut]->CptMvt!=0)||(plateau[xdebut][0]->CptMvt!=0)) return 0; //roque impossible si le roi  ou la tour a déjà bougé
    if(check(plateau,xdebut, ydebut))return 0; // si le roi est en échec ou que les cases sur lesquelles il va se déplacer sont attaqué, le roque est impossible
    return mvt_tour(affiche_erreur, plateau,xdebut, 0, xdebut, 3); //si le mouvement de la tour est impossible, car il y a des pièces sur le chemin, le roque ne l'est pas non plus   
}

    //mouv du roi 
int mvt_roi (int affiche_erreur, Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin) {
    //Faire le Roque autour de là
    if ((yfin==ydebut+2)&&(xfin==xdebut)&& petit_roque(affiche_erreur, plateau, xdebut, ydebut, xfin, yfin)){ //petit roque
        return (2); //nécessaire pour ensuite indiquer au jeu qu'il faut aussi bouger la tour de droite
    }
    if ((yfin==ydebut-2)&&(xfin==xdebut) && grand_roque(affiche_erreur, plateau, xdebut, ydebut, xdebut, yfin)){
        return (3);
    }
    if ((abs(xdebut - xfin) <= 1) && abs(ydebut - yfin) <= 1) {
            return (1) ;
    } 
    if(affiche_erreur) printf ("Mouvement Illégal\n") ;
    return (0) ;
}

int mouvement (int affiche_erreur, Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin, Couleur couleur) {
    if(plateau[xdebut][ydebut]->C!=couleur){
        if(affiche_erreur) printf("La pièce ne vous appartient pas\n");
        return (0);
    }if((xdebut==-1)||(ydebut==-1)||(xfin==-1)||(yfin==-1)){
        if(affiche_erreur) printf("L'une des cases sélectionnées ne fait pas partie du plateau\n");
        return (0);
    }if ((xdebut == xfin) && (ydebut == yfin)) {
        if(affiche_erreur) printf ("Aucun Déplacement effectué\n") ;
        return (0) ;
    } if (plateau[xdebut][ydebut] == NULL) {
        if(affiche_erreur) printf ("Aucune Pièce Sélectionnée\n") ;
        return (0) ;
    } if ((plateau[xfin][yfin] != NULL) && (plateau[xfin][yfin] -> C == plateau[xdebut][ydebut] -> C)) {
        if(affiche_erreur) printf ("Case de fin est une pièce appartenant déjà au joueur\n") ;
        return (0) ;
    } if (plateau[xdebut][ydebut] -> name == Pion) return mvt_pions(affiche_erreur, plateau, xdebut, ydebut, xfin, yfin) ;
    if (plateau[xdebut][ydebut] -> name == Cavalier) return mvt_cava(affiche_erreur, plateau, xdebut, ydebut, xfin, yfin) ;
    if (plateau[xdebut][ydebut] -> name == Tour) return mvt_tour(affiche_erreur, plateau, xdebut, ydebut, xfin, yfin) ;
    if (plateau[xdebut][ydebut] -> name == Fou) return mvt_fou(affiche_erreur, plateau, xdebut, ydebut, xfin, yfin) ;
    if (plateau[xdebut][ydebut] -> name == Reine) return mvt_reine(affiche_erreur, plateau, xdebut, ydebut, xfin, yfin) ;
    else {
        return mvt_roi(affiche_erreur, plateau, xdebut, ydebut, xfin, yfin) ;
    }
}
