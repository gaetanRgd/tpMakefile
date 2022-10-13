#ifndef RULES_FILE
#define RULES_FILE

typedef int RuleId;

typedef struct {
    RuleId id;
    char* name;
    ListHead requirement; // LISTE CHAINEE EN FAIT 
    ListHead commands;
} Rule;

#endif