#include <stdio.h>
#include <stdlib.h>

#define TAM 20

#define SAL 880

typedef struct{
	char nome[50];
	int numeroConta;
	float saldo;
}Conta;

void lp();

void preencheClientes(Conta *clientes);
int acima3Salarios(const float *saldo);

int main(){

	Conta cliente;

	int quant=0, i;

	for(i=0; i<TAM; i++){
		preencheClientes(&cliente);
		quant+=acima3Salarios(&cliente.saldo);
	}
	
	printf("Quantidade de clientes com saldo de ate três salários:%d\n", quant);
}

void lp(){
	system("clear || cls");
}

void preencheClientes(Conta *cliente){
	int i;

	lp();
	
	printf("Informe o nome:");
	scanf("%[^\n]s", cliente->nome);
	getchar();

	printf("Informe o número da conta:");
	scanf("%d", &cliente->numeroConta);
	getchar();

	printf("Informe o saldo:");
	scanf("%f", &cliente->saldo);
	getchar();

	lp();
}

int acima3Salarios(const float *saldo){

	if((*saldo)<=(3*SAL)){
		return 1;
	}
	else{
		return 0;
	}
}
