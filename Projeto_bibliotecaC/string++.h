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

int ctrNumber(char *op){

    unsigned char ctrLimitar[2];
    unsigned int i = 0;

    do{
        *op=getch();
        if (isdigit(*op)!=0){
            if (i < 1){
                ctrLimitar[i] = *op;
                i++;
                printf ("%c", *op);
            }
        }
        else if(*op=='\b'&&i){
            printf("\b \b");
            if(i==1){
            ctrLimitar[i]='\0';
            i--;
            }
        }
    }while(*op!=13);
    *op = ctrLimitar[0];
    return ctrLimitar[0];
}

#endif // STRING++_H_INCLUDED
