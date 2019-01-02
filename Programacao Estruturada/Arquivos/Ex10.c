#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINHA 4
#define COLUNA 5

void preencheMatriz(FILE *arqMatriz, int matriz[][COLUNA]);
void trocaLinhas(FILE *arqMatriz, int matriz[][COLUNA]);
void imprimeMatriz(FILE *arqMatrizAlterada, int matriz[][COLUNA]);

int main(){
	system("clear || cls");
	int cont, cont2, matriz[LINHA][COLUNA];
	FILE *arqMatriz=fopen("Matriz4x5.txt", "w");
	FILE *arqMatrizAlterada=fopen("MatrizAlterada.txt", "w");
	srand((unsigned)time(NULL));
	for(cont=0; cont<LINHA; cont++){
		for(cont2=0; cont2<COLUNA; cont2++){
			fprintf(arqMatriz, "%2d ", rand()%50+1);
		}
		fprintf(arqMatriz, "\n");
	} 	
	fclose(arqMatriz);
	arqMatriz=fopen("Matriz4x5.txt", "r");
	preencheMatriz(arqMatriz, matriz);
	trocaLinhas(arqMatriz, matriz);
	imprimeMatriz(arqMatrizAlterada ,matriz);
}
void preencheMatriz(FILE *arqMatriz, int matriz[][COLUNA]){
	int cont, cont2;
	for(cont=0; cont<LINHA; cont++){
		for(cont2=0; cont2<COLUNA; cont2++){
			fscanf(arqMatriz, "%d ", &matriz[cont][cont2]);
		}
	} 
}
void trocaLinhas(FILE *arqMatriz, int matriz[][COLUNA]){
	int cont, aux;
	for(cont=0; cont<COLUNA; cont++){
		aux=matriz[0][cont];
		matriz[0][cont]=matriz[3][cont];
		matriz[3][cont]=aux;
	}
}
void imprimeMatriz(FILE *arqMatrizAlterada, int matriz[][COLUNA]){
	int cont, cont2;
	for(cont=0; cont<LINHA; cont++){
		for(cont2=0; cont2<COLUNA; cont2++){
			fprintf(arqMatrizAlterada, "%2d ", matriz[cont][cont2]);
		}
		fprintf(arqMatrizAlterada, "\n");
	} 
}