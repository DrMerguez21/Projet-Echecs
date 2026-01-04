# option de compilation
CC = gcc
CCFLAGS = -Wall
LIBSDIR = 
LDFLAGS =

#fichiers du projet
SRC = jeu.c partie.c fini.c controle_plateau.c mvt.c save.c 
OBJ = $(SRC:. c=.o)
EXEC = jeu

# regle initiale
all: $(EXEC)

#dépendance des .h
jeu.o : partie.h fini.h controle_plateau.h mvt.h save.h
partie.o : partie.h fini.h controle_plateau.h mvt.h save.h 
fini.o : partie.h fini.h controle_plateau.h mvt.h save.h 
controle_plateau.o : partie.h fini.h controle_plateau.h mvt.h save.h 
mvt.o : partie.h fini.h controle_plateau.h mvt.h save.h 
save.o : partie.h fini.h controle_plateau.h mvt.h save.h

#regles de compilation
%.o: %.
	$(CC) $(CCFLAGS) -o $@ -c $<

#regle d'édition de liens
$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LIBSDIR) $(LDFLAGS)

#regle supplémentaires
clean:
	rm -f $(EXEC) *.o
