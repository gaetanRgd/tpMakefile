#ifndef CIBLE_FILE
#define CIBLE_FILE

#include "datastructure/ruleset.h"
#include "datastructure/rules.h"

void make_naive(char* nom_cible, RuleTab e);
void make(char* nom_cible, RuleTab e);

long int getTime(char* fichier);//Permet de connaitre la date de derniere modificatino du fichier lisible

#endif
