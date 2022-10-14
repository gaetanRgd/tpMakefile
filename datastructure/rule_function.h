#ifndef RULE_FUNCTION_FILE
#define RULE_FUNCTION_FILE

#include "ruletab.h"
#include "chainedlist.h"
#include "rule_struct.h"


Rule* str_to_rule(RuleTab* ruletab, char* str);

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

void print_rule(Rule* rule);
#endif