#ifndef CIBLE_FILE
#define CIBLE_FILE

#include "ruleset.h"
#include "rules.h"

void make_naive(char* nom_cible, Ensemble e);
void make(char* nom_cible, Ensemble e);

long int getTime(char* fichier);//Permet de connaitre la date de derniere modificatino du fichier lisible

#endif
