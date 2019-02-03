#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define TAM 20

#define SAL 880

typedef struct{
	char nome[50];
	int numeroConta;
	float salario;
}Conta;

void lp();

void preencheClientes(Conta *clientes);
int acima3Salarios(Conta *clientes);

int main(){
	Conta *clientes=malloc(TAM*sizeof(Conta));

	setlocale(LC_ALL, "Portuguese");

	preencheClientes(clientes);
	
	printf("Quantidade de funcionários com mais de três salários:%d", acima3Salarios(clientes));

	free(clientes);
	clientes=NULL;
}

void lp(){
	system("clear || cls");
}

void preencheClientes(Conta *clientes){
	int i;

	lp();

	for(i=0; i<TAM; i++){
		printf("Informe o nome:");
		scanf("%[^\n]s", clientes[i].nome);
		getchar();

		printf("Informe o número da conta:");
		scanf("%d", &clientes[i].numeroConta);
		getchar();

		printf("Informe o saldo:");
		scanf("%f", &clientes[i].salario);
		getchar();

		lp();
	}
}

int acima3Salarios(Conta *clientes){
	int i, cont=0;

	lp();

	for(i=0; i<TAM; i++){
		if(clientes[i].salario>(3*880)){
			cont++;
		}
	}
	return cont;
}