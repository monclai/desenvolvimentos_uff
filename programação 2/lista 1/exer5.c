#include <stdio.h>

void fibonnaci(int term);
int main(){
    int termos;
    printf("calcular fibonnaci\n");
    printf("------------------\n");
    printf("digite a quantidade de termos: ");
    scanf("%d", &termos);
    fibonnaci(termos);
}

void fibonnaci (int term){
    int fibo1 =0, fibo2=1, fibonac = 0, x;
    if (term == 1)
        printf("1 ");
    else{
        printf("1 ");
        for(x=0; x<term-1; x++){
            fibonac = fibo1 + fibo2;
            fibo1 = fibo2;
            fibo2 = fibonac;
            printf("%d ", fibonac);
        }
    }
}
