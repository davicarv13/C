#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 3

void geraMatriz(int M[N][N]);
void geraVetB(int* B);
void calculaSolucao(int M[N][N], int *B, float *X);
void imprimeVetB(int *B);
void imprimeMatriz(int M[N][N]);
void imprimeSolucao(float *X);

int main(){
	srand((unsigned)time(NULL));
	
	int M[N][N], B[N];
	float X[N];
	geraMatriz(M);
	geraVetB(B);
	calculaSolucao(M, B, X);
	printf("\nMatriz: \n");
	imprimeMatriz(M);
	printf("\nVetor B: \n");
	imprimeVetB(B);
	printf("\nSolucao: \n");
	imprimeSolucao(X);
}

void geraMatriz(int M[N][N]){
	int i, j;
	
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			if(i > j){
				M[i][j] = 0;
			}
			else{
				M[i][j] = rand()%10+1;
			}
		}
	}
}
void geraVetB(int* B){
	int i;
	
	for(i = 0; i < N; i++){
		B[i] = rand()%10+1;		
	}
}

void calculaSolucao(int M[N][N], int *B, float *X){
	int i, j;
	
	float soma;
	
	for(i = N-1; i >= 0; i--){
		soma = 0;
		for(j = i+1; j <= N; j++){
			soma += M[i][j] * X[j];
		}
		
		X[i] = (B[i] - soma) / M[i][i];
	}
}

void imprimeVetB(int *B){
	int i;
	
	for(i = 0; i < N; i++){
		printf("%2d ", B[i]);		
	}
}
void imprimeMatriz(int M[N][N]){
	int i, j;
	
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%2d ", M[i][j]);
		}
		printf("\n");
	}
}

void imprimeSolucao(float *X){
	int i;
	
	for(i = 0; i < N; i++){
		printf("%2.2f ", X[i]);		
	}
}
