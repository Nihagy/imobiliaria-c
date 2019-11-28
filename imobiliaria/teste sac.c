#include <stdio.h>

#include <stdlib.h>

int main()

{

float valor_financiado,tempo, juro_anual,saldo_devedor, juro_calculado, amortizacao, parcela,valor_parcela;



printf("Tabela Sac - (tbsac)\t\n\n");

printf("Valor Finaciado: ");

scanf("%f", &valor_financiado);

printf("Digite Tempo de financiamento: ");

scanf("%f ", &tempo);

printf("Digite juro_anual: ");

scanf("%f ",& juro_anual);



saldo_devedor = valor_financiado;

juro_anual = (juro_anual /100) /12;

amortizacao = valor_financiado / tempo;



{

while (parcela < tempo)

{

saldo_devedor = saldo_devedor - amortizacao;

juro_calculado = saldo_devedor * juro_anual;

valor_parcela = juro_calculado + amortizacao;

parcela = parcela + 1;

printf("parcela: %0.2f saldo: %0.2f amort.: %0.2f juros: %0.2f valor: %0.2f \n", parcela, saldo_devedor, amortizacao, juro_calculado, valor_parcela);

}

}

system("pause");

return 0;

}

