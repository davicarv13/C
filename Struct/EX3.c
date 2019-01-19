#include <stdio.h>
#include <stdlib.h>

int main(){
	typedef struct{
		int idade;
		char nome[20], endereco[40];
	}Pessoa;

	Pessoa *p1=malloc(sizeof(Pessoa));

	printf("Informe a idade:");
	scanf("%d", &p1->idade);

	getchar();

	system("clear || cls");

	printf("Informe o nome:");
	scanf("%[^\n]s", p1->nome);

	getchar();

	system("clear || cls");

	printf("Informe o endereco:");
	scanf("%[^\n]s", p1->endereco);

	printf("Nome:%s\n", p1->nome);
	printf("Idade:%d\n", p1->idade);
	printf("Endereco:%s\n", p1->endereco);

	free(p1);
	p1=NULL;		
}