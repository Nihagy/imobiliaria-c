#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "formatbr.c"
#include "string++.h"


// variaveis globais funcóes de acordo com o menu selecionado
FILE* Arquivo;
FILE* Cliente;
FILE* Corretor;
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
#define  DARK_MAGENTA       5
#define  DARK_YELLOW        6
#define  BRANC_ESC          7
#define  CINZA              8
#define  ROXO               9
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


void senhaOculta(char *senha){
    int c = 0;
    while((senha[c] = getch())!=13){
        printf("*");
        c++;
    }
    senha[c] = '\0';
}

//=========Estrutura=============

typedef struct {
	char nome[40];
	char dataNas[11];
	char email[40];
	char rg[13];
	char cpf[15];
	char tel[11];
	char cel[11];
	char sexo[13];
	char estCivil[13];
	char end[50];
	char endNum[5];
    char creci[8]
} dadosPessoais;

dadosPessoais dpe;


typedef struct {
	char tipo[16];
	char constru[4];
	char terreno[40];
	char garagem[13];
	char banheiro[11];
	char dormi[15];
	char end[50];
	char endNum[5];
    double valor[11];
    float metros[10];
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
	SetConsoleTextAttribute(Console, VERDE);        {}  printf("\nSexo(F/M): ");
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  strPlusAl(dpe.sexo, 13);
    //
	SetConsoleTextAttribute(Console, VERDE);        {}  printf("\nEstado Civil: ");
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  strPlusAl(dpe.estCivil, 13);
    //
    SetConsoleTextAttribute(Console, BRANC_ESC);    {}  printf("\nendereco S/ número: ");
    SetConsoleTextAttribute(Console, VERDE);        {}  strPlusAl(dpe.end, 50);
    //
    SetConsoleTextAttribute(Console, BRANC_ESC);    {}  printf("\nNúmero do endereco: ");
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  strPlusNum(dpe.endNum, 5);
    //
	SetConsoleTextAttribute(Console, VERDE);        {}  printf("\nData de Nascimento: ");
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  dataf(dpe.dataNas);
    //
	SetConsoleTextAttribute(Console, VERDE);        {}  printf("\nN?mero de RG: ");
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  rgm(dpe.rg);
    //
	SetConsoleTextAttribute(Console, VERDE);        {}  printf("\nN?mero de CPF: ");
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  cpfm(dpe.cpf);
    //
	SetConsoleTextAttribute(Console, VERDE);        {}  printf("\nTelefone: ");
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  strPlusNum(dpe.tel, 12);
    //
    valEmailcli:
	SetConsoleTextAttribute(Console, VERDE);        {}  printf("\nInforme seu endere?o de e-mail: ");
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  validar = emailf(dpe.email);
    if(validar==0){
        SetConsoleTextAttribute(Console, VERMELHO);
        printf("\nE-mail Inválido digite novamente\n");
        goto valEmailcli;
    }


	fprintf(Cliente,"\n\nNome:" "%s",dpe.nome);
	fprintf(Cliente,"\nSexo:" "%s",dpe.sexo);
	fprintf(Cliente,"\nEstado Civil::" "%s",dpe.estCivil);
	fprintf(Cliente,"\nEndereço:" "%s, %s",dpe.end,dpe.endNum);
	fprintf(Cliente,"\nData de Nascimento:" "%s",dpe.dataNas);
	fprintf(Cliente,"\nRegistro Geral:" "%s",dpe.rg);
	fprintf(Cliente,"\nCadastro Pessoa Fisica:" "%s",dpe.cpf);
	fprintf(Cliente,"\nTelefone:" "%s",dpe.tel);
	fprintf(Cliente,"\nEndere?o de e-mail:" "%s",dpe.email);

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
	system("cls");
    SetConsoleTextAttribute(Console, BRANCO);

    errocli1:
	printf("Pressione 1 para realizar um novo cadastro, ou 0 para sair:");
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
        printf("\n\n\t\t\t    Opção invalida!");
        Sleep(500);
    goto errocli1;
    }
}

