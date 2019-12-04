#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "formatbr.c"
#include "string++.h"
#include <windows.h>

// variaveis globais funcóes de acordo com o menu selecionado
FILE* Arquivo;
FILE* Cliente;
FILE* Corretor;
FILE* Imovel;
FILE* Leitura;
FILE* arquivoNovo1;
FILE* arquivoNovo2;
char opcaoMenu = '0';
char buscaCpf[15];
int cont;


#define  PRETO              0
#define  AZUL_ESCURO        1
#define  CINZA_ESCURO       2
#define  DARK_CYAN          3
#define  VERMELHO_ESCURO    4
#define  DARK_YELLOW        6
#define  BRANC_ESC          7
#define  CINZA              8
#define  VERDE              10
#define  AZUL_CLARO         11
#define  VERMELHO           12
#define  AMARELO            14
#define  BRANCO             15

//===========================================================

void TirarEspaco(char *texto){
	int i;
    for (i=0;i<strlen(texto);i++)
    {
		if (texto[i]==' ')
		{
			texto[i]='|';
		}
	}
}

void ColocarEspaco(char *texto){
	int i;
	for (i=0;i<strlen(texto);i++)
	{
		if (texto[i]=='|')
		{
			texto[i]=' ';
		}
	}
}

int arquivo_existe(char nmarq[]) {
	FILE* arq = fopen(nmarq, "r");
    if (arq) {
        fclose(arq);
        return 1;
    }
    return 0;
}

// outras funçoes na:
// pasta Projeto_bibliotecaC oinde estar a biblioteca string++
// e no arquivo formatbr.c

//=========Estrutura=============

typedef struct {
	char nome[40];
	char dataNas[11];
	char email[40];
	char rg[13];
	char cpf[15];
	char tel[15];
	char sexo[13];
	char estCivil[10];
	char end[50];
	char endNum[5];
    char creci[8]
} dadosPessoais;

dadosPessoais dpe;


typedef struct {
	char tipo[16];
	char constru[4];
	char terreno[40];
	char garagem[2];
	char banheiro[11];
	char dormi[11];
	char end[50];
	char endNum[5];
    char metros[16];
    char valor[16];
} dadosImoveis;

dadosImoveis dim;

//--------CLIENTE-----------CLIENTE------------------CLIENTE---------------

//numero referente ao menu e sub menu, usei na funcao goto
//1.1
void CadastroCliente(Console){

	// configuracao da tela
    SetConsoleTitle("IMOBILIARIA - Cadastro de Cliente");

    SetConsoleTextAttribute(Console, BRANCO);

    int validar;
	Arquivo = fopen("ClienteConsulta.txt","a+");
	Cliente = fopen("Cliente.txt","a+");// verificar se aqui eu abro usando o W  e depois vou usando A para adicionar.

    printf("\n\n\n\t\tCADASTRO DE CLIENTE\n\n");

	SetConsoleTextAttribute(Console, BRANC_ESC);    {}  printf ("\nEscreva seu nome completo: ");
    SetConsoleTextAttribute(Console, VERDE);        {} 	strPlusAl(dpe.nome, 40);
    //
	SetConsoleTextAttribute(Console, BRANC_ESC);    {}  printf("\nSexo(F/M): ");
    SetConsoleTextAttribute(Console, VERDE);        {}  strPlusAl(dpe.sexo, 13);
    //
	SetConsoleTextAttribute(Console, BRANC_ESC);    {}  printf("\nEstado Civil: ");
    SetConsoleTextAttribute(Console, VERDE);        {}  strPlusAl(dpe.estCivil, 13);
    //
    SetConsoleTextAttribute(Console, BRANC_ESC);    {}  printf("\nendereco S/ número: ");
    SetConsoleTextAttribute(Console, VERDE);        {}  strPlusAl(dpe.end, 50);
    //
    SetConsoleTextAttribute(Console, BRANC_ESC);    {}  printf("\nNúmero do endereço: ");
    SetConsoleTextAttribute(Console, VERDE);        {}  strPlusNum(dpe.endNum, 5);
    //
	SetConsoleTextAttribute(Console, BRANC_ESC);    {}  printf("\nData de Nascimento: ");
    SetConsoleTextAttribute(Console, VERDE);        {}  dataf(dpe.dataNas);
    //
	SetConsoleTextAttribute(Console, BRANC_ESC);    {}  printf("\nNúmero de RG: ");
    SetConsoleTextAttribute(Console, VERDE);        {}  rgm(dpe.rg);
    //
	SetConsoleTextAttribute(Console, BRANC_ESC);    {}  printf("\nNúmero de CPF: ");
    SetConsoleTextAttribute(Console, VERDE);        {}  cpfm(dpe.cpf);
    //
	SetConsoleTextAttribute(Console, BRANC_ESC);    {}  printf("\nTelefone: ");
    SetConsoleTextAttribute(Console, VERDE);        {}  telm(dpe.tel);
    //
    valEmailcli:
	SetConsoleTextAttribute(Console, BRANC_ESC);    {}  printf("\nInforme seu endereço de e-mail: ");
    SetConsoleTextAttribute(Console, VERDE);        {}  validar = emailf(dpe.email);
    if(validar==0){
        SetConsoleTextAttribute(Console, VERMELHO);
        printf("\nE-mail Inválido digite novamente\n");
        goto valEmailcli;
    }


	fprintf(Cliente,"\n\nNome:" "%s",dpe.nome);
	fprintf(Cliente,"\nSexo:" "%s",dpe.sexo);
	fprintf(Cliente,"\nEstado Civil::" "%s",dpe.estCivil);
	fprintf(Cliente,"\nEndereço:" "%s, %s",dpe.end,dpe.endNum);
	fprintf(Cliente,"\nData de Nasc:" "%s",dpe.dataNas);
	fprintf(Cliente,"\nRG:" "%s",dpe.rg);
	fprintf(Cliente,"\nCPF:" "%s",dpe.cpf);
	fprintf(Cliente,"\nTelefone:" "%s",dpe.tel);
	fprintf(Cliente,"\nEndereço de e-mail:" "%s",dpe.email);

	fclose(Cliente);
    //============================================

    //Comando para tirar espaço de um lado e o comando para gravar no arquiv do outro separado por uma chave
	TirarEspaco(dpe.nome);      {}  fprintf(Arquivo,"\n%s\n",dpe.nome);
	TirarEspaco(dpe.sexo);      {}  fprintf(Arquivo,"%s\n",dpe.sexo);
	TirarEspaco(dpe.estCivil);  {}  fprintf(Arquivo,"%s\n",dpe.estCivil);
	TirarEspaco(dpe.end);       {}  fprintf(Arquivo,"%s\n",dpe.end);
	TirarEspaco(dpe.endNum);    {}  fprintf(Arquivo,"%s\n",dpe.endNum);
	TirarEspaco(dpe.dataNas);   {}  fprintf(Arquivo,"%s\n",dpe.dataNas);
	TirarEspaco(dpe.rg);        {}  fprintf(Arquivo,"%s\n",dpe.rg);
	TirarEspaco(dpe.cpf);       {}  fprintf(Arquivo,"%s\n",dpe.cpf);
	TirarEspaco(dpe.tel);       {}  fprintf(Arquivo,"%s\n",dpe.tel);
	TirarEspaco(dpe.email);     {}  fprintf(Arquivo,"%s\n",dpe.email);

    fclose(Arquivo);
    printf("\n\nCorretor Cadastrado Com Sucesso!");
    SetConsoleTextAttribute(Console, BRANCO);

    errocli1:
	printf("\nDigite 1 para realizar um novo cadastro, ou 0 para sair:");
	ctrNumber(&opcaoMenu);

	if(opcaoMenu == '0'){
        system("cls");
		MenuCliente(Console);
	}
	else if(opcaoMenu == '1'){
        system("cls");
        CadastroCliente(Console);
    }else{
        SetConsoleTextAttribute(Console, VERMELHO);
        printf("\n\n\t\t\t    Opção inválida!");
        Sleep(500);
    goto errocli1;
    }
}

