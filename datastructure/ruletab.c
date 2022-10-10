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

#include "radixlist.c"
#include "rules.c"

typedef struct {
    Rule** tab;
    int n;
    int n_max;
} RuleTab;

/* Créer un tableau des rêgles */
RuleTab ruletabcreate(int n_max) {
    RuleTab ruletab = {malloc(n_max * sizeof(Rule *)), 0, n_max};
    return ruletab;
}

/* Ajouter un élément au tableau
 * ATTENTION si le tableau est plein, l'élémént ne sera pas ajouté
 */
void ruletabadd(RuleTab* ruletab, Rule* rule) {
    if (ruletab -> n < ruletab -> n_max) {
        ruletab -> tab[ruletab -> n] = rule;
        ruletab -> n++;
    } else {
        printf("Un élément n'a pas pu être ajouté au tableau car ce dernier est plein :/ !");
    }
}

/* Ajouter un élément au tableau */
void ruletabaddrealoc(RuleTab* ruletab, Rule* rule) {
    if (ruletab -> n == ruletab -> n_max) {
        ruletab -> tab = realloc(ruletab -> tab, ((ruletab -> n_max) + 1) * sizeof(Rule *));
    }
    ruletabadd(ruletab, rule);
}

/* Obtenir une rêgle a partir d'un identifiant */
Rule* ruletabget(RuleTab* ruletab, RuleId id) {
    
}
