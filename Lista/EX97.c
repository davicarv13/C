#include <stdio.h>
#include <STdlib.h>
void somaImposto(float *, float);
int main(){
	float taxaImposto, custo;
	printf("Informe o custo do produto:");
	scanf("%f", &custo);
	getchar();
	system("clear || cls");
	printf("Informe a taxa relativa ao imposto:");
	scanf("%f", &taxaImposto);
	getchar();
	system("clear || cls");
	somaImposto(&custo, taxaImposto);
	printf("Preco final:%.2f", custo);
}
void somaImposto(float *custo, float taxaImposto){
	*custo+=(((*custo) * taxaImposto)/100);
}
