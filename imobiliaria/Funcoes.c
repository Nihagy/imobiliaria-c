#include <stdio.h>
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
	char nome[50];
	char dataNas[11];
	char email[40];
	char rg[13];
	char cpf[15];
	char tel[11];
	char cel[11];
	char sexo[15];
	char estCivil[15];
	char end[20];
	char endNum[4];
    char creci[7]
} dadosPessoais;

dadosPessoais dpe;
//--------CLIENTE-----------CLIENTE------------------CLIENTE---------------

// Cadastrar Cliente
// Editar Cadastro
// Buscar Cliente
// Excluir Cliente

void CadastroCliente(){

	// configuracao da tela
    setlocale(LC_ALL, "Portuguese");

	//FILE* Cliente;
	Arquivo = fopen("ClienteConsulta.txt","a+");

	Cliente = fopen("Cliente.txt","a+");// verificar se aqui eu abro usando o W  e depois vou usando A para adicionar.
	printf("\n\n\n\t\tCADASTRO DE CLIENTE\n\n");

	printf ("\nEscreva seu nome completo: "); 		{} 	strPlusAl(dpe.nome, 30);
    printf("\nendereco S/ número: ");				{}	strPlusAl(dpe.end, 20);
    printf("\nNúmero do endereco: ");				{}	strPlusNum(dpe.endNum, 4);
	printf("\nTelefone: ");							{}	strPlusNum(dpe.tel, 11);
	printf("\nData de Nascimento: ");				{}	dataf(dpe.dataNas);
	printf("\nSexo(F/M): ");						{}	strPlusAl(dpe.sexo, 15);
	printf("\nInforme seu endere?o de e-mail: ");	{}	strPlusAl(dpe.email, 40);
	printf("\nN?mero de RG: ");						{}	rgm(dpe.rg);
	printf("\nN?mero de CPF: ");					{}	cpfm(dpe.cpf);
	printf("\nEstado Civil: ");						{}	strPlusAl(dpe.estCivil, 15);

	fprintf(Cliente,"\nNome:" "%s",dpe.nome);
	fprintf(Cliente,"\nEndereco:" "%s, %s",dpe.end,dpe.endNum);
	fprintf(Cliente,"\nTelefone:" "%s",dpe.tel);
	fprintf(Cliente,"\nData de Nascimento:" "%s",dpe.dataNas);
	fprintf(Cliente,"\nSexo:" "%s",dpe.sexo);
	fprintf(Cliente,"\nEndere?o de e-mail:" "%s",dpe.email);
	fprintf(Cliente,"\nRegistro Geral:" "%s",dpe.rg);
	fprintf(Cliente,"\nCadastro Pessoa Fisica:" "%s",dpe.cpf);
	fprintf(Cliente,"\nEstado Civil::" "%s",dpe.estCivil);

	fclose(Cliente);
    //============================================

    //fprintf(Arquivo,"\n");
	TirarEspaco(dpe.nome);      {}  fprintf(Arquivo,"%s\n",dpe.nome);
	TirarEspaco(dpe.end);       {}  fprintf(Arquivo,"%s\n",dpe.end);
	TirarEspaco(dpe.endNum);    {}  fprintf(Arquivo,"%s\n",dpe.endNum);
	TirarEspaco(dpe.tel);       {}  fprintf(Arquivo,"%s\n",dpe.tel);
	TirarEspaco(dpe.dataNas);   {}  fprintf(Arquivo,"%s\n",dpe.dataNas);
	TirarEspaco(dpe.sexo);      {}  fprintf(Arquivo,"%s\n",dpe.sexo);
	TirarEspaco(dpe.email);     {}  fprintf(Arquivo,"%s\n",dpe.email);
	TirarEspaco(dpe.rg);        {}  fprintf(Arquivo,"%s\n",dpe.rg);
	TirarEspaco(dpe.cpf);       {}  fprintf(Arquivo,"%s\n",dpe.cpf);
	TirarEspaco(dpe.estCivil);  {}  fprintf(Arquivo,"%s",dpe.estCivil);

    fclose(Arquivo);
	system("cls");
	printf("Cliente cadastrado com sucesso ! Pressione 1 para realizar um novo cadastro, ou 0 para sair:");
	scanf("%i", &opcaoMenu);

	if(opcaoMenu==0)
		{
			MenuCliente();
		}
	else
		{
			CadastroCliente();
		}
}


