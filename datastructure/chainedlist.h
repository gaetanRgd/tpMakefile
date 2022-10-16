#ifndef CHAINEDLIST_FILE
#define CHAINEDLIST_FILE


/// @brief Liste encapsulant des chaîne de caractères
/// @param next le prochain élément dans la liste
/// @param element la chaîne de caractère encapsulée dans le maillon
/// @exception Il faudra free ce maillon avec freelistnode(node)
/// @deprecated MERCI d'utiliser les linkedlist qui généralisent cette structure
typedef struct List {
    struct List *next;
    char* element;
} List;

/// @brief Liste avec ajout à la fin encapsulant des chaînes de caractères.
/// @param head Le maillon en tête de la liste 
/// @param tail Le maillon en queue de la liste
/// @exception Ne pas oublier de free cette liste avec freelinkedlist(listhead)
/// @deprecated MERCI d'utiliser les linkedlist qui généralisent cette structure
typedef struct {
    List* head;
    List* tail;
} ListHead;

List* createlistnode(char* element);

void freelistnode(List* node);

void freelinkedlist(ListHead* list);

ListHead createlist(void);

int is_empty(ListHead* list);

void append(ListHead* list, char* element);

char* pop(ListHead* list); 

void print_list(ListHead list);
#endif