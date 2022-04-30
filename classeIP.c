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
*  Nom du fichier : classeIP.c                                                *
*                                                                             *
******************************************************************************/
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