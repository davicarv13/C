#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t calculaTempo();
clock_t calculaTempo();

void lerVetor(int *vet, FILE *arq, int n);
void ordenaVetor(int *vet, int n);
void imprimeVet(int *vet, FILE *arq, int n);

int main(){
	
	system("clear || cls");

	clock_t inicio;
	clock_t fim;

	float tempo;

	int *vetA=calloc(5000, sizeof(vetA));
	int *vetB=calloc(10000, sizeof(vetB));
	int *vetC=calloc(20000, sizeof(vetC));
	int *vetD=calloc(30000, sizeof(vetD));

	FILE *arqA=fopen("A.txt", "r");
	FILE *arqB=fopen("B.txt", "r");
	FILE *arqC=fopen("C.txt", "r");
	FILE *arqD=fopen("D.txt", "r");

	FILE *ordenadoA=fopen("Ordenado-A.txt", "w");
	FILE *ordenadoB=fopen("Ordenado-B.txt", "w");
	FILE *ordenadoC=fopen("Ordenado-C.txt", "w");
	FILE *ordenadoD=fopen("Ordenado-D.txt", "w");

	lerVetor(vetA, arqA, 5000);
	inicio=calculaTempo();
	ordenaVetor(vetA, 5000);
	fim=calculaTempo();

	tempo=(fim-inicio)/(double)(CLOCKS_PER_SEC);

	imprimeVet(vetA, ordenadoA, 5000);

	printf("Tempo de Ordenação Insertion Sort - A: %f segundos\n\n", tempo);

	lerVetor(vetB, arqB, 10000);
	inicio=calculaTempo();
	ordenaVetor(vetB, 10000);
	fim=calculaTempo();

	tempo=(fim-inicio)/(double)(CLOCKS_PER_SEC);

	imprimeVet(vetB, ordenadoB, 10000);

	printf("Tempo de Ordenação Insertion Sort - B: %f segundos\n\n", tempo);

	lerVetor(vetC, arqC, 20000);
	inicio=calculaTempo();
	ordenaVetor(vetC, 20000);
	fim=calculaTempo();

	tempo=(fim-inicio)/(double)(CLOCKS_PER_SEC);

	imprimeVet(vetC, ordenadoC, 20000);

	printf("Tempo de Ordenação Insertion Sort - C: %f segundos\n\n", tempo);

	lerVetor(vetD, arqD, 30000);
	inicio=calculaTempo();
	ordenaVetor(vetD, 30000);
	fim=calculaTempo();

	tempo=(fim-inicio)/(double)(CLOCKS_PER_SEC);

	imprimeVet(vetD, ordenadoD, 30000);

	printf("Tempo de Ordenação Insertion Sort - D: %f segundos\n\n", tempo);

	fclose(arqA);
	fclose(ordenadoA);
	fclose(arqB);
	fclose(ordenadoB);
	fclose(arqC);
	fclose(ordenadoC);
	fclose(arqD);
	fclose(ordenadoD);
}

clock_t calculaTempo(){
	return clock();
}

void lerVetor(int *vet, FILE *arq, int n){
	int i;

	for(i=0; i<n; i++){
		fscanf(arq, "%d ", &vet[i]);
	}
}

void ordenaVetor(int *vet, int n){
	int i, j, aux;

	for(i=0; i<(n-1); i++){
		for(j=(i+1); j>0; j--){
			if(vet[j]>vet[j-1]){
				aux=vet[j];
				vet[j]=vet[j-1];
				vet[j-1]=aux;
			}
		}
	}
}

void imprimeVet(int *vet, FILE *arq, int n){
	int i;

	for(i=0; i<n; i++){
		fprintf(arq, "%d ", vet[i]);
	}
}