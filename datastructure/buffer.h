#ifndef BUFFER_FILE
#define BUFFER_FILE

/// @brief Cette structure représente un buffer dynamique
/// @param mem est le buffer en mémoire
/// @param size vaut la quantitée de mémoire allouée dans le buffer
/// @param sizemax est la quantitée de mémoire maximale du buffer
/// @param n le nombre d'éléments dans le buffer
/// @exception ATTENTION Ne pas oublier de libérer l'espace mémoire avec buffer_free(buffer)
/// @exception On ne peut pas libérer une partie du buffer sans libérer tout le buffer
typedef struct {
    void** mem;
    int size;
    int sizemax;
    int n;
} Buffer;

Buffer buffer_create(int sizemax);

void buffer_free(Buffer* buffer);

void* buffer_add(Buffer* buffer, void* element, int elementsize);

void* buffer_add_realoc(Buffer* buffer, void* element, int elementsize);
#endif
