#include <stdio.h>
#include <stdlib.h>
int verificaPrimo(int n);

int main(){
    int n;
    printf("Informe um numero 'n' >=1:");
    scanf("%d", &n);
    system("cls | clear");
    while(n<1){
       printf("Numero invalido!\n");
       printf("Informe um numero 'n' >=1:");
       scanf("%d", &n);
       system("cls | clear");
    }
    
    if(verificaPrimo(n)){
        printf("%d e primo!", n);
    }
    else{
        printf("%d nao e primo!", n);
    }
}

int verificaPrimo(int n){
    int cont, teste=0;
    for(cont=1; cont<n; cont++){
        if(n%cont==0){
            teste++;
        }
    }
    if(teste==1){
        return true;
    }
    else{
        return false;
    }
}
