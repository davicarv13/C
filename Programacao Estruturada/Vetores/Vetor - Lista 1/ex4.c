#include <stdio.h>
#include <stdlib.h>
#define TAM 25

void preencheVet(int *vet);
int verificaVet(int *vet);

int main(){
    int vet[TAM];
    preencheVet(vet);
    if(verificaVet(vet)==1){
        printf("Vetor nao ordenado");
    }
    else{
        printf("Vetor ordenado");
    }
    
}

void preencheVet(int *vet){
    system("clear || cls");
    printf("Informe %d valores para o vetor\n", TAM);
    for(int cont=0; cont<TAM; cont++){
        scanf("%d", &vet[cont]);
    }
}

int verificaVet(int *vet){
    int teste=0;
    for(int cont=0; cont<TAM-1; cont++){
        if(vet[cont+1]<vet[cont]){
            teste=1;
        }
    }
    return teste;
}
