#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINHA 10
#define COLUNA 4

void preencheMatriz(int A[][COLUNA]);
void imprimeMatriz(int A[][COLUNA]);
int MultElementosColunaX(int A[][COLUNA], int x);
int main(){
    int A[LINHA][COLUNA], x;
    printf("Informe um numero 'X' maior que 0 e menor que %d:", COLUNA);
    scanf("%d", &x);
    while(x>=COLUNA || x<0){
        system("clear || cls");
        printf("Valor invalido!\n");
        printf("Informe um numero 'X' maior que 0 e menor que %d:", COLUNA);
        scanf("%d", &x);
    }
    srand((unsigned)time(NULL));
    preencheMatriz(A);
    imprimeMatriz(A);
    printf("Multiplicacao dos elementos abaixo da diagonal principal:%d", MultElementosColunaX(A, x));
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
int MultElementosColunaX(int A[][COLUNA], int x){
    int cont, cont2, aux=0;
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            if(cont2==x){
                aux+=A[cont][cont2];
            }
        }
    }
    return aux;
}



