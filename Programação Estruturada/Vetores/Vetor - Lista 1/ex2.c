#include <stdio.h>
#include <stdlib.h>
#define TAM 15
void preencheVet(int *vet);
void inverteVet(int *vet);
void imprimeVet(int *vet);
int main(){
	int vet[TAM];
	preencheVet(vet);
	inverteVet(vet);
	imprimeVet(vet);
}

void preencheVet(int *vet){
	system("clear || cls");
	printf("\nInforme %d valores para o vetor:\n", TAM);
	for(int cont=0; cont<TAM; cont++){
		scanf("%d", &vet[cont]);
	}
}

void inverteVet(int *vet){
	system("clear || cls");
	int tam=TAM-1, aux;
	//printf("\n%d\n", tam/2);
	for(int cont=0; cont<(TAM/2); cont++){
		aux=vet[cont];
		printf("\n%d\n", aux);
		printf("\n%d\n", vet[tam]);
		vet[cont]=vet[tam];
		vet[tam]=aux; 
		tam--;
	}
}

void imprimeVet(int *vet){
	printf("\nValores do vetor:\n");
	for(int cont=0; cont<TAM; cont++){
		printf(" %d ", vet[cont]);
	}
}
