#include <stdlib.h>
#include <stdio.h>
//#include "ArvoreBusca.h"
//#include "ArvoreBusca.c"

struct reg_no{
	struct reg_no *esq;
	int dado;
	struct reg_no *dir;
};

typedef struct reg_no tipo_no;
typedef tipo_no **tipo_arvore;

tipo_no** criaArvore();
void insereRecursivo(tipo_no** sub_raiz, int dado);
tipo_no* alocaNo(int dado);
void insereIterativo(tipo_no** sub_raiz, int dado);
void listarPreOrdem(tipo_no** sub_raiz); 
void listarPosOrdem(tipo_no** sub_raiz);
void listarEmOrdem(tipo_no** sub_raiz);
int verificaExistenciaValor(tipo_no** sub_raiz, int dado);
int retornaMaiorValor(tipo_no** sub_raiz);
int retornaMenorValor(tipo_no** sub_raiz);
int contaNumeroNos(tipo_no** sub_raiz);
float calculaMediaArvore(tipo_no** sub_raiz);
int retornaNulls(tipo_no** sub_raiz);
int somaValoresNos(tipo_no** sub_raiz);
int retornaMultiplosDeTres(tipo_no** sub_raiz);
int retornaNumeroDeFolhas(tipo_no** sub_raiz);
int retornaAltura(tipo_no** sub_raiz);
int verificaExtritamenteBinaria(tipo_no** sub_raiz);
int verificaArvoreBusca(tipo_no** sub_raiz);
int excluirMaior(tipo_no** sub_raiz);
int excluirMenor(tipo_no** sub_raiz);
void excluir(tipo_no** sub_raiz, int dado);

int menu();

int main(){
	tipo_arvore Arvore;
	Arvore = NULL;
	int maiorValor;
	int menorValor;

	Arvore = criaArvore();
	int op;
	int dado;

	insereRecursivo(Arvore, 10);
	insereRecursivo(Arvore, 8);
	insereRecursivo(Arvore, 5);
	insereRecursivo(Arvore, 9);
	insereRecursivo(Arvore, 12);
	insereRecursivo(Arvore, 11);
	insereRecursivo(Arvore, 15);

	do{
		op = menu();
		switch(op){
			case 1:
				printf("Informe um numero:\n");
				scanf("%d", &dado);
				getchar();
				insereRecursivo(Arvore, dado);
			break;
			case 2:
				printf("Informe um numero:\n");
				scanf("%d", &dado);
				getchar();
				insereIterativo(Arvore, dado);
			break;
			case 3:
				listarPreOrdem(Arvore);
			break;
			case 4:
				listarPosOrdem(Arvore);
			break;
			case 5:
				listarEmOrdem(Arvore);
			break;
			case 6:
				printf("Informe um numero:\n");
				scanf("%d", &dado);
				getchar();
				if(verificaExistenciaValor(Arvore, dado) == 1){
					printf("%d existe na arvore\n", dado);
				}
				else{
					printf("%d nao existe na arvore\n", dado);	
				}
			break;
			case 7:
				maiorValor = retornaMaiorValor(Arvore);
				if(maiorValor == -1){
					printf("Arvore vazia\n");
				}
				else{
					printf("Maior valor da arvore: %d\n", maiorValor);	
				}
			break;
			case 8:
				menorValor = retornaMenorValor(Arvore);
				if(menorValor == -1){
					printf("Arvore vazia\n");
				}
				else{
					printf("Menor valor da arvore: %d\n", menorValor);	
				}
			break;

			case 9:
				printf("Media dos valores da arvore:%.2f\n", calculaMediaArvore(Arvore));
			break;

			case 10:
				printf("Numero de NULLs na arvore: %d\n", retornaNulls(Arvore));
			break;
			case 11:
				printf("Soma dos valores dos nos: %d\n", somaValoresNos(Arvore));
			break;
			case 12:
				printf("Numero de multiplos de tres na arvore: %d\n", retornaMultiplosDeTres(Arvore));
			break;
			case 13:
				printf("Numero de nos na arvore: %d", contaNumeroNos(Arvore));
			break;
			case 14:
				printf("Numero de folhas na arvore: %d", retornaNumeroDeFolhas(Arvore));
			break;
			case 15: 
				printf("Altura da arvore: %d", retornaAltura(Arvore));
			break;
			case 16:
				if(verificaExtritamenteBinaria(Arvore) == 1){
					printf("Arvore extritamente binaria\n");
				}
				else{
					printf("Arvore nao e extritamente binaria\n");	
				}
			break;
			case 17:
				if(verificaArvoreBusca(Arvore) == 1){
					printf("Arvore e de busca\n");
				}
				else{
					printf("Arvore nao e de busca\n");	
				}
			break;
			case 18:
				maiorValor = excluirMaior(Arvore);
				if(maiorValor == -1){
					printf("Lista vazia\n");
				}
				else{
					printf("Numero apagado: %d\n", maiorValor);	
				}
				
			break;
			case 19:
				menorValor = excluirMenor(Arvore);
				if(menorValor == -1){
					printf("Lista vazia\n");
				}
				else{
					printf("Numero apagado: %d\n", menorValor);	
				}
			break;
			case 20:
				printf("Informe um numero:\n");
				scanf("%d", &dado);
				getchar();
				excluir(Arvore, dado);
				listarEmOrdem(Arvore);
			break;

		}

	}while(op != 0);
}

