#include <stdio.h>

float fatorialQuad(int n);

int main(){
	int n;

	printf("Informe um numero positivo:");
	scanf("%d", &n);

	printf("Fatorial quadruplo de %d: %.2f", n, 2*fatorialQuad(n)/fatorialQuad(n));
}

float fatorialQuad(int n){
	if(n==1){
		return n;
	}
	return n*fatorialQuad(n-1);
}