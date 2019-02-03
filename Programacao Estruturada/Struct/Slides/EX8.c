#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void preencheVet(int *vet);
void selectionSort(int *vet);
void imprimeVetOrdenado(int *vet);

int main(){
	system("clear || cls");
	int *vet=calloc(TAM, sizeof(vet));;
	preencheVet(vet);
	selectionSort(vet);
	imprimeVetOrdenado(vet);

	free(vet);
	vet=NULL;
}
void preencheVet(int *vet){
	int i;
	printf("Informe valores para o vetor:");
	for(i=0; i<TAM; i++){
		scanf("%d", &vet[i]);
		getchar();
	}	
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