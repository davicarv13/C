#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINHA 3
#define COLUNA 3
void preencheAB(int A[][COLUNA], int B[][COLUNA]);
void imprimeAB(int A[][COLUNA], int B[][COLUNA]);
int verificaInversa(int A[][COLUNA], int B[][COLUNA]);
int main(){
    int A[LINHA][COLUNA], B[LINHA][COLUNA];
    srand((unsigned)time(NULL));
    preencheAB(A, B);
    imprimeAB(A, B);
    if(verificaInversa(A, B)==0){
        printf("B nao e inversa de A");
    }
    else{
        printf("B e inversa de A");
    }
}
void preencheAB(int A[][COLUNA], int B[][COLUNA]){
    int cont, cont2;
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            A[cont][cont2]=rand()%9+1;
            B[cont][cont2]=rand()%9+1;
        }
    }
}
void imprimeAB(int A[][COLUNA], int B[][COLUNA]){
    int cont, cont2;
    printf("Matriz A: \n");
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
           printf(" %d ", A[cont][cont2]);
        }
        printf("\n");
    }
    printf("Matriz B: \n");
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
           printf(" %d ", B[cont][cont2]);
        }
        printf("\n");
    }
}
int verificaInversa(int A[][COLUNA], int B[][COLUNA]){
    int cont, cont2, cont3, cont4, aux;
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            aux=0;
            for(cont3=0, cont4=0; cont3<LINHA, cont4<COLUNA; cont3++, cont4++){
                aux+=A[cont][cont4]*B[cont3][cont2];
            }
            if(cont==cont2 && aux!=1){
                return 0;
            }
            else if(cont!=cont2 && aux!=0){
                return 0;
            }
        }
    }
    return 1;
}
