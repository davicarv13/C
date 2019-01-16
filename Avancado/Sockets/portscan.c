#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

//Headers para sockets
#include <arpa/inet.h>
#include <sys/signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

//Argumentos para passar IPs no momento da compilação do código
int main(int argc, char* argv[]){
	int meusocket;
	int conecta;

	int port;
	int inicio = 0;
	int final = 65535; //Número de portas TCP/IP existentes

	char *destino;
	destino = argv[1]; //Destino recebe o numero de IP passado como argumento para main

	struct sockaddr_in alvo; //Estrutura responsavel pela conexao com a internet. Deve ser declarada como sockaddr

	for(port=inicio; port<final; port++){

		meusocket = socket(AF_INET, SOCK_STREAM, 0); 
		/*Primeiro parametro: Familia do socket (AF_NET: Arpa net e internet protocols)
		Terceiro parametro: protocolo IP;*/

		alvo.sin_family = AF_INET;
		alvo.sin_port = htons(port);
		alvo.sin_addr.s_addr = inet_addr(destino);

		conecta = connect(meusocket, (struct sockaddr *)&alvo, sizeof alvo);

		if(conecta==0){
			printf("Porta %d status [ABERTA]. \n", port);
			close(meusocket);
			close(conecta);
		} 
		else{
			//printf("Porta %d status.\n", porta);
			close(meusocket);
			close(conecta);
		}
	}
}