#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINHA 5
#define COLUNA 6

void preencheMatriz(FILE *arqMatriz, int matriz[][COLUNA]);
int somaColunas(FILE *arqMatriz, int matriz[][COLUNA]);
void imprimeSoma(FILE *arqSoma, int soma);

int main(){
	system("clear || cls");
	int cont, cont2, matriz[LINHA][COLUNA], soma=0;
	FILE *arqMatriz=fopen("Matriz5x6.txt", "w");
	FILE *arqSoma=fopen("Soma.txt", "w");
	srand((unsigned)time(NULL));
	for(cont=0; cont<LINHA; cont++){
		for(cont2=0; cont2<COLUNA; cont2++){
			fprintf(arqMatriz, "%2d ", rand()%10+1);
		}
		fprintf(arqMatriz, "\n");
	} 	
	fclose(arqMatriz);
	arqMatriz=fopen("Matriz5x6.txt", "r");
	preencheMatriz(arqMatriz, matriz);
	soma=somaColunas(arqMatriz, matriz);
	imprimeSoma(arqSoma, soma);
}
void preencheMatriz(FILE *arqMatriz, int matriz[][COLUNA]){
	int cont, cont2;
	for(cont=0; cont<LINHA; cont++){
		for(cont2=0; cont2<COLUNA; cont2++){
			fscanf(arqMatriz, "%d ", &matriz[cont][cont2]);
		}
	} 
}
int somaColunas(FILE *arqMatriz, int matriz[][COLUNA]){
	int cont, soma=0;
	for(cont=0; cont<LINHA; cont++){
		soma+=matriz[cont][1]+matriz[cont][3]+matriz[cont][5];
	}
	return soma;
}
void imprimeSoma(FILE *arqSoma, int soma){
	fprintf(arqSoma, "%s %d", "Soma da segunda, quarta e sexta colunas da matriz:", soma);
}