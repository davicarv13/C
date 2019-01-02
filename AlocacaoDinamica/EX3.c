#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraVet(int *vet);
void ordenaVet(int *vet);

int main(){
	system("clear || cls");
	int i, j, tam, menor, aux, posMenor, *teste=(int *)malloc(sizeof(int));
	int *vet;
	srand((unsigned)time(NULL));
	vet=(int *)malloc(sizeof(int));
	if(vet==NULL){
		printf("Erro! Memoria Insuficiente!\n");
		exit(1);
	}
	printf("Informe valores (-1) para parar:");
	tam=0;
	(*teste)=1;
	do{
		scanf("%d", &vet[tam]);
		if(vet[tam]==(-1)){
			break;
		}
		else{
			tam++;
			vet=realloc(vet, (tam+1)*sizeof(int));	
			if(vet==NULL){
				printf("Erro! Memoria Insuficiente!\n");
				exit(1);
			}
		}

	}while((*teste)==1);
	free(teste);

	printf("\n%d\n", tam);
	if(tam!=0){
		printf("Vetor nao ordenado:\n");
		for(i=0; i<tam; i++){
			printf("%d ", vet[i]);
		}
		for(i=0; i<tam; i++){
			menor=vet[i];
			posMenor=i;
			for(j=i; j<tam; j++){
				if(vet[j]<menor){
					menor=vet[j];
					posMenor=j;
				}
			}
			aux=vet[i];
			vet[i]=menor;
			vet[posMenor]=aux;
		}
		printf("\nVetor Ordenado:\n");
		for(i=0; i<tam; i++){
			printf("%d ", vet[i]);
		}
		free(vet);
		for(i=0; i<tam; i++){
			printf("%d ", vet[i]);
		}
	}
	else{
		printf("Nenhum valor informado!");
		exit(1);
	}
	printf("\n\n");
	//free(vet);
	
}	
