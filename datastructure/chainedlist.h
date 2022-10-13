#ifndef CHAINEDLIST_FILE
#define CHAINEDLIST_FILE

/* Liste chainée de chaînes de caractères */
typedef struct {
    List* next;
    char* element;
} List;

/* Structure de gestion de la liste chaînée pour l'ajout en fin de liste */
typedef struct {
    List* head;
    List* tail;
} ListHead;

List* createlistnode(char* element);

void freelistnode(List* node);

ListHead createlist(void);

int is_empty(ListHead* list);

void append(ListHead* list, char* element);

char* pop(ListHead* list); 
#endif