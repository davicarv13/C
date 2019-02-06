#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheVet(int *vet, int n);
int  maiorElemento(int *vet, int n, int maior);

int main(){
	int *vet;
	int n=20;
	srand((unsigned)time(NULL));
	vet=calloc(n, sizeof(vet));
	
	preencheVet(vet, n);
	printf("\nSoma dos elementos do vetor: %d", maiorElemento(vet, n, vet[0]));
	free(vet);
	vet=NULL;
}

void preencheVet(int *vet, int n){
	int i;
	for(i=0; i<n; i++){
		vet[i]=rand()%40+1;
	}
	printf("Vetor:\n");
	for(i=0; i<n; i++){
		printf("%d ", vet[i]);
	}
	printf("\n");
}

int maiorElemento(int *vet, int n, int maior){
	
	static int i=1;

	if(n==i){
		return maior;
	}

	if(vet[i]>maior){
		maior=vet[i];
	}
	
	i++;
	maiorElemento(vet, n, maior);

	
}
