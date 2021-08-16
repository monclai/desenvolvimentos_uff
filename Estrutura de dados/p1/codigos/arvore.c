#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct arvore{
	int info;
	struct arvore *esq;
	struct arvore *dir;
}arvore;

//prototipos
arvore *ler(FILE *arq);
void imprimirpos(arvore *a);
void imprimir(arvore *a);
void imprimirpre(arvore *a);
int altura (arvore *a);
void imprimirnivel(arvore *a, int nivel, int cont);
void nosnivel(arvore *a, int nivel, int cont, int *i);
void contar(arvore *a, int control, int *cont);
void imprimirfolha(arvore *a);

int menu(void);

int main(void){
	arvore *a=NULL;
	int opcao_menu, control, altur, i, cont=0;
	char entrada[121];
	do{
		opcao_menu=menu();
		if(opcao_menu==1){
			printf("digite o nome do arquivo: ");
			scanf("%120s", entrada);
			FILE* arq;
			arq=fopen(entrada, "rt");
			if(arq==NULL){
				printf("erro na abertura do arquivo");
			} 
			else{
				a=ler(arq);
		}
		int fclose(FILE* arq);
	}	
	if(opcao_menu==2){
		printf("escolha uma das opcoes abaixo para impressao\n");
		printf("1-pre-ordem\n");
		printf("2-em ordem\n");
		printf("3-pos-ordem\n");
		printf("4-em largura\n");
		printf("opcao: ");
		scanf("%d", &control);
		if(control==1){
			printf("impressao pre-ordem: ");
			imprimirpre(a);
		}
		if(control==2){
			printf("impressao em ordem: ");
			imprimir(a);
		}
		if(control==3){
			printf("impressao pos-ordem: ");
			imprimirpos(a);
		}
		if(control==4){
			altur=altura(a);
			printf("impressao em largura: ");
			for(i=0; i<=altur; i++){
				imprimirnivel(a, i, cont);				
			}
		}
		printf("\n");			
	}
	if(opcao_menu==3){
		altur=altura(a);
		printf("a altura da arvore e %d\n", altur);
	}
	if(opcao_menu==4){
		altur=altura(a);
		printf("escolha um numero entre 0 e %d: ", altur);
		scanf("%d", &control);
		cont=0;
		i=0;
		nosnivel(a, control, cont, &i);
		printf("o numero de nos nesse nivel e: %d\n", i);
	}
	if(opcao_menu==5){
		printf("digite o valor a ser contado: ");
		scanf("%d", &control);
		cont=0;
		contar(a, control, &cont);
		printf("o numero %d tem %d ocorrencias\n", control, cont);
	}
	if(opcao_menu==6){
		altur=altura(a);
		printf("imprimindo as folhas: ");
		imprimirfolha(a);
		printf("\n");
	}
	/*if(opcao_menu==7){
		altur=altura(a);
		int x;
		x=altur-1;
		control=pow(2, x);
		cont=0, i=0;
		nosnivel(a, altur, cont, &i);
		if(control==i)
			printf("arvore cheia\n");
		else
			printf("arvore nao esta cheia\n");
	}*/
	}while(opcao_menu!=8);
}

void imprimirfolha(arvore *a){
		if(a!=NULL){
			if(a->esq==NULL && a->dir==NULL)
				printf("%d ", a->info);
			imprimir(a->esq);
			imprimir(a->dir);
		}
}

void contar(arvore *a, int control, int *cont){
		if(a!=NULL){
			if(a->info==control)
				*cont=*cont+1;
			contar(a->esq, control, cont);
			contar(a->dir, control, cont);
		}
}

void nosnivel(arvore *a, int nivel, int cont, int *i){
		if(a!=NULL){
			if(cont==nivel){
				*i=*i+1;
			}
			else{
				nosnivel(a->esq, nivel, cont+1, i);
				nosnivel(a->dir, nivel, cont+1, i);
			}
		}
}

void imprimirnivel(arvore *a, int nivel, int cont){
		if(a!=NULL){
			if(cont==nivel){
				printf("%d ", a->info);
			}
			else{
				imprimirnivel(a->esq, nivel, cont+1);
				imprimirnivel(a->dir, nivel, cont+1);
			}
		}
}

int altura(arvore *a){
   if(a==NULL) 
      return 0; 
   else{
      int he=altura(a->esq);
      int hd=altura(a->dir);
      if(he<hd)
		return hd + 1;
      else 
		return he + 1;
   }
}

void imprimirpos(arvore *a){
		if(a!=NULL){
			imprimir(a->esq);
			imprimir(a->dir);
			printf("%d ", a->info);
		}
}

void imprimir(arvore *a){
		if(a!=NULL){
			imprimir(a->esq);
			printf("%d ", a->info);
			imprimir(a->dir);
		}
}

void imprimirpre(arvore *a){
		if(a!=NULL){
			printf("%d ", a->info);
			imprimir(a->esq);
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
	int opcao;
	printf("digite a opcao desejada\n");
	printf("1- ler uma arvore de arquivo\n");
	printf("2- imprimir arvore\n");
	printf("3- calcular altura da arvore\n");
	printf("4- contar o numero de nos de um determinado nivel da arvore\n");
	printf("5- contar o numero de ocorrencias de um determinado numero na arvore\n");
	printf("6- imprimir as folhas da arvore\n");
	printf("7- verificar se a arvore esta cheia\n");
	printf("8- sair\n");
	printf("opcao: ");
	scanf("%d", &opcao);	
	return opcao;
}
