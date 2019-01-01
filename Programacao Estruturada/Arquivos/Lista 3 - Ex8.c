#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
	system("clear || cls");
	char vetCidades[8][50]={"RiodeJaneiro", "Macae", "SaoGoncalo", "Vitoria", "Guararapi", "Salvador", "Italva", "Conselheiro"}, cidade[50], cidadeMaisPopulosa[50];
	int cont, numHabitantes=0, maiorNumHabitantes=0;
	FILE *arqCidades=fopen("Cidades.txt", "w");
	FILE *arqSaida=fopen("Saida.txt", "w");

	for(cont=0; cont<8; cont++){
		fprintf(arqCidades, "%s %d\n", vetCidades[cont], rand()%100000+1000);
	}
	
	fclose(arqCidades);
	arqCidades=fopen("Cidades.txt", "r");

	fscanf(arqCidades, "%s %d\n", cidade, &numHabitantes);
	maiorNumHabitantes=numHabitantes;
	while(fscanf(arqCidades, "%s %d\n", cidade, &numHabitantes)!=EOF){
		if(numHabitantes>maiorNumHabitantes){
			strcpy(cidadeMaisPopulosa, cidade);
			maiorNumHabitantes=numHabitantes;
		}
	}
	fprintf(arqSaida, "%s %d", cidadeMaisPopulosa, maiorNumHabitantes);
	fclose(arqCidades);
	fclose(arqSaida);
}	