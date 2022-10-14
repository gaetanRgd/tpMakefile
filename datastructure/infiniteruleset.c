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

#include "infiniteruleset.h"

#include "ruleset.h"
#include "rule_struct.h"

/* TODO Changer la constante 64 de cette partie du code (impropre) */
/* Complexité en O(1) (pour le moment) */ 

/// @brief Création d'un ensemble d'entiers pouvant stocker des nombres de [[0, n_max]]
/// @param n_max l'entier maximum pouvant être stocké
/// @return Un tableau représentant le grand ensemble 
/// @exception ATTENTION Ne pas oublier de libérer l'espace mémoire avec infinitesetfree(set)
InfiniteRuleSet infinitesetcreate(int n_max) {
    return malloc(n_max / 64 * sizeof(RuleSet)); // TODO set à 0 les entiers pointés
}

/// @brief Supprime le grand ensemble en libérant l'espace mémoire associé. Complexité en O(1) 
/// @param set le grand ensemble à supprimer
void infinitesetfree(InfiniteRuleSet set) {
    free(set);
}

/// @brief Ajout d'un entier possible au grand ensemble. Complexité en O(1).
/// @param set le grand ensemble
/// @param id  l'entier à ajouter
/// @return le grand ensemble complété
/// @exception On suppose que l'entier considéré appartient à [[0, n_max]]
InfiniteRuleSet infinitesetadd(InfiniteRuleSet set, RuleId id) {
    set[id / 64] = setadd(set[id / 64], id % 64);
    return set;
}

/// @brief Suppression d'un entier du grand ensemble. Complexité en O(1)
/// @param set le grand ensemble considéré
/// @param id l'entier à retirer du grand ensemble
/// @return le grand ensemble tronqué
/// @exception On suppose que l'entier considéré appartient à [[0, n_max]]
InfiniteRuleSet infinitesetdel(InfiniteRuleSet set, RuleId id) {
    set[id / 64] = setdel(set[id / 64], id % 64);
    return set;
}

/// @brief Test d'appartenance d'un entier au grand ensemble. Complexité en O(1).
/// @param set le grand ensemble considéré
/// @param id l'entier condidéré
/// @return 1 si l'entier est dans le grand ensemble et 0 sinon
/// @exception On suppose que l'entier considéré appartient à [[0, n_max]]
int infinitesetin(InfiniteRuleSet set, RuleId id) {
    return setin(set[id / 64], id % 64);
}