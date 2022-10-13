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
 *   ////////                                                        |_|   |_|  \___/|_| |_| |_|\___/     |____|\___/____|____|
*/

#include <stdlib.h>
#include <string.h>

#include "chainedlist.h"

List* createlistnode(char* element) {
    char* malocelement = malloc(sizeof(*element));
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