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

typedef int Bool;

/* Complexité en espace en O(n)
 * n étant le nombre de chaînes recconues par l'arbre radix */
typedef struct {
    void* list;
    Bool* id;
    char* endkey;
} Radix;

/* Complexité en espace en O(1)
 * Car maximum 255 éléments dans la liste, un par caractères */
typedef struct RadixChainedList {
    struct RadixChainedList* next;
    Radix* tree;
} RadixChainedList;


/* Crée une node radix
 * Complexité en O(1) */
Radix radixcreate(void) {
    return (Radix) {NULL, 0, NULL};
}

/* Ajoute la clef associée à la valeur id à l'arbre radix
 * Complexité en O(k) 
 * k étant la taille de la chaîne (clef) */
Radix radixadd(Radix radix, unsigned char* key, unsigned int value) {
    
}

/* Recherche la valeur associéde à la clef dans l'arbre radix
 * Complexité en O(k) 
 * k étant la taille de la chaîne (clef) */
Radix radixget(Radix* radix, unsigned char* key) {
    RadixChainedList* list = radix->list;
    while ((list != NULL)) {
        if (!strcomp(list -> tree -> endkey, key)) {
            radix = list -> tree;
            list = radix -> list;
        }
    }
}



