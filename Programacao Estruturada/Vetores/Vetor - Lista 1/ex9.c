#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 20

void preencheVet(int *vet);
void imprimeVet(int *vet);
void verificaParImpar(int *vet);

int main(){
    int vet[TAM];
    srand((unsigned)time(NULL));
    preencheVet(vet);
    imprimeVet(vet);
    verificaParImpar(vet);
}

void preencheVet(int *vet){
    for(int cont=0; cont<TAM; cont++){
        vet[cont]=rand()%49;
    }
}
void imprimeVet(int *vet){
    printf("Vetor:\n");
    for(int cont=0; cont<TAM; cont++){
        printf(" %d ", vet[cont]);
    }
}

void verificaParImpar(int *vet){
    int par=0, impar=0;
    for(int cont=0; cont<TAM; cont++){
        if(vet[cont]%2==0){
            par++;
        }
        else{
            impar++;
        }
    }
    printf("\nQuantidade de numeros impares:%d\n", impar);
    printf("Quantidade de numeros pares:%d", par);
}
