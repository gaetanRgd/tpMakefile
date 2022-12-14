#ifndef RULESET_FILE
#define RULESET_FILE

#include "rule_struct.h"

/* Représente un ensemble de RuleId
 * Compexité en mémoire en O(1)
 * Stocke juste un entier */
typedef unsigned long long RuleSet;

RuleSet setcreate(void);

RuleSet setadd(RuleSet set, RuleId id);

RuleSet setdel(RuleSet set, RuleId id);

int setin(RuleSet set, RuleId id);

int seteq(RuleSet set_a, RuleSet set_b);

void setprint(RuleSet set);
#endif