#include <stdio.h>

void escada(int n);

int main(){
    int n;
    printf("Informe um numero >= 1:");
    scanf("%d", &n);
    escada(n);
}
void escada(int n){
    int cont, cont2;
    for(cont=1; cont<=n; cont++){
        for(cont2=1; cont2<=cont; cont2++){
            printf(" %d ", cont2);
        }
        printf("\n");
    }
}