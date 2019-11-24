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

/*

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

*/
// ================================


// int main(){
//     FILE *f;
//     f = fopen("arquivo.txt", "w");
//     if(f == NULL){
//         printf("Erro na abertura\n");
//         system("pause");
//         exit(1);
//     }
//     char texto[20] = "Meu programa em C";
//     int i;
//     //grava a string, caractere a cararactere
//     for(i=0;i<strlen(texto); i++)
//         fputc(texto[1], f);
//     fclose(f);

//     system("pause");
//     return 0;
// }


// int main(){

//     FILE *f;
    
//     // leitura de arquivo texto
//     f = fopen("arquivo.txt", "r");
//     // escrita de arquivo texto
//     f = fopen("arquivo.txt", "w");
//     // leitura de arquivo binario
//     f = fopen("arquivo.txt","rb";
//     // escrita de arquivos binario
//     f = fopen("arquivo.txt", "wb");

//     system("pause")
//     return 0;
// }

//============================================================================

// limitar string

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>//para utilizar o getch()
#include <ctype.h>//para utilizar o isdigit()
 
int main(void)
{
    char digitado[50];//armazena o que foi digitado pelo usuário
    char c;//armazena cada caractere digitado pelo usuário
    int i=0;//variável para controlar o índice do vetor de caracteres
   
    printf ("Informe seu nome: ");
   
        do
        {
       c=getch();//captura o caractere digitado pelo usuário
           if (isalpha(c)!=0 || c==32)//se for uma letra
           {
          digitado[i] = c;//armazena no vetor de caracteres
          i++;//incrementa o índice do vetor de caracteres
          printf ("%c", c);//exibe o caractere digitado
       }
       else if(c==8&&i)//se for pressionada a tecla BACKSPACE e houver caracteres já digitados
       {
          digitado[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
          i--;//o índice do vetor de caracteres é decrementado
          printf("\b \b");//o caractere digitado é apagado da tela
       }
    }while(c!=13);//o loop vai ser executado até que a tecla pressionada seja o ENTER (código 13 na tabela ASCII)
   
    digitado[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
   
    printf ("\n\nSeja bem-vindo, %s\n\n", digitado);
   
        system ("pause");
    return 0;
}