#ifndef MVT_H
#define MVT_H

void manger (Joueur* J, Piece*** plateau, int x, int y);

void deplacement (Joueur* J, Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin);

int mvt_pions (Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin);

int mvt_cava (Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin);

int mvt_tour (Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin);

int mvt_fou (Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin);

int mvt_reine (Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin);

int mvt_roi (Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin);

int mouvement (Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin);


#endif