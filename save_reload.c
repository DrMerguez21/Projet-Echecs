#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controle_plateau.h"
#include "fini.h"
#include " mvt.h"

void save(const char* nom_fichier, Piece*** plateau, Joueur* J1, Joueur* J2, Couleur actuel){
    FILE *f=fopen(nom_fichier, 'w');
    if(!f){
        perror('Erreur de sauvegarde');
        return;
    }
    fprintf(f, "%d\n", actuel); //sauvegarde du prochain joueur à jouer

    fprintf(f, "%d %d %d\n", J1->C, J1->Points, J1->temps);

    fprintf(f, "%d %d %d\n", J2->C, J2->Points, J2->temps);

    for(int i=0; i<8; i++){
        for(int j=0; j<8; i++){
            fprintf(f,"%d %d %d %d\n", plateau[i][j]->name,plateau[i][j]->C,plateau[i][j]->Point,plateau[i][j]->CptMvt); //les symboles seronts remis au chargement
        }
    }
    
    fclose(f);
    printf("Sauvegarde réussie");
}