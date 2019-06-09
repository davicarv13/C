#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct reg_no{

	char nome[30];
	int idade;
	struct reg_no *proximo;

}*lista_no;

typedef struct reg_inicio{
	lista_no inicio;
}*lista_inicio;

int menu();
void incluiInicio(lista_inicio lista, char* nome, int idade);
void excluiInicio(lista_inicio lista);
void listar(lista_inicio lista);

int main(){

	system("clear || cls");

	int op, idade;

	char nome[30];

	lista_inicio lista = malloc(sizeof(lista));
	lista->inicio = NULL;

	do{
		op = menu();
		switch(op){
			case 1:
				printf("Informe um nome:");
				scanf("%[^\n]s", nome);
				getchar();
				printf("Informe a idade:");
				scanf("%d", &idade);
				getchar();
				incluiInicio(lista, nome, idade);
			break;

			case 2:
				excluiInicio(lista);
			break;

			case 3:
				listar(lista);
			break;

			default:
				op = 0;
			break;
		}
	}while(op!=0);
}

int menu(){
	int op;
	printf("%-20s \t %d\n", "Incluir Inicio", 1);
	printf("%-20s \t %d\n", "Excluir Inicio", 2);
	printf("%-20s \t %d\n", "Listar", 3);
	printf("%-20s \t %d\n", "Sair", 0);
	scanf("%d", &op);
	getchar();
	
	return op;
}
void incluiInicio(lista_inicio lista, char* nome, int idade){
	lista_no novo = malloc(sizeof(novo));
	strcpy(novo->nome, nome);
	novo->idade = idade;
	novo->proximo = lista->inicio;
	lista->inicio = novo;
	printf("%s - %d\n", novo->nome, novo->idade);
}
void excluiInicio(lista_inicio lista){
	if(lista->inicio != NULL){
		lista_no auxiliar;
		auxiliar = lista->inicio;
		lista->inicio = lista->inicio->proximo;
		free(auxiliar);
		auxiliar = NULL;
	}
	else{
		printf("Lista vazia!\n");
	}
	
}
void listar(lista_inicio lista){
	lista_no atual;	

	atual = lista->inicio;
	if(atual != NULL){
		while(atual != NULL){
			printf("%s - %d\n", atual->nome, atual->idade);
			atual = atual->proximo;
		}
		printf("\n");
	}
	else{
		printf("Lista vazia!\n");
	}
}	