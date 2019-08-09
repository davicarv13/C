#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 3

void geraMatriz(int U[TAM][TAM]);
void imprimeMatriz(int U[TAM][TAM]);
void geraVetorB(int *B);
void imprimeVetorB(int *B);
void calculaSolucao(int U[TAM][TAM], int *B, float *X);
void imprimeSolucao(float *X);

int main(){
	srand((unsigned)time(NULL));

	int U[TAM][TAM], B[TAM];
	float X[TAM];

	geraMatriz(U);
	imprimeMatriz(U);
	geraVetorB(B);
	imprimeVetorB(B);
	calculaSolucao(U, B, X);
	imprimeSolucao(X);
}

void geraMatriz(int U[TAM][TAM]){
	int i, j;

	for(i = 0; i < TAM; i++){
		for(j = 0; j < i; j++){
			U[i][j] = 0;
		}
	}

	for(i = 0; i < TAM; i++){
		for(j = i; j < TAM; j++){
			U[i][j] = rand()%10+1;
		}
	}	
}

void imprimeMatriz(int U[TAM][TAM]){
	int i, j;
	printf("Matriz U:\n");
	for(i = 0; i < TAM; i++){
		for(j = 0; j < TAM; j++){
			printf("%2d ", U[i][j]);
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

void calculaSolucao(int U[TAM][TAM], int *B, float *X){
	int i, j, k;
	float soma;

	for(i = TAM-1; i >= 0; i--){
		soma = 0;
		for(j = i+1; j <= TAM-1; j++){
			soma += U[i][j] * X[j];
		}

		X[i] = (B[i] - soma) / U[i][i];
	}
}

void imprimeSolucao(float *X){
	int i;

	printf("Solucao:\n");

	for(i = 0; i < TAM; i++){
		printf("%.2f\n", X[i]);
	}
}
