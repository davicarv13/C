#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[50];
	int idade;
	char cargo[20];
	float salario;
}Funcionario;

#define TAM 3

void preencheFuncionarios(Funcionario *funcionarios);
void ordenaFuncionariosPelaIdade(Funcionario *funcionarios);
void imprimeFuncionarios(Funcionario *funcionarios);

int main(){

	Funcionario *funcionarios=malloc(TAM*sizeof(Funcionario));

	preencheFuncionarios(funcionarios);
	ordenaFuncionariosPelaIdade(funcionarios);
	imprimeFuncionarios(funcionarios);

	free(funcionarios);
	funcionarios=NULL;
}


void preencheFuncionarios(Funcionario *funcionarios){
	int i;

	printf("Funcionarios:\n");

	for(i=0; i<TAM; i++){
		printf("Informe o nome");
		scanf("%[^\n]s", funcionarios[i].nome);
		getchar();

		printf("Informe a idade:");
		scanf("%d", &funcionarios[i].idade);
		getchar();

		printf("Informe o cargo:");
		scanf("%[^\n]s", funcionarios[i].cargo);
		getchar();

		printf("Informe o salario:");
		scanf("%f", &funcionarios[i].salario);
		getchar();

		system("clear || cls");
	}
}
void ordenaFuncionariosPelaIdade(Funcionario *funcionarios){
	int i, j, pos=0, menorIdade=funcionarios[0].idade;
	
	Funcionario funcionarioAux;

	for(i=0; i<TAM; i++){
		for(j=i; j<TAM; j++){
			if((funcionarios[j].idade)<menorIdade){
				menorIdade=funcionarios[j].idade;		
				pos=j;
			}
		}
		funcionarioAux=funcionarios[i];
		funcionarios[i]=funcionarios[pos];
		funcionarios[pos]=funcionarioAux;
		menorIdade=funcionarios[i+1].idade;
		pos=i+1;
	}
}
void imprimeFuncionarios(Funcionario *funcionarios){
	int i;

	printf("\n\nFuncionarios (Ordenados pela idade):\n\n");

	for(i=0; i<TAM; i++){
		printf("Nome: %s\n", funcionarios[i].nome);
		printf("Idade: %d\n", funcionarios[i].idade);
		printf("Cargo: %s\n", funcionarios[i].cargo);
		printf("Salario: R$%.2f\n", funcionarios[i].salario);

		printf("\n");
	}
}