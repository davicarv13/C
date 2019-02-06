#include <stdio.h>
#include <stdlib.h>

int fatorial(int n);

int main(){
	int n;

	printf("Informe um numero maio que 0:");
	scanf("%d", &n);

	printf("Fatorial relativo a posicao %d:%d",n, fatorial(n));
}

int fatorial(int n){
	if(n==1 || n==0){
		return n;
	}
	else{
		return fatorial(n-2)+fatorial(n-1);	
	}
	
}
