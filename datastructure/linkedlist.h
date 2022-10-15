#ifndef LINKEDLIST_FILE
#define LINKEDLIST_FILE

/// @brief Liste encapsulant des pointeurs
/// @param next le prochain élément dans la liste
/// @param element le pointeur encapsulée dans le maillon
/// @exception Il faudra free ce maillon avec freelistnode(node)
/// @exception ATTENTION Les données doivent être conservées en mémoire lors de l'utilisation
typedef struct LinkedList {
    struct LinkedList* next;
    void* element;
} LinkedList;

/// @brief Liste avec ajout à la fin encapsulant des pointeurs.
/// @param head Le maillon en tête de la liste 
/// @param tail Le maillon en queue de la liste
/// @exception Ne pas oublier de free cette liste avec freelinkedlist(listhead)
typedef struct {
    LinkedList* head;
    LinkedList* tail;
} LinkedListHead;

LinkedList* create_list_node(void* element);

void free_linkedlist(LinkedListHead* list);

LinkedListHead create_linkedlist(void);

int is_linkedlist_empty(LinkedListHead* list);

void append_linkedlist(LinkedListHead* list, void* element);

void* pop_linkedlist(LinkedListHead* list); 
#endif