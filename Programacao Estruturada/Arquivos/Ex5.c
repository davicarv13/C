#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	system("clear || cls");
	char vetCidades[5][50]={"RiodeJaneiro","Macae","SaoGoncalo", "Vitoria", "Guararapi"}, cidade[50];
	FILE *arqDistancias=fopen("Distancias.txt", "w");
	FILE *arqGastos=fopen("Gastos.txt", "w");
	int cont, km; 
	float precoComb, litrosNecessarios, precoFinal, kml;
	printf("Informe quantos km/l seu veiculo e capaz de fazer:\n");
	scanf("%f", &kml);
	while(kml<=0){
		system("clear || cls");
		printf("Valor invalido! Informe quantos km/l seu veiculo e capaz de fazer:\n");
		scanf("%f", &kml);
	}
	printf("Informe o preco do combustivel:\n");
	scanf("%f", &precoComb);
	while(precoComb<=0){
		system("clear || cls");
		printf("Valor invalido! Informe o preco do combustivel:\n");
		scanf("%f", &precoComb);
	}

	srand((unsigned)time(NULL));
	for(cont=0; cont<5; cont++){
		fprintf(arqDistancias, "%s %d\n", vetCidades[cont], rand()%1000+1);
	}
	fclose(arqDistancias);
	arqDistancias=fopen("Distancias.txt", "r");
	for(cont=0; cont<5; cont++){
		fscanf(arqDistancias, "%s %d\n", cidade, &km);
		litrosNecessarios=(float)km/kml;
		precoFinal=litrosNecessarios*precoComb;
		fprintf(arqGastos, "%s R$ %.2f\n", vetCidades[cont], precoFinal);
	}
	fclose(arqGastos);
	fclose(arqDistancias);
}