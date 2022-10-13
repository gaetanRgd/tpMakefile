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
 *       ^^^^^^^^/(////((////^ ^^^^         (&&&&&&&&              &&&&&&&&&                               __     _  __   __
 *     .^^^///////////////////                                       |  __ \                              |__ \ / _ \__ \|__ \       
 *     /^///////,..//////^//////^                                    | |__) | __ ___  _ __ ___   ___         ) | | | | ) |  ) |     
 * ////////////#////////    ^^^^^                                    |  ___/ '__/ _ \| '_ ` _ \ / _ \       / /| | | |/ /  / /   
 *  /////((((////////        ^^^^                                    | |   | | | (_) | | | | | | (_) |     / /_| |_| / /_ / /_ 
 *   ////////                                                        |_|   |_|  \___/|_| |_| |_|\___/     |____|\___/____|____|
*/

#include <stdlib.h>

#include "rules.h"

#include "ruletab.h"
#include "chainedlist.h"

/* STR to ID == Arbre Radix*/
RuleId* str_to_id(char* str) {
    return 0;
}

Rule* str_to_Rule(RuleTab* ruletab, char* str) {
    return ruletabget(ruletab, str_to_id(str));
}

/* Créer une rêgle */
Rule* create_rule(RuleTab* ruletab, char* name) {
    Rule* rule = malloc(sizeof(Rule));
    ruletabadd(ruletab, rule);
    *rule -> name = name;
    *rule -> commands = createlist();
    *rule -> requirement = createlist();
    return rule;
}

void free_rule(Rule* rule) {
    free(rule);
}

void free_rule_by_id(RuleTab* ruletab, RuleId id) {
    free_rule(ruletabget(ruletab, id));
}

/* y Ajouter des dépendances */
void add_requirement(RuleTab ruletab, RuleId id, char* req) {

}

/* y Ajouter des commandes */


/* Supprimer une rêgle */

/* Algotithme de Parsing :
 * - Première étape pour attribuer les rêgles, leurs commandes et le nombre de dépendances
 * - Seconde étape pour y ajouter les ids des dépendances */