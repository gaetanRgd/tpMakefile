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


/// @brief fonction qui lit un fichier  afin de construire la liste des regles du fichier
/// @param prend le nom du fichier
/// @return la table des regles inscrites dans le fichier$
RuleTab lecture(char* fichier) {
    int taille=nbRegles(fichier);//nombre de regles dans le fichier

    FILE* f=NULL;
    f=fopen(fichier,"r");
    if(f==NULL) {
        f=fopen("makefile","r"); // On gere ici le cas ou le nom du fichier Makefile est ecrit entierement en minuscules seulement si le fichier makefile se situe dans le meme dossier que ce projet
        if(f==NULL) {
            exit(1);
        }
    }
    char* ligne_courante = NULL; //Stocke la ligne du fichier qu'on est en train de lire
    char* token;
    size_t MAX_LIGNE=1000; // Taille maximale de la ligne du fichier


    RuleTab tab=ruletabcreate(taille);
    Rule* r;
    char* nom;

    while(!feof(f)) {//On lit tout le fichier

        getline(&ligne_courante, &MAX_LIGNE, f);
        

        if(*(ligne_courante)!='\t' && strlen(ligne_courante)>1) { // Si la ligne n'est pas vide et qu'elle n'est pas une commande, c'est un debut de nouvelle regle

            printf("********fin de la regle********\n\n");
            printf("********nouvelle regle********\n");

            nom=strtok(ligne_courante,":"); // Separer la chaine entre cible et prerequis
            r=create_rule(&tab,nom);
            printf("Nom : %s\n", nom);

            nom = strtok(NULL, ":");//On regrde ce qu'il y a apres les :
            token = strtok(nom, " ");

            printf("prerequis : ");
            while(token != NULL) { // Parcours de la liste des prerequis
                //retirer le caractere \n de la derniere prerequis ( le remplacer par \O)
                remplacer(token,'\n','\0', strlen(token));

                printf("%s, ", token);
                add_requirement(r, token);
                token=strtok(NULL, " ");
            }
        }
        else if(*(ligne_courante)=='\t' ){ // La ligne entiere donne tout de suite la commande (avec le caractere \n pour qu'elles executent toutes seules)
            add_command(r, ligne_courante+1);//On ne veut pas le caractere \t donc +1
            printf("\ncommande : %s", ligne_courante+1); //On ne veut pas le caractere \t donc +1
        }
        


    }
    printf("\n********fin de la regle********\n\n");
    free(ligne_courante); // On libere la memoire allouee dans le getline
    fclose(f);
    return tab;
}


/// @brief remplace un caractere c_av par un caractere c_ap dans le string str
/// @param str chaine de caracteres a modifier
/// @param c_av le caractere present avant la modification
/// @param c_ap le caractere present apres la modification
/// @param n la taille de la chaine str
void remplacer(char* str, char c_av, char c_ap, int n) {
    int i=0;
    while(i<n) {
        if(*(str+i) == c_av) {
            *(str+i)=c_ap;
        }
        i++;
    }
}

/// @brief fonction qui parcourt un fichier pour connaitre le nombre de regles a l'interieur
/// @param prend le nom du fichier a etudier
/// @return le nombre de regles dans le fichier
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
    while(!feof(f)) {//Parcours de tout le fichier
        getline(&ligne_courante, &MAX_LIGNE, f);
        if(*(ligne_courante)!='\t' && strlen(ligne_courante)>1) {
            taille++;
        }
    }
    free(ligne_courante);// On libere la memoire allouee dans le getline
    fclose(f);
    return taille;
}
