#include <stdio.h>
#define MAX 200
void pegaNumeros(float *);
void soId(void);

int main(){
	float vet[MAX], n1, n2, maior;
	preencheVet(vet);
	soma(&n1, &n2, &maior);
}

void pegaNumeros(float vet[]){
	float somaVet, mediVet=0;
	register int cont=0;
	for(; cont<MAX; cont++){
		printf("Informe um numero:");
		scanf("%f", &vet[cont]);
		soId();
		*somaVet+=vet[cont];
	}
	mediaVet=somaVet/MAX
	printf("Media dos numeros:\n", mediaVet);
	for(cont=0; cont<MAX; cont++){
		if(vet[cont]>mediaVet){
			printf("Numero %.2f. Posicao:%i", vet[cont], cont);
		}
	}
}

void soId()
{
#ifdef LINUX
__fpurge(stdin);
#elif defined WIN32
fflush(stdin);
#else
#error Plataforma não suportada
#endif
}
