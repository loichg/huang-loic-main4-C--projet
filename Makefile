# Variables
CC = g++                  # Le compilateur à utiliser
CCFLAGS = -Wall -Werror -std=c++11 -g  # Options de compilation (C++11, avertissements, et débogage)
SRC = $(wildcard ../*.cc)  # Tous les fichiers .cc dans le répertoire parent
OBJ = $(SRC:.cc=.o)        # Conversion des fichiers .cc en fichiers .o
TST = $(wildcard *.cc)     # Tous les fichiers .cc dans le répertoire actuel (pour les tests)
OBJ_TEST = $(filter-out ../main.o, $(OBJ)) $(TST:.cc=.o) # Fichiers objets pour les tests

# Nom de l'exécutable
EXEC = testcase.out

# Cible par défaut : créer l'exécutable
all: $(EXEC)

# Lier les objets pour créer l'exécutable
$(EXEC): $(OBJ_TEST)
	$(CC) $(CCFLAGS) -o $@ $^

# Règle pour compiler les fichiers .cpp en .o (fichiers source)
%.o: %.cpp
	$(CC) $(CCFLAGS) -I../ -o $@ -c $<

# Règle pour compiler les fichiers .cc en .o (fichiers tests)
%.o: %.cc
	$(CC) $(CCFLAGS) -I../ -o $@ -c $<

# Nettoyer les fichiers générés (objets et exécutable)
clean:
	rm -f $(OBJ_TEST) $(EXEC)

# Cible pour générer les dépendances
.depends:
	$(CC) -MM $(SRC) > .depends

# Inclure le fichier .depends pour gérer les dépendances
-include .depends

.PHONY: all clean
