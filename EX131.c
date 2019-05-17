#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheVet(int *vet, int n);
void imprimeVet(int *vetor, int n);
int** inverte2 (int n, int* vet);

int main(){

	srand((unsigned)time(NULL));

	int n=10;
	int i;
	int vet[n];

	preencheVet(vet, n);
	int** w = inverte2(n, vet);

	printf("\nVetor de Numeros:\n");
	imprimeVet(vet, n);

	printf("\nVetor de enderecos: \n");

	for(i=0; i<n; i++){
		printf("%p \n", w[i]);
	}

	printf("\nValores do vetor de enderecos:\n");

	for(i=0; i<n; i++){
		
	}
}

int** inverte2 (int n, int* vet){
	int** w = malloc(n * sizeof(w));
	int vetAux[n];
	int maior;
	int i, j;
	int posMaior;
	int* endMaior;

	for(i=0; i<n; i++){
		vetAux[i] = vet[i];
	}

	for (int i = n-1 ; i >= 0; i--){
		maior = vet[i];
		for(j = 0; j < n; j++){
			if(vet[i] > maior){
				maior = vet[j];
				posMaior = j;
				endMaior = &vet[j];
 			}
		}
		w[i] = endMaior;
		vet[j] = 0; 
	}

	for(i = 0; i < n; i++){
		vet[i] = vetAux[i]; 
	}

	return w;
}

void imprimeVet(int *vetor, int n){

	for(int i = 0; i < n; i++){
		printf("%d ", vetor[i]);
	}

	putchar('\n');
}

void preencheVet(int *vet, int n){
	
	for(int i = 0; i < n; i++){
		vet[i]=rand()%20+1;	
	}
} 