//1.2
void ListarCliente(Console){

    char texto_str[100];// array de string captura os dados em uma linha no arquivo
    cont =0;

    SetConsoleTitle("IMOBILIARIA - Lista de Cliente");

    system("cls");
    SetConsoleTextAttribute(Console, VERDE);

    printf("\n\n\t\t\t\tLISTA DE CLIENTES CADASTRADO\n\n");
    SetConsoleTextAttribute(Console, BRANC_ESC);
	Leitura = fopen("Cliente.txt", "r");
	while(fgets(texto_str, 100, Leitura) != NULL){
		printf("\t\t\t%s", texto_str);
        cont++;
        if(cont% 9==0 ){
            // printf("\n\t\t\t=======================================\n");
        }
	}
	//fechando o arquivo
	fclose(Leitura);
    SetConsoleTextAttribute(Console, VERDE);
    printf( "\n\n\n\t\t\t================================================"
	        "\n\t\t\t\tCliente(s) listado com sucesso !");
    opcaoMenu = '0';


    errocli2:
        SetConsoleTextAttribute(Console, VERDE);
        printf("\n\n\t\t\tPressione 0 para voltar ao menu cliente: ");

    SetConsoleTextAttribute(Console, VERDE);
	ctrNumber(&opcaoMenu);

	if(opcaoMenu == '0'){
        system("cls");
		MenuCliente(Console);
    }
    else{
        system("cls");
        SetConsoleTextAttribute(Console, VERMELHO);
        printf("\n\n\t\t\t    Opção inválida!");
        Sleep(500);
    goto errocli2;
    }
}

//1.5
void EditarCliente(Console){
    char teste[11];

    SetConsoleTitle("IMOBILIARIA - Editar Cadastro de Cliente");

    SetConsoleTextAttribute(Console, BRANCO);

    printf("\nEditar cadastro\n\n");
    printf("\n\n\t\tCASO NÃO SAIBA O CPF, PROCURE O CLIENTE NA OPCAO LISTAR CLIENTE OU BUSCAR CLIENTE\n\n");
	printf("Informe o CPF referente ao cadastro que deseja excluir: ");
	cpfm(teste);

    printf( "\ntenha paciência, por favor!"
            "\nAguarde a atualização");
    getch();
    system("cls");
    MenuSobre(Console);
}

