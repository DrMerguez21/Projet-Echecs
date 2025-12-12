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
    const char* Symbole ;
} Piece;

typedef struct joueur {
    Couleur C;
    int Points;
    int temps;
} Joueur;

Piece* ini_pion(Couleur c);

Piece* ini_tour(Couleur c);

Piece* ini_cavalier(Couleur c);

Piece* ini_fou(Couleur c);

Piece* ini_reine(Couleur c);

Piece* ini_roi(Couleur c);

Piece*** ini_plateau();

void affiche_plateau(Piece*** plateau);

void free_plateau(Piece*** plateau);

#endif