#ifndef RADIX_FILE
#define RADIX_FILE

#include "linkedlist.h"
#include "rule_struct.h"

/* Complexité en espace en O(n)
 * n étant le nombre de chaînes recconues par l'arbre radix */
typedef struct {
    LinkedListHead listhead;
    char* name;
    char* match;
    Rule* rule;
} Radix;

void free_radix_node(Radix* node);

Radix* radixget(Radix* radix, char* key, int key_length);

void radixadd(Radix* radix, char* key, char* match, Rule* rule, int key_length);
#endif