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

#include "rule_struct.h"
#include "linkedlist.h"
#include "safemalloc.h"

/* Complexité en espace en O(n)
 * n étant le nombre de chaînes recconues par l'arbre radix */
typedef struct {
    LinkedListHead list;
    char* name;
    Rule* rule;
} Radix;

typedef struct {
    int size_a;
    int size_b;
    int size_same;
    char* common_part;
    char* char_a;
    char* char_b;
} StrCompared;

StrCompared compare(char* char_a, char* char_b) {
    StrCompared comp = {strlen(char_a), strlen(char_b), 0, NULL, NULL, NULL};
    for (int i = 0; i < ((comp.size_a > comp.size_b) ? comp.size_a : comp.size_b); i++) {
        
    }
}

/* Crée une node radix
 * Complexité en O(1) */
Radix* alloc_radix_node(LinkedListHead* list, Rule* rule) {
    Radix* radix = safe_malloc(size_of(Radix));
    radix -> list = list;
    radix -> rule = rule;
    return radix; 
}

void free_radix_node() {

}



/* Ajoute la clef associée à la valeur id à l'arbre radix
 * Complexité en O(k) 
 * k étant la taille de la chaîne (clef) */
void radixadd(Radix* radix, Rule* rule) {

}

/* Recherche la valeur associéde à la clef dans l'arbre radix
 * Complexité en O(k) 
 * k étant la taille de la chaîne (clef) */
char* radixget(Radix* radix, unsigned char* key) {
    return 0;
}


