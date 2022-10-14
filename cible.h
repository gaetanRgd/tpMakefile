#ifndef CIBLE_FILE
#define CIBLE_FILE


#include "datastructure/ruleset.h"
#include "datastructure/rule_function.h"
#include "datastructure/rule_struct.h"
#include "datastructure/ruletab.h"

void make_naive(char* nom_cible, RuleTab tab);
void make(char* nom_cible, RuleTab tab);

long int getTime(char* fichier);//Permet de connaitre la date de derniere modificatino du fichier lisible

#endif
