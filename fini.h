#ifndef FINI_H
#define FINI_H

int fini (Piece*** plateau, Joueur* J1, Joueur* J2);

int trouver_roi(Piece*** plateau, Couleur couleur);

int check (Piece*** plateau, int xroi, int yroi);
#endif