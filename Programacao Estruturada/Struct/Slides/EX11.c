#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 20

void preencheVet(int *vet);
void imprimeVetNaoOrdenado(int *vet);
void insertionSort(int *vet);
void imprimeVetOrdenado(int *vet);

int main(){
	system("clear || cls");
	int *vet=calloc(TAM, sizeof(vet));;
	preencheVet(vet);
	imprimeVetNaoOrdenado(vet);
	insertionSort(vet);
	imprimeVetOrdenado(vet);
}
void preencheVet(int *vet){
	int i;
	for(i=0; i<TAM; i++){
		vet[i]=rand()%30+1;
	}	
}

void imprimeVetNaoOrdenado(int *vet){
	int i;

	printf("Vetor nao ordenado:\n");

	for(i=0; i<TAM; i++){
		printf("%d ", vet[i]);
	}
	printf("\n");
}

void insertionSort(int *vet){
	int i, j, aux;
	for(i=0; i<(TAM-1); i++){
		for(j=(i+1); j>0; j--){
			if(vet[j]>vet[j-1]){
				aux=vet[j];
				vet[j]=vet[j-1];
				vet[j-1]=aux;
			}
		}
	}
}
void imprimeVetOrdenado(int *vet){
	int i;
	printf("\nVetor ordenado:\n");
	for(i=0; i<TAM; i++){
		printf("%d ", vet[i]);
	}
}