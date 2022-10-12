#ifndef LECTURE_FILE
#define LECTURE_FILE
#include <stdio.h>
#include <stdlib.h>

typedef struct Graphe Graphe;
struct Graphe{
    int id_node;
    TabG* fils;
};

typedef struct TabG TabG;
struct TabG{
    Graphe* g;
    TabG* suivant;
};

Graphe creerGraphe(Ruletab e);
Graphe newNode(Ruletab e);

#endif
