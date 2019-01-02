#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	system("clear || cls");
	FILE *arqNotas=fopen("Notas.txt", "w");
	FILE *arqSituacao=fopen("Situaca.txt", "w");
	int cont;
	float p1, p2, p3, media;
	srand((unsigned)time(NULL));
	for(cont=0; cont<10; cont++){
		fprintf(arqNotas, "%.1f %.1f %.1f\n", (double)(rand()%11), (double)(rand()%11), (double)(rand()%11));
	}
	fclose(arqNotas);
	arqNotas=fopen("Notas.txt", "r");
	for(cont=0; cont<10; cont++){
		fscanf(arqNotas, "%f%f%f", &p1, &p2, &p3);
		media=(p1+p2+p3)/3.0;
		if(media>=5){
			fprintf(arqSituacao, "%.1f %c\n", media, 'A');	
		}
		else{
			fprintf(arqSituacao, "%.1f %c\n", media, 'R');
		}
	}
	fclose(arqNotas);
	fclose(arqSituacao);
}