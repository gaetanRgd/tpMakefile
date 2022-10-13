#ifndef RULETAB_FILE
#define RULETAB_FILE

#include "rule_struct.h"

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
