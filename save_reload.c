#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controle_plateau.h"
#include "fini.h"
#include " mvt.h"

void save(const char* nom_fichier, Piece*** plateau, Joueur* J1, Joueur* J2, Couleur actuel){
    FILE *f=fopen(nom_fichier, "w");
    if(f==NULL){
        perror("Erreur de sauvegarde");
        return;
    }
    fprintf(f, "%d\n", actuel); //sauvegarde du prochain joueur à jouer

    fprintf(f, "%d %d %d\n", J1->C, J1->Points, J1->temps);

    fprintf(f, "%d %d %d\n", J2->C, J2->Points, J2->temps);

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if (plateau[i][j]!=NULL) fprintf(f,"%d %d %d %d\n", plateau[i][j]->name,plateau[i][j]->C,plateau[i][j]->Point,plateau[i][j]->CptMvt); //les symboles seronts remis au chargement
            fprintf(f,"-1 -1 0 0\n"); /pour identifier les cases vides
        }
    }
    
    fclose(f);
    printf("Sauvegarde réussie");
}

void reload(constant char* nom_fichier, Piece*** plateau, Joueur* J1, Joueur* J2, Couleur* actuel){
    File f*=fopen(nom_fichier, "r");
    if(f==NULL){
        perror("Erreur de chargement");
        return;
    }
    int tmp;
    fscanf(f, "%d", &tmp);
    *actuel=(Couleur)tmp; //récupération de la couleur du joueur courant
    fscanf(f, "%d %d %d", &J1->C, &J1->Points, &J1->temps);
    fscanf(f, "%d %d %d", &J2->C, &J2->Points, &J2->temps);

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            int name, C, Point, CptMvt;
            fscanf(f,"&d &d &d &d", &name, &C, &Point, &CptMvt);

            if(name == -1) plateau[i][j]=NULL;
            else{
                plateau[i][j] = malloc(sizeof(Piece));
                if(!plateau[i][j]){
                    fclose(f);
                    return;
                }
                plateau[i][j]->name=(NomPiece)name;
                plateau[i][j]->C =C;
                plateau[i][j]->Point=Point;
                plateau[i][j]->CptMvt=CptMvt;
            }
        }
    }
    fclose(f);
    printf("Chargement réussi\n");
}