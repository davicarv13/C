#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	system("clear || cls");
	char vetNomes[10][50]={"Mateus", "Jonas", "Evaldo", "Zeli", "Sara", "Debora", "Carlos", "Marcos", "Silas", "Jane"}, nome[50];
	int ano, idade, cont;
	FILE *arqPessoas=fopen("Pessoas.txt", "w");
	FILE *arqMaiores=fopen("Maiores.txt", "w");
	FILE *arqMenores=fopen("Menores.txt", "w");
	srand((unsigned)time(NULL));
	for(cont=0; cont<10; cont++){
		fprintf(arqPessoas, "%s %d\n", vetNomes[cont], 1930+rand()%88);
	}
	fclose(arqPessoas);
	arqPessoas=fopen("Pessoas.txt", "r");
	while(fscanf(arqPessoas, "%s %d\n", nome, &ano)!=EOF){
		idade=2018-ano;
		if(idade>=18){
			fprintf(arqMaiores, "%s %d\n", nome, idade);
		}
		else{
			fprintf(arqMenores, "%s %d\n", nome, idade);
		}
	}
}