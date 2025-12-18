#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controle_plateau.h"
#include "mvt.h"
#include "fini.h"
#include "save_reload.h"
#include "partie.h"

void partie_blanc(Piece*** plateau, Joueur* J1, Joueur* J2){ // si le premier joueur a joué est le blanc
    printf("les pièces noires sont en haut, les blanches en bas (les couleurs semblent inversées si on est en affichage sombre), les x correspondent aux lignes et les y aux colonnes\n");
    printf("Si vous voulez sauvegarder, entrez z9 z9 à la place des coordonnées de votre mouvement\n");
    affiche_plateau(plateau);
    while(fini(J1, J2)==0){
        char yd, yf;
        int xd, xf;
        int xdebut, ydebut, xfin, yfin;
        double p ;
        clock_t start, end ;

        printf("Au tour des blancs\n");
        start = clock () ;
        //debut du décompte pour le joueur blanc
        printf("Entrez les coordonnées de la pièce que vous voulez déplacer, puis celles de la case où vous voulez aller, séparées par un espace\n");
        scanf(" %c %d %c %d",&yd, &xd, &yf, &xf);
        if((yd=='z')&&(xd==9)&&(yf=='z')&&(xf==9)){
            char nom_fichier[50];
            printf("Entrez le nom dans lequel vous voulez faire la sauvegarde, en précisant .txt\n");
            scanf("%49s", nom_fichier);
            save(nom_fichier, plateau, J1, J2, Blanc);
            return;
        }
        xdebut=convert_x(xd);
        ydebut=convert_y(yd);
        xfin=convert_x(xf);
        yfin=convert_y(yf);
        while(mouvement(1,plateau, xdebut, ydebut, xfin, yfin)==0){
            printf("Entrez les coordonnées de la pièce que vous voulez déplacer, puis celles de la case où vous voulez aller, séparées par un espace\n");
            scanf(" %c %d %c %d",&yd, &xd, &yf, &xf);
            if((yd=='z')&&(xd==9)&&(yf=='z')&&(xf==9)){
                char nom_fichier[50];
                printf("Entrez le nom dans lequel vous voulez faire la sauvegarde, en précisant .txt\n");
                scanf("%49s", nom_fichier);
                save(nom_fichier, plateau, J1, J2, Blanc);
                return;
            }
            xdebut=convert_x(xd);
            ydebut=convert_y(yd);
            xfin=convert_x(xf);
            yfin=convert_y(yf);
        } int mouv_spe=mouvement(0,plateau, xdebut, ydebut, xfin, yfin);
        if(mouv_spe==2){ //petit roque
            deplacement(J1, plateau, xdebut, 7, xdebut, 5); //deplacement de la tour de droite    
        }
        if (mouv_spe==3){ //grand roque
            deplacement(J1, plateau, xdebut, 0, xdebut, 3); //deplacement de la tour de gauche
        }
        deplacement (J1, plateau, xdebut, ydebut, xfin, yfin) ;
        //fin du décompte pour le joueur blanc
        end = clock () ;
        p = (double) (end - start) / CLOCKS_PER_SEC ;
        J1 -> temps -= p ;
        printf ("Il vous reste %d secondes\n", J1 -> temps) ;
        affiche_plateau(plateau);
        if (fini(J1, J2) != 0) break ;

        printf("Au tour des noirs\n");
        start = clock () ;
        //debut du décompte pour le joueur noir
        printf("Entrez les coordonnées de la pièce que vous voulez déplacer, puis celles de la case où vous voulez aller, séparées par un espace\n");
        scanf(" %c %d %c %d",&yd, &xd, &yf, &xf);
            if((yd=='z')&&(xd==9)&&(yf=='z')&&(xf==9)){
                char nom_fichier[50];
                printf("Entrez le nom dans lequel vous voulez faire la sauvegarde, en précisant .txt\n");
                scanf("%49s", nom_fichier);
                save(nom_fichier, plateau, J1, J2, Noir);
                return;
            }
        xdebut=convert_x(xd);
        ydebut=convert_y(yd);
        xfin=convert_x(xf);
        yfin=convert_y(yf);
        while(mouvement(1,plateau, xdebut, ydebut, xfin, yfin)==0){
            printf("Entrez les coordonnées de la pièce que vous voulez déplacer, puis celles de la case où vous voulez aller, séparées par un espace\n");
            scanf(" %c %d %c %d",&yd, &xd, &yf, &xf);
            if((yd=='z')&&(xd==9)&&(yf=='z')&&(xf==9)){
                char nom_fichier[50];
                printf("Entrez le nom dans lequel vous voulez faire la sauvegarde, en précisant .txt\n");
                scanf("%49s", nom_fichier);
                save(nom_fichier, plateau, J1, J2, Noir);
                return;
            }
            xdebut=convert_x(xd);
            ydebut=convert_y(yd);
            xfin=convert_x(xf);
            yfin=convert_y(yf);
        } mouv_spe=mouvement(0,plateau, xdebut, ydebut, xfin, yfin);
        if(mouv_spe==2){ //petit roque
            deplacement(J2, plateau, xdebut, 7, xdebut, 5); //deplacement de la tour de droite    
        }
        if (mouv_spe==3){ //grand roque
            deplacement(J2, plateau, xdebut, 0, xdebut, 3); //deplacement de la tour de gauche
        } 
        deplacement (J2, plateau, xdebut, ydebut, xfin, yfin) ;
        //fin du décompte pour le joueur noir
        end = clock () ;
        p = (double) (end - start) / CLOCKS_PER_SEC ;
        J2 -> temps -= p ;
        printf ("Il vous reste %d secondes\n", J2 -> temps) ;
        affiche_plateau(plateau);
    }

    if (fini(J1, J2) == 1) printf ("Le Joueur 1 a gagné\n") ;
    if (fini(J1, J2) == 2) printf ("Le Joueur 2 a gagné\n") ;
}