void RelatorioCliente(){

    // char texto_str[50];
    // int i;
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
                dpe.nome, dpe.end, dpe.endNum, dpe.tel, dpe.dataNas, dpe.sexo, dpe.email, dpe.rg, dpe.cpf, dpe.estCivil);
        // fscanf(Arquivo,"%s",dpe.cpf);      {}//  TirarEspaco(dpe.cpf);
        // fscanf(Arquivo,"%s",dpe.nome);     {}//  ColocarEspaco(dpe.nome);
        // fscanf(Arquivo,"%s",dpe.tel);      {}//  TirarEspaco(dpe.tel);
        // fscanf(Arquivo,"%s",dpe.dataNas);  {}//  TirarEspaco(dpe.dataNas);
        // fscanf(Arquivo,"%s",dpe.sexo);     {}//  TirarEspaco(dpe.sexo);
        // fscanf(Arquivo,"%s",dpe.email);    {}//  TirarEspaco(dpe.email);
        // fscanf(Arquivo,"%s",dpe.rg);       {}//  TirarEspaco(dpe.rg);
        // fscanf(Arquivo,"%s",dpe.estCivil); {}//  TirarEspaco(dpe.estCivil);

		if (strcmp(dpe.cpf, buscaCpf)==0){
            ColocarEspaco(dpe.nome);    {}  printf("\nNome:" "%s",dpe.nome);
            ColocarEspaco(dpe.nome);    {}  printf("\nEndereco:" "%s,%s",dpe.end,dpe.endNum);
            ColocarEspaco(dpe.nome);    {}  printf("\nTelefone:" "%s",dpe.tel);
            ColocarEspaco(dpe.nome);    {}  printf("\nData de Nascimento:" "%s",dpe.dataNas);
            ColocarEspaco(dpe.nome);    {}  printf("\nSexo:" "%s",dpe.sexo);
            ColocarEspaco(dpe.nome);    {}  printf("\nEndere?o de e-mail:" "%s",dpe.email);
            ColocarEspaco(dpe.nome);    {}  printf("\nRegistro Geral:" "%s",dpe.rg);
            ColocarEspaco(dpe.nome);    {}  printf("\nCadastro Pessoa F?sica:" "%s",dpe.cpf);
            ColocarEspaco(dpe.nome);    {}  printf("\nEstado Civil::" "%s",dpe.estCivil);

		}
	}
	fclose(Arquivo);
	getch();
}


void BuscarCliente(){

    char texto_str[60];// array de string

	// fa�o a atribuai?ao do meu ponteiro para qual arquivo quero abrir e como vai ser a abertura dele.
	Leitura = fopen("Cliente.txt", "r");
    printf("\n`\n");
	//fa?o um loop aqui para nao parar de ler enquanto nao achar algo igual a null
	while(fgets(texto_str, 5, Leitura) != NULL)
	{
		printf("%s", texto_str);
	}
	//fechando o arquivo
	fclose(Leitura);
	getch();
}


