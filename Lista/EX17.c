#include <stdio.h>
#include <stdlib.h>
int main(){
    float n1, n2;
    printf("Informe um numero:");
    scanf("%f", &n1);
    getchar();
    system("clear || cls");
    printf("Informe outro numero:");
    scanf("%f", &n2);
    getchar();
    system("clear || cls");
    if(n1<n2){
        printf("Maior:%.2f", n2);
    }
    else if(n2<n1){
        printf("Maior:%.2f", n1);
    }
    else{
        printf("Sao iguais!");
    }
}
