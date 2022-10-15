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

#include "buffer.h"
#include "safemalloc.h"

/// @brief Créer un buffer vide
/// @param n_max La taille maximale du buffer
/// @return Le buffer nouvellement crée
/// @exception ATTENTION Ne pas oublier de libérer l'espace mémoire avec buffer_free(buffer)
Buffer buffer_create(int n_max) {
    Buffer buffer = {safe_malloc(n_max), 0, n_max};
    return buffer;
}

/// @brief libere l'espace réservé pour le tableau
/// @param buffer le buffer à désallouer
void buffer_free(Buffer* buffer) {
    free(buffer -> buffer);
}

/// @brief Ajoute un élément au buffer
/// @param buffer le Buffer
/// @param element l'élément à ajouter
/// @param size la taille de l'élément à ajouter
/// @return le buffer incrémenté
/// @exception ATTENTION si le buffer est plein, l'élémént ne sera pas ajouté
void* buffer_add(Buffer* buffer, void* element, int size) {
    if ((buffer -> n + size) < buffer -> n_max) {
        buffer -> buffer[buffer -> n] = element;
        buffer -> n += size;
        return buffer -> buffer[buffer -> n - size];
    }
    perror("Un élément n'a pas pu être ajouté au tableau car ce dernier est plein :/ !");
    return NULL;
}

/// @brief Ajoute une rêgle au tableau quitte à realloc
/// @param buffer le Buffer
/// @param element l'élément à ajouter
/// @param size la taille de l'élément à ajouter
/// @return le tableau incrémenté
void* buffer_add_realoc(Buffer* buffer, void* element, int size) {
    if ((buffer -> n + size) >= buffer -> n_max) {
        buffer -> buffer = safe_realloc(buffer -> buffer, ((buffer -> n_max) * 2 + size));
    }
    return buffer_add(buffer, element, size);
}