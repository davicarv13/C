#include <stdio.h>
#include <stdlib.h>
#define MAX 4
int main(){
	float vet[MAX], soma=0;
	int cont=0;
	printf("Informe valores para o vetor:");
	while(cont<MAX){
		scanf("%f", &vet[cont]);
		cont++;
	}
	cont=0;
	while(cont<MAX){
		soma=soma+vet[cont];
		cont++;
	}
	printf("Soma dos valores:%.2f", soma);
	system("pause");
}
