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



/// @brief fonction qui permet de remplacere les variables de type $ dans le Makefile sans modifier la variable d'entree
/// @param prend une liste de caracteres a modifier, les prerequis et le nom du fichier cible
/// @return la liste de caractere ou les $ ont ete remplace par les variables
char* parcourir(char* commande, char* pre, char* nom){
    size_t t_pre = strlen(pre);//fixee avant que pre ne soit modifie
    char* stockePre=malloc(t_pre*sizeof(char));//+1 pour le '\0'
    strcpy(stockePre,pre);//Eviter la corruption de pre
    char* premier_pre=strtok(pre, " ");// Premier prerequis
    char* newCommand=malloc(((int)strlen(commande) + (int)t_pre + (int)strlen(nom))*sizeof(char));
    char c_courant=*commande;//Caractere qui parcourt la commande a la recherche des $
    int indiceC=0;//Indice de parcours de la commande pour c_courant
    int decalageNewC=0;//decalage de l'indice pour ecrire dans newCommand a chaque fois qu'il y a un $

    while(c_courant != '\0'){
        if(c_courant=='$'){
            switch(*(commande+indiceC+1)){ // On regarde par quoi on va devoir remplacer
                case '@':
                    for(int i=0;i<(int)strlen(nom);i++){
                        *(newCommand+decalageNewC+indiceC+i)=*(nom+i);
                    }
                    decalageNewC+=(int)strlen(nom);
                    break;
                case '<':
                    for(int i=0;i<(int)strlen(premier_pre);i++){
                        *(newCommand+decalageNewC+indiceC+i)=*(premier_pre+i);
                    }
                    decalageNewC+=((int)strlen(premier_pre));
                    break;
                case '^':
                    for(int i=0;i<(int)t_pre;i++){
                        *(newCommand+decalageNewC+indiceC+i)=*(stockePre+i);
                    }
                    decalageNewC+=(int)t_pre;
                    break;
                default:
                    exit(1);
                    break;

            }
            indiceC++;//On ne regarde pas le caratere apres le $
            decalageNewC-=2;
        }
        else{
            *(newCommand+decalageNewC+indiceC)=c_courant;
        }
        indiceC++;
        c_courant=*(commande+indiceC);
    }
    *(newCommand+decalageNewC+indiceC)='\0';

    free(stockePre);
    return newCommand;
}



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
    size_t MAX_LIGNE=1000; // Taille maximale de la ligne du fichier -> a faire : connaitre la taille max d'une ligne grace au premier parcours

    //Variables utilisees pour l'extension remplacer les $
    char* commande_modif;
    char* liste_prerequis=NULL;
    char* copynomBoucle=NULL;


    RuleTab tab=ruletabcreate(taille);
    Rule* r;
    char* nom;


    while(!feof(f)) {//On lit tout le fichier

        getline(&ligne_courante, &MAX_LIGNE, f);
        

        if(*(ligne_courante)!='\t' && strlen(ligne_courante)>1) { // Si la ligne n'est pas vide et qu'elle n'est pas une commande, c'est un debut de nouvelle regle

            printf("\n********fin de la regle********\n\n");
            printf("********nouvelle regle********\n");

            if(liste_prerequis != NULL){
                free(liste_prerequis);
                liste_prerequis=NULL;
            }
            if(copynomBoucle != NULL){
                free(copynomBoucle);
                copynomBoucle=NULL;
            }

            nom=strtok(ligne_courante,":"); // Separer la chaine entre cible et prerequis
            r=create_rule(&tab,nom);
            printf("Nom : %s\n", nom);
            copynomBoucle=malloc(strlen(nom)*sizeof(char)+1);// +1 pour le '\0'
            strcpy(copynomBoucle,nom);//On garde en memoire la liste des prerequis  pour eventuelement changer les commandes

            nom = strtok(NULL, ":");//On regrde ce qu'il y a apres les :
            liste_prerequis=malloc(strlen(nom)*sizeof(char)+1);// +1 pour le '\0'
            strcpy(liste_prerequis,nom);//On garde en memoire la liste des prerequis  pour eventuelement changer les commandes
            remplacer(liste_prerequis,'\n','\0', strlen(liste_prerequis));
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
            commande_modif=parcourir(ligne_courante+1,liste_prerequis, copynomBoucle);
            add_command(r, commande_modif);//On ne veut pas le caractere \t donc +1
            printf("\ncommande : %s", commande_modif); //On ne veut pas le caractere \t donc +1
            free(commande_modif);
        }
    }

    printf("\n********fin de la regle********\n\n");
    free(ligne_courante); // On libere la memoire allouee dans le getline
    if(liste_prerequis != NULL){
        free(liste_prerequis);
        liste_prerequis=NULL;
    }
    if(copynomBoucle != NULL){
        free(copynomBoucle);
        copynomBoucle=NULL;
    }
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