//1.2
void ListarCliente(Console){

    char texto_str[150];// array de string captura os dados em uma linha no arquivo
    cont =0;

    system("cls");
    SetConsoleTextAttribute(Console, VERDE);
    printf("\n\n\t\t\t\tLista de Clientes Cadastrado\n\n");
    SetConsoleTextAttribute(Console, BRANC_ESC);
	Leitura = fopen("Cliente.txt", "r");
	while(fgets(texto_str, 100, Leitura) != NULL){
		printf("\t\t\t%s", texto_str);
        cont++;
        if(cont% 9==0 ){
            printf("\n\t\t\t=======================================\n");
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
        printf("\n\n\t\t\t    Opção invalida!");
        Sleep(500);
    goto errocli2;
    }
}

//1.5
void EditarCliente(Console){
    char teste;

    SetConsoleTextAttribute(Console, BRANCO);

    printf("\nEditar cadastro\n\n");
    printf("\n\n\t\tCASO NÃO SAIBA O CPF, PROCURE O CLIENTE NA OPCAO LISTAR CLIENTE OU BUSCAR CLIENTE\n\n");
	printf("Informe o CPF referente ao cadastro que deseja excluir: ");
	cpfm(teste);

    printf( "\ntenha paciência, por favor!"
            "\nAguarde a atualização");
    getch();
    system("cls");
    MenuCliente(Console);
}

//1.3
void ExcluirCliente(Console){

    if (!arquivo_existe("ClienteConsulta.txt")){
        printf("\n\n\tnão existe cadastro");
    }else{
        int i=0;
        printf("\nExclusão do cadastro\n\n");
        printf("Informe o CPF referente ao cadastro que deseja excluir: ");
        cpfm(buscaCpf);
        Arquivo = fopen("ClienteConsulta.txt","r");
        Cliente = fopen("Cliente.txt","r");
        arquivoNovo1 = fopen("ClienteConsulta_novo.txt","w");
        FILE* arquivoNovo2 = fopen("Cliente_novo.txt","w");
        while(!feof(Arquivo)){

            fscanf( Arquivo,"%s %s %s %s %s %s %s %s %s %s",
            dpe.nome, dpe.sexo, dpe.estCivil, dpe.end, dpe.endNum, dpe.dataNas, dpe.rg, dpe.cpf, dpe.tel, dpe.email);// acessar os dados
            if (strcmp(dpe.cpf, buscaCpf)!=0){
                //editado
                ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\n\nNome:" "%s",dpe.nome);
                ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nSexo:" "%s",dpe.sexo);
                ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nEstado Civil::" "%s",dpe.estCivil);
                ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nEndereco:" "%s, %s",dpe.end,dpe.endNum);
                ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nData de Nascimento:" "%s",dpe.dataNas);
                ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nRegistro Geral:" "%s",dpe.rg);
                ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nCadastro Pessoa F?sica:" "%s",dpe.cpf);
                ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nTelefone:" "%s",dpe.tel);
                ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nEndere?o de e-mail:" "%s",dpe.email);
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
                //novo editado
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
    printf("\nPressione 1 para Excluir outro cadastro, ou 0 para sair:");
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
        printf("\n\n\t\t\t    Opção invalida!");
        Sleep(500);
        goto errocli3;
    }
}

//1.4
void BuscarCliente(Console){

    if (!arquivo_existe("ClienteConsulta.txt")){
        printf("\n\n\tnão existe cadastro");
    }else{
        int i = 0;
        printf("\nBuscar cliente\n\n");
        printf("Informe o cpf ");
        cpfm(buscaCpf);
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
            printf("\nNenhum cliente cadastrado com esse CPF");
        }else{
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

	SetConsoleTextAttribute(Console, VERDE);        {}  printf ("\nEscreva seu nome completo: ");
    SetConsoleTextAttribute(Console,  AZUL_CLARO);  {} 	strPlusAl(dpe.nome, 40);
    //
	SetConsoleTextAttribute(Console, VERDE);        {}  printf("\nSexo(F/M): ");
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  strPlusAl(dpe.sexo, 13);
    //
	SetConsoleTextAttribute(Console, VERDE);        {}  printf("\nCreci: ");
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  strPlusNum(dpe.creci, 8);
    //
	SetConsoleTextAttribute(Console, VERDE);        {}  printf("\nEstado Civil: ");
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  strPlusAl(dpe.estCivil, 13);
    //
    SetConsoleTextAttribute(Console, BRANC_ESC);    {}  printf("\nendereco S/ número: ");
    SetConsoleTextAttribute(Console, VERDE);        {}  strPlusAl(dpe.end, 50);
    //
    SetConsoleTextAttribute(Console, BRANC_ESC);    {}  printf("\nNúmero do endereco: ");
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  strPlusNum(dpe.endNum, 5);
    //
	SetConsoleTextAttribute(Console, VERDE);        {}  printf("\nData de Nascimento: ");
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  dataf(dpe.dataNas);
    //
	SetConsoleTextAttribute(Console, VERDE);        {}  printf("\nN?mero de RG: ");
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  rgm(dpe.rg);
    //
	SetConsoleTextAttribute(Console, VERDE);        {}  printf("\nN?mero de CPF: ");
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  cpfm(dpe.cpf);
    //
	SetConsoleTextAttribute(Console, VERDE);        {}  printf("\nTelefone: ");
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  strPlusNum(dpe.tel, 12);
    //
    valEmail:
	SetConsoleTextAttribute(Console, VERDE);        {}  printf("\nInforme seu endere?o de e-mail: ");
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  //strPlusAl(dpe.email, 40);
    validar = emailf(dpe.email);
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
	fprintf(Corretor,"\nData de Nascimento:" "%s",dpe.dataNas);
	fprintf(Corretor,"\nRegistro Geral:" "%s",dpe.rg);
	fprintf(Corretor,"\nCadastro Pessoa Fisica:" "%s",dpe.cpf);
	fprintf(Corretor,"\nTelefone:" "%s",dpe.tel);
	fprintf(Corretor,"\nEndere?o de e-mail:" "%s",dpe.email);

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
    system("cls");
    SetConsoleTextAttribute(Console, BRANCO);

    errocor1:
	printf("\n\nCliente cadastrado com sucesso ! Pressione 1 para realizar um novo cadastro, ou 0 para sair:");
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
        printf("\n\n\t\t\t    Opção invalida!");
        Sleep(500);
        goto errocor1;
    }

}

//2.2
void ListarCorretor(Console){
    char texto_str[200];
    cont =0;

    system("cls");
    SetConsoleTextAttribute(Console, VERDE);
    printf("\n\n\t\t\t\tLista de Corretores Cadastrado\n\n");
    SetConsoleTextAttribute(Console, BRANC_ESC);
	Leitura = fopen("Corretor.txt", "r");
	while(fgets(texto_str, 200, Leitura) != NULL){
		printf("\t\t\t%s", texto_str);
        cont++;
        if(cont% 9==0 ){
            printf("\n\t\t\t=======================================\n");
        }
	}
	//fechando o arquivo
	fclose(Leitura);
    SetConsoleTextAttribute(Console, VERDE);
    printf( "\n\n\n\t\t\t================================================"
	        "\n\t\t\t\tCorretores(s) listado com sucesso !");



    errocor2:
    SetConsoleTextAttribute(Console, VERDE);
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
        printf("\n\n\t\t\t    Opção invalida!");
        Sleep(500);
    goto errocor2;
    }
}

//2.3
void EditarCorretor(Console){
    char teste;

    SetConsoleTextAttribute(Console, BRANCO);

    printf("\nEditar cadastro\n\n");
    printf("\n\n\t\tFaça o teste vai que da certo, não custa tentar\n\n");
	printf("Informe o CPF referente ao cadastro que deseja excluir: ");
	cpfm(teste);

    printf( "\ntenha paciência, por favor!"
            "\nAguarde a atualização");
    getch();
    system("cls");
    MenuCorretor(Console);
}

//2.4
void ExcluirCorretor(Console){

    SetConsoleTextAttribute(Console, BRANCO);

    if (!arquivo_existe("ClienteConsulta.txt")){
        printf("\n\n\tnão existe cadastro");
    }else{
        int i=0;
        printf("\nExclusão do cadastro\n\n");
        printf("Informe o CPF referente ao cadastro que deseja excluir: ");
        cpfm(buscaCpf);
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
                ColocarEspaco(dpe.endNum);  {}  fprintf(arquivoNovo2,"\nEndereco:" "%s, %s",dpe.end,dpe.endNum);
                ColocarEspaco(dpe.dataNas);    {}  fprintf(arquivoNovo2,"\nData de Nascimento:" "%s",dpe.dataNas);
                ColocarEspaco(dpe.rg);    {}  fprintf(arquivoNovo2,"\nRegistro Geral:" "%s",dpe.rg);
                ColocarEspaco(dpe.cpf);    {}  fprintf(arquivoNovo2,"\nCadastro Pessoa F?sica:" "%s",dpe.cpf);
                ColocarEspaco(dpe.tel);    {}  fprintf(arquivoNovo2,"\nTelefone:" "%s",dpe.tel);
                ColocarEspaco(dpe.email);    {}  fprintf(arquivoNovo2,"\nEndere?o de e-mail:" "%s",dpe.email);
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
            printf("Cadastro excluido");
            printf( "\n\nCorretor Excluido com sucesso !");
        }
    }
    errocor3:
    printf("\nPressione 1 para Excluir outro cadastro, ou 0 para sair:");
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
        printf("\n\n\t\t\t    Opção invalida!");
        Sleep(500);
        goto errocor3;
    }
}

