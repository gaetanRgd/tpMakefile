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
#include <stdio.h>

#include "ruletab.h"

#include "safemalloc.h"
#include "rule_function.h"
#include "rule_struct.h"

/// @brief Créer un tableau de regle vide
/// @param n_max La taille maximale du tableau
/// @return Le tableau nouvelement crée
/// @exception ATTENTION Ne pas oublier de libérer l'espace mémoire avec ruletabfree(ruletab)
RuleTab ruletabcreate(int n_max) {
    RuleTab ruletab = {safe_malloc(n_max * sizeof(Rule *)), 0, n_max};
    return ruletab;
}


/// @brief libere l'espace réservé pour le tableau
/// @param ruletab le tableau a supprimer
void ruletabfree(RuleTab* ruletab) {
    for (RuleId i = 0; i < ruletab -> n_max; i++) {
        free_rule(ruletab -> tab[i]);
    }
    free(ruletab -> tab);
}

/// @brief Ajoute une rêgle au tableau
/// @param ruletab le tableau
/// @param rule la rêgle a ajouter
/// @return le tableau incrémenté
/// @exception ATTENTION si le tableau est plein, l'élémént ne sera pas ajouté
Rule* ruletabadd(RuleTab* ruletab, Rule* rule) {
    if (ruletab -> n < ruletab -> n_max) {
        ruletab -> tab[ruletab -> n] = rule;
        rule -> id = ruletab -> n; // Pour que la rêgle conaisse son ID
        ruletab -> n++;
        return rule;
    } else {
        perror("Un élément n'a pas pu être ajouté au tableau car ce dernier est plein :/ !");
        return NULL;
    }
}

/// @brief Ajoute une rêgle au tableau sans se soucier de la taille
/// @param ruletab le tableau
/// @param rule la rêgle a ajouter
/// @return le tableau incrémenté
Rule* ruletabaddrealoc(RuleTab* ruletab, Rule* rule) {
    if (ruletab -> n == ruletab -> n_max) {
        ruletab -> tab = safe_realloc(ruletab -> tab, ((ruletab -> n_max) * 2) * sizeof(Rule *));
    }
    return ruletabadd(ruletab, rule);
}

/// @brief Obtenir une rêgle a partir d'un identifiant
/// @param ruletab le tableau stockant les regles
/// @param id l'identifiant de la rêgle étudiée
/// @return Un pointeur vers la rêgle en question
Rule* ruletabget(RuleTab* ruletab, RuleId id) {
    return ruletab -> tab[id];
}
