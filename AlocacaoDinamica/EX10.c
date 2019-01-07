#include <stdio.h>
#include <stdlib.h>

void inverteNumero(int n);

int main()
{
    int n;
    printf("Informe um numero natural:");
    scanf("%d", &n);
    if(n==0){
        printf("%d", n);
    }
    else{
        inverteNumero(n);
    }
}

void inverteNumero(int n){
    if(n==0){
        exit(0);
    }
    printf("%d", n%10);
    inverteNumero(n/10);
}
