#ifndef CIBLE_FILE
#define CIBLE_FILE


#include "datastructure/rule_function.h"
#include "datastructure/rule_struct.h"

void make_naive(char* nom_cible, RuleManager* rulemanager);
void make(char* nom_cible, RuleManager* rulemanager);

long int getTime(char* fichier);//Permet de connaitre la date de derniere modificatino du fichier lisible

#endif
