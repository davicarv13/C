#include <stdio.h>
#include <stdlib.h>

void limpaTela();
int * alocaVet(int n);
void imprimeVet(int *vet, int n);
void desalocaVet(int *vet);

int main(){
	limpaTela();
	int n, *vet, i;
	printf("Informe o tamanho do vetor:");
	scanf("%d", &n);
	getchar();
	
	while(n<=0){
		limpaTela();
		printf("Tamanho invalido!\n");
		printf("Informe o tamanho do vetor (Valor positivo):");
		scanf("%d", &n);
		getchar();
	}

	vet=alocaVet(n);
	printf("Informe valores para o vetor:\n");
	for(i=0; i<n; i++){
		scanf("%d", &vet[i]);
	}
	imprimeVet(vet, n);
	desalocaVet(vet);
	printf("\n\n");
}

void limpaTela(){
	system("clear || cls");
}

int * alocaVet(int n){
	int *vet;
	vet=(int *)calloc(n,sizeof(int));
	return vet;
}

void imprimeVet(int *vet, int n){
	int i;
	printf("Vetor informado:\n"); 
	for(i=0; i<n; i++){
		printf("%d ", vet[i]);
	}
}

void desalocaVet(int *vet){
	free(vet);
	vet=NULL;
}
