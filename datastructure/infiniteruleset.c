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

#include "infiniteruleset.h"

#include "ruleset.h"
#include "rules.h"

/* TODO Changer la constante 64 de cette partie du code (impropre) */

/* Création d'un ensemble d'entiers pouvant stocker des nombres de [[0, n]]
 * ATTENTION Ne pas oublier de libérer l'espace mémoire avec infinitesetfree(set)
 * Complexité en O(1) (pour le moment) */ 
InfiniteRuleSet infinitesetcreate(int n) {
    return malloc(n / 64 * sizeof(RuleSet)); // TODO set à 0 les entiers pointés
}

/* Supprime l'ensemble fourni en libérant l'espace mémoire associé
 * Complexité en O(1) */
void infinitesetfree(InfiniteRuleSet set) {
    free(set);
}

/* Ajout d'un entier appartenant à l'ensemble
 * Complexité en O(1) */
InfiniteRuleSet infinitesetadd(InfiniteRuleSet set, RuleId id) {
    set[id / 64] = setadd(set[id / 64], id % 64);
}

/* Suppression d'un entier 
 * Complexité en O(1) */
InfiniteRuleSet infinitesetdel(InfiniteRuleSet set, RuleId id) {
    set[id / 64] = setdel(set[id / 64], id % 64);
}

/* Test d'appartenance à l'ensemble 
 * Complexité en O(1) */
int infinitesetin(InfiniteRuleSet set, RuleId id) {
    return setin(set[id / 64], id % 64);
}

/* Test d'équivalence d'ensemble 
 * complexité en o(n/64) */
int infiniteseteq(InfiniteRuleSet set_a, InfiniteRuleSet set_b) {
    return 0;
}

/* TODO Créer une fonction iter ? */
