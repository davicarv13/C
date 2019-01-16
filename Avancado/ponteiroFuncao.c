#include <stdio.h>
#include <stdlib.h>

int executa(int (*ptr)(int, int), int x, int y);
int soma(int a, int b);
int max(int a, int b);

int main(){
	int a, b;
	printf("Digite dois numeros:");
	scanf("%d %d", &a, &b);
	printf("Maior: %d\n", executa(max, a, b));
	printf("Soma:%d\n", executa(soma, a, b));
}


int executa(int (*ptr)(int, int), int a, int b){
	return ptr(a, b);
}

int soma(int a, int b){
	return a+b;
}

int max(int a, int b){
	if(a>b){
		return a;
	}
	else if(a<b){
		return b;
	}
	else{
		return a || b;
	}
}