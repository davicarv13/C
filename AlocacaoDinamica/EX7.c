#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* geraV(int n);
int** inverte2(int n, int* v);
void imprimeVetV(int *v, int n);
void imprimeVetW(int **w, int n);

int main(){
	system("clear || cls");
	int *v, **w;
	int n;

	srand((unsigned)time(NULL));

	printf("Informe a quantidade de elementos do vetor:");
	scanf(" %d", &n);
	while(n<=0){
		printf("Valor invalido!\n");
		printf("Informe a quantidade de elementos do vetor (Valores Positivos):");
		scanf(" %d", &n);
	}
	v=geraV(n);

	imprimeVetV(v, n);
	
	w=inverte2(n, v);
	
	imprimeVetW(w, n);

	printf("\n");
	free(v);
	v=NULL;
	free(w);
	w=NULL;
}

int* geraV(int n){
	int i, *v;

	v=(int *)calloc(n, sizeof(int));
	for(i=0; i<n; i++){
		v[i]=rand()%40+1;
	}

	return v;
	v=NULL;
}

int** inverte2(int n, int* v){
	int i, j, menor, posMenor, aux;
	int **w;
	int *vetAux;

	vetAux=(int *)calloc(n, sizeof(int));
	w=(int **)calloc(n, sizeof(int));

	for(i=0; i<n; i++){
		vetAux[i]=v[i];
	}

	for(i=0; i<n; i++){
		posMenor=i;
		menor=vetAux[i];
		for(j=i; j<n; j++){
			if(vetAux[j]<menor){
				menor=vetAux[j];
				posMenor=j;
			}
		}
		w[i]=&v[posMenor];
		aux=vetAux[i];
		vetAux[i]=menor;
		vetAux[posMenor]=aux;
	}

	return w;

	w=NULL;
	free(vetAux);
	vetAux=NULL;
}

void imprimeVetV(int *v, int n){
	int i;

	printf("Vetor v:\n");
	for(i=0; i<n; i++){
		printf("%d ", v[i]);
	}
}

void imprimeVetW(int **w, int n){

	int i;

	printf("\nVetor w:\n");
	for(i=0; i<n; i++){
		printf("%d ", (*w[i]));
	}
}
