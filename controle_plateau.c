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
    if(c==Blanc) new->Symbole="\u2659";
    else new->Symbole ="\u265F";

    return new;
}

Piece* ini_tour(Couleur c){
    Piece* new=malloc(sizeof(Piece));
    new->name=Tour;
    new->C=c;
    new->Point=5;
    new->CptMvt=0;
    if(c==Blanc) new->Symbole="\u2656";
    else new->Symbole ="\u265C";

    return new;
}

Piece* ini_cavalier(Couleur c){
    Piece* new=malloc(sizeof(Piece));
    new->name=Cavalier;
    new->C=c;
    new->Point=3;
    new->CptMvt=0;
    if(c==Blanc) new->Symbole="\u2658";
    else new->Symbole ="\u265E";

    return new;
}

Piece* ini_fou(Couleur c){
    Piece* new=malloc(sizeof(Piece));
    new->name=Fou;
    new->C=c;
    new->Point=3;
    new->CptMvt=0;
    if(c==Blanc) new->Symbole="\u2657";
    else new->Symbole ="\u265D";

    return new;
}

Piece* ini_reine(Couleur c){
    Piece* new=malloc(sizeof(Piece));
    new->name=Reine;
    new->C=c;
    new->Point=9;
    new->CptMvt=0;
    if(c==Blanc) new->Symbole="\u2655";
    else new->Symbole ="\u265B";

    return new;
}

Piece* ini_roi(Couleur c){
    Piece* new=malloc(sizeof(Piece));
    new->name=Roi;
    new->C=c;
    new->Point=99;
    new->CptMvt=0;
    if(c==Blanc) new->Symbole="\u2654";
    else new->Symbole ="\u265A";

    return new;
}

Piece*** ini_plateau_vide(){
    Piece*** plateau=malloc(8*sizeof(Piece**)); //crée les lignes du plateau représentée par les x
    for(int i=0; i<8; i++){
        plateau[i]=malloc(8*sizeof(Piece*)); //crée les colonnes du plateau représentée par les y
    }
    return plateau;
}

Piece*** ini_plateau(){
    Piece*** plateau=ini_plateau_vide();
    plateau[0][0]=ini_tour(Noir);// pièces noires
    plateau[0][1]=ini_cavalier(Noir);
    plateau[0][2]=ini_fou(Noir);
    plateau[0][3]=ini_reine(Noir);
    plateau[0][4]=ini_roi(Noir);
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
    plateau[7][3]=ini_reine(Blanc);
    plateau[7][4]=ini_roi(Blanc);
    plateau[7][5]=ini_fou(Blanc);
    plateau[7][6]=ini_cavalier(Blanc);
    plateau[7][7]=ini_tour(Blanc);

    return plateau;
}

Joueur* init_joueur (Couleur c) {
    Joueur* J = malloc(sizeof(Joueur)) ;
    J -> C = c ;
    J -> temps = 900 ;
    J -> Points = 0 ;
    return J ;
}

void affiche_plateau(Piece*** plateau){
    printf("  +---+---+---+---+---+---+---+---+\n");
    for(int i=0;i<8;i++){
        printf("%d |", 8-i);
        for (int j=0;j<8;j++){
            if(plateau[i][j]!=NULL) printf(" %s |",plateau[i][j]->Symbole);
            else printf("   |");
        }
        printf("\n");
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
    printf("    a   b   c   d   e   f   g   h\n");
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

int convert_x(int xdebut){
    switch(xdebut){
        case 1: return 7;
        case 2: return 6;
        case 3: return 5;
        case 4: return 4;
        case 5: return 3;
        case 6: return 2;
        case 7: return 1;
    }return 0;
}

int convert_y(char ydebut){
    switch(ydebut){
        case 'a': return 0;
        case 'b': return 1;
        case 'c': return 2;
        case 'd': return 3;
        case 'e': return 4;
        case 'f': return 5;
        case 'g': return 6;
    }return 7;
}
