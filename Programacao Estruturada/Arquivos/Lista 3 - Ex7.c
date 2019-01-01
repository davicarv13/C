#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main(){
	system("clear || cls");
	char vetCidades[5][50]={"RiodeJaneiro", "Macae", "SaoGoncalo", "Vitoria", "Guararapi"}, cidade[50], cidadePesq[50];
	FILE *arqDistancias=fopen("Distancias.txt", "w");
	FILE *arqGastos=fopen("Gastos.txt", "w");
	int cont, km, teste=0; 
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

	system("clear || cls");
	srand((unsigned)time(NULL));

	for(cont=0; cont<5; cont++){
		fprintf(arqDistancias, "%s %d\n", vetCidades[cont], rand()%1000+1);
	}

	printf("Lista de Cidades arquivadas:\n");
	for(cont=0; cont<5; cont++){
		printf("%s\n", vetCidades[cont]);
	}

	printf("Informe a cidade que voce deseja consultar:");
	scanf("%s", cidadePesq);

	fclose(arqDistancias);
	arqDistancias=fopen("Distancias.txt", "r");

	for(cont=0; cont<5; cont++){
		fscanf(arqDistancias, "%s %d\n", cidade, &km);
		if(strcmp(cidade, cidadePesq)==0){
			litrosNecessarios=(float)km/kml;
			precoFinal=litrosNecessarios*precoComb;
			fprintf(arqGastos, "%s %.1flitros R$ %.2f\n", vetCidades[cont], litrosNecessarios, precoFinal);
			teste=1;
			break;
		}
	}
	if(teste==0){
		system("clear || cls");
		printf("Cidade nao arquivada!\n\n");
		return 1;
	}
	fclose(arqGastos);
	fclose(arqDistancias);
}