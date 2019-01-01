#include <stdio.h>
#define MAX 99
float calculaS();

int main(){
    printf("Valor de S:%.2f", calculaS());
}
float calculaS(){
    float s=0;
    float cont, cont2=1;
    for(cont=1; cont<=MAX; cont=cont+2){
        s+=cont/cont2;
        cont2++;
    }
    return s;
}