//1.3
void ExcluirCliente(Console){

    SetConsoleTitle("IMOBILIARIA - Excluir Cliente");

    SetConsoleTextAttribute(Console, BRANCO);

    if (!arquivo_existe("ClienteConsulta.txt")){
        SetConsoleTextAttribute(Console, VERMELHO);
        printf("\n\n\tnão existe cadastro");
    }else{
        int i=0;
        printf("\nExclusão do cadastro\n\n");
        printf("Informe o CPF referente ao cadastro que deseja excluir: ");
        SetConsoleTextAttribute(Console, VERDE);
        cpfm(buscaCpf);
        SetConsoleTextAttribute(Console, BRANCO);
        Arquivo = fopen("ClienteConsulta.txt","r");
        Cliente = fopen("Cliente.txt","r");
        arquivoNovo1 = fopen("ClienteConsulta_novo.txt","w");
        FILE* arquivoNovo2 = fopen("Cliente_novo.txt","w");
        while(!feof(Arquivo)){

            fscanf( Arquivo,"%s %s %s %s %s %s %s %s %s %s",
            dpe.nome, dpe.sexo, dpe.estCivil, dpe.end, dpe.endNum, dpe.dataNas, dpe.rg, dpe.cpf, dpe.tel, dpe.email);// acessar os dados
            if (strcmp(dpe.cpf, buscaCpf)!=0){
                //novo editado
                ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\n\nNome:" "%s",dpe.nome);
                ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nSexo:" "%s",dpe.sexo);
                ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nEstado Civil::" "%s",dpe.estCivil);
                ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nEndereço:" "%s, %s",dpe.end,dpe.endNum);
                ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nData de Nasc:" "%s",dpe.dataNas);
                ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nRG:" "%s",dpe.rg);
                ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nCPF:" "%s",dpe.cpf);
                ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nTelefone:" "%s",dpe.tel);
                ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nEndereço de e-mail:" "%s",dpe.email);
                // novo em linha
                TirarEspaco(dpe.nome);      {}  fprintf(arquivoNovo1,"\n%s\n",dpe.nome);
                TirarEspaco(dpe.sexo);      {}  fprintf(arquivoNovo1,"%s\n",dpe.sexo);
                TirarEspaco(dpe.estCivil);  {}  fprintf(arquivoNovo1,"%s\n",dpe.estCivil);
                TirarEspaco(dpe.end);       {}  fprintf(arquivoNovo1,"%s\n",dpe.end);
                TirarEspaco(dpe.endNum);    {}  fprintf(arquivoNovo1,"%s\n",dpe.endNum);
                TirarEspaco(dpe.dataNas);   {}  fprintf(arquivoNovo1,"%s\n",dpe.dataNas);
                TirarEspaco(dpe.rg);        {}  fprintf(arquivoNovo1,"%s\n",dpe.rg);
                TirarEspaco(dpe.cpf);       {}  fprintf(arquivoNovo1,"%s\n",dpe.cpf);
                TirarEspaco(dpe.tel);       {}  fprintf(arquivoNovo1,"%s\n",dpe.tel);
                TirarEspaco(dpe.email);     {}  fprintf(arquivoNovo1,"%s\n",dpe.email);
            }else{
                i++;
            }
        }
        fclose(Arquivo);
        fclose(Cliente);
        fclose(arquivoNovo1);
        fclose(arquivoNovo2);

        system("del ClienteConsulta.txt");
        system("del Cliente.txt");
        system("rename ClienteConsulta_novo.txt ClienteConsulta.txt");
        system("rename Cliente_novo.txt Cliente.txt");

        if(i==1){
            printf("Cadastro excluido");
            printf( "\n\nCliente Excluido com sucesso !");
        }
        getchar();
    }
    errocli3:
    printf("\nDigite 1 para Excluir outro cadastro, ou 0 para sair:");
	ctrNumber(&opcaoMenu);

    if(opcaoMenu=='0'){
        system("cls");
        MenuCliente(Console);
    }
    else if(opcaoMenu == '1'){
        system("cls");
        ExcluirCliente(Console);
    }else{
        SetConsoleTextAttribute(Console, VERMELHO);
        printf("\n\n\t\t\t    Opção inválida!");
        Sleep(500);
        goto errocli3;
    }
}

