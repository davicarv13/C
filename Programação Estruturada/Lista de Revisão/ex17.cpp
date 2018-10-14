#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float calculaS(int n);

int main(){
    int n;
    printf("Informe um numero >= 1:");
    scanf("%d", &n);
    system("clear || cls");
    while(n<1){
        printf("Numero invalido!\n");
        printf("Informe um numero >= 1:");
        scanf("%d", &n);
        system("clear || cls");
    }
    printf("Valor de S:%.2f", calculaS(n));
}
float calculaS(int n){
    int cont;
    float resul=0;
    for(cont=1; cont<=n; cont++){
        resul+=(pow(cont, 2)+1)/(cont+3);
    }
    return resul;
}