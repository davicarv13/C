#include <stdio.h>
#include <stdlib.h>

#define N 3

void decomposicao(float A[N][N], float L[N][N], float U[N][N]);
void triangularInferior(float L[N][N], float y[], float b[]);
void triangularSuperior(float U[N][N], float x[], float y[]);

int main(){
	float A[N][N] = {{3,2,4},{1,1,2},{4,3,-2}},
	b[N] = {1,2,3},
	x[N], y[N],
	L[N][N], U[N][N];
	
	int i;
	
	decomposicao(A, L, U);
	
	triangularInferior(L, y, b);
	triangularSuperior(U, x, y);
	
	printf("Matriz X (Solucao):\n");
	for(i = 0; i < N; i++){
		printf("%.2f ", x[i]);
	}
}

void decomposicao(float A[N][N], float L[N][N], float U[N][N]){
	int p, j, i, k;
	float soma;
	
	/*for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){				
			if(i > j){
				U[i][j] = 0;
			}
			else if(i < j){
				L[i][j] = 0;
			}
		}
	}
	*/
	
	for(p = 0; p < N; p++){
		L[p][p] = 1;
		for(j = p; j < N; j++){
			soma = 0;
			for(k = 0; k <= p-1; k++){
				soma += L[p][k]*U[k][j];
			} 
			U[p][j] = A[p][j] - soma;
		}
		for(i = p+1; i < N; i++){
			soma = 0;
			for(k = 0; k <= p-1; k++){
				soma += L[i][k]*U[k][p];
			} 
			L[i][p] = (1/U[p][p])*(A[i][p] - soma);
		}
	}
	
	
	printf("Matriz U:\n");
	
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%.2f ", U[i][j]);
		}
		printf("\n");
	}
	
	printf("Matriz L:\n");
	
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%.2f ", L[i][j]);
		}
		printf("\n");
	}
}

void triangularInferior(float L[N][N], float y[], float b[]){
	int i, j;
	float soma;
	
	for(i = 0; i < N; i++){
		soma = 0;
		for(j = 0; j < i; j++){
			soma += L[i][j] * y[j];
		} 
		y[i] = (b[i] - soma) / L[i][i];
	} 
	
	printf("Vetor y\n");
	for(i = 0; i < N; i++){
		printf("%.2f ", y[i]);
	}
	printf("\n");
}

void triangularSuperior(float U[N][N], float x[], float y[]){
	int i, j;
	float soma;
	
	for(i = N-1; i >= 0; i--){
		soma = 0;
		for(j = i+1; j <= N-1; j++){
			soma += U[i][j] * x[j];
		}
		x[i] = (y[i] - soma) / U[i][i];
	} 
}
