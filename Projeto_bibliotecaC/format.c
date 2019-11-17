

// formatar uma string e criar uma mascara com os caracteres

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>//para utilizar strlen()
#include <conio.h>//para utilizar o getch()
#include <ctype.h>//para utilizar o isdigit()

int main(void){
	char digitado[50];//armazena o que foi digitado pelo usuário
	char c;//armazena cada caractere digitado pelo usuário
    int i=0;//variável para controlar o índice do vetor de caracteres e o último loop

    printf ("Informe uma data (dd/mm/aaaa): ");

    do
	 {
       c=getch();//captura o caractere digitado pelo usuário
	   if (isdigit(c)!=0)//se for um número
	   {
          if (i < 8)//se o índice do vetor for menor que 8
          {
              digitado[i] = c;//armazena no vetor de caracteres
              i++;//incrementa o índice do vetor de caracteres
              printf ("%c", c);//exibe o caractere digitado
              if (i == 2 || i == 4)//se o índice do vetor for igual a 2 ou igual a 4
              {
                  printf ("/");//imprime uma barra
              }
          }
       }
       else if(c==8&&i)//se for pressionada a tecla BACKSPACE e houver caracteres já digitados
       {
          if (i==2 || i==4)//se o índice do vetor for igual a 2 ou igual a 4
          {
              printf("\b \b");//a barra que separa dia, mês e ano é apagada da tela
              digitado[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
              i--;//o índice do vetor de caracteres é decrementado
              printf("\b \b");//o caractere digitado é apagado da tela
          }else{//senão
                digitado[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
                i--;//o índice do vetor de caracteres é decrementado
                printf("\b \b");//o caractere digitado é apagado da tela
          }
       }
    }while(c!=13);//o loop vai ser executado até que a tecla pressionada seja o ENTER (código 13 na tabela ASCII)

    digitado[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string

	printf ("\n\nA data digitada foi ");
    for (i=0;i<strlen(digitado);i++)//o loop vai percorrer todos os caracteres que estão no vetor de caracteres
    {
    	if (i==2 || i==4){//se o índice do vetor for igual a 2 ou igual a 4
    		printf ("/");//imprime uma barra
    		printf ("%c", digitado[i]);//exibe o caractere no índice atual do vetor
		}
		else//senão
		{
    		printf ("%c", digitado[i]);//exibe o caractere no índice atual do vetor
    	}
    }
    printf ("\n\n");

    system ("pause");
    return 0;
}