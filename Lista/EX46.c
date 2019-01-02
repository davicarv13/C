#include <stdio.h>
#include <stdlib.h>

int menu(void);
void deposito(float*);
void retirada(float*);
void saldo(float*);

int main(void){
    int resp=0;
    float conta=0;
    resp=menu();
    while(resp!=4){
        switch(resp){
            case 1:
                deposito(&conta);
            break;
            case 2:
            	if(conta==0){
            		system("clear || cls");
            		printf("Conta vazia!\n");
				}
				else{
					 retirada(&conta);
				}
            break;
            case 3:
                saldo(&conta);
            break;
        }
        resp=menu();
    }
    
}

int menu(void){
    int resp2=0;
    do{
        printf("1- Deposito:\n");
        printf("2- Retirada:\n");
        printf("3- Saldo:\n");
        printf("4- Sair do programa:\n");
        scanf("%i", &resp2);
        if(resp2!=1 && resp2!=2 && resp2!=3 && resp2!=4){
            system("cls || clear");
            printf("Resposta invalida!\n");
            
        }
    }while(resp2!=1 && resp2!=2 && resp2!=3 && resp2!=4);
    return resp2;
}

void deposito(float *conta){
    float valor;
    system("clear || cls");
    printf("Informe o valor a ser depositado:");
    scanf("%f", &valor);
    while(valor<0){
        printf("Valor invalido!\n");
        printf("Informe o valor a ser depositado:");
        scanf("%f", &valor);
    }
    *conta+=valor;
    system("clear || cls");
}

void retirada(float *conta){
    float valor;
    system("clear || cls");
    printf("Informe o valor a ser retirado:");
    scanf("%f", &valor);
    while(valor<0 || valor>*conta){
        if(valor<0){
            printf("Valor invalido!\n");
            printf("Informe o valor a ser retirada:");
            scanf("%f", &valor);
        }
        else{
            printf("Saldo menor do que o valor a ser retirado! (%.2f)\n", *conta);
            printf("Informe o valor a ser retirado (Menor que %.2f):\n", *conta);
            scanf("%f", &valor);
        }
    }
    *conta-=valor;
    system("clear || cls");
}

void saldo(float *conta){
    system("clear || cls");
    printf("Saldo atual:%.2f\n\n", *conta);
}

//https://onlinegdb.com/Bkj6seTEX
