#include <stdio.h>
#include <stdlib.h>

int fatorial(int n);

int main(){
	int n;
	system("clear || cls");
	printf("Informe um numero inteiro:");
	scanf("%d", &n);
	printf("Fatorial de %d: %d\n\n", n, fatorial(n));
}
int fatorial(int n){
	if(n==1){
		return 1;
	}
	else{
		return (n * fatorial(n-1));
	}
}