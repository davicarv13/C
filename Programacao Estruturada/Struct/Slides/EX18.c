#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheVet(int *vet, int n);
int  somaVet(int *vet, int n);

int main(){
	int *vet;
	int n=20;
	srand((unsigned)time(NULL));
	vet=calloc(n, sizeof(vet));
	
	preencheVet(vet, n);
	printf("\nSoma dos elementos do vetor: %d", somaVet(vet, n-1));
	free(vet);
	vet=NULL;
}

void preencheVet(int *vet, int n){
	int i;
	for(i=0; i<n; i++){
		vet[i]=rand()%10+1;
	}
	printf("Vetor:\n");
	for(i=0; i<n; i++){
		printf("%d ", vet[i]);
	}
	printf("\n");
}

int somaVet(int *vet, int n){
	if(n==0){
		return vet[0];
	}
	else{
		return vet[n]+somaVet(vet, n-1);
	}
}
