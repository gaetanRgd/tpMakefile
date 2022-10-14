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

List* createlistnode(char* element) {
    char* malocelement = malloc(strlen(element) + 1);
    strcpy(malocelement, element);
    List* node = malloc(sizeof(List));
    *node = (List) {NULL, malocelement};
    return node;
}

void freelistnode(List* node) {
    free(node -> element);
    free(node);
}

ListHead createlist(void) {
    return (ListHead) {NULL, NULL};
}

int is_empty(ListHead* list) {
    return list -> head == NULL; 
}

void append(ListHead* list, char* element) {
    List* node = createlistnode(element);
    if (is_empty(list)) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

char* pop(ListHead* list) {
    List* node = list -> head;
    list -> head = node -> next;
    char* element = node -> element;
    freelistnode(node);
    return element;
}

void print_list(ListHead list) {
    List* node = list.head;
    printf("[");
    int n = 0;
    while (node != NULL && n < 10) {
        printf("%s, ", node -> element);
        node = node -> next;
        n ++;
    }
    printf("]");
}