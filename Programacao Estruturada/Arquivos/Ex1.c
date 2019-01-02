#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	system("clear || cls");
	char vetNomes[5][50]={"Jose","Silvia","Ana","Julia", "Marcos"}, nome[50];
	FILE *arqTurma=fopen("Turma.txt", "w");
	FILE *arqMedia=fopen("MediaAlunos.txt", "w");
	int cont; 
	float p1, p2, p3, media;
	srand((unsigned)time(NULL));
	for(cont=0; cont<5; cont++){
		fprintf(arqTurma, "%s %.1f %.1f %.1f\n", vetNomes[cont], (double)((rand()%11)+(rand()%10/10.0)), (double)((rand()%11)+(rand()%10/10.0)), (double)((rand()%11)+(rand()%10/10.0)));
	}
	fclose(arqTurma);
	arqTurma=fopen("Turma.txt", "r");
	while(fscanf(arqTurma, "%[^\n]s %f %f %f\n", nome, &p1, &p2, &p3)!=EOF){
		media=(p1+p2+p3)/3.0;
		fprintf(arqMedia, "%s %.1f\n", nome, media);
	}
	fclose(arqTurma);
	fclose(arqMedia);
}