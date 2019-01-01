#include <stdio.h>
#define ORDEM 3

void preencheMatriz(int A[][ORDEM]);
void imprimeMatriz(int A[][ORDEM]);
void somaColunas(int A[][ORDEM], int *Vet);
int main(){
    int A[ORDEM][ORDEM], Vet[ORDEM]={0};
    preencheMatriz(A);
    imprimeMatriz(A);
    somaColunas(A, Vet);
}
void preencheMatriz(int A[][ORDEM]){
    int cont, cont2;
    printf("Informe valores para a matriz A:\n");
    for(cont=0; cont<ORDEM; cont++){
        for(cont2=0; cont2<ORDEM; cont2++){
            scanf("%d", &A[cont][cont2]);
        }
    }
}
void imprimeMatriz(int A[][ORDEM]){
    int cont, cont2;
    printf("Matriz A:\n");
    for(cont=0; cont<ORDEM; cont++){
        for(cont2=0; cont2<ORDEM; cont2++){
            printf(" %2d ", A[cont][cont2]);
        }
        printf("\n");
    }
}
void somaColunas(int A[][ORDEM], int *Vet){
    int cont, cont2, aux=0;
    for(cont=0; cont<ORDEM; cont++){
        for(cont2=0; cont2<ORDEM; cont2++){
            aux+=A[cont2][cont];
        }
        Vet[cont]=aux;
        aux=0;
    }
    printf("Vetor com a soma das colunas da matriz A:");
    for(cont=0; cont<ORDEM; cont++){
        printf(" %d ", Vet[cont]);
    }
}




