#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ORDEM 6

void preencheMatriz(float A[][ORDEM]);
void imprimeMatriz(float A[][ORDEM]);
float somaElementosForaDiagPrinSec(float A[][ORDEM]);
int main(){
    float A[ORDEM][ORDEM];
    preencheMatriz(A);
    imprimeMatriz(A);
    printf("Soma dos elementos fora da diagonal principal e secundaria da matriz A:%.2f", somaElementosForaDiagPrinSec(A));
}
void preencheMatriz(float A[][ORDEM]){
    int cont, cont2;
    for(cont=0; cont<ORDEM; cont++){
        for(cont2=0; cont2<ORDEM; cont2++){
            A[cont][cont2]=rand()%29+1;
        }
    }
}
void imprimeMatriz(float A[][ORDEM]){
    int cont, cont2;
    printf("Matriz A:\n");
    for(cont=0; cont<ORDEM; cont++){
        for(cont2=0; cont2<ORDEM; cont2++){
            printf(" %4.1f ", A[cont][cont2]);
        }
        printf("\n");
    }
}
float somaElementosForaDiagPrinSec(float A[][ORDEM]){
    int cont, cont2, posicao=ORDEM-1;
    float aux=0;
    for(cont=0; cont<ORDEM; cont++){
        for(cont2=0; cont2<ORDEM; cont2++){
            if(cont!=cont2 && cont2!=posicao){
                aux+=A[cont][cont2];
            }
        }
        posicao--;
    }
    return aux;
}





