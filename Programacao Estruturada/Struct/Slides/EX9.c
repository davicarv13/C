#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 20

void preencheVet(int *vet);
void imprimeVetNaoOrdenado(int *vet);
void selectionSort(int *vet);
void imprimeVetOrdenado(int *vet);

int main(){
	system("clear || cls");
	int *vet=malloc(TAM*sizeof(vet));
	srand((unsigned)time(NULL));
	preencheVet(vet);
	imprimeVetNaoOrdenado(vet);
	selectionSort(vet);
	imprimeVetOrdenado(vet);

	free(vet);
	vet=NULL;
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
}

void selectionSort(int *vet){
	int i, j, aux, posMaior;

	for(i=0; i<n-1; i++){
		posMaior=i;
		for(j=i+1; j<n; j++){
			if(vet[j]>vet[posMaior]){
				posMaior=j;
			}
		}
		aux=vet[i];
		vet[i]=vet[posMaior];
		vet[posMaior]=aux;
	}
}
void imprimeVetOrdenado(int *vet){
	int i;
	printf("\nVetor ordenado:\n");
	for(i=0; i<TAM; i++){
		printf("%d ", vet[i]);
	}
}
