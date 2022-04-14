#include <stdio.h>

void fibonacci(int qtdTermos) {
  int 
  termo = 0, 
  aux = 1, 
  count,
  i;

  printf("1 ");
  for( i=0; i < qtdTermos; i++ ){
    count = termo + aux;
    printf("%d ", count);
    termo = aux;
    aux = count;
  }
}

int main()
{
  int qtdTermos;
  printf("Quantos termos de fibonacci deseja conferir? \n");
  scanf("%d", &qtdTermos);
  fibonacci(qtdTermos);
  return 0;
}