#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define TAM 10

void limpaTela();
void geraArquivos(FILE *arqA, FILE *arqB);
void leArquivos(FILE *arqA, FILE *arqB, int *A, int *B);
void geraC(int *A, int *B, int *C);
void imprimeC(int *C, FILE *arqC);

int main(){
	limpaTela();
	int A[TAM], B[TAM], C[TAM*2];
	srand((unsigned)time(NULL));
	FILE *arqA=fopen("A.txt", "w");
	FILE *arqB=fopen("B.txt", "w");
	FILE *arqC=fopen("C.txt", "w");
	geraArquivos(arqA, arqB);
	fclose(arqA);
	fclose(arqB);
	arqA=fopen("A.txt", "r");
	arqB=fopen("B.txt", "r");
	leArquivos(arqA, arqB, A, B);
	geraC(A, B, C);
	imprimeC(C, arqC);
	fclose(arqA);
	fclose(arqB);
	fclose(arqC);
}
void limpaTela(){
	system("clear || cls");
}
void geraArquivos(FILE *arqA, FILE *arqB){
	int i;
	for(i=0; i<TAM; i++){
		fprintf(arqA, "%d ", rand()%50+1);
		fprintf(arqB, "%d ", rand()%50+1);
	}
}
void leArquivos(FILE *arqA, FILE *arqB, int *A, int *B){
	int i;
	for(i=0; i<TAM; i++){
		fscanf(arqA, "%d ", &A[i]);
		fscanf(arqB, "%d ", &B[i]);
	}
}
void geraC(int *A, int *B, int *C){
	int i, k, posA=0, posB=0, maiorA=A[0], maiorB=B[0];
	for(i=0; i<(TAM*2); i++){
		for(k=0; k<TAM; k++){
			if(A[k]>maiorA){
				maiorA=A[k];
				posA=k;
			}
			if(B[k]>maiorB){
				maiorB=B[k];
				posB=k;
			}
		}
		if(maiorA>maiorB){
			C[i]=maiorA;
			A[posA]=0;
		}
		else if(maiorB>maiorA){
			C[i]=maiorB;
			B[posB]=0;
		}
		else{
			C[i]=maiorA;
			A[posA]=0;
		}
		maiorA=A[0];
		maiorB=B[0];
		posA=0;
		posB=0;
	}
}
void imprimeC(int *C, FILE *arqC){
	int i;
	printf("Vetor C\n");
	for(i=0; i<(TAM*2); i++){
		printf("%d ", C[i]);
	}
}
