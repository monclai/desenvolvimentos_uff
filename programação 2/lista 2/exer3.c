#include <stdio.h>

int total_de_notas(int valor);
int main(){
	int valor, total;
	printf("digite o valor a ser sacado: ");
	scanf("%d", &valor);
	total = total_de_notas(valor);
	printf("o total de notas a ser sacado e %d", total);
}

int total_de_notas(int valor){
	int quant = 0;
	if (valor >= 100){
		quant += (valor / 100);
		valor = valor % 100;	
	}
	if (valor >= 50){
		quant += (valor / 50);
		valor = valor % 50;	
	}
	if (valor >= 20){
		quant += (valor / 20);
		valor = valor % 20;	
	}
	if (valor >= 10){
		quant += (valor / 10);
		valor = valor % 10;	
	}
	if (valor >= 5){
		quant += (valor / 5);
		valor = valor % 5;	
	}
	if (valor >= 2){
		quant += (valor / 2);
		valor = valor % 2;	
	}
	if (valor >= 1){
		quant += (valor / 1);
		valor = valor % 1;	
	}
	return quant;	
}
