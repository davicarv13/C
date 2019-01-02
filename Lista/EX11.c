#include <stdio.h>
#include <stdlib.h>
int main(){
    float sal, perc;
    printf("Informe o salario:");
    scanf("%f", &sal);
    getchar();
    system("clear || cls");
    while(sal<0){
        printf("Salario invalido!\n");
        printf("Informe o salario:");
        scanf("%f", &sal);
        getchar();
        system("clear || cls");
    }
    
    printf("Informe o percentual de reajuste:");
    scanf("%f", &perc);
    getchar();
    system("clear || cls");
    while(perc<0){
        printf("Percentual de desconto invalido!\n");
        printf("Informe o percentual de reajuste:");
        scanf("%f", &perc);
        getchar();
        system("clear || cls");
    }
    printf("Salario reajustado:%.2f", sal+(sal*perc/100));
}
