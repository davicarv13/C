#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 15

void preencheVet(int *vet);
void imprimeVetNaoOrdenado(int *vet);
void selectionSort(int *vet);
void imprimeVetOrdenado(int *vet);

int main(){
	system("clear || cls");

	srand((unsigned)time(NULL));

	int *vet=malloc(TAM*sizeof(vet));;

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

	printf("\n");
}

void selectionSort(int *vet){
	int i, j, aux, posMenor;

	for(i=0; i<n-1; i++){
		posMenor=i;
		for(j=i+1; j<n; j++){
			if(vet[j]<vet[posMenor]){
				posMenor=j;
			}
		}
		aux=vet[i];
		vet[i]=vet[posMenor];
		vet[posMenor]=aux;
	}
}
void imprimeVetOrdenado(int *vet){
	int i;
	printf("\nVetor ordenado:\n");
	for(i=0; i<TAM; i++){
		printf("%d ", vet[i]);
	}
}
