#include <stdio.h>
#include <stdlib.h>
int main(){
    int resp;
    printf("Menu\n");
    printf("1 - Fim\n");
    printf("2 - Cadastro\n");
    printf("3 - Consulta\n");
    scanf("%d", &resp);
    system("clear || cls");
    switch(resp){
        case 1:
            printf("Opcao escolhida:Fim");
        break;
        case 2:
            printf("Opcao escolhida:Cadastro");
        break;
        case 3:
            printf("Opcao escolhida:Consulta");
        break;
        default:
            printf("Opcao invalida!");
    }
}