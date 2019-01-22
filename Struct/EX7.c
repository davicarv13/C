#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct lista{
	int id;
	struct lista* proximo;
};

typedef struct lista Lista;
int main(){

	system("clear || cls");

	srand((unsigned)time(NULL));

	Lista *gancho, l1, l2, l3;

	l1.proximo=&l2;
	l2.proximo=&l3;
	l3.proximo=(Lista *)0;

	for(gancho=&l1; gancho!=NULL; gancho=gancho->proximo){
		gancho->id=rand()%10+1;
	}
	printf("IDs\n");
	for(gancho=&l1; gancho!=NULL; gancho=gancho->proximo){
		printf("%d\n", gancho->id);
	}
}