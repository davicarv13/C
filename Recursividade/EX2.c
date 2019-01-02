#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheVet(float *vet, int n);
float somaVet(float *vet, int n);

int main(){
	float *vet;
	int n=5;
	srand((unsigned)time(NULL));
	vet=calloc(n, sizeof(vet));
	
	preencheVet(vet, n);
	printf("Soma dos elementos do vetor: %.f", somaVet(vet, n-1));
	free(vet);
	vet=NULL;
}

void preencheVet(float *vet, int n){
	int i;
	for(i=0; i<n; i++){
		vet[i]=rand()%10+1;
	}
	printf("Vetor:\n");
	for(i=0; i<n; i++){
		printf("%.1f ", vet[i]);
	}
	printf("\n");
}

float somaVet(float *vet, int n){
	if(n==0){
		return vet[0];
	}
	else{
		return vet[n]+somaVet(vet, n-1);
	}
}