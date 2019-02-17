#include <stdio.h>
#include <stdlib.h>

#define TAM 2

typedef struct{
	char nome[50];
	int numeroConta;
	float saldo;
}Conta;

void lp();
int preencheClientes(Conta *cliente);
int saldoAcima1000(const float *saldo);

int main(){

	Conta cliente;
	
	printf("Quantidade de clientes com saldo acima de R$1000,00:%d \n", preencheClientes(&cliente));
}

void lp(){
	system("clear || cls");
}

int preencheClientes(Conta *cliente){
	int i, quant=0;

	lp();

	for(i=0; i<TAM; i++){
		printf("Informe o nome:");
		scanf("%[^\n]s", cliente->nome);
		getchar();

		printf("Informe o número da conta:");
		scanf("%d", &cliente->numeroConta);
		getchar();

		printf("Informe o saldo:");
		scanf("%f", &cliente->saldo);
		getchar();

		quant+=saldoAcima1000(&cliente->saldo);

		lp();
	}

	return quant;
}

int saldoAcima1000(const float *saldo){
	if((*saldo)>1000){
		return 1;
	}
	else{
		return 0;
	}
}
