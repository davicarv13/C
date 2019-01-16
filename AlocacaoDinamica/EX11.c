#include <stdio.h>
#include <stdlib.h>

struct pessoa{
	int idade;
	char nome[50];
};

int main(int argc, char *argv[]){

	struct pessoa *p1;


	p1=calloc(2, sizeof(p1));

	p1[0].idade=21;
	p1[1].idade=18;

	printf("%d\n", p1[0].idade);
	printf("%d", p1[1].idade);
}