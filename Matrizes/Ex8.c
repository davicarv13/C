#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define LINHA 7
#define COLUNA 3

void preencheMatriz(int M[][COLUNA]);
void calculaTransposta(int M[][COLUNA], int N[][LINHA]);
void imprimeMatriz(int N[][LINHA]);
int main(){
    int M[LINHA][COLUNA], N[COLUNA][LINHA];
    srand((unsigned)time(NULL));
    preencheMatriz(M);
    calculaTransposta(M, N);
    imprimeMatriz(N);
}
void preencheMatriz(int M[][COLUNA]){
    int cont, cont2;
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            M[cont][cont2]=rand()%24+1;
        }
    }
}
void calculaTransposta(int M[][COLUNA], int N[][LINHA]){
    int cont, cont2, cont3=0, cont4=0;
    printf("Matriz M:\n");
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            printf(" %2d ", M[cont][cont2]);
        }
        printf("\n");
    }
    for(cont=0; cont<COLUNA; cont++){
        for(cont2=0; cont2<LINHA; cont2++){
            N[cont][cont2]=M[cont3][cont4];
            cont3++;
        }
        cont4++;
        cont3=0;
    }
}
void imprimeMatriz(int N[][LINHA]){
    int cont, cont2;
    printf("Matriz N:\n");
    for(cont=0; cont<COLUNA; cont++){
        for(cont2=0; cont2<LINHA; cont2++){
            printf(" %2d ", N[cont][cont2]);
        }
        printf("\n");
    }
}



