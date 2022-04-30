/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 2                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : Analyse d'adresse IP                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : MATHIEU-Damien                                               *
*                                                                             *
*  Nom-prénom2 : PATOUT-Tristan                                               *
*                                                                             *
*  Nom-prénom3 : CAUJOLLE-Virgile                                             *
*                                                                             *
*  Nom-prénom4 : GUISEPPIN-Léo                                                *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : lecture.c                                                 *
*                                                                             *
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <lecture.h>

int verifierChaine(char *ip) {
    int i = 0;
    int enchainement = 0;
    int separateur = 0;
    if (strlen(ip) >= 9) { /**Une adresse ip ne peut pas être inférieure à une taille de 9 **/
        while( i < strlen(ip)){
            if(isdigit(ip[i])==0 && i==0) { /**On vérife que le premier caractère n'est pas autre chose qu'un chiffre si c'est le cas on retourne 0 **/    
                return 0;
            }
            if (isdigit(ip[i])==1){ /**On regarde si le caractère courant est un nombre et on ajoute1 à l'enchainement de nombre**/
                separateur = 0;
                enchainement++;
                if ((strlen(ip)-1 == i )) { /**Si l'on est dans les 2 derniers caractères nous sommes dans les valeurs de masque car il y a le '/' puis un ou deux chiffres ensuite**/
                    if (ip[i-2]=='/'){
                        if (charToInt(ip[i-1])>3){
                            return 0;
                        }
                        if (charToInt(ip[i-1])==3){
                            if (charToInt(ip[i])>2){
                                return 0;
                            }
                        }
                    }
                    else if (ip[i]=='/') {
                        return 0;
                    }
                }
                if (enchainement==3){ /** si il y a 3 chiffres enchainés il faut que la valeur max soit 255 **/
                    if(charToInt(ip[i-2])>2 ) {/** si le premier chiffre de l'enchainement est supérieur à 2 alors retourne faux.**/
                        return 0;
                    } 
                    if (charToInt(ip[i-2])==2){
                        if(charToInt(ip[i-1])>5 ) {/** si le deuxeieme chiffre de l'enchainement est supérieur à 5 alors retourne faux.**/
                            return 0;
                        }
                        if(charToInt(ip[i])>5 ) {/** si le 3eme chiffre de l'enchainement est supérieur à 5 alors retourne faux.**/
                            return 0;
                        }
                    }
                }
                if (enchainement > 3){ /**Les valeurs d'adresses ip peuvent avoir 3 chiffres enchainés au maximum donc renvoie faux si l'enchainement est supérieur à 3**/
                    return 0;
                }
            }
            if (isdigit(ip[i])== 0) { /**On vérifie si le caractère courant n'est pas un nombre **/
                if (ip[i] == '/' || ip[i]== '.'){ /** on vérifie que les caractères sont bien des séparateurs**/   
                    enchainement = 0; /**l'enchainement de chiffre est donc réinitialiser **/
                    separateur++; /**Le nombre de séparateur est mis à jour **/
                    if (separateur > 1 ) { /**s'il y a plus de 1 séparateur à la suite il y a une erreur**/
                        return 0;
                    }
                }
                else { /**si le caractère n'est pas un séparateur on renvoie une erreur**/
                    return 0;
                }
            }
            i++;
        }
    }
    else {
        return 0;
    }
    return 1; /**Retourne 1 si toutes la chaine de caractère est passée sans lever d'erreur**/
}

void clearBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
 
int lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;
 
    if (fgets(chaine, longueur, stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        else
        {
            clearBuffer();
        }
        return 1;
    }
    else
    {
        clearBuffer();
        return 0;
    }
}