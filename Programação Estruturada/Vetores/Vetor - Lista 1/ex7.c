#include <stdio.h>
#define TAM 15
void preencheVet(int *vet);
void verificaMaior(int *vet);

int main(){
    int vet[TAM];
    preencheVet(vet);
    verificaMaior(vet);
}
void preencheVet(int *vet){
    printf("Informe %d valores para o vetor:\n", TAM);
    for(int cont=0; cont<TAM; cont++){
        scanf("%d", &vet[cont]);
    }
}
void verificaMaior(int *vet){
    int maior=vet[0], posicao;
    for(int cont=0; cont<TAM; cont++){
        if(vet[cont>maior]){
            maior=vet[cont];
            posicao=cont;
        }
    }
    printf("Maior numero:%d\n", maior);
    printf("Posicao em que aparece:%d", posicao);
   
}
