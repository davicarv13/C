#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINHA 6
#define COLUNA 6

void preencheMatriz(int A[][COLUNA]);
void imprimeMatriz(int A[][COLUNA]);
int MultElementosAbaixoDiagonalP(int A[][COLUNA]);
int main(){
    int A[LINHA][COLUNA];
    srand((unsigned)time(NULL));
    preencheMatriz(A);
    imprimeMatriz(A);
    printf("Multiplicacao dos elementos abaixo da diagonal principal:%d", somaElementosAbaixoDiagonalP(A));
}
void preencheMatriz(int A[][COLUNA]){
    int cont, cont2;
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            A[cont][cont2]=rand()%9+1;
        }
    }
}
void imprimeMatriz(int A[][COLUNA]){
    int cont, cont2;
    printf("Matriz A:\n");
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            printf(" %2d ", A[cont][cont2]);
        }
        printf("\n");
    }
}
int somaElementosAbaixoDiagonalP(int A[][COLUNA]){
    int cont, cont2, aux=1;
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            if(cont2<cont){
                aux*=A[cont][cont2];
            }
        }
    }
    return aux;
}