int menu(){
	int op;
	printf("\n1 - Insere Recursivo\n");
	printf("2 -  Insere Iterativo\n");
	printf("3 -  Listar Pre Ordem\n");
	printf("4 -  Listar Pos Ordem\n");
	printf("5 -  Listar Em Ordem\n");
	printf("6 -  Verifica existencia de um valor na arvore\n");
	printf("7 -  Retorna maior valor da arvore\n");
	printf("8 -  Retorna menor valor da arvore\n");
	printf("9 -  Calcula media dos valores da arvore\n");
	printf("10 - Retorna numero de NULLs\n");
	printf("11 - Retorna soma dos valores dos nos\n");
	printf("12 - Retorna numero de multiplos de tres\n");
	printf("13 - Retorna numero de nos da arvore\n");
	printf("14 - Retorna numero de folhas da arvore\n");
	printf("15 - Retorna altura da arvore\n");
	printf("16 - Verifica arvore extritamente binaria\n");
	printf("17 - Verifica arvore de busca\n");
	printf("18 - Excluir maior numero\n");
	printf("19 - Excluir menor numero\n");
	printf("20 - Excluir um numero N\n");
	printf("0 - Sair\n");
	scanf("%d", &op);
	return op;
}

tipo_no** criaArvore(){
	return (tipo_no**)malloc(sizeof(tipo_no*));
}

//Ex164
void insereRecursivo(tipo_no** sub_raiz, int dado){
	if(*sub_raiz == NULL){
		*sub_raiz = (tipo_no*)malloc(sizeof(tipo_no));
		(*sub_raiz)->dado = dado;
		(*sub_raiz)->esq = NULL;
		(*sub_raiz)->dir = NULL;
	}
	else{
		if(dado < (*sub_raiz)->dado){
			insereRecursivo(&((*sub_raiz)->esq), dado);
		}
		else{
			if(dado > (*sub_raiz)->dado){
				insereRecursivo(&((*sub_raiz)->dir), dado);
			}
		}
	}
}

tipo_no* alocaNo(int dado){
	tipo_no* no;
	no = (tipo_no*)(malloc(sizeof(tipo_no)));
	no->dado = dado;
	no->esq = NULL;
	no->dir = NULL;
	return no;
}

void insereIterativo(tipo_no** sub_raiz, int dado){
	if(*sub_raiz == NULL){
		*sub_raiz = alocaNo(dado); //(tipo_no*)malloc(sizeof(tipo_no));
		/*(*sub_raiz)->dado = dado;
		(*sub_raiz)->esq = NULL;
		(*sub_raiz)->dir = NULL;*/
	}
	else{
		tipo_no* aux;
		aux = *sub_raiz;

		while(aux != NULL){

			if(dado < aux->dado){
				if(aux->esq == NULL){
						aux->esq = alocaNo(dado); //(tipo_no*)malloc(sizeof(tipo_no));
						/*aux->esq->dado = dado;
						aux->esq->esq = NULL;
						aux->esq->dir = NULL;*/
						break;
				}
				aux = aux->esq;
			}
			else{
				if(dado > aux->dado){
					if(aux->dir == NULL){
						aux->dir = alocaNo(dado); //(tipo_no*)malloc(sizeof(tipo_no));
						/*aux->dir->dado = dado;
						aux->dir->esq = NULL;
						aux->dir->dir = NULL;*/
						break;
					}
					aux = aux->dir;
				}
			}
		}
	}
}

