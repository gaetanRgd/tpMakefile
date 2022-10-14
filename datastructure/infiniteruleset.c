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
/// @return Un tableau représentant l'ensemble 
/// @exception ATTENTION Ne pas oublier de libérer l'espace mémoire avec infinitesetfree(set)
InfiniteRuleSet infinitesetcreate(int n_max) {
    return malloc(n_max / 64 * sizeof(RuleSet)); // TODO set à 0 les entiers pointés
}

/// @brief Supprime l'ensemble en libérant l'espace mémoire associé. Complexité en O(1) 
/// @param set l'ensemble à supprimer
void infinitesetfree(InfiniteRuleSet set) {
    free(set);
}

/// @brief Ajout d'un entier possible à l'ensemble. Complexité en O(1).
/// @param set l'ensemble
/// @param id  l'entier à ajouter
/// @return l'ensemble complété
/// @exception On suppose que l'entier considéré appartient à [[0, n_max]]
InfiniteRuleSet infinitesetadd(InfiniteRuleSet set, RuleId id) {
    set[id / 64] = setadd(set[id / 64], id % 64);
    return set;
}

/// @brief Suppression d'un entier de l'ensemble. Complexité en O(1)
/// @param set l'ensemble considéré
/// @param id l'entier à retirer de l'ensemble
/// @return l'ensemble tronqué
/// @exception On suppose que l'entier considéré appartient à [[0, n_max]]
InfiniteRuleSet infinitesetdel(InfiniteRuleSet set, RuleId id) {
    set[id / 64] = setdel(set[id / 64], id % 64);
    return set;
}

/// @brief Test d'appartenance d'un entier à l'ensemble. Complexité en O(1).
/// @param set l'ensemble considéré
/// @param id l'entier condidéré
/// @return 1 si l'entier est dans l'ensemble et 0 sinon
/// @exception On suppose que l'entier considéré appartient à [[0, n_max]]
int infinitesetin(InfiniteRuleSet set, RuleId id) {
    return setin(set[id / 64], id % 64);
}