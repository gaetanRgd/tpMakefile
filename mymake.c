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
#include "datastructure/rule_function.h"
#include "graphe.h"
#include "cible.h"

/// @brief fonction main
/// @param prend potentiellement en argument le nom de la premiere regle a construire
int main(int argc, char **argv){
    printf("Lecture du fichier en cours ... :/\n");
    RuleManager* rulemanager = lecture("Makefile"); //Creation du tableau des regles
    printf("\nFin de la lecture du fichier\n");

    printf("Execution des commandes :\n");
    if(argv[1]==NULL){
        make("mymake", rulemanager);
    }
    else {
        make(argv[1], rulemanager);
    }

    rulemanager_free(rulemanager); //Liberation de la memoire
    return 0;
}
