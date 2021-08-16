#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

typedef struct lista{
    void *info;
    struct lista *prox;    
}lista;

struct fila{
    lista *l;
};

Fila inicializar(void){
  Fila x;  
  x=(Fila)malloc(sizeof(struct fila));
  x->l=NULL;
  return x;
}

Fila inserir(Fila p, void *x){
    lista *no=(lista*)malloc(sizeof(lista));
    //adiciona os valores
    no->info=x;
    //passagem de parametro
    no->prox=p->l;
    p->l=no;
    return p;    
}

Fila remover(Fila p, void **x){
    if(vazia(p)==1)
        return p;
    else{
        lista *t=p->l;
        lista *aux_ant=NULL;
        while(t->prox!=NULL){
            aux_ant=t;
            t=t->prox;
        }
        *x=t->info;
        if(aux_ant==NULL){
            free(p->l);
            p->l=NULL;
        }
        else{
            aux_ant->prox=NULL;
            free(t);
        }
        return p;
    }
}

int vazia(Fila p){
    if(p->l==NULL)
        return 1;
     else
        return 0;    
}

int cheia(Fila p){
    if(p->l==NULL)
        return 0;
    else
        return 1;    
}

Fila destruir(Fila p){
    while(p->l!=NULL){
		lista *t=p->l;
		p->l=p->l->prox;
		free(t);
	}
    free(p);
    return NULL;
}