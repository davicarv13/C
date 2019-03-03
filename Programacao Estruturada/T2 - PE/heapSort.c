#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t calculaTempo();
clock_t calculaTempo();

void lerVetor(int *vet, FILE *arq, int n);
void ordenaVetor(int *vet, int MAX);
void buildMaxHeap(int tabela[], int MAX);
void maxHeapify(int tabela[], int pos, int n);
void swap(int tabela[], int j, int aposJ);
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

void ordenaVetor(int tabela[], int MAX)
{
    buildMaxHeap(tabela, MAX);
    int n = MAX;

    for (int i = MAX - 1; i > 0; i--)
    {
        swap(tabela, i, 0);
        maxHeapify(tabela, 0, --n);
    }
}
void buildMaxHeap(int tabela[], int MAX)
{
    for (int i = MAX / 2 - 1; i >= 0; i--)
        maxHeapify(tabela,i,MAX);
}

void maxHeapify(int tabela[], int pos, int n)
{
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

void swap(int tabela[], int j, int aposJ)
{
    int trocaHeap=0;

    int aux = tabela[j];
    tabela[j] = tabela[aposJ];
    tabela[aposJ] = aux;
    trocaHeap++;
}

void imprimeVet(int *vet, FILE *arq, int n){
   int i;

   for(i=0; i<n; i++){
      fprintf(arq, "%d ", vet[i]);
   }
}