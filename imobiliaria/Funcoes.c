
// funcóes de acordo com o menu selecionado
FILE* arquivo;
FILE * Cliente;
FILE * Corretor;
int opcaoMenu = 0;


		//---------------------------------- CLIENTE-----------CLIENTE------------------CLIENTE---------------------------------------------------------------------
void CadastroCliente(){
	char nome [10], nascimento[12], sexo[15], mail[40], tel[10], rg[14], cpf[14], EstadoCivil[10];
	FILE * Cliente;

	Cliente = fopen("c:/Cliente.txt","a++");// verificar se aqui eu abro usando o W  e depois vou usando A para adicionar.
	printf("CADASTRO DE CLIENTE\n");

	printf ("\nEscreva seu nome completo:");
	gets(nome);
	printf("Telefone:");
	gets(tel);
	printf("Data de Nascimento:");
	scanf("%s",&nascimento);
	printf("Sexo(F/M):");
	scanf("%s",&sexo);
	printf("Informe seu endere?o de e-mail:");
	scanf("%s", &mail);
	printf("N?mero de RG:");
	scanf("%s", &rg);
	printf("N?mero de CPF:");
	scanf("%s", &cpf);
	printf("Estado Civil:");
	scanf("%s", &EstadoCivil);

	fprintf(Cliente,"\nNome:" "%s",nome);
	fprintf(Cliente,"\nData de Nascimento:" "%s",nascimento);
	fprintf(Cliente,"\nSexo:" "%s",sexo);
	fprintf(Cliente,"\nEndere?o de e-mail:" "%s",mail);
	fprintf(Cliente,"\nTelefone:" "%s",tel);
	fprintf(Cliente,"\nRegistro Geral:" "%s",rg);
	fprintf(Cliente,"\nCadastro Pessoa F?sica:" "%s",cpf);
	fprintf(Cliente,"\n\nNome:" "%s",EstadoCivil);

	fclose(Cliente);
	system("cls");
	printf("Cliente cadastrado com sucesso ! Pressione 1 para realizar um novo cadastro, ou 0 para sair:");
	scanf("%i", &opcaoMenu);//FILE * Cliente;

	if(opcaoMenu==0)
		{
			MenuCliente();
		}
	else
		{
			CadastroCliente();
		}
}


void BuscarCliente(){
	  FILE *Leitura;// tipo de arquivo FILE --> SEMPRE ELE EM MAIUSCULO
	  char texto_str[50];// array de string

	  // fa?o a atribuai??o do meu ponteiro para qual arquivo quero abrir e como vai ser a abertura dele.
	  Leitura = fopen("c:/Cliente.txt", "r");
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

	//---------------------------------- CORRETOR-----------CORRETOR------------------CORRETOR---------------------------------------------------------------------

void CadastroCorretor(){
	char nome [10], tel[12],end[15];

	Corretor = fopen("c:/Corretor.txt","a++");// verificar se aqui eu abro usando o W  e depois vou usando A para adicionar.

		if (Corretor == NULL)
		{
			printf("abertura nao foi bem sucedida");
		}
		else
		{
			printf("deu bom a abertura do arquivo!\n");
		}
	printf("\nCADASTRO DO CORRETOR!!\n");
	printf ("\nescreva seu nome:");scanf("%s",&nome);
	printf("telefone:");scanf("%s",&tel);
	printf("informe seu endere?o:");scanf("%s",&end);

	fprintf(Corretor,"\nNome:" "%s",nome);
	//fprintf(cadastro,"%s",nome);
	fprintf(Corretor,"\nEndereco:");
	fprintf(Corretor,"%s",end);
	fprintf(Corretor,"\nTelefone:");
	fprintf(Corretor,"%s",tel);
	fclose(Corretor);
	printf("Cadastrado Com sucesso!!");
}


ExcluirCorretor(){

	char nome [10], tel[12],end[15];
	printf("\nExclus�o do cadastro\n\n");
	printf("Informe o RA que deseja remover: ");
	scanf("%s",&nome);
	cadastro = fopen("CadastroCorretor.txt","r"); // abrir arquivo em modo leitura
	FILE* arquivoNovo = fopen("CadastroCorretor_novo.txt","r"); // abrir arquivo em modo escrita
	while(!feof(cadastro))
	{
		fscanf(cadastro,"%s %s %s \n", &nome, &end, &tel); // acessar os dados
		if (strcmp(nome, nome)!=0) // se o RA lido for diferente do desejado para exluir, grava no arquivo novo
		{
			fprintf(arquivoNovo,"%s %s %s \n", &nome, &end, &tel); // escrever dados no arquivo novo
		}
	}
	fclose(cadastro); // fechar o uso do arquivo
	fclose(arquivoNovo); // fechar o uso do arquivo

	system("del CadastroCorretor.txt");
	system("rename CadastroCorretor_novo.txt CadastroCorretor.txt");

	printf("Fim da exclus�o!");
}

/*

void lerCadastroCorretor(){
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

//--------------------------------------------- IMOVEIS--------------------IMOVEIS--------------------IMOVEIS-------------------------------------

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



void lerCadastroImovel(){
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



//void SimulacaoFinanciamento()
//	{
//		float valorImovel, calculo1, calculo2, porcentagem;
//
//		printf("Informe o valor do im?vel R$:");
//		scanf("%f", &valorImovel);
//		printf("Informe a porcentagem para o estado de SP:");
//		scanf("%f", &porcentagem);
//
//		calculo1 = (porcentagem / 100) * valorImovel;
//		calculo2 = valorImovel + calculo1;
//		system("cls");
//		printf("Com a porcentagem de %.0f %%, o valor final do im?vel ser? de %.2f.", porcentagem, calculo2);
//		getch();
//	}


*/
