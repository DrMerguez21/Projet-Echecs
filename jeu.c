#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controle_plateau.h"
#include "mvt.h"
#include "partie.h"
#include "fini.h"
#include "save.h"

int main(){
    //ajouter ici la recharge de sauvegarde
    char recharge;
    Piece*** plateau;
    Joueur* J1;
    Joueur* J2;
    printf("Voulez-vous recharger une partie? o ou n\n");
    scanf(" %c",&recharge);
    if(recharge=='o'){
        plateau=ini_plateau_vide();
        J1=malloc(sizeof(Joueur));
        J2=malloc(sizeof(Joueur));
        Couleur actuel;
        char nom_fichier[50];
        printf("Entrez le nom de votre sauvegarde\n");
        scanf("%49s", nom_fichier);
        while(!reload(nom_fichier, plateau, J1, J2, &actuel)){
            printf("Entrez le nom de votre sauvegarde\n");
            scanf("%49s", nom_fichier);
        }
        if(actuel== Blanc) partie(plateau, J1, J2,0);
        else{
            partie(plateau, J1, J2,1);
        }
    }
    else{
        plateau=ini_plateau();
        J1 = init_joueur (Blanc) ;
        J2 = init_joueur (Noir) ;
        duree(J1, J2);
    
        partie(plateau, J1, J2, 0);
    }
        
    free_plateau(plateau);
    free(J1);
    free(J2);
}