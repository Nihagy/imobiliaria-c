/*
    vers�o 2.0 Programa Imobilaria

*/


//Bibliotecas
#include <conio.h>
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // importar para usar algun comandos do windows principalmente na parte de utilidades e as cores
#include "funcoes.c"
//#include "formatbr.c"
#include "string++.h"



//Configurac�o



// Variavel Global
char opcao;



//Menu Incial com as opc�es
void MenuPrincipal(Console){
    // Nome que aparece no topo da janela
	SetConsoleTitle("IMOBILIARIA");
    printf( "\n\t\t\t\tIMOBILIARIA");

    SetConsoleTextAttribute(Console, VERDE);
	printf( "\n\n\n\t========================= BAIXADA BROKERS =========================\n");
    SetConsoleTextAttribute(Console, BRANCO);

	printf(	"\n\n\t1 -> CLIENTE     ||" "\t4 -> SIMULA��O\t\t|| "     "\t7 -> AJUDA"
			"\n\n\t2 -> CORRETOR    ||" "\t5 -> UTILIDADES\t\t|| "  "\t8 -> SOBRE"
			"\n\n\t3 -> IM�VEIS     ||"  "\t6 -> USUARIO\t\t|| "     "\t0 -> SAIR");
    SetConsoleTextAttribute(Console, VERDE);
    printf( "\n\n\t===================================================================\n");
    SetConsoleTextAttribute(Console, BRANCO);
    printf("\nEntre com a o desejada: ");
}


//Numero correspodente aa opcao do menu
//1
void MenuCliente(Console){

    // configuracao da tela
    SetConsoleTitle("IMOBILIARIA - CLIENTES");
    SetConsoleTextAttribute(Console, BRANCO);

	printf("\n\n\n\t\t============= MENU CLIENTE ==============\n\n");

    // Comando para cor de um lado e o que vai ser exbido na tela do outro de acordo com a cor
    SetConsoleTextAttribute(Console, VERDE);
    printf( "\n\t\t\t1 <-> Cadastrar Cliente"
            "\n\t\t\t2 <-> lista de Cliente"
            "\n\t\t\t3 <-> Excluir Cliente"
            "\n\t\t\t4 <-> Buscar Cliente");
    // SetConsoleTextAttribute(Console, VERDE);    {}  printf( "\n\t3 - ");
    // SetConsoleTextAttribute(Console, BRANCO);   {}  printf( "Editar Cadastro");
    SetConsoleTextAttribute(Console, VERMELHO);
    printf( "\n\t\t\t0 <-> Menu Principal");

    SetConsoleTextAttribute(Console, BRANCO);
    printf( "\n\n\t\t=========================================");

        printf("\n\nEntre com a op��o desejada: ");
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
        // 	menu(Console);
        // 	break;
        case '3': // Excluir Cliente
            ExcluirCliente(Console);
            break;
        case '4': // Buscar Cliente
            BuscarCliente(Console);
            break;
        case '0':// Voltar para o Menu Principal
            menu(Console);
            break;
        default:
            SetConsoleTextAttribute(Console, VERMELHO);
            printf("\nOp��o Inv�lida!\n");
            Sleep(500);
            system("cls");
            MenuCliente(Console);
            break;
    }
}


//2
void MenuCorretor(Console){

    // configuracao da tela
    SetConsoleTitle("IMOBILIARIA - CORRETOR");

    SetConsoleTextAttribute(Console, BRANCO);

	printf("\n\n\n\t\t============ MENU CORRETOR ============\n\n");
    SetConsoleTextAttribute(Console, VERDE);

    printf( "\n\t\t\t1 <-> Cadastrar Corretor"
            "\n\t\t\t2 <-> lista de Corretor"
            "\n\t\t\t3 <-> Excluir Corretor"
            "\n\t\t\t4 <-> Buscar Corretor");
    //printf( "\n\t3 - "  "Editar Cadastro");
    SetConsoleTextAttribute(Console, VERMELHO);
    printf( "\n\t\t\t0 <-> Menu Principal");

    SetConsoleTextAttribute(Console, BRANCO);
    printf( "\n\n\t\t=========================================");
    printf("\n\nEntre com a op��o desejada: ");
    SetConsoleTextAttribute(Console, VERDE);
    ctrNumber(&opcao);

    switch(opcao){
        case '1': // Cadastro Corretor
            CadastroCorretor(Console);
            break;
        case '2': // Listar Cadastro
            ListarCorretor(Console);
            break;
        // case '3': // Editar Corretor
        // 	menu(Console);
        // 	break;
        case '3': // Excluir Corretor
            ExcluirCorretor(Console);
            break;
        case '4': // Excluir Corretor
            BuscarCorretor(Console);
            break;
        case '0':// Voltar para o Menu Principal
            menu(Console);
            break;
        default:
            SetConsoleTextAttribute(Console, VERMELHO);
            printf("\nOp��o Inv�lida!\n");
            Sleep(500);
            system("cls");
            MenuCorretor(Console);
            break;
    }
}


