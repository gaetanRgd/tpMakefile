#ifndef CHAINEDLIST_FILE
#define CHAINEDLIST_FILE

typedef struct {
    List* next;
    char* element;
} List;

typedef struct {
    List* head;
    List* tail;
} ListHead;

#endif