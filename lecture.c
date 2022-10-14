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


#include "lecture.h"


/* Lit le fichier donne en entree
 * Cree l'ensemble contenant les regles du fichier
 * Renvoie l'ensemble des regles lues dans le fichier(type Ensemble)
 */
RuleTab lecture(char* fichier) {
    int taille=nbRegles(fichier);
    printf("\n\n%d\n\n", taille);

    FILE* f=NULL;
    f=fopen(fichier,"r");
    if(f==NULL) {
        exit(1);
    }
    char* ligne_courante = NULL;
    char* token;
    size_t MAX_LIGNE=100;


    RuleTab e=ruletabcreate(taille);
    Rule* r;
    char* nom;

    while(!testFinFichier(f)) {

        getline(&ligne_courante, &MAX_LIGNE, f);
        

        if(*(ligne_courante)!='\t' && strlen(ligne_courante)>1) { // Si la ligne n'est pas vide et qu'elle n'est pas une commande, c'est un debut de nouvelle regle

            printf("********fin de la regle********\n\n");
            printf("********nouvelle regle********\n");

            nom=strtok(ligne_courante,":"); // Separer la chaine entre cible et premisses
            r=create_rule(&e,nom);
            printf("Nom : %s\n", nom);

            nom = strtok(NULL, ":");//On regrde ce qu'il y a apres les :
            token=strtok(nom, " ");

            printf("premisses : ");
            while(token != NULL) { // Parcours de la liste des premisses
                //retirer le caractere \n de la derniere premisse ( le remplacer par \O)
                remplacer(token,'\n','\0', strlen(token));

                printf("%s, ", token);
                add_requirement(r, token);
                token=strtok(NULL, " ");
            }
        }
        else if(*(ligne_courante)=='\t' ){ // La ligne entiere donne tout de suite la commande (avec le caractere \n pour qu'elles'execure toute seule)
            add_command(r, ligne_courante+1);//On ne veut pas le caractere \t
            printf("\ncommande : %s", ligne_courante+1); //On ne veut pas le caractere \t
        }
        


    }
    printf("\n********fin de la regle********\n\n");
    free(ligne_courante);
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
/// @brief 
/// @param s1 
/// @param c2 
/// @param c3 
/// @param n 
void remplacer(char* s1, char c2, char c3, int n) {
    int i=0;
    while(i<n) {
        if(*(s1+i) == c2) {
            *(s1+i)=c3;
        }
        i++;
    }
}

/*Permet de connaitre le nombre de regles dans le fichier avant de creer toutes les structures
 * Prend en entree le nom du fichier ou sont stockees les regles
 * Renvoie le nombre de regles dans le fichier
 */
int nbRegles(char* fichier){
    FILE* f;
    size_t MAX_LIGNE=1000;
    f=fopen(fichier,"r");
    printf("%ld", (long int) f);
    if(f==NULL) {
        exit(1);
    }
    int taille=0;
    char* ligne_courante = NULL;
    while(!feof(f)) {
        getline(&ligne_courante, &MAX_LIGNE, f);
        if(*(ligne_courante)!='\t' && strlen(ligne_courante)>1) {
            taille++;
        }
    }
    free(ligne_courante);
    fclose(f);
    return taille;
}
