#include <stdio.h>
#include <stdlib.h>

typedef struct{
	float x;
	float y; 
	float z;
}Vetor;

#define TAM 2

void pegaVetores(Vetor *vetores);
void somaVetores(Vetor *vetores);

int main(){
	Vetor *vetores=malloc(TAM*sizeof(Vetor));

	pegaVetores(vetores);
	somaVetores(vetores);

	free(vetores);
	vetores=NULL;
}

void pegaVetores(Vetor *vetores){
	int i;

	for(i=0; i<TAM; i++){
		printf("Vetor %d:\n", i+1);
		printf("X:");
		scanf("%f", &vetores[i].x);
		getchar();

		printf("Y:");
		scanf("%f", &vetores[i].y);
		getchar();

		printf("Z:");
		scanf("%f", &vetores[i].z);
		getchar();
		system("clear || cls");
	}
}

void somaVetores(Vetor *vetores){
	int i;

	printf("Soma dos vetores (%.1f, %.1f, %.1f) e (%.1f, %.1f, %.1f):\n", vetores[0].x, vetores[0].y, vetores[0].z, vetores[1].x, vetores[1].y, vetores[1].z);
	printf("(%.1f, %.1f, %.1f)", vetores[0].x+vetores[1].x, vetores[0].y+vetores[1].y, vetores[0].z+vetores[1].z);
}
