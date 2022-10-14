#ifndef RULETAB_FILE
#define RULETAB_FILE

#include "rule_struct.h"

/// @brief Cette structure représente un tableau de rêgles
/// @param tab est le tableau de pointeurs vers les regles
/// @param n vaut le nombre de regles dans le tableau
/// @param n_max est la taille maximale de tab
/// @exception ATTENTION Ne pas oublier de libérer l'espace mémoire avec ruletabfree(ruletab)
typedef struct {
    Rule** tab;
    int n;
    int n_max;
} RuleTab;

RuleTab ruletabcreate(int n_max);

void ruletabfree(RuleTab* ruletab);

Rule* ruletabadd(RuleTab* ruletab, Rule* rule);

Rule* ruletabaddrealoc(RuleTab* ruletab, Rule* rule);

Rule* ruletabget(RuleTab* ruletab, RuleId id);
#endif
