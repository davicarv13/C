#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float* segundoGrau(float a, float b, float c);

int main(){
	float a, b, c;
	float *coef;

	printf("Informe 'a':");
	scanf("%f", &a);
	getchar();
	printf("Informe 'b':");
	scanf("%f", &b);
	getchar();
	printf("Informe 'c':");
	scanf("%f", &c);

	coef=segundoGrau(a, b, c);
	
	printf("Raizes reais:%.2f e %.2f", coef[0], coef[1]);
	
	free(coef);
	coef=NULL;
}

float* segundoGrau(float a, float b, float c){
	float *coef;
	float det;

	coef=calloc(2, sizeof(coef));
	det=(pow(b, 2))-(4*a*c);
	if(det<0){
		system("clear || cls");
		printf("Determinante negativo. Nao existem raizes reais\n");
		exit(0);
	}
	else{
		coef[0]=(((-1)*b)+sqrt(det))/(2*a);
		coef[1]=(((-1)*b)-sqrt(det))/(2*a);
		return coef;
	}
}
