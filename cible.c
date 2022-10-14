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


/* Version naive du make
 * Prend en entree le nom d'une regle(type char*) et l'ensemble des regles(type Ensemble)
 * Construit la regle passee en entree en executant les commades necessaires a la creation
 * Ne renvoie rien
 */
/*void make_naive(char* nom_cible, RuleTab e){
    int id_cible=-1;
    id_cible=parcourir(e, nom_cible);

    if (id_cible==-1){
        char* extension;
        char* nom = nom_cible;
        extension=strtok(nom, ".");
        extension=strtok(NULL, ".");
        if(extension == "o" ) {
            exit(1);// c'est un .o donc il devrait etre dans la liste'
        }
        else{
            //Rien a faire pour construire un .c ou un .h
        }
    }
    else{ // Construire recursivement la cible
        // Contructino de chacune des premisses
        Rules r =get_Regle(id);
        Liste* p = r.premisses;
        while(p != NULL) {
            make_naive(p->nom_cible);
            p=p->suivant;
        }
        // Execution des regles
        Liste c=r.commandes;
        while(c != NULL) {
            system(c->nom_cible);
            c=c->suivant;
        }
    }
}*/

/* Version amelioree du make
 * Prend en entree le nom d'une regle(type char*) et l'ensemble des regles(type Ensemble)
 * Construit la regle passee en entree en executant les commades necessaires a la creation si un des prerequis a ete modifie
 * Ne renvoie rien
 */
void make(char* nom_cible, RuleTab e){
    int* id_cible;
    id_cible=str_to_id(&e, nom_cible);

    printf("Construction de %s\n", nom_cible);

    if (id_cible==NULL){
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
        Rule* r = ruletabget(&e,*id_cible);
        List* p = get_requirement_list(r);
        int a_change=0; // 0 si aucun des fichiers n'a change et 1 sinon
        while(p != NULL) {
            printf("premisse : %s\n", p->element);
            if(getTime(nom_cible)>getTime(p->element)){
                make(p->element, e);
                a_change=1;
            }
            p=p->next;
        }
        // Execution des regles
        if(a_change){// On ne reconstruit que si une premisse au moins a change
            List* c = get_requirement_list(r);
            printf("Execution des commandes de %s :\n", nom_cible);
            while(c != NULL){
                printf("commande : %s\n", c->element);
                system(c->element);
                c=c->next;
            }
        }

    }
    printf("Fin de construction de %s\n\n", nom_cible);
}
/* Permet d'obtenir la date de la derniere modification d'un fichier
 * Prend en entree le nom du fichier(type char*)
 * Renvoie le temps en secondes(long int) depuis la derniere creation
 */
long int getTime(char* fichier) {
    struct stat stats;
    stat(fichier, &stats);

    return stats.st_mtime;
}
