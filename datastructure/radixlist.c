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

#include <stdlib.h>

typedef int Bool;

/* Complexité en espace en O(n)
 * n étant le nombre de chaînes recconues par l'arbre radix */
typedef struct {
    RadixChainedList* list;
    Bool* id;
    char* endkey;
} Radix;

/* Complexité en espace en O(1)
 * Car maximum 255 éléments dans la liste, un par caractères */
typedef struct {
    RadixChainedList* next;
    char c;
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


Radix radixget(Radix* radix, unsigned char* key) {
    while (radix->list) {

    }
}


