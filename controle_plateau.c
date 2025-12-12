#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controle_plateau.h"


Piece* ini_pion(Couleur c){
    Piece* new=malloc(sizeof(Piece));
    new->name=Pion;
    new->C=c;
    new->Point=1;
    new->CptMvt=0;
    if(c==Blanc) new->Symbole='P';
    else new->Symbole ='p';

    return new;
}

Piece* ini_tour(Couleur c){
    Piece* new=malloc(sizeof(Piece));
    new->name=Tour;
    new->C=c;
    new->Point=5;
    new->CptMvt=0;
    if(c==Blanc) new->Symbole='R';
    else new->Symbole ='r';

    return new;
}

Piece* ini_cavalier(Couleur c){
    Piece* new=malloc(sizeof(Piece));
    new->name=Cavalier;
    new->C=c;
    new->Point=3;
    new->CptMvt=0;
    if(c==Blanc) new->Symbole='N';
    else new->Symbole ='n';

    return new;
}

Piece* ini_fou(Couleur c){
    Piece* new=malloc(sizeof(Piece));
    new->name=Fou;
    new->C=c;
    new->Point=3;
    new->CptMvt=0;
    if(c==Blanc) new->Symbole='B';
    else new->Symbole ='b';

    return new;
}

Piece* ini_reine(Couleur c){
    Piece* new=malloc(sizeof(Piece));
    new->name=Reine;
    new->C=c;
    new->Point=9;
    new->CptMvt=0;
    if(c==Blanc) new->Symbole='Q';
    else new->Symbole ='q';

    return new;
}

Piece* ini_roi(Couleur c){
    Piece* new=malloc(sizeof(Piece));
    new->name=Roi;
    new->C=c;
    new->Point=99;
    new->CptMvt=0;
    if(c==Blanc) new->Symbole='K';
    else new->Symbole ='k';

    return new;
}


Piece*** ini_plateau(){
    Piece*** plateau=malloc(8*sizeof(Piece**)); //crée les lignes du plateau représentée par les x
    for(int i=0; i<8; i++){
        plateau[i]=malloc(8*sizeof(Piece*)); //crée les colonnes du plateau représentée par les y
    }
    plateau[0][0]=ini_tour(Noir);// pièces noires
    plateau[0][1]=ini_cavalier(Noir);
    plateau[0][2]=ini_fou(Noir);
    plateau[0][3]=ini_roi(Noir);
    plateau[0][4]=ini_reine(Noir);
    plateau[0][5]=ini_fou(Noir);
    plateau[0][6]=ini_cavalier(Noir);
    plateau[0][7]=ini_tour(Noir);
    for (int j=0; j<8; j++){
        plateau[1][j]=ini_pion(Noir);
    }
    for(int i=2; i<6; i++){ //on place les cases vides
        for (int j=0; j<8; j++){
            plateau[i][j]=NULL;
        }
    }
    for (int j=0; j<8; j++){ //piècces blanches
        plateau[6][j]=ini_pion(Blanc);
    }
    plateau[7][0]=ini_tour(Blanc);
    plateau[7][1]=ini_cavalier(Blanc);
    plateau[7][2]=ini_fou(Blanc);
    plateau[7][3]=ini_roi(Blanc);
    plateau[7][4]=ini_reine(Reine);
    plateau[7][5]=ini_fou(Blanc);
    plateau[7][6]=ini_cavalier(Blanc);
    plateau[7][7]=ini_tour(Blanc);

    return plateau;
}

void affiche_plateau(Piece*** plateau){
    printf("   0 1 2 3 4 5 6 7\n");
    printf("  +-+-+-+-+-+-+-+-+\n");
    for(int i=0;i<8;i++){
        printf("%d |", i);
        for (int j=0;j<8;j++){
            if(plateau[i][j]!=NULL) printf("%c|",plateau[i][j]->Symbole);
            else printf(" |");
        }
        printf("\n");
        printf("  +-+-+-+-+-+-+-+-+\n");
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

