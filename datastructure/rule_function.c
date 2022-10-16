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
#include <stdio.h>

#include "rule_struct.h"

#include "safemalloc.h"
#include "ruletab.h"
#include "chainedlist.h"

/// @brief Renvoie une regle a partir de son nom
/// @param ruletab le talbeau des rêgles
/// @param name le nom de la regle
/// @return Un pointeur vers la regle associée
Rule* str_to_rule(RuleTab* ruletab, char* name) {
    for (RuleId id = 0; id < ruletab -> n; id++) {
        printf("{%s == %s}\n", ruletabget(ruletab, id) -> name, name);
        if (!strcmp(ruletabget(ruletab, id) -> name, name)) {
            return ruletabget(ruletab, id);
        }
    }
    return NULL;
}

/// @brief Crée une rêgle sans dépendence ou commande
/// @param ruletab un pointeur vers le tableau des rêgles
/// @param name le nom de la regle
/// @return Un pointeur vers la regle
/// @exception ATTENTION ne pas oublier de libérer l'espace mémoire avec free_rule(rule)
Rule* create_rule(RuleTab* ruletab, char* name) {
    Rule* rule = safe_malloc(sizeof(Rule));
    ruletabadd(ruletab, rule);
    rule -> name = safe_malloc(strlen(name) + 1);
    strcpy(rule -> name, name);
    rule -> commands = createlist();
    rule -> requirement = createlist();
    return rule;
}

/// @brief Libère l'espace mémoire bloqué par la regle
/// @param rule un pointeur vers la regle a supprimer
void free_rule(Rule* rule) {
    freelinkedlist(&(rule -> commands));
    freelinkedlist(&(rule -> requirement));
    free(rule -> name);
    free(rule);
}


/// @brief Libère l'espace mémoire bloqué par la regle
/// @param ruletab un pointeur vers le tableau des rêgles
/// @param id l'identifiant de la regle a supprimer
void free_rule_by_id(RuleTab* ruletab, RuleId id) {
    free_rule(ruletabget(ruletab, id));
}

/// @brief Ajout d'une dépendance à la rêgle
/// @param rule un pointeur vers rêgle a modifier
/// @param req le nom de la prémice nécessaire
void add_requirement(Rule* rule, char* req) {
    append(&(rule -> requirement), req);
}

/// @brief Ajout d'une dépendance à la rêgle
/// @param ruletab un pointeur vers le tableau des rêgles
/// @param id l'identifiant de la regle a supprimer
/// @param req le nom de la prémice nécessaire
void add_requirement_by_id(RuleTab* ruletab, RuleId id, char* req) {
    add_requirement(ruletabget(ruletab, id), req);
}

/// @brief Associe a une regle sa liste des prémices
/// @param rule un pointeur vers rêgle a modifier
/// @return la liste des prémices
List* get_requirement_list(Rule* rule) {
    return rule -> requirement.head;
}

/// @brief Associe a une regle sa liste des prémices
/// @param ruletab un pointeur vers le tableau des rêgles
/// @param id l'identifiant de la regle
/// @return la liste des prémices
List* get_requirement_list_by_id(RuleTab* ruletab, RuleId id) {
    return get_requirement_list(ruletabget(ruletab, id));
}

/// @brief Ajoute une prémice à la regle
/// @param rule un pointeur vers rêgle a modifier
/// @param cmd la commande a ajouter
void add_command(Rule* rule, char* cmd) {
    append(&(rule -> commands), cmd);
}


/// @brief Ajoute une prémice a la regle
/// @param ruletab un pointeur vers le tableau des rêgles
/// @param id l'identifiant de la regle
/// @param cmd la commande a ajouter
void add_command_by_id(RuleTab* ruletab, RuleId id, char* cmd) {
    add_requirement(ruletabget(ruletab, id), cmd);
}

/// @brief Associe a une regle sa liste des commandes
/// @param rule un pointeur vers rêgle a modifier
/// @return la liste des commandes
List* get_command_list(Rule* rule) {
    return rule -> commands.head;
}

/// @brief Associe a une regle sa liste des commandes
/// @param ruletab un pointeur vers le tableau des rêgles
/// @param id l'identifiant de la regle
/// @return la liste des commandes
List* get_command_list_by_id(RuleTab* ruletab, RuleId id) {
    return get_command_list(ruletabget(ruletab, id));
}

/// @brief Afficher une regle 
/// @param rule un pointeur vers la regle a afficher
void print_rule(Rule* rule) {
    printf("\n{\nid=%d\nname=%s\ndependencies=", rule -> id, rule -> name);
    print_list(rule -> requirement);
    printf("\ncommands=");
    print_list(rule -> commands);
    printf("\n}\n");
}