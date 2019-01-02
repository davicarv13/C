#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

void ordenaVet(int *vet);
void imprimeVet(int *vet);

int main(){
	system("clear || cls");
	int vet[TAM], cont, cont2;
	FILE *arqNumeros=fopen("Numeros.txt", "w");
	srand((unsigned)time(NULL));
	for(cont=0; cont<TAM; cont++){
		fprintf(arqNumeros, "%d\n", rand()%31);
	}
	fclose(arqNumeros);
	arqNumeros=fopen("Numeros.txt", "r");
	for(cont=0; cont<TAM; cont++){
		fscanf(arqNumeros, "%d\n", &vet[cont]);
	}
	ordenaVet(vet);
	imprimeVet(vet);
}
void ordenaVet(int *vet){
	int cont, cont2, aux;
	for(cont=0; cont<TAM; cont++){
		for(cont2=0; cont2<(TAM-1); cont2++){
			if(vet[cont2]>vet[cont2+1]){
				aux=vet[cont2];
				vet[cont2]=vet[cont2+1];
				vet[cont2+1]=aux;
			}
		}
	}
}
void imprimeVet(int *vet){
	int cont;
	system("clear || cls");
	printf("Vetor ordenado:\n");
	for(cont=0; cont<TAM; cont++){
		printf("%d\n", vet[cont]);
	}
}
