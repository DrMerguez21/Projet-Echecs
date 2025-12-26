#ifndef SAVE_H
#define SAVE_H

int save(const char* nom_fichier, Piece*** plateau, Joueur* J1, Joueur* J2, Couleur actuel);

int reload(const char* nom_fichier, Piece*** plateau, Joueur* J1, Joueur* J2, Couleur* actuel);

#endif