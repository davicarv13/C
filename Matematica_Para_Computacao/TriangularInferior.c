#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 3

void geraMatriz(int L[TAM][TAM]);
void imprimeMatriz(int L[TAM][TAM]);
void geraVetorB(int *B);
void imprimeVetorB(int *B);
void calculaSolucao(int L[TAM][TAM], int *B, float *X);
void imprimeSolucao(float *X);

int main(){
	srand((unsigned)time(NULL));

	int L[TAM][TAM], B[TAM];
	float X[TAM];

	geraMatriz(L);
	imprimeMatriz(L);
	geraVetorB(B);
	imprimeVetorB(B);
	calculaSolucao(L, B, X);
	imprimeSolucao(X);
}

void geraMatriz(int L[TAM][TAM]){
	int i, j;

	for(i = 0; i < TAM; i++){
		for(j = i+1; j < TAM; j++){
			L[i][j] = 0;
		}
	}

	for(i = 0; i < TAM; i++){
		for(j = 0; j <= i; j++){
			L[i][j] = rand()%10+1;
		}
	}
}

void imprimeMatriz(int L[TAM][TAM]){
	int i, j;
	printf("Matriz L:\n");
	for(i = 0; i < TAM; i++){
		for(j = 0; j < TAM; j++){
			printf("%2d ", L[i][j]);
		}
		printf("\n");
	}
}

void geraVetorB(int *B){
	int i;

	for(i = 0; i < TAM; i++){
		B[i] = rand() % 10+1;
	}
}
void imprimeVetorB(int *B){
	int i;

	printf("Vetor B\n");

	for(i = 0; i < TAM; i++){
		printf("%d\n", B[i]);
	}
}

void calculaSolucao(int L[TAM][TAM], int *B, float *X){
	int i, j, k;
	float soma;

	for(i = 0; i < TAM; i++){
		soma = 0;
		for(j = 0; j <= i-1; j++){
			soma += L[i][j] * X[j];
		}

		X[i] = (B[i] - soma) / L[i][i];
	}
}

void imprimeSolucao(float *X){
	int i;

	printf("Solucao:\n");

	for(i = 0; i < TAM; i++){
		printf("%.2f\n", X[i]);
	}
}
