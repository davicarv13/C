#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 40

//Identificador de SO
void soId()
{
	#ifdef LINUX
	__fpurge(stdin);
	#elif defined WIN32
	fflush(stdin);
	#else
	#error Plataforma nao suportada
	#endif	
}

int main(){
    int somaId=0, somaIdH=0, numM=0, numH=0, cont=0, idade;
    float mediaId, mediaIdH;
    char nome[40], sexo;
    for(cont=0; cont<MAX; cont++){
        system("clear || cls");
        printf("Informe o nome:");
        fgets(nome, 40, stdin);
        printf("Informe o sexo[H/M]:");
        sexo=getchar();
        sexo=tolower(sexo);
        printf("%c", sexo);
        while(sexo!='h' && sexo!='m'){
        	soId();
            printf("Sexo invalido!\n");
            printf("Informe o sexo[H/M]:");
            sexo=getchar();
            sexo=tolower(sexo);
        }
        printf("Informe a idade:");
        scanf(" %i", &idade);
        while(idade<0){
            printf("Idade invalida!\n");
            printf("Informe a idade:");
            scanf("%i", &idade);
        }
        somaId+=idade;
        if(sexo=='h'){
            somaIdH+=idade;
            numH++;
        }
        else{
            numM++;
        }
        soId();
    }
    mediaId=(float)somaId/MAX;
    mediaIdH=(float)somaIdH/numH;
    system("clear || cls");
    printf("Media das idades:%.2f\n", mediaId);
    printf("Media das idades dos homens:%.2f\n", mediaIdH);
    printf("Numero de mulheres:%i", numM);
}

//https://onlinegdb.com/HkPOo7AE7