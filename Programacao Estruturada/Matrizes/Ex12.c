#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define LINHA 10
#define COLUNA 10

void preencheMatriz(int A[][COLUNA]);
void imprimeMatriz(int A[][COLUNA]);
int main(){
    int A[LINHA][COLUNA];
    srand((unsigned)time(NULL));
    preencheMatriz(A);
    imprimeMatriz(A);
}
void preencheMatriz(int A[][COLUNA]){
    int cont, cont2;
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            if(cont<cont2){
                A[cont][cont2]=(2*cont)+(7*cont2)+2;
            }
            else if(cont==cont2){
                A[cont][cont2]=(3*pow(cont, 2))-1;
            }
            else{
                A[cont][cont2]=(4*pow(cont, 3))-(5*pow(cont2, 2))+1;
            }
            
        }
    }
}
void imprimeMatriz(int A[][COLUNA]){
    int cont, cont2;
    printf("Matriz A:\n");
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            printf(" %4d ", A[cont][cont2]);
        }
        printf("\n");
    }
}
