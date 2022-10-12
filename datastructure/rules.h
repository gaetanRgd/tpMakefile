#ifndef RULES_FILE
#define RULES_FILE

typedef int RuleId;

typedef struct {
    RuleId id;
    char* name;
    char** requirement; // LISTE CHAINEE EN FAIT 
    char** commands;
} Rule;

#endif