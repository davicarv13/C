#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheV(int* v, int n);
int* somatorios (int n, int* v);
void imprimeVetores(int *v, int *w, int n);

int main(){
	int *w, n;
	srand((unsigned)time(NULL));
	printf("Informe a quantidade de elementos do vetor:");
	scanf(" %d", &n);
	while(n<=0){
		printf("Valor invalido!\n");
		printf("Informe a quantidade de elementos do vetor (Valores Positivos):");
		scanf(" %d", &n);
	}
	int *v=(int *)calloc(n, sizeof(int));
	preencheV(v, n);
	
	w=somatorios(n, v);
	
	imprimeVetores(v, w, n);

	free(v);
	v=NULL;
	free(w);
	w=NULL;
}

void preencheV(int *v, int n){
	int i; 
	for(i=0; i<n; i++){
		v[i]=rand()%30+1;
	}
}

int* somatorios(int n, int* v){
	int i, *w;

	w=(int*)calloc(n, sizeof(int));

	for(i=0; i<n; i++){
		if(i==0){
			w[i]=v[i];
		}
		else{
			w[i]=v[i]+w[i-1];
		}
	}

	return w;

	free(w);
	w=NULL;
}

void imprimeVetores(int *v, int *w, int n){
	int i;
	printf("Vetor v:\n");
	for(i=0; i<n; i++){
		printf("%d ", v[i]);
	}
	printf("\nVetor w:\n");
	for(i=0; i<n; i++){
		printf("%d ", w[i]);
	}
}
