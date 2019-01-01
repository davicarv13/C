#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char frase[10];
    int compara, sim=0, nao=0, cont=0;
    printf("Informe 'Fim' para encerrar o algoritmo\n");
    do{
        printf("Informe uma frase:");
        scanf(" %[^\n]s", frase);
        if(strcmp(frase, "Sim")==0){
            sim++;
        }
        else{
            if(strcmp(frase, "Nao")==0){
                nao++;
            }
        }
        cont++;
    }while((strcmp("Fim", frase))!=0);
    if(sim!=0 || nao!=0){
        cont--;
    }
  
    printf("Porcentagem de 'Sim' em relacao a %d frases:%d\n", cont, 100*sim/cont);
  
    printf("Porcentagem de 'Nao' em relacao a %d frase:%d", cont, 100*nao/cont);
}
