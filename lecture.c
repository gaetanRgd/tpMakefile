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

#include<string.h>


/* Lit le fichier donne en entree
 * Cree l'ensemble contenant les regles du fichier
 * Renvoie l'ensemble des regles lues dans le fichier(type Ensemble)
 */
Ensemble lecture(char* fichier) {
    int taille=nbRegles(fichier);

    FILE* f=NULL;
    f=fopen(fichier,"r");
    if(f==NULL) {
        exit(1);
    }
    char* ligne_courante;
    char* token;
    size_t MAX_LIGNE=100;


    //Ruletab e=ruleTabCreate(taille);
    char*nom;

    while(!testFinFichier(f)) {

        getline(&ligne_courante, &MAX_LIGNE, f);


        if(*(ligne_courante)!='\t' && strlen(ligne_courante)>1) {

            printf("********fin de la regle********\n\n");
            printf("********nouvelle regle********\n");
            // //ajouterRegle(e,creerRegle(nom));

            //setRegle(id).nom=strtok(ligne_courante,":");
            //id=creerRegle(nom);
            nom=strtok(ligne_courante,":"); // Separer la chaine entre cible et premisses
            printf("Nom : %s\n", nom);

            ligne_courante=strtok(NULL, ":");//On regrde ce qu'il y a apres les :'
            token=strtok(ligne_courante, " ");

            printf("premisses : ");
            while(token != NULL) { // Parcours de la liste des premisses
                //ajouterP(getRegle(e),token);
                //retirer le caractere \n de la derniere premisse ( le remplacer par \O)
                remplacer(token,'\n','\0', strlen(token));
                printf("%s, ", token);
                token=strtok(NULL, " ");
            }
        }
        else if(*(ligne_courante)=='\t' ){ // La ligne entiere donne tout de suite la commande (avec le caractere \n pour qu'elles'execure toute seule)
            //ajouterC(getRegle(e),ligne_courante);
            printf("\ncommande : %s", ligne_courante+1); //On ne veut pas le caractere \t
        }


    }
    printf("\n********fin de la regle********\n\n");
    fclose(f);

    return e;
}

/* Teste si la position actuelle dans le fichier correspond a EOF
 * Prend en entree le nom du fichier(type char*) ou on fait le test
 * Renvoie 1 si on est a la fin du fichier et 0 sinon
 */
int testFinFichier(FILE* f) { // pour savoir si on peut continuer les getline
    if (fgetc(f)==EOF) {
        return 1;
    }
    else {
        fseek(f, -1, SEEK_CUR);
        return 0;
    }
}

/* Remplace le caractere c2 par c3 dans la chaine de caracteres s1
 * Prend en entree s1(type char*) c2(type char) et c3(type char)
 */
void remplacer(char* s1, char c2, char c3, int n) {
    int i=0;
    while(i<10) {
        if(*(s1+i) == c2) {
            *(s1+i)=c3;
        }
        i++;
    }
}
