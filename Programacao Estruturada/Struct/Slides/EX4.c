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

void preencheAlunos(Aluno *aluno, int i);
void verificaAprovadosReprovados(const float *p3, int i);

int main(){

	Aluno aluno;

	int i=0;

	for(i=0; i<TAM; i++){
		preencheAlunos(&aluno, i);
	}
}

void preencheAlunos(Aluno *aluno, int i){
	
	printf("Informe a matricula:");
	scanf("%d", &aluno->matricula);
	getchar();
	printf("Informe o primeiro nome:");
	scanf("%s", aluno->nome);
	getchar();
	printf("Informe a nota da P1:");
	scanf("%f", &aluno->p1);
	getchar();
	printf("Informe a nota da P2:");
	scanf("%f", &aluno->p2);
	getchar();

	aluno->p3=(aluno->p1+aluno->p2)/2;

	verificaAprovadosReprovados(&aluno->p3, i);
}

void verificaAprovadosReprovados(const float *p3, int i){
	static int aprovados=0;
	static int reprovados=0;

	if((*p3)>=6){
		aprovados++;
	}
	else{
		reprovados++;
	}

	i++;

	if(i==(TAM)){
		system("clear || cls");
		printf("Quantidade de alunos aprovados: %d\n", aprovados);
		printf("Quantidade de alunos reprovados: %d\n", reprovados);
	}
	
}
