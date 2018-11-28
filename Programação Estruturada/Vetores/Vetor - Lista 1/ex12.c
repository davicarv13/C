#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void pegaFrase(char *frase, int tam);
void imprimeSemEspacos(char *frase);

int main(){
    char frase[40];
    pegaFrase(frase, 40);
    imprimeSemEspacos(frase);
}
void pegaFrase(char *frase, int tam){
    printf("Informe uma frase:");
    fgets(frase, tam, stdin);
    system("clear || cls");
}
void imprimeSemEspacos(char *frase){
    int tam=strlen(frase);
    for(int cont=0; cont<tam; cont++){
        if(frase[cont]==' '){
            continue;
        }
        printf("%c", frase[cont]);
    }
}
