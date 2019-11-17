// Arquivo para realização de teste de funcões para implementar na biblioteca




/*

*/

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int main(void){
	char digitado[11];
	char c;
    int i=0;

    printf ("Informe uma data (dd/mm/aaaa): ");


/*
else{
                    digitado[i] = c;
                    i++;
                    printf ("%c", c);
                }
*/
    do{
        //printf("\t%i\n", i);
        c=getch();
	    if (isdigit(c)!=0){
            if (i <= 9){
                // Validar Dia
                if(i <=1){
                    if(i == 0){
                        if(c == '0'){
                            digitado[i] == '0';
                            printf("0");
                            i++;
                        }else if(c >='4'){
                            digitado[i] == '0';
                            printf("0");
                            i++;
                            digitado[i] == 'c';
                            printf ("%c", c);
                            i++;
                        }else{
                            digitado[i] = c;
                            printf ("%c", c);
                            i++;
                        }
                    }else if(i==1){
                        if( digitado[0] != '3'){
                            if (digitado[0] != '0' && c >= '1'){
                                digitado[i] = c;
                                printf ("%c", c);
                                i++;
                            }else if(digitado[0] == '1' && c >= '0'){
                                digitado[i] = c;
                                printf ("%c", c);
                                i++;
                            }
                        }else{
                            if( digitado[0] == '3' && c <= '1'){
                                digitado[i] = c;
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
                            digitado[i] == '0';
                            printf("0");
                            i++;
                        }else if(c > '1'){
                            digitado[i] == '0';
                            printf("0");
                            i++;
                            digitado[i] == 'c';
                            printf ("%c", c);
                            i++;
                        }else{
                            digitado[i] = c;
                            printf ("%c", c);
                            i++;
                        }
                    }else if(i == 4){
                        if(digitado[3] == '1' && c <='2'){
                            digitado[i] = c;
                            printf("%c", c);
                            i++;
                        }else if(digitado[3] != '1' && c >='1'){
                            digitado[i] = c;
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
                                digitado[i] = c;
                                printf("%c", c);
                                i++;
                            }else{
                                digitado[i] = c;
                                printf("%c", c);
                                i++;
                                digitado[i] = '0';
                                printf("0");
                                i++;
                            }
                        }
                    }else if(i >= 7){
                        if(i == 7 && c >= '8'){
                            digitado[i] = c;
                            printf("%c", c);
                            i++;
                            if(digitado[7] == '8' || digitado[7] == '9'){
                                digitado[i] = '9';
                                printf("9");
                                i++;
                            }
                        }else if(i == 8){
                            if (digitado[7] == '0' && c <= '1'){
                                digitado[i] = c;
                                printf("%c", c);
                                i++;
                            }
                        }else if(i==9){
                            digitado[i] = c;
                            printf("%c", c);   
                            i++;
                        }
                    }
                }
                if(i==2 || i==5){
                    digitado[i]='/';
                    printf ("/");
                    i++;
                }
            }
        }
        else if(c=='\b' && i){
            if (i==3 || i==6){
                printf("\b \b");
                i--;
                digitado[i]='\0';
                printf("\b \b");
                i--;
            }
            else{
                digitado[i]='\0';
                printf("\b \b");
                i--;
          }
        }
    }while(c!=13);

    digitado[i]='\0';

	 printf ("\n\nA data digitada foi ");
     for (i=0;i<strlen(digitado);i++){
     		printf ("%c", digitado[i]);
     }
    printf ("\n\n");

    system ("pause");
    return 0;
}


//=========================================================



