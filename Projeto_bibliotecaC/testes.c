// Arquivo para realização de teste de funcões para implementar na biblioteca



int crtNumber(char op){

    //O tipo usigned é apenas por precaução
    unsigned char crt[2];
    // i de indice
    unsigned int i = 0;

    do{
        op=getch();
        if (isdigit(op)!=0){
            if (i < 1){//menor que 1 ja que só pode exibir um caracter
                crt[i] = op;
                i++;//incrementa o índice do vetor de caracteres
                printf ("%c", op);//exibe o caractere digitado
            }
        }
        //tecla BACKSPACE é igual a \b ou 8 na tabela ASCII
        else if(op=='\b'&&i){
            // Dois caracter backspace pois somente com ele andava para o lado e não apagava a letra digitada
            printf("\b \b");
            if(i==1){
            crt[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
            i--;//o índice do vetor de caracteres é decrementado
            }
        }
    }while(op!=13);
    op = crt[0];
    return op;
}
