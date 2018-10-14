#include <stdio.h>
#include <stdlib.h>
#define TAM 15
void preencheVet(int *vet);
void imprimiParesVet(int *vet);

int main(){
	int vet[TAM];
	preencheVet(vet);
	imprimiParesVet(vet);
}

void preencheVet(int *vet){
	system("clear || cls");
	printf("\nInforme %d valores para o vetor:\n", TAM);
	for(int cont=0; cont<TAM; cont++){
		scanf("%d", &vet[cont]);
		
	}
}

void imprimiParesVet(int *vet){
	system("clear || cls");
	printf("\nValores do vetor\n");
	for(int cont=0; cont<TAM; cont=cont+2){
		printf(" %d ", vet[cont]);
	}
}
