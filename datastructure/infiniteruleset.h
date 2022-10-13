#ifndef INFINITERULESET_FILE
#define INFINITERULESET_FILE

#include "rules.h"
#include "ruleset.h"

// Type grand ensemble

/* Représente un ensemble de RuleId
 * Complexité en espace en O(n)
 * ATTENTION Ne pas oublier de libérer l'espace mémoire avec infinitesetfree(set)
 * Stocke un bit par entier possible dans l'ensemble */
typedef RuleSet* InfiniteRuleSet;

// Fonctions sur les grands ensembles

InfiniteRuleSet infinitesetcreate(int n_max);

void infinitesetfree(InfiniteRuleSet set);

InfiniteRuleSet infinitesetadd(InfiniteRuleSet set, RuleId id);

InfiniteRuleSet infinitesetdel(InfiniteRuleSet set, RuleId id);

int infinitesetin(InfiniteRuleSet set, RuleId id);

#endif