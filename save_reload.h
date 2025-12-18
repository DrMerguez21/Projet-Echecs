#ifndef SAVE_RELOAD_H
#define SAVE_RELOAD_H

void save(const char* nom_fichier, Piece*** plateau, Joueur* J1, Joueur* J2, Couleur actuel);

void reload(const char* nom_fichier, Piece*** plateau, Joueur* J1, Joueur* J2, Couleur* actuel);

#endif