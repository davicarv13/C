#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheVet(int *v, int n);
int* somatorios (int n, int* v);
void imprimeVet(int *vet, int n);

int main(){

	srand((unsigned)time(NULL));

	int n=10;
	int v[n];
	

	preencheVet(v, n);
	int* w = somatorios(n, v);

	printf("Vetor v:\n");
	imprimeVet(v, n);

	printf("Vetor w:\n");
	imprimeVet(w, n);
}

void preencheVet(int *v, int n){
	
	for(int i = 0; i < n; i++){
		v[i]=rand()%20;	
	}
} 

int* somatorios (int n, int* v){
	
	int* w = malloc(n * sizeof(w));

	for(int i = 0; i < n; i++){
		if(i == 0){
			w[i] = v[i];
		}
		else{
			w[i] = v[i] + w[i-1]; 
		}
	}

	return w;
}

void imprimeVet(int *vet, int n){

	for(int i = 0; i < n; i++){
		printf("%d ", vet[i]);
	}

	putchar('\n');
}