//1.4
void BuscarCliente(Console){

    SetConsoleTitle("IMOBILIARIA - Buscar de Cliente");
    SetConsoleTextAttribute(Console, BRANCO);

    if (!arquivo_existe("ClienteConsulta.txt")){
        printf("\n\n\tnão existe cadastro");
    }else{
        int i = 0;
        printf("\nBuscar cliente\n\n");
        printf("Informe o CPF: ");
        SetConsoleTextAttribute(Console, VERDE);
        cpfm(buscaCpf);
        SetConsoleTextAttribute(Console, BRANCO);
        printf("\n");
        Arquivo = fopen("ClienteConsulta.txt","r"); // abrir arquivo em modo leitura
        // 	while(fgets(texto_str, 5, Leitura) != NULL)
        // {
        // 	for(i=0; i<(fgets(texto_str, 5, Leitura) != NULL); i++){

        //     }
        // }
        while(!feof(Arquivo)){
            fscanf( Arquivo,"%s %s %s %s %s %s %s %s %s %s",
            dpe.nome, dpe.sexo, dpe.estCivil, dpe.end, dpe.endNum, dpe.dataNas, dpe.rg, dpe.cpf, dpe.tel, dpe.email);

            if (strcmp(dpe.cpf, buscaCpf)==0){
                i++;
                ColocarEspaco(dpe.nome);    {}  printf("\nNome:" "%s",dpe.nome);
                ColocarEspaco(dpe.nome);    {}  printf("\nSexo:" "%s",dpe.sexo);
                ColocarEspaco(dpe.nome);    {}  printf("\nEstado Civil::" "%s",dpe.estCivil);
                ColocarEspaco(dpe.nome);    {}  printf("\nEndereco:" "%s,%s",dpe.end,dpe.endNum);
                ColocarEspaco(dpe.nome);    {}  printf("\nData de Nascimento:" "%s",dpe.dataNas);
                ColocarEspaco(dpe.nome);    {}  printf("\nRegistro Geral:" "%s",dpe.rg);
                ColocarEspaco(dpe.nome);    {}  printf("\nCadastro Pessoa F?sica:" "%s",dpe.cpf);
                ColocarEspaco(dpe.nome);    {}  printf("\nTelefone:" "%s",dpe.tel);
                ColocarEspaco(dpe.nome);    {}  printf("\nEndere?o de e-mail:" "%s",dpe.email);
            }
        }
        fclose(Arquivo);
        if(i==0){
            SetConsoleTextAttribute(Console, VERMELHO);
            printf("\nNenhum cliente cadastrado com esse CPF");
        }else{
            SetConsoleTextAttribute(Console, VERDE);
            printf("\n\nBusca concluida com sucesso !");
        }
    }
    errocli3:
    printf("\nDigite 1 para realizar uma nova busca ou 0 para sair:");
	ctrNumber(&opcaoMenu);

	if(opcaoMenu == '0'){
        system("cls");
		MenuCliente(Console);
	}
	else if(opcaoMenu == '1'){
        system("cls");
		BuscarCliente(Console);
	}else{
        system("cls");
        SetConsoleTextAttribute(Console, VERMELHO);
        printf("\n\n\t\t\t    Opção invalida!");
        Sleep(500);
    goto errocli3;
    }
}


//---------CORRETOR-----------CORRETOR--------------CORRETOR---------------


//2.1
void CadastroCorretor(Console){

    SetConsoleTitle("IMOBILIARIA - Cadastro de Corretor");
    SetConsoleTextAttribute(Console, BRANCO);

    int validar;
    Arquivo = fopen("CorretorConsulta.txt","a+");
	Corretor = fopen("Corretor.txt","a+");// verificar se aqui eu abro usando o W  e depois vou usando A para adicionar.

	printf("\n\n\n\t\tCADASTRO DE CORRETOR\n\n");

	SetConsoleTextAttribute(Console, BRANCO);  {}  printf ("\nEscreva seu nome completo: ");
    SetConsoleTextAttribute(Console,  VERDE);  {} 	strPlusAl(dpe.nome, 40);
    //
	SetConsoleTextAttribute(Console, BRANCO);  {}  printf("\nSexo(F/M): ");
    SetConsoleTextAttribute(Console, VERDE);   {}  strPlusAl(dpe.sexo, 13);
    //
	SetConsoleTextAttribute(Console, BRANCO);  {}  printf("\nCreci: ");
    SetConsoleTextAttribute(Console, VERDE);   {}  strPlusNum(dpe.creci, 8);
    //
	SetConsoleTextAttribute(Console, BRANCO);  {}  printf("\nEstado Civil: ");
    SetConsoleTextAttribute(Console, VERDE);   {}  strPlusAl(dpe.estCivil, 13);
    //
    SetConsoleTextAttribute(Console, BRANCO);  {}  printf("\nendereco S/ número: ");
    SetConsoleTextAttribute(Console, VERDE);   {}  strPlusAl(dpe.end, 50);
    //
    SetConsoleTextAttribute(Console, BRANCO);  {}  printf("\nNúmero do endereco: ");
    SetConsoleTextAttribute(Console, VERDE);   {}  strPlusNum(dpe.endNum, 5);
    //
	SetConsoleTextAttribute(Console, BRANCO);  {}  printf("\nData de Nascimento: ");
    SetConsoleTextAttribute(Console, VERDE);   {}  dataf(dpe.dataNas);
    //
	SetConsoleTextAttribute(Console, BRANCO);  {}  printf("\nNúmero de RG: ");
    SetConsoleTextAttribute(Console, VERDE);   {}  rgm(dpe.rg);
    //
	SetConsoleTextAttribute(Console, BRANCO);  {}  printf("\nNúmero de CPF: ");
    SetConsoleTextAttribute(Console, VERDE);   {}  cpfm(dpe.cpf);
    //
	SetConsoleTextAttribute(Console, BRANCO);  {}  printf("\nTelefone: ");
    SetConsoleTextAttribute(Console, VERDE);   {}  telm(dpe.tel);
    //
    valEmail:
	SetConsoleTextAttribute(Console, BRANCO);  {}  printf("\nInforme seu endere?o de e-mail: ");
    SetConsoleTextAttribute(Console, VERDE);   {}  validar = emailf(dpe.email);
    if(validar==0){
        SetConsoleTextAttribute(Console, VERMELHO);
        printf("E-mail Inválido digite novamente\n");
        goto valEmail;
    }

	fprintf(Corretor,"\n\nNome:" "%s",dpe.nome);
	fprintf(Corretor,"\nSexo:" "%s",dpe.sexo);
	fprintf(Corretor,"\nCreci:" "%s",dpe.creci);
	fprintf(Corretor,"\nEstado Civil:" "%s",dpe.estCivil);
	fprintf(Corretor,"\nEndereço:" "%s, %s",dpe.end,dpe.endNum);
	fprintf(Corretor,"\nData de Nasc:" "%s",dpe.dataNas);
	fprintf(Corretor,"\nRG:" "%s",dpe.rg);
	fprintf(Corretor,"\nCPF:" "%s",dpe.cpf);
	fprintf(Corretor,"\nTelefone:" "%s",dpe.tel);
	fprintf(Corretor,"\nEndereço de e-mail:" "%s",dpe.email);

	fclose(Corretor);
    //============================================================================

    //função para automatizar isso se der tempo
    //algumas não precisa tirar o espaco mais coloquei por garantia
	TirarEspaco(dpe.nome);      {}  fprintf(Arquivo,"\n%s\n",dpe.nome);
	TirarEspaco(dpe.sexo);      {}  fprintf(Arquivo,"%s\n",dpe.sexo);
	TirarEspaco(dpe.creci);     {}  fprintf(Arquivo,"%s\n",dpe.creci);
	TirarEspaco(dpe.estCivil);  {}  fprintf(Arquivo,"%s\n",dpe.estCivil);
	TirarEspaco(dpe.end);       {}  fprintf(Arquivo,"%s\n",dpe.end);
	TirarEspaco(dpe.endNum);    {}  fprintf(Arquivo,"%s\n",dpe.endNum);
	TirarEspaco(dpe.dataNas);   {}  fprintf(Arquivo,"%s\n",dpe.dataNas);
	TirarEspaco(dpe.rg);        {}  fprintf(Arquivo,"%s\n",dpe.rg);
	TirarEspaco(dpe.cpf);       {}  fprintf(Arquivo,"%s\n",dpe.cpf);
	TirarEspaco(dpe.tel);       {}  fprintf(Arquivo,"%s\n",dpe.tel);
	TirarEspaco(dpe.email);     {}  fprintf(Arquivo,"%s\n",dpe.email);

    fclose(Arquivo);

	printf("\n\nCorretor Cadastrado Com Sucesso!");
    SetConsoleTextAttribute(Console, BRANCO);

    errocor1:
	printf("\n\nDigite 1 para realizar um novo cadastro, ou 0 para sair:");
	ctrNumber(&opcaoMenu);

	if(opcaoMenu == '0'){
        system("cls");
        MenuCorretor(Console);
    }
	else if(opcaoMenu == '1'){
        system("cls");
        CadastroCorretor(Console);
    }else{
        SetConsoleTextAttribute(Console, VERMELHO);
        printf("\n\n\t\t\t    Opção inválida!");
        Sleep(500);
        goto errocor1;
    }

}

