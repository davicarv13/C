#include <stdio.h>
#include <stdlib.h>

float calculaS(int n);

int main(){
    int n;
    printf("Informe um numero >=1:");
    scanf("%d", &n);
    system("clear || cls");
    while(n<1){
        printf("Numero invalido!\n");
        printf("Informe um numero >=1:");
        scanf("%d", &n);
        system("clear || cls");
    }
    printf("Valor de S:%.2f", calculaS(n));
}
float calculaS(int n){
    int cont;
    float resul=0;
    for(cont=1; cont<=n; cont++){
        if(cont%2==0){
            resul+=cont/(n-(cont-1));
        }
        else{
            resul+=(-1)*(float(cont)/(n-(cont-1)));
        }
    }
    return resul;
}
