#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheMatrizes(int** A, int** B, int m, int n);
void geraMatrizSoma(int** A, int** B, int** C, int m, int n);
void imprimematrizes(int** A, int** B, int **C, int m, int n);

int main(){
	unsigned int m, n, i;
	int **A;
	int **B;
	int **C; 

	system("clear");

	printf("Informe a quantidade de linhas das matrizes:");
	scanf("%d", &m);
	printf("Informe a quantidade de colunas das matrizes:");
	scanf("%d", &n);

	srand((unsigned)time(NULL));

	A=(int **)calloc(m, sizeof(int));
	B=(int **)calloc(m, sizeof(int));
	C=(int **)calloc(m, sizeof(int));

	for(i=0; i<m; i++){
		A[i]=(int *)calloc(n, sizeof(int));
		B[i]=(int *)calloc(n, sizeof(int));
		C[i]=(int *)calloc(n, sizeof(int));
	}

	preencheMatrizes(A, B, m, n);
	geraMatrizSoma(A, B, C, m, n);
	imprimematrizes(A, B, C, m, n);

	for(i=0; i<m; i++){
		free(A[i]);
		free(B[i]);
		free(C[i]);
	}
	free(A);
	free(B);
	free(C);
	A=NULL;
	B=NULL;
	C=NULL;
}

void preencheMatrizes(int** A, int** B, int m, int n){
	int i, j;

	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			A[i][j]=rand()%10+1;
			B[i][j]=rand()%10+1;
		}
	}

}	

void geraMatrizSoma(int** A, int** B, int** C, int m, int n){
	int i, j;

	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			C[i][j]=A[i][j]+B[i][j];
		}
	}
}

void imprimematrizes(int** A, int** B, int **C, int m, int n){
	int i, j;

	printf("Matriz A:\n");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("%2d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

	printf("Matriz B:\n");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("%2d ", B[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

	printf("Matriz C:\n");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("%2d ", C[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
