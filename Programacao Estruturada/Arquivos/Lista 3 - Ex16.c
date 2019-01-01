#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main(){
	system("clear || cls");
	int quantPalavra=0, cont, numRepeticoes;
	char palavras[20][15]={"Um", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez"}, palavra[15], palavraAProcurar[15];
	FILE *arqPalavras=fopen("Palavras.txt", "w");
	srand((unsigned)time(NULL));
	printf("Informe uma palavra:");
	scanf("%s", palavraAProcurar); 
	numRepeticoes=rand()%30;
	for(cont=0; cont<numRepeticoes; cont++){
		fprintf(arqPalavras, "%s\n", palavras[rand()%10]);
	}
	fclose(arqPalavras);
	arqPalavras=fopen("Palavras.txt", "r");
	while(fscanf(arqPalavras, "%s\n", palavra)!=EOF){
		if(strcmp(palavra, palavraAProcurar)==0){
			quantPalavra++;
		}
	}
	printf("Quantidade de vezes que a palavra %s aparece no arquivo:%d\n\n", palavraAProcurar, quantPalavra);
	fclose(arqPalavras);
}