//2.5
void BuscarCorretor(Console){
    if (!arquivo_existe("CorretorConsulta.txt")){
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
            printf("Nenhum Corretor cadastrado com esse CPF");
        }else{
            printf("\n\nBusca concluida com sucesso !");
        }
    }
    errocor4:
    printf("\nDigite 1 para realizar uma nova busca ou 0 para sair:");
	ctrNumber(&opcaoMenu);

	if(opcaoMenu == '0'){
        system("cls");
		BuscarCorretor(Console);
	}
	else if(opcaoMenu == '1'){
        system("cls");
		CadastroCorretor(Console);
	}else{
        system("cls");
        SetConsoleTextAttribute(Console, VERMELHO);
        printf("\n\n\t\t\t    Opção invalida!");
        Sleep(500);
        goto errocor4;
    }
}



//---------IMOVEIS-------------IMOVEIS----------------IMOVEIS---------------

void CadastroImovel(Console){

    SetConsoleTextAttribute(Console, BRANCO);

	// FILE* cadastro;

	// cadastro = fopen("CadastroImovel.txt","a+");// verificar se aqui eu abro usando o W  e depois vou usando A para adicionar.
	// printf("CADASTRO DE IMOVEL\n");


	// printf ("\nQual e o tipo do imóvel");               {} strPlusAl(dim.tipo, 16);
	// printf("Informe o endereco do imovel:");            {} strPlusAl(dim.end, 50);
	// printf("Informe a quantidade de dormitorios:");     {} strPlusAl(dim.dormi, 11);
	// printf("Quantidade de banheiros:");                 {} strPlusAl(dim.banheiro, 11);
	// printf("Quantos metros quadrados de terreno:");     {} strPlusAl(dim.metros, 11);
	// printf("Tem garagem ?(S/N):");                      {} strPlusAl(dim.garagem, 16);
	// printf("Quantos metros quadrados: ");               {} strPlusAl(dim.metros, 16);
	// printf("Tem garagem ?(S/N):");                      {} strPlusAl(dim.valor, 16);



	// fprintf(cadastro,"\nTipo de negociacao:" "%s",tipo);
	// fprintf(cadastro,"\nEndereco:" "%s", endereco);
	// fprintf(cadastro,"\nQuantidade de dormitorios:" "%s", dormitorios);
	// fprintf(cadastro,"\nQuantidade de banheiros:" "%s",banheiro);
	// fprintf(cadastro,"\nMetros quadrados do terreno:" "%s", terreno);
	// fprintf(cadastro,"\nMetros quadrados construidos:" "%s", construido);
	// fprintf(cadastro,"\nGaragem:" "%s", garagem);


	// fclose(cadastro);
	// printf("Cadastrado Com sucesso!!");
    // // =====================================================

    // TirarEspaco(dpe.nome);      {}  fprintf(Arquivo,"\n%s\n",dpe.nome);
	// TirarEspaco(dpe.sexo);      {}  fprintf(Arquivo,"%s\n",dpe.sexo);
	// TirarEspaco(dpe.estCivil);  {}  fprintf(Arquivo,"%s\n",dpe.estCivil);
	// TirarEspaco(dpe.end);       {}  fprintf(Arquivo,"%s\n",dpe.end);
	// TirarEspaco(dpe.endNum);    {}  fprintf(Arquivo,"%s\n",dpe.endNum);
	// TirarEspaco(dpe.dataNas);   {}  fprintf(Arquivo,"%s\n",dpe.dataNas);
	// TirarEspaco(dpe.rg);        {}  fprintf(Arquivo,"%s\n",dpe.rg);
	// TirarEspaco(dpe.cpf);       {}  fprintf(Arquivo,"%s\n",dpe.cpf);
	// TirarEspaco(dpe.tel);       {}  fprintf(Arquivo,"%s\n",dpe.tel);
	// TirarEspaco(dpe.email);     {}  fprintf(Arquivo,"%s\n",dpe.email);


    // fclose(Arquivo);
    // printf("\n\nCorretor Cadastrado Com Sucesso!");
	// system("cls");
    // SetConsoleTextAttribute(Console, BRANCO);
	// printf("Pressione 1 para realizar um novo cadastro, ou 0 para sair:");
	// ctrNumber(&opcaoMenu);

	// if(opcaoMenu == '0'){
	// 	MenuCliente(Console);
	// }
	// else if(opcaoMenu == '1'){
    //     CadastroCliente();
    // }else{
    //     printf("opção invalida!");
    // }

}


