#include <stdio.h>
#include <stdlib.h>

#define MATRICULA 9
#define TAM 5

int main(){
	
	int i;

	typedef struct {
		char nome[20], matricula[MATRICULA], curso[20];
	}Alunos;

	Alunos *vetAlunos=malloc(TAM*sizeof(Alunos));

	for(i=0; i<TAM; i++){
		printf("Informe o nome do aluno:");
		scanf("%[^\n]s", vetAlunos[i].nome);
		getchar();

		printf("Informe a matricula do aluno:");
		scanf("%[^\n]s", vetAlunos[i].matricula);
		getchar();

		printf("Informe o curso do aluno:");
		scanf("%[^\n]s", vetAlunos[i].curso);
		getchar();		

		system("clear || cls");
	}

	for(i=0; i<TAM; i++){
		printf("Aluno %d", i+1);
		printf("Nome:%s\n",  vetAlunos[i].nome);
		printf("Matricula:%s\n", vetAlunos[i].matricula);
		printf("Curso:%s\n", vetAlunos[i].curso);
		printf("\n");
	}

	free(vetAlunos);
	vetAlunos=NULL;
}