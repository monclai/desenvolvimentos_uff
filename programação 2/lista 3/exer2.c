#include <stdio.h>

#define inicial 4.95f
#define bandeira1 2.50f
#define bandeira2 3.00f
void calcula_corrida(float dist, float *b1, float *b2);

int main (){
	float dist, b1, b2;
	printf("digite a distancia a ser percorrrida: ");
	scanf("%f", &dist);
	calcula_corrida(dist, &b1, &b2);
	printf("o valor pra bandeira 1: R$ %.2f\n", b1);
	printf("o valor pra bandeira 2: R$ %.2f\n", b2);	
}

void calcula_corrida(float dist, float *b1, float *b2){
		*b1 = inicial + (dist*bandeira1);
		*b2 = inicial + (dist*bandeira2);	
}
