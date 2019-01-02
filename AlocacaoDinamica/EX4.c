#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHA 2
#define COLUNA 4

int main(){
	system("clear || cls");
	int **matriz, i, j;
	srand((unsigned)time(NULL));
	matriz=(int **)calloc(LINHA, sizeof(int));

	for(i=0; i<LINHA; i++){
		matriz[i]=(int *)calloc(COLUNA, sizeof(int));
	}

	for(i=0; i<LINHA; i++){
		for(j=0; j<COLUNA; j++){
			matriz[i][j]=rand()%50+1;
		}
	}

	for(i=0; i<LINHA; i++){
		for(j=0; j<COLUNA; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}	
	
	for(i=0; i<LINHA; i++){
		free(matriz[i]);
	}
	free(matriz);

	
}
