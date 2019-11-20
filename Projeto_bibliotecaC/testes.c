// Arquivo para realização de teste de funcões para implementar na biblioteca




/*

*/

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>




int main(void) {

	//char c;
    char email[50]={"michaelnevesv@gmail.com"};
    int tam=strlen(email);
    int arroba = 0, charAntes = 0, pontoAntes = 0, pontoDepois = 0, i;
    int valor;

    //gets(email);
    //tam = strlen(email);

    for (i = 0; i < tam; i++) {
    	//scanf("%c", &c);
        email[i];
            // Códigos da validacao correspondentes a '.' e '@' e '_' de acordo com a tabela ASCII
            if( (isalnum(email[i]) != 0 ) || email[i] == 46 || email[i] == 64 || email[i] == 95){
                // se arroba possui qualquer valor diferente de 0 ele é verdadeiro
                if(email[i] == '@') {
                    arroba++;
                    if (i < 3){
                        break; // se o@ vier antes de 3 caracteres, erro
                    }
                    else if(email[i-1] == '.' || email[i-1] == '_'){
                        break;
                    }
                }
                // como foi atribuido '0' a variavel arroba ele não executa pois é considerado falso
                else if (arroba) {
                    // caso entre, vai sair fora porque não pode ter dois arroba
                    if (arroba >1){
                        break; 
                    }
                    //else if (ponto) { // se encontrar '.' depois do @
                    //}
                    else if(email[i] == '.') {
                        pontoDepois++;
                         // se '.' depois de @ vier antes de 3 caracteres
                        if(charAntes < 3) {
                            break;
                        }
                    }
                    else if(isalpha(email[i]) != 0 || email[i] == 95){
                        charAntes++;
                        }
                        else if( email[i] == 95){
                                break;
                        }
                }
                // else {
                //     if (email[i] == '.'){
                //         pontoAntes++;
                //     }
                //}
            }else{
                break;
            }
    }

    //perrcoreu todas as casas do vetor que contem o email e verifica se tem um ponto depois 
    valor = (i == tam && pontoDepois >= 1)?1:0;

    if (i == tam && pontoDepois >= 1){
        printf("Valido: %i\n", valor);
        printf("Valido: %i\n", pontoDepois);
        printf("Valido: %i\n", pontoAntes);
        printf("Valido: %i\n", arroba);
    }
    else{
        printf("Invalido %i\n", valor);
        printf("Invalido %i\n", pontoDepois);
        printf("Invalido %i\n", pontoAntes);
        printf("Invalido %i\n", arroba);
    }

    system("pause");
    return (i == tam && pontoDepois > 1)?1:0;
}


//====================//====================//=================//


