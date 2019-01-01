#include <stdio.h>
#include <stdlib.h>
#define TAM 10
void preencheVet(int *vet);
void imprimiInversoVet(int *vet);

int main(){
	int vet[TAM];
	preencheVet(vet);
	imprimiInversoVet(vet);
}

void preencheVet(int *vet){
	system("clear || cls");
	printf("\nInforme %d valores para o vetor:\n", TAM);
	for(int cont=0; cont<TAM; cont++){
		scanf("%d", &vet[cont]);
		
	}
}

void imprimiInversoVet(int *vet){
	system("clear || cls");
	printf("\nValores do vetor\n");
	for(int cont=TAM-1; cont>=0; cont--){
		printf(" %d ", vet[cont]);
	}
}
