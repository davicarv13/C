#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

void preencheVet(int *vet);
void imprimeVet(int *vet);

int main(){
    int vet[TAM];
    srand((unsigned)time(NULL));
    preencheVet(vet);
    imprimeVet(vet);
}
void preencheVet(int *vet){
    for(int cont=0; cont<TAM; cont++){
        vet[cont]=rand()%20+1;
        for(int cont2=0; cont2<cont; cont2++){
            while(vet[cont]==vet[cont2]){
                printf("%d\n", vet[cont]);
                vet[cont]=rand()%20+1;
                
            }
        }
    }
   
}

void imprimeVet(int *vet){
    printf("Vetor:");
    for(int cont=0; cont<TAM; cont++){
        printf(" %d ", vet[cont]);
    }
}
