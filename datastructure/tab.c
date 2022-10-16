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
 *       ^^^^^^^^/(////((////^ ^^^^         (&&&&&&&&      ____    &&&&&&&&                     __     _  __   __
 *     .^^^///////////////////                            |  __ \                              |__ \ / _ \__ \|__ \       
 *     /^///////,..//////^//////^                         | |__) | __ ___  _ __ ___   ___         ) | | | | ) |  ) |     
 * ////////////#////////    ^^^^^                         |  ___/ '__/ _ \| '_ ` _ \ / _ \       / /| | | |/ /  / /   
 *  /////((((////////        ^^^^                         | |   | | | (_) | | | | | | (_) |     / /_| |_| / /_ / /_ 
 *   ////////                                             |_|   |_|  \___/|_| |_| |_|\___/     |____|\___/____|____|
*/

#include <stdlib.h>
#include <stdio.h>

#include "tab.h"
#include "safemalloc.h"

/// @brief Créer un tableau de pointeurs vide
/// @param nmax La taille maximale du tableau
/// @return Le tableau nouvellement crée
/// @exception ATTENTION Ne pas oublier de libérer l'espace mémoire avec tab_free(tab)
Tab tab_create(int nmax) {
    Tab* tab = safe_malloc(sizeof(Tab));
    *tab = (Tab) {safe_malloc(nmax * sizeof(void*)), nmax, 0};
    return tab;
}

/// @brief libere l'espace réservé pour le tableau
/// @param tab le tableau à désallouer
void tab_free(Tab* tab) {
    free(tab -> mem);
    free(tab);
}

/// @brief Ajoute un élément au tableau
/// @param tab le tableau
/// @param ptr le pointeur à ajouter
/// @return le tableau incrémenté
/// @exception ATTENTION si le tableau est plein, le pointeur ne sera pas ajouté
void* tab_add(Tab* tab, void* ptr) {
    if (tab -> n < tab -> nmax) {
        tab -> mem[tab -> n] = ptr;
        tab -> n++;
        return tab -> mem[tab -> n - 1];
    }
    perror("Un élément n'a pas pu être ajouté au tableau car ce dernier est plein :/ !\n");
    return NULL;
}

/// @brief Ajoute un pointeur au tableau quitte à realloc
/// @param tab le tableau
/// @param ptr le pointeur à ajouter
/// @return le tableau incrémenté
void* tab_add_realoc(Tab* tab, void* ptr) {
    if (tab -> n >= tab -> nmax) {
        tab -> mem = safe_realloc(tab -> mem, (tab -> nmax) * 2);
        tab -> nmax = (tab -> nmax) * 2;
    }
    return tab_add(tab, ptr);
}

/// @brief Récupère le pointeur a partir de son numéro dans le tableau
/// @param tab le tableau
/// @param ptr le pointeur à ajouter
/// @return le tableau incrémenté
void* tab_get(Tab* tab, int id) {
    if (id <= tab -> n) {
        return tab -> mem[id];
    }
    perror("Le tableau ne contient pas autant de pointeurs :/\n");
    return NULL;
}