#include <stdio.h>
#include <stdlib.h>
int main(){
	float p1=0, p2=0, media=0;
	char conceito;
	printf("Informe a nota 1:");
	scanf("%f", &p1);
	while((p1>10)||(p1<0)){
		printf("Nota inválida! Informe uma nota válida:");
		scanf("%f", p1);
	}
	printf("Informe a nota 2:");
	scanf("%f", &p2);
	while((p2>10)||(p2<0)){
		printf("Nota inválida! Informe uma nota válida:");
		scanf("%f", p2);
	}
	media=(p1+p2)/2;
	if((media>=9)&&(media<=10)){
		conceito='A';
	}
	if((media>=7.5)&&(media<9)){
		conceito='B';
	}
	if((media>=6)&&(media<7.5)){
		conceito='C';
	}
	if((media>=4)&&(media<6)){
		conceito='D';
	}
	if((media>=0)&&(media<4)){
		conceito='E';
	}
	if((conceito=='A')||(conceito=='B')||(conceito=='C')){
		printf("Aprovado!\n");
		printf("Conceito:%c", conceito);
		
	}
	else
		if((conceito=='D')||(conceito=='E')){		
		printf("Aprovado!\n");
		printf("Conceito:%c", conceito);
	}
	system("pause");
}
