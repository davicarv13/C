#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#define TAM 25

typedef struct{
	char nome[50];
	int idade;
	float salario;
	char cargo[30];
}Funcionario;

void lp();
void preeencheFuncionarios(Funcionario *funcionarios);
int salariosDiretores(Funcionario *funcionarios);

int main(){
	Funcionario *funcionarios=malloc(TAM*sizeof(Funcionario));

	setlocale(LC_ALL, "Portuguese");

	preeencheFuncionarios(funcionarios);
	
	printf("Quantidade de diretores com salário acima de R$ 5000,00: %d", salariosDiretores(funcionarios));
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

		printf("Informe o cargo:");
		scanf("%[^\n]s", funcionarios[i].cargo);
		getchar();

		lp();
	}
}

int salariosDiretores(Funcionario *funcionarios){
	int i, cont=0;

	for(i=0; i<30; i++){
		if(funcionarios[i].salario>5000 && strcmp("diretor", funcionarios[i].cargo)==0){
			cont++;
		}
	}
	return cont;
}

