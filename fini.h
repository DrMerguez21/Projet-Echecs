#ifndef FINI_H
#define FINI_H

int fini (Joueur* J1, Joueur* J2);

void trouver_roi(Piece*** plateau, Couleur couleur);

int check (Piece*** plateau, int xroi, int yroi);
#endif