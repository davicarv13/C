#include <stdio.h>
#include <stdlib.h>
long int fatorial(int n);

int main(){
    int n;
    printf("Informe um numero nao negativo:");
    scanf("%d", &n);
    system("clear || cls");
    while(n<0){
        printf("Numero invalido!\n");
        printf("Informe um numero nao negativo:");
        system("clear || cls");
    }
    printf("Fatorial de %d e:%ld", n, fatorial(n));
}

long int fatorial(int n){
    int cont;
    long int fatorial=1;
    if(n==0){
        return 1;
    }
    else{
        for(cont=1; cont<=n; cont++){
            fatorial*=cont;
        }
    }
    return fatorial;
}