/*
 * Essa Biblioteca não tem como objetivo substituir a Biblioteca string.h
 * Essa Biblioteca tem como objetivo complementar a Biblioteca string.h
 *
 *
 * Criador: Nihagy Radesh
 * E-mail: michaelneves.v@gmail.com
 *
 *
 * A Biblioteca contem funcões que limitam
 * os caracteres de entrada tanto do tipo char com string
 * contem validacão para entrada de dados
 * como numéricos, letras e caracteres especiais
 *
 * Em atualizacão ...
 */


#ifndef STRING++_H_INCLUDED
#define STRING++_H_INCLUDED

#include <conio.h>



int ctr(char *c){

    //char c;
    char ctrLimitar[2];
    unsigned int i=0, cont=0, enter=0;

    ctrLimitar[0] == "/0";

    do{
        cont++;
        *c =getch();
        if (*c != 13){
            if(i == 0 && *c!='\b' ){
                ctrLimitar[i] = *c;
                i++;
                printf ("%c", *c);
            }
            else if(*c!='\b' && i){
                if(i==1){
                    printf("\b");
                    ctrLimitar[i]='\0';
                    i--;
                    printf ("%c", *c);
                    printf("\b");
                }
            }
            else if(*c=='\b'){
                cont=0;
                enter=0;
                if(i==1){
                    printf("\b \b");
                    i--;
                }else if(i==0){
                    printf(" \b");
                }
            }

        }
        else{
            enter++;
            if(cont==1 && enter==1){
                cont=0;
                enter=0;
                printf(" \b");
            }else{
                if(i==0 && cont>1){
                    i=2;
                }
                else if(i!='\0'){
                    i=2;
                }
            }
        }
    }while (i<2);

    *c = ctrLimitar[0];
    // return ctrLimitar[0];
    return 0;

}


int ctrNumber(char *num){

    unsigned char ctrLimitar[2];
    unsigned int i = 0, cont=0, enter=0;

    do{
        *num=getch();
        if (*num != 13){
            if (isdigit(*num)!=0){
                if (i < 1){
                    ctrLimitar[i] = *num;
                    i++;
                    printf ("%c", *num);
                }
                else if(*num!='\b' && i){
                    if(i==1){
                        printf("\b");
                        ctrLimitar[i]='\0';
                        i--;
                        printf ("%c", *num);
                        printf("\b");
                    }
                }
            }
            else if(*num=='\b'){
                cont=0;
                enter=0;
                if(i==1){
                    printf("\b \b");
                    i--;
                }else if(i==0){
                    printf(" \b");
                }
            }
        }else{
            enter++;
            if(cont==1 && enter==1){
                cont=0;
                enter=0;
                printf(" \b");
            }else{
                if(i==0 && cont>1){
                    i=2;
                }
                else if(i!='\0'){
                    i=2;
                }
            }
        }
    }while(i<2);

    *num = ctrLimitar[0];
    return ctrLimitar[0];
}





#endif // STRING++_H_INCLUDED
