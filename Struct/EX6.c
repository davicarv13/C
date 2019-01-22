#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM_AGENDA 5

typedef struct{
	int dia, mes, ano;
}Datas;

typedef struct{
	char compromisso[60];
	struct Datas Dt[TAM_AGENDA];
}Agenda;

void preencheAgenda(Agenda *agenda);

int main(){
	setlocale(LC_ALL, "Portuguese");

	Agenda *agenda=malloc(TAM_AGENDA*sizeof(Agenda));
	
	preencheAgenda(agenda);
}

void preencheAgenda(Agenda *agenda){
	system("clear || clear");

	int i;

	for(i=0; i<TAM_AGENDA; i++){
		printf("Informe o compromisso:");
		scanf("%[^\n]s", agenda[i].compromisso);
		printf("Informe o dia:");
		scanf("%d", agenda->Dt[i].dia);
		system("clear || cls");
	}
}