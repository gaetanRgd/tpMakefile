/* Version naive du make
 * Prend en entree le nom d'une regle(type char*) et l'ensemble des regles(type Ensemble)
 * Construit la regle passee en entree en executant les commades necessaires a la creation
 * Ne renvoie rien
 */
void make_naive(char* nom_cible, Ensemble e){
    int id_cible=-1;
    id_cible=parcourir(e, nom_cible);

    if (id_cible==-1){
        char*extension;
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
        Regle r =get_Regle(id);
        Liste* p = r.premisses;
        while(p != NULL) {
            make_naive(p->nom);
            p=p->suivant;
        }
        // Execution des regles
        Liste c=r.commandes;
        while(c != NULL) {
            system(c->nom);
            c=c->suivant;
        }
    }
}

/* Version amelioree du make
 * Prend en entree le nom d'une regle(type char*) et l'ensemble des regles(type Ensemble)
 * Construit la regle passee en entree en executant les commades necessaires a la creation si un des prerequis a ete modifie
 * Ne renvoie rien
 */
void make(char* nom_cible, Ensemble e){
    int id_cible=-1;
    id_cible=parcourir(e, nom_cible);

    if (id_cible==-1){
        char*extension;
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
        Regle r =get_Regle(id);
        Liste* p = r.premisses;
        int a_change=0; // 0 si aucun des fichiers n'a change et 1 sinon
        while(p != NULL) {
            if(getTime(nom_cible)>getTime(p->nom)){
                make_naive(p->nom);
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

