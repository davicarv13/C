#include <stdio.h>
#include <string.h>

void comparaString(char *, char *);
int main(){
	char string1[50], string2[50];
	printf("Informe uma palavra:");
	fgets(string1, 50, stdin);
	printf("Informe outra palavra:");
	fgets(string2, 50, stdin);
	comparaString(string1, string2);
}

void comparaString(char *string1, char *string2){
	int tam1, tam2, cont=0, comp=0;
	tam1=strlen(string1);
	tam2=strlen(string2);
	if(tam1!=tam2){
		comp++;
	}
	else{
		if(tam1>tam2){
			for(cont=0;cont<tam1;cont++){
				if(string1[cont]!=string2[cont]){
					comp++;
					
				}
			}
		}
		else{
			for(cont=0;cont<tam2;cont++){
				if(string1[cont]!=string2[cont]){
					comp++;
				}
			}
		}
	}
	if(comp==0){
		printf("Sao iguais");
	}
	else{
		printf("Nao sao iguais!");
	}
	
}
