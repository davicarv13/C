#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 1

typedef struct{
	int codigo;
	int quantidade;
	float preco;
	char nome[15];
}Produto;

void lp();
void leProdutos(Produto *produtos);
void pedido(Produto *produtos);

int main(){
	Produto *produtos=malloc(TAM*sizeof(Produto));
	leProdutos(produtos);
	pedido(produtos);

	free(produtos);
	produtos=NULL;
}

void lp(){
	system("clear || cls");
}

void leProdutos(Produto *produtos){
	int i;

	lp();

	printf("Produtos:\n");

	for(i=0; i<TAM; i++){
		printf("Informe o nome:");
		scanf("%[^\n]s", produtos[i].nome);
		getchar();
		printf("Informe o código:");
		scanf("%d", &produtos[i].codigo);
		getchar();
		printf("Informe o preço:");
		scanf("%f", &produtos[i].preco);
		getchar();
		printf("Informe a quantidade em estoque:");
		scanf("%d", &produtos[i].quantidade);
		getchar();
		lp();
	}
}

void pedido(Produto *produtos){
	int cod=1, quant, i, teste;

	printf("Pedidos: (Informe '0' para parar)\n");

	do{
		printf("Informe o código do produtos:");
		scanf("%d", &cod);
		getchar();
		if(cod==0){
			lp();
			printf("Programa encerrado!\n");
			break;
		}
		printf("Informe a quantidade:");
		scanf("%d", &quant);

		teste=0;

		for(i=0; i<TAM; i++){
			if(produtos[i].codigo==cod){
				teste=1;
				if(produtos[i].quantidade>=quant){
					lp();
					printf("Pedido realizado!\n\n");
					produtos[i].quantidade=produtos[i].quantidade-quant;
				}
				else{
					lp();
					printf("Pedido não realizado! Quantidade de produtos em estoque insuficiente!\n\n");
				}
			}
		}
		if(teste==0){
			lp();
			printf("Código informado não corresponde a nenhum produto em estoque!\n\n");
		}
	}while(cod!=0);
}
