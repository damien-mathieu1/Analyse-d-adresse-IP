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
*  Nom du fichier : extraireChamp.c                                           *
*                                                                             *
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <extraireChamp.h>
int  extraireChamp(char *source, char *target,int from, int to)
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
	
	//on met la valeur de fin de chaine a la fin de la chaine
	target[f]='\0'; 
	
	return 0;	
}