#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 40

void preencheVet(int *vet);
void imprimeVetor(int *vet);
void verificaValor(int *vet, int n);

int main(){
	int vet[TAM];
	int n;
	srand((unsigned)time(NULL));
	preencheVet(vet);
	printf("Informe um valor:");
	scanf("%d", &n);
	printf("Vetor:\n");
	imprimeVetor(vet);
	verificaValor(vet, n);
}

void preencheVet(int *vet){
	for(int cont=0; cont<TAM; cont++){
		vet[cont]=rand()%100+1;
	}
}

void imprimeVetor(int *vet){
	for(int cont=0; cont<TAM; cont++){
		printf(" %d ", vet[cont]);
	}
}

void verificaValor(int *vet, int n){
	int teste=0;
	printf("\nPosicoes em que %d aparece:\n", n);
	for(int cont=0; cont<TAM; cont++){
		if(vet[cont]==n){
			printf(" %d ", cont);
			teste=1;
		}
	}
	if(teste==0){
		printf("Numero nao pertence ao vetor!");
	}
}
