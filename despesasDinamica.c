#include <stdio.h>
#include <string.h>

typedef struct {
    int dia, mes, ano;
}Data;

typedef struct {
    int id;
    char descricao[100];
    float valor;
    Data data;
    struct Despesa *prox;
}Despesa;

static int qtde = 0;

Despesa cadastraDespesa(){
    Despesa despesa;
    printf("\nCadastro de Despesa");
    despesa.id = qtde+1;
    printf("\nDescricao: ");
    scanf(" %[A-z a-z 0-9]", &despesa.descricao);
    printf("Valor: ");
    scanf("%f", &despesa.valor);
    printf("Data ");
    printf("\ndia:");
    scanf("%d", &despesa.data.dia);
    printf("mes:");
    scanf("%d", &despesa.data.mes);
    printf("ano:");
    scanf("%d", &despesa.data.ano);
    qtde++;
    return despesa;
}

Despesa *inserirDespesa(Despesa* listaDespesas, Despesa despesa){
    Despesa *novo = (Despesa*) malloc(sizeof(Despesa));
    novo->id = despesa.id;
    strcpy(novo->descricao,despesa.descricao);
    novo->valor = despesa.valor;
    novo->data = despesa.data;//ou passar um a um
    novo->prox = listaDespesas;
    return novo;
}

void imprimeTodasDespesas(Despesa *listaDespesas){
    Despesa *p;
    printf("\n----------Listagem de Despesas----------");
    for(p = listaDespesas; p != NULL; p = p->prox){
        printf("\nDespesa: %d", p->id);
        printf("\nDescricao: %s", p->descricao);
        printf("\nValor: %.2f", p->valor);
        printf("\nData: %d/%d/%d\n\n", p->data.dia,
               p->data.mes, p->data.ano);
    }
}

Despesa *removeDespesa(Despesa *listaDespesas, int id){
    Despesa *ant = NULL;
    Despesa *perc = listaDespesas;

    while(perc != NULL && perc->id != id){
        ant = perc;
        perc = perc -> prox;
    }

    if(perc == NULL){
        printf("Elemento nao encontrado: %d\n", id);
        return listaDespesas;
    }

    if(ant == NULL){
        listaDespesas = perc -> prox;
    }else{
        ant->prox = perc->prox;
    }
    printf("Removendo o elemento de id: %d", id);
    free(perc);
    return listaDespesas;
}

Despesa *criaListaDespesas(){
    return NULL;
}

void liberarListaDespesas(Despesa *listaDespesas){
    Despesa *p = listaDespesas;
    while(p != NULL){
        Despesa *temp = p->prox;
        free(p);
        p = temp;
    }
}

int main()
{
    Despesa *listaDespesas;
    Despesa despesa;
    int opcao, id;
    listaDespesas = criaListaDespesas();
    do{
        printf("----------Sistema de Despesas----------");
        printf("\n1 - Cadastrar Despesa");
        printf("\n2 - Listar todas as despesas");
        printf("\n4 - Remover Despesa");
       // printf("\n6 - Listar todas as despesas por valor (Decrescente)");
        printf("\n0 - Sair\n>>");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            despesa = cadastraDespesa();
            listaDespesas = inserirDespesa(listaDespesas, despesa);
            printf("Cadastro realizado com sucesso!\n");
            break;
        case 2:
            imprimeTodasDespesas(listaDespesas);
            break;
        case 3:
            //
            break;
        case 4:
            printf("\nRemocao de Despesa\n");
            printf("Digite o id da despesa:");
            scanf("%d", &id);
            listaDespesas = removeDespesa(listaDespesas, id);
            break;
        case 5:
            printf("\nBusca de Despesa por id\n");
            printf("Digite o id da despesa:");
            scanf("%d", &id);
            imprimeDespesaPorId(listaDespesas);
            break;
        case 6:

            break;
        case 0:
            printf("\nTchau!!");
            liberarListaDespesas(listaDespesas);
            break;
        default:
            printf("\nOpcao Invalida");
        }
    }while(opcao != 0);

    return 0;
}