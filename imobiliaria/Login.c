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

/*
void ValidaLogin(){

 	Senha=fopen("Login.txt","r"); //Abre o arquivo de usu�rios
	while(!feof(Senha)) //Enquanto n�o for o final do arquivo
	{
		fscanf (Senha,"%s %s\n",&senhaC,&usuarioC); //Le os arquivos de usu�rios

		if (strcmp(usuario1,usuarioC)==0 && senha1 == senhaC) //Valida usu�rio e senha digitado
		{
			printf("bem vindo"); //Faz com que o retorno da vari�vel seja 1
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
	printf("\n\tAcessar\n\n");
	printf("Usuario:");
	gets(usuario1);
	printf("Senha:");
	gets(senha1);

	if(strcmp(usuario1, "Admin")==0)
	{
		printf("\n bem vindo");
		Login();
	}

		Senha = fopen ("Login.txt","r"); //Abre o arquivo de usu�rios
		while(!feof(Senha)) //Enquanto n�o for o final do arquivo
		{
			fscanf (Senha,"%s %s \n",usuario1,&senha1); //Le os arquivos de usu�rios

			printf ("Digite seu usuario: ");
			gets(usuario1); //Preenche a vari�vel

			printf("Digite sua senha: ");
			scanf("%d", & senha1); //Preenche a vari�vel

			if (strcmp(usuario1,usuarioC)==0 && senha1 == senhaC) //Valida usu�rio e senha digitado
			{
				retorno = 1;
				printf("Logou com Sucesso"); //Faz com que o retorno da vari�vel seja 1
			}
		}

		if (retorno == 0)
		{
			printf("Usuario ou senha incorretos\n");
			getchar (); // Limpar o buffer
		}


}
*/

//===================================

//fase beta login

int main(){

	FILE *login;
	int pri=0;
	login = fopen("teste1","rb");
	if(login == NULL){
		login = fopen("teste1","wb");
		char uPadrao[6] = "admin";
		char sPadrao[6] = "admin";
		fwrite(uPadrao,sizeof(char),6, login);
		fwrite(sPadrao,sizeof(char),6, login);
		fclose(login);
		pri++;
	}
	login = fopen("usuarios","rb");
	char uPadrao[6];
	char sPadrao[6];
	fread(uPadrao,sizeof(char),6, login);
	fread(sPadrao,sizeof(char),6, login);
	printf("%s\n%s\n", uPadrao,sPadrao);
	fclose(login);
	system("pause");
	return 0;
}


//============================ 1 ==============================
	//escreve
/*
int main(){
	FILE *arq;
	arq = fopen("vetor.txt", "wb");
	if(arq == NULL){
		printf("Erro na abertura\n");
		system("pause");
		exit(1);
	}
	int total_gravado, v[5] = {1,2,3,4,5};
	total_gravado = fwrite(v, sizeof(int),5, arq);
	if(total_gravado != 5){
		printf("Erro na escrita do arquivo!");
		system("pause");
		exit(1);
	}
}
*/


//============================ 1.1 ==============================
	// leitura
/*
int main(){
	FILE *arq = fopen("vetor.txt", "rb");
	if(arq == NULL){
		printf("Erro na abertura\n");
		system("pause");
		exit(1);
	}
	int total_lido, v[5];
	total_lido = fread(v, sizeof(int),5, arq);
	if(total_lido != 5){
		printf("Erro na leitura do arquivo!");
		system("pause");
		exit(1);
	}
	fclose(arq);
	printf("%d,%d,%d,%d,%d\n", v[0], v[1], v[2], v[3], v[4]);
	system("pause");
	return 0;
}
*/

//============================ 2 ==============================

//escrita
/*
int main(){
	FILE *arq;
	arq = fopen("dados.txt", "wb");
	if(arq == NULL){
		printf("Erro na abertura\n");
		system("pause");
		exit(1);
	}
	char str[20] = "Hello World!";
	float x = 5;
	int v[5] = {1,2,3,4,5};
	fwrite(str, sizeof(char),20, arq);
	fwrite(&x, sizeof(float),1, arq);
	fwrite(v, sizeof(int),5, arq);
	fclose(arq);
	system("pause");
	return 0;
}
*/

//============================ 2.1 ==============================

//leitura
/*
int main(){
	FILE *arq;
	arq = fopen("dados", "rb");
	if(arq == NULL){
		printf("Erro na abertura\n");
		system("pause");
		exit(1);
	}
	char str[20];
	float x;
	int v[5];
	fread(str, sizeof(char),20, arq);
	fread(&x, sizeof(float),1, arq);
	fread(v, sizeof(int),5, arq);
	printf("%s\n%.2f\n", str,x);
	printf("%i,%i,%i,%i,%i\n", v[0], v[1], v[2], v[3], v[4]);
	fclose(arq);
	system("pause");
	return 0;
}
*/

