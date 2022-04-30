# Analyse d'adresse IP
Ce projet a été réalisé en groupe de 4, dans le cadre d'un projet scolaire pour l'IUT Informatique de Toulouse :  
* CAUJOLLE Virgile  
* PATOUT Tristan  
* GUISEPPIN Léo  
* MATHIEU Damien  

#### !IMPORTANT! 
Nous n'avons pas réussi à mener à bien le projet malgré notre bonne volonté à le réaliser. Le programme ne compile pas.  

CEPENDANT, nous avons tout de même tenu à rendre notre travail bien que cela ne fonctionne pas. Nous avons essayé de développer les fonctions
permettant l'analyse d'une adresse IP.  

# DESCRIPTION DES FONCTIONS :   

## Fonctions pour la lecture de la saisie utilisateur :
> fichier : lecture.c 

### -int lire(char \*chaine, int longueur)  

La fonction lire permet de récupérer la saisie utilisateur d'une manière sécuriser et vide le buffer une fois la saisie effectué pour ne pas surcharger le buffer.  
Elle prend 2 paramètres un pointeur sur une chaine qui contiendra la saisie, et la longueur max de la chaine que l'on doit saisir.  
Elle renvoie un état de sortie qui prend la forme d'un entier.

### -void clearBuffer()

La fonction clearBuffer ne prend pas de paramètre en entrée et ne renvoie rien car elle permet de vider le buffer une fois une saisie effectuer dans la fonction lire.
  
### -int verifierChaine(char \*ip)

La fonction verifierChaine a pour but de vérifier si le format de l'adresse IP saisie est bien concordant à ce que peut être une adresse IP.
Elle prend en paramètre un pointeur vers une chaine de caractère (celle saisie par l'utilisateur) et renvoie un entier correpondant à l'état, 0 si l'adresse IP n'est pas
concordante a une bonne adresse et 1 autrement.

## Fonctions pour l'analyse des champs de l'adresse IP
> fichier : extraireChamp.c, conversionValeur.c

### -int  extraireChamp(char \*source, char \*target,int from, int to)

La fonction extraireChamp prend 4 paramètres d'entrée et renvoie un paramètre d'état sous forme d'entier 0 : bon, 1 : pas bon. Cette fonction extrait une partie d'une chaine de caractère et l'ajoute à une autre chaine de caractère.
Les deux premiers paramètres sont des pointeurs sur des chaines de caractère, l'un pour la chaine source et l'autre pour la chaine destinataire. 
Les deux derniers paramètres sont les délimiteurs du point de départ de l'extraction au point de fin de l'extraction.

### -int charToInt(char c)

La fonction charToInt permet de changer une chaine de caractère en 1 entier, elle prend une chaine de caractère en entrée et renvoie un int correspondant à la valeur numérique de la chaine en entrèe.

## Fonctions pour l'analyse du type et de la classe de l'adresse IP

###
