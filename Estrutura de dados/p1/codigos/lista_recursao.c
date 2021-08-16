#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int info;
	struct lista *prox;
}lista;
//prototipos
lista *inserir_final(lista *l, int x);
lista *inserir_inicio(lista *l, int x);
lista *remover(lista *l, int x);
int imprimir(lista *l);
int imprimir_inverso(lista *l);
int contar(lista *l, int *cont);
int multipicar(lista *l);
lista *destruir(lista *l);

int main(void){
	lista *l=NULL;
	int opcao, x, control, cont=0;
	do{
	printf("digite a opcao desejada\n");
	printf("1- inserir um elemento no final da lista\n");
	printf("2- inserir elemento no inicio da lista\n");
	printf("3- remover elemento da lista\n");
	printf("4- imprimir\n");
	printf("5- imprimir de tras para frente\n");
	printf("6- contar numero de elementos\n");
	printf("7- multiplicar todos os impares por 2\n");
	printf("8- sair\n");
	printf("opcao: ");
	scanf("%d", &opcao);
	if(opcao==1){
		printf("digite o valor a ser inserido: ");
		scanf("%d", &x);
		l=inserir_final(l, x);
	}	
	if(opcao==2){
		printf("digite o valor a ser inserido: ");
		scanf("%d", &x);
		l=inserir_inicio(l, x);
	}
	if(opcao==3){
		printf("digite o valor a ser removido: ");
		scanf("%d", &x);
		l=remover(l, x);
	}
	if(opcao==4){
		printf("valores da lista: ");
		control=imprimir(l);
		printf("\n");
	}
	if(opcao==5){
		printf("valores da lista invertida: ");
		control=imprimir_inverso(l);
		printf("\n");
	}
	if(opcao==6){
		control=contar(l, &cont);
		printf("a lista tem %d elemento(s)\n", cont);
	}
	if(opcao==7)
		control=multipicar(l);
	if(opcao==8)
		l=destruir(l);	
	}while(opcao!=8);
	return 0;	
}

lista *destruir(lista *l){
	if(l==NULL)
		return 0;
	else{
		lista *t=l;
		l=l->prox;
		free(t);
		return destruir(l);
	}
}

int multipicar(lista *l){
		if(l==NULL)
			return 0;
		else{
			if(l->info%2==0){
				l->info=l->info*2;
				return multipicar(l->prox);
			}
			else
				return multipicar(l->prox);
		}	
}

int contar(lista *l, int *cont){
		if(l==NULL)
			return 0;
		else{
			*cont=*cont+1;
			return contar(l->prox, cont);			
		}	
}

int imprimir_inverso(lista *l){
		if(l==NULL)
			return 0;
		else{
			return imprimir(l->prox);
			printf("%d ", l->info);			
		}	
}

int imprimir(lista *l){
		if(l==NULL)
			return 0;
		else{
			printf("%d ", l->info);
			return imprimir(l->prox);			
		}	
}

lista *remover(lista *l, int x){
		if(l==NULL)
			return l;
		else{
			if(l->info==x){
				lista *t=l;
				l=l->prox;
				free(t);
				return remover(l, x);
			}
			else
				return remover(l->prox, x);
		}	
}

lista *inserir_inicio(lista *l, int x){
		lista *no;
		no=(lista*)malloc(sizeof(lista));		
		no->info=x;
		no->prox=l;
		return no;
}

lista *inserir_final(lista *l, int x){
	if(l==NULL){
		lista *no=(lista*)malloc(sizeof(lista));
		no->info=x;
		no->prox=NULL;
		l=no;
		return l;
	}	
	else{
		l->prox=inserir_final(l->prox, x);
		return l;
	}	
}
