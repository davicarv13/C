#include <stdio.h>
#include <stdlib.h>

float sequencia(int n, int i);

int main(){
	int n;
	printf("Informe um numero N:");
	scanf("%d", &n);
	int i=n;
	printf("Sequencia:%.2f", sequencia(n , i));
}

float sequencia(int n, int i){
	if(i==1){
		return 1;
	}
	return 1.0/i+sequencia(n, --i);
}
