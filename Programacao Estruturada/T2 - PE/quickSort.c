// PE-T2-Pedro-Davi

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMA 5000
#define TAMB 10000
#define TAMC 20000
#define TAMD 30000

void lerVetor(int vetor[], FILE *arqVetor, int tamanho);
void calcularTempoDeOrdenacao(int vetor[], int tamanho, char nome[]);
void ordenarVetor(int vet[], int esq, int dir);
void imprimirVetor(int vetor[], FILE *arqVetor, int tamanho);

int main(){
	
	system("clear || cls");

	int vetorA[TAMA];
	int vetorB[TAMB];
	int vetorC[TAMC];
	int vetorD[TAMD];

	FILE *arqVetorA, *arqVetorB, *arqVetorC, *arqVetorD, *arqOrdenadoA, *arqOrdenadoB, *arqOrdenadoC, *arqOrdenadoD;

	arqVetorA = fopen("A.txt", "r");
	arqVetorB = fopen("B.txt", "r");
	arqVetorC = fopen("C.txt", "r");
	arqVetorD = fopen("D.txt", "r");

	arqOrdenadoA = fopen("Ordenado-A.txt", "w");
	arqOrdenadoB = fopen("Ordenado-B.txt", "w");
	arqOrdenadoC = fopen("Ordenado-C.txt", "w");
	arqOrdenadoD = fopen("Ordenado-D.txt", "w");
    
    // Vetor A
	lerVetor(vetorA, arqVetorA, TAMA);
	calcularTempoDeOrdenacao(vetorA, TAMA, "A");
	imprimirVetor(vetorA, arqOrdenadoA, TAMA);
    // Vetor B
	lerVetor(vetorB, arqVetorB, TAMB);
	calcularTempoDeOrdenacao(vetorB, TAMB, "B");
	imprimirVetor(vetorB, arqOrdenadoB, TAMB);
    // Vetor C
	lerVetor(vetorC, arqVetorC, TAMC);
	calcularTempoDeOrdenacao(vetorC, TAMC, "C");
	imprimirVetor(vetorC, arqOrdenadoC, TAMC);
    // Vetor D
	lerVetor(vetorD, arqVetorD, TAMD);
	calcularTempoDeOrdenacao(vetorD, TAMD, "D");
	imprimirVetor(vetorD, arqOrdenadoD, TAMD);
	
    fclose(arqVetorA);
    fclose(arqVetorB);
	fclose(arqVetorC);
    fclose(arqVetorD);
    fclose(arqOrdenadoA);
    fclose(arqOrdenadoB);
    fclose(arqOrdenadoC);
    fclose(arqOrdenadoD);
}

void lerVetor(int vetor[], FILE *arqVetor, int tamanho){
	int i;

	for(i=0; i<tamanho; i++){
		fscanf(arqVetor, "%d ", &vetor[i]);
	}
}

void calcularTempoDeOrdenacao(int vetor[], int tamanho, char nome[]){
	
	clock_t tempoInicial;
	clock_t tempoFinal;
	float tempoDecorrido;

	tempoInicial = clock();
	ordenarVetor(vetor, 0, tamanho -1);
	tempoFinal = clock();

	tempoDecorrido = (tempoFinal-tempoInicial)/(double)(CLOCKS_PER_SEC);

	printf("Tempo de Ordenação QuickSort - Vetor %s: %f segundos\n", nome, tempoDecorrido);

}

void ordenarVetor(int vet[], int esq, int dir) {
    int i, j, x, y;
     
    i = esq;
    j = dir;
    x = vet[(esq + dir) / 2];
     
    while(i <= j) {
        //para fazer crescente, troque o sinal de vet[i] < x
        while(vet[i] > x && i < dir) {
            i++;
        }
        //para fazer crescente, troque o sinal de x<vet[j]
        while(x > vet[j] && j > esq) {
            j--;
        }
        if(i <= j) {
            y = vet[i];
            vet[i] = vet[j];
            vet[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > esq) {
        ordenarVetor(vet, esq, j);
    }
    if(i < dir) {
        ordenarVetor(vet, i, dir);
    }
}

void imprimirVetor(int vetor[], FILE *arqVetor, int tamanho){
	int i;
	for(i = 0; i < tamanho; i++){
		fprintf(arqVetor, "%d ", vetor[i]);
	}
}