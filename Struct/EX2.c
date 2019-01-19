#include <stdio.h>
#include <stdlib.h>

int main(){
	typedef struct Data{
		int hora, minuto, segundos;
	}Dt;

	Dt *dt1=malloc(sizeof(Dt));

	printf("Informe a hora:");
	scanf("%d", &dt1->hora);
	getchar();
	while(dt1->hora<=0 || dt1->hora>23){
		system("clear || cls");
		printf("\aHora invalida!\n");
		printf("Informe a hora:");
		scanf("%d", &dt1->hora);
		getchar();
	}
	printf("Informe os minutos:");
	scanf("%d", &dt1->minuto);
	getchar();
	while(dt1->minuto<=0 || dt1->minuto>59){
		system("clear || cls");
		printf("\aMinutos invalidos!\n");
		printf("Informe o minuto:");
		scanf("%d", &dt1->minuto);
		getchar();
	}
	printf("Informe os segundos:");
	scanf("%d", &dt1->segundos);
	while(dt1->segundos<=0 || dt1->segundos>59){
		system("clear || cls");
		printf("\aSegundos invalidos!\n");
		printf("Informe os segundos:");
		scanf("%d", &dt1->segundos);
		getchar();
	}

	printf("Hora: %d:%d:%d", dt1->hora, dt1->minuto, dt1->segundos);

	free(dt1);
}
