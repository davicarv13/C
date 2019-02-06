#include <stdio.h>
#include <stdlib.h>

int potencia(int base, int expoente);

int main(){
	int base, expoente;

	printf("Informe um numero base:");
	scanf("%d", &base);
	getchar();
	printf("Informe uma potencia:");
	scanf("%d", &expoente);
	getchar();

	system("clear || cls");

	printf("%d elevado a %d: %d\n", base, expoente, potencia(base, expoente));

}

int potencia(int base, int expoente){
	if(expoente==0){
		return 1;
	}
	static int i=0;
	static int mult=1;

	if(i==expoente){
		return mult;
	}
	else{
		i++;
		mult*=base;
		potencia(base, expoente);
	}
}

/*int calculaPotencia(int x, int n){
	if(n==0){
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
	
}*/