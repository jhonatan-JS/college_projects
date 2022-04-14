#include <stdio.h>

void encontraMaior() {
  int num[100], num2, i, maior = 0;
 
  scanf("%d", &num2);

  printf("Digite os valores.\n");
  for(i=0; i < num2; i++) {
    scanf("%d", &num[i]);

    if(num[i] > maior) {
      maior = num[i];
    }
  }

  printf("O maior valor é %d ", maior);
}

int main()

{
  printf("Quantos valores deseja conferir?\n");
  encontraMaior();

  return 0;
}