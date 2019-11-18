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


