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
 *   ////////                                                        |_|   |_|  \___/|_| |_|_|_|\___/     |____|\___/____|____|
*/

#include <stdlib.h>

typedef unsigned int RuleId;

typedef unsigned long long RuleSet;
 
typedef struct {
    int id;
    char* name;
    char** dependencies;
    char** commands;
} Rule;

/* STR to ID == Arbre Radix*/
RuleId str_to_id(char* str) {
    return (RuleId) 0;
}

Rule str_to_Rule(RuleTab ruletab, char* str) {
    return *(ruletab.tab[str_to_id(str)]);
}

/* Créer une rêgle */
Rule create_rule(RuleTab ruletab, char* name, int n_commands, int n_dependencies) {
    ruletab.tab[ruletab.n] = &((Rule) {ruletab.n, name, malloc(n_commands * sizeof(Rule *)), malloc(n_dependencies * sizeof(Rule *))});
    ruletab.n ++;
}

/* y Ajouter des dépendances */
void add_dependencie(RuleTab ruletab, RuleId id, char* dependencie) {
}


/* y Ajouter des commandes */

/* Supprimer une rêgle */

/* Algotithme de Parsing :
 * - Première étape pour attribuer les rêgles, leurs commandes et le nombre de dépendances
 * - Seconde étape pour y ajouter les ids des dépendances */







