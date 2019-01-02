#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NOTAS 2

void limpaTela();

int main(){
	limpaTela();
	int **matriz, soma, linhas=0, i, j;
	char resp;

	matriz=(int **)calloc(1, sizeof(int));
	matriz[0]=(int *)calloc(NOTAS, sizeof(int));

	do{
		for(j=0; j<NOTAS; j++){
			printf("Nota %d:", j+1);
			scanf("%d", &matriz[linhas][j]);	
		}
		linhas++;
		printf("Quer continuar? [S/N]");
		scanf(" %c", &resp);
		getchar();
		resp=toupper(resp);
		if(resp=='S'){
			matriz=(int **)realloc(matriz, linhas+1 * sizeof(int));
			matriz[linhas]=(int *)calloc(NOTAS, sizeof(int));
		}
		
	}while(resp!='N');

	printf("Medias:\n");
	for(i=0; i<linhas; i++){
		printf("Aluno %d:", i+1);
		soma=0;
		for(j=0; j<NOTAS; j++){
			soma+=matriz[i][j];
		}
		printf("%.2f", soma/2.0);
		printf("\n");
	}

	for(i=0; i<linhas; i++){
		free(matriz[i]);
	}
	free(matriz);
}

void limpaTela(){
	system("clear || cls");
}
