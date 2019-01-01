#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINHA 8
#define COLUNA 8

void preencheMatriz(int A[][COLUNA]);
void imprimeMatriz(int A[][COLUNA]);
int verificaMatrizTriangular(int A[][COLUNA]);
int main(){
    int A[LINHA][COLUNA];
    srand((unsigned)time(NULL));
    preencheMatriz(A);
    imprimeMatriz(A);
    if(verificaMatrizTriangular(A)==0){
        printf("Matriz A nao e triangular inferior");
    }
    else{
        printf("Matriz A e triangular inferior");
    }
}
void preencheMatriz(int A[][COLUNA]){
    int cont, cont2;
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            A[cont][cont2]=rand()%15;
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
int verificaMatrizTriangular(int A[][COLUNA]){
    int cont, cont2;
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            if(cont2>cont && A[cont][cont2]!=0){
                return 0;
            }
        }
    }
    return 1;
}


