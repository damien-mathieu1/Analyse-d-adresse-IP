/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet :                                                              *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé :                                                                 *
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
void clearBuffer();
int lire(char *chaine, int longueur);
int verifierChaine(char *ip);
int charToInt(char c); 
int  getSubString(char *source, char *target,int from, int to);
char classeIP(int ip1,int ip2, int ip3, int ip4);
int typeAdresse(int ip1,int ip2, int ip3, int ip4,int CIDR);


int main() 
{
    char ip[18];
    char ip1[3];
    char ip2[3];
    char ip3[3];
    char ip4[3];
    char CIDR[2];
    char classe[0];
    printf("Saisir une adresse ip : \n");
    lire(ip,18);
    while (verifierChaine(ip)!= 1){
        printf("Saisir une adresse ip valable : \n");
        lire(ip,18);
    }
    int j =0;
    int count = 1;
    for (int i = 0; i<strlen(ip);i++){
        /**on compte chaque fois qu'un champ est extrait pour extraire le prochain champ dans une autre variable**/
        if (count == 1)
            if (ip[i]=='.'){
                if (extraireChamp(ip,ip1,j,(i-1))==0) {
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
                if (extraireChamp(ip,ip2,j,(i-1))==0) {
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
                if (extraireChamp(ip,ip3,j,(i-1))==0) {
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
                if (extraireChamp(ip,ip4,j,(i-1))==0) {
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
                if (extraireChamp(ip,CIDR,j,(i-1))==0) {
                    printf("Champ du masque : %s\n",CIDR);
                    j=i+1;
                    count++;
                }
                else {
                    printf("erreur dans l'extration du champ du masque.\n");
                }
            }  
    }
    classe = classeIP(charToInt(ip1),charToInt(ip2),charToInt(ip3),charToInt(ip4));
    if(classeIP(ip1,ip2,ip3,ip4)=='Z'){
        printf("erreur dans le traitement de classe de l'adresse.\n");
    }
    else{
        printf("Adresse ip de classe : %c\n",classeIP(ip1,ip2,ip3,ip4));
    }

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

int typeAdresse(int ip1,int ip2, int ip3, int ip4,int CIDR){
    if (ip1==10&&CIDR == 8) {
        if (ip2 <= 255){
            if(ip3<=255){
                if (ip4<=255){
                    return 0;
                }
            }
        }
    }
    else if (ip1==172&&CIDR == 12){
        if (ip2>=16 && ip2<=31){
            if(ip3<=255){
                if (ip4<=255){
                    return 0;
                }
            }
        }
    }
    else if (ip1==192&&CIDR == 16){
        if (ip2==168){
            if(ip3<=255){
                if (ip4<=255){
                    return 0;
                }
            }
        }
    }
    else if (ip1>=224&&ip1<=239&&CIDR == 4){
        if (ip2<=255){
            if(ip3<=255){
                if (ip4<=255){
                    return 1;
                }
            }
        }
    }
    else if (ip1==255&&CIDR==32){
        if (ip2 == 255){
            if(ip3==255){
                if (ip4==255){
                    return 2;
                }
            }
        }
    }
    else if (ip1==0&&CIDR ==8) {
        if (ip2 <= 255){
            if(ip3<=255){
                if (ip4<=255){
                    return 3;
                }
            }
        }
    }
    else {
        return 4;
    }
}
char classeIP(int ip1,int ip2, int ip3, int ip4){
    /**on vérifie chaque condition de départ de Ip1 et on vérifie toujours que les autres champs sont <= à 255**/
    if (ip1<=126){
        if (ip2 <= 255){
            if(ip3<=255){
                if (ip4<=255){
                    return 'A';
                }
            }
        }
    }
    else if (ip1<=191){
        if (ip2 <= 255){
            if(ip3<=255){
                if (ip4<=255){
                    return 'B';
                }
            }
        }
    }
    else if (ip1<=223){
        if (ip2 <= 255){
            if(ip3<=255){
                if (ip4<=255){
                    return 'C';
                }
            }
        }
    }
    else if (ip1<=239){
        if (ip2 <= 255){
            if(ip3<=255){
                if (ip4<=255){
                    return 'D';
                }
            }
        }
    }
    else if (ip1<=255){
        if (ip2 <= 255){
            if(ip3<=255){
                if (ip4<=255){
                    return 'E';
                }
            }
        }
    }
    else {
        return 'Z';
    } 
}

int  getSubString(char *source, char *target,int from, int to)
{
	int length=0;
	int k=0,f=0;
	
	/**On récupère la longueur de la source**/
	while(source[k++]!='\0')
		length++;
	/**On vérfie si les valeurs de découppage du string en sous string sont correctes on retourne si c'est faux**/
	if(from<0 || from>length){
		return 1;
	}
	if(to>length){
		return 1;
	}	
	
	for(k=from,f=0;k<=to;k++,f++){
		target[f]=source[k];
	}
	
	target[f]='\0';
	
	return 0;	
}


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

int charToInt(char c){
	int num = 0;
	num = c - '0';
	return num;
}

