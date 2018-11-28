#include <stdio.h>
#include <stdlib.h>
#define TAM 5
void preencheVet(int *vet);
int procuraX(int *vet, int x);

int main(){
	int vet[TAM], x;
	preencheVet(vet);
	printf("Informe um valor 'x':");
	scanf("%d", &x);
	if(procuraX(vet, x)){
		printf("O valor %d esta contido no vetor", x);
	}
	else{
		printf("O valor %d nao esta contido no vetor", x);
	}
}

void preencheVet(int *vet){
	system("clear || cls");
	printf("\nInforme %d valores para o vetor:\n", TAM);
	for(int cont=0; cont<TAM; cont++){
		scanf("%d", &vet[cont]);
	}
}

int procuraX(int *vet, int x){
	system("clear || cls");
	int teste=0;
	for(int cont=0; cont<TAM; cont++){
		if(vet[cont]==x){
			teste++;
			break;
		}
	}
	if(teste==0){
		return false;
	}
	else{
		return true;
	}
}
