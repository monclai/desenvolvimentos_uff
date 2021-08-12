#include <stdio.h>

int main(){
	int test, soma=0, num;
	printf("quantidade de numeros entre 100 e 200\n");
	do{
		printf("digite um numero: ");
		scanf("%d", &num);
		if (num > 100 && num < 200)
			soma += 1;
		printf("digite zero pra parar a exercução: ");
		scanf("%d", &test);
	}while(test!=0);
	printf("a quantidade de valores entre 100 e 200: %d\n", soma);
}
