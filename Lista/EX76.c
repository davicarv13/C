#include <stdio.h>
#include <stdlib.h>
#define MAX 2

void preencheVet(float *, float *);
void concatVet(float *, float *, float *);
void imprimiVet(float *);
int main(){
    float vet1[MAX], vet2[MAX], vet3[2*MAX];
    preencheVet(vet1, vet2);
    concatVet(vet1, vet2, vet3);
    imprimiVet(vet3);
}

void preencheVet(float vet1[], float vet2[]){
    int cont=0;
    printf("Preencha os vetores:\n");
    for(; cont<MAX; cont++){
       
        printf("Vetor 1:\n");
        scanf("%f", &vet1[cont]);
        system("clear || cls");
        printf("Vetor 2:\n");
        scanf("%f", &vet2[cont]);
        system("clear || cls");
    }
}

void concatVet(float vet1[], float vet2[], float vet3[]){
    int cont, cont2=0;
    for(cont=0;cont<2*MAX;cont++){
        if(cont<MAX){
            vet3[cont]=vet1[cont];
        }
        else{
            vet3[cont]=vet2[cont2];
            cont2++;
        }
    }
}

void imprimiVet(float vet3[]){
    int cont=0;
    printf("Vetor 3:\n");
    for(;cont<2*MAX;cont++){
        printf("%.2f\n", vet3[cont]);
    }
}