void ListarImovel(Console){
    SetConsoleTextAttribute(Console, BRANCO);
}

void EditarImovel(Console){

    SetConsoleTextAttribute(Console, BRANCO);
    printf("\nEditar cadastro\n\n");
    printf("\n\n\t\tNão da para editar imóveis ainda, mas em breve vai ser possivel\n\n");
	printf("aperte uma tecla para continuar ");

    getch();
    system("cls");
    MenuCliente(Console);
}


void ExcluiImovel(Console){
    SetConsoleTextAttribute(Console, BRANCO);
}


void BuscarImovel(Console){
    SetConsoleTextAttribute(Console, BRANCO);
}



//-------SIMULAÇÃO------------SIMULAÇÃO---------------SIMULAÇÃO--------------

void SimularFinanciamento(Console){
    SetConsoleTextAttribute(Console, BRANCO);

    float valorImovel, calculo1, calculo2, porcentagem;

    printf("Informe o valor do imóvel R$:");
    scanf("%f", &valorImovel);
    printf("Informe a porcentagem para o estado de SP:");
    scanf("%f", &porcentagem);

    calculo1 = (porcentagem / 100) * valorImovel;
    calculo2 = valorImovel + calculo1;
    system("cls");
    printf("Com a porcentagem de %.0f %%, o valor final do im?vel ser? de %.2f.", porcentagem, calculo2);
    getch();

    //======================================================

    float valor_financiado,tempo, juro_anual,saldo_devedor, juro_calculado, amortizacao, parcela,valor_parcela;



    printf("Tabela Sac - (tbsac)\t\n\n");

    printf("Valor Finaciado: ");

    scanf("%f", &valor_financiado);

    printf("Digite Tempo de financiamento: ");

    scanf("%f ", &tempo);

    printf("Digite juro_anual: ");

    scanf("%f ",& juro_anual);



    saldo_devedor = valor_financiado;

    juro_anual = (juro_anual /100) /12;

    amortizacao = valor_financiado / tempo;





    while (parcela < tempo){

    saldo_devedor = saldo_devedor - amortizacao;

    juro_calculado = saldo_devedor * juro_anual;

    valor_parcela = juro_calculado + amortizacao;

    parcela = parcela + 1;

    printf("parcela: %0.2f saldo: %0.2f amort.: %0.2f juros: %0.2f valor: %0.2f \n", parcela, saldo_devedor, amortizacao, juro_calculado, valor_parcela);

    }

}




