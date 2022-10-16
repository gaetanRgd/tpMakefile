#ifndef GRAPHE_FILE
#define GRAPHE_FILE
#include <stdio.h>
#include <stdlib.h>

#include "datastructure/ruletab.h"

typedef struct Graphe Graphe;
struct Graphe{
    int id_node;
    //TabG* fils;
};

Graphe creerGraphe(RuleTab e);

#endif
