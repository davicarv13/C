#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheVet(int *vet, int n);
void imprimeVetor(int *vet, int n);
int verificaMenor(int *vet, int n, int menor);

int main(){
	int n;
	int *vet;

	srand((unsigned)time(NULL));

	printf("Informe qual tamanho do vetor:");
	scanf("%d", &n);

	vet=calloc(n, sizeof(vet));

	preencheVet(vet, n);
	imprimeVetor(vet, n);
	printf("Menor elemento do vetor:%d", verificaMenor(vet, n, vet[0]));

	free(vet);
	vet=NULL;
}

void preencheVet(int *vet, int n){
	int i;
	for(i=0; i<n; i++){
		vet[i]=rand()%20+1;
	}
}

void imprimeVetor(int *vet, int n){
	int i;

	printf("Vetor:\n");
	for(i=0; i<n; i++){
		printf("%d ", vet[i]);
	}
	printf("\n");
}

int verificaMenor(int *vet, int n, int menor){
	static int i=0;

	if(i==n){
		return menor;
	}

	if(vet[i]<menor){
		menor=vet[i];
	}

	i++;
	verificaMenor(vet, n, menor);
}