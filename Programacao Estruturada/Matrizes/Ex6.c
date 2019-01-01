#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define LINHA 2
#define COLUNA 8

void preencheMatriz(int M[][COLUNA]);
void multiplicaMatriz(int M[][COLUNA], int N[][COLUNA], int k);
void imprimeMatriz(int M[][COLUNA], int N[][COLUNA], int k);
int main(){
    int M[LINHA][COLUNA], N[LINHA][COLUNA], k;
    srand((unsigned)time(NULL));
    printf("Informe um numero:");
    scanf("%d", &k);
    preencheMatriz(M);
    multiplicaMatriz(M, N, k);
    imprimeMatriz(M, N, k);
}
void preencheMatriz(int M[][COLUNA]){
    int cont, cont2;
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            M[cont][cont2]=rand()%30;
        }
    }
}
void multiplicaMatriz(int M[][COLUNA], int  N[][COLUNA], int k){
    int cont, cont2;
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            N[cont][cont2]=k*M[cont][cont2];
        }
    }
}
void imprimeMatriz(int M[][COLUNA], int N[][COLUNA], int k){
    int cont, cont2;
    printf("Matriz M:\n");
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            printf(" %2d ", M[cont][cont2]);
        }
        printf("\n");
    }
    printf("Matriz N formada por %d * M:\n", k);
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            printf(" %2d ", N[cont][cont2]);
        }
        printf("\n");
    }
}
