#ifndef RULE_STRUCT_FILE
#define RULE_STRUCT_FILE

#include "chainedlist.h"

/// @brief Un entier qui représente l'identifiant d'une rêgle
typedef int RuleId;

/// @brief Une regle dans le makefile
/// @param id l'identifiant de la regle
/// @param name le nom de cette regle
/// @param requirement une liste chainée des dépendance
/// @param commands une liste chainée des commandes
/// @exception ATTENTION ne pas oublier de free cette liste avec free_rule(rule)
typedef struct {
    RuleId id;
    char* name;
    ListHead requirement;
    ListHead commands;
} Rule;

#endif