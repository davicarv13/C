#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindromo(char *palavra, int esq, int dir);

int main(){
	system("clear || cls");
	char palavra[10];
	int esq=0, dir;
	printf("Informe uma palavra:");
	scanf("%s", palavra);
	dir=strlen(palavra)-1;
	if((palindromo(palavra, esq, dir))==1){
		printf("Nao e palindromo\n");
	}
	else{
		printf("E palindromo\n");
	}
}

int palindromo(char *palavra, int esq, int dir){
	if(esq>=dir){
		return 0;
	}
	if(palavra[esq]!=palavra[dir]){
		return 1;
	}
	palindromo(palavra, esq+1, dir-1);
}
