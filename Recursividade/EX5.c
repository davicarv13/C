#include <stdio.h>
#include <stdlib.h>

int converteBin(int n);

int main(){
	int n;
	system("clear || cls");
	printf("Informe um numero n positivo(Base decimal):");
	scanf("%d", &n);
	printf("Binario:");
	converteBin(n);
	printf("\n\n");
}

int converteBin(int n){
	if(n<2){
		printf("%d", 1);
	}
	else{
		converteBin(n/2);
		printf("%d", n%2);
	}
}