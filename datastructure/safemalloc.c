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

/// @brief Alloue buffer_size bytes de mémoire
/// @param buffer_size la quantitée de mémoire à allouer
/// @return Un pointeur vers cet espace mémoire
void* safe_malloc(int buffer_size) {
    void* pointer = malloc(buffer_size);
    if (pointer) {
        return pointer;
    } else {
        perror("Le malloc a échoué :/");
        exit(1);
    }
}

/// @brief Change la taille d'un espace mémoire réservé
/// @param pointer un pointeur vers cet espace mémoire
/// @param buffer_size la quantitée de mémoire à allouer
/// @return Un pointeur vers ce nouvel espace mémoire redimensioner
void* safe_realloc(void* pointer, int buffer_size) {
    pointer = realloc(pointer, buffer_size);
    if (pointer) {
        return pointer;
    } else {
        perror("L'opération realloc a échouée :/");
        exit(1);
    }
}