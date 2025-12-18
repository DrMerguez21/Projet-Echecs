#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controle_plateau.h"
#include "mvt.h"
#include "partie.h"
#include "fini.h"
#include "save_reload.h"

int main(){
    //ajouter ici la recharge de sauvegarde
    Piece*** plateau=ini_plateau();
    Joueur* J1 = init_joueur (Blanc) ;
    Joueur* J2 = init_joueur (Noir) ;
    
    partie_blanc(plateau, J1, J2);
}