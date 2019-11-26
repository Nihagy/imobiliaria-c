/*
    versão 1.3 Programa Imobilaria

*/

//Bibliotecas
#include <conio.h>
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // importar para usar algun comandos do windows principalmente na parte de utilidades
#include "funcoes.c"
// #include "formatbr.c"



//Configuracão



// contantes



// Variavel Global
char opcao;
// struct {
//     Nome[40];
//     telefonecel[11];
//     Nasc[10];
//     sexo[3];
//     email[30];
//     rg[11];
//     cpf[11];
//     est_civil[10];
// }dados;





// Tela login




//Menu Incial com as opcões
void MenuPrincipal(){
	//printf("IMÓBILIARIA \n");

    setlocale(LC_ALL, "Portuguese");
	SetConsoleTitle("IMOBILIÁRIA");

	printf(	"\n\t\t\t\tIMOBILIARIA \n\n\n"
			"\n\n\t1 - CLIENTE     ||" "\t4 - AJUDA\t|| "       "7 - TESTES"
			"\n\n\t2 - CORRETOR    ||" "\t5 - UTILIDADES\t|| "  "0 - Sair"
			"\n\n\t3 - IMÓVEIS    ||" "\t6 - Simulacao\t|| "
			"\n\nEntre com a o desejada: ");
}


//Numero correspodente aa opcao do menu
//1
void MenuCliente(Console){
    //char opc;
    // configuracao da tela
    setlocale(LC_ALL, "Portuguese");
    SetConsoleTextAttribute(Console, DARK_CYAN); 

	printf("\n\n\n\t\tMENU CLIENTE\n\n");

    SetConsoleTextAttribute(Console, VERDE);    {}  printf( "\n\t1 - ");
    SetConsoleTextAttribute(Console, BRANCO);   {}  printf( "Cadastrar Cliente");
    SetConsoleTextAttribute(Console, VERDE);    {}  printf( "\n\t2 - ");
    SetConsoleTextAttribute(Console, BRANCO);   {}  printf( "lista de Cliente");
    SetConsoleTextAttribute(Console, VERDE);    {}  printf( "\n\t3 - ");
    SetConsoleTextAttribute(Console, BRANCO);   {}  printf( "Editar Cadastro");
    SetConsoleTextAttribute(Console, VERDE);    {}  printf( "\n\t4 - ");
    SetConsoleTextAttribute(Console, BRANCO);   {}  printf( "Excluir Cliente");
    SetConsoleTextAttribute(Console, VERDE);    {}  printf( "\n\t5 - ");
    SetConsoleTextAttribute(Console, BRANCO);   {}  printf( "Buscar Cliente");
    SetConsoleTextAttribute(Console, VERMELHO); {}  printf( "\n\t0 - ");
    SetConsoleTextAttribute(Console, BRANCO);   {}  printf( "Menu Principal");

    SetConsoleTextAttribute(Console, DARK_CYAN); 
    printf("\n\nEntre com a opção desejada: ");

    SetConsoleTextAttribute(Console, VERDE);
    ctrNumber(&opcao);

	switch(opcao){
		case '1': // Cadastro Cliente
			CadastroCliente(Console);
			break;
		case '2': // Editar Cadastro
			RelatorioCliente();
			break;
        case '3': // Buscar Cliente
			main();
			break;
        case '4': // Excluir Cliente
			ExcluirCliente();
			break;
        case '5': // Excluir Cliente
			BuscarCliente(Console);
			break;
		case '0':// Voltar para o Menu Principal
            main();
			break;
		default:
			printf("Opção Invalida!");
			break;
	}

}


