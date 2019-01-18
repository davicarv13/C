#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int SomaSerie(int i, int j, int k);

int main(){
	int i, j, k;

	setlocale(LC_ALL, "Portuguese");
	printf("Informe o começo da sequência:");
	scanf("%d", &i);
	printf("Informe o final da sequência:");
	scanf("%d", &j);
	printf("Informe o incremento:");
	scanf("%d", &k);

	printf("Soma da sequencia %d - %d, com incremento %d: %d\n", i, j, k, SomaSerie(i, j, k));
}

int SomaSerie(int i, int j, int k){
	static int soma=0;

	if(i>j){
		return soma;
	}

	soma+=i;

	i=i+k;

	SomaSerie(i, j, k);
}