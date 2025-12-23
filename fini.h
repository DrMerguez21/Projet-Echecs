#ifndef FINI_H
#define FINI_H

int fini (Piece*** plateau, Joueur* J1, Joueur* J2);

int trouver_roi(Piece*** plateau, Couleur couleur, int* xroi, int* yroi);

int check (int affiche_erreur, Piece*** plateau, int xroi, int yroi);

int case_attaque(Piece*** plateau, int x, int y, Couleur couleur);

#endif