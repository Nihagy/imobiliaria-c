#include<string.h>
#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <locale.h>
#include<conio.h>
#include <stdio.h>
#include <locale.h>

FILE *Senha;
FILE* usuario;
char senha1[15];
char usuario1[15];
char senhaC[15];
char usuarioC[15];
int retorno;


  void ValidaLogin()
 {
 
 	Senha=fopen("Login.txt","r"); //Abre o arquivo de usuários
	while(!feof(Senha)) //Enquanto não for o final do arquivo
	{
		fscanf (Senha,"%s %s\n",&senhaC,&usuarioC); //Le os arquivos de usuários

		if (strcmp(usuario1,usuarioC)==0 && senha1 == senhaC) //Valida usuário e senha digitado
		{	
			printf("bem vindo"); //Faz com que o retorno da variável seja 1
		}
		else
		{
			printf("Usuario ou senha incorretos\n");	
			return;
		}		
	}
	main();
	
		
		getchar (); // Limpar o buffer
	
	
	fclose(usuario);
 	
 	
 	
 	
 }

int Login()
{

	Senha=fopen("Login.txt","a++");
	if(Senha==NULL)
	{
		printf("Cadastro de Usuario via Admin");
	}
	else
	{
		printf("O arquivo foi aberto com sucesso!\n");
	}

	printf("\n---Cadastre---\n");
	printf("Usuario:");
	gets(usuarioC);
	printf("Senha:");
	gets(senhaC);
//	fprintf(Senha,"\nLogin:");
//	fprintf(Senha,"\n%s",usuario1);
//  fprintf(Senha,"\nSenha:");
//	fprintf(Senha," \n%s",senha1);
	fclose(Senha);
	printf("\n processo  Cadastro conclido");
	system("pause");
	main();
	return 0;
}
int main()
{
	printf("\nAcessar\n");
	printf("Usuario:");
	gets(usuario1);
	printf("Senha:");
	gets(senha1);

	if(strcmp(usuario1, "Admin")==0)
	{
		printf("\n bem vindo");
		Login();
	}
	
		Senha = fopen ("Login.txt","r"); //Abre o arquivo de usuários
		while(!feof(Senha)) //Enquanto não for o final do arquivo
		{
			fscanf (Senha,"%s %s \n",usuario1,&senha1); //Le os arquivos de usuários
	
			printf ("Digite seu usuario: ");
			gets(usuario1); //Preenche a variável
	
			printf("Digite sua senha: ");
			scanf("%d", & senha1); //Preenche a variável
			
			if (strcmp(usuario1,usuarioC)==0 && senha1 == senhaC) //Valida usuário e senha digitado
			{	
				retorno = 1;
				printf("Logou com Sucesso"); //Faz com que o retorno da variável seja 1
			}		
		}
	
		if (retorno == 0)
		{
			printf("Usuario ou senha incorretos\n");
			getchar (); // Limpar o buffer
		}
	
	
}
