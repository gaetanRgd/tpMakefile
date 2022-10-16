#ifndef RULE_FUNCTION_FILE
#define RULE_FUNCTION_FILE

#include "ruletab.h"
#include "chainedlist.h"
#include "rule_struct.h"
#include "radix.h"

typedef struct {
    RuleTab* ruletab;
    Radix* radix;
} RuleManager;

RuleManager* rulemanager_create(int nmax);

void rulemanager_free(RuleManager* rulemanager);

Rule* str_to_rule(RuleManager* rulemanager, char* str);

Rule* create_rule(RuleManager* rulemanager, char* name);

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

void print_rule(Rule* rule);
#endif