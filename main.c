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
*  Nom du fichier : main.c                                                    *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <lecture.h>
#include <extraireChamp.h>
#include <conversionValeur.h>
#include <classeIP.h>

int main() 
{
    char ip[18];
    char ip1[3];
    char ip2[3];
    char ip3[3];
    char ip4[3];
    char CIDR[2];
    char classe[0];
    /**Récupération de la saisie utilisateur**/
    printf("Saisir une adresse ip : \n");
    lire(ip,18);
    while (verifierChaine(ip)!= 1){
        printf("Saisir une adresse ip valable : \n");
        lire(ip,18);
    }
    /**Découpage des champs de l'adresse IP**/
    int j =0;
    int count = 1;
    for (int i = 0; i<strlen(ip);i++){
        if (count == 1)
            if (ip[i]=='.'){
                if (getSubString(ip,ip1,j,(i-1))==0) {
                    printf("Champ 1 de l'ip : %s\n",ip1);
                    j=i+1;
                    count++;
                }
                else {
                    printf("erreur dans l'extration du champ 1.\n");
                }
            }     
        else if (count == 2)
            if (ip[i]=='.'){
                if (getSubString(ip,ip2,j,(i-1))==0) {
                    printf("Champ 2 de l'ip : %s\n",ip2);
                    j=i+1;
                    count++;
                }
                else {
                    printf("erreur dans l'extration du champ 2.\n");
                }
            }  
        else if (count == 3)
            if (ip[i]=='.'){
                if (getSubString(ip,ip3,j,(i-1))==0) {
                    printf("Champ 3 de l'ip : %s\n",ip3);
                    j=i+1;
                    count++;
                }
                else {
                    printf("erreur dans l'extration du champ 3.\n");
                }
            }  
        else if (count == 4)
            if (ip[i]=='.'){
                if (getSubString(ip,ip4,j,(i-1))==0) {
                    printf("Champ 4 de l'ip : %s\n",ip4);
                    j=i+1;
                    count++;
                }
                else {
                    printf("erreur dans l'extration du champ 4.\n");
                }
            }  
        else if (count == 5)
            if (ip[i]=='/'){
                if (getSubString(ip,CIDR,j,(i-1))==0) {
                    printf("Champ du masque : %s\n",CIDR);
                    j=i+1;
                    count++;
                }
                else {
                    printf("erreur dans l'extration du champ du masque.\n");
                }
            }  
    }
    /**Affichage de la classe de l'adresse IP**/
    classe = classeIP(charToInt(ip1),charToInt(ip2),charToInt(ip3),charToInt(ip4));
    if(classeIP(ip1,ip2,ip3,ip4)=='Z'){
        printf("erreur dans le traitement de classe de l'adresse.");
    }
    else{
        printf("Adresse ip de classe : %c",classeIP(ip1,ip2,ip3,ip4));
    }
    /**Affichage du type de l'adresse IP**/
    if (typeAdresse(charToInt(ip1),charToInt(ip2),charToInt(ip3),charToInt(ip4),charToInt(CIDR))==0) {
        printf("Cette IP est privée.\n");
    } 
    else if (typeAdresse(charToInt(ip1),charToInt(ip2),charToInt(ip3),charToInt(ip4),charToInt(CIDR))==1) {
        printf("Cette IP est multicast.\n");
    }
    else if (typeAdresse(charToInt(ip1),charToInt(ip2),charToInt(ip3),charToInt(ip4),charToInt(CIDR))==2) {
        printf("Cette IP est broadcast.\n");
    }
    else if (typeAdresse(charToInt(ip1),charToInt(ip2),charToInt(ip3),charToInt(ip4),charToInt(CIDR))==3) {
        printf("Cette IP est localhost.\n");
    }
    else if (typeAdresse(charToInt(ip1),charToInt(ip2),charToInt(ip3),charToInt(ip4),charToInt(CIDR))==4) {
        printf("Cette IP est publique.\n")
    }
    return 0;
}


