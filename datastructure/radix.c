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
#include <string.h>

#include "radix.h"

#include "rule_struct.h"
#include "linkedlist.h"
#include "safemalloc.h"



/* Crée une node radix
 * Complexité en O(1) */
Radix* alloc_radix_node(LinkedListHead listhead, char* name, char* match, Rule* rule) {
    Radix* node = safe_malloc(sizeof(Radix));
    node -> listhead = listhead;
    node -> name = safe_malloc(strlen(name) + 1);
    node -> name = name;
    node -> match = safe_malloc(strlen(match) + 1);
    node -> match = match;
    node -> rule = rule;
    return node; 
}

void free_radix_node(Radix* node) {
    LinkedList* list = node -> listhead.head;
    while(list != NULL) {
        free_radix_node(list -> element);
    }
    free(node -> name);
    free(node);
}


typedef struct {
    int size_same;
    char* radix_char_left;
    char* key_char_left;
    char* samechar;
} StrCompared;

StrCompared compare(char* radixchar, char* keychar, int key_length) {
    StrCompared comp = {0, safe_malloc(key_length + 1), safe_malloc(key_length + 1), safe_malloc(key_length + 1)};
    while ((*radixchar == *keychar) && (*radixchar != '\0')) {
        comp.samechar[comp.size_same] = keychar[comp.size_same];
        comp.size_same++;
        radixchar++;
        keychar++;
    }
    comp.samechar[comp.size_same] = '\0';
    comp.radix_char_left = radixchar;
    comp.key_char_left = keychar;
    return comp;
}

void free_strcompared(StrCompared comp) {
    free(comp.radix_char_left);
    free(comp.key_char_left);
    free(comp.samechar);
}

/* Recherche la valeur associéde à la clef dans l'arbre radix
 * Complexité en O(k) 
 * k étant la taille de la chaîne (clef) */
Radix* radixget(Radix* radix, char* key, int key_length) {
    LinkedList* list = radix -> listhead.head;
    while (list != NULL) {
        StrCompared comp = compare(((Radix*) (list -> element)) -> name, key, key_length);
        if (*(comp.radix_char_left) == '\0') {
            if (*(comp.key_char_left) == '\0') {
                return radix;
            }
            return radixget(list -> element, comp.key_char_left, key_length - comp.size_same);
        } else if (comp.size_same > 0) {
            return NULL;
        }
    }
    return NULL;
}

/* Ajoute la clef associée à la valeur id à l'arbre radix
 * Complexité en O(k) 
 * k étant la taille de la chaîne (clef) */
void radixadd(Radix* radix, char* key, char* match, Rule* rule, int key_length) {
    LinkedList* list = radix -> listhead.head;
    int node_inserted = 0;
    while ((list != NULL) && (!node_inserted)) {
        StrCompared comp = compare(((Radix*) (list -> element)) -> name, key, key_length);
        if (*(comp.radix_char_left) == '\0') {
            node_inserted = 1;
            if (*(comp.key_char_left) == '\0') {
                radix -> match = match;
                radix -> rule = rule;
                printf("La node pour le match %s existe déjà :/\n", match);
            } else {
                radixadd(list -> element, comp.key_char_left, match, rule, key_length - comp.size_same);
            }
        } else if (comp.size_same > 0) {
            node_inserted = 1;
            LinkedListHead linkedlisthead = create_linkedlist();
            append_linkedlist(&linkedlisthead, alloc_radix_node(create_linkedlist(), key + comp.size_same, match, rule));
            safe_realloc(((Radix*) (list -> element)) -> name, comp.size_same + 1);
            ((Radix*) (list -> element)) -> name[comp.size_same + 1] = '\0';
            append_linkedlist(&linkedlisthead, list -> element);
            list -> element = alloc_radix_node(linkedlisthead, comp.samechar, NULL, NULL);
        }
        free_strcompared(comp);
    }
    if (!node_inserted) {
        append_linkedlist(&(radix -> listhead), alloc_radix_node(create_linkedlist(), key, match, rule));
    }
}


