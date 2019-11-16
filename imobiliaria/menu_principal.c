//Bibliotecas
#include <conio.h>
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//#include "funcoes.c"



//Configuracão



// contantes


// Variavel Global
int opcao = 0;



void MenuPrincipal(){
	//printf("MENU PRINCIPAL \n");

    //setlocale(LC_ALL, "Portuguese");
	//SetConsoleTitle("IMOBILIÁRIA");

	printf(	"\nIMOBILIARIA \n\n\n"
			"\n1 - CLIENTE || "
			"2 - CORRETOR || "
			"3 - IMÓVEIS || "
			"4 - CALCULO || "
			"5 - AJUDA || "
			"6 - UTILIDADES || "
            "7 - TESTES || "
			"0 - Sair"
			"\n\nEntre com a o desejada: ");
}



void menuCliente(){
	printf("MENU CLIENTE");
	
	printf("\n\n(1) - Cadastrar Cliente\n");
	printf("(2) - Editar de cadastro\n");
	printf("(4) - Excluir Cliente\n");
	printf("(5) - Visualizar Cadastro\n");
	printf("(0) - Voltar\n");
	printf("Entre com a opção desejada: ");
	scanf("%i", &opcao);
	system("cls");
	getchar(); // limpar o <enter> do scanf anterior

	switch(opcao)
	{
		case 1: // Cadastro Cliente
			MenuPrincipal();
			break;
		case 2: // Leitura Cadastro
			MenuPrincipal();
			break;
		case 0:// Voltar
			break;
		default:
			printf("Op??o Inv?lida!");
			break;
	}
}



int main(){

    char sair;
    char opcMenu[2];
    char opc;
    // i de indice
    int i = 0;


	do{
		MenuPrincipal();

        do{
            opc=getch();
            if (isdigit(opc)!=0 || opc == ';'){
                if (opc == ';')
                {
                goto ajuda;
                }else if (i < 1){//menor que 1 ja que só pode exibir um caracter
                    opcMenu[i] = opc;
                    i++;//representa o indice(posição) do vetor
                    printf ("%c", opc);//exibe o caractere digitado
                }
            }
            //tecla BACKSPACE é igual a '\b' ou 8 na tabela ASCII
            else if(opc=='\b'&&i){
                // Dois caracter backspace pois somente com um ele andava para o lado e não apagava a letra digitada
                printf("\b \b");
                if(i==1){
                // para saber o fim de uma string tem que ter o '\0' por isso foi inserida na posição logo após o primeiro caracter fazendo que esse seja o fim;
                opcMenu[i]='\0';
                i--;
                }
            }
        }while(opc!=13);
        //opc = opcMenu[0];
        i=0;

        switch(opcMenu[0]){
            case '1': // Menu Cliente
                opcMenu[0] ='\0'; // Deixando o valor nulo para quando retornar ao menu principal não acessar nenhum outro menu quando apertar o enter
                system("cls");
                menuCliente();
                //printf("teste1");
                break;
            case '2': // Menu Corretor
                opcMenu[0] ='\0';
                system("cls");
                MenuPrincipal();
                printf("teste2");
                break;
            case '3': // Menu Imoveis
                opcMenu[0] ='\0';
                system("cls");
                MenuPrincipal();
                printf("teste3");
                break;
            case '4': // Menu Calculo
                opcMenu[0] ='\0';
                system("cls");
                MenuPrincipal();
                printf("teste4");
                break;
            case '5': // Menu Ajuda
                opcMenu[0] ='\0';
                ajuda:
                system("cls");
                //MenuAjuda();
                MenuPrincipal();
                printf("teste5");
                break;
            case '6': // Menbu Utilidade
                opcMenu[0] ='\0';
                system("cls");
                //MenuUtilidades();
                printf("teste6");
                break;
            case '7': // Menbu de Testes
                opcMenu[0] ='\0';
                system("cls");
                //MenuTests();
                printf("teste7");
                break;
            case '0': // sair
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
        //printf("\noi\n%c\n\n", opcMenu[0]);
	}while(sair !=13);
	return 0;
}
