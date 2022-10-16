#ifndef RULETAB_FILE
#define RULETAB_FILE

#include "rule_struct.h"
#include "buffer.h"

/// @brief Cette structure représente un tableau de pointeurs vers des rêgles
/// @exception ATTENTION Ne pas oublier de libérer l'espace mémoire avec ruletabfree(ruletab)
typedef Buffer RuleTab;

RuleTab ruletabcreate(int n_max);

void ruletabfree(RuleTab* ruletab);

Rule* ruletabadd(RuleTab* ruletab, Rule* rule);

Rule* ruletabaddrealoc(RuleTab* ruletab, Rule* rule);

Rule* ruletabget(RuleTab* ruletab, RuleId id);
#endif
