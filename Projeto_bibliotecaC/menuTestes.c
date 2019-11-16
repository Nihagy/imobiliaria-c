//Bibliotecas
#include <conio.h>
#include <ctype.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "testando.c"


//Configuracão



// contantes
#define TAMANHO 10



// variaveis globais



int opcao;


void MenuPrincipal(){
	//printf("MENU PRINCIPAL \n");

    setlocale(LC_ALL,"");
	SetConsoleTitle("IMOBILIARIA");

	printf(	"\nIMOBILIARIA \n\n\n"
			"\n1 - CLIENTE"
			"2 - CORRETOR"
			"3 - IMÓVEIS"
			"4 - CALCULO"
			"5 - AJUDA"
			"6 - UTILIDADES"
			"0 - Sair\t"
			"\n\nEntre com a o desejada: ");
		// scanf("%i", &opcao);
		// system("cls");
		// getchar(); // limpar o <enter> do scanf anterior
    	//system("pause");
}


int main(){

    //MenuPrincipal();
    char sair;
    //char opcMenu[10];
    char opc;
    // i de indice
    //int i = 0;

	do{
		MenuPrincipal();
        printf("\noi\n%c\n", opc);
        //scanf("%c", &opc);
		//opc=getch();

        opc = crtNumber(opc);

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
