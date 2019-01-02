#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHA 5
#define COLUNA 4

void geraMatrizes(int A[][COLUNA], int B[][COLUNA]);
void geraTransposta(int B[][COLUNA], int BTrans[][LINHA]);
void geraC(int A[][COLUNA], int BTrans[][LINHA], int C[][LINHA]);
void imprimeMatrizes(int A[][COLUNA], int B[][COLUNA], int BTrans[][LINHA], int C[][LINHA]);
int verificaTriangularSuperior(int C[][LINHA]);

int main(){
	system("clear || cls");
	srand((unsigned)time(NULL));
	int A[LINHA][COLUNA], B[LINHA][COLUNA], BTrans[COLUNA][LINHA], C[LINHA][LINHA];
	geraMatrizes(A, B);
	geraTransposta(B, BTrans);
	geraC(A, BTrans, C);
	imprimeMatrizes(A, B, BTrans, C);
	if(verificaTriangularSuperior(C)==1){
		printf("C nao e matriz triangular superior!");
	}
	else{
		printf("C e uma matriz triangular superior!");	
	}
	printf("\n\n");
}
void geraMatrizes(int A[][COLUNA], int B[][COLUNA]){
	int i, j;
	for(i=0; i<LINHA; i++){
		for(j=0; j<COLUNA; j++){
			A[i][j]=rand()%5+1;
			B[i][j]=rand()%5+1;
		}
	}
}
void geraTransposta(int B[][COLUNA], int BTrans[][LINHA]){
	int i, j;
	for(i=0; i<LINHA; i++){
		for(j=0; j<COLUNA; j++){
			BTrans[j][i]=B[i][j];
		}
	}
}
void geraC(int A[][COLUNA], int BTrans[][LINHA], int C[][LINHA]){
	int soma, i, j, k;
	for(i=0; i<LINHA; i++){
		for(j=0; j<LINHA; j++){
			soma=0;
			for(k=0; k<COLUNA; k++){
				soma+=A[i][k]*BTrans[k][j];
			}
			C[i][j]=soma;
		}
	}
}
void imprimeMatrizes(int A[][COLUNA], int B[][COLUNA], int BTrans[][LINHA], int C[][LINHA]){
	int i, j;
	printf("Matriz A:\n");
	for(i=0; i<LINHA; i++){
		for(j=0; j<COLUNA; j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Matriz B:\n");
	for(i=0; i<LINHA; i++){
		for(j=0; j<COLUNA; j++){
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Matriz B Transposta:\n");
	for(i=0; i<COLUNA; i++){
		for(j=0; j<LINHA; j++){
			printf("%d ", BTrans[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Matriz C:\n");
	for(i=0; i<LINHA; i++){
		for(j=0; j<LINHA; j++){
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int verificaTriangularSuperior(int C[][LINHA]){
	int i, j;
	for(i=0; i<LINHA; i++){
		for(j=0; j<LINHA; j++){
			if(j>i){
				if(C[i][j]!=0){
					return 1;
				}
			}
		}
	}
	return 0;
}