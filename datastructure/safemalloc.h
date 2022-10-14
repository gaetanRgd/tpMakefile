#ifndef SAFE_MALLOC_FILE
#define SAFE_MALLOC_FILE

void* safe_malloc(int buffer_size);

void* safe_realloc(void* pointer, int buffer_size);
#endif