void ExcluirCliente(){

	printf("\nExclusão do cadastro\n\n");
	printf("Informe o CPF referente ao cadastro que deseja excluir: ");
	cpfm(buscaCpf);
	Arquivo = fopen("ClienteConsulta.txt","r"); // abrir arquivo em modo leitura
    // Cliente = fopen("Cliente.txt","r");
	arquivoNovo1 = fopen("ClienteConsulta_novo.txt","w");
	FILE* arquivoNovo2 = fopen("Cliente_novo.txt","w");
	while(!feof(Arquivo)){

        fscanf( Arquivo,"%s %s %s %s %s %s %s %s %s %s",
        dpe.nome, dpe.end, dpe.endNum, dpe.tel,dpe.dataNas, dpe.sexo,dpe.email,dpe.rg, dpe.cpf, dpe.estCivil);// acessar os dados
		if (strcmp(dpe.cpf, buscaCpf)!=0){
            //editado

            ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nNome:" "%s",dpe.nome);
            ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nEndereco:" "%s, %s",dpe.end,dpe.endNum);
            ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nTelefone:" "%s",dpe.tel);
            ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nData de Nascimento:" "%s",dpe.dataNas);
            ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nSexo:" "%s",dpe.sexo);
            ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nEndere?o de e-mail:" "%s",dpe.email);
            ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nRegistro Geral:" "%s",dpe.rg);
            ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nCadastro Pessoa F?sica:" "%s",dpe.cpf);
            ColocarEspaco(dpe.nome);    {}  fprintf(arquivoNovo2,"\nEstado Civil::" "%s",dpe.estCivil);
            // novo em linha
            TirarEspaco(dpe.nome);      {}  fprintf(arquivoNovo1,"%s\n",dpe.nome);
            TirarEspaco(dpe.end);       {}  fprintf(arquivoNovo1,"%s\n",dpe.end);
            TirarEspaco(dpe.endNum);    {}  fprintf(arquivoNovo1,"%s\n",dpe.endNum);
            TirarEspaco(dpe.tel);       {}  fprintf(arquivoNovo1,"%s\n",dpe.tel);
            TirarEspaco(dpe.dataNas);   {}  fprintf(arquivoNovo1,"%s\n",dpe.dataNas);
            TirarEspaco(dpe.sexo);      {}  fprintf(arquivoNovo1,"%s\n",dpe.sexo);
            TirarEspaco(dpe.email);     {}  fprintf(arquivoNovo1,"%s\n",dpe.email);
            TirarEspaco(dpe.rg);        {}  fprintf(arquivoNovo1,"%s\n",dpe.rg);
            TirarEspaco(dpe.cpf);       {}  fprintf(arquivoNovo1,"%s\n",dpe.cpf);
            TirarEspaco(dpe.estCivil);  {}  fprintf(arquivoNovo1,"%s\n",dpe.estCivil);
            //novo editado
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

	printf("Cadastro excluido");
}


//---------CORRETOR-----------CORRETOR--------------CORRETOR---------------

void CadastroCorretor(){

    Arquivo = fopen("CorretorConsulta.txt","a+");
	Corretor = fopen("Corretor.txt","a+");// verificar se aqui eu abro usando o W  e depois vou usando A para adicionar.

		if (Corretor == NULL){
			printf("abertura nao foi bem sucedida");
		}
		else{
			printf("deu bom a abertura do arquivo!\n");
		}
	printf("\nCADASTRO DO CORRETOR!!\n");


	printf ("\nEscreva seu nome completo: "); 		{} 	strPlusAl(dpe.nome, 30);
    printf("\nendereco S/ número: ");				{}	strPlusAl(dpe.end, 15);
    printf("\nNúmero do endereco: ");				{}	strPlusNum(dpe.endNum, 15);
	printf("\nTelefone: ");							{}	strPlusNum(dpe.tel, 11);
	printf("\nData de Nascimento: ");				{}	dataf(dpe.dataNas);
	printf("\nSexo(F/M): ");						{}	strPlusAl(dpe.sexo, 15);
	printf("\nInforme seu endere?o de e-mail: \n");	{}	strPlusAl(dpe.email, 40);
	printf("\nN?mero de RG: ");						{}	rgm(dpe.rg);
	printf("\nN?mero de CPF: ");					{}	cpfm(dpe.cpf);
	printf("\nEstado Civil: ");						{}	strPlusAl(dpe.estCivil, 15);

	fprintf(Cliente,"\nNome:" "%s",dpe.nome);
	fprintf(Cliente,"\nEndereco:" "%s, %s",dpe.end,dpe.endNum);
	fprintf(Cliente,"\nTelefone:" "%s",dpe.tel);
	fprintf(Cliente,"\nData de Nascimento:" "%s",dpe.dataNas);
	fprintf(Cliente,"\nSexo:" "%s",dpe.sexo);
	fprintf(Cliente,"\nEndere?o de e-mail:" "%s",dpe.email);
	fprintf(Cliente,"\nRegistro Geral:" "%s",dpe.rg);
	fprintf(Cliente,"\nCadastro Pessoa F?sica:" "%s",dpe.cpf);
	fprintf(Cliente,"\nEstado Civil::" "%s",dpe.estCivil);

	fclose(Cliente);
    //============================================

    //fprintf(Arquivo,"\n");
	TirarEspaco(dpe.nome);      {}  fprintf(Arquivo,"%s\n",dpe.nome);
	TirarEspaco(dpe.end);       {}  fprintf(Arquivo,"%s",dpe.end);
	TirarEspaco(dpe.endNum);    {}  fprintf(Arquivo,"%s%s",dpe.endNum);
	TirarEspaco(dpe.tel);       {}  fprintf(Arquivo,"%s\n",dpe.tel);
	TirarEspaco(dpe.dataNas);   {}  fprintf(Arquivo,"%s\n",dpe.dataNas);
	TirarEspaco(dpe.sexo);      {}  fprintf(Arquivo,"%s\n",dpe.sexo);
	TirarEspaco(dpe.email);     {}  fprintf(Arquivo,"%s\n",dpe.email);
	TirarEspaco(dpe.rg);        {}  fprintf(Arquivo,"%s\n",dpe.rg);
	TirarEspaco(dpe.cpf);       {}  fprintf(Arquivo,"\n%s\n",dpe.cpf);
	TirarEspaco(dpe.estCivil);  {}  fprintf(Arquivo,"%s",dpe.estCivil);

    fclose(Arquivo);

	printf("Cadastrado Com sucesso!!");

	printf("\n\nCliente cadastrado com sucesso ! Pressione 1 para realizar um novo cadastro, ou 0 para sair:");
	ctrNumber(&opcaoMenu);

	if(opcaoMenu == '0')
		{
			MenuCliente();
		}
	else
		{
			CadastroCliente();
		}

}


void ExcluirCorretor(){

	// printf("\nExclusão do cadastro\n\n");
	// printf("Informe o CPF referente ao cadastro que deseja excluir: ");
	// cpfm(buscaCpf);
	// Corretor = fopen("CorretorConsultar.txt","r"); // abrir arquivo em modo leitura
	// FILE* arquivoNovo = fopen("CadastroCorretor_novo.txt","r"); // abrir arquivo em modo escrita
	// while(!feof(Corretor))
	// {
	// 	fscanf(Corretor,"%s %s %s \n", &nome, &end, &tel); // acessar os dados
	// 	if (strcmp(nome, nome)!=0) // se o RA lido for diferente do desejado para exluir, grava no arquivo novo
	// 	{
	// 		fprintf(arquivoNovo,"%s %s %s \n", &nome, &end, &tel); // escrever dados no arquivo novo
	// 	}
	// }
	// fclose(Corretor); // fechar o uso do arquivo
	// fclose(arquivoNovo); // fechar o uso do arquivo

	// system("del CadastroCorretor.txt");
	// system("rename CadastroCorretor_novo.txt CadastroCorretor.txt");

	printf("Fim da exclus�o!");
}


void BuscarCorretor(){
	FILE *Leitura;// tipo de arquivo FILE --> SEMPRE ELE EM MAIUSCULO
	char texto_str[50];// array de string

	// fa�o a atribuai?ao do meu ponteiro para qual arquivo quero abrir e como vai ser a abertura dele.
	Leitura = fopen("CadastroCorretor.txt", "r");
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



//---------IMOVEIS-------------IMOVEIS----------------IMOVEIS---------------

void CadastroImovel(){

	char  tipo[10], endereco[12], dormitorios[15], banheiro[10], terreno[10], construido[10], garagem[5];
	FILE * cadastro;

	cadastro= fopen("CadastroImovel.txt","a++");// verificar se aqui eu abro usando o W  e depois vou usando A para adicionar.
	printf("CADASTRO DE IMOVEL\n");


	printf ("\nQual e o tipo do im?vel(Aluguel ou Venda):");
	scanf("%s",&tipo);
	printf("Informe o endereco do imovel:");
	scanf("%s",&endereco);
	printf("Informe a quantidade de dormitorios:");
	scanf("%s",&dormitorios);
	printf("Quantidade de banheiros:");
	scanf("%s",&banheiro);
	printf("Quantos metros quadrados de terreno:");
	scanf("%s", &terreno);
	printf("Quantos metros quadrados construidos:");
	scanf("%s", &construido);
	printf("Tem garagem ?(S/N):");
	scanf("%s", &garagem);

	fprintf(cadastro,"\nTipo de negociacao:" "%s",tipo);
	fprintf(cadastro,"\nEndereco:" "%s", endereco);
	fprintf(cadastro,"\nQuantidade de dormitorios:" "%s", dormitorios);
	fprintf(cadastro,"\nQuantidade de banheiros:" "%s",banheiro);
	fprintf(cadastro,"\nMetros quadrados do terreno:" "%s", terreno);
	fprintf(cadastro,"\nMetros quadrados construidos:" "%s", construido);
	fprintf(cadastro,"\nGaragem:" "%s", garagem);


	fclose(cadastro);
	printf("Cadastrado Com sucesso!!");
}


void BuscarCadastroImovel(){
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

		printf("Informe o valor do im?vel R$:");
		scanf("%f", &valorImovel);
		printf("Informe a porcentagem para o estado de SP:");
		scanf("%f", &porcentagem);

		calculo1 = (porcentagem / 100) * valorImovel;
		calculo2 = valorImovel + calculo1;
		system("cls");
		printf("Com a porcentagem de %.0f %%, o valor final do im?vel ser? de %.2f.", porcentagem, calculo2);
		getch();
	}


