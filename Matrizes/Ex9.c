#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define LINHA 10
#define COLUNA 10

void preencheMatriz(int M[][COLUNA]);
int verificaIdentidade(int M[][COLUNA]);
void imprimeMatriz(int M[][COLUNA]);
int main(){
    int M[LINHA][COLUNA];
    srand((unsigned)time(NULL));
    preencheMatriz(M);
    if(verificaIdentidade(M)==0){
        printf("Matriz não e identidade!");
    }
    else{
        printf("Matriz identidade!");
    }
    
}
void preencheMatriz(int M[][COLUNA]){
    int cont, cont2;
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
           M[cont][cont2]=rand()%20;
        }
    }
}
int verificaIdentidade(int M[][COLUNA]){
    int cont, cont2;
    imprimeMatriz(M);
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            if(cont==cont2){
                if(M[cont][cont2]!=1){
                    return 0;
                }
            }
            else if(cont!=cont2){
                if(M[cont][cont2]!=0){
                    return 0;
                }
            }
            
        }
    }
    return 1;
}
void imprimeMatriz(int M[][COLUNA]){
    int cont, cont2;
    printf("Matriz M:\n");
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            printf(" %2d ", M[cont][cont2]);
        }
        printf("\n");
    }
}



