#include <stdio.h>

float imc (float peso, float altura){
return ((peso)/(altura*altura));
}

int main(){
  float peso, altura, result;
  char sexo;

  printf("infome seu sexo: \n");
  scanf("%c", &sexo);
  sexo = toupper(sexo);
  printf("Informe seu peso: \n");
  scanf("%f", &peso);
  printf("Informe sua altura: \n");
  scanf("%f", &altura);

  result = imc(peso, altura);

  if(sexo == 'M') {
    if( result < 19.1 ) {
      printf("Seu IMC é: %.2f e esta abaixo da média", result);
    } else if (result >= 19.1 && result < 25.8) {
      printf("Seu IMC é: %.2f e esta no peso normal", result);
    } else if (result >= 25.8 && result < 27.3) {
      printf("Seu IMC é: %.2f e esta marginalmente acima do peso", result);
    } else if ( result > 27.3 && result < 32.3 ) {
      printf("Seu IMC é: %.2f e esta acima do peso ideal", result);
    } else if (result > 32.3) {
      printf("Seu IMC é: %.2f e esta em obesidade", result);
    }

  } else {
    if( result < 20.7 ) {
      printf("Seu IMC é: %.2f e esta abaixo da média", result);
    } else if( result > 20.7 && result < 26.4 ) {
    printf("Seu IMC é: %.2f e esta com peso normal", result);
    } else if( result > 26.4 && result < 27.8 ) {
    printf("Seu IMC é: %.2f e esta marginalmente acima do peso", result);
    }else if( result > 27.8 && result < 31.1 ) {
    printf("Seu IMC é: %.2f e esta marginalmente acima do peso", result);
    } else if( result > 31.1 ) {
    printf("Seu IMC é: %.2f e esta marginalmente acima do peso", result);
    }
  }

  return 0;
}