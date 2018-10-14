#include <stdio.h>
#include <stdlib.h>
int somatorioDuplo(int n, int m);

int main(){
    int n, m;
    printf("Informe um numero inteiro 'n' >=1:");
    scanf("%d", &n);
    system("cls | clear");
    while(n<1){
        printf("Valor invalido\n");
        printf("Informe um numero inteiro 'n' >=1:");
        scanf("%d", &n);
        system("cls | clear");
    }
    printf("Informe um numero inteiro 'm' >=1:");
    scanf("%d", &m);
    system("cls | clear");
    while(n<1){
        printf("Valor invalido\n");
        printf("Informe um numero inteiro 'n' >=1:");
        scanf("%d", &m);
        system("cls | clear");
    }
    
    printf("Somatorio:%d", somatorioDuplo(n, m));
}

int somatorioDuplo(int n, int m){
    int cont, cont2, somatorio=0, soma=0;
    for(cont=1; cont<=n; cont++){
        for(cont2=1; cont2<=m; cont2++){
            soma+=cont*cont2;
        }
        somatorio+=soma;
        soma=0;
    }
    return somatorio;
}