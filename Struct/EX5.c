#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define CODIGO 9
#define QUANTVOOS 5
#define QUANTAEROPORTOS 5 

typedef struct {
	int codOrigem, codDestino;
}Voos;

typedef struct {
	int codAeroporto, quantVoosChegam, quantVoosSaem;
}Aeroportos;

void preencheAeroportos(Aeroportos *aeroporto);
void preencheVoos(Aeroportos *aeroporto, Voos *voos);
void imprimeVoos(Voos *voos);
void imprimeAeroportos(Aeroportos *aeroporto);

int main(){
	
	setlocale(LC_ALL, "Portuguese");

	int resp=0;

	Voos *voos=calloc(QUANTVOOS, sizeof(Voos));
	Aeroportos *aeroporto=calloc(QUANTAEROPORTOS, sizeof(Aeroportos));

	preencheAeroportos(aeroporto);
	preencheVoos(aeroporto, voos);

	while(resp!=3){
		printf("1 \t %s\n", "Consultar Aerportos");
		printf("2 \t %s\n", "Consultar Voôs");
		printf("3 \t %s\n", "Sair");
		scanf("%d", &resp);

		if(resp>3 || resp<1){
			system("clear || cls");
			printf("Opção Inválida!\n\n");
		}

		else{
			switch(resp){
				case 1:
					imprimeAeroportos(aeroporto);
				break;
				case 2:
					imprimeVoos(voos);
				break;
			}
		}
		
	}

	free(aeroporto);
	free(voos);
	aeroporto=NULL;
	voos=NULL;
}

void preencheAeroportos(Aeroportos *aeroporto){
	system("clear || cls");

	int i, j; 

	printf("Códigos Válidos: 0 a 4\n\n");

	for(i=0; i<QUANTAEROPORTOS; i++){
		system("clear || cls");
		printf("Informe o codigo do aeroporto:");
		scanf(" %d", &aeroporto[i].codAeroporto);
		getchar();

		while(aeroporto[i].codAeroporto>4 || aeroporto[i].codAeroporto<0){
			system("clear || cls");
			printf("\aCódigo inválido\n");
			printf("Informe o codigo do aeroporto: ");
			scanf(" %d", &aeroporto[i].codAeroporto);
			getchar();
		}

		for(j=0; j<i; j++){
			if(aeroporto[j].codAeroporto==aeroporto[i].codAeroporto){
				system("clear || cls");
				printf("\aCódigo Repetido!\n");
				printf("Informe o código do aeroporto:");
				scanf(" %d", &aeroporto[i].codAeroporto);
				j=0;
			}
		}
	}
}

void preencheVoos(Aeroportos *aeroporto, Voos *voos){
	system("clear || cls");

	int i, j;

	printf("Códigos Válidos: 0 a 4\n\n");

	for(i=0; i<QUANTAEROPORTOS; i++){
		printf("Voo %d:\n", i+1);
		printf("Informe o código do aeporto de origem:");
		scanf(" %d", &voos[i].codOrigem);
		getchar();

		while(voos[i].codOrigem>4 || voos[i].codOrigem<0){
			system("clear || cls");
			printf("\aCódigo invalido!\n");
			printf("Informe o codigo do aeporto de origem:");
			scanf(" %d", &voos[i].codOrigem);
			getchar();
		}

		printf("Informe o código do aeporto de destino:");
		scanf(" %d", &voos[i].codDestino);
		getchar();

		while(voos[i].codDestino>4 || voos[i].codDestino<0){
			system("clear || cls");
			printf("\aCódigo inválido\n");
			printf("Informe o codigo do aeroportorto de destino: ");
			scanf(" %d", &voos[i].codDestino);
			getchar();
		}

		while(voos[i].codDestino==voos[i].codOrigem){
			system("clear || cls");
			printf("Códigos de origem e destino iguais!\n");
			printf("Informe um codigo de destino diferente do de origem (%d):", voos[i].codOrigem);
			scanf(" %d", &voos[i].codDestino);
			getchar();
		}

		for(j=0; j<QUANTAEROPORTOS; j++){
			if(voos[i].codOrigem==aeroporto[j].codAeroporto){
				aeroporto[j].quantVoosSaem++;
			}

			if(voos[i].codDestino==aeroporto[j].codAeroporto){
				aeroporto[j].quantVoosChegam++;
			}
		}
		system("clear || cls");
	}
}

void imprimeVoos(Voos *voos){
	int i;

	system("clear || cls");

	printf("Voos\n\n");

	for(i=0; i<QUANTVOOS; i++){
		printf("Voo %d:\n", i+1);
		printf("Origem: Aeroporto %d\n", voos[i].codOrigem);
		printf("Destino: Aeroporto %d\n\n", voos[i].codDestino);
	}
}

void imprimeAeroportos(Aeroportos *aeroporto){
	int i;

	system("clear || cls");

	printf("Aeroportos\n\n");

	for(i=0; i<QUANTAEROPORTOS; i++){
		printf("Aeroporto %d:\n", aeroporto[i].codAeroporto);
		printf("Quantidade de voos que chegaram:%d\n", aeroporto[i].quantVoosChegam);
		printf("Quantidade de voos que chegaram:%d\n\n", aeroporto[i].quantVoosSaem);
	}
}	