//3
void MenuImoveis(Console){

    // configuracao da tela
    SetConsoleTitle("IMOBILIARIA - IMOVEIS");
    SetConsoleTextAttribute(Console, BRANCO);

	printf("\n\n\n\t\t============ MENU IM�VEIS ============\n\n");

	printf( "\n\t\t\t1 <-> Cadastro Im�vel\n"
            "\n\t\t\t2 <-> Lista de Im�veis\n"
	        // "3 <-> Alterar Im�vel\n"
	        "\n\t\t\t3 <-> Excluir Im�vel\n"
	        "\n\t\t\t4 <-> Buscar Im�vel\n"
	        "\n\t\t\t0 <-> Voltar");
    printf( "\n\n\t\t========================================");
    printf("\n\nEntre com a op��o desejada: ");

    SetConsoleTextAttribute(Console, VERDE);
    ctrNumber(&opcao);

    switch(opcao){
        case '1': // Cadastro Im�vel
            CadastroImovel(Console);
            break;
        case '2': // Lista com tod im�veis
            ListarImovel(Console);
            break;
        case '3': //Excluir im�vel
            ExcluirImovel(Console);
            break;
        case '4': // Buscar Im�vel
            BuscarImovel(Console);
            break;
        // case 5: //
        // 	MenuPrincipal();
        // 	break;
        case '0': //Voltar
            menu(Console);
            break;
        default:
            SetConsoleTextAttribute(Console, VERMELHO);
            printf("\nOp��o Inv�lida!\n");
            Sleep(500);
            system("cls");
            MenuImoveis(Console);
            break;
    }
}


//4
void MenuSimulado(Console){

    SetConsoleTitle("IMOBILIARIA - SIMULADO");

    SetConsoleTextAttribute(Console, BRANCO);

	printf("\n\n\n\t\t============ MENU SIMULACAO ============\n\n");
	printf("\n\t\t\t1 <-> Simulacao tabela SAC\n");
	printf("\n\t\t\t2 <-> Simulacao tabela Price(Bloqueado)\n");
	printf("\n\t\t\t0 <-> Menu Pricipal\n");
    printf( "\n\t\t=========================================");
	printf("\n\nEntre com a op��o desejada: ");

    SetConsoleTextAttribute(Console, VERDE);
    ctrNumber(&opcao);
    switch(opcao){
        case '1': // tabela SAC
            SimularFinanciamento(Console);
            break;
        case '2': // tabela Price
            menu(Console);
            break;
        // case '3': // Voltar
        //     menu(Console);
        // 	break;
        case '0': // Voltar Menu Pricipal
            menu(Console);
            break;
        default:
            SetConsoleTextAttribute(Console, VERMELHO);
            printf("\nOp��o Inv�lida!\n");
            Sleep(500);
            system("cls");
            MenuSimulado(Console);
            break;
    }
}


