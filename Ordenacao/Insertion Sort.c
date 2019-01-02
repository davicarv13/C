#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

void preencheVet(int *vet);
void imprimeVetNaoOrdenado(int *vet);
void selectionSort(int *vet);
void imprimeVetOrdenado(int *vet);

int main(){
	system("clear || cls");
	int vet[TAM];
	srand((unsigned)time(NULL));
	preencheVet(vet);
	imprimeVetNaoOrdenado(vet);
	selectionSort(vet);
	imprimeVetOrdenado(vet);
}
void preencheVet(int *vet){
	int i;
	for(i=0; i<TAM; i++){
		vet[i]=rand()%50;
	}	
}
void imprimeVetNaoOrdenado(int *vet){
	int i;
	printf("Vetor nao ordenado:\n");
	for(i=0; i<TAM; i++){
		printf("%d ", vet[i]);
	}
}
void selectionSort(int *vet){
	int i, j, aux, menor;
	menor=vet[0];
	for(i=0; i<(TAM-1); i++){
		for(j=(i+1); j>0; j--){
			if(vet[j]<vet[j-1]){
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