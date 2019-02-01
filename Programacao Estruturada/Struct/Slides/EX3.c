#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	float x;
	float y;
}Ponto;

void preenchePontos(Ponto *pontos);
float calculaDistancia(Ponto *pontos);

int main(){
	Ponto *pontos=malloc(2*sizeof(Ponto));

	preenchePontos(pontos);

	printf("Distancia entre os pontos: %.2f", calculaDistancia(pontos));
}

void preenchePontos(Ponto *pontos){
	int i;
	for(i=0; i<2; i++){
		system("clear || cls");
		printf("Informe a cordenada X do ponto %d:", i+1);
		scanf("%f", &pontos[i].x);
		getchar();

		printf("Informe a cordenada Y do ponto %d:", i+1);
		scanf("%f", &pontos[i].y);
		getchar();
	}
}
float calculaDistancia(Ponto *pontos){
	return sqrt(pow(pontos[1].x-pontos[0].x, 2)+pow(pontos[1].y-pontos[0].y, 2));
}
