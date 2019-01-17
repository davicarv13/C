#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheVet(float *vet, int n);
void mediaVet(float *vet, int n);

int main(){
	float *vet;
	int n=5;
	srand((unsigned)time(NULL));
	vet=calloc(n, sizeof(vet));
	
	preencheVet(vet, n);
	mediaVet(vet, n);
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

void mediaVet(float *vet, int n){
	static int i=0;
	static float soma=0;

	if(n==i){
		printf("Media dos elementos do vetor:%.2f\n", soma/n);
		exit(0);
	}
	else{
		soma+=vet[i];
	}
	
	i++;
	mediaVet(vet, n);
}