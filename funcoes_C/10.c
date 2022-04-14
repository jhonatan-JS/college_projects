#include <stdio.h>

void encontraValor() {
  int vetor[100], qtdNumber, i, compar;

  scanf("%d", &qtdNumber);
  printf("Digite os valores do vetor \n");

  for(i=0; i < qtdNumber; i++) {
    scanf("%d", &vetor[i]);
  }

  printf("Qual valor deseja encontrar? ");
  scanf("%d", &compar);

  for(i=0; i < qtdNumber; i++) {

    if(compar == vetor[i]) {
      printf("O valor %d existe no vetor ", compar);
      break;
    }
  }

  if(i == qtdNumber) {
    printf("Valor nao encontrado ");
  }
}

void main()
{
  printf("Verificar se valor existe no vetor.\n");
  printf("Qual tamanho do vetor? ");
  encontraValor();
}