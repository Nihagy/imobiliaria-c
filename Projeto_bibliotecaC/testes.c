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
    char ctrLimitar[2];
    unsigned int i=0, cont=0, enter=0;

    ctrLimitar[0] == "/0";

    printf ("digite uma letra: ");

    do{
        cont++;
        c =getch();
        if (c != 13){
            if(i == 0 && c!='\b' ){
                ctrLimitar[i] = c;
                i++;
                //printf("\b");
                printf ("%c", c);
            }
            else if(c!='\b' && i){
                if(i==1){
                    printf("\b");
                    ctrLimitar[i]='\0';
                    i--;
                    printf ("%c", c);
                    printf("\b");
                }
            }
            else if(c=='\b'){
                cont=0;
                enter=0;
                if(i==1){
                    printf("\b \b");
                    i--;
                }else if(i==0){
                    //cont=0;
                    printf(" \b");
                }
            }

        }
        else{
            //printf("\n%i\n", cont);
            enter++;
            if(cont==1 && enter==1){
                cont=0;
                enter=0;
                printf(" \b");
            }else{
                if(i==0 && cont>1){
                    //printf("\n1\n");
                    i=2;
                }
                else if(i!='\0'){
                    //printf("\n2\n");
                    i=2;
                }
            }
        }
        // printf("\n%c\n", ctrLimitar[0]);
        // printf("%c\n", ctrLimitar[1]);
        // printf("%c\n", c);

    }while (i<2);

    // *c = ctrLimitar[0];
    // return ctrLimitar[0];
    return 0;

}


// ================================


/*

    char ctrLimitar[2];
    unsigned int ind=0, cont;;

    
    do{

        gets(ctrLimitar[ind]);

        if(ctrLimitar[ind] != 13){
            if (ind < 1){
                ind++;
                printf ("%c", ctrLimitar[ind]);
            }
        }
        else if(ctrLimitar[ind] == '\b'&&ind){
            printf("\b \b");
            if(ind==1){
            ctrLimitar[ind] ='\0';
            ind--;
            }
        }

    }while(*c!=13);

    ctrLimitar[1] = '/0';


*/