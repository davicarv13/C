#include <stdio.h>
#define TAM 15
void preencheVet(int *vet);
void verificaMenor(int *vet);

int main(){
    int vet[TAM];
    preencheVet(vet);
    verificaMenor(vet);
}
void preencheVet(int *vet){
    printf("Informe %d valores para o vetor:\n", TAM);
    for(int cont=0; cont<TAM; cont++){
        scanf("%d", &vet[cont]);
    }
}
void verificaMenor(int *vet){
    int menor=vet[0], posicao;
    for(int cont=0; cont<TAM; cont++){
        if(vet[cont]<menor){
            menor=vet[cont];
            posicao=cont;
        }
    }
    printf("Menor numero:%d\n", menor);
    printf("Posicao em que aparece:%d", posicao);
   
}
