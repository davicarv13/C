#include <stdio.h>
#include <stdlib.h>

void imprimePares(int n, int k);

int main(){

	int n;

	system("clear || cls");

	printf("Informe um numero par:");
	scanf("%d", &n);
	while(n%2!=0){
		printf("Numero nao e par!\n");
		printf("Informe um numero par:");
		scanf("%d", &n);
	}

	int k=n;

	printf("Numeros pares de 0 ate %d:\n", n);

	imprimePares(n, k);

	printf("\n\n");
}

void imprimePares(int n, int k){
	if(k==0){
		printf("%d\n", k);
		exit(0);
	}
	else if(k%2==0){
		printf("%d\n", k);
	}
	imprimePares(n, k-1);
}
