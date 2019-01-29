#include <stdio.h>
#include <stdlib.h>

typedef struct{
	float x;
	float y;
	float z;
}Vetor3d;

void pegaVetores(Vetor3d *vetores3d);
float calculaProdutoEscalar(Vetor3d *vetores3d);
void calculaProdutoVetorial(Vetor3d *vetores3d);

int main(){

	Vetor3d *vetores3d=malloc(2*sizeof(Vetor3d));

	pegaVetores(vetores3d);

	printf("Produto Escalar: %.2f\n", calculaProdutoEscalar(vetores3d));
	calculaProdutoVetorial(vetores3d);
}

void pegaVetores(Vetor3d *vetores3d){
	int i;

	for(i=0; i<2; i++){
		system("clear || cls");
		if(i==0){
			printf("Vetor v:\n");
		}
		else{
			printf("Vetor w:\n");
		}
		printf("X:");
		scanf("%f", &vetores3d[i].x);
		getchar();
		printf("Y:");
		scanf("%f", &vetores3d[i].y);
		getchar();
		printf("Z:");
		scanf("%f", &vetores3d[i].z);
		getchar();
	}
}
float calculaProdutoEscalar(Vetor3d *vetores3d){
	return ((vetores3d[0].x*vetores3d[1].x)+(vetores3d[0].y*vetores3d[1].y)+(vetores3d[0].z*vetores3d[1].z));
}

void calculaProdutoVetorial(Vetor3d *vetores3d){
	float x, y, z;
	int i;

	for(i=0; i<3; i++){
		if(i==0){
			x=(vetores3d[0].y*vetores3d[1].z)-(vetores3d[0].z*vetores3d[1].y);
		}
		else if(i==1){
			y=(-1)*((vetores3d[0].x * vetores3d[1].z) - (vetores3d[0].z * vetores3d[1].x));
		}
		else{
			z=(vetores3d[0].x * vetores3d[1].y)-(vetores3d[0].y * vetores3d[1].x);	
		}
	}

	printf("Produto v x w: (%.1f, %.1f, %.1f)\n", x, y, z);
	printf("Produto w x v: (%.1f, %.1f, %.1f)\n", (-1)*x, (-1)*y, -(1)*z);
}
