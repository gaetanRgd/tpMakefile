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

#include "rule_function.h"

/* Complexité en espace en O(n)
 * n étant le nombre de chaînes recconues par l'arbre radix */
typedef struct {
    void* list;
    Rule* rule;
    char* endkey;
} Radix;

/* Complexité en espace en O(1)
 * Car maximum 255 éléments dans la liste, un par caractères */
typedef struct RadixChainedList {
    struct RadixChainedList* next;
    Radix* tree;
} RadixChainedList;

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
Radix radixcreate(void) {
    return (Radix) {NULL, NULL, NULL};
}

/* Ajoute la clef associée à la valeur id à l'arbre radix
 * Complexité en O(k) 
 * k étant la taille de la chaîne (clef) */
void radixadd(Radix* radix, char* key, Rule* rule) {
    int cmp = strcmp(radix -> endkey, key);
    if (cmp == 0) {
        radix -> rule = rule;
    } else if (cmp > 0) {

    } else {

    }
}

/* Recherche la valeur associéde à la clef dans l'arbre radix
 * Complexité en O(k) 
 * k étant la taille de la chaîne (clef) */
char* radixget(Radix* radix, unsigned char* key) {
    RadixChainedList* list = radix->list;
    while ((list != NULL)) {
        if (!strcmp(list -> tree -> endkey, key)) {
            radix = list -> tree;
            list = radix -> list;
        }
    }
    return NULL;
}



