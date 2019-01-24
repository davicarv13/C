#include <stdio.h>
#include <stdlib.h>

struct Livro{
    char titulo[30];
    char autor[15];
    int ano;
    struct Livro *prox;
};

typedef struct Livro livro;

int main(){
    livro *gancho, l1, l2, l3, l4, l5;

    char tituloProcura[15];
    int i, teste=0;

    l1.prox=&l2;
    l2.prox=&l3;
    l4.prox=0;
    l5.prox=0;

    for(gancho=&l1; gancho->prox!=0; gancho=gancho->prox){
    	system("clear || cls");
    	printf("Informe o titulo:");
    	scanf("%[^\n]s", gancho->titulo);
    	getchar();
    	printf("Informe o autor:");
    	scanf("%[^\n]s", gancho->autor);
    	getchar();
    	printf("Informe ano:");
    	scanf("%d", &gancho->ano);
    	getchar();
    }

    printf("Informe titulo a ser procurado:");
    scanf("%[^\n]s", tituloProcura);
    
    printf("Livros:\n\n");

    for(gancho=&l1; gancho->prox!=0; gancho=gancho->prox){
    	i=0;
    	teste=0;
    	while(gancho->titulo[i]!='\0' && tituloProcura[i]!='\0'){
    		if(gancho->titulo[i]!=tituloProcura[i]){
    			teste=1;
    			break;
    		}
    	}
    	if(teste!=1){
    		printf("- %s\n", gancho->titulo);
    	}
    }
}
