#include <stdio.h>

int mdc(int a, int b);
int main(){
	printf("calcular mdc\n");
	int a, b;
	printf("digite o primeiro valor: ");
	scanf("%d", &a);
	printf("digite o segundo valor: ");
	scanf("%d", &b);
	printf("%d", mdc(a, b));
}

int mdc(int a, int b){
    int x;
    if(a<b){
        x=a;
        a=b;
        b=x;
    }
    
    if(a%b==0)
        return b;
    else{
      a=a%b;
      mdc(a, b);
    }
}

