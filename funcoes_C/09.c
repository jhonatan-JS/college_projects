#include <stdio.h>

void soma() {
  int valores[100], soma = 0, i, qtdValores;

  scanf("%d", &qtdValores);
  printf("Quais valores deseja somar?\n");

  for(i=0; i < qtdValores; i++) {
    scanf("%d", &valores[i]);

    soma = valores[i] + soma;
  }

  printf("A soma dos valores é: %d ", soma);
}

void main()
{
  printf("Quantos valores deseja somar?\n");
  soma();
}