//2.2
void ListarCorretor(Console){
    char texto_str[200];
    cont =0;

    SetConsoleTitle("IMOBILIARIA - Lista de Corretor");

    system("cls");
    SetConsoleTextAttribute(Console, VERDE);
    printf("\n\n\t\t\t\tLista de Corretores Cadastrado\n\n");
    SetConsoleTextAttribute(Console, BRANC_ESC);
	Leitura = fopen("Corretor.txt", "r");
	while(fgets(texto_str, 200, Leitura) != NULL){
		printf("\t\t\t%s", texto_str);
        cont++;
        if(cont% 9==0 ){
            // printf("\n\t\t\t=======================================\n");
        }
	}
	//fechando o arquivo
	fclose(Leitura);
    SetConsoleTextAttribute(Console, VERDE);
    printf( "\n\n\n\t\t\t================================================"
	        "\n\t\t\t\tCorretores(s) listado com sucesso !");



    errocor2:
    SetConsoleTextAttribute(Console, BRANCO);
    printf("\n\n\t\t\tPressione 0 para voltar ao menu corretor: ");
    SetConsoleTextAttribute(Console, VERDE);
	ctrNumber(&opcaoMenu);

	if(opcaoMenu == '0'){
        system("cls");
		MenuCorretor(Console);
    }
    else{
        system("cls");
        SetConsoleTextAttribute(Console, VERMELHO);
        printf("\n\n\t\t\t    Opção inválida!");
        Sleep(500);
    goto errocor2;
    }
}

//2.3
void EditarCorretor(Console){
    char teste[11];

    SetConsoleTitle("IMOBILIARIA - Editar Cadastro de Corretor");

    SetConsoleTextAttribute(Console, BRANCO);

    printf("\n\t\tEditar cadastro\n");
    printf("\n\n\t\tFaça o teste vai que da certo, não custa tentar\n\n");
	printf("Informe o CPF referente ao cadastro que deseja excluir: ");
	cpfm(teste);

    printf( "\ntenha paciência, por favor!"
            "\nAguarde a atualização");
    getch();
    system("cls");
    MenuSobre(Console);
}