/*

void SimularSac(){
    float Valor_Financiado,Tempo, Juros_ano;
    float Saldo_devedor, Juros_calc, Amortizacao, Parcela;

    printf("Tabela Sac - (tbsac)\t\n\n");
    printf("Valor Finaciado: ");
    scanf("%f", & Valor_Financiado);
    printf("Tempo: ");
    scanf("%f ", & Tempo);
    printf("Juros ao ano: ");
    scanf("%f ",& Juros_ano);
    printf("Saldo devedor: ");
    scanf("%f", & Saldo_devedor);
    printf("Juros calc: ");
    scanf("%f ", & Juros_calc);
    printf("Amortizacao: ");
    scanf("%f ", & Amortizacao);
    printf("Parcela: ");
    scanf("%f ", & Parcela);

    while( Parcela = (contador==contador+1){
        if(Amortizacao==Valor_Financiado)
        Amortizacao==Valor Financiado/Tempo;
    }
    while{
        if(Saldo devedor==Valor Financiado - Amortizacao)
        Saldo devedor==Valor Financiado - Parcela;
        }
        else{
            if(Juros calc==Saldo devedor*Taxa de Juros)
            Juros calc==Valor Finaciado*((10/100)/12);
        }
        else{
            if(Parcela==Amortizacao+Juros ao ano)
            Parcela==Amortizacao+Juros calc;
        }

     system("pause");

}



void SimularPrice(){

}
*/

