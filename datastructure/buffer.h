#ifndef BUFFER_FILE
#define BUFFER_FILE

/// @brief Cette structure représente un buffer dynamique
/// @param buffer est le buffer
/// @param n vaut la quantitée de mémoire allouée dans le buffer
/// @param n_max est la taille maximale du buffer
/// @exception ATTENTION Ne pas oublier de libérer l'espace mémoire avec buffer_free(buffer)
/// @exception On ne peut pas libérer une partie du buffer sans libérer tout le buffer
typedef struct {
    void** buffer;
    int n;
    int n_max;
} Buffer;

Buffer buffer_create(int n_max);

void buffer_free(Buffer* buffer);

void* buffer_add(Buffer* buffer, void* element, int size);

void* buffer_add_realoc(Buffer* buffer, void* element, int size);
#endif
