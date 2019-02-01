#include <stdio.h>
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
void verificaAprovadosReprovados(Aluno *alunos);

int main(){
	Aluno *alunos=malloc(TAM*sizeof(Aluno));

	preencheAlunos(alunos);
	verificaAprovadosReprovados(alunos);

	free(alunos);
	alunos=NULL;
}

void preencheAlunos(Aluno *alunos){
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

void verificaAprovadosReprovados(Aluno *alunos){
	int i, aprovados=0, reprovados=0;

	for(i=0; i<TAM; i++){
		if(alunos[i].p3>=6){
			aprovados++;
		}
		else{
			reprovados++;
		}
	}

	system("clear || cls");

	printf("Quantidade de alunos aprovados: %d\n", aprovados);
	printf("Quantidade de alunos reprovados: %d\n", reprovados);



}
