#ifndef INFINITERULESET_FILE
#define INFINITERULESET_FILE

#include "rules.h"
#include "ruleset.h"

typedef RuleSet* InfiniteRuleSet;

InfiniteRuleSet infinitesetcreate(int n);

void infinitesetfree(InfiniteRuleSet set);

InfiniteRuleSet infinitesetadd(InfiniteRuleSet set, RuleId id);

InfiniteRuleSet infinitesetdel(InfiniteRuleSet set, RuleId id);

int infinitesetin(InfiniteRuleSet set, RuleId id);

#endif