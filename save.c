#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "controle_plateau.h"
#include "fini.h"
#include "mvt.h"
#include "save.h"

void save(const char* nom_fichier, Piece*** plateau, Joueur* J1, Joueur* J2, Couleur actuel){
    FILE *f=fopen(nom_fichier, "w");
    if(f==NULL){
        perror("Erreur de sauvegarde\n");
        return;
    }
    fprintf(f, "%d\n", actuel); //sauvegarde du prochain joueur à jouer

    fprintf(f, "%d %d %d\n", J1->C, J1->Points, J1->temps);

    fprintf(f, "%d %d %d\n", J2->C, J2->Points, J2->temps);

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if (plateau[i][j]!=NULL) fprintf(f,"%d %d %d %d %s\n", plateau[i][j]->name,plateau[i][j]->C,plateau[i][j]->Point,plateau[i][j]->CptMvt, plateau[i][j]->Symbole); //les symboles seronts remis au chargement
            else{
                fprintf(f,"-1 -1 0 0 -\n"); //pour identifier les cases vides
            }
        }
    }
    
    fclose(f);
    printf("Sauvegarde réussie\n");
}

int reload(const char* nom_fichier, Piece*** plateau, Joueur* J1, Joueur* J2, Couleur* actuel){
    FILE *f=fopen(nom_fichier, "r");
    if(f==NULL){
        perror("Erreur de chargement\n");
        return 0;
    }
    int tmp;
    fscanf(f, "%d", &tmp);
    *actuel=(Couleur)tmp; //récupération de la couleur du joueur courant
    fscanf(f, "%d %d %d", &tmp, &J1->Points, &J1->temps);
    J1->C=(Couleur)tmp;
    fscanf(f, "%d %d %d", &tmp, &J2->Points, &J2->temps);
    J2->C=(Couleur)tmp;

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            int name, C, Point, CptMvt;
            char symbole[5];
            fscanf(f,"%d %d %d %d %4s", &name, &C, &Point, &CptMvt, symbole);

            if(name == -1){
                plateau[i][j]=NULL;
            } 
            else{
                plateau[i][j] = malloc(sizeof(Piece));
                plateau[i][j]->name=(NomPiece)name;
                plateau[i][j]->C =C;
                plateau[i][j]->Point=Point;
                plateau[i][j]->CptMvt=CptMvt;
                strcpy(plateau[i][j]->Symbole, symbole);
            }
        }
    }
    fclose(f);
    printf("Chargement réussi\n");
    return 1;
}