#include <stdio.h>
#include <stdlib.h>

void matrizMenu() {
  int menu[3][3], i, j, tamanho = 3, 
  opcao, lCParaSomar = 0, resultSoma=0, 
  acumulationC = 0,acumulationL = 0, 
  qtdMaior=0,valorInformado;
  char linhaqtd,coluqtd;

  for(i=0; i < tamanho; i++) {
    printf("Linha %d\n", i);
    for(j=0; j < tamanho; j++) {
      scanf("%d", &menu[i][j]);
    }
  }
  
  printf("Escolha uma opcao.\n");
  printf("\n");
  
  printf("(1)-Somar linha.\n");
  printf("(2)-Somar coluna.\n");
  printf("(3)-Quantiade de linhas e colunas nulas distinguindo-as.\n");
  printf("(4)-Informar a quantidade de elementos maiores que o valor informado.\n");
  printf("(5)-Buscar um valor na matriz.\n");
  
  scanf("%d", &opcao); 
  
  for(i=0; i < tamanho; i++) {
    printf("\n\n");
    for(j=0; j < tamanho; j++) {
      printf("%d ", menu[i][j]);
    }
  }
  
  switch(opcao) {
    //Somar linha.
    case 1:
      printf("\nQual linha deseja somar?\n");
      scanf("%d", &lCParaSomar);
      
      for(i=lCParaSomar-1; i < lCParaSomar; i++) {
        for(j=0; j < tamanho; j++) {
          resultSoma += menu[i][j];
        }
      }
      printf("A soma da linha %d e %d", i, resultSoma);
    break;
    //Somar coluna.
    case 2:
      printf("\nQual coluna deseja somar?\n");
      scanf("%d", &lCParaSomar);
        
      for(i=0; i < tamanho; i++){
        for(j=lCParaSomar-1; j<lCParaSomar; j++){
          resultSoma += menu[i][j];
        }
      }
      printf("A soma da coluna %d e %d:", j, resultSoma);
    break;
    //Quantiade de linhas e colunas nulas distinguindo-as."
    case 3:
      for(i=0; i < tamanho; i++){
        int quantidadeD0 = 0;
        for(j=0; j < tamanho; j++){
          if(menu[i][j] == 0) {
            quantidadeD0++;
          }
        }
        if(quantidadeD0 == 3){
          acumulationL++;
        }
      }

      for(j=0; j < tamanho; j++){
        int quantidadeD0 = 0;
        for(i=0; i < tamanho; i++){
          if(menu[i][j] == 0) {
            quantidadeD0++;
          }
        }

        if(quantidadeD0 == 3){
          acumulationC++;
        }
      }

      if(acumulationL > 1){
        linhaqtd = 's';
      } else if(acumulationC > 1){
        coluqtd = 's';
      } else {
        linhaqtd = ' ';
        coluqtd = ' ';
      }
      printf("\nQuantidade de linhas e colunas nulas.");
      printf("\n%d Linha%c", acumulationL, linhaqtd);
      printf("\n%d Coluna%c", acumulationC, coluqtd);
    break;
    //Informar a quantidade de elementos maiores que o valor informado.
    case 4:
      printf("\nDigite um valor.\n");
      scanf("%d", &valorInformado);

      for(i=0; i < tamanho; i++){
        for(j=0; j < tamanho; j++){
          if(menu[i][j] > valorInformado){
            qtdMaior++;
          }
        }
      }
      printf("\n%d valores maiores que o informado.", qtdMaior);
    break;
    //Buscar um valor na matriz.
    case 5:
      printf("\nDigite um valor.\n");
      scanf("%d", &valorInformado);

      for(i=0; i < tamanho; i++){
        for(j=0; j < tamanho; j++){

          if(menu[i][j] == valorInformado){
            printf("Valor encontrado na linha %d coluna %d", i+1 ,j+1);
          }
        }
      }
    break;
    default:
    printf("Opcao invalida!\n");
  }
}

int main()
{
  printf("Digite os valores.\n");
  matrizMenu();
  
  return 0;
}