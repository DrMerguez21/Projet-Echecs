#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controle_plateau.h"
#include "mvt.h"

int fini (Joueur* J1, Joueur* J2) {
    if (J1 -> Points >= 99) return (1) ;
    if (J2 -> points >= 99) return (2) ;
    return (0) ;
}


