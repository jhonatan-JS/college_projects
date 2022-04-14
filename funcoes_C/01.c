#include <stdio.h>
float imc (float peso, float altura){
return ((peso)/(altura*altura));
}

int main(){
float peso, altura, result;
printf("Calculo do IMC\n");
printf("Informe seu peso: \n");
scanf("%f", &peso);
printf("Informe sua altura: \n");
scanf("%f", &altura);

result = imc(peso, altura);

printf("Resultado: %.2f ", result);
return 0;
}