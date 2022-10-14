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
#include <string.h>
#include <stdio.h>

#include "chainedlist.h"


/// @brief Crée un maillon de la liste encapsulant une chaîne de caractère
/// @param element l'élément à encapsuler
/// @return Le maillon de la liste nouvelement formé
/// @exception Il faudra free ce maillon avec freelistnode(node)
List* createlistnode(char* element) {
    List* node = malloc(sizeof(List));
    *node = (List) {NULL, malloc(strlen(element) + 1)};
    strcpy(node -> element, element);
    return node;
}


/// @brief Libère l'espace mémoire occupée par le maillon 
/// @param node le maillon
void freelistnode(List* node) {
    free(node -> element);
    free(node);
}


/// @brief Libère l'espace occupé par la liste chaînée
/// @param listhead la tête de la liste
void freelinkedlist(ListHead* listhead) {
    List* node = listhead -> head;
    List* next; 
    while (node != NULL) {
        next = node -> next;
        freelistnode(node);
        node = next;
    }
}


/// @brief Crée une liste chaînée permettant l'ajout en fin de chaîne
/// @return La liste chaînée vide
/// @exception Ne pas oublier de free cette liste avec freelinkedlist(listhead)
ListHead createlist(void) {
    return (ListHead) {NULL, NULL};
}


/// @brief Vérfie si une liste chainée est vide
/// @param listhead La liste étudiée
/// @return Un entier valant vrai si la liste est vide et 0 sinon
int is_empty(ListHead* listhead) {
    return listhead -> head == NULL; 
}

/// @brief Ajoute une chaîne en queue de liste (enfile)
/// @param listhead la tête de la liste
/// @param element l'élément à ajouter
void append(ListHead* listhead, char* element) {
    List* node = createlistnode(element);
    if (is_empty(listhead)) {
        listhead->head = node;
        listhead->tail = node;
    } else {
        listhead->tail->next = node;
        listhead->tail = node;
    }
}


/// @brief Enlène un élément en tête de liste (défile)
/// @param listhead la tête de la liste
/// @return L'élément retiré de la liste
char* pop(ListHead* listhead) {
    List* node = listhead -> head;
    listhead -> head = node -> next;
    char* element = node -> element;
    freelistnode(node);
    return element;
}


/// @brief Affiche la liste
/// @param listhead la tête de la liste
void print_list(ListHead listhead) {
    List* node = listhead.head;
    printf("[");
    while (node != NULL) {
        printf("%s, ", node -> element);
        node = node -> next;
    }
    printf("]");
}