#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int mat1[2][2], mat2[2][2];
    int linha, coluna, cont, aux, linha2=0, coluna2=0;
    srand((unsigned)time(NULL));
    for(linha=0; linha<2; linha++){
        for(coluna=0; coluna<2; coluna++){
            mat1[linha][coluna]=rand()%4;
            mat2[linha][coluna]=rand()%4;
        }
    }
    printf("Matriz 1: \n");
    for(linha=0; linha<2; linha++){
        for(coluna=0; coluna<2; coluna++){
           printf(" %d ", mat1[linha][coluna]);
        }
        printf("\n");
    }
    printf("Matriz 2: \n");
    for(linha=0; linha<2; linha++){
        for(coluna=0; coluna<2; coluna++){
           printf(" %d ", mat2[linha][coluna]);
        }
        printf("\n");
    }
    
    printf("MultiplicaC'C#o de Matriz 1 * Matriz2\n");
    for(linha=0; linha<2; linha++){
        for(coluna=0; coluna<2; coluna++){
            aux=0;
            for(linha2=0, coluna2=0; linha2<2, coluna2<2; linha2++, coluna2++){
            aux+=mat1[linha][coluna2]*mat2[linha2][coluna];
              
            }
            printf(" %d ", aux);
        }
        printf("\n");
           
          
    }
    
}

