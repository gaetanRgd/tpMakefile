#ifndef CHAINEDLIST_FILE
#define CHAINEDLIST_FILE

/* Liste chainée de chaînes de caractères */
typedef struct List {
    struct List *next;
    char* element;
} List;

/* Structure de gestion de la liste chaînée pour l'ajout en fin de liste */
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