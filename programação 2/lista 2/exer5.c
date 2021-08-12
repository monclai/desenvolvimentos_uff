#include <stdio.h>

void imprime_binario(int n);

int main(){
	printf("converso de decimal para binario\n");
	int n;
	printf("digite o numero a ser convertido ");
	scanf("%d", &n);
	imprime_binario(n);
}

void imprime_binario(int n){
	if(n>=1){
		imprime_binario(n/2);
		printf("%d", n%2);
	}
}
