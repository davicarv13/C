//Gerador de arquivos

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraArquivo(FILE *, int n);
/*void geraArquivoB(FILE *arqA);
void geraArquivoC(FILE *arqA);
void geraArquivoD(FILE *arqA);*/

int main(){
	FILE *arqA, *arqB, *arqC, *arqD;

	srand((unsigned)time(NULL));

	arqA=fopen("A.txt", "w");
	arqB=fopen("B.txt", "w");
	arqC=fopen("C.txt", "w");
	arqD=fopen("D.txt", "w");

	geraArquivo(arqA, 5000);
	geraArquivo(arqB, 10000);
	geraArquivo(arqC, 20000);
	geraArquivo(arqD, 30000);

	fclose(arqA);
	fclose(arqB);
	fclose(arqC);
	fclose(arqD);
}

void geraArquivo(FILE *arq, int n){
	int i;

	for(i=0; i<n; i++){
		fprintf(arq, "%d ", rand()%10000+1);
	}
}
/*void geraArquivoB(FILE *arqA){

}
void geraArquivoC(FILE *arqA){

}
void geraArquivoD(FILE *arqA){

}*/