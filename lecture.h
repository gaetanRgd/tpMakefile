#ifndef LECTURE_FILE
#define LECTURE_FILE

#include "lecture.h"
#include "ruleset.h"
#include "rules.h"

Ruletab lecture(char* fichier);
int testFinFichier(FILE* f);
void remplacer(char* s1, char c2, char c3, int n);


#endif
