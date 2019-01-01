#include <stdio.h>
#define LINHA 5
#define COLUNA 3

void preencheMatrizAB(float A[][COLUNA], float B[][COLUNA]);
void preencheMatrizC(float A[][COLUNA], float B[][COLUNA], float C[][COLUNA]);
void imprimeMatrizC(float C[][COLUNA]);

int main(){
    float A[LINHA][COLUNA], B[LINHA][COLUNA], C[LINHA][COLUNA];
    preencheMatrizAB(A, B);
    preencheMatrizC(A, B, C);
    imprimeMatrizC(C);
}
void preencheMatrizAB(float A[][COLUNA], float B[][COLUNA]){
    int cont, cont2;
    printf("Informe valores para a Matriz A:");
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            scanf("%f", &A[cont][cont2]);
        }
    }
    printf("Informe valores para a Matriz B:");
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            scanf("%f", &B[cont][cont2]);
        }
    }
}
void preencheMatrizC(float A[][COLUNA], float B[][COLUNA], float C[][COLUNA]){
    int cont, cont2;
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            C[cont][cont2]=A[cont][cont2]+B[cont][cont2];
        }
    }
    
}
void imprimeMatrizC(float C[][COLUNA]){
    int cont, cont2;
    printf("Matriz C:\n");
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            printf(" %.1f ", C[cont][cont2]);
        }
        printf("\n");
        
    }
    
}

