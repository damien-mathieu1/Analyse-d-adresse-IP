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
*  Nom du fichier : conversionValeur.c                                        *
*                                                                             *
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conversionValeur.h>
int charToInt(char c){
	int num = 0;
	num = c - '0';
	return num;
}