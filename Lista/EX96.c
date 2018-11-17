#include <stdio.h>
#include <STdlib.h>
char posNeg(float);
int main(){
	float n1;
	char resul;
	printf("Informe um numero:");
	scanf("%f", &n1);
	getchar();
	system("clear || cls");
	resul=posNeg(n1);
	if(resul=='P'){
		printf("Argumento postivo");
	}	
	else{
	printf("Argumento nulo ou negativo");
	}
}
char posNeg(float n1){
	if(n1>0){
		return 'P';
	}
	else{
		return 'N';
	}
}
