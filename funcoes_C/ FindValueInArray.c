#include <stdio.h>

void menorN() {
  int mQuadrada[2][2], i, j, somaDaLinha = 0, valorDaSoma[2], valorDeI;

  for(i=0; i < 2; i++) {
    printf("Linha %d \n", i+1);
    for(j=0; j < 2; j++){
      scanf("%d", &mQuadrada[i][j]);
    }
  }

  for(i=0; i < 2; i++) {
    for(j=0; j < 2; j++){
      somaDaLinha += mQuadrada[i][j];
    }
    valorDaSoma[i] = somaDaLinha;
    somaDaLinha = 0;

  }
  somaDaLinha = valorDaSoma[0];
  for(i=0; i < 2; i++) {
    if(valorDaSoma[i] <= somaDaLinha) {
      valorDeI = i;
    }
  }

  printf("O menor valor esta na linha %d ", valorDeI+1);
}


void main()
{
  printf("Encontrar valor menor na matriz \n");
  menorN();
}