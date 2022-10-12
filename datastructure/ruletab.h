#ifndef RULETAB_FILE
#define RULETAB_FILE

#include "rules.h"

typedef struct {
    Rule** tab;
    int n;
    int n_max;
} RuleTab;

RuleTab ruletabcreate(int n_max);

void ruletabfree(RuleTab* ruletab);

RuleId ruletabadd(RuleTab* ruletab, Rule* rule);

RuleId ruletabaddrealoc(RuleTab* ruletab, Rule* rule);

Rule* ruletabget(RuleTab* ruletab, RuleId id);
#endif
