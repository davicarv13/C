#include <stdio.h>
#include <ctype.h>
#include <string.h>

void stringVert(char *);

int main(){
	char string1[50];
	printf("Informe uma palavra:");
	fgets(string1, 50, stdin);
	//stringVert(string1);
	int cont=0, tam;
	tam=strlen(string1);
	for(; cont<tam;cont++){
		string1[cont]=toupper(string1[cont]);
		printf("%c\n");
	}
}

/*void stringVert(char *string1){
	int cont=0, tam;
	tam=strlen(*string1);
	for(; cont<tam;cont++){
		string1[cont]=tolower(string1[cont]);
		printf("%c\n");
	}
	
}
*/
