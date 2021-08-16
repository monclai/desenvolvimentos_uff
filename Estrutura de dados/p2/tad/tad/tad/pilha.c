#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
typedef struct lista{
	int info;
	struct lista *prox;	
}lista;

struct pilha{
	lista *l;
};

Pilha inserir(Pilha p, int x){
	lista *no=(lista*)malloc(sizeof(lista));
	no->info=x;
	no->prox=p->l;
	p->l=no;
	return p;
}

Pilha inicializar(void){
	Pilha x;
	x=(Pilha)malloc(sizeof(struct pilha));
	x->l=NULL;
	return x;	
}

Pilha destruir(Pilha p){
	lista *t=p->l;
	while(t!=NULL){
		lista *no=t;
		t=t->prox;
		free(no);
	}
	free(p);
	return NULL;
}

Pilha remover(Pilha p, int *x){
	lista *aux=p->l;
	p->l=p->l->prox;
	*x=aux->info;
	free(aux);
	return p;
}

void imprimir(Pilha p){
	lista *aux=p->l;
	while(aux!=NULL){
		printf("%d", aux->info);
		aux=aux->prox;
	}	
}
