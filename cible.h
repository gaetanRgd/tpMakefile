#ifndef CIBLE_FILE
#define CIBLE_FILE

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "ensemble.h"
#include "regles.h"


void make_naive(char* nom_cible, Ensemble e);
void make(char* nom_cible, Ensemble e);

long int getTime(char* fichier);//Permet de connaitre la date de derniere modificatino du fichier lisible

#endif
