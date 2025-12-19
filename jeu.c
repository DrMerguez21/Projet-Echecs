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
    printf("Voulez-vous recharger une partie? o ou n\n");
    scanf(" %c",&recharge);
    if(recharge=='n'){
    Piece*** plateau=ini_plateau();
    Joueur* J1 = init_joueur (Blanc) ;
    Joueur* J2 = init_joueur (Noir) ;
    
    partie(plateau, J1, J2, 0);
    }
    else{
        Piece*** plateau=ini_plateau_vide();
        Joueur* J1=malloc(sizeof(Joueur));
        Joueur* J2=malloc(sizeof(Joueur));
        Couleur actuel;
        char nom_fichier[50];
        printf("Entrez le nom de votre sauvegarde, en ajoutant bien .txt à la fin\n");
        scanf("%49s", nom_fichier);
        reload(nom_fichier, plateau, J1, J2, &actuel);
        if(actuel== Blanc) partie(plateau, J1, J2,0);
        else{
            partie(plateau, J1, J2,1);
        }
    }
    free_plateau(plateau);
    free(J1);
    free(J2);
}