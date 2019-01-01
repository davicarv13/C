#include <stdio.h>
#include <ctype.h>
#include <string.h>
void pegaFrase(char *frase);
void contaVogalConsoante(const char *frase, const char *vogais);

int main(){
    
    char vogais[]={'a','e','i','o','u'},
         frase[100];
    pegaFrase(frase);
    contaVogalConsoante(frase, vogais);
}
void pegaFrase(char *frase){
    printf("Informe uma frase:");
    fgets(frase, 100, stdin);
}
void contaVogalConsoante(const char *frase, const char *vogais){
    char vogal=0, consoante=0, caractere;
    int tam, teste=0;
    tam=strlen(frase);
    for(int cont=0; cont<tam-1; cont++){
        caractere=tolower(frase[cont]);
        for(int cont2=0; cont2<5; cont2++){
            if(caractere==vogais[cont2]){
                vogal++;
                teste=1;
            }
        }
        if(teste==0){
            consoante++;
        }
        teste=0;
    }
    printf("\nVogais:%d\n", vogal);
    printf("\nConsoantes:%d\n", consoante);
}
