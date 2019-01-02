#include <stdio.h>
#include <stdlib.h>

int contaK(int n, int k, int *i);

int main(){
	int n, k, *i;

	(*i)=0;

	printf("Informe um numero N:");
	scanf("%d", &n);
	getchar();
	printf("Informe um numero k:");
	scanf("%d", &k);
	contaK(n, k, i);
	printf("Quantidade de %d em %d: %d", k, n, *i);
}

int contaK(int n, int k, int *i){
	if(n<=10){
		if(n==k){
			(*i)++;
		}	
		return 0;
	}
	else{
		if(n%10==k){
			(*i)++;
		}
		contaK(n/10, k, i);
	}
}