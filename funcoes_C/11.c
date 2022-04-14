#include <stdio.h>

void inverter() {
  int qtdValores, valores[100], i;

  scanf("%d", &qtdValores);
  printf("Digite os valores para imprimir.\n");

  for (i = 0; i < qtdValores; i++) {
    scanf("%d", &valores[i]);
  }

  for(i=qtdValores -1 ; i >= 0; i--){
    printf("%d ", valores[i]);
  }
}

void main()
{
  printf("Imprimir valores inversos.\n");
  printf("Quantos valores deseja imprimir?\n");
  inverter();
  return 0;
}