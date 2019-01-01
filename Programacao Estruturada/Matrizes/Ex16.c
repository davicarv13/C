#include <stdio.h>
#define ORDEM 4

void preencheMatriz(float A[][ORDEM]);
void imprimeMatriz(float A[][ORDEM]);
float somaDiagonalSecun(float A[][ORDEM]);
int main(){
    float A[ORDEM][ORDEM];
    preencheMatriz(A);
    imprimeMatriz(A);
    printf("Soma dos elementos da diagonal secundaria de A:%.2f", somaDiagonalSecun(A));
}
void preencheMatriz(float A[][ORDEM]){
    int cont, cont2;
    printf("Informe valores para a matriz A:\n");
    for(cont=0; cont<ORDEM; cont++){
        for(cont2=0; cont2<ORDEM; cont2++){
            scanf("%f", &A[cont][cont2]);
        }
    }
}
void imprimeMatriz(float A[][ORDEM]){
    int cont, cont2;
    printf("Matriz A:\n");
    for(cont=0; cont<ORDEM; cont++){
        for(cont2=0; cont2<ORDEM; cont2++){
            printf(" %2.1f ", A[cont][cont2]);
        }
        printf("\n");
    }
}
float somaDiagonalSecun(float A[][ORDEM]){
    int cont, cont2, posicao=ORDEM-1;
    float aux=0;
    for(cont=0; cont<ORDEM; cont++){
        for(cont2=0; cont2<ORDEM; cont2++){
            if(cont2==posicao){
                aux+=A[cont][cont2];
            }
        }
        posicao--;
    }
    return aux;
}




