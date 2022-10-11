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
struct Graphe{
    Graphe* g;
    Graphe* suivant;
};

Graphe newNode(int id);

#endif
