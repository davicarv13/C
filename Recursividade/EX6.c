#include <stdio.h>
#include <stdlib.h>

int MDC(int n, int m);

int main(){
	int n, m;

	system("clear || cls");

	printf("Informe um numero:");
	scanf("%d", &n);
	getchar();
	printf("Informe outro numero:");
	scanf("%d", &m);

	printf("MDC entre %d e %d: %d", n, m, MDC(n,m));
}

int MDC(int n, int m){
	if(n==m){
		return n;
	}
	if(n<m){
		return MDC(n, m);
	}
	MDC(n-m, m);
}