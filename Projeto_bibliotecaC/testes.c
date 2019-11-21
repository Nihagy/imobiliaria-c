// Arquivo para realização de teste de funcões para implementar na biblioteca




/* Ideias para Desenvolver
 *
 * mascara para Rg
 * mascara para cpf
 * limitar string *** Prioridade
 * funcao para ler e limitar o tipo char *** Prioridade
 * ...
 * ...
 * ...
 * ...
 *
 * Alguma ideia ainda irá de sugir
 */

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

// int str(char *vetor){

//     unsigned int tam = strlen(*vetor);
//     unsigned int i=0;
    
//     do{

//     }while();


// }


//====================//====================//=================//

int main(){

    char c;
    char cpf[15];
    unsigned int i=0;

    printf ("digite um cpf: ");

    do{
        c=getch();
        if (isdigit(c)!=0){
            if (i <= 13){
                cpf[i] = c;
                i++;
                printf ("%c", c);
            }
        if(i==3 || i==7 || i==11){
            if(i==11){
                cpf[i]='-';
                printf ("%c", cpf[i]);
                i++;
            }else{
                cpf[i]='.';
                printf ("%c", cpf[i]);
                i++;
            }
        }
        }
        else if(c=='\b' && i){
            if (i==3 || i==7 || i==11){
                printf("\b \b");
                i--;
                //cpf[i]='\0';
                printf("\b \b");
                i--;
            }
            else{
                cpf[i]='\0';
                printf("\b \b");
                i--;
            }
        }
    }while(c!=13);

// teste para verificar na tela
    // cpf[i]='\0';

    // printf ("\n\nO cpf digitada foi: ");
    // puts(cpf);
    // printf("\n%s", cpf);
    // printf("\n\n");
    // system("pause");

    return 0;

}


// ================================


/*

    char cpf[2];
    unsigned int ind=0, cont;;

    
    do{

        gets(cpf[ind]);

        if(cpf[ind] != 13){
            if (ind < 1){
                ind++;
                printf ("%c", cpf[ind]);
            }
        }
        else if(cpf[ind] == '\b'&&ind){
            printf("\b \b");
            if(ind==1){
            cpf[ind] ='\0';
            ind--;
            }
        }

    }while(*c!=13);

    cpf[1] = '/0';


*/