// funcões para formatar e colocar mascara em rg, cpf, data entre outras coisas

void dataf(char *data){

	//unsigned char data[11];
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

}


int emailf(char *email) {

    int tam=strlen(email);
    int arroba = 0, charAntes = 0, pontoAntes = 0, pontoDepois = 0, i;
    int valor;

    gets(email);
    tam = strlen(email);

    for (i = 0; i < tam; i++) {
        email[i];
            if( (isalnum(email[i]) != 0 ) || email[i] == 46 || email[i] == 64 || email[i] == 95){
                if(email[i] == '@') {
                    arroba++;
                    if (i < 3){
                        break;
                    }
                    else if(email[i-1] == '.' || email[i-1] == '_'){
                        break;
                    }
                }
                else if (arroba) {
                    if (arroba >1){
                        break;
                    }
                    else if(email[i] == '.') {
                        pontoDepois++;
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
            }else{
                break;
            }
    }

    valor = (i == tam && pontoDepois >= 1)?1:0;

    return (i == tam && pontoDepois >= 1)?1:0;
}


void rgm(char rg[]){

    char c;
    unsigned int i=0;

    do{
        c=getch();
        if (isdigit(c)!=0){
            if (i <= 11){
                rg[i] = c;
                i++;
                printf ("%c", c);
            }
            if(i==2 || i==6 || i==10){
                if(i==10){
                    rg[i]='-';
                    printf ("%c", rg[i]);
                    i++;
                }else if(i==2 || i==6 ){
                    rg[i]='.';
                    printf ("%c", rg[i]);
                    i++;
                }
            }
        }
        else if(isdigit(c)==0 && c!='\b'){
            if(i==11){
                rg[i] = c;
                i++;
                printf ("%c", c);
            }
        }
        else if(c=='\b' && i){
            if (i==3 || i==7 || i==11){
                printf("\b \b");
                i--;
                printf("\b \b");
                i--;
                rg[i]='\0';
            }
            else{
                printf("\b \b");
                i--;
                rg[i]='\0';
            }
        }
    }while(c!=13);

    rg[i]='\0';
}


void cpfm(char cpf[]){

    char c;
    unsigned int i=0;

    do{
        c=getch();
        if (isdigit(c)!=0){
            if (i <= 13){
                cpf[i] = c;
                i++;
                printf ("%c", c);
            }
            if(i==3 || i==7 || i==11){
                if(i==11){
                    cpf[i]='-';
                    printf ("%c", cpf[i]);
                    i++;
                }else{
                    cpf[i]='.';
                    printf ("%c", cpf[i]);
                    i++;
                }
            }
        }
        else if(c=='\b' && i){
            if (i==4 || i==8 || i==12){
                printf("\b \b");
                i--;
                printf("\b \b");
                i--;
                cpf[i]='\0';
            }
            else{
                printf("\b \b");
                i--;
                cpf[i]='\0';
            }
        }
    }while(c!=13);

    return 0;
}
