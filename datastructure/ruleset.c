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

/* Créer un set vide strockant des entiers de 0 à 64
 * Complexité en O(1) */  
RuleSet setcreate(void) {
    return (RuleSet) 0; 
}

/* Ajouter une rêgle au Set 
 * Complexité en O(1) */
RuleSet setadd(RuleSet set, RuleId id) {
    return (RuleSet) {set | (RuleSet) pow(2, id)};
}

/* Supprimer une rêgle au set 
 * Complexité en O(1) */
RuleSet setdel(RuleSet set, RuleId id) {
    return (RuleSet) {set ^ (RuleSet) pow(2, id)};
}

/* Vérification de l'appartenance 
 * Compelxité en O(1) */
int setin(RuleSet set, RuleId id) {
    return  0 != (set & (RuleSet) pow(2, id));
}

/* Egalite de sets 
 * Complexité en O(1) */
int seteq(RuleSet set_a, RuleSet set_b) {
    return set_a == set_b;
}

/* Afficher un set sur la cmd 
 * Complexité en O(1) */
void setprint(RuleSet set) {
    printf("%lld\n", set);
}

/*
void iter(RuleSet set, void* func, RuleId id_start) {
    for (RuleSet i = set; i > 0; i<<0) {
        func(i % 2, id_start);
        id_start ++;
    }
}
*/


/* Exemple d'utilisation des sets */
int main(void) {
    RuleSet set = setcreate();
    set = setadd(set, (RuleId) 3); // Ajout d'une rêgle
    setprint(set);
    set = setadd(set, (RuleId) 2);
    setprint(set);
    set = setadd(set, (RuleId) 0);
    setprint(set);
    printf("%d\n", setin(set, (RuleId) 2)); // Test d'égalité
    return 0;
}