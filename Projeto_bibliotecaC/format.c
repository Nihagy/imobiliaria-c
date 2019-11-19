/*
 *  // formatar uma string e criar uma mascara para os dados
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *  OBS.: ERROR quando coloca a barra
 * 
 */


// Bibliotecas necessária
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

// Validar data de Nasc

// Parametro tem que ser um vetor de preferencia 10 casas
char main(void){

	unsigned char data[11];
	char c;
    unsigned int i=0;

    do{
        c=getch();
	    if (isdigit(c)!=0){
            if (i <= 9){
                // Validar Dia
                if(i <=1){
                    if(i == 0){
                        if(c == '0'){
                            data[i] = '0';
                            printf("0");
                            i++;
                        }else if(c >='4'){
                            data[i] = '0';
                            printf("0");
                            i++;
                            data[i] = c;
                            printf ("%c", c);
                            i++;
                        }else{
                            data[i] = c;
                            printf ("%c", c);
                            i++;
                        }
                    }else if(i==1){
                        if( data[0] != '3'){
                            if (data[0] != '0' && c >= '1'){
                                data[i] = c;
                                printf ("%c", c);
                                i++;
                            }else if(data[0] == '1' && c >= '0'){
                                data[i] = c;
                                printf ("%c", c);
                                i++;
                            }else if(data[i] = 48 && c >'0'){
                                data[i] = c;
                                printf ("%c", c);
                                i++;
                            }
                        }else{
                            if( data[0] == '3' && c <= '1'){
                                data[i] = c;
                                printf ("%c", c);
                                i++;
                            }
                        }
                    }
                }
                // Validar Mes
                else if(i == 3 || i == 4){
                    if(i == 3){
                        if(c == '0'){
                            data[i] = '0';
                            printf("0");
                            i++;
                        }else if(c > '1'){
                            data[i] = '0';
                            printf("0");
                            i++;
                            data[i] = c;
                            printf ("%c", c);
                            i++;
                        }else{
                            data[i] = c;
                            printf ("%c", c);
                            i++;
                        }
                    }else if(i == 4){
                        if(data[3] == '1' && c <='2'){
                            data[i] = c;
                            printf("%c", c);
                            i++;
                        }else if(data[3] != '1' && c >='1'){
                            data[i] = c;
                            printf("%c", c);
                            i++;
                        }
                    }
                }
                // Validar Ano
                else if(i>=6){
                    if(i == 6){
                        if(c > '0' && c <= '2'){
                            if(c == '1'){
                                data[i] = c;
                                printf("%c", c);
                                i++;
                            }else{
                                data[i] = c;
                                printf("%c", c);
                                i++;
                                data[i] = '0';
                                printf("0");
                                i++;
                            }
                        }
                    }else if(i >= 7){
                        if(i == 7){
                            if(c == '8'){
                                data[i] = c;
                                printf("%c", c);
                                i++;
                                data[i] = '9';
                                printf("9");
                                i++;
                            }else if(c == '9'){
                                data[i] = c;
                                printf("%c", c);
                                i++;
                                data[i] = '9';
                                printf("9");
                                i++;
                            }
                        }else if(i == 8){
                            if (data[7] == '0' && c <= '1'){
                                data[i] = c;
                                printf("%c", c);
                                i++;
                            }else if(data[7] == '8' && c == '9'){
                                    data[i] = c;
                                    printf("%c", c);
                                    i++;
                            }else if( data[7] == '9'){
                                if(c >= 48){
                                    data[i] = c;   
                                    printf("%c", c);
                                    i++;
                                }
                            }
                        }else if(i==9){
                            if(data[7] == '8'){
                                if(c >= '7'){
                                    data[i] = c;
                                    printf("%c", c);
                                    i++;
                                }
                            }else{
                                data[i] = c;
                                printf("%c", c);
                                i++;
                            }
                        }
                    }
                }
                if(i==2 || i==5){
                    data[i]='/';
                    printf ("%c", data[i]);
                    i++;
                }
            }
        }
        else if(c=='\b' && i){
            if (i==3 || i==6){
                printf("\b \b");
                i--;
                data[i]='\0';
                printf("\b \b");
                i--;
            }
            else{
                data[i]='\0';
                printf("\b \b");
                i--;
          }
        }
    }while(c!=13);

    data[i]='\0';

    printf ("\n\nA data digitada foi ");
    puts(data);
    printf("%s", data);
    printf("\n\n");
    system("pause");
}


//====================//====================//=================//


// Validar email


int main(void) {

	//char c;
    char email[50]={"abc@xyz.se"};
    int tam=strlen(email);
    int arroba = 0, ponto = 0, pontoAntes = 0, pontoDepois = 0, i;
    int valor;

    for (i = 0; i < tam; i++) {
    	//scanf("%c", &c);
        char validar = email[i];
        if(validar == '@') {
            arroba++;
            if (i < 3){
                break; // se o@ vier antes de 3 caracteres, erro
            }
        }
        // se arroba possui qualquer valor diferente de 0 ele é verdadeiro
        else if (arroba) {
            // como foi atribuido '0' a variavel arroba ele não executa pois é considerado falso
            if (arroba >1){
                break; // caso entre, vai sair fora porque não pode ter dois arroba
            }
            else if (ponto) { // se encontrar '.' depois do @
                pontoDepois++;
            }
            else if(validar == '.') {
                ponto++;
                if (pontoAntes < 3) {
                    break; // se '.' depois de @ vier antes de 3 caracteres, erro
                }
            }
            else
                pontoAntes++;
        }
    }

    valor = (i == tam && pontoDepois > 1)?1:0;
    if (i == tam && pontoDepois > 1)
        printf("Valido: %i", valor);
    else
        printf("Invalido %i", valor);

        system("pause");
        return (i == tam && pontoDepois > 1)?1:0;
}


//====================//====================//=================//