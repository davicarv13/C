#include <stdio.h>
#include <stdlib.h>
#define LINHA 2
#define COLUNA 3

void preencheMatriz(int A[][COLUNA]);
void imprimeMatriz(int A[][COLUNA]);
void maiorMenorNotas(int A[][COLUNA]);
int main(){
    int A[LINHA][COLUNA];
    preencheMatriz(A);
    imprimeMatriz(A);
    maiorMenorNotas(A);
}
void preencheMatriz(int A[][COLUNA]){
    int cont, cont2;
    for(cont=0; cont<LINHA; cont++){
        for(cont2=0; cont2<COLUNA; cont2++){
            printf("Aluno %d - Prova %d:", cont+1, cont2+1);
            scanf("%d", &A[cont][cont2]);
            while(A[cont][cont2]>10 || A[cont][cont2]<0){
                system("clear || cls");
                printf("Valor invalido! Informe valores menores que 10 e maiores que 0:");
                scanf("%d", &A[cont][cont2]);
                system("clear || cls");
            }
        }
    }
}
void imprimeMatriz(int A[][COLUNA]){
    int cont, cont2;
    system("clear || cls");
    printf("\t %6s \t %6s \t %6s \t \n", "Prova 1", "Prova 2", "Prova 3");
    for(cont=0; cont<LINHA; cont++){
        printf("%7s %d", "Aluno ", cont+1);
        for(cont2=0; cont2<COLUNA; cont2++){
            printf(" %4d \t\t", A[cont][cont2]);
        }
        printf("\n");
    }
}
void maiorMenorNotas(int A[][COLUNA]){
    int cont, cont2, maiorP1=A[0][0], menorP1=A[0][0], maiorP2=A[0][1], menorP2=A[0][1], maiorP3=A[0][2], menorP3=A[0][2];
    for(cont=0; cont<COLUNA; cont++){
        for(cont2=0; cont2<LINHA; cont2++){
            if(cont==0){
                if(A[cont2][cont]>maiorP1){
                    maiorP1=A[cont2][cont];   
                }
                if(A[cont2][cont]<menorP1){
                    menorP1=A[cont2][cont]; 
                }
            }
            if(cont==1){
                if(A[cont2][cont]>maiorP2){
                    maiorP2=A[cont2][cont];   
                }
                if(A[cont2][cont]<menorP2){
                    menorP2=A[cont2][cont]; 
                }
            }
            if(cont==2){
                if(A[cont2][cont]>maiorP3){
                    maiorP3=A[cont2][cont];   
                }
                if(A[cont2][cont]<menorP3){
                    menorP3=A[cont2][cont]; 
                }
            }
        }
    }
    //printf("Maior P%d: %d", cont, maiorP,"%d", cont);
    //printf("Menor P%d: %d", cont, menorP,"%d", cont);
        
    printf("Maior P1: %d\n", maiorP1);
    printf("Menor P1: %d\n", menorP1);
    printf("Maior P2: %d\n", maiorP2);
    printf("Menor P2: %d\n", menorP2);
    printf("Maior P3: %d\n", maiorP3);
    printf("Menor P3: %d\n", menorP3);
}

