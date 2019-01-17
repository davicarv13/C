#include <stdio.h>
#include <math.h>

int somaCubos(int n);

int main(){
	int n;

	printf("Informe um numero:");
	scanf("%d", &n);

	printf("Soma dos cubos de 1 ate %d: %d", n, somaCubos(n));
}

int somaCubos(int n){
	static int i=1;
	static int soma_cubos=0;
	
	soma_cubos+=pow(i, 3);

	if(i==n){
		return soma_cubos;
	}

	i++;
	somaCubos(n);
}