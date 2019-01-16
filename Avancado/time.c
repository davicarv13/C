#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){
	float tempo;
	time_t t_ini, t_fim;

	int i, j;

	t_ini=time(NULL);

	struct tm *data_hora;

	time_t segundos;

	time(&segundos);

	data_hora=localtime(&segundos);

	printf("Segundos:%d\n", data_hora->tm_sec);
	printf("Minuto:%d\n", data_hora->tm_min);
	printf("Hora:%d\n", data_hora->tm_hour);
	printf("Dia:%d\n", data_hora->tm_mday);
	printf("Mes:%d\n", data_hora->tm_mon+1);
	printf("Ano:%d\n", data_hora->tm_year+1900);
	printf("Dia do ano:%d\n", data_hora->tm_yday+1);
	printf("Dia da semana:%d\n", data_hora->tm_wday);
	
	if(data_hora->tm_isdst){
		printf("Horario de verao");
	}
	else{
		printf("Nao esta no horario de verao");
	}

	tempo=difftime(t_fim, t_ini);
}