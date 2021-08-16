#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
		int info;
		struct lista *prox;	
}lista;

void imprimir (lista *l){
	lista *p=l;
	while(p!=null){
		printf("%d ", p->info);
		p=p->prox;
	}	
}

lista *push(lista *l, int x){
	lista *no;
	no=(lista*)malloc(sizeof(lista));
	no->info=x;
	no->prox=l;
	l=no;
	return l;	
}

lista *pop(lista *l, int x){
	lista *t=l;
	*x=l->info;
	l=l->prox;
	free(t);
	return l;	
}

lista *destruir(lista *l){
	while(l!=null){
		lista *t=l;
		l=l->prox;
		free(t);		
	}	
	return l;
}

int main(void){
	lista *l=null;
	int x;
	l=inserir(l, 10);
	l=inserir(l, 20);
	l=inserir(l, 30);
	
	l=remover(l, &x);
	printf("%d ", x);
	
	l=remover(l, &x);
	printf("%d ", x);
	l=destruir(l);
	return 0;
}














