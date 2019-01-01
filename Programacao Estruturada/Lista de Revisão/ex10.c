#include <stdio.h>

void sequencia(int n);

int main(){
    int n;
    printf("Informe um numero 'n' >=1:");
    scanf("%d", &n);
    sequencia(n);
}

void sequencia(int n){
    int cont;
    printf("Sequencia:\n");
    for(cont=1; cont<=n; cont++){
        if(cont%2==0){
            printf("%5d\n", cont+1);
        }
        else{
            printf("%5d\n", cont-1);
        }
    }
}
