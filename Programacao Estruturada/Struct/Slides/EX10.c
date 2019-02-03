#include <stdio.h>
#include <stdlib.h>

#define TAM 15

void preencheVet(int *vet);
void insertionSort(int *vet);
void imprimeVetOrdenado(int *vet);

int main(){
	system("clear || cls");
	int *vet=calloc(TAM, sizeof(vet));;
	preencheVet(vet);
	insertionSort(vet);
	imprimeVetOrdenado(vet);
}
void preencheVet(int *vet){
	int i;
	printf("Informe valores para o vetor:");
	for(i=0; i<TAM; i++){
		scanf("%d", &vet[i]);
		getchar();
	}	
}
void insertionSort(int *vet){
	int i, j, aux;
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