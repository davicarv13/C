#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	float x;
	float y;
}Ponto;

void preenchePonto(Ponto *ponto);
float calculaDistancia(Ponto *pontoA, Ponto *pontoB);

int main(){
	Ponto *pontoA, *pontoB;
    printf("Ponto A:\n");
    preenchePonto(pontoA);
    printf("Ponto B:\n");
	preenchePonto(pontoB);

	printf("Distancia entre os pontos: %.2f", calculaDistancia(pontoA, pontoB));
}

void preenchePonto(Ponto *ponto){
	system("clear || cls");
	printf("Informe a cordenada X:");
	scanf("%f", &ponto->x);
	getchar();

	printf("Informe a cordenada Y:");
	scanf("%f", &ponto->y);
	
	system("clear || cls");
}
float calculaDistancia(Ponto *pontoA, Ponto *pontoB){
	return sqrt(pow((pontoB->x)-(pontoA->x), 2)+pow((pontoA->y)-(pontoA->y), 2));
}
