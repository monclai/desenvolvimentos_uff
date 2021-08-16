#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
		int info;
		struct lista *prox;	
}lista;

//protótipos
int menu(void);
void imprimir(lista *l);
lista *inserir(lista *l);
lista *remover(lista *l, int *x);
lista *destruir (lista *l);

int main(void){
	lista *l=NULL;
	int opcao_menu, x;
	do{
		opcao_menu=menu();
		if(opcao_menu==1)
			l=inserir(l);
		if(opcao_menu==2){
			l=remover(l, &x);
			printf("valor removido: %d\n", x);
		}
		if(opcao_menu==3)
			imprimir(l);
		if(opcao_menu==4)
			l=destruir(l);
	}while(opcao_menu!=4);	
	return 0;
}

lista *destruir (lista *l){
	while(l!=NULL){
		lista *t=l;
		l=l->prox;
		free(t);
	}
	return l;
}

lista *remover(lista *l, int *x){
	lista *t=l;
	lista *aux_ant=NULL;
	lista *aux_prox=NULL;
	while(t->prox!=NULL){
		aux_prox=t->prox;
		*x=aux_prox->info;
		aux_ant=t;
		t=t->prox;
	}
	aux_ant->prox=NULL;
	free(t);
	return l;	
}

lista *inserir(lista *l){
		int valor;
		lista *no;
		no=(lista*)malloc(sizeof(lista));
		printf("digite o valor a ser inserido: ");
		scanf("%d", &valor);
		no->info=valor;
		no->prox=l;
		return no;
}

void imprimir(lista *l){
		lista *p=l;
		printf("fila: ");
		while(p!=NULL){
			printf("%d ", p->info);
			p=p->prox;
		}
		printf("\n");
}

int menu(void){
	int opcao;
	printf("digite a opcao desejada\n");
	printf("1- inserir um elemento\n");
	printf("2- remover elemento\n");
	printf("3- imprimir\n");
	printf("4- sair\n");
	printf("opcao: ");
	scanf("%d", &opcao);
	return opcao;
}
