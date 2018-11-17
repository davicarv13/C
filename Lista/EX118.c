#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 200

typedef struct {
char titulo[200];
int id;
char sinopse[2000];
char serie[6];
char atorPrincipal[200];
int alugado;
} Filmes[TAM];

void inserir(Filmes *, int *cont, int *id);
void remocao(Filmes *, int *cont, int *id);
void devolucao(Filmes *, int *cont, int *id);
void listarFilmes(Filmes *, int *cont, int *id);
void listarFilmesPorAtor(Filmes *, int *cont, int *id);
void aluguel(Filmes *, int *cont, int *id);

int menu(){
	int resp;
	printf("\t=========Locadora=========\n");
	printf("%-25s \t 1\n", "Inserir Livro");
	printf("%-25s \t 2\n", "Remocao de Filme");
	printf("%-25s \t 3\n", "Devolucao de Filme");
	printf("%-25s \t 4\n", "Listar Filmes Por Ator");
	printf("%-25s \t 5\n", "Listar Filmes");
	printf("%-25s \t 6\n", "Aluguel");
	printf("%-25s \t 7\n", "Sair");
	scanf("%d", &resp);
	getchar();
	return resp;
}

int main(){
	system("clear || cls");
	int resp, cont=0, id=1;
	Filmes vetFilmes;

	do{
		resp=menu();
		if(resp<1 || resp>7){
			resp=menu();
		}
		switch(resp){
			case 1:
				inserir(&vetFilmes, &cont, &id);
			break;
			case 2:
				remocao(&vetFilmes, &cont, &id);
			break;
			case 3:
				devolucao(&vetFilmes, &cont, &id);
			break;
			case 4:
				listarFilmesPorAtor(&vetFilmes, &cont, &id);
			break;
			case 5:
				listarFilmes(&vetFilmes, &cont, &id);
			break;
			case 6:
				aluguel(&vetFilmes, &cont, &id);
			break;
		}
	}while(resp!=7);
}
void inserir(Filmes *vetFilmes, int *cont, int *id){
	system("clear || cls");
	if(*cont==TAM){
		printf("Lista de Filmes vazia!\n");

	}
	else{
		printf("Informe o Titulo do Livro:");
		scanf("%[^\n]s", vetFilmes[*cont]->titulo);
		getchar();
		printf("Informe a Sinopse do Livro:");
		scanf("%[^\n]s", vetFilmes[*cont]->sinopse);
		getchar();
		printf("Informe a Serie do livro (Ouro, Prata ou Bronze):");
		scanf("%[^\n]s", vetFilmes[*cont]->serie);
		getchar();
		while((strcmp(vetFilmes[*cont]->serie, "Prata")!=0) && (strcmp(vetFilmes[*cont]->serie, "Ouro")!=0) && (strcmp(vetFilmes[*cont]->serie, "Bronze")!=0)){
			printf("Serie invalida!\n");
			printf("Informe a Serie do livro (Ouro, Prata ou Bronze):");
			scanf("%[^\n]s", vetFilmes[*cont]->serie);	
			getchar();
		}

		printf("Informe o ator principal do livro:");
		scanf("%[^\n]s", vetFilmes[*cont]->atorPrincipal);
		getchar();
		vetFilmes[*cont]->id=(*id);
		vetFilmes[*cont]->alugado=0;
		(*cont)++;
		(*id)++;
	}
}
void remocao(Filmes *vetFilmes, int *cont, int *id){
	system("clear || cls");
	if(*cont==0){
		printf("Lista de Filmes vazia!\n");
	}
	else{
		int i, idRemocao, teste=0;
		printf("Informe o id do livro:");
		scanf("%d", &idRemocao);
		getchar();
		for(i=0; i<(*cont); i++){
			if(vetFilmes[i]->id==idRemocao && vetFilmes[i]->alugado==0){
				strcpy(vetFilmes[i]->titulo, vetFilmes[(*cont)-1]->titulo);
				strcpy(vetFilmes[i]->sinopse, vetFilmes[(*cont)-1]->sinopse);
				strcpy(vetFilmes[i]->serie, vetFilmes[(*cont)-1]->serie);
				strcpy(vetFilmes[i]->atorPrincipal, vetFilmes[(*cont)-1]->atorPrincipal);
				vetFilmes[i]->alugado=vetFilmes[(*cont)-1]->alugado;
				vetFilmes[i]->id=vetFilmes[(*cont)-1]->id;
				teste=1;
				break;
			}
			else if(vetFilmes[i]->id==idRemocao && vetFilmes[i]->alugado==1){
				teste=2;
			}
		}
		if(teste==0){
			printf("Livro nao encontrado!\n");
		}
		else if(teste==2){
			printf("Livro se encontra alugado e nao pode ser removido!\n");
		}
		else{
			printf("Livro Removido!\n");
			(*cont)--;
		}
	}
}
void devolucao(Filmes *vetFilmes, int *cont, int *id){
	system("clear || cls");
	if(*cont==0){
		printf("Lista de filmes vazia!\n");

	}
	else{
		int idDevolucao, i, teste=0;
		printf("Informe o ID do livro:");
		scanf("%d", &idDevolucao);
		for(i=0; i<(*cont); i++){
			if(vetFilmes[i]->id==idDevolucao && vetFilmes[i]->alugado==1){
				vetFilmes[i]->alugado=0;
				teste=1;
			}
			else if(vetFilmes[i]->id==idDevolucao && vetFilmes[i]->alugado==0){
				teste=2;
			}
		}
		system("clear || cls");
		if(teste==0){
			printf("Livro nao encontrado!\n\n");
		}
		else if(teste==1){
			printf("Livro devolvido com sucesso!\n\n");
		}
		else{
			printf("Livro nao se encontra alugado no momento!\n\n");
		}
	}
}
void listarFilmes(Filmes *vetFilmes, int *cont, int *id){
	system("clear || cls");
	if(*cont==0){
		printf("Lista de filmes vazia!\n");

	}
	else{
		int i, j=1;
		printf("=========Lista de Filmes=========\n");
		for(i=0; i<(*cont); i++){
			printf("%-15s \t%d\n", "ID" , vetFilmes[i]->id);
			printf("%-15s \t%s\n", "Titulo", vetFilmes[i]->titulo);
			printf("%-15s \t%s\n", "Sinopse", vetFilmes[i]->sinopse);
			printf("%-15s \t%s\n", "Serie", vetFilmes[i]->serie);
			printf("%-15s \t%s\n", "Ator Principal", vetFilmes[i]->atorPrincipal);
			if(vetFilmes[i]->alugado==0){
				printf("%-15s \t%s\n\n", "Alugado", "Nao");
			}
			else{
				printf("%-15s \t%s\n\n", "Alugado", "Sim");	
			}
			j++;
		}
		printf("\n\n");	
	}
}
void listarFilmesPorAtor(Filmes *vetFilmes, int *cont, int *id){
	system("clear || cls");
	if(*cont==0){
		printf("Lista de filmes vazia!\n");

	}
	else{
		char nomeAtor[200];
		int teste=0, i;
		printf("Informe o nome do ator a ser pesquisado:");
		scanf("%[^\n]s", nomeAtor);
		getchar();
		printf("Filme em que %s participa:\n", nomeAtor);
		for(i=0; i<(*cont); i++){
			if(strcmp(nomeAtor, vetFilmes[i]->atorPrincipal)==0){
				printf("%-15s \t%d\n", "ID" , vetFilmes[i]->id);
				printf("%-15s \t%s\n", "Titulo", vetFilmes[i]->titulo);
				printf("%-15s \t%s\n", "Sinopse", vetFilmes[i]->sinopse);
				printf("%-15s \t%s\n", "Serie", vetFilmes[i]->serie);
				printf("%-15s \t%s\n", "Ator Principal", vetFilmes[i]->atorPrincipal);
				if(vetFilmes[i]->alugado==0){
					printf("%-15s \t%s\n\n", "Alugado", "Nao");
				}
				else{
					printf("%-15s \t%s\n\n", "Alugado", "Sim");	
				}
					teste=1;
			}
		}
		if(teste==0){
			printf("Nenhum filme que %s participe na lista!\n\n", nomeAtor);
		}
	}
}
void aluguel(Filmes *vetFilmes, int *cont, int *id){
	system("clear || cls");
	if(*cont==0){
		printf("Lista de filmes vazia!\n");

	}
	else{
		int idAluguel, i, teste=0;
		printf("Informe o ID do livro:");
		scanf("%d", &idAluguel);
		for(i=0; i<(*cont); i++){
			if(vetFilmes[i]->id==idAluguel && vetFilmes[i]->alugado==0){
				vetFilmes[i]->alugado=1;
				teste=1;
			}
			else if(vetFilmes[i]->id==idAluguel && vetFilmes[i]->alugado==1){
				teste=2;
			}
		}
		system("clear || cls");
		if(teste==0){
			printf("Livro nao encontrado!\n\n");
		}
		else if(teste==1){
			printf("Livro alugado com sucesso!\n\n");
		}
		else{
			printf("Livro indisponivel no momento!\n\n");
		}
		(*id)++;
	}
}
