#include <stdio.h>

int calculaPotencia(int x, int n);

int main(){
	int x, n;

	printf("Informe a base:");
	scanf(" %d", &x);
	getchar();
	printf("Informe a potencia:");
	scanf(" %d", &n);
	printf("%d elevado a %d: %d", x, n, calculaPotencia(x, n));
}

int calculaPotencia(int x, int n){
	if(n==00){
		return 1;
	}
	else{
		if(n==1){
		return x;
	}
		else{
			return x*calculaPotencia(x, n-1);
		}	
	}
	
}