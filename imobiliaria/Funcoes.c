#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "formatbr.c"


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

// outras funçoes na:
// pasta Projeto_bibliotecaC oinde estar a biblioteca string++
// e no arquivo formatbr.c
void ctrAlnum(char *chart){

    unsigned char ctrLimitar[2];
    unsigned int i = 0, cont=0, enter=0;

    do{
		cont++;
        *chart=getch();
        if (*chart != 13){
            if (isalnum(*chart)!=0){
                if (i < 1){
                    ctrLimitar[i] = *chart;
                    i++;
                    printf ("%c", *chart);
                }
                else if(*chart!='\b' && i){
                    if(i==1){
                        printf("\b");
                        ctrLimitar[i]='\0';
                        i--;
                        printf ("%c", *chart);
                        printf("\b");
                    }
                }
            }
            else if(*chart=='\b'){
                cont=0;
                enter=0;
                if(i==1){
                    printf("\b \b");
                    i--;
                }else if(i==0){
                    printf(" \b");
                }
            }
        }else{
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

    *chart = ctrLimitar[0];
    //return ctrLimitar[0];
}


void ctrNumber(char *num){

    unsigned char ctrLimitar[2];
    unsigned int i = 0, cont=0, enter=0;

    do{
        cont++;
        *num=getch();
        if (*num != 13){
            if (isdigit(*num)!=0){
                if (i < 1){
                    ctrLimitar[i] = *num;
                    i++;
                    printf ("%c", *num);
                }
                else if(*num!='\b' && i){
                    if(i==1){
                        printf("\b");
                        ctrLimitar[i]='\0';
                        i--;
                        printf ("%c", *num);
                        printf("\b");
                    }
                }
            }
            else if(*num=='\b'){
                cont=0;
                enter=0;
                if(i==1){
                    printf("\b \b");
                    i--;
                }else if(i==0){
                    printf(" \b");
                }
            }
        }else{
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

    *num = ctrLimitar[0];
    //return ctrLimitar[0];
}


void ctr(char *c){

    //char c;
    char ctrLimitar[2];
    unsigned int i=0, cont=0, enter=0;

    ctrLimitar[0] == "/0";

    do{
        cont++;
        *c =getch();
        if (*c != 13){
            if(i == 0 && *c!='\b' ){
                ctrLimitar[i] = *c;
                i++;
                printf ("%c", *c);
            }
            else if(*c!='\b' && i){
                if(i==1){
                    printf("\b");
                    ctrLimitar[i]='\0';
                    i--;
                    printf ("%c", *c);
                    printf("\b");
                }
            }
        }
		else if(*c=='\b'){
			cont=0;
			enter=0;
			if(i==1){
				printf("\b \b");
				i--;
			}else if(i==0){
				printf(" \b");
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
    }while (i<2);

    *c = ctrLimitar[0];
    // return ctrLimitar[0];

}


void senhaOculta(char *senha){
    int c = 0;
    while((senha[c] = getch())!=13){
        printf("*");
        c++;
    }
    senha[c] = '\0';
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
	char estCivil[10];
	char end[50];
	char endNum[5];
    char creci[7]
} dadosPessoais;

dadosPessoais dpe;


typedef struct {
	char tipo[16];
	char construido[4];
	char terreno[40];
	char garagem[13];
	char banheiro[11];
	char dormitorios[15];
	char end[50];
	char endNum[5];
    double valor[11];
    float compri[8];
    float lagura[8];
} dadosImoveis;

dadosImoveis dim;

//--------CLIENTE-----------CLIENTE------------------CLIENTE---------------

void CadastroCliente(Console){

	// configuracao da tela
    SetConsoleTitle("IMOBILIARIA - Cadastro de Cliente");
    SetConsoleTextAttribute(Console, BRANCO);
	//FILE* Cliente;
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
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  strPlusAl(dpe.estCivil, 10);
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
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  strPlusNum(dpe.tel, 11);
    //
	SetConsoleTextAttribute(Console, VERDE);        {}  printf("\nInforme seu endere?o de e-mail: ");
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  strPlusAl(dpe.email, 40);


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
	printf("Pressione 1 para realizar um novo cadastro, ou 0 para sair:");
	ctrNumber(&opcaoMenu);

	if(opcaoMenu == '0'){
		MenuCliente(Console);
	}
	else if(opcaoMenu == '1'){
        CadastroCliente();
    }else{
        printf("opção invalida!");
    }

}


void ListarCliente(Console){

    char texto_str[60];// array de string captura os dados em uma linha no arquivo
    cont =0;
    system("cls");
    SetConsoleTextAttribute(Console, VERDE);
    printf("\n\n\t\t\t\tLista de Clientes Cadastrado\n\n");
    SetConsoleTextAttribute(Console, BRANC_ESC);
	Leitura = fopen("Cliente.txt", "r");
	while(fgets(texto_str, 60, Leitura) != NULL){
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
    if(opcaoMenu != '0'){
        SetConsoleTextAttribute(Console, VERDE);
        printf("\n\n\t\t\tPressione 0 para voltar ao menu cliente: ");
    }
    else{
    erromenu1:
        SetConsoleTextAttribute(Console, VERMELHO);
        printf("\n\n\t\t\tPressione 0 para voltar ao menu cliente: ");
    }
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
        goto erromenu1;
    }
}


void EditarCliente(){
    char teste;
    printf("\nEditar cadastro\n\n");
    printf("\n\n\t\tCASO NÃO SAIBA O CPF, PROCURE O CLIENTE NA OPCAO LISTAR CLIENTE OU BUSCAR CLIENTE\n\n");
	printf("Informe o CPF referente ao cadastro que deseja excluir: ");
	cpfm(teste);

    printf( "\ntenha paciência, por favor!"
            "\nAguarde a atualização");
}


void ExcluirCliente(Console){
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
    printf("\nPressione 1 para Excluir outro cadastro, ou 0 para sair:");
	ctrNumber(&opcaoMenu);

    do{
        if(opcaoMenu=='0'){
            MenuCliente(Console);
        }
        else if(opcaoMenu == '1'){
            ExcluirCliente(Console);
        }else{
            SetConsoleTextAttribute(Console, VERMELHO);
            printf("opção invalida!");
        }
    }while(opcaoMenu >= '2');
}


void BuscarCliente(Console){

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
        printf("Nenhum cliente cadastrado com esse CPF");
    }else{
	    printf("\n\nBusca concluida com sucesso !");
    }
        printf("\nDigite 1 para realizar uma nova busca ou 0 para sair:");
	ctrNumber(&opcaoMenu);

	if(opcaoMenu == '0'){
			MenuCliente();
	}
	else if(opcaoMenu == '1'){
			CadastroCliente();
	}else{
        printf("opção invalida!");
    }
}


//---------CORRETOR-----------CORRETOR--------------CORRETOR---------------


void CadastroCorretor(Console){

    SetConsoleTitle("IMOBILIARIA - Cadastro de Corretor");

    Arquivo = fopen("CorretorConsulta.txt","a+");
	Corretor = fopen("Corretor.txt","a+");// verificar se aqui eu abro usando o W  e depois vou usando A para adicionar.

	printf("\n\n\n\t\tCADASTRO DE CORRETOR\n\n");

	SetConsoleTextAttribute(Console, BRANC_ESC);    {}  printf ("\nEscreva seu nome completo: ");
    SetConsoleTextAttribute(Console, VERDE);        {} 	strPlusAl(dpe.nome, 30);
    //
	SetConsoleTextAttribute(Console, VERDE);        {}  printf("\nSexo(F/M): ");
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  strPlusAl(dpe.sexo, 15);
    //
	SetConsoleTextAttribute(Console, VERDE);        {}  printf("\nEstado Civil: ");
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  strPlusAl(dpe.estCivil, 15);
    //
    SetConsoleTextAttribute(Console, BRANC_ESC);    {}  printf("\nendereco S/ número: ");
    SetConsoleTextAttribute(Console, VERDE);        {}  strPlusAl(dpe.end, 20);
    //
    SetConsoleTextAttribute(Console, BRANC_ESC);    {}  printf("\nNúmero do endereco: ");
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  strPlusNum(dpe.endNum, 4);
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
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  strPlusNum(dpe.tel, 11);
    //
	SetConsoleTextAttribute(Console, VERDE);        {}  printf("\nInforme seu endere?o de e-mail: ");
    SetConsoleTextAttribute(Console, AZUL_CLARO);   {}  strPlusAl(dpe.email, 40);
    //

	fprintf(Corretor,"\n\nNome:" "%s",dpe.nome);
	fprintf(Corretor,"\nSexo:" "%s",dpe.sexo);
	fprintf(Corretor,"\nEstado Civil::" "%s",dpe.estCivil);
	fprintf(Corretor,"\nEndereço:" "%s, %s",dpe.end,dpe.endNum);
	fprintf(Corretor,"\nData de Nascimento:" "%s",dpe.dataNas);
	fprintf(Corretor,"\nRegistro Geral:" "%s",dpe.rg);
	fprintf(Corretor,"\nCadastro Pessoa Fisica:" "%s",dpe.cpf);
	fprintf(Corretor,"\nTelefone:" "%s",dpe.tel);
	fprintf(Corretor,"\nEndere?o de e-mail:" "%s",dpe.email);

	fclose(Corretor);
    //============================================

    //função para automatizar isso
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
	printf("\n\nCliente cadastrado com sucesso ! Pressione 1 para realizar um novo cadastro, ou 0 para sair:");
	ctrNumber(&opcaoMenu);

	if(opcaoMenu == '0'){
        MenuCliente();
    }
	else if(opcaoMenu == '1'){
        CadastroCliente();
    }else{
        printf("opção invalida!");
    }

}


void ListarCorretor(Console){


    char texto_str[60];
    cont =0;
    system("cls");
    SetConsoleTextAttribute(Console, VERDE);
    printf("\n\n\t\t\t\tLista de Clientes Cadastrado\n\n");
    SetConsoleTextAttribute(Console, BRANC_ESC);
	Leitura = fopen("Cliente.txt", "r");
	while(fgets(texto_str, 60, Leitura) != NULL){
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
    opcaoMenu = '0';
    if(opcaoMenu != '0'){
        SetConsoleTextAttribute(Console, VERDE);
        printf("\n\n\t\t\tPressione 0 para voltar ao menu cliente: ");
    }
    else{
    erromenu2:
        SetConsoleTextAttribute(Console, VERMELHO);
        printf("\n\n\t\t\tPressione 0 para voltar ao menu cliente: ");
    }
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
        goto erromenu2;
    }
}


void EditarCorretor(){
    char teste;
    printf("\nEditar cadastro\n\n");
    printf("\n\n\t\tCASO NÃO SAIBA O CPF, PROCURE O CLIENTE NA OPCAO LISTAR CLIENTE OU BUSCAR CLIENTE\n\n");
	printf("Informe o CPF referente ao cadastro que deseja excluir: ");
	cpfm(teste);

    printf( "\ntenha paciência, por favor!"
            "\nAguarde a atualização");
}


void ExcluirCorretor(Console){
    int i=0;
	printf("\nExclusão do cadastro\n\n");
	printf("Informe o CPF referente ao cadastro que deseja excluir: ");
	cpfm(buscaCpf);
	Arquivo = fopen("ClienteConsulta.txt","r");
    Cliente = fopen("corretor.txt","r");
	arquivoNovo1 = fopen("CorretorConsulta_novo.txt","w");
	FILE* arquivoNovo2 = fopen("Corretor_novo.txt","w");
	while(!feof(Arquivo)){

        fscanf( Arquivo,"%s %s %s %s %s %s %s %s %s %s",
        dpe.nome, dpe.sexo, dpe.estCivil, dpe.end, dpe.endNum, dpe.dataNas, dpe.rg, dpe.cpf, dpe.tel, dpe.email);// acessar os dados
		if (strcmp(dpe.cpf, buscaCpf)!=0){
            //novo editado
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

        printf("\nPressione 1 para Excluir outro cadastro, ou 0 para sair:");
	ctrNumber(&opcaoMenu);

    do{
        if(opcaoMenu=='0'){
            MenuCorretor(Console);
        }
        else if(opcaoMenu == '1'){
            ExcluirCorretor(Console);
        }else{
            printf("opção invalida!");
        }
    }while(opcaoMenu >= '2');
}


void BuscarCorretor(){

    int i = 0;
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
        printf("\nDigite 1 para realizar uma nova busca ou 0 para sair:");
	ctrNumber(&opcaoMenu);

	if(opcaoMenu == '0'){
			MenuCliente();
	}
	else if(opcaoMenu == '1'){
			CadastroCliente();
	}else{
        printf("opção invalida!");
    }

}



//---------IMOVEIS-------------IMOVEIS----------------IMOVEIS---------------

void CadastroImovel(){


	// FILE* cadastro;

	// cadastro = fopen("CadastroImovel.txt","a+");// verificar se aqui eu abro usando o W  e depois vou usando A para adicionar.
	// printf("CADASTRO DE IMOVEL\n");


	// printf ("\nQual e o tipo do im?vel(Aluguel ou Venda):");
	// scanf("%s",&tipo);
	// printf("Informe o endereco do imovel:");
	// scanf("%s",&endereco);
	// printf("Informe a quantidade de dormitorios:");
	// scanf("%s",&dormitorios);
	// printf("Quantidade de banheiros:");
	// scanf("%s",&banheiro);
	// printf("Quantos metros quadrados de terreno:");
	// scanf("%s", &terreno);
	// printf("Quantos metros quadrados construidos:");
	// scanf("%s", &construido);
	// printf("Tem garagem ?(S/N):");
	// scanf("%s", &garagem);

	// fprintf(cadastro,"\nTipo de negociacao:" "%s",tipo);
	// fprintf(cadastro,"\nEndereco:" "%s", endereco);
	// fprintf(cadastro,"\nQuantidade de dormitorios:" "%s", dormitorios);
	// fprintf(cadastro,"\nQuantidade de banheiros:" "%s",banheiro);
	// fprintf(cadastro,"\nMetros quadrados do terreno:" "%s", terreno);
	// fprintf(cadastro,"\nMetros quadrados construidos:" "%s", construido);
	// fprintf(cadastro,"\nGaragem:" "%s", garagem);


	// fclose(cadastro);
	// printf("Cadastrado Com sucesso!!");
}


void ListarImovel(Console){

    char texto_str[60];// array de string captura os dados em uma linha no arquivo
    cont =0;
    system("cls");
    SetConsoleTextAttribute(Console, VERDE);
    printf("\n\n\t\t\t\tLista de Imoveis Cadastrado\n\n");
    SetConsoleTextAttribute(Console, BRANC_ESC);
	Leitura = fopen("Cliente.txt", "r");
	while(fgets(texto_str, 60, Leitura) != NULL){
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
    if(opcaoMenu != '0'){
        SetConsoleTextAttribute(Console, VERDE);
        printf("\n\n\t\t\tPressione 0 para voltar ao menu cliente: ");
    }
    else{
    erromenu1:
        SetConsoleTextAttribute(Console, VERMELHO);
        printf("\n\n\t\t\tPressione 0 para voltar ao menu cliente: ");
    }
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
        goto erromenu1;
    }
}


void EditarImovel(){
    printf("\nEditar cadastro\n\n");
    printf("\n\n\t\tCASO NÃO SAIBA O CPF, PROCURE O CLIENTE NA OPCAO LISTAR CLIENTE OU BUSCAR CLIENTE\n\n");
	printf("Informe o CPF referente ao cadastro que deseja excluir: ");
	cpfm(buscaCpf);

    printf( "\ntenha paciência, por favor!"
            "\nAguarde a atualização");
}


void ExcluiImovel(Console){
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
    printf("\nPressione 1 para Excluir outro cadastro, ou 0 para sair:");
	ctrNumber(&opcaoMenu);

    do{
        if(opcaoMenu=='0'){
            MenuCliente(Console);
        }
        else if(opcaoMenu == '1'){
            ExcluirCliente(Console);
        }else{
            SetConsoleTextAttribute(Console, VERMELHO);
            printf("opção invalida!");
        }
    }while(opcaoMenu >= '2');
}


void BuscarImovel(){
	FILE *Leitura;// tipo de arquivo FILE --> SEMPRE ELE EM MAIUSCULO
	char texto_str[200];// array de string

	// fa?o a atribuai?ao do meu ponteiro para qual arquivo quero abrir e como vai ser a abertura dele.
	Leitura = fopen("CadastroImovel.txt", "r");
	//fa?o um loop aqui para nao parar de ler enquanto nao achar algo igual a null
	while(fgets(texto_str, 20, Leitura) != NULL)
	{
		printf("%s", texto_str);
	}
	//fechando o arquivo
	fclose(Leitura);
	getch();
	return(0);
}



//-------SIMULAÇÃO------------SIMULAÇÃO---------------SIMULAÇÃO--------------

void SimularFinanciamento(){
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

