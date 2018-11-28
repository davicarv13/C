#include <stdio.h>
#include <stdlib.h>

int calculaP(int n, int b);

int main(){
    int n, b;
    printf("Informe um numero 'n' >= 1:");
    scanf("%d", &n);
    system("clear || cls");
    while(n<1){
        printf("Numero Invalido!\n");
        printf("Informe um numero 'n' >= 1:");
        scanf("%d", &n);
        system("clear || cls");
    }
    printf("Informe um valod para 'b':");
    scanf("%d", &b);
    printf("Valor de P:%d", calculaP(n, b));
}
int calculaP(int n, int b){
    int cont, resul=1;
    for(cont=1; cont<=n; cont++){
        if(cont%2==0){
            resul*=cont-b;
        }
        else{
            resul*=cont+b;
        }
    }
    return resul;
}