//2.4
void ExcluirCorretor(Console){

    SetConsoleTextAttribute(Console, BRANCO);

    SetConsoleTitle("IMOBILIARIA - Excluir Corretor");

    if (!arquivo_existe("ClienteConsulta.txt")){
        SetConsoleTextAttribute(Console, VERMELHO);
        printf("\n\n\tnão existe cadastro");
    }else{
        int i=0;
        printf("\nExclusão do cadastro\n\n");
        printf("Informe o CPF referente ao cadastro que deseja excluir: ");
        SetConsoleTextAttribute(Console, VERDE);
        cpfm(buscaCpf);
        SetConsoleTextAttribute(Console, BRANCO);
        Arquivo = fopen("CorretorConsulta.txt","r");
        Cliente = fopen("corretor.txt","r");
        arquivoNovo1 = fopen("CorretorConsulta_novo.txt","w");
        FILE* arquivoNovo2 = fopen("Corretor_novo.txt","w");
        while(!feof(Arquivo)){

            fscanf( Arquivo,"%s %s %s %s %s %s %s %s %s %s %s",
            dpe.nome, dpe.sexo, dpe.creci, dpe.estCivil, dpe.end, dpe.endNum, dpe.dataNas, dpe.rg, dpe.cpf, dpe.tel, dpe.email);// acessar os dados
            if (strcmp(dpe.cpf, buscaCpf)!=0){
                //novo editado
                ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\n\nNome:" "%s",dpe.nome);
                ColocarEspaco(dpe.sexo);    {}  fprintf(arquivoNovo2,"\nSexo:" "%s",dpe.sexo);
                ColocarEspaco(dpe.creci);   {}  fprintf(arquivoNovo2,"\nCreci:" "%s",dpe.creci);
                ColocarEspaco(dpe.estCivil);{}  fprintf(arquivoNovo2,"\nEstado Civil::" "%s",dpe.estCivil);
                ColocarEspaco(dpe.end);
                ColocarEspaco(dpe.endNum);  {}  fprintf(arquivoNovo2,"\nEndereço:" "%s, %s",dpe.end,dpe.endNum);
                ColocarEspaco(dpe.dataNas);    {}  fprintf(arquivoNovo2,"\nData de Nasc:" "%s",dpe.dataNas);
                ColocarEspaco(dpe.rg);    {}  fprintf(arquivoNovo2,"\nRG:" "%s",dpe.rg);
                ColocarEspaco(dpe.cpf);    {}  fprintf(arquivoNovo2,"\nCPF:" "%s",dpe.cpf);
                ColocarEspaco(dpe.tel);    {}  fprintf(arquivoNovo2,"\nTelefone:" "%s",dpe.tel);
                ColocarEspaco(dpe.email);    {}  fprintf(arquivoNovo2,"\nEndereço de e-mail:" "%s",dpe.email);
                // novo em linha
                TirarEspaco(dpe.nome);      {}  fprintf(arquivoNovo1,"\n%s\n",dpe.nome);
                TirarEspaco(dpe.sexo);      {}  fprintf(arquivoNovo1,"%s\n",dpe.sexo);
                TirarEspaco(dpe.estCivil);  {}  fprintf(arquivoNovo1,"%s\n",dpe.estCivil);
                TirarEspaco(dpe.end);       {}  fprintf(arquivoNovo1,"%s\n",dpe.end);
                TirarEspaco(dpe.endNum);    {}  fprintf(arquivoNovo1,"%s\n",dpe.endNum);
                TirarEspaco(dpe.dataNas);   {}  fprintf(arquivoNovo1,"%s\n",dpe.dataNas);
                TirarEspaco(dpe.rg);        {}  fprintf(arquivoNovo1,"%s\n",dpe.rg);
                TirarEspaco(dpe.cpf);       {}  fprintf(arquivoNovo1,"%s\n",dpe.cpf);
                TirarEspaco(dpe.tel);       {}  fprintf(arquivoNovo1,"%s\n",dpe.tel);
                TirarEspaco(dpe.email);     {}  fprintf(arquivoNovo1,"%s\n",dpe.email);
            }else{
                i++;
            }
        }
        fclose(Arquivo);
        fclose(Cliente);
        fclose(arquivoNovo1);
        fclose(arquivoNovo2);

        system("del CorretorConsulta.txt");
        system("del Corretor.txt");
        system("rename CorretorConsulta_novo.txt CorretorConsulta.txt");
        system("rename Corretor_novo.txt Corretor.txt");
        if(i==1){
            SetConsoleTextAttribute(Console, VERDE);
            printf("Cadastro excluido");
            printf( "\n\nCorretor Excluido com sucesso !");
        }
    }
    errocor3:
    printf("\nPressione 1 para Excluir outro cadastro, ou 0 para sair:");
    SetConsoleTextAttribute(Console, VERDE);
	ctrNumber(&opcaoMenu);

    if(opcaoMenu=='0'){
        system("cls");
        MenuCorretor(Console);
    }
    else if(opcaoMenu == '1'){
        system("cls");
        ExcluirCorretor(Console);
    }else{
        SetConsoleTextAttribute(Console, VERMELHO);
        printf("\n\n\t\t\t    Opção inválida!");
        Sleep(500);
        goto errocor3;
    }
}

