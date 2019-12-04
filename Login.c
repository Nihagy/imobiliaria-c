
#include<string.h>
#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <locale.h>
#include<conio.h>
#include <windows.h>
#include "string++.h"
#include "menu_principal.c"


FILE *Senha;
char senha1[16];
char usuario1[16];
char senhaC[16];
char usuarioC[16];
int retorno;
int pri=0;

//FUNCÕES

void senhaOculta(char *senha, int tam){
    char c;
    int i=0;
    do{
        c=getch();
        if(c == 13){
            senha[i]='\0';
            break;
        }
        else if(i < tam-1){
            if (c !=8 || c == 32){
                senha[i] = c;
                i++;
                printf ("*");
            }
            else if(c==8&&i){
                senha[i]='\0';
                i--;
                printf("\b \b");
            }
        }
        else if(c==8&&i){
            senha[i]='\0';
            i--;
            printf("\b \b");
        }
    }while(c!=13);

    senha[i]='\0';
}

//================================================================


void priAcesso(Console){
    SetConsoleTextAttribute(Console, BRANCO);
    Senha = fopen("usuario.tx","r");
	if(Senha == NULL){
		Senha = fopen("usuario.txt","w");
		fprintf(Senha,"%s \n",usuario1);
		fprintf(Senha,"%s \n",senha1);
		fclose(Senha);
		pri++;
	}
	if(pri){
		printf("\n Bem vindo ao seu primeiro acesso \n");
		Senha=fopen("usuario.txt","w+");
		if(Senha==NULL){
			printf("\n Cadastro de Usuario via Admin \n");
		}
		else{
			printf("");
		}

		SetConsoleTextAttribute(Console, BRANCO);
		printf("\n\t\tCadastre-se\n");
		printf("\n\t\tDigite qual sera seu LOGIN:");
		SetConsoleTextAttribute(Console, VERDE);
		strPlusAlnum(usuarioC, 16);
		SetConsoleTextAttribute(Console, BRANCO);
		printf("\n\t\tSenha:");
		SetConsoleTextAttribute(Console, VERDE);
		senhaOculta(senhaC,16);


		fprintf(Senha,"%s \n",usuarioC);
		fprintf(Senha,"%s \n",senhaC);
		fclose(Senha);
		printf("\n\t\tprocesso Cadastro concluido");
	}
    system("cls");
    main();
}



void bemVindo(Console){

    int i;
    setlocale(LC_ALL, "Portuguese");
	SetConsoleTextAttribute(Console, BRANCO);

        printf("\n\n\n\t\t\tSeja Bem-Vindo %s", usuario1);
    for(i=0; i<5;i++){
		SetConsoleTextAttribute(Console, VERDE);
        printf(".");
        Sleep(1000);
    }
    // system("pause");
    system("cls");
	SetConsoleTextAttribute(Console, VERDE);
    printf("\n\n\n\n\t\t\tBem vindo ao sistema imobiliaria! V. 2.0");
    Sleep(1000);
    Beep(1500,500);
    menu(Console);
}



int main(){

    setlocale(LC_ALL, "Portuguese");
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTitle("IMOBILIARIA - LOGIN");
    SetConsoleTextAttribute(Console, BRANCO);
    printf("\n\t\t    -___-___-___-___-___-___-___-___-___-");
    printf("\n\n\t\t    -___-___-");

    SetConsoleTextAttribute(Console, VERDE);
    printf("  BAIXADA BROKERS");

    SetConsoleTextAttribute(Console, BRANCO);
    printf("  -___-___-");
    printf("\n\n\t\t    -___-___-___-___-___-___-___-___-___-");


	printf("\n\n\t\t\t\tAcessar\n");
	printf("\n\n\t\t\tLogin: ");
	SetConsoleTextAttribute(Console, VERDE);
	strPlusAlnum(usuario1, 16);
	SetConsoleTextAttribute(Console, BRANCO);
	printf("\n\t\t\tPassword: ");
	SetConsoleTextAttribute(Console, VERDE);
	senhaOculta(&senha1, 16);

	Senha = fopen("usuario.txt","r");
    if(pri==0 && Senha == NULL){
        priAcesso(Console);
    }
	else{
		do{
			fscanf (Senha,"%s %s ",usuarioC,&senhaC); //Le os arquivos de usuarios

			if (strcmp(usuario1,usuarioC)==0 && strcmp(senha1,senhaC)==0){
                bemVindo(Console);
			}
			else if(retorno == 0){
                fclose(Senha);
				SetConsoleTextAttribute(Console, VERMELHO);
				printf("\n\n\t\t\tUsuario ou senha incorretos\n");
                SetConsoleTextAttribute(Console, BRANCO);
                Beep(1200,200);
                Sleep(1000);
                system("cls");
                main(Console);
			}
		}while(!feof(Senha));

	}
	return 0;
}
