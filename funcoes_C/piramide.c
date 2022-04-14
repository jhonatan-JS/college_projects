#include <stdio.h>

void piramide() {
   int i, j, tamanho = 9, inicio = 0, fim = 10;
   int matriz[9][9];

  for (i=0; i < tamanho; i++) {
    for(j=1; j <= tamanho; j++) {
      matriz[i][j] = j;
    }
  }

  for (i=0; i < tamanho; i++) {
    printf("\n");
    for(j=1; j <= tamanho; j++) {
      if(i == 0) {
        printf("%d ", matriz[i][j]);
      } else {
        if( j > inicio && j < fim ) {
          printf("%d ", matriz[i][j]);
        } else {
          printf("  ");
        }
      }
    }
    inicio++;
    fim--;
  }
}

void main()
{
  printf("Executando piramide\n");
  piramide();
  return 0;
}