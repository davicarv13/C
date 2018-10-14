#include <stdio.h>
#define MAX 40
int main(){
	float vetor[MAX], maior=0, menor=0;
	int cont=0;
	printf("Informe valores:");
	for(cont=0; cont<MAX; cont++){
		scanf("%f", &vetor[cont]);
	}
	menor=vetor[0];
	maior=vetor[0];
	for(cont=0; cont<MAX; cont++){
		if(vetor[cont]>maior){
			maior=vetor[cont];
		}
		if(vetor[cont]<menor){
			menor=vetor[cont];
		}
	}
	printf("Maior:%.2f", maior);
	printf("Menor:%.2f", menor);
}
