#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void preencheVet(int *vet);
int verificaPA(int *vet);

int main(){
    int vet[TAM];
    preencheVet(vet);
    if(verificaPA(vet)==1){
        printf("O vetor nao e uma PA");
    }
    else{
        printf("O vetor e uma PA");
    }
}
void preencheVet(int *vet){
    system("clear || cls");
    printf("Informe %d valores para o vetor:\n", TAM);
    for(int cont=0; cont<TAM; cont++){
        scanf("%d", &vet[cont]);
    }
}

int verificaPA(int *vet){
    int r, teste=0;
    r=vet[1]-vet[0];
    for(int cont=0; cont<TAM-1; cont++){
        if(vet[cont+1]!=(vet[cont]+r)){
            teste=1;
        }
    }
    return teste;
}
