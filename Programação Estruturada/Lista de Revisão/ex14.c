#include <stdio.h>
#include <stdlib.h>
float calculaExponenciacao(int x, int y);

int main(){
    int x, y;
    printf("Informe um numero 'x':");
    scanf("%d", &x);
    system("clear || cls");
    printf("Informe um numero 'y'");
    scanf("%d", &y);
    system("clear || cls");
    printf("%d elevado a %d e: %.3f",x,y, calculaExponenciacao(x, y));
}
float calculaExponenciacao(int x, int y){
    int cont;
    float resul;
    
    if(y==0){
        return 1;
    }
    else if(y>0){
        resul=x;
        for(cont=1; cont<y; cont++){
            resul*=x;
        }
    }
    else{
        resul=1.0/x;
        //printf("Resul%.2f\n", resul);
        for(cont=-1; cont>y; cont--){
            resul*=1.0/x;
        }
    }
    return resul;
    
}
