#include <stdio.h>
#include <STdlib.h>
int mult(int, int);
int main(){
	int n1, n2;
	printf("Informe um numero:");
	scanf("%d", &n1);
	getchar();
	system("clear || cls");
	printf("Informe outro numero:");
	scanf("%d", &n2);
	getchar();
	system("clear || cls");
	printf("Multiplicacao entre %d e %d:%d",n1, n2, mult(n1, n2));
}
int mult(int n1, int n2){
	int cont, result;
	if(n1>=n2){
		for(cont=0; cont<n2; cont++){
			result+=n1;
		}
		return result;
	}
	else{
		for(cont=0; cont<n1; cont++){
			result+=n2;
		}
		return result;
	}
}
