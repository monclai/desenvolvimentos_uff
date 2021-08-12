#include <stdio.h>

int main(){
	printf("imprimir a soma dos números múltiplos de 5 no intervalo aberto entre 1 e num\n");
	int num, x, soma = 0;
	printf("digite um numero: ");
	scanf("%d", &num);
	for(x=1; x<=num; x++){
		if (x%5==0)
			soma += x;			
	}
	printf("a soma e %d\n", soma);
}
