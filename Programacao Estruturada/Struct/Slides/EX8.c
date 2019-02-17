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
	int i, j, aux, menor=vet[0], pos;
	for(i=0; i<TAM; i++){
		for(j=i; j<TAM; j++){
			if(vet[j]<menor){
				menor=vet[j];		
				pos=j;
			}
		}
		aux=vet[i];
		vet[i]=menor;
		vet[pos]=aux;
		menor=vet[i+1];
	}
}
void imprimeVetOrdenado(int *vet){
	int i;
	printf("\nVetor ordenado:\n");
	for(i=0; i<TAM; i++){
		printf("%d ", vet[i]);
	}
}
