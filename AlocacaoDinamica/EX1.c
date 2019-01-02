#include <stdio.h>
#include <stdlib.h>

void limpaTela();
void preencheVet(int *vet, int n);
int pegaTam();

int main(){
	limpaTela();
	int *vet, n, i;
	n=pegaTam();
	vet=(int *)calloc(n, sizeof(int));
	preencheVet(vet, n);
	limpaTela();
	printf("Vetor informado:");
	for(i=0; i<n; i++){
		printf("%d ", vet[i]);
	}

	free(vet);
	vet=NULL;
	printf("\n\n");
}
void limpaTela(){
	system("clear || cls");
}

void preencheVet(int *vet, int n){
	int i;
	limpaTela();
	printf("Informe valores para o vetor:");
	for(i=0; i<n; i++){
		scanf("%d", &vet[i]);
	}
}

int pegaTam(){
	int n;
	printf("Informe o tamanho do vetor:");
	scanf("%d", &n);
	getchar();
	while(n<=0){
		printf("Valor invalido!\n");
		printf("Informe o tamanho do vetor (Valores positivos):");
		scanf("%d", &n);
		getchar();
	}
}
