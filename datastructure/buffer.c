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
Buffer buffer_create(int sizemax) {
    return (Buffer) {safe_malloc(sizemax * 8), 0, sizemax, 0};
}

/// @brief libere l'espace réservé pour le tableau
/// @param buffer le buffer à désallouer
void buffer_free(Buffer* buffer) {
    free(buffer -> mem);
}

/// @brief Ajoute un élément au buffer
/// @param buffer le Buffer
/// @param element l'élément à ajouter
/// @param size la taille de l'élément à ajouter
/// @return le buffer incrémenté
/// @exception ATTENTION si le buffer est plein, l'élémént ne sera pas ajouté
void* buffer_add(Buffer* buffer, void* element, int elementsize) {
    printf("n=%d, size=%d, sizemax=%d, elementsize=%d, buffer=%p\n", buffer -> n, buffer -> size, buffer -> sizemax, elementsize, buffer -> mem);
    if ((buffer -> size + elementsize) <= buffer -> sizemax) {
        printf("Writting to address %p, buffer+%d, buffer=%p\n", ((buffer -> mem) + (buffer -> size)), buffer -> size, buffer -> mem);
        *(buffer -> mem + (buffer -> size)) = element;
        buffer -> size += elementsize;
        buffer -> n++;
        return buffer -> mem[buffer -> size - elementsize];
    }
    perror("Un élément n'a pas pu être ajouté au tableau car ce dernier est plein :/ !\n");
    return NULL;
}

/// @brief Ajoute une rêgle au tableau quitte à realloc
/// @param buffer le Buffer
/// @param element l'élément à ajouter
/// @param size la taille de l'élément à ajouter
/// @return le tableau incrémenté
void* buffer_add_realoc(Buffer* buffer, void* element, int elementsize) {
    if ((buffer -> size + elementsize) > buffer -> sizemax) {
        buffer -> mem = safe_realloc(buffer -> mem, ((buffer -> sizemax) * 2 + elementsize) * 8);
        buffer -> sizemax = ((buffer -> sizemax) * 2 + elementsize);
    }
    return buffer_add(buffer, element, elementsize);
}