//5
void MenuUtilidades(Console){

    // configuracao da tela
    SetConsoleTitle("Imobliaria - UTILIDADES");
    SetConsoleTextAttribute(Console, VERDE);

    printf( "\t\t============ MENU Utilidade ============");

    SetConsoleTextAttribute(Console, BRANCO);
    printf( "\n\n\t\tEscolha um programa para abrir\t\n\n"
            "\t\t\t1 <-> Calculadora\t\n\n"
            "\t\t\t2 <-> Bloco de notas\t\n\n"
            "\t\t\t3 <-> WordPad\t\n\n"
            "\t\t\t4 <-> Microsoft Word\t\n\n"
            "\t\t\t5 <-> Microsoft Excel\t\n\n"
            "\t\t\t6 <-> Microsoft chrome\t\n\n"
            "\t\t\t0 <-> Menu Principal\t\n\n");

    SetConsoleTextAttribute(Console, VERDE);
    printf( "\t\t========================================");
            SetConsoleTextAttribute(Console, VERMELHO);
    printf("\n\nObs.: Algumas op��es acima s� ir� abrir se o mesmo estiver instalado no computador.\n\n");

    SetConsoleTextAttribute(Console, BRANCO);
    //tenta implementar o gotoxy da biblioteca conio.h
    printf ("Digite a op��o desejada: ");
    SetConsoleTextAttribute(Console, VERDE);
    ctrNumber(&opcao);
    switch (opcao){
        case '1':
            system ("start calc");
            system("cls");
            MenuUtilidades(Console);
            break;
        case '2':
            system ("start notepad");
            system("cls");
            MenuUtilidades(Console);
            break;
        case '3':
            system ("start write");
            system("cls");
            MenuUtilidades(Console);
            break;
        case '4':
            system ("start winword");
            system("cls");
            MenuUtilidades(Console);
            break;
        case '5':
            system ("start excel");
            system("cls");
            MenuUtilidades(Console);
            break;
        case '6':
            system ("start chrome");
            system("cls");
            MenuUtilidades(Console);
            break;
        case '0':
            menu(Console);
            break;
        default:
            SetConsoleTextAttribute(Console, VERMELHO);
            printf ("\n\nDesculpe, mas esta op��o � inv�lida.\n\n");
            Sleep(500);
            system("cls");
            MenuUtilidades(Console);
            break;
    }
}


//6
void MenuUsuario(Console){
    SetConsoleTextAttribute(Console, BRANCO);
    printf("ta comentado");
    //getch();
    //menu(Console);
    char usuario1[16], senha1[16];

    SetConsoleTextAttribute(Console, BRANCO);

	Arquivo = fopen("usuario.txt","a+");
    printf("\n\tCadastre um usuario: ");
	printf("\n\n\tLogin:");
	strPlusAlnum(usuario1, 16);
	printf("\n\tSenha:");
	senhaOculta(senha1,16);

    fprintf(Arquivo,"%s \n",usuario1);
    fprintf(Arquivo,"%s \n",senha1);
    fclose(Arquivo);
    printf("\n\n\t\tCadastro concluido");
    getch();
    menu(Console);
}


