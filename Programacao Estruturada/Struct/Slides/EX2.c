#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define TAM 30

typedef struct{
	char nome[50];
	int idade;
	float salario;
}Funcionario;

void lp();
void preeencheFuncionarios(Funcionario *funcionarios);
float salariosAcima30Anos(Funcionario *funcionarios);

int main(){
	Funcionario *funcionarios=malloc(TAM*sizeof(Funcionario));

	setlocale(LC_ALL, "Portuguese");

	preeencheFuncionarios(funcionarios);
	
	printf("Soma dos salários dos funcionários com 20 anos ou mais:%.2f", salariosAcima30Anos(funcionarios));
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

float salariosAcima20Anos(Funcionario *funcionarios){
	int i, somaSal=0;

	for(i=0; i<30; i++){
		if(funcionarios[i].idade>=20){
			somaSal=+funcionarios[i].salario;
		}
	}
	return cont;
}