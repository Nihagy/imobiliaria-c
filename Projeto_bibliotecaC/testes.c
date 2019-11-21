// Arquivo para realização de teste de funcões para implementar na biblioteca




/* Ideias para Desenvolver
 *
 * mascara para Rg
 * mascara para rg
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
    char rg[13];
    unsigned int i=0, cont;

    printf ("digite um rg: ");
    //scanf("%c", c);

    do{
        c=getch();
        if (isdigit(c)!=0 ||  c==-32){
            if (i <= 11 && c!=-32){
                rg[i] = c;
                i++;
                printf ("%c", c);
            }
            // else if(c==-32 ){
            //     printf("%i",c);
            //     printf("%i",c);
            //     if(c=='K'){
            //         printf("%i",c);
            //         printf("\b");
            //         i--;
            //     }
            // }
            if(i==2 || i==6 || i==10){
                if(i==10){
                    rg[i]='-';
                    printf ("%c", rg[i]);
                    i++;
                }else if(i==2 || i==6){
                    rg[i]='.';
                    printf ("%c", rg[i]);
                    i++;
                }
            }
        }
        else if(c=='\b' && i){
            if (i==3 || i==7 || i==11){
                printf("\b \b");
                i--;
                rg[i]='\0';
                printf("\b \b");
                i--;
            }
            else{
                rg[i]='\0';
                printf("\b \b");
                i--;
            }
        }
        if(c==-32&&i>=0){
            // for(cont=0; cont<i;cont++){
                do{
                    printf(" \b");
                    //printf("\b");
                    i--;
                }while(i==0&&c==-32);
                //printf("Texto: %c",c);
                //printf("%i",i);
                //printf("\b");
                //printf("\b");
                //i--;
            //}
            cont=0;
        }
    }while(c!=13);

// teste para verificar na tela
    // rg[i]='\0';

    // printf ("\n\nO rg digitada foi: ");
    // puts(rg);
    // printf("\n%s", rg);
    // printf("\n\n");
    // system("pause");

    return 0;

}


// ================================


/*

    char rg[2];
    unsigned int ind=0, cont;;


    do{

        gets(rg[ind]);

        if(rg[ind] != 13){
            if (ind < 1){
                ind++;
                printf ("%c", rg[ind]);
            }
        }
        else if(rg[ind] == '\b'&&ind){
            printf("\b \b");
            if(ind==1){
            rg[ind] ='\0';
            ind--;
            }
        }

    }while(*c!=13);

    rg[1] = '/0';


*/
