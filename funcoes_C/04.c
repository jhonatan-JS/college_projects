#include <stdio.h>

float calcMedia(float n1, float n2, float n3, float n4){
  float media;

  media = (n1 + n2 + n3 + n4) / 4;

  if (media < 4) {
    printf("Reprovado");
  } else if (media >= 4 && media < 6 ) {
    printf("Exame");
  } else if (media >= 6) {
    printf("Aprovado");
  }

  return media;
}

int main()
{
  float n1, n2, n3, n4;
  printf("Calcular media do aluno.\n");
  printf("Primeira nota: ");
  scanf("%f", &n1);

  printf("Segunda nota: ");
  scanf("%f", &n2);

  printf("Terceira nota: ");
  scanf("%f", &n3);

  printf("Ultima nota: ");
  scanf("%f", &n4);

  printf(", a media do aluno é: %.1f ", calcMedia(n1, n2, n3, n4));
}