//7
void MenuAjuda(Console){

    // configuracao da tela
    SetConsoleTitle("IMOBILIARIA - AJUDA");

    printf( "\n\n\t\t============ MENU AJUDA ===============");

    SetConsoleTextAttribute(Console, BRANCO);
    printf( "\n\n\t\t\t1 <-> Menu PRINCIPAL\n"
            "\t\t\t2 <-> Menu CLIENTE\n"
            "\t\t\t3 <-> Menu CORRETOR\n"
            "\t\t\t4 <-> Menu IM�VEIS\n"
            "\t\t\t5 <-> Menu UTILIDADES\n"
            "\t\t\t6 <-> Menu SIMULA��O\n"
            "\t\t\t7 <-> Menu USUARIO\n"
            "\t\t\t8 <-> Menu AJUDA\n"
            "\t\t\t9 <-> Menu SOBRE\n"
            "\t\t\t0 <-> VOLTAR");
    SetConsoleTextAttribute(Console, VERDE);
    printf("\n\n\n\t\t=======================================");
    printf("\n\nQual dos menus tem Duvida: ");

        SetConsoleTextAttribute(Console, BRANCO);
        ctrNumber(&opcao);

    switch(opcao){
        case '1': // pricipal
            system("cls");
            SetConsoleTextAttribute(Console, BRANCO);
            printf( "\n\n\t\tO Menu Principal � a tela pricipal, "
                   "\n\t\t"
                    "\n\t\tTe da acesso aos outros menus e foi o que te trouxe aqui"
                    "\n\t\tLinkar"
                    "\n\n\t\tPrecione qualquer tecla para voltar: ");
            getch();
            system("cls");
            MenuAjuda(Console);
            break;
        case '2': // cliente
            system("cls");
            SetConsoleTextAttribute(Console, BRANCO);
            printf( "\n\n\t\tO Menu Cliente cria cadastro do cliente da imobiliaria, "
                    "\n\t\tRealiza a busca do cadastro do cliente atrav�s do CPF"
                    "\n\t\tRealiza a exclus�o do cadastro de algum cliente"
                    "\n\t\tMostrar uma Lista com todos os cliente cadastrado"
                    "\n\n\t\tPrecione qualquer tecla para voltar: ");
            getch();
            system("cls");
            MenuAjuda(Console);
            break;
        case '3': // Corretor
            system("cls");
            SetConsoleTextAttribute(Console, BRANCO);
            printf( "\n\n\t\tO Menu Corretor cria cadastro do corretor da imobiliaria, "
                    "\n\t\tRealiza a busca do cadastro do corretor atrav�s do CPF"
                    "\n\t\tRealiza a exclus�o do cadastro de algum corretor"
                    "\n\t\tMostrar uma Lista com todos os corretor cadastrado"
                    "\n\n\t\tPrecione qualquer tecla para voltar: ");
            getch();
            system("cls");
            MenuAjuda(Console);
            break;
        case '4': // imoveis
            system("cls");
            SetConsoleTextAttribute(Console, BRANCO);
            printf( "\n\n\t\tO Menu Im�veis cadastra Im�veis na imobiliaria, "
                    "\n\t\tRealiza a busca do cadastro do Im�veis atrav�s do endere�o"
                    "\n\t\tRealiza a exclus�o do cadastro de algum Im�veil"
                    "\n\t\tMostrar uma Lista com todos os Im�veis cadastrado"
                    "\n\n\t\tPrecione qualquer tecla para voltar: ");
            getch();
            system("cls");
            MenuAjuda(Console);
            break;
        case '5': // utilidades
            system("cls");
            SetConsoleTextAttribute(Console, BRANCO);
            printf( "\n\n\t\tO Menu Utilidades mostra algumas ferramentas"
                    "\n\t\tque pode ser utilizadas como apoio para o dia a dia,"
                    "\n\t\talgumas ferramentas precisam ser instaladas"
                    "\n\t\tcomo � caso do office, ja outras n�o precisam"
                    "\n\t\tcomo � caso do bloco de notas, caculadores e outras."
                    "\n\n\t\tPrecione qualquer tecla para voltar: ");
            getch();
            system("cls");
            MenuAjuda(Console);
            break;
        case '6': // simula��o
            system("cls");
            SetConsoleTextAttribute(Console, BRANCO);
            printf( "\n\n\t\tO Menu Simula��o, simula um financiamento"
                    "\n\t\tutilizando a tabela SAC e faz o calculo"
                    "\n\t\tde acordo com os dados informados"
                    "\n\n\t\tPrecione qualquer tecla para voltar: ");
            getch();
            system("cls");
            MenuAjuda(Console);
            break;
        case '7': // usuario
            system("cls");
            SetConsoleTextAttribute(Console, BRANCO);
            printf( "\n\n\t\tO Menu Usu�rio cria cadastro de usu�rio para o sistema da imobiliaria"
                    "\n\n\t\tPrecione qualquer tecla para voltar: ");
            getch();
            system("cls");
            MenuAjuda(Console);
            break;
        case '8': // ajuda
            system("cls");
            SetConsoleTextAttribute(Console, BRANCO);
            printf( "\n\n\t\tO Menu Ajuda, Esse mesmo que voc� esta"
                    "\n\t\tele ajuda voc� como o pr�prio nome ja diz"
                    "\n\t\tCom breve descri��es sobre cada menu"
                    "\n\t\tObrigado pela escolha e foco para dominar esse sistema."
                    "\n\n\t\tPrecione qualquer tecla para voltar: ");
            getch();
            system("cls");
            MenuAjuda(Console);
            break;
        case '9': // sobre
            system("cls");
            SetConsoleTextAttribute(Console, BRANCO);
            printf( "\n\n\t\tO Menu Sobre, Mostrar informa��es sobre a empresa"
                    "\n\t\tque desenvolveu o software e alguns outros dados "
                    "\n\t\ttbm cont�m um supresa l�, por�m s� estara liberado futuramente,"
                    "\n\t\tmas vai la conhecer o menu sobre e ver essa tal supresa"
                    "\n\n\t\tPrecione qualquer tecla ara voltar: ");
            getch();
            system("cls");
            MenuAjuda(Console);
            break;
        case '0':// Voltar para o Menu Principal
            system("cls");
            menu(Console);
            break;
        default:
        //apenas por segunranca
            SetConsoleTextAttribute(Console, VERMELHO);
            printf("\nOp��o Inv�lida!\n");
            break;
    }
}


