#include <stdio.h>

int somaInteracao(int a, int b);

int main(){
	int a, b;	

	printf("Informe dois valores:");
	scanf("%d%d", &a, &b);
	printf("Soma de %d com %d: %d\n", a, b, somaInteracao(a, b));
}

int somaInteracao(int a, int b){
	static int i=0;

	if(i==b){
		return a;
	}

	i++;
	somaInteracao(++a, b);
}