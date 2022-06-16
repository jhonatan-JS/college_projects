#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int qtde = 0;

typedef struct {
	int dia, mes, ano;
}Data;

typedef struct {
	int id;
	char descricao[100];
	float valor;
	Data data;
}Despesa;

void cadastrarDespesa(Despesa despesas[]) {	
	int i;
	printf("\nCadastro de Despesa");
	despesas[qtde].id = qtde + 1;
	printf("\nDescricao: ");
	scanf(" %[A-Z a-z 0-9]", &despesas[qtde].descricao);
	printf("Valor: ");
	scanf("%f", &despesas[qtde].valor);
	printf("Data");
	printf("\nDia: ");
	scanf("%d", &despesas[qtde].data.dia);
	printf("\nMes: ");
	scanf("%d", &despesas[qtde].data.mes);
	printf("\nAno: ");
	scanf("%d", &despesas[qtde].data.ano);
	qtde++;
}
	
void imprimeTodasDespesas(Despesa despesas[]) {
	int i;
	
	if(qtde >= 1 ){
		printf("\n----------Listagem de Despesas----------");
	
		for(i=0; i < qtde; i++) {

			printf("\nDespesa: %d", despesas[i].id);
			printf("\nDescricao: %s", despesas[i].descricao);
			printf("\nValor: %.1f", despesas[i].valor);
			printf("\nData: %02d/%02d/%02d\n\n", despesas[i].data.dia, despesas[i].data.mes, despesas[i].data.ano);
		}
	} else {
		printf("Nada a declarar\n");
	}

}

void imprimeDespesasPorId(Despesa despesas[], int id) {
	if(id <= qtde) {
		printf("\n----------Despesa----------");
		printf("\nDespesa: %d", despesas[id-1].id);
		printf("\nDescricao: %s", despesas[id-1].descricao);
		printf("\nValor: %.1f", despesas[id-1].valor);
		printf("\nData: %02d/%02d/%02d\n\n", despesas[id-1].data.dia, despesas[id-1].data.mes, despesas[id-1].data.ano);
	} else {
		printf("id nao cadastrado");
	}
}

void removeDespesa(Despesa despesas[], int id) {
	int i;
	if(despesas[id-1].id != 0) {
		imprimeDespesasPorId(despesas, id);
		for (i = id-1; i > qtde; i++) {
			despesas[i] = despesas[i+1];
			despesas[i].id--;
		}
		despesas[qtde].id = 0;
		qtde--;
		printf("Remocao realizada com sucesso!\n");
	}
}

int main()
{	
	int opcao, idDespesa;
	Despesa despesas[100];
	Data data;

	memset(&despesas, 0, sizeof(Despesa));
	
	do{
		printf("Digite a opcao desejada ou -1 para sair.\n");
		printf("(1)Cadastrar despesas\n");
		printf("(2)Imprimir todas despesas\n");
		printf("(3)Imprimir despesa por id\n");
		printf("(4)Atualizar despesa\n");
		printf("(5)Remover despesa\n");
		printf("(6)Pesquisar por data\n");
		printf("(7)Imprimir despesas do mes/ano e o total\n");
		scanf("%d", &opcao);
		
		switch(opcao) {
	    	case 1:
	    		cadastrarDespesa(despesas);
    		break;
    		
    		case 2:
	    		imprimeTodasDespesas(despesas);
    		break;
    		    	   		    		
    		case 3:
    			printf("Qual despesa deseja remover?\n");
    			scanf("%d", &idDespesa);
	    		removeDespesa(despesas, idDespesa);
    		break;
    	default:
    		printf("Opcao invalida\n");
    		break;
    	}
	} while(opcao != -1);
	
	return 0;
}