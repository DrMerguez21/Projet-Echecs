#ifndef MVT_H
#define MVT_H

void manger (Joueur* J, Piece*** plateau, int x, int y);

void deplacement (Joueur* J, Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin);

int mvt_pions (int affiche_erreur, Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin);

int mvt_cava (int affiche_erreur, Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin);

int mvt_tour (int affiche_erreur, Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin);

int mvt_fou (int affiche_erreur, Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin);

int mvt_reine (int affiche_erreur, Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin);

int petit_roque(int affiche_erreur, Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin);

int grand_roque(int affiche_erreur, Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin);

int mvt_roi (int affiche_erreur, Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin);

int mouvement (int affiche_erreur, Piece*** plateau, int xdebut, int ydebut, int xfin, int yfin, Couleur couleur);


#endif