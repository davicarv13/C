#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 30

typedef struct {
	int matricula;
	char nome[20];
	float p1;
	float p2;
	float p3;
}Aluno;

void preencheAlunos(Aluno *alunos);
void verificaAluno(Aluno *alunos, char *nome);

int main(){

	char nome[20];

	Aluno *alunos=malloc(TAM*sizeof(Aluno));

	preencheAlunos(alunos);

	printf("Informe o nome de um aluno a ser pesquisado:");
	scanf("%s", nome);
	getchar();

	verificaAluno(alunos, nome);

	free(alunos);
	alunos=NULL;
}

void preencheAluno(Aluno *alunos){
	int i;

	for(i-0; i<TAM; i++){
		printf("Informe a matricula:");
		scanf("%d", &alunos[i].matricula);
		getchar();
		printf("Informe o primeiro nome:");
		scanf("%s", alunos[i].nome);
		getchar();
		printf("Informe a nota da P1:");
		scanf("%f", &alunos[i].p1);
		getchar();
		printf("Informe a nota da P2:");
		scanf("%f", &alunos[i].p2);
		getchar();

		alunos[i].p3=alunos[i].p1+alunos[i].p2;

		system("clear || cls");
	}
}

void verificaAluno(Aluno *alunos, char *nome){
	int i;

	printf("Notas de alunos cujo nome e %s:", nome);

	for(i=0; i<TAM; i++){
		if(strcmp(alunos[i].nome, nome)==0){
			printf("P1: %.2f\n", alunos[i].p1);
			printf("P2: %.2f\n", alunos[i].p2);
			printf("p3: %.2f\n", alunos[i].p3);
			printf("\n\n");
		}
	}

	system("clear || cls");

}
