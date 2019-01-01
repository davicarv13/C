#include <stdio.h>
#include <stdlib.h>

int calculaS(int n);

int main(){
    int n;
    printf("Informe um numero >= n:");
    scanf("%d", &n);
    system("clear || cls");
    printf("Valor de S:%d", calculaS(n));
}
int calculaS(int n){
    int cont, resul=0;
    for(cont=1; cont<=n; cont++){
        if(cont%2==0){
            resul+=(-1)*cont;
        }
        else{
            resul+=cont;
        }
    }
    return resul;
}
