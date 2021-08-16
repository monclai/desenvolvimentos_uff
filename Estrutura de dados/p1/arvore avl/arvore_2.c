#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
	int info;
	struct arvore *esq;
	struct arvore *dir;
}arvore;

//prototipos
int menu(void);
arvore *ler(FILE *arq);
void imprimir(arvore *a);
arvore *inserir(arvore *a, int x);
arvore *remover(arvore *a, int x);
void imprimirmenor(arvore *a, int x);
int ocorrencia(arvore *a, int x);
int contar(arvore *a, int x);
arvore *destruir(arvore *a);

int main(void){
	arvore *a;
	int opcao_menu, valor, valor2, control, control2, sub;
	char entrada[121];
	do{
		opcao_menu=menu();
		if(opcao_menu==1){
			printf("digite o nome do arquivo: ");
			scanf("%120s", entrada);
			FILE* arq;
			arq=fopen(entrada, "rt");
			if(arq==NULL){
				printf("erro na abertura do arquivo\n");
			} 
			else{
				a=ler(arq);
		}
		int fclose(FILE* arq);
	}
	if(opcao_menu==2){
		imprimir(a);		
	}
	if(opcao_menu==3){
		printf("digite o x: ");
		scanf("%d", &valor);
		imprimirmenor(a, valor);
		printf("\n");		
	}
	if(opcao_menu==4){
		printf("digite o valor de x: ");
		scanf("%d", &valor);
		printf("digite o valor de y: ");
		scanf("%d", &valor2);
		control=contar(a, valor);
		control2=contar(a, valor2);
		sub=control-control2;
		printf("a quant. de valores entre x e y e: %d\n", sub);				
	}		
	if(opcao_menu==5){
		printf("digite o valor a ser inserido: ");
		scanf("%d", &valor);
		a=inserir(a, valor);
	}	
	if(opcao_menu==6){
		printf("digite o valor a ser removido: ");
		scanf("%d", &valor);
		//a=remove(a, valor);
	}
	if(opcao_menu==7){
		printf("digite o valor a ser pesquisado: ");
		scanf("%d", &valor);
		valor2=ocorrencia(a, valor);
		printf("deve %d ocorrencia(s)\n", valor2);
	}	
	if(opcao_menu==8)
		a=destruir(a);
	}while(opcao_menu!=8);
	return 0;	
}

arvore *destruir(arvore *a){
	if(a->esq==NULL && a->dir==NULL){
		free(a);
		return NULL;
	}
	else if(a->esq==NULL || a->dir==NULL){
			if(a->esq==NULL)
				a=destruir(a->dir);
			else
				a=destruir(a->esq);			
	}
	else{
		a=destruir(a->esq);
		a=destruir(a->dir);
	}
	return a;
}

int contar(arvore *a, int x){
	if(a==NULL)
		return 0;
	else{
		if(a->info==x)
			return 1+contar(a->esq, x);
		else{
			if(a->info>x)
				return contar(a->esq, x);
			else
				return 1+contar(a->esq, x)+contar(a->dir, x);			
		}		
	}	
}

int ocorrencia(arvore *a, int x){
	if(a==NULL)
		return 0;
	else{
		if(a->info==x)
			return 1+ocorrencia(a->esq, x);
		else{
			if(x<a->info)
				return ocorrencia(a->esq, x);
			else
				return ocorrencia(a->dir, x);
		}		
	}	
}

void imprimirmenor(arvore *a, int x){
		if(a!=NULL){
			if(a->info==x)
			 imprimirmenor(a->esq, x);
			else{
				if(a->info>x)
					imprimirmenor(a->esq, x);
				else{
					imprimirmenor(a->esq, x);
					printf("%d ", a->info);
					imprimirmenor(a->dir, x);
				}
			}
		}
}

arvore *remover(arvore *a, int x){
	if(a!=NULL){
		if(x==a->info){
			if(a->esq==NULL && a->dir==NULL){
				free(a);
				return NULL;				
			}
			else if(a->esq==NULL || a->dir==NULL){
				arvore *t;
				if(a->esq==NULL)
					t=a->dir;
				else
					t=a->esq;
				free(a);
				return t;				
			}
			else{
				arvore *t=a->esq;
				while(t->dir!=NULL)
					t=t->dir;
				a->info=t->info;
				a->esq=remover(a->esq, t->info);
				return a;
			}
		}
		else{
		if(x<a->info)
			a->esq=remover(a->esq, x);
		else
			a->dir=remover(a->dir, x);
		}
	}
	return a;	
}

arvore *inserir(arvore *a, int x){
	if(a==NULL){
		arvore *no=(arvore*)malloc(sizeof(arvore));
		no->info=x;
		no->esq=NULL;
		no->dir=NULL;
		return no;		
	}	
	else{
		if(x<=a->info)
			a->esq=inserir(a->esq, x);
		else
			a->dir=inserir(a->dir, x);
		return a;
	}	
}

void imprimir(arvore *a){
		if(a!=NULL){
			imprimir(a->esq);
			printf("%d ", a->info);
			imprimir(a->dir);
		}
}

arvore *ler(FILE *arq){
	char c;
	int x;
	fscanf(arq, "%c", &c);
	fscanf(arq, "%d", &x);
	if(x==-1){
		fscanf(arq, "%c", &c);
		return NULL;
	}	
	else{
		arvore *no=(arvore*)malloc(sizeof(arvore));
		no->info=x;
		no->esq=ler(arq);
		no->dir=ler(arq);
		fscanf(arq, "%c", &c);
		return no;
	}
}

int menu(void){
	int menu;
	printf("digite a opcao desejada\n");
	printf("1- ler uma arvore de um arquivo\n");
	printf("2- imprimir em ordem\n");
	printf("3- imprimir todos os numeros menores que x\n");
	printf("4- contem os nos entre x e y\n");
	printf("5- inserir novo no na arvore\n");
	printf("6- remove no da arvore\n");
	printf("7- contar o numero de ocorrencias de um no\n");
	printf("8- sair\n");
	printf("opcao: ");
	scanf("%d", &menu);
	return menu;
}
