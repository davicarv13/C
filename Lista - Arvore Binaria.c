#include <stdio.h>
#include <stdlib.h>

struct reg_no{
	struct reg_no *esq;
	int dado;
	struct reg_no *dir;
};

typedef struct reg_no tipo_no;
typedef tipo_no **tipo_arvore;

tipo_no** criar_arvore(){
	return ((tipo_no**) malloc(sizeof(tipo_no*)));
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

//Ex164
void insereIterativo(tipo_no** sub_raiz, int dado){
	tipo_no* aux;
	tipo_no* novo = (tipo_no*)malloc(sizeof(tipo_no));
	novo->dado = dado;
	novo->esq = NULL;
	novo->dir = NULL;
	
	aux = *sub_raiz;
	
	if(*sub_raiz == NULL){
		*sub_raiz = novo;
	}
	else{
		while(aux != NULL){
			if(dado < aux->dado){
				if(aux->esq == NULL){
					aux->esq = novo;
					break;
				}
			    aux = aux->esq;
		    }
		    else{
			    if(dado > aux->dado){
				    if(aux->dir == NULL){
					    aux->dir = novo;
					    break;
				    }
				    aux = aux->dir;
			    }
		    }
	    }
	}
}

//Ex165
void listar_em_ordem(tipo_no** sub_raiz){
	if(*sub_raiz != NULL){
		listar_em_ordem(&((*sub_raiz)->esq));
		printf("%d ", ((*sub_raiz)->dado));
		listar_em_ordem(&((*sub_raiz)->dir));
	}
	
}

//Ex166
void listar_pre_ordem(tipo_no** sub_raiz){
	if(*sub_raiz != NULL){
		printf("%d ", ((*sub_raiz)->dado));
		listar_em_ordem(&((*sub_raiz)->esq));
		listar_em_ordem(&((*sub_raiz)->dir));
	}
	
}

//Ex167
void listar_pos_ordem(tipo_no** sub_raiz){
	if(*sub_raiz != NULL){
		listar_em_ordem(&((*sub_raiz)->esq));
		listar_em_ordem(&((*sub_raiz)->dir));
		printf("%d ", ((*sub_raiz)->dado));
	}
	
}

//Ex168
int verificaN(tipo_no** sub_raiz, int n)
{
      int direita, esquerda;
      if(*sub_raiz==NULL){
      	return 0;
      }
      if((*sub_raiz)->dado == n){
          return 1;
      }
      if(n < (*sub_raiz)->dado){
      	esquerda = verificaN(&(*sub_raiz)->esq, n);
      }
      else{
          direita = verificaN(&((*sub_raiz)->dir), n);
 
      }
      return esquerda+direita;
}




//Ex169
int retornaMaiorValor(tipo_no **sub_raiz){
	if(*sub_raiz != NULL){
		if((*sub_raiz)->dir != NULL){
			return retornaMaiorValor(&((*sub_raiz)->dir));
		}
		else{
			return (*sub_raiz)->dado;
		}
	}
}

//Ex170
int retornaMenorValor(tipo_no** sub_raiz){
	if(*sub_raiz != NULL){
		if((*sub_raiz)->esq != NULL){
			return retornaMenorValor(&((*sub_raiz)->esq));
		}
		else{
			return (*sub_raiz)->dado;
		}
	}
}

//Ex171
//Media

int excluirMaior(tipo_no **sub_raiz){
	tipo_no *auxiliar;
	int dado;
	
	if(*sub_raiz != NULL){
		if((*sub_raiz)->dir != NULL){
			return excluirMaior(&((*sub_raiz)->dir));
		}
		else{
			auxiliar = *sub_raiz;
			dado = (*sub_raiz)->dado;
			*sub_raiz = (*sub_raiz)->esq;
			free(auxiliar);
			return dado;
		}
	}
	return -1;
}

//Ex175
int contaNos(tipo_no** sub_raiz){
	if(*sub_raiz == NULL){
		return 0;
	}
	return contaNos(&((*sub_raiz)->esq)) + 1 + contaNos(&((*sub_raiz)->dir)); 
}

//Ex176
int numFolhas(tipo_no** sub_raiz){
	if(*sub_raiz == NULL){
		return 0;
	}
	else{
		if((*sub_raiz)->esq == (*sub_raiz)->dir){
			return 1;
		}
		else{
			return numFolhas(&((*sub_raiz)->esq)) + numFolhas(&((*sub_raiz)->dir));
	    }
	}
	
}

//Excluir de forma recursiva um elemento na arvore
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


//Realiza a busca recursiva por um elemento na arvore
tipo_no* contem(tipo_no** sub_raiz, int dado){
	if(*sub_raiz == NULL){
		return NULL;
	}
	if((*sub_raiz)->dado == dado){
		return *sub_raiz;
	}
	if(dado < (*sub_raiz)->dado){
		return (contem(&((*sub_raiz)->esq), dado));
	}
	else{
		if(dado > (*sub_raiz)->dado){
			return (contem(&((*sub_raiz)->dir), dado));
		}
	}
}

//Refeitas v2
int retornaMaiorValor2(tipo_no **sub_raiz){
	if((*sub_raiz)->dir == NULL){
		return (*sub_raiz)->dado;
	}
	else{
		return retornaMaiorValor2(&((*sub_raiz)->dir));
	}
}

int retornaMenorValor2(tipo_no **sub_raiz){
	if((*sub_raiz)->esq == NULL){
		return (*sub_raiz)->dado;
	}
	else{
		return retornaMenorValor2(&((*sub_raiz)->esq));
	}
}

int contaNos2(tipo_no** sub_raiz){
	if(*sub_raiz == NULL){
		return 0;
	}
	else{
		return contaNos2(&((*sub_raiz)->esq)) + contaNos2(&((*sub_raiz)->dir)) + 1;
	}
}

int contaNulls2(tipo_no** sub_raiz){
	if(*sub_raiz == NULL){
		return 1;
	}
	else{
		return contaNulls2(&((*sub_raiz)->esq)) + contaNulls2(&((*sub_raiz)->dir));
	}
}

int verificaN2(tipo_no **sub_raiz, int n){
	if(*sub_raiz == NULL){
		return 0;
	}
	if((*sub_raiz)->dado == n){
		return 1;
	}
	if(n < (*sub_raiz)->dado){
		return verificaN2(&((*sub_raiz)->esq), n);
	}
	else{
		if(n > (*sub_raiz)->dado){
			return verificaN2(&((*sub_raiz)->dir), n);
		}
	}
}


int main(){
	int result;
	tipo_arvore Arvore = NULL;
	Arvore = criar_arvore();
	
	insereRecursivo(Arvore, 5);
	insereRecursivo(Arvore, 3);
	insereRecursivo(Arvore, 7);
	insereRecursivo(Arvore, 1);
	insereRecursivo(Arvore, 4);
	insereRecursivo(Arvore, 8);
	insereRecursivo(Arvore, 10);

	listar_em_ordem(Arvore);
	printf("\n");
	listar_pre_ordem(Arvore);
	printf("\n");
	listar_pos_ordem(Arvore);
	printf("\n");
	
	printf("Maior valor: %d\n", retornaMaiorValor2(Arvore));
	printf("Menor valor: %d\n", retornaMenorValor2(Arvore));
	printf("Numero de nos:%d \n", contaNos2(Arvore));
	printf("Numero de NULLs: %d\n", contaNulls2(Arvore));
	printf("Numero de folhas da arvore: %d\n", numFolhas(Arvore));	
	int n = 2;
	if(verificaN2(Arvore, n) == 1){
		printf("Valor %d existe na arvore\n", n);
	}
	else{
		printf("Valor %d nao existe na arvore\n", n);
	}
}

    
