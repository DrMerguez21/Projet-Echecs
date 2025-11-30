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
    char Symbole ;
} Piece;

Piece* ini_piece(NomPiece nom, Couleur c, int point, char symbole);

Piece*** ini_plateau();

void affiche_plateau(Piece*** plateau);

void free_plateau(Piece*** plateau);

#endif