#ifndef LECT_FILE
#define LECT_FILE


#include <stdio.h>
#include <stdlib.h>

#include<string.h>


#include "datastructure/ruleset.h"
#include "datastructure/ruletab.h"
#include "datastructure/rule_function.h"
#include "datastructure/rule_struct.h"

RuleTab lecture(char* fichier);
int testFinFichier(FILE* f);
void remplacer(char* s1, char c2, char c3, int n);
int nbRegles(char* fichier);

char* parcourir(char* commande, char* pre, char* nom);


#endif
