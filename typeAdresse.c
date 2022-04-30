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
*  Nom du fichier : typeAdresse.c                                             *
*                                                                             *
******************************************************************************/
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