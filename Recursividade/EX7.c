#include <stdio.h>
#include <stdlib.h>

int multiplicacao(int n, int m);

int main(){
	int n, m;
	printf("Informe um numero:");
	scanf("%d", &n);
	getchar();
	printf("Informe outro numero:");
	scanf("%d", &m);
	printf("Multiplicacao de %d por %d:%d", n, m, multiplicacao(n, m));
}

int multiplicacao(int n, int m){
	if(m==1){
		return n;
	}
	return n+multiplicacao(n, m-1);
}
