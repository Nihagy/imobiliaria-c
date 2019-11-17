

// formatar uma string e criar uma mascara com os caracteres

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int main(void){
	unsigned char digitado[11];
	unsigned char c;
    unsigned int i=0;

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
                            i++;
                            printf ("%c", c);
                        }
                    }else if(i==1){
                        if( digitado[0] != '3'){
                            if (digitado[0] != '0' && c >= '1'){
                                digitado[i] = c;
                                i++;
                                printf ("%c", c); 
                            }else if(digitado[0] == '1' && c >= '0'){
                                digitado[i] = c;
                                i++;
                                printf ("%c", c);           
                            }
                        }else{
                            if( digitado[0] == '3' && c <= '1'){
                                digitado[i] = c;
                                i++;
                                printf ("%c", c);
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
                            i++;
                            printf("%c", c);
                        }else if(digitado[3] != '1' && c >='1'){
                            digitado[i] = c;
                            i++;
                            printf("%c", c);
                        }
                    }
                }
                // Validar Ano
                else if(i>=6){
                    if(i == 6){
                        if(c > '0' && c <= '2'){
                            digitado[i] = c;
                            i++;
                            printf("%c", c);
                        }
                    }else if(i == 7){
                        if(digitado[6] == '1' ){
                            if(c == '9'){
                                digitado[i] = c;
                                i++;
                                printf("%c", c);
                            }
                        }else{
                            digitado[i] = c;
                            i++;
                            printf("%c", c);
                        }
                    }else{
                        digitado[i] = c;
                        i++;
                        printf("%c", c);   
                    }
                }
                if(i==2 || i==5){
                    digitado[i]='/';
                    i++;
                    printf ("/");
                }
            }
        }
        // else if(i==2 || i==5){
        //     digitado[i]='/';
        //     i++;
        //     printf ("/");
        // }
        else if(c=='\b' && i){
            if (i==2 || i==5){
                printf("\b \b");
                i--;
                digitado[i]='\0';
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
     	if (i==2 || i==5)
     		printf ("%c", digitado[i]);
	 	else
     		printf ("%c", digitado[i]);
     }
    printf ("\n\n");

    system ("pause");
    return 0;
}


//=========================================================



                else if(i>=6){
                    if(i == 6){
                        if(c > '0' && c <= '2'){
                            if(c == '1'){
                                    digitado[i] = c;
                                    printf("%c", c);
                                    i++;
                                    digitado[i] = '9';
                                    printf("9");
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
                    }else if(i == 8){
                        if(digitado[7] == '0'){
                            if(c <= '1'){
                                digitado[i] = c;
                                i++;
                                printf("%c", c);
                            }else{
                                digitado[i] = c;
                                i++;
                                printf("%c", c);
                            }
                        }else{
                            digitado[i] = c;
                            i++;
                            printf("%c", c);   
                        }
                    }