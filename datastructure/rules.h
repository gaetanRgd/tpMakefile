#ifndef RULES_FILE
#define RULES_FILE

typedef int RuleId;

typedef struct {
    RuleId id;
    char* name;
    ListHead requirement; // LISTE CHAINEE EN FAIT 
    ListHead commands;
} Rule;

RuleId* str_to_id(RuleTab* ruletab, char* str);

Rule* str_to_Rule(RuleTab* ruletab, char* str);

Rule* create_rule(RuleTab* ruletab, char* name);

void free_rule(Rule* rule);

void free_rule_by_id(RuleTab* ruletab, RuleId id);

void add_requirement(Rule* rule, char* req);

void add_requirement_by_id(RuleTab* ruletab, RuleId id, char* req);

List* get_requirement_list(Rule* rule);

List* get_requirement_list_by_id(RuleTab* ruletab, RuleId id);

void add_command(Rule* rule, char* cmd);

void add_command_by_id(RuleTab* ruletab, RuleId id, char* cmd);

List* get_command_list(Rule* rule);

List* get_command_list_by_id(RuleTab* ruletab, RuleId id);
#endif