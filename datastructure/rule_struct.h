#ifndef RULE_STRUCT_FILE
#define RULE_STRUCT_FILE

#include "chainedlist.h"

typedef int RuleId;

typedef struct {
    RuleId id;
    char* name;
    ListHead requirement; // LISTE CHAINEE EN FAIT 
    ListHead commands;
} Rule;

#endif