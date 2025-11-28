#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

struct piece {
    NomPiece name ;
    Couleur C ;
    int Point ;
    int CptMvt ;
    char Symbole ;
} ;
typedef struct piece Piece



test
test 2
