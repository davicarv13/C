#include <stdio.h>
#include <stdlib.h>

int fatorialDuplo(int n);

int main(){

	int n, k=1;

	system("clear || cls");

	printf("Informe um numero impar:");
	scanf("%d", &n);
	while(n%2==0){
		printf("Numero nao e par!\n");
		printf("Informe um numero impar:");
		scanf("%d", &n);
	}

	printf("Fatorial duplo de %d:\n", fatorialDuplo(n));

	printf("\n\n");
}

int fatorialDuplo(int n){
	if(n==1){
		return 1;
	}
	else if(n%2!=0){
		return n*fatorialDuplo(n-1);
	}
	else{
		fatorialDuplo(n-1);
	}
}
