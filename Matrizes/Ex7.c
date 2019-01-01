#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define LINHA 4
#define COLUNA 4

void preencheMatriz(int M[][COLUNA]);
int verificaSimetrica(int M[][COLUNA]);
void imprimeMatriz(int M[][COLUNA]);
int main(){
    int M[LINHA][COLUNA];
    srand((unsigned)time(NULL));
    preencheMatriz(M);
    if(verificaSimetrica(M)==0){
        printf("Matriz Nao simetrica!");
    }
    else{
        printf("Matriz simetrica!");
    }
}
void preencheMatriz(int M[][COLUNA]){
    int cont, cont2;
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            M[cont][cont2]=rand()%50+1;
        }
    }
}
int verificaSimetrica(int M[][COLUNA]){
    int cont, cont2;
    imprimeMatriz(M);
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            if(cont!=cont2){
                if(M[cont][cont2]!=M[cont2][cont]){
                    return 0;
                }
            }
        }
    }
    return 1;
}
void imprimeMatriz(int M[][COLUNA]){
    int cont, cont2;
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            printf(" %d ", M[cont][cont2]);
        }
        printf("\n");
    }
}
