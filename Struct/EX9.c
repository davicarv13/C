#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 2

typedef struct{
	char nome[50], matricula[9];
	float media;
}Alunos;

void lp(); //Limpa tela 
void preencheAlunos(Alunos *vetAlunos); //Preenche vetor de structs com dados dos alunos
int verificaAprovados(Alunos *vetAlunos);
int verificaReprovados(Alunos *vetAlunos);
void preencheAlunosAprovados(Alunos *vetAlunosAprovados, Alunos *vetAlunos);
void preencheAlunosReprovados(Alunos *vetAlunosReprovados, Alunos *vetAlunos);
void imprimeAlunosAprovadosReprovados(Alunos *vetAlunosAprovados, Alunos *vetAlunosReprovados, int aprovados, int reprovados);

int main(){

	int aprovados, reprovados;

	setlocale(LC_ALL, "Portuguese");
	Alunos *vetAlunos=malloc(TAM*sizeof(Alunos));

	preencheAlunos(vetAlunos);

	aprovados=verificaAprovados(vetAlunos);
	reprovados=verificaReprovados(vetAlunos); 

	Alunos *vetAlunosAprovados=malloc(aprovados*sizeof(Alunos));
	Alunos *vetAlunosReprovados=malloc(reprovados*sizeof(Alunos));
      
	preencheAlunosAprovados(vetAlunosAprovados, vetAlunos);
	preencheAlunosReprovados(vetAlunosReprovados, vetAlunos);

	imprimeAlunosAprovadosReprovados(vetAlunosAprovados, vetAlunosReprovados, aprovados, reprovados);

	free(vetAlunos);
	vetAlunos=NULL;
	free(vetAlunosAprovados);
	vetAlunosAprovados=NULL;
	free(vetAlunosReprovados);
	vetAlunosReprovados=NULL;

}
      
void lp(){
	system("clear || cls");
}

void preencheAlunos(Alunos *vetAlunos){
	int i;

	lp();

	printf("Alunos:\n");

	for(i=0; i<TAM; i++){
		printf("Informe o nome:");
		scanf("%[^\n]s", vetAlunos[i].nome);
		getchar();
		printf("Informe a matrícula");
		scanf("%[^\n]s", vetAlunos[i].matricula);
		getchar();
		printf("Informe a média:");
		scanf("%f", &vetAlunos[i].media);
		getchar();

		lp();
	}
}

int verificaAprovados(Alunos *vetAlunos){
	int i, aprovados=0;

	for(i=0; i<TAM; i++){
		if((vetAlunos[i].media)>=6){
			aprovados++;
		}
	}

	return aprovados;
}
int verificaReprovados(Alunos *vetAlunos){
	int i, reprovados=0;

	for(i=0; i<TAM; i++){
		if((vetAlunos[i].media)<6){
			reprovados++;
		}
	}

	return reprovados;
}	

void preencheAlunosAprovados(Alunos *vetAlunosAprovados, Alunos *vetAlunos){
	int i;

	for(i=0; i<TAM; i++){
		if((vetAlunos[i].media)>=6){
			vetAlunosAprovados[i]=vetAlunos[i];
		}
	}
}
void preencheAlunosReprovados(Alunos *vetAlunosReprovados, Alunos *vetAlunos){
	int i;

	for(i=0; i<TAM; i++){
		if((vetAlunos[i].media)<6){
			vetAlunosReprovados[i]=vetAlunos[i];
		}
	}
}

void imprimeAlunosAprovadosReprovados(Alunos *vetAlunosAprovados, Alunos *vetAlunosReprovados, int aprovados, int reprovados){
	int i;

	printf("Alunos aprovados:\n");

	for(i=0; i<aprovados; i++){
		printf("%9s \t %s \n", "Nome", vetAlunosAprovados[i].nome);
		printf("%9s \t %s \n", "Matrícula", vetAlunosAprovados[i].matricula);
		printf("%9s \t %.2f \n", "Média", vetAlunosAprovados[i].media);

		printf("\n");
	}

	printf("\n");

	printf("Alunos reprovados:\n");

	for(i=0; i<reprovados; i++){
		printf("%9s \t %s \n", "Nome", vetAlunosReprovados[i].nome);
		printf("%9s \t %s \n", "Matrícula", vetAlunosReprovados[i].matricula);
		printf("%9s \t %.2f \n", "Média", vetAlunosReprovados[i].media);

		printf("\n");
	}
}
