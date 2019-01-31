#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define TAM 20

typedef struct{
	char nome[50];
	int idade;
	float salario;
}Funcionario;

void lp();
void preeencheFuncionarios(Funcionario *funcionarios);
int Acima30Anos(Funcionario *funcionarios);

int main(){
	Funcionario *funcionarios=malloc(TAM*sizeof(Funcionario));

	setlocale(LC_ALL, "Portuguese");

	preeencheFuncionarios(funcionarios);
	
	printf("Quantidade de funcionários com 30 anos ou mais:%d", Acima30Anos(funcionarios));
}

void lp(){
	system("clear || cls");
}

void preeencheFuncionarios(Funcionario *funcionarios){
	int i;

	lp();

	for(i=0; i<TAM; i++){
		printf("Informe o nome:");
		scanf("%[^\n]s", funcionarios[i].nome);
		getchar();

		printf("Informe a idade:");
		scanf("%d", &funcionarios[i].idade);
		getchar();

		printf("Informe o nome:");
		scanf("%f", &funcionarios[i].salario);
		getchar();

		lp();
	}
}

int Acima30Anos(Funcionario *funcionarios){
	int i, cont=0;

	lp();

	for(i=0; i<30; i++){
		if(funcionarios[i].idade>=30){
			cont++;
		}
	}
	return cont;
}
