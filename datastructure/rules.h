#ifndef RULES_FILE
#define RULES_FILE

typedef int RuleId;

typedef struct {
    RuleId id;
    char* name;
    char** dependencies;
    char** commands;
} Rule;

#endif