//2
void MenuCorretor(){

    // configuracao da tela
    setlocale(LC_ALL, "Portuguese");

    printf("MENU Corretor");

	printf( "\n1 - Cadastrar Corretor\n"
	        "2 - lista de Corretores\n"
            "3 - Editar Cadastro\n"
	        "4 - Excluir Corretor\n"// estudar se aqui ? o lugar certo de comissao.
            "5 - Buscar Corretor\n"
	        "0 - Menu Principal\n");
	printf("Digite o numero da opçção desejada: ");

    ctrNumber(&opcao);

    	switch(opcao){
		case '1': // Cadastro Corretor
			CadastroCorretor();
			break;
		case '2': // Editar Cadastro
			main();
			break;
        case '3': // Buscar Corretor
			main();
			break;
        case '4': // Excluir Corretor
			ExcluirCorretor();
			break;
        case '5': // Excluir Corretor
			BuscarCorretor();
			break;
		case '0':// Voltar para o Menu Principal
            main();
			break;
		default:
			printf("Opção Invalida!");
			break;
	}
}


//3
void MenuImoveis(){

    // configuracao da tela
    setlocale(LC_ALL, "Portuguese");

	printf("MENU IMOVEIS");

	printf( "\n\n(1) - Cadastro Imóvel\n"
	        "(2) - Buscar Imóvel\n"
	        "(3) - Alteracao no Imóvel\n"
	        "(4) - Excluir Imóvel\n"
	        "(0) - Voltar\n");

    printf("Entre com a opcao desejada: ");
    ctrNumber(&opcao);

	switch(opcao){
		case '1': // Cadastro Imóvel
			CadastroImovel();
			break;
		case '2': // Buscar Imóvel
			BuscarCadastroImovel();
			break;
        case '3': // Alteracao Cadastro
			main();
			break;
        case '4': // Excluir Imóvel
			main();
			break;
        // case 5: // Leitura Cadastro
		// 	MenuPrincipal();
		// 	break;
		case '0': //Voltar
			break;
		default:
			printf("Opcao invalida");
			break;
	}
}


//4
void MenuAjuda(){

    // configuracao da tela
    setlocale(LC_ALL, "Portuguese");


    printf("MENU AJUDA\n\n");
    system("pause");
}


//5
void MenuUtilidades(){

    // configuracao da tela
    setlocale(LC_ALL, "Portuguese");

    //título do programa
    SetConsoleTitle("Imobliaria - Utilidades");
    

    printf( "MENU Utilidade"
            "Escolha um programa para abrir\n\n"
            "\t1 - Calculadora\n\n"
            "\t2 - Bloco de notas\n\n"
            "\t3 - WordPad\n\n"
            "\t4 - Microsoft Word\n\n"
            "\t5 - Microsoft Excel\n\n"
            "\t6 - Microsoft chrome\n\n"
            "\t7 - Menu Principal\n\n"
            "Obs.: Algumas opcoes acima só irá abrir se o mesmo estiver instalado no computador.\n\n");


    //tenta implementar o gotoxy da biblioteca conio.h
    printf ("Digite a opção desejada: ");

    ctrNumber(&opcao);
    switch (opcao){
        case '1':
            system ("start calc");
            system("cls");
            MenuUtilidades();
            break;
        case '2':
            system ("start notepad");
            system("cls");
            MenuUtilidades();
            break;
        case '3':
            system ("start write");
            system("cls");
            MenuUtilidades();
            break;
        case '4':
            system ("start winword");
            system("cls");
            MenuUtilidades();
            break;
        case '5':
            system ("start excel");
            system("cls");
            MenuUtilidades();
            break;
        case '6':
            system ("start chrome");
            system("cls");
            MenuUtilidades();
            break;
        case '0':
            system("cls");
            main();
            break;
        default:
            printf ("\n\nDesculpe, esta opção é inválida.\n\n");
            break;
    }
}


//6
void MenuTeste(){

    // configuracao da tela
    setlocale(LC_ALL, "Portuguese");


    printf("MENU Teste");
    system("pause");
}


