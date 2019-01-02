#include <stdio.h>
#include <stdlib.h>

int soma(int n);

int main(){
	int n;
	system("clear || cls");
	printf("Informe um numero inteiro:");
	scanf("%d", &n);
	printf("Soma dos valores de 1 ate %d: %d\n\n", n, soma(n));
}
int soma(int n){
	if(n==1){
		return 1;
	}
	else{
		return (n + soma(n-1));
	}
}
