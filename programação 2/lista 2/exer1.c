#include <stdio.h>

#define galao 3.7854f
double preco_brasil(double preco, double taxa);

int main(){
	double preco, taxa, valor;
	printf("digite o valor do dolar: ");
	scanf("%lf", &taxa);
	printf("digite o preco do galao: ");
	scanf("%lf", &preco);
	valor = preco_brasil(preco, taxa);
	printf("o valor do galao e: %lf", valor);
}

double preco_brasil(double preco, double taxa){
		return (preco * galao * taxa);	
}
