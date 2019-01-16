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

int main(){
	int meusocket;
	int conecta;

	struct sockaddr_in alvo; //Estrutura responsavel pela conexao com a internet. Deve ser declarada como sockaddr

	meusocket = socket(AF_INET, SOCK_STREAM, 0); 
	/*Primeiro parametro: Familia do socket (AF_NET: Arpa net e internet protocols)
	Terceiro parametro: protocolo IP;*/

	alvo.sin_family = AF_INET;
	alvo.sin_port = htons(80);
	alvo.sin_addr.s_addr = inet_addr("192.168.0.1");

	conecta = connect(meusocket, (struct sockaddr *)&alvo, sizeof alvo);

	if(conecta==0){
		printf("Porta aberta\n");
		close(meusocket);
		close(conecta);
	} 
	else{
		printf("Porta fechada");

	}
}