//8
void MenuSobre(Console){

    SetConsoleTitle("IMOBILIARIA - SOBRE");
    SetConsoleTextAttribute(Console, BRANCO);

    printf( "\n\n\t  A BI tecnology foi formada por dois estudantes e tamebem "
            "\n\tprogramadores com grandes sonhos e muita criatividade. "
            "\n\n\tObrigado por adquirir um dde nossos software,"
            "\n\tespero que goste e obrigado por nos escolher."
            "\n\tAtesiosamente Isac e Valdenor CEOs da BI Tecnology.!");
    printf( "\n\n\n\tUma supresa para voc� cliente, no software adquirido"
			"\n\ttem menus secretos que em breve estar� disponivel em uma breve atulaiza��o"
            "\n\tDigite 0 para sair ou 1,2 ou 3 para acessar esses misteriosos menus"
			"\n\n\t");

    SetConsoleTextAttribute(Console, VERDE);
    ctrNumber(&opcao);
    switch(opcao){
        case '1':
            EditarCliente(Console);
            break;
        case '2': // Lista com tod im�veis
            EditarCorretor(Console);
            break;
        case '3':
            EditarImovel(Console);
            break;
        case '0':
            menu(Console);
            break;
        default:
            SetConsoleTextAttribute(Console, VERMELHO);
            printf("\n\n\t\t\tOp��o Inv�lida!");
            Sleep(500);
            system("cls");
            MenuSobre(Console);
            break;
    }
}



//Redireciona para qual menu vai acessar de acordo com as opc�o e todos retornam para o menu
int menu(Console){

    SetConsoleTextAttribute(Console, BRANCO);

    char sair;
    char opcMenu[2];
    char opc;
    // i de indice
    int i = 0, cont=0, enter=0;

    // configuracao da tela
    setlocale(LC_ALL, "Portuguese");

    system("cls");
    MenuPrincipal(Console);
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
                            opcMenu[0] = opc;
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
    //*num = ctrLimitar[0];

    switch(opcMenu[0]){
        case '1': // Menu Cliente
            opcMenu[0] ='\0'; // Deixando o valor nulo para quando retornar ao menu principal n�o acessar nenhum outro menu quando apertar o enter
            system("cls");
            MenuCliente(Console);
            break;
        case '2': // Menu Corretor
            opcMenu[0] ='\0';
            system("cls");
            MenuCorretor(Console);
            break;
        case '3': // Menu Imoveis
            opcMenu[0] ='\0';
            system("cls");
            MenuImoveis(Console);
            break;
        case '4': // Menu Ajuda
            opcMenu[0] ='\0';
            system("cls");
            MenuSimulado(Console);
            break;
        case '5': // Menu Utilidade
            opcMenu[0] ='\0';
            system("cls");
            MenuUtilidades(Console);
            break;
        case '6': // Menu de Teste
            opcMenu[0] ='\0';
            system("cls");
            MenuUsuario(Console);
            break;
        case '7': // Menu de Teste
            opcMenu[0] ='\0';
            ajuda:
            system("cls");
            MenuAjuda(Console);
            break;
        case '8': // Menu de Simulado
            opcMenu[0] ='\0';
            system("cls");
            MenuSobre(Console);
            break;
        case '0': // sair
            system("cls");
            do{
                SetConsoleTextAttribute(Console, BRANCO);
                printf( "\n\n\tTem certeza que deseja sair do programa ?"
                        "\n\tdigite 0 ou S para Sair"
                        "\n\t1 ou N para voltar ao Menu"
                        "\n\nDigite a opcao escolhida?");
                SetConsoleTextAttribute(Console, VERDE);
                ctrAlnum(&sair);

                    if(sair== '0' || tolower(sair)== 's'){
                        printf ("%c", sair);
                        exit(1);
                    }else if(sair== '1' || tolower(sair)== 'n'){
                        printf ("%c", sair);
                        system("cls");
                        menu(Console);
                        break;
                    }
                    else{
                        SetConsoleTextAttribute(Console, VERMELHO);
                        printf("\n\n\n\t\t\tOpcao Invalida!! Tente denovo!");
                        Sleep(1000);
                        system("cls");
                    }
            }while(sair!= 's' || sair!= 'n');
            break;
        default:
            SetConsoleTextAttribute(Console, VERMELHO);
            printf("\n\t\t\tOpcao Invalida!! Tente denovo!");
            Sleep(1000);
            system("cls");
            menu(Console);
            break;
    }

	return 0;
}
