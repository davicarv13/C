#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
    char sexo;
    printf("Informe o sexo:[F/M]");
    sexo=getchar();
    sexo=tolower(sexo);
    switch(sexo){
        case 'f':
            printf("Sexo feminino");
        break;
        case 'm':
            printf("Sexo masculino");
        break;
        default:
            printf("Sexo invalido!");
    }
}
