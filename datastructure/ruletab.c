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
#include <stdio.h>

#include "ruletab.h"

#include "rule_struct.h"

/* Créer un tableau des rêgles
 * ATTENTION Ne pas oublier de libérer l'espace mémoire avec ruletabfree(ruletab)*/
RuleTab ruletabcreate(int n_max) {
    RuleTab ruletab = {malloc(n_max * sizeof(Rule *)), 0, n_max};
    return ruletab;
}

/* ATTENTION cette fonction ne free pas les regles
 * Il faut les free avnat ! */
void ruletabfree(RuleTab* ruletab) {
    free(ruletab -> tab);
}

/* Ajouter un élément au tableau
 * ATTENTION si le tableau est plein, l'élémént ne sera pas ajouté
 */
Rule* ruletabadd(RuleTab* ruletab, Rule* rule) {
    if (ruletab -> n < ruletab -> n_max) {
        ruletab -> tab[ruletab -> n] = rule;
        rule -> id = ruletab -> n; // Pour que la rêgle conaisse son ID
        ruletab -> n++;
        return rule;
    } else {
        printf("Un élément n'a pas pu être ajouté au tableau car ce dernier est plein :/ !");
        return NULL;
    }
}

/* Ajouter un élément au tableau */
Rule* ruletabaddrealoc(RuleTab* ruletab, Rule* rule) {
    if (ruletab -> n == ruletab -> n_max) {
        ruletab -> tab = realloc(ruletab -> tab, ((ruletab -> n_max) * 2) * sizeof(Rule *));
    }
    return ruletabadd(ruletab, rule);
}

/* Obtenir une rêgle a partir d'un identifiant */
Rule* ruletabget(RuleTab* ruletab, RuleId id) {
    return ruletab -> tab[id];
}
