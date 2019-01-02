#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void preencheVet(float *vet, int n);
float inverteVet(float *vet, int esq, int dir);
void imprimeVet(float *vet, int n);

int main(){
	float *vet;
	int n=5;
	int esq=0, dir=n-1;
	srand((unsigned)time(NULL));
	vet=calloc(n, sizeof(vet));
	
	preencheVet(vet, n);
	imprimeVet(vet, n);
	inverteVet(vet, esq, dir);
	imprimeVet(vet, n);

	free(vet);
	vet=NULL;
}

void preencheVet(float *vet, int n){
	int i;
	for(i=0; i<n; i++){
		vet[i]=rand()%10+1;
	}
}

float inverteVet(float *vet, int esq, int dir){

	int aux;

	if(esq>=dir){
		return 0.0;
	}
	aux=vet[esq];
	vet[esq]=vet[dir];
	vet[dir]=aux;
	inverteVet(vet, esq+1, dir-1);
}

void imprimeVet(float *vet, int n){
	int i;
	printf("Vetor antes:\n");
	for(i=0; i<n; i++){
		printf("%.0f ", vet[i]);
	}
	printf("\n");
}
