/*
 *             ///((/////                   *&&&&&&&&              %&&&&&&&&    
 *          //(/////((//////              /&&&     *&&&          &&&&     %&&&  
 *        /(//^     ^//(//(///            &&&                   #&&             
 *      ///^,        //////////           &&&                    &&&            
 *               //////////(///            &&&&&&         *%&(    &&&&&&%       
 *             //////(///////////          &&&&&&      &&&&&&&&&&%   *&&&&&&&   
 *             ^^^////////(//^////        &&&        %&&#       &&&        &&&* 
 *             ^^^/(/////////^////        &&&        &&&        #&&         &&% 
 *          ^^^  ////////(////^^^^        (&&&     *&&&          &&&%     #&&&  
 *       ^^^^^^^^/(////((////^ ^^^^         (&&&&&&&&      ____    &&&&&&&&                     __     _  __   __
 *     .^^^///////////////////                            |  __ \                              |__ \ / _ \__ \|__ \       
 *     /^///////,..//////^//////^                         | |__) | __ ___  _ __ ___   ___         ) | | | | ) |  ) |     
 * ////////////#////////    ^^^^^                         |  ___/ '__/ _ \| '_ ` _ \ / _ \       / /| | | |/ /  / /   
 *  /////((((////////        ^^^^                         | |   | | | (_) | | | | | | (_) |     / /_| |_| / /_ / /_ 
 *   ////////                                             |_|   |_|  \___/|_| |_| |_|\___/     |____|\___/____|____|
*/

#include <stdlib.h>
#include <string.h>

#include "rule_struct.h"

#include "ruletab.h"
#include "chainedlist.h"

/* STR to ID == Arbre Radix*/
Rule* str_to_Rule(RuleTab* ruletab, char* str) {
    for (RuleId i = 0; i < ruletab -> n_max; i++) {
        if (strcmp(ruletab -> tab[i] -> name, str)) {
            return ruletab -> tab[i];
        }
    }
    return NULL;
}

/* Créer une rêgle */
Rule* create_rule(RuleTab* ruletab, char* name) {
    Rule* rule = malloc(sizeof(Rule));
    ruletabadd(ruletab, rule);
    rule -> name = name;
    rule -> commands = createlist();
    rule -> requirement = createlist();
    return rule;
}

void free_rule(Rule* rule) {
    free(rule);
}

void free_rule_by_id(RuleTab* ruletab, RuleId id) {
    free_rule(ruletabget(ruletab, id));
}

void add_requirement(Rule* rule, char* req) {
    append(&(rule -> requirement), req);
}

/* y Ajouter des dépendances */
void add_requirement_by_id(RuleTab* ruletab, RuleId id, char* req) {
    add_requirement(ruletabget(ruletab, id), req);
}

List* get_requirement_list(Rule* rule) {
    return rule -> requirement.head;
}

List* get_requirement_list_by_id(RuleTab* ruletab, RuleId id) {
    return get_requirement_list(ruletabget(ruletab, id));
}

void add_command(Rule* rule, char* cmd) {
    append(&(rule -> commands), cmd);
}

/* y Ajouter des dépendances */
void add_command_by_id(RuleTab* ruletab, RuleId id, char* cmd) {
    add_requirement(ruletabget(ruletab, id), cmd);
}

List* get_command_list(Rule* rule) {
    return rule -> commands.head;
}

List* get_command_list_by_id(RuleTab* ruletab, RuleId id) {
    return get_command_list(ruletabget(ruletab, id));
}

/* y Ajouter des commandes */


/* Supprimer une rêgle */

/* Algotithme de Parsing :
 * - Première étape pour attribuer les rêgles, leurs commandes et le nombre de dépendances
 * - Seconde étape pour y ajouter les ids des dépendances */