//Ex165
void listarEmOrdem(tipo_no** sub_raiz){
	if(*sub_raiz == NULL){
		return;
	}
	else{
		listarEmOrdem(&((*sub_raiz)->esq));
		printf("%d ", (*sub_raiz)->dado);
		listarEmOrdem(&((*sub_raiz)->dir));
	}
}

//Ex166
void listarPreOrdem(tipo_no** sub_raiz){
	if(*sub_raiz == NULL){
		return;	
	}
	else{
		printf("%d ", (*sub_raiz)->dado);
		listarPreOrdem(&((*sub_raiz)->esq));
		listarPreOrdem(&((*sub_raiz)->dir));
	}
}

//167
void listarPosOrdem(tipo_no** sub_raiz){
	if(*sub_raiz == NULL){
		return;
	}
	else{
		listarPosOrdem(&((*sub_raiz)->esq));
		listarPosOrdem(&((*sub_raiz)->dir));
		printf("%d ", (*sub_raiz)->dado);
	}
}

//Ex168
int verificaExistenciaValor(tipo_no** sub_raiz, int dado){
	if(*sub_raiz == NULL){
		return 0;
	}
	else{
		if(dado == (*sub_raiz)->dado){
			return 1;
		}
		else{
			if(dado < (*sub_raiz)->dado){
				return verificaExistenciaValor(&((*sub_raiz)->esq), dado);
			}
			else{
				return verificaExistenciaValor(&((*sub_raiz)->dir), dado);	
			}
		}
	}
}

//Ex169
int retornaMaiorValor(tipo_no** sub_raiz){
	if(*sub_raiz == NULL){
		return -1;
	}
	else{
		if((*sub_raiz)->dir == NULL){
			return (*sub_raiz)->dado;
		}
		else{
			return retornaMaiorValor(&((*sub_raiz)->dir));
		}
	}
}

//Ex170
int retornaMenorValor(tipo_no** sub_raiz){
	if(*sub_raiz == NULL){
		return -1;
	}
	else{
		if((*sub_raiz)->esq == NULL){
			return (*sub_raiz)->dado;
		}
		else{
			return retornaMenorValor(&((*sub_raiz)->esq));
		}
	}
}

//Ex172
int retornaNulls(tipo_no** sub_raiz){
	if(*sub_raiz == NULL){
		return 1;
	}
	else{
		return retornaNulls(&((*sub_raiz)->esq)) + retornaNulls(&((*sub_raiz)->dir));
	}
}

//Ex173
int somaValoresNos(tipo_no** sub_raiz){
	if(*sub_raiz == NULL){
		return 0;
	}
	else{
		return somaValoresNos(&((*sub_raiz)->esq)) + somaValoresNos(&((*sub_raiz)->dir)) + (*sub_raiz)->dado;
	}
}

//Ex174
int retornaMultiplosDeTres(tipo_no** sub_raiz){
	if(*sub_raiz == NULL){
		return 0;
	}	
	else{	
		return retornaMultiplosDeTres(&((*sub_raiz)->esq)) + retornaMultiplosDeTres(&((*sub_raiz)->dir)) + ((*sub_raiz)->dado % 3 == 0);
	}	
}

//Ex175
int contaNumeroNos(tipo_no** sub_raiz){
	if(*sub_raiz == NULL){
		return 0;
	}
	else{
		return contaNumeroNos(&((*sub_raiz)->esq)) + 1 + contaNumeroNos(&((*sub_raiz)->dir));
	}	
}

//Ex171
float calculaMediaArvore(tipo_no** sub_raiz){
	float soma = 0;
	//int numeroNos = 0;
	if(*sub_raiz == NULL){
		return 0;
	}
	else{	
		//numeroNos += contaNumeroNos(&((*sub_raiz)->esq)) + contaNumeroNos(&((*sub_raiz)->dir)) + 1;
		soma += calculaMediaArvore(&((*sub_raiz)->esq)) + calculaMediaArvore(&((*sub_raiz)->dir)) + (*sub_raiz)->dado;	
	}

	return soma / contaNumeroNos(&(*sub_raiz));
}

