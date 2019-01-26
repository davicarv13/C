#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM_AGENDA 5

typedef struct{
	int dia, mes, ano;
}Datas;

typedef struct{
	char compromisso[60];
	Datas data;
}Agenda;

void preencheAgenda(Agenda *agenda);
void verificaCompromissos(Agenda *agenda);

int main(){
	setlocale(LC_ALL, "Portuguese");

	Agenda agenda[TAM_AGENDA];
	
	preencheAgenda(agenda);

	verificaCompromissos(agenda);
}

void preencheAgenda(Agenda *agenda){
	system("clear || clear");

	int i;

	for(i=0; i<TAM_AGENDA; i++){
		printf("Informe o compromisso:");
		scanf("%[^\n]s", agenda[i].compromisso);
		getchar();
		printf("Informe o dia:");
		scanf("%d", &agenda[i].data.dia);
		getchar();
		printf("Informe o dia:");
		scanf("%d", &agenda[i].data.mes);
		getchar();
		printf("Informe o dia:");
		scanf("%d", &agenda[i].data.ano);
		getchar();
		system("clear || cls");
	}
}

void verificaCompromissos(Agenda *agenda){
	int M, A, i, quant=0;

	system("clear || cls");

	printf("Consulta Agenda:\n");

	do{
		printf("Informe o mês:");
		scanf("%d", &M);
		getchar();
		printf("Informe o ano:");
		scanf("%d", &A);
		getchar();

		quant=0;

		for(i=0; i<TAM_AGENDA; i++){
			if(M==(agenda[i].data.mes) && A==(agenda[i].data.mes)){
				quant=1;
				printf("%-15s \t %s\n", "- Compromisso: ", agenda[i].compromisso);
				printf("%-15s \t %d:%d:%d \n\n", "- Data: ", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);
			}
		}

		if(quant==0){
			printf("Nenhum compromisso para esta data!");
		}

		printf("\n\n");

	}while(M!=0);
}
