//Bibliotecas
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
//#include "funcoes.c"


//Configuracão

// contantes



// variaveis globais, pois foram declaradas fora das fun??es

int opcao = 0;

void MenuPrincipal(){
	//printf("MENU PRINCIPAL \n");


	SetConsoleTitle("IMOBILIÁRIA");

	printf(	"\nIMOBILIARIA \n\n\n"
			"\n1 - CLIENTE"
			"2 - CORRETOR"
			"3 - IMÓVEIS"
			"4 - CALCULO"
			"5 - AJUDA"
			"6 - UTILIDADES"
			"0 - Sair\t"
			"\n\nEntre com a o desejada: ");
		scanf("%i", &opcao);
		system("cls");
		getchar(); // limpar o <enter> do scanf anterior

}



int main(){

	do{
		MenuPrincipal();
        //scanf("%c", &opc);
		//opc=getch();

        do{
            opc=getch();
            if (isdigit(opc)!=0){
                //menor que 1 ja que só pode exibir um caracter
                if (i < 1){
                    opcMenu[i] = opc;
                    i++;//incrementa o índice do vetor de caracteres
                    printf ("%c", opc);//exibe o caractere digitado
                }
            }
            //tecla BACKSPACE é igual a \b ou 8 na tabela ASCII
            else if(opc=='\b'&&i){
                // Dois caracter backspace pois somente com ele andava para o lado e não apagava a letra digitada
                printf("\b \b");
                if(i==1){
                opcMenu[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
                i--;//o índice do vetor de caracteres é decrementado
                }
            }
        }while(opc!=13);
        opc = opcMenu[0];
        i=0;

        switch(opc){
            case '1': // listar Menu Cliente
                system("cls");
                MenuPrincipal();
                printf("teste1");
                break;
            case '2': // listar Menu Corretor
                system("cls");
                MenuPrincipal();
                printf("teste2");
                break;
            case '3': // listar Menu Imoveis
                system("cls");
                MenuPrincipal();
                printf("teste3");
                break;
            case '4': // listar Menu Calculo
                system("cls");
                MenuPrincipal();
                printf("teste4");
                break;
            case '5': // Sair
                ajuda:
                system("cls");
                //MenuAjuda();
                MenuPrincipal();
                printf("teste5");
                break;
            case '6':
                system("cls");
                //MenuUtilidades();
                printf("teste6");
                break;
            case '0':
                system("cls");
                printf("\n\tTem certeza que deseja sair do programa ?[S/N]: ");
                scanf("%c", &sair);
                getchar();
                if(sair == 'S' || sair == 's'){
                    exit(1);
                }else{
                    MenuPrincipal();
                }
                break;
            default:
                printf("\n\t\t\tOpcao Invalida!! Tente denovo!");
                Sleep(1000);
		}
        //getchar();
		system("cls");
	}while(sair !=13);

	return 0;
}
