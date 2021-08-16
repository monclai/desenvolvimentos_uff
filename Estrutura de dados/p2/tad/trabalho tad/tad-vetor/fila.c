#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila{
	int *vet;
	int pos;
};

Fila inicializar(void){
	Fila x;
	x=(Fila)malloc(sizeof(struct fila));
	x->vet=(int*)malloc(101*sizeof(int));
	x->pos=1;	
	return x;
}

Fila inserir(Fila p, int x){
	if(cheia(p)==1)
		return p;
	else{
		p->vet[p->pos]=x;
		p->pos=p->pos+1;
		return p; 
	}
}

Fila remover(Fila p, int *x){
	if(vazia(p)==1)
		return p; 
	else
		*x=p->vet[1];
		int n, i;
		n=p->pos-1;
		for(i=1; i<=n; i++){
			p->vet[i]=p->vet[i+1];
		}
		p->pos=p->pos-1;		
	return p;
}

void imprimir(Fila p){
	int i, n;
	n=p->pos-1;
	for(i=1; i<=n; i++){
		printf("%d ", p->vet[i]);
		if(i%10==0)
			printf("\n");		
	}
	printf("\n");
}

Fila destruir(Fila p){
	free(p->vet);
	p->pos=0;
	return p; 
}

int vazia(Fila p){
	if(p->pos==0)
		return 1;
	else
		return 0;	
}

int cheia(Fila p){
	if(p->pos==100)
		return 1;
	else
		return 0;
}