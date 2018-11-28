#include <stdio.h>
#include <ctype.h>
#include <string.h>

void pegaFrase(char *frase);
int verificaLetra(const char *frase, const char caractere);

int main(){
    char frase[40], caractere;
    pegaFrase(frase);
    printf("Informe um cacactere:");
    caractere=getchar();
    if(verificaLetra(frase, caractere)==1){
        printf("O caractere '%c' existe em %s", caractere, frase);
    }
    else{
        printf("O caractere '%c' nao existe em %s", caractere, frase);
    }
    
}
void pegaFrase(char *frase){
    printf("Informe uma frase:");
    fgets(frase, 100, stdin);
}
int verificaLetra(const char *frase, const char caractere){
    char car;
    int tam;
    tam=strlen(frase);
    for(int cont=0; cont<tam-1; cont++){
        car=tolower(frase[cont]);
        if(car==caractere){
            return 1;
        }
    }
    return 0;
}
