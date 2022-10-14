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

#include <math.h>
#include <stdio.h>

#include "ruleset.h"
#include "rule_struct.h"

/// @brief Créer un ensemble vide pouvant strocker des entiers de [[0, 63]]. Complexité en O(1)
/// @return Retourne l'ensemble vide.
RuleSet setcreate(void) {
    return 0; 
}

/// @brief Ajoute un élément à l'ensemble. Complexité en O(1).
/// @param set l'ensemble condidéré
/// @param id l'élément à ajouter à l'ensemble
/// @return L'ensemble complété
RuleSet setadd(RuleSet set, RuleId id) {
    return set | (RuleSet) pow(2, id);
}


/// @brief Supprime un entier à l'ensemble. Complexité en O(1).
/// @param set l'ensemble considéré
/// @param id l'élément à retirer
/// @return L'ensemble tronqué
RuleSet setdel(RuleSet set, RuleId id) {
    return set ^ (RuleSet) pow(2, id);
}

/// @brief Vérifie l'appartenance d'un élément à l'ensemble. Compelxité en O(1).
/// @param set L'ensemble considéré
/// @param id L'élément considéré
/// @return 1 si l'élément est dans l'ensemble 0 sinon.
int setin(RuleSet set, RuleId id) {
    return  0 != (set & (RuleSet) pow(2, id));
}

/// @brief Vérifie l'égalité de deux ensembles. Complexité en O(1).
/// @param set_a le premier ensemble
/// @param set_b le second ensemble
/// @return 1 si les ensembles sont égaux et 0 sinon
int seteq(RuleSet set_a, RuleSet set_b) {
    return set_a == set_b;
}

/// @brief Affiche un ensemble. Complexité en O(1).
/// @param set L'ensemble considéré
void setprint(RuleSet set) {
    printf("%lld\n", set);
}