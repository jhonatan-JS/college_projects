#include <stdio.h>
#include <stdlib.h>

int main()
{
	float salarioBruto;
	float dependentes;
	float salario;
	float valor1;
	float inss;

	printf("Qual Valor do seu Salario?:");
	scanf("%f", &salarioBruto);
	printf("Quantos dependentes?:");
	scanf("%f", &dependentes);
	printf("\n");
	printf("Seu Salario: %.2f\n", salarioBruto);

	if (salarioBruto <= 1100)
	{
		inss = salarioBruto * 0.075;
		printf("Valor INSS a ser pago: %.2f\n", inss);
	}

	else if (salarioBruto > 1100 && salarioBruto <= 2203.48)
	{
		valor1 = (salarioBruto - 1100) * 0.09;
		inss = valor1  + (1100 * 0.075);
		printf("Valor INSS a ser pago: %.2f\n", inss);
	}

	else if (salarioBruto > 2203.48 && salarioBruto <= 3305.22)
	{
		valor1 = (salarioBruto - 2203.48) * 0.12;
		inss = valor1  + (1100 * 0.075) + (1103.48 * 0.09);
		printf("Valor INSS a ser pago: %.2f\n", inss);
	}
	else if (salarioBruto > 3305.22 && salarioBruto <= 6433.57)
	{
		valor1 = (salarioBruto - 3305.22) * 0.14;
		inss = valor1  + (1100 * 0.075) + (1103.48 * 0.09) + (1101.74 * 0.12);
		printf("Valor INSS a ser pago: %.2f\n", inss);
	}

		else if (salarioBruto > 6433.57)
	{
		inss = 751.97;
		printf("Valor INSS a ser pago: %.2f\n", inss);
	}


	salario = salarioBruto - (dependentes * 189.59) - inss;
	printf("Salario Base: %.2f\n", salario);
	
	float aliquota;
	float imposto;
	
	if (salario <= 1903.99)
	{
		printf("Isento de Impostos\n");
	}
	else if (salario > 1903.99 && salario <= 2826.65)
	{
		aliquota = salario * 0.075;
		imposto = aliquota - 142.80;
		printf("Imposto Devido:%.2f\n", imposto);
		printf("Salario liquido:%.2f\n", salario - imposto);
	}
	else if (salario > 2826.65 && salario <= 3751.05)
	{
		aliquota = salario * 0.15;
		imposto = aliquota - 354.80;
		printf("Imposto Devido:%.2f\n", imposto);
		printf("Salario liquido:%.2f\n", salario - imposto);
	}
	else if (salario > 3751.05 && salario <= 4664.68)
	{
		aliquota = salario * 0.225;
		imposto = aliquota - 636.13;
		printf("Imposto Devido:%.2f\n", imposto);
		printf("Salario liquido:%.2f\n", salario - imposto);
	}
	else if (salario > 4664.68 )
	{
		aliquota = salario * 0.275;
		imposto = aliquota - 869.36;
		printf("Imposto Devido:%.2f\n", imposto);
		printf("Salario liquido:%.2f\n", salario - imposto);
	}
}
