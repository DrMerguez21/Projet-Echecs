#ifndef CONTROLE_PLATEAU_H
#define CONTROLE_PLATEAU_H

enum nom
{
    Pion, Tour, Cavalier, Fou, Reine, Roi
};
typedef enum nom NomPiece ;

enum couleur
{
    Blanc, Noir
};
typedef enum couleur Couleur ;

typedef struct piece {
    NomPiece name ;
    Couleur C ;
    int Point ;
    int CptMvt ;
    char Symbole[5] ;
} Piece;

typedef struct joueur {
    Couleur C;
    int Points;
    int temps;
} Joueur;

Joueur* init_joueur (Couleur c);

Piece* ini_pion(Couleur c);

Piece* ini_tour(Couleur c);

Piece* ini_cavalier(Couleur c);

Piece* ini_fou(Couleur c);

Piece* ini_reine(Couleur c);

Piece* ini_roi(Couleur c);

Piece*** ini_plateau_vide();

Piece*** ini_plateau();

void affiche_plateau(Piece*** plateau);

void free_plateau(Piece*** plateau);

int convert_x(int xdebut);

int reconvert_x(int x);

int convert_y(char ydebut);

char reconvert_y(int y);

void affiche_temps(Joueur* J);

void affiche_point(Joueur* opposant);

void duree(Joueur* J1, Joueur* J2);

void promotion(Piece*** plateau, int xpion, int ypion, Joueur* opposant);

#endif