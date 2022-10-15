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

#include "linkedlist.h"
#include "safemalloc.h"

/// @brief Crée un maillon de la liste encapsulant un pointeur
///        Complexité en O(1)
/// @param element le pointeur à encapsuler
/// @return Le maillon de la liste nouvelement formé
/// @exception Il faudra free ce maillon avec free(node)
LinkedList* create_list_node(void* element) {
    LinkedList* node = safe_malloc(sizeof(LinkedList));
    *node = (LinkedList) {NULL, element};
    return node;
}

/// @brief Libère l'espace occupé par la liste chaînée
///        Complexité linéaire en la taille de la liste
/// @param listhead la tête de la liste
void free_linkedlist(LinkedListHead* listhead) {
    LinkedList* node = listhead -> head;
    LinkedList* next; 
    while (node != NULL) {
        next = node -> next;
        free(node);
        node = next;
    }
}

/// @brief Crée une liste chaînée permettant l'ajout en fin de chaîne
///        Complexité en O(1)
/// @return La liste chaînée vide
/// @exception Ne pas oublier de free cette liste avec freelinkedlist(listhead)
LinkedListHead create_linkedlist(void) {
    return (LinkedListHead) {NULL, NULL};
}


/// @brief Vérfie si une liste chainée est vide
///        Complexité en O(1)
/// @param listhead La liste étudiée
/// @return Un entier valant vrai si la liste est vide et 0 sinon
int is_linkedlist_empty(LinkedListHead* listhead) {
    return listhead -> head == NULL; 
}

/// @brief Ajoute un pointeur en queue de liste (enfile)
///        Complexité en O(1)
/// @param listhead la tête de la liste
/// @param element l'élément à ajouter
/// @exception ATTENTION On ne sauvegarde que le pointeur, la mémoire doit rester allouée pour l'utilisation
void append_linkedlist(LinkedListHead* listhead, void* element) {
    LinkedList* node = create_list_node(element);
    if (is_linkedlist_empty(listhead)) {
        listhead->head = node;
        listhead->tail = node;
    } else {
        listhead->tail->next = node;
        listhead->tail = node;
    }
}


/// @brief Enlène un élément en tête de liste (défile)
///        Complexité en O(1)
/// @param listhead la tête de la liste
/// @return L'élément retiré de la liste
void* pop_linkedlist(LinkedListHead* listhead) {
    LinkedList* node = listhead -> head;
    listhead -> head = node -> next;
    void* element = node -> element;
    free(node);
    return element;
}