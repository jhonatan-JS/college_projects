#include <stdio.h>

void valoresNegativos() {
  int matriz[4][4], valor0 = 0, qtdValores, i, j, tamanho = 4, valoresNegativos = 0;

  for(i=0; i < tamanho; i++) {
    printf("Linha %d \n", i);

    for(j=0; j < tamanho; j++) {
      scanf("%d", &matriz[i][j]);
    }
  }

  for (i=0; i < tamanho; i++) {
    printf("\n");
    for(j=0; j < tamanho; j++) {

      if(matriz[i][j] >= 0 ) {
        printf("%d ", matriz[i][j]);
      } else {
        valoresNegativos++;
        printf("0 ");
      }
    }
  }

  printf("\n%d valores negativos alterados. ", valoresNegativos);
}

void main()
{
  printf("Digite os valores.\n");
  valoresNegativos();
}