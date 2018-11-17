#include <stdio.h>

void escadinha(int);
int main(){
	int n;
	printf("Informe um numero:");
	scanf("%d", &n);
	escadinha(n);
}

void escadinha(int n){
	int cont, cont2, cont3;
	for(cont=1; cont<=n+1; cont++){
		for(cont2=1; cont2<=cont3; cont2++){
			printf("%d", cont3);
		}
		printf("\n");
		cont3++;
	}
}
