#include <stdio.h>
int main(){
	int n, *ptrn;
	n=5;
	ptrn=&n;
	printf("Valor de n a partir de ptrn:%d\n", *ptrn);
	printf("Endereco de n:%p\n", &n);
	printf("Valor de ptrn:%p\n", ptrn);
}
