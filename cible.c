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


/* Version naive du make
 * Prend en entree le nom d'une regle(type char*) et l'ensemble des regles(type Ensemble)
 * Construit la regle passee en entree en executant les commades necessaires a la creation
 * Ne renvoie rien
 */
void make_naive(char* nom_cible, Ruleset e){
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
}

/* Version amelioree du make
 * Prend en entree le nom d'une regle(type char*) et l'ensemble des regles(type Ensemble)
 * Construit la regle passee en entree en executant les commades necessaires a la creation si un des prerequis a ete modifie
 * Ne renvoie rien
 */
void make(char* nom_cible, Ruletab e){
    int* id_cible;
    id_cible=strtoid(e, nom_cible);

    if (id_cible==NULL){
        char* extension;
        char* nom = nom_cible;// je cree une copie pour ne pas detruire la chaine nom_cible avec le strtok
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
        // Contruction de chacune des premisses
        Rules r =ruletabget(&e,*id_cible);
        Liste* p = r.premisses;
        int a_change=0; // 0 si aucun des fichiers n'a change et 1 sinon
        while(p != NULL) {
            if(getTime(nom_cible)>getTime(p)->nom)){
                make(p->nom, e);
                a_change=1;
            }
            p=p->suivant;
        }
        // Execution des regles
        if(a_change){// On ne reconstruit que si une premisse au moins a change
            Liste c=r.commandes;
            while(c != NULL) {
                system(c->nom);
                c=c->suivant;
            }
        }

    }
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
