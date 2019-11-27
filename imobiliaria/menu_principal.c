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


// Tela login




//Menu Incial com as opcões
void MenuPrincipal(){

    setlocale(LC_ALL, "Portuguese");
	SetConsoleTitle("IMOBILIARIA");

	printf(	"\n\t\t\t\tIMOBILIARIA \n\n\n"
			"\n\n\t1 -> CLIENTE     ||" "\t4 -> AJUDA\t\t|| "       "\t7 -> SOBRE"
			"\n\n\t2 -> CORRETOR    ||" "\t5 -> UTILIDADES\t\t|| "  "\t0 -> SAIR"
			"\n\n\t3 -> IMÓVEIS    ||" "\t6 -> SIMULAÇÃO\t|| "
			"\n\nEntre com a o desejada: ");
}


//Numero correspodente aa opcao do menu
//1
void MenuCliente(Console){

    // configuracao da tela
    setlocale(LC_ALL, "Portuguese");
    SetConsoleTitle("IMOBILIARIA - ClIENTES");
    SetConsoleTextAttribute(Console, DARK_CYAN);

	printf("\n\n\n\t\tMENU CLIENTE\n\n");

    // Comando para cor de um lado e o que vai ser exbido na tel do outro de acordo com a cor
    SetConsoleTextAttribute(Console, BRANCO);   {}  printf( "\n\t1 <-> ");
    SetConsoleTextAttribute(Console, VERDE);    {}  printf( "Cadastrar Cliente");
    SetConsoleTextAttribute(Console, BRANCO);   {}  printf( "\n\t2 <-> ");
    SetConsoleTextAttribute(Console, VERDE);    {}  printf( "lista de Cliente");
    // SetConsoleTextAttribute(Console, VERDE);    {}  printf( "\n\t3 - ");
    // SetConsoleTextAttribute(Console, BRANCO);   {}  printf( "Editar Cadastro");
    SetConsoleTextAttribute(Console, BRANCO);   {}  printf( "\n\t3 <-> ");
    SetConsoleTextAttribute(Console, VERDE);    {}  printf( "Excluir Cliente");
    SetConsoleTextAttribute(Console, BRANCO);   {}  printf( "\n\t4 <-> ");
    SetConsoleTextAttribute(Console, VERDE);    {}  printf( "Buscar Cliente");
    SetConsoleTextAttribute(Console, BRANCO);   {}  printf( "\n\t0 <-> ");
    SetConsoleTextAttribute(Console, VERMELHO); {}  printf( "Menu Principal");

    SetConsoleTextAttribute(Console, DARK_CYAN);
    printf("\n\nEntre com a opção desejada: ");

    SetConsoleTextAttribute(Console, VERDE);
    ctrNumber(&opcao);

	switch(opcao){
		case '1': // Cadastro Cliente
			CadastroCliente(Console);
			break;
		case '2': // listar Cadastro
			ListarCliente(Console);
			break;
        // case '3': // Editar Cliente
		// 	main();
		// 	break;
        case '3': // Excluir Cliente
			ExcluirCliente();
			break;
        case '4': // Buscar Cliente
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
void MenuCorretor(Console){

    // configuracao da tela
    setlocale(LC_ALL, "Portuguese");
    SetConsoleTitle("IMOBILIARIA - CORRETOR");

    printf("MENU Corretor");

	printf( "\n1 <-> Cadastrar Corretor\n"
	        "2 <-> lista de Corretores\n"
            // "3 - Editar Cadastro\n"
	        "3 <-> Excluir Corretor\n"// estudar se aqui ? o lugar certo de comissao.
            "4 <-> Buscar Corretor\n"
	        "0 - Menu Principal\n");
	printf("Digite o numero da opçção desejada: ");

    ctrNumber(&opcao);

    switch(opcao){
		case '1': // Cadastro Corretor
			CadastroCorretor();
			break;
		case '2': // Listar Cadastro
			ListarCorretor();
			break;
        // case '3': // Editar Corretor
		// 	main();
		// 	break;
        case '3': // Excluir Corretor
			ExcluirCorretor();
			break;
        case '4': // Excluir Corretor
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
void MenuImoveis(Console){

    // configuracao da tela
    setlocale(LC_ALL, "Portuguese");
    SetConsoleTitle("IMOBILIARIA - IMOVEIS");

	printf("MENU IMOVEIS");

	printf( "\n\n1 <-> Cadastro Imóvel\n"
            "2 <-> Lista de Imóveis"
	        // "3 <-> Alterar Imóvel\n"
	        "3 <-> Excluir Imóvel\n"
	        "4 <-> Buscar Imóvel\n"
	        "0 <-> Voltar\n");

    printf("Entre com a opção desejada: ");
    ctrNumber(&opcao);

	switch(opcao){
		case '1': // Cadastro Imóvel
			CadastroImovel();
			break;
		case '2': // Lista com tod imóveis
            ListarImovel(Console);
			break;
        case '3': //Excluir imóvel
			ExcluiImovel();
			break;
        case '4': // Buscar Imóvel
			BuscarImovel();
			main();
			break;
        // case 5: //
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
    SetConsoleTitle("IMOBILIARIA - AJUDA");


    printf("MENU AJUDA\n\n");
    system("pause");
}


//5
void MenuUtilidades(){

    // configuracao da tela
    setlocale(LC_ALL, "Portuguese");

    //título do programa
    SetConsoleTitle("Imobliaria - UTILIDADES");


    printf( "MENU Utilidade"
            "Escolha um programa para abrir\n\n"
            "\t1 <-> Calculadora\n\n"
            "\t2 <-> Bloco de notas\n\n"
            "\t3 <-> WordPad\n\n"
            "\t4 <-> Microsoft Word\n\n"
            "\t5 <-> Microsoft Excel\n\n"
            "\t6 <-> Microsoft chrome\n\n"
            "\t7 <-> Menu Principal\n\n"
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
void MenuSimulado(){

    SetConsoleTitle("IMOBILIARIA - SIMULADO");
	printf("MENU Simulado");

	printf("\n\n(1) <-> Simulacao tabela SAC\n");
	printf("(2) <-> Simulacao tabela Price\n");
	printf("(0) <-> Menu Pricipal\n");
	printf("Entre com a opção desejada: ");
    ctrNumber(&opcao);


	switch(opcao){
		case '1': // tabela SAC
			SimularFinanciamento();
			break;
		case '2': // tabela Price
            main();
			break;
		// case '3': // Voltar
        //     main();
		// 	break;
		case 0: // Voltar Menu Pricipal
            main();
			break;
		default:
			printf("Opção Invalida");
			break;
	}
}


//7
void MenuSobre(Console){


    SetConsoleTextAttribute(Console, BRANCO);

    printf( "A BI tecnology foi formada por dois estudantes e tamebem programadores com grandes sonhos e muita criatividade. "
            "\n\nObrigado por adquirir um dde nossos software, espero que goste e obrigado por nos escolher."
            "\nAtesiosamente Isac e Valdenor CEOs da BI Tecnology.!");
    printf( "\n\n\nUma supresa para você cliente, no software adquirido tem menus secretos que em breve estará disponivel em uma breve atulaização"
            "\nDigite 1,2 ou 3 para acessar esses misteriosos menus");

        ctrNumber(&opcao);
        if(opcao == '1'){
            EditarCliente();
        }else if(opcao == '2'){
            EditarCorretor();
        }else if(opcao == '3'){
            EditarImovel();
        }else{
            SetConsoleTextAttribute(Console, VERMELHO);
            printf("\n\n\t\t\tOpção Invalida!");
            Sleep(500);
            system("cls");
            MenuSobre(Console);
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
            MenuSimulado();
            break;
        case '7': // Menu de Simulado
            opcMenu[0] ='\0';
            system("cls");
            MenuSobre(Console);
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

