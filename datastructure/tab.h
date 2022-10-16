#ifndef TAB_FILE
#define TAB_FILE

/// @brief Cette structure représente un tableau de pointeurs
/// @param mem est le tableau en mémoire
/// @param nmax est la quantitée de mémoire maximale du buffer
/// @param n le nombre d'éléments dans le buffer
/// @exception ATTENTION Ne pas oublier de libérer l'espace mémoire avec tab_free(tab)
/// @exception On ne peut pas libérer une partie du tableau sans libérer tout le ableau
typedef struct {
    void** mem;
    int nmax;
    int n;
} Tab;

Tab* tab_create(int nmax);

void tab_free(Tab* tab);

void* tab_add(Tab* tab, void* ptr);

void* tab_add_realoc(Tab* tab, void* ptr);

void* tab_get(Tab* tab, int id);
#endif
