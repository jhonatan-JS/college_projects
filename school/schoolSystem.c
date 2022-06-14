#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int qtde = 0;

typedef struct {
	int     numero;
	char  nome[30];
	char curso[30];
	float    nota1;
	float    nota2;
}Aluno;

FILE* abrirArquivo(FILE *arq, char *nomeDoArquivo, char *type) {
	
	if ((arq = fopen(nomeDoArquivo, type)) == NULL) {
		printf("Falha ao abrir o arquivo %s\n", nomeDoArquivo);
		exit(1);
	}
	
	return arq;
}

int encontarRaDoAluno(Aluno alunos[], int numero) {
	int i=0;
	FILE *arq;
	arq = abrirArquivo(arq, "alunos.dat", "rb");
	
	while (fread(&alunos[i], sizeof(Aluno), 1, arq)) {
		if (numero == alunos[i].numero) {
	    	return i;
		}
		i++;	
	}
	fclose(arq);
	return -1;
			
}

int encontarRaDoAlunoAndListar(Aluno alunos[], int numero) {
	int i=0;
	FILE *arq;
	arq = abrirArquivo(arq, "alunos.dat", "rb");
	
	while (fread(&alunos[i], sizeof(Aluno), 1, arq)) {
		if (numero == alunos[i].numero) {
			printf("\nid: %d", qtde);
			printf("\nRA do Aluno: %d ", alunos[i].numero);
			printf("\nNome do Aluno: %s ", alunos[i].nome);
			printf("\nCurso em Andamento: %s", alunos[i].curso);
			printf("\nPrimeira Nota: %.2f", alunos[i].nota1);
			printf("\nSegunda Nota: %.2f", alunos[i].nota2);
			
	    	return i;
		}
		i++;	
	}
	fclose(arq);
	return -1;
			
}

void alterarAluno(Aluno alunos[], FILE *arq, int opcao) {
	
	int numberAluno, resultAluno;
	printf("Qual Aluno Deseja Alterar?\n");
	scanf("%d", &numberAluno);
	
	resultAluno = encontarRaDoAlunoAndListar(alunos, numberAluno);
	
	if (resultAluno != -1) {
		arq = abrirArquivo(arq, "alunos.dat", "r+b");
		fseek(arq, resultAluno*sizeof(Aluno), SEEK_SET);
		
		if (opcao == 3) {
			printf("\n\nPrimeira Nota: ");
			scanf("%f", &alunos[resultAluno].nota1);
			printf("\nSegunda Nota: ");
			scanf("%f", &alunos[resultAluno].nota2);
			fwrite(&alunos[resultAluno], sizeof(Aluno), 1, arq);
		} else if (opcao == 4) {
			printf("\n\nNome do Novo Curso:");
			scanf (" %[A-Z a-z 0-9]", &alunos[resultAluno].nome);
			fwrite(&alunos[resultAluno], sizeof(Aluno), 1, arq);
		}
	}
	
	fclose(arq);
	
}


void cadastrarAluno(Aluno alunos[], FILE *arq) {
	int i = 0;
	int registro, result;
	
	printf("\nCadastrar.");
	printf("\nRA do Aluno: ");
	scanf (" %d", &registro);
	result = encontarRaDoAluno(alunos, registro);
		
	if (result == -1) {
		alunos[qtde].numero = registro;
		printf("\nNome do Aluno: ");
		scanf (" %[A-Z a-z 0-9]", &alunos[qtde].nome);
		printf("\nCurso em Andamento: ");
		scanf (" %[A-Z a-z 0-9]", &alunos[qtde].curso);
		printf("\nPrimeira nota: ");
		scanf ("%f", &alunos[qtde].nota1);
		printf("\nSegunda nota: ");
		scanf ("%f", &alunos[qtde].nota2);
		qtde++;
		fwrite(&alunos[qtde - 1], sizeof(Aluno), 1, arq);
	} else {
		printf("Ra existente, tente novamente.");
	}
}

void listarAlunos(Aluno alunos[], FILE *arq) {
	int i = 0;

	while (fread(&alunos[i], sizeof(Aluno), 1, arq) != 0 ) {
		qtde++;
		printf("\nid: %d", qtde);
		printf("\nRA do Aluno: %d", alunos[i].numero);
		printf("\nNome do Aluno: %s", alunos[i].nome);
		printf("\nCurso em Andamento: %s", alunos[i].curso);
		printf("\nPrimeira nota: %.2f", alunos[i].nota1);
		printf("\nSegunda nota: %.2f\n", alunos[i].nota2);
		}
	fclose(arq);
}

int main() {
	int opcao;
	FILE *arquivo = NULL;
	Aluno alunos[200];
	
	memset(&alunos, 0, sizeof(Aluno));
	
	do{
    	printf("\n----------Sistema Escola----------\n");
		printf("(1) Cadastrar aluno\n");
		printf("(2) Listar alunos\n");
		printf("(3) Alterar Notas do aluno\n");
		printf("(4) Alterar Curso do aluno\n");
		printf("(0) Sair\n");

		scanf("%d", &opcao);

		switch(opcao) {
	    	case 1:
	    		arquivo = abrirArquivo(arquivo, "alunos.dat", "ab");
	    		cadastrarAluno(alunos, arquivo);
	    		fclose(arquivo);
    		break;

    		case 2:
    			arquivo = abrirArquivo(arquivo, "alunos.dat", "rb");
				listarAlunos(alunos, arquivo);
    		break;
    		
    		case 3:
				alterarAluno(alunos, arquivo, opcao);
    		break;
    		
    		case 4:
				alterarAluno(alunos, arquivo, opcao);
    		break;
    		
    	default:
            if(opcao == 0) {
                printf("Saindo do Programa...\nTchau Tchau!\n");
            } else {
                printf("Opcao invalida\n");
            }
        break;
    	}
    	
	} while(opcao != 0);
	
	return 0;
}
