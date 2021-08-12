#include <stdio.h>

int main(){
		printf("imprimir o maior dos tres\n");
		int num1, num2, num3;
		printf("Digite um numero: ");
			scanf("%d", &num1);
		printf("Digite um numero: ");
			scanf("%d", &num2);
		printf("Digite um numero: ");
			scanf("%d", &num3);
		if(num1 > num2 && num1 > num3)
			printf("o maior e o %d", num1);
		else if (num2 > num1 && num2 > num3)
			printf("o maior e o %d", num2);
		else 
			printf("o maior e o %d", num3);
		printf("\n");
}
