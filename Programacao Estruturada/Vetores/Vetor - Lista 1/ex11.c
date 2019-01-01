#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 50

void preencheVetA(int *A);
void preencheVetBC(int *A, int *B, int *C);
void imprimeVetBC(int *B, int *C);

int main(){
    int A[TAM], B[TAM/2], C[TAM/2];
    srand((unsigned)time(NULL));
    preencheVetA(A);
    preencheVetBC(A, B, C);
    imprimeVetBC(B, C);
}
void preencheVetA(int *vet){
    for(int cont=0; cont<TAM; cont++){
        vet[cont]=rand()%100+1;
    }
    //system("clear || cls");
}
void preencheVetBC(int *A, int *B, int *C){
    for(int cont=0; cont<TAM/2; cont++){
        if(A[cont]%2==0){
            B[cont]=A[cont];
        }
    }
    for(int cont=0; cont<TAM/2; cont++){
        if(A[cont]%2!=0){
            C[cont]=A[cont];
        }
    }
}
void imprimeVetBC(int *B, int *C){
    int cont;
    printf("\nVetor B:\n");
    for(cont=0; cont<TAM/2; cont++){
        printf(" %d \n", B[cont]);
    }
    printf("\nVetor C:\n");
    for(cont=0; cont<TAM/2; cont++){
        printf(" %d \n", C[cont]);
    }
}