//2.5
void BuscarCorretor(Console){

    SetConsoleTitle("IMOBILIARIA - Busca de Corretor");

    if (!arquivo_existe("CorretorConsulta.txt")){
        SetConsoleTextAttribute(Console, VERMELHO);
        printf("\n\n\tnão existe cadastro");
    }else{
        int i = 0;

        SetConsoleTextAttribute(Console, BRANCO);
        printf("\nBuscar Corretor\n\n");
        printf("Informe o cpf ");
        cpfm(buscaCpf);
        printf("\n");
        Arquivo = fopen("CorretorConsulta.txt","r"); // abrir arquivo em modo leitura

        while(!feof(Arquivo)){
            fscanf( Arquivo,"%s %s %s %s %s %s %s %s %s %s",
            dpe.nome, dpe.sexo, dpe.estCivil, dpe.end, dpe.endNum, dpe.dataNas, dpe.rg, dpe.cpf, dpe.tel, dpe.email);

            if (strcmp(dpe.cpf, buscaCpf)==0){
                i++;
                ColocarEspaco(dpe.nome);    {}  printf("\nNome:" "%s",dpe.nome);
                ColocarEspaco(dpe.nome);    {}  printf("\nSexo:" "%s",dpe.sexo);
                ColocarEspaco(dpe.nome);    {}  printf("\nEstado Civil::" "%s",dpe.estCivil);
                ColocarEspaco(dpe.nome);    {}  printf("\nEndereço:" "%s,%s",dpe.end,dpe.endNum);
                ColocarEspaco(dpe.nome);    {}  printf("\nData de Nasc:" "%s",dpe.dataNas);
                ColocarEspaco(dpe.nome);    {}  printf("\nRG:" "%s",dpe.rg);
                ColocarEspaco(dpe.nome);    {}  printf("\nCPF:" "%s",dpe.cpf);
                ColocarEspaco(dpe.nome);    {}  printf("\nTelefone:" "%s",dpe.tel);
                ColocarEspaco(dpe.nome);    {}  printf("\nEndereço de e-mail:" "%s",dpe.email);
            }
        }
        fclose(Arquivo);
        if(i==0){
            SetConsoleTextAttribute(Console, VERMELHO);
            printf("Nenhum Corretor cadastrado com esse CPF");
        }else{
            SetConsoleTextAttribute(Console, VERDE);
            printf("\n\nBusca concluida com sucesso !");
        }
    }
    errocor4:
    printf("\nDigite 1 para realizar uma nova busca ou 0 para sair:");
    SetConsoleTextAttribute(Console, VERDE);
	ctrNumber(&opcaoMenu);

	if(opcaoMenu == '0'){
        system("cls");
		MenuCorretor(Console);
	}
	else if(opcaoMenu == '1'){
        system("cls");
		BuscarCorretor(Console);
	}else{
        system("cls");
        SetConsoleTextAttribute(Console, VERMELHO);
        printf("\n\n\t\t\t    Opção inválida!");
        Sleep(500);
        goto errocor4;
    }
}



//---------IMOVEIS-------------IMOVEIS----------------IMOVEIS---------------

void CadastroImovel(Console){

    SetConsoleTitle("IMOBILIARIA - Cadastro de Imóvel");
    SetConsoleTextAttribute(Console, BRANCO);

    int validar;
	Arquivo = fopen("ImovelConsulta.txt","a+");
    Imovel = fopen("Imovel.txt","a+");

	printf("\n\n\n\t\tCADASTRO DE IMOVEL\n");


	printf ("\n\t\tQual e o tipo do imóvel");               {} strPlusAl(dim.tipo, 16);
	printf("\n\t\tInforme o endereco do imóvel:");          {} strPlus(dim.end, 50);
	printf("\n\t\tInforme a quantidade de dormitórios:");   {} strPlusNum(dim.dormi, 11);
	printf("\n\t\tQuantidade de banheiros:");               {} strPlusNum(dim.banheiro, 11);
	printf("\n\t\tTem garagem ?(S/N):");                    {} strPlusAl(dim.garagem, 2);
	printf("\n\t\tQuantos metros quadrados: ");             {} strPlusNum(dim.metros, 16);
	printf("\n\t\tValor do imóvel ?(S/N):");                {} strPlusNum(dim.valor, 16);



	fprintf(Imovel,"\nTipo do imóvel:" "%s",dim.tipo);
	fprintf(Imovel,"\nEndereço:" "%s", dim.end);
	fprintf(Imovel,"\nQuantidade de dormitorios:" "%s", dim.dormi);
	fprintf(Imovel,"\nQuantidade de banheiros:" "%s",dim.banheiro);
	fprintf(Imovel,"\nGaragem:" "%s", dim.garagem);
	fprintf(Imovel,"\nMetros quadrados do terreno:" "%s", dim.metros);
	fprintf(Imovel,"\nMetros quadrados construidos:" "%s", dim.valor);


	fclose(Imovel);
	printf("Cadastrado Com sucesso!!");
    // =====================================================

    TirarEspaco(dim.tipo);      {}  fprintf(Arquivo,"\n%s\n",dim.tipo);
	TirarEspaco(dim.end);       {}  fprintf(Arquivo,"%s\n",dim.end);
	TirarEspaco(dim.dormi);     {}  fprintf(Arquivo,"%s\n",dim.dormi);
	TirarEspaco(dim.banheiro);  {}  fprintf(Arquivo,"%s\n",dim.banheiro);
	TirarEspaco(dim.garagem);   {}  fprintf(Arquivo,"%s\n",dim.garagem);
	TirarEspaco(dim.metros);    {}  fprintf(Arquivo,"%s\n",dim.metros);
	TirarEspaco(dim.valor);     {}  fprintf(Arquivo,"%s\n",dim.valor);


    fclose(Arquivo);
    printf("\n\nImóvel Cadastrado Com Sucesso!");
    SetConsoleTextAttribute(Console, BRANCO);

    erroimo1:
	printf("\nPressione 1 para realizar um novo cadastro, ou 0 para sair:");
    SetConsoleTextAttribute(Console, VERDE);
	ctrNumber(&opcaoMenu);

	if(opcaoMenu == '0'){
        system("cls");
		MenuImoveis(Console);
	}
	else if(opcaoMenu == '1'){
        system("cls");
        CadastroImovel(Console);
    }else{
        SetConsoleTextAttribute(Console, VERMELHO);
        printf("\n\n\t\t\t    Opção invalida!");
        Sleep(500);
    goto erroimo1;
    }

}


