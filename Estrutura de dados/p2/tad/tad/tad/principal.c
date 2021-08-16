#include <stdio.h>
#include "Pilha.h"

int main(void){
	int a;
	Pilha p;
	p=inicializar();
	p=inserir(p, 10);
	p=inserir(p, 20);
	p=remover(p, &a);
	printf("%d", a);
	p=destruir(p);
	return 0;	
}
