#include <stdio.h>
#include <stdlib.h>

int pegaNotas(int *notas);
void imprimeNotas(int *notas, int n);
void calculaMedia(int *notas, int n);

int main(){
	system("clear || cls");
	int *notas, n;
	notas=(int *)malloc(sizeof(int));

	n=pegaNotas(notas);

	for(int j=0; j<n; j++){
		printf("%d ", notas[j]);
	}

	imprimeNotas(notas, n);
	calculaMedia(notas, n);

	free(notas);
	notas=NULL;
	printf("\n\n");
}

int pegaNotas(int *notas){
	int n=1, teste=1, nota;

	printf("Informe notas: (-1 Para Sair):\n");
	do{
		scanf(" %d", &nota);
		if(nota>0){
			notas[n-1]=nota;
			notas=(int *)realloc(notas, (n+1)*sizeof(int));
			n++;
		}
		else{
			break;
		}
	}while(teste==1);

	return --n;
}

void imprimeNotas(int *notas, int n){
	int i;
	printf("Notas:\n");
	for(i=0; i<n; i++){
		printf("%d ", notas[i]);
	}
	printf("\n");
}

void calculaMedia(int *notas, int n){
	int i, soma=0;

	for(i=0; i<n; i++){
		soma+=notas[i];
	}
	printf("Media: %d", soma/n);
}
