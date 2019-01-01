#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ORDEM 10

void preencheMatriz(float A[][ORDEM]);
void imprimeMatriz(float A[][ORDEM]);
float calculaMinimax(float A[][ORDEM]);

/*Obs: Em caso de existirem mais de uma linha cujo maior
valor contido na matriz esteja contido será considerada 
a ultima linha da matriz onde o maior valor esteja contido 
*/

int main(){
    float A[ORDEM][ORDEM];
    srand((unsigned)time(NULL));
    preencheMatriz(A);
    imprimeMatriz(A);
    printf("O Minimax da matriz A e:%.2f", calculaMinimax(A));
}
void preencheMatriz(float A[][ORDEM]){
    int cont, cont2;
    for(cont=0; cont<ORDEM; cont++){
        for(cont2=0; cont2<ORDEM; cont2++){
            A[cont][cont2]=rand()%49+1;
        }
    }
}

void imprimeMatriz(float A[][ORDEM]){
    int cont, cont2;
    printf("Matriz A:\n");
    for(cont=0; cont<ORDEM; cont++){
        for(cont2=0; cont2<ORDEM; cont2++){
            printf(" %4.1f ", A[cont][cont2]);
        }
        printf("\n");
    }
}
float calculaMinimax(float A[][ORDEM]){
    int cont, cont2, maior=A[0][0], linhaMaior=0;
    float minimax=0;
    for(cont=0; cont<ORDEM; cont++){
        for(cont2=0; cont2<ORDEM; cont2++){
            if(A[cont][cont2]>maior){
                maior=A[cont][cont2];
                linhaMaior=cont;
            }
        }
    }
    minimax=A[linhaMaior][0];
    for(cont=linhaMaior, cont2=0; cont2<ORDEM; cont2++){
        if(A[cont][cont2]<minimax){
            minimax=A[cont][cont2];
        }
    }
    return minimax;
}



