#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ORDEM 4

void geraTransposta(FILE *arqTransposta, FILE *arqMatriz, int matriz[][ORDEM]);

int main(){
	system("clear || cls");
	int cont, cont2, matriz[ORDEM][ORDEM];
	FILE *arqMatriz=fopen("Matriz4x4.txt", "w");
	FILE *arqTransposta=fopen("Tranposta.txt", "w");
	srand((unsigned)time(NULL));
	for(cont=0; cont<ORDEM; cont++){
		for(cont2=0; cont2<ORDEM; cont2++){
			fprintf(arqMatriz, "%d ", rand()%11);
		}
		fprintf(arqMatriz, "\n");
	} 	
	fclose(arqMatriz);
	arqMatriz=fopen("Matriz4x4.txt", "r");
	geraTransposta(arqTransposta, arqMatriz, matriz);
	fclose(arqMatriz);
	fclose(arqTransposta);
}
void geraTransposta(FILE *arqTransposta, FILE *arqMatriz, int matriz[][ORDEM]){
	int cont, cont2;
	for(cont=0; cont<ORDEM; cont++){
		for(cont2=0; cont2<ORDEM; cont2++){
			fscanf(arqMatriz, "%d", &matriz[cont][cont2]);
		}
		fscanf(arqMatriz, "\n");
	}
	for(cont=0; cont<ORDEM; cont++){
		for(cont2=0; cont2<ORDEM; cont2++){
			fprintf(arqTransposta, "%d ", matriz[cont2][cont]);
		}
		fprintf(arqTransposta, "\n");
	}
}