#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controle_plateau.h"
#include "mvt.h"
#include "fini.h"

int fini (Piece*** plateau, Joueur* J1, Joueur* J2) {
    if (!trouver_roi(plateau, Noir)) {
        printf("Le joueur Bleu a gagné\n");
        return (1) ;
    }
    if (!trouver_roi(plateau, Blanc)) {
        printf("Le joueur Rouge a gagné\n");
        return (1) ;
    }
    if(J1 ->temps <= 0){
        printf("Le joueur Bleu a perdu au temps\n");
        return (1);
    }
    if(J2 -> temps <=0){
        printf("Le joueur Rouge a perdu au temps\n");
        return (1);
    }
    return (0) ;
}

int trouver_roi(Piece*** plateau, Couleur couleur){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if((plateau[i][j]!=NULL)&&(plateau[i][j]->name==Roi)&&(plateau[i][j]->C==couleur)){
                check(plateau,i,j);
                return 1;
            }
        }
    }
    return 0; //le roi n'a pas été trouvé
}

int check (Piece*** plateau, int xroi, int yroi) {
    for (int i = 0 ; i < 8 ; i++) {
        for (int j = 0 ; j < 8 ; j++) {
            if ((plateau[i][j] != NULL) && (plateau[i][j] -> C != plateau[xroi][yroi] -> C) && (mouvement(0,plateau, i, j, xroi, yroi, plateau[i][j] -> C) == 1)) {
                if(plateau[xroi][yroi]==Blanc) printf ("Echec du roi bleu en %d %d", xroi, yroi) ;
                else{
                    printf ("Echec du roi rouge en %c%d\n", reconvert_y(yroi), reconvert_x(xroi)) ;        
                }
                return 1;
            }
        }
    } return 0;
}

int case_attaque(Piece*** plateau, int x, int y, Couleur couleur){ // vérifie si la case vide est attaquée par le joueur de la couleur opposé
    if(plateau[x][y]!=NULL) return 0;
    Piece* temp=ini_pion(couleur); //on créé une pièce fantome de la couleur du joueur
    plateau[x][y]=temp;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if((plateau[i][j]!=NULL)&&(plateau[i][j]->C!=couleur)&&(mouvement(0,plateau, i, j, x, y, plateau[i][j]->C))){
                printf("la case %c%d est attaquée\n", reconvert_y(y), reconvert_x(x));
                free(temp);
                plateau[x][y]=NULL;
                return 1; 
            }
        }
    }
    free(temp);
    plateau[x][y]=NULL;
    return 0;
}