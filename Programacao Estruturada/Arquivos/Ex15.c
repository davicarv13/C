#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	system("clear || cls");
	int quantPalavras=0, cont, numRepeticoes;
	char palavras[20][20]={"Um", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez"}, palavra[20];
	FILE *arqTexto=fopen("Texto.txt", "w");
	srand((unsigned)time(NULL));
	numRepeticoes=rand()%30;
	for(cont=0; cont<numRepeticoes; cont++){
		fprintf(arqTexto, "%s ", palavras[rand()%10]);
	}
	fclose(arqTexto);
	arqTexto=fopen("Texto.txt", "r");

	while(fscanf(arqTexto, "%s ", palavra)!=EOF){
		quantPalavras++;
	}
	printf("Quantidade de palavras no arquivo:%d\n\n", quantPalavras);
}