#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controle_plateau.h"

void mouvement (Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin) {
    if ((xdebut == xfin) && (ydebut == yfin)) {
        printf ("Aucun Déplacement effectué\n") ;
    } else if (plateau[xdebut][ydebut] == NULL) {
        printf ("Aucune Pièce Sélectionnée\n") ;
    } else if ((plateau[xfin][yfin] != NULL) && (plateau[xfin][yfin] -> C == plateau[xdebut][ydebut] -> C)) {
        printf ("Case de fin est une pièce appartenant déjà au joueur\n") ;
    }
    //Mouvement Pions
    else if (plateau[xdebut][ydebut] -> name == Pion) {
        if ((plateau[xdebut][ydebut] -> C == Blanc) && (xfin == xdebut - 1)) {
            if (ydebut != yfin) {
                if ((yfin == ydebut + 1) || (yfin == ydebut - 1)) { //mouv en diago pour manger
                    if ((plateau[xfin][yfin] != NULL) && (plateau[xfin][yfin] -> C == Noir)){
                        // mettre futur système de points ici
                        Piece* temp=plateau[xfin][yfin];
                        plateau[xdebut][ydebut] -> CptMvt += 1 ;
                        plateau[xfin][yfin] = plateau[xdebut][ydebut] ;
                        plateau[xdebut][ydebut] = NULL ;
                        free(temp); //suppr la pièce mangée
                    } else {
                        printf ("Mouvement Illégal\n") ;
                    }
                } else {
                    printf ("Mouvement Illégal\n") ;
                }
            } else if (plateau[xfin][yfin] == NULL) {
                plateau[xdebut][ydebut] -> CptMvt += 1 ;
                plateau[xfin][yfin] = plateau[xdebut][ydebut] ;
                plateau[xdebut][ydebut] = NULL ;
            } else {
                printf ("Mouvement Illégal\n") ;
            }
        } else if ((plateau[xdebut][ydebut] -> C == Noir) && (xfin == xdebut + 1)) {
            if (ydebut != yfin) {
                if ((yfin == ydebut + 1) || (yfin == ydebut - 1)) {
                    if ((plateau[xfin][yfin] != NULL) && (plateau[xfin][yfin] -> C == Blanc)){
                        // mettre futur système de points ici
                        Piece* temp=plateau[xfin][yfin];
                        plateau[xdebut][ydebut] -> CptMvt += 1 ;
                        plateau[xfin][yfin] = plateau[xdebut][ydebut] ;
                        plateau[xdebut][ydebut] = NULL ;
                        free(temp);
                    } else {
                        printf ("Mouvement Illégal\n") ;
                    }
                } else {
                    printf ("Mouvement Illégal\n") ;
                }
            } else if (plateau[xfin][yfin] == NULL) {
                plateau[xdebut][ydebut] -> CptMvt += 1 ;
                plateau[xfin][yfin] = plateau[xdebut][ydebut] ;
                plateau[xdebut][ydebut] = NULL ;
            } else {
                printf ("Mouvement Illégal\n") ;
            }
        } else if (((plateau[xdebut][ydebut] -> C == Blanc) && (plateau[xdebut][ydebut] -> CptMvt == 0)) && ((xfin == xdebut - 2) && (ydebut == yfin))) {
            if (plateau[xdebut-1][ydebut] == NULL) { //si la case devant le pion est vide
                plateau[xdebut][ydebut] -> CptMvt += 1 ;
                plateau[xfin][yfin] = plateau[xdebut][ydebut] ;
                plateau[xdebut][ydebut] = NULL ;
            } else {
                printf ("Mouvement Illégal\n") ;
            }
        } else if (((plateau[xdebut][ydebut] -> C == Noir) && (plateau[xdebut][ydebut] -> CptMvt == 0)) && ((xfin == xdebut + 2) && (ydebut == yfin))) {
            if (plateau[xdebut+1][ydebut] == NULL) { //la case devant le pion est vide
                plateau[xdebut][ydebut] -> CptMvt += 1 ;
                plateau[xfin][yfin] = plateau[xdebut][ydebut] ;
                plateau[xdebut][ydebut] = NULL ;
            } else {
                printf ("Mouvement Illégal\n") ;
            }
        }
    } 
    //Mouvement Cavalier
    else if (plateau[xdebut][ydebut] -> name == Cavalier) {
        if ((xfin == xdebut + 2) || (xfin == xdebut - 2)) { // y a pas la vérif qu'on bouffe une pièce?
            if ((yfin == ydebut + 1) || (yfin == ydebut - 1)) {
                //Mettre futur système de points ici
                plateau[xdebut][ydebut] -> CptMvt += 1 ;
                plateau[xfin][yfin] = plateau[xdebut][ydebut] ;
                plateau[xdebut][ydebut] = NULL ;
            } else {
                printf ("Mouvement Illégal\n") ;
            }
        } else if ((xfin == xdebut + 1) || (xfin == xdebut - 1)) {
            if ((yfin == ydebut + 2) || (yfin == ydebut - 2)) {
                plateau[xdebut][ydebut] -> CptMvt += 1 ;
                plateau[xfin][yfin] = plateau[xdebut][ydebut] ;
                plateau[xdebut][ydebut] = NULL ;
            } else {
                printf ("Mouvement Illégal\n") ;
            }
        } else {
            printf ("Mouvement Illégal\n") ;
        }
    }
    //Mouvement Tour
    else if (plateau[xdebut][ydebut] -> name == Tour) {
        int compteur = 0 ;
        if (xdebut == xfin) {
            if (ydebut < yfin) {
                if (yfin - ydebut >= 2) {
                    for (int i = ydebut + 1 ; i < yfin ; i++) { //vérif que les cases sont toutes vides entre la tour et la case où elle veut aller
                        if (plateau[xdebut][i] != NULL) {
                            compteur += 1 ;
                        }
                    }
                } 
            } else {
                if (ydebut - yfin >= 2) {
                    for (int i = ydebut + 1 ; i < yfin ; i--) {
                        if (plateau[xdebut][i] != NULL) {
                            compteur += 1 ;
                        }
                    }
                }
            }
        } else if (ydebut == yfin) {
            if (xdebut < xfin) {
                if (xfin - xdebut >= 2) {
                    for (int i = xdebut + 1 ; i < xfin ; i++) {
                        if (plateau[i][ydebut] != NULL) {
                            compteur += 1 ;
                        }
                    }
                } 
            } else {
                if (xdebut - xfin >= 2) {
                    for (int i = xdebut + 1 ; i < xfin ; i--) {
                        if (plateau[i][ydebut] != NULL) {
                            compteur += 1 ;
                        }
                    }
                }
            }
        } else {
            printf ("Mouvement Illégal\n") ;
            compteur = 1 ;
        } if (compteur == 0) {
            //Faire le calcul des points ici
            plateau[xdebut][ydebut] -> CptMvt += 1 ;
            plateau[xfin][yfin] = plateau[xdebut][ydebut] ;
            plateau[xdebut][ydebut] = NULL ;
        } else {
            printf ("Une pièce bloque le chemin\n") ;
        }
    }
    //Mouvement Fou
    else if (plateau[xdebut][ydebut] -> name == Fou) {
        int compteur = 0 ;
        if (xdebut - xfin == ydebut - yfin) {
            if (xdebut < xfin) {
                if (xfin - xdebut >= 2) {
                    for (int i = 1 ; i < xfin - xdebut ; i++) {
                        if (plateau[xdebut + i][ydebut + i] != NULL) {
                            compteur += 1 ;
                        }
                    }
                }
            } else {
                if (xdebut - xfin >= 2) {
                    for (int i = 1 ; i < xdebut - xfin ; i++) {
                        if (plateau[xdebut - i][ydebut - i] != NULL) {
                            compteur += 1 ;
                        }
                    }
                }
            }
        } else if (xdebut - xfin == -1 * (ydebut - yfin)) {
            if (xdebut < xfin) {
                if (xfin - xdebut >= 2) {
                    for (int i = 1 ; i < xfin - xdebut ; i++) {
                        if (plateau[xdebut + i][ydebut - i] != NULL) {
                            compteur += 1 ;
                        }
                    }
                }
            } else {
                if (xdebut - xfin >= 2) {
                    for (int i = 1 ; i < xdebut - xfin ; i++) {
                        if (plateau[xdebut - i][ydebut + i] != NULL) {
                            compteur += 1 ;
                        }
                    }
                }
            }
        } else {
            printf ("Mouvement Illégal\n") ;
            compteur = 1 ;
        } if (compteur == 0) {
            //Faire le calcul des points ici
            plateau[xdebut][ydebut] -> CptMvt += 1 ;
            plateau[xfin][yfin] = plateau[xdebut][ydebut] ;
            plateau[xdebut][ydebut] = NULL ;
        } else {
            printf ("Une pièce bloque le chemin\n") ;
        }
    //mouv de la reine
    } else if (plateau[xdebut][ydebut] -> name == Reine) {
        int compteur = 0 ;
        if (xdebut == xfin) {
            if (ydebut < yfin) {
                if (yfin - ydebut >= 2) {
                    for (int i = ydebut + 1 ; i < yfin ; i++) {
                        if (plateau[xdebut][i] != NULL) {
                            compteur += 1 ;
                        }
                    }
                } 
            } else {
                if (ydebut - yfin >= 2) {
                    for (int i = ydebut + 1 ; i < yfin ; i--) {
                        if (plateau[xdebut][i] != NULL) {
                            compteur += 1 ;
                        }
                    }
                }
            }
        } else if (ydebut == yfin) {
            if (xdebut < xfin) {
                if (xfin - xdebut >= 2) {
                    for (int i = xdebut + 1 ; i < xfin ; i++) {
                        if (plateau[i][ydebut] != NULL) {
                            compteur += 1 ;
                        }
                    }
                } 
            } else {
                if (xdebut - xfin >= 2) {
                    for (int i = xdebut + 1 ; i < xfin ; i--) {
                        if (plateau[i][ydebut] != NULL) {
                            compteur += 1 ;
                        }
                    }
                }
            }
        } else if (xdebut - xfin == ydebut - yfin) {
            if (xdebut < xfin) {
                if (xfin - xdebut >= 2) {
                    for (int i = 1 ; i < xfin - xdebut ; i++) {
                        if (plateau[xdebut + i][ydebut + i] != NULL) {
                            compteur += 1 ;
                        }
                    }
                }
            } else {
                if (xdebut - xfin >= 2) {
                    for (int i = 1 ; i < xdebut - xfin ; i++) {
                        if (plateau[xdebut - i][ydebut - i] != NULL) {
                            compteur += 1 ;
                        }
                    }
                }
            }
        } else if (xdebut - xfin == -1 * (ydebut - yfin)) {
            if (xdebut < xfin) {
                if (xfin - xdebut >= 2) {
                    for (int i = 1 ; i < xfin - xdebut ; i++) {
                        if (plateau[xdebut + i][ydebut - i] != NULL) {
                            compteur += 1 ;
                        }
                    }
                }
            } else {
                if (xdebut - xfin >= 2) {
                    for (int i = 1 ; i < xdebut - xfin ; i++) {
                        if (plateau[xdebut - i][ydebut + i] != NULL) {
                            compteur += 1 ;
                        }
                    }
                }
            }
        } else {
            printf ("Mouvement Illégal\n") ;
            compteur = 1 ;
        } if (compteur == 0) {
            //Faire le calcul des points ici
            plateau[xdebut][ydebut] -> CptMvt += 1 ;
            plateau[xfin][yfin] = plateau[xdebut][ydebut] ;
            plateau[xdebut][ydebut] = NULL ;
        } else {
            printf ("Une pièce bloque le chemin\n") ;
        }
    }
    //mouv du roi 
    else {
        if ((xdebut - xfin <= 1) || (xdebut - xfin >= -1)) {
            if ((ydebut - yfin <= 1) || (ydebut - yfin >= -1)) {
                //Faire le calcul des points ici
                plateau[xdebut][ydebut] -> CptMvt += 1 ;
                plateau[xfin][yfin] = plateau[xdebut][ydebut] ;
                plateau[xdebut][ydebut] = NULL ;
            } else {
                //Faire le Roque autour de là
                printf ("Mouvement Illégal\n") ;
            }
        }
    }
}

int main(){
    Piece*** plateau=ini_plateau();
    printf("les pièces noires sont écrites en minuscules, les blanches en majuscules, les x correspondent aux lignes et les y aux colonnes\n");
    affiche_plateau(plateau);
    mouvement(plateau, 0,1, 2,2);
    mouvement(plateau, 2,2 ,4,3);
    mouvement(plateau, 4,3 ,6,4);
    affiche_plateau(plateau);
    free_plateau(plateau);
}