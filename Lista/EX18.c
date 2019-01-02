#include <stdio.h>
#include <stdlib.h>
int main(){
	int idade=0;
	printf("Informe a idadde do nadador:");
	scanf("%i", &idade);
	while(idade<5){
		printf("Idade inválida! Informe uma idade válida");
		scanf("%i", &idade);
	}
	switch(idade){
		case 5 ... 7:
			printf("Infantil A");
			break;
		case 8 ... 10:
			printf("Infantil B");
			break;
		case 11 ... 13:
			printf("Juvenil A");
			break;
		case 14 ... 17:
			printf("Juvenil B");
			break;
		default:
			printf("Adulto");
			break;
	}
	system("pause");
}
