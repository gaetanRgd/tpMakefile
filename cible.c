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

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include<string.h>

#include "cible.h"


/// @brief version naive du make qui reconstruit toujours les prerequis
/// @param prend le nom de la premiere regle a construire et la table des regles du fichier
/// @return void (execute des commandes)
void make(char* nom_cible, RuleTab e){
    Rule* reg_cible = str_to_rule(&e, nom_cible);

    printf("Construction de %s\n", nom_cible);

    if (reg_cible==NULL){
        char* extension;
        char* nom = nom_cible;// je cree une copie pour ne pas detruire la chaine nom_cible avec le strtok
        extension=strtok(nom, ".");
        extension=strtok(NULL, ".");

        char* oo="o";
        if(extension == oo ) {
            exit(1);// c'est un .o donc il devrait etre dans la liste'
        }
        else{
            //Rien a faire pour construire un .c ou un .h
        }
    }
    else{ // Construire recursivement la cible
        // Contruction de chacune des premisses
        List* p = get_requirement_list(reg_cible);
        while(p != NULL) {
            printf("premisse : %s\n", p->element);
            if(getTime(cible_nom)>getTime(p->element)){
                printf("%s", p->element);
                make(p->element, e);
            }
            p=p->next;
        }
        // Execution des regles
        List* c = get_requirement_list(reg_cible);
        printf("Execution des commandes de %s :\n", nom_cible);
        while(c != NULL){
            printf("commande : %s\n", c->element);
            system("cd /test");
            system(c->element);
            c=c->next;
        }

    }
    printf("Fin de construction de %s\n\n", nom_cible);
}


/// @brief fonction make construisant récursivement les regles d'un fichier en partant d'une regle specifiee
/// @param prend le nom de la premiere regle a construire et la table des regles du fichier
/// @return void (execute des commandes)
void make(char* nom_cible, RuleTab e){
    Rule* reg_cible = str_to_rule(&e, nom_cible);

    printf("Construction de %s\n", nom_cible);

    if (reg_cible==NULL){
        char* extension;
        char* nom = nom_cible;// je cree une copie pour ne pas detruire la chaine nom_cible avec le strtok
        extension=strtok(nom, ".");
        extension=strtok(NULL, ".");

        char* oo="o";
        if(extension == oo ) {
            exit(1);// c'est un .o donc il devrait etre dans la liste'
        }
        else{
            //Rien a faire pour construire un .c ou un .h
        }
    }
    else{ // Construire recursivement la cible
        // Contruction de chacune des premisses
        List* p = get_requirement_list(reg_cible);
        int a_change=0; // 0 si aucun des fichiers n'a change et 1 sinon
        while(p != NULL) {
            printf("premisse : %s\n", p->element);
            if(getTime(cible_nom)>getTime(p->element)){
                printf("%s", p->element);
                make(p->element, e);
                a_change=1;
            }
            p=p->next;
        }
        // Execution des regles
        if(a_change){// On ne reconstruit que si une premisse au moins a change
            List* c = get_requirement_list(reg_cible);
            printf("Execution des commandes de %s :\n", nom_cible);
            while(c != NULL){
                printf("commande : %s\n", c->element);
                system("cd /test");
                system(c->element);
                c=c->next;
            }
        }

    }
    printf("Fin de construction de %s\n\n", nom_cible);
}


/// @brief fonction permettant de calculer la derniere date de modification d'un fichier'
/// @param prend le nom du fichier considere
/// @return le temps depuis la derniere modification
long int getTime(char* fichier) {
    struct stat stats;
    stat(fichier, &stats);

    return stats.st_mtime;
}
