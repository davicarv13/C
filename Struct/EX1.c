#include <stdlib.h>
#include <stdio.h>

int main(){

	int i;

	typedef struct{
		char nome[20];
		int idade;
	}pessoa;
	pessoa *d;
	d=malloc(3*sizeof(pessoa));

	for(i=0; i<3; i++){
		printf("Informe o nome:");
		scanf("%[^\n]s", d[i].nome);
		getchar();
		printf("Informe a idade:");
		scanf("%d", &d[i].idade);
		getchar();
	}
	for(i=0; i<3; i++){
		printf("Idade: %d\n", d[i].idade);
		printf("Nome: %s\n", d[i].nome);
	}
	free(d);
	d=NULL;
}