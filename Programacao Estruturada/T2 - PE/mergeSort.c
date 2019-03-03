#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t calculaTempo();
clock_t calculaTempo();

void lerVetor(int *vet, FILE *arq, int n);

void ordenaVetor(int *, int *, int esq, int dir);
void sort(int *v, int *c, int i, int f);
void merge(int *v, int *c, int i, int m, int f);

void imprimeVet(int *vet, FILE *arq, int n);

int main(){
   
   system("clear || cls");

   clock_t inicio;
   clock_t fim;

   float tempo;

   int *vetA=calloc(5000, sizeof(vetA));
   int *auxVetA=calloc(5000+1, sizeof(auxVetA));
   int *vetB=calloc(10000, sizeof(vetB));
   int *auxVetB=calloc(10000+1, sizeof(auxVetB));
   int *vetC=calloc(20000, sizeof(vetC));
   int *auxVetC=calloc(20000+1, sizeof(auxVetC));
   int *vetD=calloc(30000, sizeof(vetD));
   int *auxVetD=calloc(30000+1, sizeof(auxVetD));

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
   ordenaVetor(vetA, auxVetA, 0, 5000);
   fim=calculaTempo();

   tempo=(fim-inicio)/(double)(CLOCKS_PER_SEC);

   imprimeVet(vetA, ordenadoA, 5000);

   printf("Tempo de Ordenação Insertion Sort - A: %f segundos\n\n", tempo);

   lerVetor(vetB, arqB, 10000);
   inicio=calculaTempo();
   ordenaVetor(vetB, auxVetB, 0, 10000);
   fim=calculaTempo();

   tempo=(fim-inicio)/(double)(CLOCKS_PER_SEC);

   imprimeVet(vetB, ordenadoB, 10000);

   printf("Tempo de Ordenação Insertion Sort - B: %f segundos\n\n", tempo);

   lerVetor(vetC, arqC, 20000);
   inicio=calculaTempo();
   ordenaVetor(vetC, auxVetC, 0, 20000);
   fim=calculaTempo();

   tempo=(fim-inicio)/(double)(CLOCKS_PER_SEC);

   imprimeVet(vetC, ordenadoC, 20000);

   printf("Tempo de Ordenação Insertion Sort - C: %f segundos\n\n", tempo);

   lerVetor(vetD, arqD, 30000);
   inicio=calculaTempo();
   ordenaVetor(vetD, auxVetD, 0, 30000);
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
   
   free(auxVetA);
   free(auxVetB);
   free(auxVetC);
   free(auxVetD);
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

void ordenaVetor(int tabela[],int temp_tabela[],int esq, int dir)
{

    //para ordenar decrescente ative o código comentado abaixo dos if


    int meio, temp, i, j, k, t, m, comparacaoMerge=0, trocaMerge=0;
    if (dir - esq == 1)
    {
        if //(tabela[esq] > tabela[dir])
           (tabela[esq] < tabela[dir])
        {
            comparacaoMerge++;
            temp = tabela[dir];
            temp = tabela[esq];
            tabela[dir]= tabela[esq];
            tabela[esq]= tabela[dir];
            tabela[esq]=temp;
            tabela[dir]=temp;
        }
    }
    else
        if (esq != dir)
        {
            comparacaoMerge++;
            meio = (esq+dir)/2;
            ordenaVetor(tabela,temp_tabela, esq, meio-1);
            ordenaVetor(tabela,temp_tabela, meio, dir);

            i = esq;
            j = meio;
            k = -1;
            while ((i <= meio-1) && (j <= dir))
            {
                  comparacaoMerge++;

                k = k+1;
                if //(tabela[i] <= tabela[j])
                   (tabela[i] >= tabela[j])
                {
                    trocaMerge++;
                    temp_tabela[k] = tabela[i];
                    i++;
                }
                else
                {
                    trocaMerge++;
                    temp_tabela[k] = tabela[j];
                    j++;
                }
            }
            if (j > dir )
            {
                trocaMerge++;
                for (t=0; t<meio-i; t++)
                    tabela[dir-t] = tabela[meio-1-t];
            }
                   
            for (t=0; t<=k; t++)
                tabela[esq+t] = temp_tabela[t];
        }
}
void imprimeVet(int *vet, FILE *arq, int n){
   int i;

   for(i=0; i<n; i++){
      fprintf(arq, "%d ", vet[i]);
   }
}