#include <stdio.h>
#include <stdlib.h>

int calculaFatorial(int cont);
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
    printf("Valor de S:%.3f", calculaS(n));
}
float calculaS(int n){
    int i;
    float s=0;
    for(i=1; i<=n; i++){
        s+=float(i)/calculaFatorial(i-1);
    }
    return s;
}
int calculaFatorial(int cont){
    int i, resul=1;
    if(cont==0){
        return 1;
    }
    else{
        for(i=1; i<=cont; i++){
            resul*=i;
        }
    }
    return resul;
}