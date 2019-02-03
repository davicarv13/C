#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void preencheVet(int *vet);
void bubbleSort(int *vet);
void imprimeVetOrdenado(int *vet);

int main(){
	system("clear || cls");
	int *vet=calloc(TAM, sizeof(vet));;
	preencheVet(vet);
	bubbleSort(vet);
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
void bubbleSort(int *vet){
	int i, j, aux;
	for(i=0; i<TAM; i++){
		for(j=0; j<TAM-1; j++){
			if(vet[j]>vet[j+1]){
				aux=vet[j];
				vet[j]=vet[j+1];
				vet[j+1]=aux;
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