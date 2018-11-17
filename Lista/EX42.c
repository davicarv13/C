#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 3
int main(){
	int cont=0, h=0, m=0;
	char i, nome[40];
	for(cont=0;cont<MAX; cont++){
		printf("Informe o nome\n:");
		scanf("%s", nome);
		printf("Informe o sexo[H/M]\n:");
		scanf("%s", &i);
		i=tolower(i);

		while((i!='h')&&(i!='m')){
			printf("Sexo inválido! Informe sexo válido[H/M]");
			scanf("%s", &i);
		}
		if(i=='h'){
			h++;
		}
		else{
			m++;
		}
		
	}
	printf("Homens:%i\n", h);
	printf("Mulheres:%i\n", m);
	
}
