#ifndef LECTURE_FILE
#define LECTURE_FILE
#include <stdio.h>
#include <stdlib.h>

typedef struct Graphe Graphe;
struct Graphe{
    int id_node;
    TabG* fils;
};

Graphe creerGraphe(Ruletab e);

#endif
