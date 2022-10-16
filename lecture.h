#ifndef LECTURE_FILE
#define LECTURE_FILE


#include <stdio.h>
#include <stdlib.h>

#include<string.h>


#include "datastructure/ruleset.h"
#include "datastructure/ruletab.h"
#include "datastructure/rule_function.h"
#include "datastructure/rule_struct.h"

RuleManager* lecture(char* fichier);

int testFinFichier(FILE* f);

void remplacer(char* s1, char c2, char c3, int n);

int nbRegles(char* fichier);


#endif
