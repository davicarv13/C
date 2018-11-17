#include <stdio.h>
#include <stdlib.h>
void volume(float, float, float);

int main(){
    float larg, alt, comp;
    printf("Informe a largura:");
    scanf("%f", &larg);
    getchar();
    system("clear || cls");
    while(larg<=0){
        printf("Largura invalida!\n");
        printf("Informe a largura:");
        scanf("%f", &larg);
        getchar();
        system("clear || cls");
    }
    printf("Informe a altura:");
    scanf("%f", &alt);
    getchar();
    system("clear || cls");
    while(larg<=0){
        printf("Altura invalida!\n");
        printf("Informe a altura:");
        scanf("%f", &alt);
        getchar();
        system("clear || cls");
    }
    printf("Informe o comprimento:");
    scanf("%f", &comp);
    getchar();
    system("clear || cls");
    while(comp<=0){
        printf("Comprimento invalido!\n");
        printf("Informe o comprimento:");
        scanf("%f", &comp);
        getchar();
        system("clear || cls");
    }
    
    volume(alt, comp, larg);
}

void volume(float alt, float comp, float larg){
    printf("Volume:%2.f", alt*comp*larg);
}
