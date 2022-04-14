#include <stdio.h>

void encontraMenor() {
  int numbers[100], qtdConsult, i, consult;

  scanf("%d", &qtdConsult);
  printf("Digite os valores.\n");
  for(i=0; i < qtdConsult; i++) {
    scanf("%d", &numbers[i]);
  }

  consult = numbers[0];

  for(i=0; i < qtdConsult; i++) {

    if(numbers[i] < consult){
      consult = numbers[i];
    }
  }

  printf("O menor valor encontrado é %d ", consult);
}

int main()
{
  printf("Quantos valores deseja conferir?\n");
  encontraMenor();

  return 0;
}