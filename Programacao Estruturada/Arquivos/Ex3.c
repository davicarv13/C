#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	char vetNomes[5][50]={"Joana", "Luiza", "Ana", "Marcos", "Luis"}, nome[50];
	FILE *arqMedias=fopen("Medias.txt", "w");
	FILE *arqAprovados=fopen("Aprovados.txt", "w");
	FILE *arqReprovados=fopen("Reprovados.txt", "w");
	int cont;
	float media;
	srand((unsigned)time(NULL));
	for(cont=0; cont<5; cont++){
		fprintf(arqMedias, "%s %.1f\n", vetNomes[cont], (double)((rand()%11)+((rand()%10)/10.0)));
	}

	fclose(arqMedias);
	arqMedias=fopen("Medias.txt", "r");
	while(fscanf(arqMedias, "%s %f\n", nome, &media)!= EOF){
		if(media>=7){
			fprintf(arqAprovados, "%s %.1f\n", nome, media);
		}
		else{
			fprintf(arqReprovados, "%s %.1f\n", nome, media);
		}
	}
}