//7
void MenuSimulado(){
	printf("MENU Simulado");

	printf("\n\n(1) - Simulacao financiamento\n");
	printf("(2) - Comissao por locacao\n");
	printf("(3) - Comissao por venda\n");
	printf("(0) - Voltar\n");
	printf("Entre com a opção desejada: ");
	scanf("%i", &opcao);
	getchar(); // limpar o <enter> do scanf anterior
	system("cls");

	switch(opcao){
		case 1: // Simula??o financiamento
			SimularFinanciamento();
			break;
		case 0: // Voltar
            main();
			break;
		default:
			printf("Op??o inv?lida");
			break;
	}
}


//Redireciona para qual menu vai acessar de acordo com as opcão e todos retornam para o main
int main(){

    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(Console, BRANCO);

    char sair;
    char opcMenu[2];
    char opc;
    // i de indice
    int i = 0, cont=0, enter=0;

    // configuracao da tela
    setlocale(LC_ALL, "Portuguese");

    system("cls");
    MenuPrincipal();
    SetConsoleTextAttribute(Console, VERDE);
    do{
        cont++;
        opc=getch();
        if (opc != 13){
            if (isdigit(opc)!=0 || opc == ';'){
                if (opc == ';'){
                    goto ajuda;
                }else if (isdigit(opc)!=0){
                    if (i < 1){
                        opcMenu[i] = opc;
                        i++;
                        printf ("%c", opc);
                    }
                    else if(opc!='\b' && i){
                        if(i==1){
                            printf("\b");
                            opcMenu[i]='\0';
                            i--;
                            printf ("%c", opc);
                            printf("\b");
                        }
                    }
                }
            }
            else if(opc=='\b'){
                cont=0;
                enter=0;
                if(i==1){
                    printf("\b \b");
                    i--;
                }else if(i==0){
                    printf(" \b");
                }
            }
        }
        else{
            enter++;
            if(cont==1 && enter==1){
                cont=0;
                enter=0;
                printf(" \b");
            }else{
                if(i==0 && cont>1){
                    i=2;
                }
                else if(i!='\0'){
                    i=2;
                }
            }
        }
    }while(i<2);
    i=0;

    switch(opcMenu[0]){
        case '1': // Menu Cliente
            opcMenu[0] ='\0'; // Deixando o valor nulo para quando retornar ao menu principal não acessar nenhum outro menu quando apertar o enter
            system("cls");
            MenuCliente(Console);
            break;
        case '2': // Menu Corretor
            opcMenu[0] ='\0';
            system("cls");
            MenuCorretor();
            break;
        case '3': // Menu Imoveis
            opcMenu[0] ='\0';
            system("cls");
            MenuImoveis();
            break;
        case '4': // Menu Ajuda
            opcMenu[0] ='\0';
            ajuda:
            system("cls");
            MenuAjuda();
            break;
        case '5': // Menu Utilidade
            opcMenu[0] ='\0';
            system("cls");
            MenuUtilidades();
            break;
        case '6': // Menu de Teste
            opcMenu[0] ='\0';
            system("cls");
            MenuTeste();
            printf("teste6");
            break;
        case '7': // Menu de Simulado
            opcMenu[0] ='\0';
            system("cls");
            MenuSimulado();
            break;
        case '0': // sair
            system("cls");
            do{
                printf( "\n\n\tTem certeza que deseja sair do programa ?\n"
                        "\tdigite 1 ou Sim para Sair\n"
                        "\t2 ou Não para voltar ao Menu"
                        "\n\nDigite a opcao escolhida?");
                ctrAlnum(&sair);

                    if(sair== '1' || tolower(sair)== 's'){
                        printf ("%c", sair);
                        exit(1);
                    }else if(sair== '2' || tolower(sair)== 'n'){
                        printf ("%c", sair);
                        system("cls");
                        MenuPrincipal();
                        break;
                    }
                    else{
                        printf("\n\n\n\t\t\tOpcao Invalida!! Tente denovo!");
                        Sleep(1000);
                        system("cls");
                    }
            }while(sair!= 's' || sair!= 'n');
            break;
        default:
            printf("\n\t\t\tOpcao Invalida!! Tente denovo!");
            Sleep(1000);
            system("cls");
            main();
            break;
    }

	return 0;
}
