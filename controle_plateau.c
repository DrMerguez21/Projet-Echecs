#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controle_plateau.h"



Piece* ini_piece(NomPiece nom, Couleur c, int point, char symbole){
    Piece* new=malloc(sizeof(Piece));
    new->name=nom;
    new->C=c;
    new->Point=point;
    new->CptMvt=0;
    new->Symbole=symbole;

    return new;
}

Piece*** ini_plateau(){
    Piece*** plateau=malloc(8*sizeof(Piece**)); //crée les lignes du plateau
    for(int i=0; i<8; i++){
        plateau[i]=malloc(8*sizeof(Piece*)); //crée les colonnes du plateau
    }
    plateau[0][0]=ini_piece(Tour,Noir,5,'r');// pièces noires
    plateau[0][1]=ini_piece(Cavalier,Noir,3,'n');
    plateau[0][2]=ini_piece(Fou,Noir,3,'b');
    plateau[0][3]=ini_piece(Roi,Noir,0,'k');
    plateau[0][4]=ini_piece(Reine,Noir,9,'q');
    plateau[0][5]=ini_piece(Fou,Noir,3,'b');
    plateau[0][6]=ini_piece(Cavalier,Noir,3,'n');
    plateau[0][7]=ini_piece(Tour,Noir,5,'r');
    for (int j=0; j<8; j++){
        plateau[1][j]=ini_piece(Pion,Noir,1,'p');
    }
    for(int i=2; i<6; i++){ //on place les cases vides
        for (int j=0; j<8; j++){
            plateau[i][j]=NULL;
        }
    }
    for (int j=0; j<8; j++){ //piècces blanches
        plateau[6][j]=ini_piece(Pion,Blanc,1,'P');
    }
    plateau[7][0]=ini_piece(Tour,Blanc,5,'R');
    plateau[7][1]=ini_piece(Cavalier,Blanc,3,'N');
    plateau[7][2]=ini_piece(Fou,Blanc,3,'B');
    plateau[7][3]=ini_piece(Roi,Blanc,0,'K');
    plateau[7][4]=ini_piece(Reine,Blanc,9,'Q');
    plateau[7][5]=ini_piece(Fou,Blanc,3,'B');
    plateau[7][6]=ini_piece(Cavalier,Blanc,3,'N');
    plateau[7][7]=ini_piece(Tour,Blanc,5,'R');

    return plateau;
}

void affiche_plateau(Piece*** plateau){
    printf("+-+-+-+-+-+-+-+-+\n");
    for(int i=0;i<8;i++){
        printf("|");
        for (int j=0;j<8;j++){
            if(plateau[i][j]!=NULL) printf("%c|",plateau[i][j]->Symbole);
            else printf(" |");
        }
        printf("\n");
        printf("+-+-+-+-+-+-+-+-+\n");
    }
}

void free_plateau(Piece*** plateau){
    for (int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if( plateau[i][j]!=NULL) free(plateau[i][j]);
        }
        free(plateau[i]);
    }
    free(plateau);
}

int main(){
    Piece*** plateau=ini_plateau();
    affiche_plateau(plateau);
    free_plateau(plateau);
}