//Ex176
int retornaNumeroDeFolhas(tipo_no** sub_raiz){ 
	if(*sub_raiz == NULL){
		return 0;
	}
	if((*sub_raiz)->esq == NULL && (*sub_raiz)->dir == NULL){
		return 1;
	}
	else{
		return retornaNumeroDeFolhas(&((*sub_raiz)->esq)) + retornaNumeroDeFolhas(&((*sub_raiz)->dir));
	}
}

//Ex177
int retornaAltura(tipo_no** sub_raiz){	

	int altEsq = 0;
	int altDir = 0;

	if(*sub_raiz == NULL){
		return -1;
	}
	else{
		altEsq += retornaAltura(&((*sub_raiz)->esq)) + 1; 
		altDir += retornaAltura(&((*sub_raiz)->dir)) + 1;
	}

	if(altEsq > altDir){
		return altEsq;
	}
	else if(altDir > altEsq){
		return altDir;
	}
	else{
		return altEsq;
	}
}

//Ex178
int verificaExtritamenteBinaria(tipo_no** sub_raiz){
	if(*sub_raiz == NULL){
		return 0;
	}
	else{
		if(((*sub_raiz)->esq == NULL && (*sub_raiz)->dir == NULL)){
			return 1;
		}
		else{
			return (verificaExtritamenteBinaria(&((*sub_raiz)->esq)) && verificaExtritamenteBinaria(&((*sub_raiz)->dir)));
		}
	}
}

//Ex182
int verificaArvoreBusca(tipo_no** sub_raiz){
	if(*sub_raiz == NULL){
		return 1;
	}
	else{
		if((*sub_raiz)->esq != NULL && (*sub_raiz)->dir != NULL){
			if((*sub_raiz)->dado <= (*sub_raiz)->esq->dado || (*sub_raiz)->dado >= (*sub_raiz)->dir->dado || (*sub_raiz)->esq->dado >= (*sub_raiz)->dir->dado){
				return 0;
			}
		}
		else if((*sub_raiz)->esq != NULL && (*sub_raiz)->dir == NULL){
			if((*sub_raiz)->dado <= (*sub_raiz)->esq->dado){
				return 0;
			}
		}
		else if((*sub_raiz)->esq == NULL && (*sub_raiz)->dir != NULL){
			if((*sub_raiz)->dado >= (*sub_raiz)->dir->dado){
				return 0;
			}
		}
		else{
			return 1;
		}
	}

	return (verificaArvoreBusca(&((*sub_raiz)->esq)) && verificaArvoreBusca(&((*sub_raiz)->dir)));
}


int excluirMaior(tipo_no** sub_raiz){
	if(*sub_raiz == NULL){
		return -1;
	}
	if((*sub_raiz)->dir == NULL){
		int dadoAux;
		tipo_no* aux;
		dadoAux = (*sub_raiz)->dado;
		aux = (*sub_raiz);
		*sub_raiz = (*sub_raiz)->esq;
		free(aux);
		return dadoAux;
	}
	else{
		return excluirMaior(&((*sub_raiz)->dir));
	}
}

int excluirMenor(tipo_no** sub_raiz){
	if(*sub_raiz == NULL){
		return -1;
	}
	if((*sub_raiz)->esq == NULL){
		int dadoAux;
		tipo_no* aux;
		dadoAux = (*sub_raiz)->dado;
		aux = (*sub_raiz);
		*sub_raiz = (*sub_raiz)->dir;
		free(aux);
		return dadoAux;
	}
	else{
		return excluirMenor(&((*sub_raiz)->esq));
	}
}

//Ex181
void excluir(tipo_no** sub_raiz, int dado){
	tipo_no *auxiliar;
    if (*sub_raiz != NULL)
    {
        if (dado < (*sub_raiz)->dado)
        {
            excluir(&((*sub_raiz)->esq), dado);
        }
        else
        {
            if (dado > (*sub_raiz)->dado)
            {
                excluir(&((*sub_raiz)->dir), dado);
            }
            else
            {
                if ((*sub_raiz)->esq == NULL)
                {
                    auxiliar = *sub_raiz;
                    *sub_raiz = (*sub_raiz)->dir;
                    free(auxiliar);
                }
                else
                {
                    if ((*sub_raiz)->dir == NULL)
                    {
                        auxiliar = *sub_raiz;
                        *sub_raiz = (*sub_raiz)->esq;
                        free(auxiliar);
                    }
                    else
                    {
                        (*sub_raiz)->dado = excluirMaior(&((*sub_raiz)->esq));
                    }
                }
            }
        }
    } 
}