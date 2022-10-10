#ifndef RULES_FILE
#define RULES_FILE

typedef int RuleId;

typedef unsigned long long RuleSet;

RuleSet setcreate(void);

RuleSet setadd(RuleSet set, RuleId id);

RuleSet setdel(RuleSet set, RuleId id);

int setin(RuleSet set, RuleId id);

int seteq(RuleSet set_a, RuleSet set_b);

void setprint(RuleSet set);

#endif