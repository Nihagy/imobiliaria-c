#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>



FILE* arquivo;
int opcao = 0;
int p;
FILE * cadastro;



void OpcaoCorretor(){
	while(opcao!=5){
		switch(opcao){
			case 1: // listar Menu Cliente
				CadastroCorretor();
				printf("\n informe 1 caso deseje fazer um novo cadastro de corretor ou 0 para sair...\n");
						scanf("%i",&p);

					if(p== 1){// coloquei 1 mais quero que seja S ou N, mais se nao uso numero ele da errado, ver depois
						CadastroCorretor();
					}
					else{
						printf("\n Saindo do cadastro de Corretores. \n");
						printf("----------------------------------------");
					}
					return MenuCorretor();
				break;
			case 2: // listar Menu Corretor
				lerCadastroCorretor();
				break;
			case 3: // listar Menu Imoveis
				ExcluirCorretor();
				break;
			case 4: // listar Menu Calculo
				MenuCalculo();
				break;
			case 5: // Sair
				break;

			default:
				printf("Op??o inv?lida!");
				break;
		}
		printf("\n\nClique uma tecla para continuar.\n\n");
		getch();
		system("cls");
	} // fim do while
}



void MenuImoveis(){
	printf("MENU IMOVEIS");

	printf("\n\n(1) - Cadastro Imovel\n");
	printf("(2) - Leitura de cadastro\n");
	printf("(3) - Alteracao de cadastro\n");
	printf("(4) - Exclusao de Cadastro\n");
	printf("(0) - Voltar\n");
	printf("Entre com a opcao desejada: ");
	scanf("%i", &opcao);
	getchar(); // limpar o <enter> do scanf anterior

	switch(opcao){
		case 1: // Cadastro Cliente
			CadastroImovel();
			break;
		case 2: // Leitura Cadastro
			lerCadastroImovel();
			break;
		case 0: //Voltar
			break;
		default:
			printf("Opcao invalida");
			break;
	}
}



void MenuCalculo(){
	printf("MENU CALCULO");

	printf("\n\n(1) - Simulacao financiamento\n");
	printf("(2) - Comissao por locacao\n");
	printf("(3) - Comissao por venda\n");
	printf("(0) - Voltar\n");
	printf("Entre com a opção desejada: ");
	scanf("%i", &opcao);
	getchar(); // limpar o <enter> do scanf anterior
	system("cls");

	switch(opcao){
		case 1: // Simula??o financiamento
			SimulacaoFinanciamento();
			break;
		case 0: // Voltar
			break;
		default:
			printf("Op??o inv?lida");
			break;
	}
}

