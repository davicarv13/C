#include <stdio.h>
#include <stdlib.h>
#define TAM 15

void preencheVet(int *, char id);
void preencheVetC(int *A, int *B, int *C);
void imprimeVet(int *C);

int main(){
    int A[TAM], B[TAM], C[TAM];
    preencheVet(A, 'A');
    preencheVet(B, 'B');
    preencheVetC(A, B, C);
    imprimeVet(C);
}
void preencheVet(int *vet, char id){
    printf("Informe %d elementos para o vetor %c:\n", TAM, id);
    for(int cont=0; cont<TAM; cont++){
        scanf("%d", &vet[cont]);
    }
    //system("clear || cls");
}
void preencheVetC(int *A, int *B, int *C){
    for(int cont=0; cont<TAM; cont++){
        C[cont]=2*A[cont]+B[cont];
    }
}
void imprimeVet(int *C){
    printf("\nVetor C:\n");
    for(int cont=0; cont<TAM; cont++){
        printf(" %d ", C[cont]);
    }
}
