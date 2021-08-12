#include <stdio.h>

int main(){
		printf("calcular fatorial\n");
		int x, n, fat = 1;
		printf("digite o valor: ");
		scanf("%d", &x);
		for (n=x; n>=1; n--){
			fat *= n;			
		}
	printf("o fatorial de %d e %d\n", x, fat);	
}
