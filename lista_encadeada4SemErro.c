#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct reg_no{

	int num;
	struct reg_no *proximo;

}*lista_no;

typedef struct reg_inicio{
	lista_no inicio;
}*lista_inicio;

int menu();
void incluiInicio(lista_inicio lista, int num);
void excluiInicio(lista_inicio lista);
void incluiFinal(lista_inicio lista, int num);
void excluiFinal(lista_inicio lista);

void insere_n_esima(lista_inicio lista, int n, int num);
void exclui_n_esima(lista_inicio lista, int n);

int retornaTamanho(lista_inicio lista);
void esvaziarLista(lista_inicio lista);
void listar(lista_inicio lista);

int main(){

	system("clear || cls");

	int op, num, tam, n;

	lista_inicio lista = malloc(sizeof(lista));
	lista->inicio = NULL;

	do{
		op = menu();
		switch(op){
			case 1:
				system("clear || cls");
				printf("Informe um numero:");
				scanf("%d", &num);
				getchar();
				incluiInicio(lista, num);
			break;

			case 2:
				system("clear || cls");
				excluiInicio(lista);
			break;

			case 3:
				system("clear || cls");
				printf("Informe um numero:");
				scanf("%d", &num);
				getchar();
				incluiFinal(lista, num);
			break;

			case 4:
				system("clear || cls");
				excluiFinal(lista);
			break;

			case 5:
				system("clear || cls");

				tam = retornaTamanho(lista);

				printf("Tamanho da lista: %d\n", tam);

				printf("Informe um numero:");
				scanf("%d", &num);
				getchar();
				if(tam == 0){
					printf("Lista vazia! Numero incluido no inicio\n");
					incluiInicio(lista, num);
				}
				else{
					printf("Informe uma posicao entre 1 e %d:", tam);
					scanf("%d", &n);
					getchar();
					while(n < 1 || n > tam){
						printf("Posicao invalida!\n");
						printf("Informe uma posicao entre 1 e %d:", tam);
						scanf("%d", &n);
						getchar();
					}
					insere_n_esima(lista, n, num);
				}
			break;

			case 6:
				system("clear || cls");
				tam = retornaTamanho(lista);
				printf("Tamanho da lista: %d\n", tam);
				if(tam == 0){
					printf("Lista vazia!\n");
				}
				else if(tam == 1){
					printf("Lista so contem um numero!\n");
					excluiInicio(lista);
				}

				else{
					printf("Informe uma posicao entre 1 e %d:", tam);
					scanf("%d", &n);
					getchar();
					while(n < 1 || n > tam){
						printf("Posicao invalida!\n");
						printf("Informe uma posicao entre 1 e %d:", tam);
						scanf("%d", &n);
						getchar();
					}
					exclui_n_esima(lista, n);
				}
			break;

			case 7:
				system("clear || cls");
				tam = retornaTamanho(lista);
				printf("Tamanho da lista: %d\n", tam);
			break;

			case 8:
				system("clear || cls");
				if(retornaTamanho(lista) == 0){
					printf("Lista vazia");
				}			
				else{
					esvaziarLista(lista);
				}
			break;

			case 9:
				system("clear || cls");
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
	printf("%-40s \t %d\n", "Incluir Inicio", 1);
	printf("%-40s \t %d\n", "Excluir Inicio", 2);
	printf("%-40s \t %d\n", "Incluir Final", 3);
	printf("%-40s \t %d\n", "Excluir Final", 4);
	printf("%-40s \t %d\n", "Inserir depois na n-esima posicao", 5);
	printf("%-40s \t %d\n", "Excluir n-esima posicao", 6);
	printf("%-40s \t %d\n", "Retorna tamanho", 7);
	printf("%-40s \t %d\n", "Esvaziar lista", 8);
	printf("%-40s \t %d\n", "Listar", 9);
	printf("%-40s \t %d\n", "Sair", 0);
	scanf("%d", &op);
	getchar();
	
	return op;
}
void incluiInicio(lista_inicio lista, int num){
	lista_no novo = malloc(sizeof(novo));
	novo->num = num;
	novo->proximo = lista->inicio;
	lista->inicio = novo;
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

void incluiFinal(lista_inicio lista, int num){
	if(lista->inicio != NULL){
		lista_no novo = malloc(sizeof(novo));
		lista_no auxiliar;
		lista_no atual;
		atual = lista->inicio;

		while(atual != NULL){
			auxiliar = atual;
			atual = atual->proximo;

			if(atual == NULL){
				auxiliar->proximo = novo;
				novo->proximo = NULL;
				novo->num = num;
			}
		}
	}
	else{
		incluiInicio(lista, num);
	}
}

void excluiFinal(lista_inicio lista){
	if(lista->inicio == NULL){
		printf("Lista vazia!\n");
	}
	else if(lista->inicio != NULL && lista->inicio->proximo != NULL){
		lista_no atual;
		lista_no auxiliar;

		atual = lista->inicio;

		while(atual != NULL){
			auxiliar = atual;
			atual = atual->proximo;

			if(atual->proximo == NULL){
				atual = NULL;
				free(atual);
				auxiliar->proximo = NULL;
			}

		}
	}
	else if(lista->inicio->proximo == NULL){
		lista->inicio = NULL;
		free(lista->inicio);
	}
	
}

void insere_n_esima(lista_inicio lista, int n, int num){
	lista_no atual;
	lista_no auxiliar;
	lista_no novo = malloc(sizeof(novo));
	novo->num = num;
	atual = lista->inicio;

	int i = 0;

	while(i !=  n){
		auxiliar = atual;

		i++;

		if(i==n){
			novo->proximo = auxiliar->proximo;
			auxiliar->proximo = novo;
		}
		atual = atual->proximo;
	}
}

void exclui_n_esima(lista_inicio lista, int n){
	lista_no atual;
	lista_no auxiliar;

	atual = lista->inicio;

	int i=0; 

	if(n==1){
		auxiliar = lista->inicio;
		lista->inicio = lista->inicio->proximo;
		free(auxiliar);
		auxiliar = NULL;
	}
	else{
		while(i != n){
			auxiliar = atual;

			i++;

			if(i+1 == n){
				auxiliar = atual->proximo;
				atual->proximo = atual->proximo->proximo;
				free(auxiliar);
				auxiliar = NULL;
				break;
			}		
			atual = atual->proximo;
		}	
	}
	
}

int retornaTamanho(lista_inicio lista){
	lista_no atual;

	atual = lista->inicio;

	int i = 0;

	if(atual != NULL){
		while(atual != NULL){
			i++;
			atual = atual->proximo;	
		}
	}
	else{
		return 0;
	}

	return i;
}

void esvaziarLista(lista_inicio lista){
	lista_no auxiliar;
	lista_no atual;

	atual = lista->inicio;

	int tam = retornaTamanho(lista);

	while(atual != NULL){

		auxiliar = atual;

		if(auxiliar->proximo->proximo == NULL){
			free(auxiliar->proximo); 
			auxiliar->proximo = NULL;
			if(lista->inicio->proximo == NULL){
				free(lista->inicio->proximo);
				lista->inicio = NULL;
				break;
			}
			else{
				atual = lista->inicio;
			}
		}
		else{
			atual = atual->proximo;
		}
	}	

	lista->inicio = NULL;
}

void listar(lista_inicio lista){
	lista_no atual;	

	atual = lista->inicio;
	if(atual != NULL){
		while(atual != NULL){
			printf("%d ", atual->num);
			atual = atual->proximo;
		}
		printf("\n");
	}
	else{
		printf("Lista vazia!\n");
	}
}	