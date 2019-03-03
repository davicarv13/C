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
void ordenarVetor(int vet[], int n);
void buildMaxHeap(int tabela[], int MAX);
void maxHeapify(int tabela[], int pos, int n);
void swap(int tabela[], int j, int aposJ);


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
	ordenarVetor(vetor, tamanho);
	tempoFinal = clock();

	tempoDecorrido = (tempoFinal-tempoInicial)/(double)(CLOCKS_PER_SEC);

	printf("Tempo de Ordenação BubbleSort - Vetor %s: %f segundos\n", nome, tempoDecorrido);

}

void ordenarVetor(int tabela[], int MAX){
    buildMaxHeap(tabela, MAX);
    int n = MAX;

    for (int i = MAX - 1; i > 0; i--)
    {
        swap(tabela, i, 0);
        maxHeapify(tabela, 0, --n);
    }
}

void buildMaxHeap(int tabela[], int MAX){
    for (int i = MAX / 2 - 1; i >= 0; i--)
        maxHeapify(tabela,i,MAX);
}

void maxHeapify(int tabela[], int pos, int n){
    int max = 2 * pos + 1, right = max + 1, comparacaoHeap;
    if (max < n)
    {
        //para ordenar crescente ative o código comentado abaixo do if
        if //((right < n) && (tabela[max] < tabela[right]))
            ((right < n) && (tabela[max] > tabela[right]))
            max = right;
            comparacaoHeap++;
        if //(tabela[max] > tabela[pos])
           (tabela[max] < tabela[pos])
        {
            swap(tabela, max, pos);
            maxHeapify(tabela, max, n);
        }
    }
}

void swap(int tabela[], int j, int aposJ){
    int trocaHeap=0;

    int aux = tabela[j];
    tabela[j] = tabela[aposJ];
    tabela[aposJ] = aux;
    trocaHeap++;
}






void imprimirVetor(int vetor[], FILE *arqVetor, int tamanho){
	int i;
	for(i = 0; i < tamanho; i++){
		fprintf(arqVetor, "%d ", vetor[i]);
	}
}