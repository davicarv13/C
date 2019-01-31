#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define TAM 20

typedef struct{
	char nome[50];
	int numeroConta;
	float salario;
}Conta;

void lp();
void preencheClientes(Conta *clientes);
int saldoAcima1000(Conta *clientes);

int main(){
	Conta *clientes=malloc(TAM*sizeof(Conta));

	setlocale(LC_ALL, "Portuguese");

	preencheClientes(clientes);
	
	printf("Quantidade de funcionários com 30 anos ou mais:%d", saldoAcima1000(clientes));
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

int saldoAcima1000(Conta *clientes){
	int i, cont=0;

	lp();

	for(i=0; i<30; i++){
		if(clientes[i].salario>1000){
			cont++;
		}
	}
	return cont;
}
