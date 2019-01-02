#include <stdio.h>
int main(){
	int n, m, *ptrn, *ptrm;
	n=5;
	m=3;
	ptrn=&n;
	ptrm=&m;
	if(*ptrn>*ptrm){
		printf("Maior:%d", *ptrn);
	}
	else if(*ptrm>*ptrn){
		printf("Maior:%d", *ptrm);
	}
	else{
		printf("Sao iguais");
	}
}
