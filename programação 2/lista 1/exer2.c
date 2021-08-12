#include <stdio.h>

int main(){
	printf("imprima todos os números pares no intervalo de 1 a 10 \n");
	int x;
	for (x=1; x<=10; x++){
		if(x%2 == 0)
			printf("%d ", x);		
	}	
	printf("\n");
}
