#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ORDEM 10

int main(){
	system("clear || cls");
	int cont, cont2, matriz[ORDEM][ORDEM];
	FILE *arqMatriz=fopen("Matriz10x10.txt", "w");
	srand((unsigned)time(NULL));
	for(cont=0; cont<ORDEM; cont++){
		for(cont2=0; cont2<ORDEM; cont2++){
			if(cont==cont2){
				fprintf(arqMatriz, "%2d ", rand()%50+1);	
			}
			else{
				fprintf(arqMatriz, "%2d ", rand()%40);
			}
		}
		fprintf(arqMatriz, "\n");
	} 	
}