void partie_noir(Piece*** plateau, Joueur* J1, Joueur* J2){ // si le premier joueur a jouer est le noir
    printf("les pièces noires sont en haut, les blanches en bas (les couleurs semblent inversées si on est en affichage sombre), les x correspondent aux lignes et les y aux colonnes\n");
    affiche_plateau(plateau);
    while(fini(J1, J2)==0){
        char yd, yf;
        int xd, xf;
        int xdebut, ydebut, xfin, yfin;
        double p ;
        clock_t start, end ;

        printf("Au tour des noirs\n");
        start = clock () ;
        //debut du décompte pour le joueur blanc
        printf("Entrez les coordonnées de la pièce que vous voulez déplacer, puis celles de la case où vous voulez aller, séparées par un espace\n");
        scanf(" %c %d %c %d",&yd, &xd, &yf, &xf);
        xdebut=convert_x(xd);
        ydebut=convert_y(yd);
        xfin=convert_x(xf);
        yfin=convert_y(yf);
        while(mouvement(1,plateau, xdebut, ydebut, xfin, yfin)==0){
            printf("Entrez les coordonnées de la pièce que vous voulez déplacer, puis celles de la case où vous voulez aller, séparées par un espace\n");
            scanf(" %c %d %c %d",&yd, &xd, &yf, &xf);
            xdebut=convert_x(xd);
            ydebut=convert_y(yd);
            xfin=convert_x(xf);
            yfin=convert_y(yf);
        } int mouv_spe=mouvement(0,plateau, xdebut, ydebut, xfin, yfin);
        if(mouv_spe==2){ //petit roque
            deplacement(J2, plateau, xdebut, 7, xdebut, 5); //deplacement de la tour de droite    
        }
        if (mouv_spe==3){ //grand roque
            deplacement(J2, plateau, xdebut, 0, xdebut, 3); //deplacement de la tour de gauche
        }
        deplacement (J2, plateau, xdebut, ydebut, xfin, yfin) ;
        //fin du décompte pour le joueur blanc
        end = clock () ;
        p = (double) (end - start) / CLOCKS_PER_SEC ;
        J1 -> temps -= p ;
        printf ("Il vous reste %d secondes\n", J2 -> temps) ;
        affiche_plateau(plateau);
        if (fini(J1, J2) != 0) break ;

        printf("Au tour des blancs\n");
        start = clock () ;
        //debut du décompte pour le joueur noir
        printf("Entrez les coordonnées de la pièce que vous voulez déplacer, puis celles de la case où vous voulez aller, séparées par un espace\n");
        scanf(" %c %d %c %d",&yd, &xd, &yf, &xf);
        xdebut=convert_x(xd);
        ydebut=convert_y(yd);
        xfin=convert_x(xf);
        yfin=convert_y(yf);
        while(mouvement(1,plateau, xdebut, ydebut, xfin, yfin)==0){
            printf("Entrez les coordonnées de la pièce que vous voulez déplacer, puis celles de la case où vous voulez aller, séparées par un espace\n");
            scanf(" %c %d %c %d",&yd, &xd, &yf, &xf);
            xdebut=convert_x(xd);
            ydebut=convert_y(yd);
            xfin=convert_x(xf);
            yfin=convert_y(yf);
        } mouv_spe=mouvement(0,plateau, xdebut, ydebut, xfin, yfin);
        if(mouv_spe==2){ //petit roque
            deplacement(J1, plateau, xdebut, 7, xdebut, 5); //deplacement de la tour de droite    
        }
        if (mouv_spe==3){ //grand roque
            deplacement(J1, plateau, xdebut, 0, xdebut, 3); //deplacement de la tour de gauche
        } 
        deplacement (J1, plateau, xdebut, ydebut, xfin, yfin) ;
        //fin du décompte pour le joueur noir
        end = clock () ;
        p = (double) (end - start) / CLOCKS_PER_SEC ;
        J2 -> temps -= p ;
        printf ("Il vous reste %d secondes\n", J1 -> temps) ;
        affiche_plateau(plateau);
    }

    if (fini(J1, J2) == 1) printf ("Le Joueur 1 a gagné\n") ;
    if (fini(J1, J2) == 2) printf ("Le Joueur 2 a gagné\n") ;
}