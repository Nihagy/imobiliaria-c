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

/*
void strPlusAl(char *var, int tam){

    char c;
    int i=0;
    do{
        c=getch();
        if(i < tam-1){
            if (isalpha(c) !=0 || c == 32){
                var[i] = c;
                i++;
                printf ("%c", c);
            }
            else if(c=='\b'&&i){
                var[i]='\0';
                i--;
                printf("\b \b");
            }
        }
        else if(c=='\b'&&i){
            var[i]='\0';
            i--;
            printf("\b \b");
        }
    }while(c!=13);

    var[i]='\0';
}


void strPlusNum(char *var, int tam){

    char c;
    int i=0;
    do{
        c=getch();
        if(i < tam-1){
            if (isdigit(c) !=0 || c == 32){
                var[i] = c;
                i++;
                printf ("%c", c);
            }
            else if(c=='\b'&&i){
                var[i]='\0';
                i--;
                printf("\b \b");
            }
        }
        else if(c=='\b'&&i){
            var[i]='\0';
            i--;
            printf("\b \b");
        }
    }while(c!=13);

    var[i]='\0';
}


void strPlus(char *var, int tam){

    char c;
    int i=0;
    do{
        c=getch();
        if(i < tam-1){
            if (c !=8 || c == 32){
                var[i] = c;
                i++;
                printf ("%c", c);
            }
            else if(c==8&&i){
                var[i]='\0';
                i--;
                printf("\b \b");
            }
        }
        else if(c==8&&i){
            var[i]='\0';
            i--;
            printf("\b \b");
        }
    }while(c!=13);

    var[i]='\0';
}

*/


void strPlusAlnum(char *var, int tam){

    char c;
    int i=0;
    do{
        c=getch();//captura o caractere digitado pelo usuário
        if(i < tam-1){
            if (isalnum(c) !=0 || c == 32){
                var[i] = c;//armazena no vetor de caracteres
                i++;//incrementa o índice do vetor de caracteres
                printf ("%c", c);//exibe o caractere digitado
            }
            else if(c==8&&i){
                var[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
                i--;//o índice do vetor de caracteres é decrementado
                printf("\b \b");//o caractere digitado é apagado da tela
            }
        }
        else if(c==8&&i){
            var[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
            i--;//o índice do vetor de caracteres é decrementado
            printf("\b \b");//o caractere digitado é apagado da tela
        }
    }while(c!=13);//o loop vai ser executado até que a tecla pressionada seja o ENTER (código 13 na tabela ASCII)

    var[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
}


int main(){
	char nome[11];
	char sobrenome[11];
    int tam;

    tam = strlen(nome);
    printf ("\nInforme seu nome: ");
    printf ("%i\n\n", tam);

	printf("\nInforme o nome: ");
	strPlusAlnum(&nome, 11);

	printf("\nInforme o sobrenome: ");
	strPlusAlnum(sobrenome, 11);

	printf("\n\nNome: %s\nSobrenome: %s\n", nome, sobrenome);

    tam = strlen(nome);
    printf ("\nInforme seu nome: ");
    printf ("%i\n\n", tam);

    tam = strlen(sobrenome);
    printf ("\nInforme seu nome: ");
    printf ("%i\n\n", tam);

	getch();
	return 0;
}
