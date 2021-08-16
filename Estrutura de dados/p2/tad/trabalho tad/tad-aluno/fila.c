#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

typedef struct aluno{
    int matricula;
    int nota;
    char nome[121];    
}Aluno;

typedef struct lista{
    Aluno info;
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

Fila inserir(Fila p, int mat, char* nome, int nota){
    lista *no=(lista*)malloc(sizeof(lista));
    //adiciona os valores
    no->info.matricula=mat;
    no->info.nota=nota;
    strcpy(no->info.nome, nome);
    //passagem de parametro
    no->prox=p->l;
    p->l=no;
    return p;    
}

void imprimir(Fila p){
    lista *aux=p->l;
    while(aux!=NULL){
        printf("matricula: ");
        printf("%d  ", aux->info.matricula);
        printf("nome: ");
        printf("%s  ", aux->info.nome);
        printf("nota: ");
        printf("%d  ", aux->info.nota);
        printf("\n\n");
        aux=aux->prox;
    }   
}

Fila remover(Fila p, int *mat, char *nome, int *nota ){
    if(vazia(p)==1)
        return p;
    else{
        lista *t=p->l;
        lista *aux_ant=NULL;
        lista *aux_prox=NULL;
        while(t->prox!=NULL){
            aux_prox=t->prox;
            aux_ant=t;
            t=t->prox;
        }
        *mat=t->info.matricula;
        *nota=t->info.nota;
        strcpy(nome, t->info.nome);
        aux_ant->prox=NULL;
        //system("pause");
        free(t);
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