void ListarImovel(Console){

    char texto_str[100];
    cont =0;

    SetConsoleTitle("IMOBILIARIA - Lista de Imóvel");

    system("cls");
    SetConsoleTextAttribute(Console, VERDE);

    printf("\n\n\t\t\t\tLista de Imovel Cadastrado\n\n");
    SetConsoleTextAttribute(Console, BRANC_ESC);
	Leitura = fopen("Imovel.txt", "r");
	while(fgets(texto_str, 100, Leitura) != NULL){
		printf("\t\t\t%s", texto_str);
        cont++;
        if(cont% 9==0 ){
            // printf("\n\t\t\t=======================================\n");
        }
	}
	//fechando o arquivo
	fclose(Leitura);
    SetConsoleTextAttribute(Console, VERDE);
    printf( "\n\n\n\t\t\t================================================"
	        "\n\t\t\t\tImovel(is) listado com sucesso !");
    opcaoMenu = '0';


    errocli2:
    SetConsoleTextAttribute(Console, BRANCO);
    printf("\n\n\t\t\tDigite 0 para voltar ao menu Imovel: ");

    SetConsoleTextAttribute(Console, VERDE);
	ctrNumber(&opcaoMenu);

	if(opcaoMenu == '0'){
        system("cls");
		MenuImoveis(Console);
    }
    else{
        system("cls");
        SetConsoleTextAttribute(Console, VERMELHO);
        printf("\n\n\t\t\t    Opção inválida!");
        Sleep(500);
    goto errocli2;
    }
}


void EditarImovel(Console){

    SetConsoleTitle("IMOBILIARIA - Editar Cadastro de Imóvel");

    SetConsoleTextAttribute(Console, BRANCO);

    printf("\nEditar Imovel\n\n");
    printf("\n\n\t\tNão da para editar imóveis ainda, mas em breve vai ser possivel\n\n");
	printf("aperte uma tecla para continuar ");

    getch();
    system("cls");
    MenuSobre(Console);
}


void ExcluirImovel(Console){

    SetConsoleTitle("IMOBILIARIA - Excluir Imóvel");

    SetConsoleTextAttribute(Console, BRANCO);
    printf("\n\n\t\tVolte para o menu Imóveis :(");
    getch();
    MenuImoveis(Console);
}


void BuscarImovel(Console){

    SetConsoleTitle("IMOBILIARIA - Busca de Imóvel");

    SetConsoleTextAttribute(Console, BRANCO);

    printf("\n\n\n\t\tEM ATUALIZACÃO");
    getch();
    MenuImoveis(Console);
}



//-------SIMULAÇÃO------------SIMULAÇÃO---------------SIMULAÇÃO--------------

void SimularFinanciamento(Console){

    float val_finan,tempo, juros_ano,saldo_devedor, juros_calc, amortiz, parcela,valor_parcela;


    SetConsoleTitle("IMOBILIARIA - Simular Financiamento");


    SetConsoleTextAttribute(Console, BRANCO);

    //programa
    printf( "\n\n\tSimulado com a tabela SAC\n"
            "\n==============================================");
    printf("\nValor do imóvel: ");
    SetConsoleTextAttribute(Console, VERDE);
    scanf("%f", &val_finan);

    printf("\nQuantidade de meses parcelado: ");
    SetConsoleTextAttribute(Console, VERDE);
    scanf("%f ", &tempo);

    printf("\nDigite o Juros Anual: ");
    SetConsoleTextAttribute(Console, VERDE);
    scanf("%f ",& juros_ano);


    saldo_devedor = val_finan;
    amortiz = val_finan / tempo;
    juros_ano = (juros_ano /100) /12;

    //parcela vale 0
    while (parcela < tempo){

        saldo_devedor = saldo_devedor - amortiz;

        juros_calc = saldo_devedor * juros_ano;

        valor_parcela = juros_calc + amortiz;

        parcela = parcela + 1;
        printf( "parcela: %0.2f || "
                "saldo: %0.2f || "
                "amort.: %0.2f || "
                "juros: %0.2f || "
                "valor: %0.2f \n",
                parcela, saldo_devedor, amortiz, juros_calc, valor_parcela);
    }

    printf("\n\n\tAperte alguma tecla para retornar ao Menu Pricipal: ");
    getch();
    menu(Console);
}
