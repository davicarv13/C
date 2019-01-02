#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 50

void limpaTela();
void pegaFrase(char *frase);
void inverte(char *frase);

int main(){
	limpaTela();
	char frase[TAM];
	pegaFrase(frase);
	inverte(frase);
	printf("\n\n");
}
void limpaTela(){
	system("clear || cls");
}
void pegaFrase(char *frase){
	printf("Informe uma frase:");
	scanf("%[^\n]s", frase);
}
void inverte(char *frase){
	int i, k=0, pos=0, tamFrase, tam=0, teste=0;
	tamFrase=strlen(frase);
	for(i=(tamFrase-1); i>=0; i--){
		pos++;
		if(frase[i]==' '){
			pos+=i;
			for(k=(i+1); k<pos; k++){
				printf("%c", frase[k]);
			}
			pos=0;
			teste=1;
			printf(" ");
		}
		if(i==0){
			for(k=0; k<pos; k++){
				printf("%c", frase[k]);
			}	
		}
	}
}