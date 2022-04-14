#include <stdio.h>

float maiorQueX() {
  float vetorV[100];
  int qtd, i, numberX, acumulation = 0;

  scanf("%d", &qtd);

  printf("Qual valor deseja comparar? ");
  scanf("%d", &numberX);
  
  printf("Digite os valores.\n");
  for(i=0; i < qtd; i++) {
    scanf("%f", &vetorV[i]);
  }

  for(i=0; i < qtd; i++) {

    if(vetorV[i] > numberX) {
      acumulation++;
    }
  }

  printf("%d numeros maiores que o informado.", acumulation);
}

void main() 
{
  printf("Quantos valores deseja consultar? \n");
  maiorQueX();
  return 0;
}