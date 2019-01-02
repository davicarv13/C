#include <stdio.h>
int main(){
    int A, B, C;
    printf("Informe um valor para 'A':");
    scanf("%d", &A);
    getchar();
    printf("Informe um valor para 'B':");
    scanf("%d", &B);
    getchar();
    C=A;
    A=B;
    B=C;
    printf("Valores trocados:\n");
    printf("A:%d\n", A);
    printf("B:%d\n", B);
}
