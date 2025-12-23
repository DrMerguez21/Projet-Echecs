#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "controle_plateau.h"


Piece* ini_pion(Couleur c){
    Piece* new=malloc(sizeof(Piece));
    new->name=Pion;
    new->C=c;
    new->Point=1;
    new->CptMvt=0;
    if(c==Blanc) strcpy(new->Symbole,"\u2659");
    else strcpy(new->Symbole,"\u265F");

    return new;
}

Piece* ini_tour(Couleur c){
    Piece* new=malloc(sizeof(Piece));
    new->name=Tour;
    new->C=c;
    new->Point=5;
    new->CptMvt=0;
    if(c==Blanc) strcpy(new->Symbole,"\u2656");
    else strcpy(new->Symbole,"\u265C");

    return new;
}

Piece* ini_cavalier(Couleur c){
    Piece* new=malloc(sizeof(Piece));
    new->name=Cavalier;
    new->C=c;
    new->Point=3;
    new->CptMvt=0;
    if(c==Blanc) strcpy(new->Symbole,"\u2658");
    else strcpy(new->Symbole,"\u265E");

    return new;
}

Piece* ini_fou(Couleur c){
    Piece* new=malloc(sizeof(Piece));
    new->name=Fou;
    new->C=c;
    new->Point=3;
    new->CptMvt=0;
    if(c==Blanc) strcpy(new->Symbole,"\u2657");
    else strcpy(new->Symbole ,"\u265D");

    return new;
}

Piece* ini_reine(Couleur c){
    Piece* new=malloc(sizeof(Piece));
    new->name=Reine;
    new->C=c;
    new->Point=9;
    new->CptMvt=0;
    if(c==Blanc) strcpy(new->Symbole,"\u2655");
    else strcpy(new->Symbole,"\u265B");

    return new;
}

Piece* ini_roi(Couleur c){
    Piece* new=malloc(sizeof(Piece));
    new->name=Roi;
    new->C=c;
    new->Point=99;
    new->CptMvt=0;
    if(c==Blanc) strcpy(new->Symbole,"\u2654");
    else strcpy(new->Symbole,"\u265A");

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
    J -> Points = 0 ;
    return J ;
}

void affiche_plateau(Piece*** plateau){
    printf("    a   b   c   d   e   f   g   h\n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for(int i=0;i<8;i++){
        printf("%d |", 8-i);
        for (int j=0;j<8;j++){
            if(plateau[i][j]!=NULL) printf(" %s |",plateau[i][j]->Symbole);
            else printf("   |");
        }
        printf(" %d\n", 8-i);
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
        case 8: return 0;
    }return -1; //si la case n'est pas dans le plateau
}

int reconvert_x(int x){
    switch(x){
        case 7: return 1;
        case 6: return 2;
        case 5: return 3;
        case 4: return 4;
        case 3: return 5;
        case 2: return 6;
        case 1: return 7;
    }return 8;
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
        case 'h': return 7;
    }return -1;
}

char reconvert_y(int y){
    switch(y){
        case 0: return 'a';
        case 1: return 'b';
        case 2: return 'c';
        case 3: return 'd';
        case 4: return 'e';
        case 5: return 'f';
        case 6: return 'g';
    }return 'h';
}

void affiche_temps(Joueur* J){
    int temps=J->temps;
    int minute=0;
    while(temps >=60){
        minute ++;
        temps-=60;
    }
    printf("Il vous reste %d min et %d s\n", minute, temps);
}

void affiche_point(Joueur* opposant){
    int points=39-(opposant->Points);
    printf("Il vous reste %d points\n", points);
}

void duree(Joueur* J1, Joueur* J2){
    char longueur;
    printf("quelle type de partie voulez vous jouer ?\n");
    printf("Si vous voulez faire un Blitz de 5 min, entrez b.\n");
    printf("Si vous voulez faire une partie rapide de 20 min, entrez r.\n");
    printf("Si vous voulez faire une partie longue, entrez l.\n");
    scanf(" %c", &longueur);
    if(longueur =='b'){
        J1->temps=(5*60);
        J2->temps=(5*60);
        return;
    }
    if(longueur =='l'){
        J1->temps=(60*60);
        J2->temps=(60*60);
        return;
    }
    J1->temps=(20*60);
    J2->temps=(20*60);
}

void promotion(Piece*** plateau, int xpion, int ypion, Joueur* opposant){
    int temp=plateau[xpion][ypion]->CptMvt;
    char promo;
    if ((plateau[xpion][ypion]!=NULL)&&(plateau[xpion][ypion]->name==Pion)){
        if((plateau[xpion][ypion]->C==Blanc)&&(xpion==0)){ //un pion blanc a traversé le plateau
            printf("le pion en %c%d peut être promu. Entrez r pour le convertir en reine, f pour le convertir en fou, t pour en tour et c pour en cavalier.\n", reconvert_y(ypion), reconvert_x(xpion));
            printf("Sinon la pièce sera automatiquement convertie en reine\n");
            scanf(" %c", &promo);
            free(plateau[xpion][ypion]);
            if(promo == 'f') plateau[xpion][ypion]=ini_fou(Blanc);
            else if(promo=='t') plateau[xpion][ypion]=ini_tour(Blanc);
            else if(promo=='c') plateau[xpion][ypion]=ini_cavalier(Blanc);
            else plateau[xpion][ypion]=ini_reine(Blanc);
            plateau[xpion][ypion]->CptMvt=temp;
            opposant->Points -= (plateau[xpion][ypion]->Point -1); //on prend en compte la promotion dans le décompte des points
        }
        if((plateau[xpion][ypion]->C==Noir)&&(xpion==7)){ //un pion blanc a traversé le plateau
            printf("le pion en %c%d peut être promu. Entrez r pour le convertir en reine, f pour le convertir en fou, t pour en tour et c pour en cavalier.\n", reconvert_y(ypion), reconvert_x(xpion));
            printf("Sinon la pièce sera automatiquement convertie en reine\n");
            scanf(" %c", &promo);
            free(plateau[xpion][ypion]);
            if(promo == 'f') plateau[xpion][ypion]=ini_fou(Noir);
            else if(promo=='t') plateau[xpion][ypion]=ini_tour(Noir);
            else if(promo=='c') plateau[xpion][ypion]=ini_cavalier(Noir);
            else plateau[xpion][ypion]=ini_reine(Noir);
            plateau[xpion][ypion]->CptMvt=temp;
            opposant->Points -= (plateau[xpion][ypion]->Point -1);
        }
    }
}