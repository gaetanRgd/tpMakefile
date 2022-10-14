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
 *       ^^^^^^^^/(////((////^ ^^^^         (&&&&&&&&              &&&&&&&&&                               __     _  __   __
 *     .^^^///////////////////                                       |  __ \                              |__ \ / _ \__ \|__ \
 *     /^///////,..//////^//////^                                    | |__) | __ ___  _ __ ___   ___         ) | | | | ) |  ) |
 * ////////////#////////    ^^^^^                                    |  ___/ '__/ _ \| '_ ` _ \ / _ \       / /| | | |/ /  / /
 *  /////((((////////        ^^^^                                    | |   | | | (_) | | | | | | (_) |     / /_| |_| / /_ / /_
 *   ////////                                                        |_|   |_|  \___/|_| |_|_|_|\___/     |____|\___/____|____|
*/

#include <stdlib.h>
#include <stdio.h>

#include "lecture.h"
#include "datastructure/ruleset.h"
#include "datastructure/ruletab.h"
#include "graphe.h"
#include "cible.h"

/// @brief fonction main
/// @param prend potentiellement en argument le nom de la premiere regle a construire
int main(int argc, char **argv){
    printf("Lecture du fichier en cours ... :/\n");
    RuleTab tab = lecture("Makefile"); //Creation du tableau des regles
    printf("\nFin de la lecture du fichier\n");

    printf("Execution des commandes :\n");
    if(argv[1]==NULL){
        make("main",tab);
    }
    else {
        make(argv[1],tab);
    }

    ruletabfree(&tab); //Liberation de la memoire
    return 0;
}
